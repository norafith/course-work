//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DrawTextUnit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDrawTextForm *DrawTextForm;


//---------------------------------------------------------------------------
__fastcall TDrawTextForm::TDrawTextForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TDrawTextForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	globalPaintState.paintMode = PaintMode::TEXT;
	globalPaintState.setText(DrawTextEdit->Text);
}

//---------------------------------------------------------------------------

void __fastcall TDrawTextForm::ConfigureFontButtonClick(TObject *Sender)
{
  if (!DrawFontDialog->Execute()) return;
	globalPaintState.setFont(DrawFontDialog->Font);
}
//---------------------------------------------------------------------------

