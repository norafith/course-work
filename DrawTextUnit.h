//---------------------------------------------------------------------------

#ifndef DrawTextUnitH
#define DrawTextUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "PaintUtils.h"
#include <Vcl.Dialogs.hpp>

//---------------------------------------------------------------------------
class TDrawTextForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ConfigureFontButton;
	TFontDialog *ConfigureFontDialog;
	TEdit *DrawTextEdit;
	TFontDialog *DrawFontDialog;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ConfigureFontButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDrawTextForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDrawTextForm *DrawTextForm;
//---------------------------------------------------------------------------
#endif
