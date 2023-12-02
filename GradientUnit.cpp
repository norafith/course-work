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

}

//---------------------------------------------------------------------------

void __fastcall TGradientForm::StartColorDialogClose(TObject *Sender)
{
	globalPaintState.gradientStartColor = StartColorDialog->Color;


// 	TODO
//	StartColorButton->Brush->Style = bsSolid;
//	StartColorButton->Brush->Color = StartColorDialog->Color;
//
//	StartColorButton->Glyph->Width = StartColorButton->Width;
//	StartColorButton->Glyph->Height = StartColorButton->Height;
//
//	StartColorButton->Glyph->Canvas->Rectangle(0, 0, StartColorButton->Width, StartColorButton->Height);
}


//---------------------------------------------------------------------------

void __fastcall TGradientForm::StartColorDialogShow(TObject *Sender)
{
	StartColorDialog->Color = globalPaintState.gradientStartColor;
}
//---------------------------------------------------------------------------

void __fastcall TGradientForm::EndColorDialogClose(TObject *Sender)
{
	globalPaintState.gradientEndColor = EndColorDialog->Color;
//  EndColorButton->Color = EndColorDialog->Color;
}
//---------------------------------------------------------------------------

void __fastcall TGradientForm::EndColorDialogShow(TObject *Sender)
{
	EndColorDialog->Color = globalPaintState.gradientEndColor;
}
//---------------------------------------------------------------------------

void __fastcall TGradientForm::StartColorButtonClick(TObject *Sender)
{
  if (!StartColorDialog->Execute()) return;
}
//---------------------------------------------------------------------------

