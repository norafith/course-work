#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"

#pragma package(smart_init)
#pragma link "cgrid"
#pragma resource "*.dfm"

TMainForm *MainForm;

void TMainForm::removePaintButtonsSelectedFocus() {
	SelectCircle->Flat = true;
	SelectEraser->Flat = true;
	SelectLine->Flat = true;
	SelectRectangle->Flat = true;
	SelectBrush->Flat = true;
	SelectFill->Flat = true;
	SelectText->Flat = true;
}

void TMainForm::initializeImagesBitmap() {
	TBitmap* tmpBitmap = new TBitmap(MainImage->Width, MainImage->Height);
	MainImage->Picture->Assign(tmpBitmap);
	CanvasImage->Picture->Assign(tmpBitmap);

	globalPaintState.setFont(tmpBitmap->Canvas->Font);
	tmpBitmap->Free();
}

// Создание bitmap для холстов, занесение стандартного шрифта в состояние
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
  initializeImagesBitmap();

	SelectCircle->Flat = false;
}

void __fastcall TMainForm::SelectCircleClick(TObject *Sender)
{
	removePaintButtonsSelectedFocus();
	globalPaintState.paintMode = PaintMode::ELLIPSE;
  SelectCircle->Flat = false;
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
	int resultCode = globalFileHandler.loadImage(SaveImageDialog, OpenImageDialog, MainImage, CanvasImage);
	if (resultCode != 0) {
		String message = L"Невозможно открыть изображение по пути \""
			+ String(SaveImageDialog->FileName) + L"\".";

		Application->MessageBox(
			message.w_str(),
			String("Ошибка!").w_str(),
			MB_OK | MB_ICONERROR
		);
	}
}

void __fastcall TMainForm::SelectEraserClick(TObject *Sender)
{
  removePaintButtonsSelectedFocus();
	globalPaintState.paintMode = PaintMode::ERASER;
	SelectEraser->Flat = false;
}

void __fastcall TMainForm::SelectLineClick(TObject *Sender)
{
	removePaintButtonsSelectedFocus();
	globalPaintState.paintMode = PaintMode::LINE;
  SelectLine->Flat = false;
}

void __fastcall TMainForm::SelectRectangleClick(TObject *Sender)
{
	removePaintButtonsSelectedFocus();
	globalPaintState.paintMode = PaintMode::RECTANGLE;
  SelectRectangle->Flat = false;
}

void __fastcall TMainForm::SelectBrushClick(TObject *Sender)
{
	removePaintButtonsSelectedFocus();
	globalPaintState.paintMode = PaintMode::BRUSH;
  SelectBrush->Flat = false;
}

void __fastcall TMainForm::CanvasImageMouseDown(TObject *Sender, TMouseButton Button,
					TShiftState Shift, int X, int Y)
{
	globalPaintState.onMouseDown(X, Y, CanvasImage, MainImage);
}

void __fastcall TMainForm::CanvasImageMouseMove(TObject *Sender, TShiftState Shift,
					int X, int Y)
{
	globalPaintState.onMouseMove(X, Y, CanvasImage, MainImage);
}

void __fastcall TMainForm::CanvasImageMouseUp(TObject *Sender, TMouseButton Button,
					TShiftState Shift, int X, int Y)
{
	globalPaintState.onMouseUp(X, Y, CanvasImage, MainImage);
}

void __fastcall TMainForm::SetThicknessBarChange(TObject *Sender)
{
	globalPaintState.setThickness(SetThicknessBar->Position);
}

void __fastcall TMainForm::FormResize(TObject *Sender)
{
	globalPaintState.onFormResize(CanvasImage, MainImage, MainForm, ToolPanel);
}

void __fastcall TMainForm::SelectFillClick(TObject *Sender)
{
	removePaintButtonsSelectedFocus();
	globalPaintState.paintMode = PaintMode::FILL;
  SelectFill->Flat = false;
}

void __fastcall TMainForm::GradientBackgroundButtonClick(TObject *Sender)
{
	GradientForm->ShowModal();
}

void __fastcall TMainForm::SelectTextClick(TObject *Sender)
{
	removePaintButtonsSelectedFocus();
  SelectText->Flat = false;
	DrawTextForm->ShowModal();
}

void __fastcall TMainForm::ShouldResizeImageMenuItemClick(TObject *Sender)
{
	ShouldResizeImageMenuItem->Checked = !ShouldResizeImageMenuItem->Checked;
	globalFileHandler.setShouldResizeImage(ShouldResizeImageMenuItem->Checked);
}

void __fastcall TMainForm::SetCanvasSizeMenuItemClick(TObject *Sender)
{
	CanvasSizeForm->ShowModal();
}

void __fastcall TMainForm::OutlineColorDialogShow(TObject *Sender)
{
	OutlineColorDialog->Color = globalPaintState.outlineColor;
	OutlineColorPanel->Color = globalPaintState.outlineColor;
}

void __fastcall TMainForm::PaintColorDialogShow(TObject *Sender)
{
	PaintColorDialog->Color = globalPaintState.paintColor;
	PaintColorPanel->Color = globalPaintState.paintColor;
}

void __fastcall TMainForm::PaintColorButtonClick(TObject *Sender)
{
	if (!PaintColorDialog->Execute()) return;
	globalPaintState.paintColor = PaintColorDialog->Color;
	PaintColorPanel->Color = PaintColorDialog->Color;
}

void __fastcall TMainForm::OutlineColorButtonClick(TObject *Sender)
{
	if (!OutlineColorDialog->Execute()) return;
	globalPaintState.outlineColor = OutlineColorDialog->Color;
	OutlineColorPanel->Color = OutlineColorDialog->Color;
}

void __fastcall TMainForm::BackgroundColorDialogShow(TObject *Sender)
{
	BackgroundColorDialog->Color = globalPaintState.getBackgroundColor();
	BackgroundColorPanel->Color = globalPaintState.getBackgroundColor();
}

void __fastcall TMainForm::BackgroundColorButtonClick(TObject *Sender)
{
	if (!BackgroundColorDialog->Execute()) return;
	globalPaintState.setBackgroundColor(BackgroundColorDialog->Color, CanvasImage, MainImage);
	BackgroundColorPanel->Color = globalPaintState.getBackgroundColor();
}

void __fastcall TMainForm::SaveMenuItemClick(TObject *Sender)
{
  globalFileHandler.saveCanvas(SaveImageDialog, MainImage, false);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	String message =
		L"Вы действительно хотите закрыть приложение? Несохраненные данные будут утеряны";

	int returnCode = Application->MessageBox(
		message.w_str(),
		String("Внимание!").w_str(),
		MB_YESNO | MB_ICONWARNING
	);

	if (returnCode == IDNO) {
		CanClose = false;
	}
	else {
    CanClose = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CloseMenuItemClick(TObject *Sender)
{
  MainForm->Close();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::NewMenuItemClick(TObject *Sender)
{
	globalPaintState.resetState(globalPaintState);

	removePaintButtonsSelectedFocus();
  SelectCircle->Flat = false;

	BackgroundColorPanel->Color = globalPaintState.getBackgroundColor();
	PaintColorPanel->Color = globalPaintState.paintColor;
	OutlineColorPanel->Color = globalPaintState.outlineColor;

  initializeImagesBitmap();
}
//---------------------------------------------------------------------------

