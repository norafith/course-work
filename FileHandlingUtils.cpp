//---------------------------------------------------------------------------

#pragma hdrstop

#include "FileHandlingUtils.h"
#include <Vcl.ExtDlgs.hpp>
#include <pngimage.hpp>
#include <jpeg.hpp>
#include <GIFimg.hpp>
#include <System.IOUtils.hpp>

class FileHandler {
	private:
		enum class FileExtensionIndex {
			PNG = 1,
			JPG = 2,
			JPEG = 3,
			GIF = 4,
			BMP = 5,
			CUSTOM = 6,
		};

		String selectedExtension;

	public:
		void setSelectedExtension(TSavePictureDialog* SaveMainImageDialog) {
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

		void saveCanvas(TSavePictureDialog* SaveMainImageDialog, TImage* MainImage) {
			if (!SaveMainImageDialog->Execute()) return;
			SaveMainImageDialog->FileName += selectedExtension;
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

			else { // .png or other
				TPngImage* TmpPng = new TPngImage;
				TmpPng->Assign(MainImage->Picture->Graphic);
				TmpPng->SaveToFile(SaveMainImageDialog->FileName);
				TmpPng->Free();
			}
		}

		void loadImage(TSavePictureDialog* OpenMainImageDialog, TImage* MainImage) {
      if (!OpenMainImageDialog->Execute()) return;
			MainImage->Picture->LoadFromFile(OpenMainImageDialog->FileName);
		}
};

//---------------------------------------------------------------------------
#pragma package(smart_init)
