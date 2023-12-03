//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GradientUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGradientForm *GradientForm;
//---------------------------------------------------------------------------
__fastcall TGradientForm::TGradientForm(TComponent* Owner)
	: TForm(Owner)
{
	GradientPreviewImage->Picture->Bitmap->Width = GradientPreviewImage->Width;
	GradientPreviewImage->Picture->Bitmap->Height = GradientPreviewImage->Height;
}
//---------------------------------------------------------------------------

void __fastcall TGradientForm::StartColorDialogShow(TObject *Sender)
{
	StartColorDialog->Color = globalPaintState.gradientStartColor;
	StartColorPanel->Color = globalPaintState.gradientStartColor;
}
//---------------------------------------------------------------------------


void __fastcall TGradientForm::EndColorDialogShow(TObject *Sender)
{
	EndColorDialog->Color = globalPaintState.gradientEndColor;
	EndColorPanel->Color = globalPaintState.gradientEndColor;
}
//---------------------------------------------------------------------------

void __fastcall TGradientForm::StartColorButtonClick(TObject *Sender)
{
	if (!StartColorDialog->Execute()) return;
	globalPaintState.gradientStartColor = StartColorDialog->Color;
	StartColorPanel->Color = StartColorDialog->Color;
	globalPaintState.fillGradient(GradientPreviewImage);
	globalPaintState.backgroundMode = BackgroundMode::GRADIENT;
}
//---------------------------------------------------------------------------

void __fastcall TGradientForm::EndColorButtonClick(TObject *Sender)
{
	if (!EndColorDialog->Execute()) return;
	globalPaintState.gradientEndColor = EndColorDialog->Color;
	EndColorPanel->Color = EndColorDialog->Color;
	globalPaintState.fillGradient(GradientPreviewImage);
	globalPaintState.backgroundMode = BackgroundMode::GRADIENT;
}
//---------------------------------------------------------------------------

void __fastcall TGradientForm::SelectHorizontalRadioClick(TObject *Sender)
{
	globalPaintState.gradientDirection = gdHorizontal;
	globalPaintState.fillGradient(GradientPreviewImage);
}
//---------------------------------------------------------------------------

void __fastcall TGradientForm::SelectVerticalRadioClick(TObject *Sender)
{
	globalPaintState.gradientDirection = gdVertical;
	globalPaintState.fillGradient(GradientPreviewImage);
}
//---------------------------------------------------------------------------

void __fastcall TGradientForm::FormResize(TObject *Sender)
{
	GradientPreviewImage->Width = GradientForm->ClientWidth - 16;
	GradientPreviewImage->Left = 8;
  GradientPreviewImage->Picture->Bitmap->Width = GradientPreviewImage->Width;
  globalPaintState.fillGradient(GradientPreviewImage);
}
//---------------------------------------------------------------------------

