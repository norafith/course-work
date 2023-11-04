//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include <pngimage.hpp>
#include <jpeg.hpp>
#include <GIFimg.hpp>
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cgrid"
#pragma resource "*.dfm"
TMainForm *MainForm;

// create empty bitmap at load
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	TBitmap* tmpBitmap = new TBitmap(MainImage->Width, MainImage->Height);
	MainImage->Picture->Assign(tmpBitmap);
	tmpBitmap->Free();
}

// test fn
void __fastcall TMainForm::SelectCircleClick(TObject *Sender)
{
	MainImage->Picture->Bitmap->Canvas->Brush->Color=clYellow;
	MainImage->Picture->Bitmap->Canvas->Ellipse(100, 50, MainImage->Picture->Bitmap->Width, MainImage->Picture->Bitmap->Height);
}

String selectedExtension;

enum class FileExtensionIndex {
	PNG = 1,
	JPG = 2,
	JPEG = 3,
	GIF = 4,
	BMP = 5,
	CUSTOM = 6,
};

// track which image type is selected
void __fastcall TMainForm::SaveMainImageDialogTypeChange(TObject *Sender)
{
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

// save canvas image depending on selected extension
void __fastcall TMainForm::SaveAsMenuItemClick(TObject *Sender)
{
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

// load image in canvas
void __fastcall TMainForm::LoadFileMenuItemClick(TObject *Sender)
{
	if (!OpenMainImageDialog->Execute()) return;
	MainImage->Picture->LoadFromFile(OpenMainImageDialog->FileName);

}

