#pragma hdrstop

#include "FileHandlingUtils.h"
#include <pngimage.hpp>
#include <jpeg.hpp>
#include <GIFimg.hpp>
#include <System.IOUtils.hpp>
#include <Vcl.GraphUtil.hpp>
#include "MainUnit.h"

// объ€вление глобального объекта обработки файлов
FileHandler globalFileHandler;

void FileHandler::setSelectedExtension(TSavePictureDialog* SaveMainImageDialog) {
	switch (static_cast<FileExtensionIndex>(SaveMainImageDialog->FilterIndex)) {
		case FileExtensionIndex::GIF:
			selectedExtension = L".gif";
			break;
		case FileExtensionIndex::JPEG:
			selectedExtension = L".jpeg";
			break;
		case FileExtensionIndex::JPG:
			selectedExtension = L".jpg";
			break;
		case FileExtensionIndex::PNG:
			selectedExtension = L".png";
			break;
		case FileExtensionIndex::BMP:
			selectedExtension = L".bmp";
			break;
		case FileExtensionIndex::CUSTOM:
			selectedExtension = L"";
			break;
	}
}

void FileHandler::saveCanvas(TSavePictureDialog* SaveMainImageDialog, TImage* MainImage, bool executeDialog) {
			if (
				(executeDialog || !SaveMainImageDialog->FileName.Length()) &&
				!SaveMainImageDialog->Execute()
			) {
        return;
			}

			if (Ioutils::TPath::GetExtension(SaveMainImageDialog->FileName).IsEmpty()) {
				SaveMainImageDialog->FileName += selectedExtension;
			}
			String fileExtension = Ioutils::TPath::GetExtension(SaveMainImageDialog->FileName);

			if (fileExtension == L".jpeg" || fileExtension == L".jpg") {
				TJPEGImage* TmpJpeg = new TJPEGImage;
				TmpJpeg->Assign(MainImage->Picture->Graphic);
				TmpJpeg->SaveToFile(SaveMainImageDialog->FileName);
				TmpJpeg->Free();
			}
			else if (fileExtension == L".gif") {
				TGIFImage* TmpGif = new TGIFImage;
				TmpGif->Assign(MainImage->Picture->Graphic);
				TmpGif->SaveToFile(SaveMainImageDialog->FileName);
				TmpGif->Free();
			}
			else if (fileExtension == L".bmp") {
				MainImage->Picture->SaveToFile(SaveMainImageDialog->FileName);
			}
			else { // .png или другое
				TPngImage* TmpPng = new TPngImage;
				TmpPng->Assign(MainImage->Picture->Graphic);
				TmpPng->SaveToFile(SaveMainImageDialog->FileName);
				TmpPng->Free();
			}
		}

int FileHandler::loadImage(TSavePictureDialog* SaveMainImageDialog, TOpenPictureDialog* OpenMainImageDialog, TImage* MainImage, TImage* CanvasImage) {
	// если код возврата не 0, возникла ошибка

	if (!OpenMainImageDialog->Execute()) return 0;

	try {
		if (shouldResizeImage) {
			TWICImage* tmpImage = new TWICImage;
			tmpImage->LoadFromFile(OpenMainImageDialog->FileName);

			tmpImage = tmpImage->CreateScaledCopy(MainImage->Width, MainImage->Height);

			MainImage->Picture->Graphic->Assign(tmpImage);
			CanvasImage->Picture->Graphic->Assign(tmpImage);

			MainImage->Picture->Bitmap->AlphaFormat = afIgnored;
			CanvasImage->Picture->Bitmap->AlphaFormat = afIgnored;

			tmpImage->Free();
		}
		else {
			MainImage->Picture->LoadFromFile(OpenMainImageDialog->FileName);

			TBitmap* tmpBitmap = new TBitmap;
			tmpBitmap->Assign(MainImage->Picture->Graphic);

			MainForm->ClientWidth = tmpBitmap->Width + MainForm->ToolPanel->Width + 5;
			MainForm->ClientHeight = tmpBitmap->Height;

			MainImage->Picture->Bitmap->Assign(tmpBitmap);
			CanvasImage->Picture->Bitmap->Assign(tmpBitmap);

			MainImage->Picture->Bitmap->AlphaFormat = afIgnored;
			CanvasImage->Picture->Bitmap->AlphaFormat = afIgnored;

			tmpBitmap->Free();
		}

		SaveMainImageDialog->FileName = OpenMainImageDialog->FileName;
		return 0;
	}
	catch (...) {
    return -1;
	}
}

void FileHandler::setShouldResizeImage(bool value) {
	shouldResizeImage = value;
}

#pragma package(smart_init)
