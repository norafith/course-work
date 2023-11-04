//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "FileHandlingUtils.h"
#include "PaintUtils.h"

#pragma package(smart_init)
#pragma link "cgrid"
#pragma resource "*.dfm"

TMainForm *MainForm;
FileHandler globalFileHandler;
PaintState globalPaintState;

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

// track which image type is selected
void __fastcall TMainForm::SaveMainImageDialogTypeChange(TObject *Sender)
{
	globalFileHandler.setSelectedExtension(SaveMainImageDialog);
}

// save canvas image depending on selected extension
void __fastcall TMainForm::SaveAsMenuItemClick(TObject *Sender)
{
	globalFileHandler.saveCanvas(SaveMainImageDialog, MainImage);
}

// load image in canvas
void __fastcall TMainForm::LoadFileMenuItemClick(TObject *Sender)
{
	globalFileHandler.loadImage(SaveMainImageDialog, MainImage);

}

