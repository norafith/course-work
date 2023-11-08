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
	CanvasImage->Picture->Assign(tmpBitmap);
	tmpBitmap->Free();
}

void __fastcall TMainForm::SelectCircleClick(TObject *Sender)
{
	globalPaintState.paintMode = PaintMode::ELLIPSE;
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

void __fastcall TMainForm::SelectEraserClick(TObject *Sender)
{
	globalPaintState.paintMode = PaintMode::ERASER;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SelectLineClick(TObject *Sender)
{
  globalPaintState.paintMode = PaintMode::LINE;
}


//---------------------------------------------------------------------------

void __fastcall TMainForm::SelectRectangleClick(TObject *Sender)
{
	globalPaintState.paintMode = PaintMode::RECTANGLE;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SelectBrushClick(TObject *Sender)
{
	globalPaintState.paintMode = PaintMode::BRUSH;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CanvasImageMouseDown(TObject *Sender, TMouseButton Button,
					TShiftState Shift, int X, int Y)
{
	globalPaintState.onMouseDown(X, Y);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CanvasImageMouseMove(TObject *Sender, TShiftState Shift,
					int X, int Y)
{
	globalPaintState.onMouseMove(X, Y, CanvasImage);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CanvasImageMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
  globalPaintState.onMouseUp(X, Y, CanvasImage, MainImage);
}
//---------------------------------------------------------------------------

