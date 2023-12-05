//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"

#pragma package(smart_init)
#pragma link "cgrid"
#pragma resource "*.dfm"

TMainForm *MainForm;

__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	TBitmap* tmpBitmap = new TBitmap(MainImage->Width, MainImage->Height);
	MainImage->Picture->Assign(tmpBitmap);
	CanvasImage->Picture->Assign(tmpBitmap);

	globalPaintState.setFont(tmpBitmap->Canvas->Font);

	tmpBitmap->Free();
}

void __fastcall TMainForm::SelectCircleClick(TObject *Sender)
{
	globalPaintState.paintMode = PaintMode::ELLIPSE;
}

void __fastcall TMainForm::SaveMainImageDialogTypeChange(TObject *Sender)
{
	globalFileHandler.setSelectedExtension(SaveMainImageDialog);
}

void __fastcall TMainForm::SaveAsMenuItemClick(TObject *Sender)
{
	globalFileHandler.saveCanvas(SaveMainImageDialog, MainImage);
}

void __fastcall TMainForm::LoadFileMenuItemClick(TObject *Sender)
{
	globalFileHandler.loadImage(SaveMainImageDialog, MainImage, CanvasImage);

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
	globalPaintState.onMouseDown(X, Y, CanvasImage, MainImage);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CanvasImageMouseMove(TObject *Sender, TShiftState Shift,
					int X, int Y)
{
	globalPaintState.onMouseMove(X, Y, CanvasImage, MainImage);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CanvasImageMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
  globalPaintState.onMouseUp(X, Y, CanvasImage, MainImage);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ColorGridChange(TObject *Sender)
{
	globalPaintState.setColors(ColorGrid->ForegroundColor, ColorGrid->BackgroundColor);
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::SetThicknessBarChange(TObject *Sender)
{
  globalPaintState.setThickness(SetThicknessBar->Position);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SelectBackgroundColorChange(TObject *Sender)
{
	globalPaintState.setBackgroundColor(SelectBackgroundColor->Selected, CanvasImage, MainImage);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormResize(TObject *Sender)
{
  globalPaintState.onFormResize(CanvasImage, MainImage, MainForm, ToolPanel);
}

//---------------------------------------------------------------------------


void __fastcall TMainForm::SelectFillClick(TObject *Sender)
{
  globalPaintState.paintMode = PaintMode::FILL;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GradientBackgroundButtonClick(TObject *Sender)
{
	GradientForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SelectTextClick(TObject *Sender)
{
	DrawTextForm->Show();
}


//---------------------------------------------------------------------------

