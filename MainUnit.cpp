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

void __fastcall TMainForm::SaveImageDialogTypeChange(TObject *Sender)
{
	globalFileHandler.setSelectedExtension(SaveImageDialog);
}

void __fastcall TMainForm::SaveAsMenuItemClick(TObject *Sender)
{
	globalFileHandler.saveCanvas(SaveImageDialog, MainImage);
}

void __fastcall TMainForm::OpenFileMenuItemClick(TObject *Sender)
{
	int resultCode = globalFileHandler.loadImage(SaveImageDialog, MainImage, CanvasImage);
	if (resultCode != 0) {
		String message = L"Ќевозможно открыть изображение по пути \""
			+ String(SaveImageDialog->FileName) + L"\".";
		ShowMessage(message);
	}
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

//
//void __fastcall TMainForm::ColorGridChange(TObject *Sender)
//{
//	globalPaintState.setColors(ColorGrid->ForegroundColor, ColorGrid->BackgroundColor);
//}
//---------------------------------------------------------------------------



void __fastcall TMainForm::SetThicknessBarChange(TObject *Sender)
{
  globalPaintState.setThickness(SetThicknessBar->Position);
}
//---------------------------------------------------------------------------
//
//void __fastcall TMainForm::SelectBackgroundColorChange(TObject *Sender)
//{
//	globalPaintState.setBackgroundColor(SelectBackgroundColor->Selected, CanvasImage, MainImage);
//}
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


void __fastcall TMainForm::ShouldResizeImageMenuItemClick(TObject *Sender)
{
	ShouldResizeImageMenuItem->Checked = !ShouldResizeImageMenuItem->Checked;
  globalFileHandler.setShouldResizeImage(ShouldResizeImageMenuItem->Checked);
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::SetCanvasSizeMenuItemClick(TObject *Sender)
{
  CanvasSizeForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OutlineColorDialogShow(TObject *Sender)
{
	OutlineColorDialog->Color = globalPaintState.outlineColor;
	OutlineColorPanel->Color = globalPaintState.outlineColor;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PaintColorDialogShow(TObject *Sender)
{
	PaintColorDialog->Color = globalPaintState.paintColor;
	PaintColorPanel->Color = globalPaintState.paintColor;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PaintColorButtonClick(TObject *Sender)
{
	if (!PaintColorDialog->Execute()) return;
	globalPaintState.paintColor = PaintColorDialog->Color;
	PaintColorPanel->Color = PaintColorDialog->Color;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OutlineColorButtonClick(TObject *Sender)
{
	if (!OutlineColorDialog->Execute()) return;
	globalPaintState.outlineColor = OutlineColorDialog->Color;
	OutlineColorPanel->Color = OutlineColorDialog->Color;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BackgroundColorDialogShow(TObject *Sender)
{
	BackgroundColorDialog->Color = globalPaintState.getBackgroundColor();
	BackgroundColorPanel->Color = globalPaintState.getBackgroundColor();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BackgroundColorButtonClick(TObject *Sender)
{
	if (!BackgroundColorDialog->Execute()) return;
	globalPaintState.setBackgroundColor(BackgroundColorDialog->Color, CanvasImage, MainImage);
	BackgroundColorPanel->Color = globalPaintState.getBackgroundColor();
}
//---------------------------------------------------------------------------

