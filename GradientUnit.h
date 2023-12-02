//---------------------------------------------------------------------------

#ifndef GradientUnitH
#define GradientUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Dialogs.hpp>

#include "PaintUtils.h"
//---------------------------------------------------------------------------
class TGradientForm : public TForm
{
__published:	// IDE-managed Components
	TImage *GradientPreviewImage;
	TPanel *GradientToolsPanel;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TSpeedButton *EndColorButton;
	TSpinEdit *GradientAngleEdit;
	TColorDialog *StartColorDialog;
	TColorDialog *EndColorDialog;
	TBitBtn *StartColorButton;
	void __fastcall StartColorDialogClose(TObject *Sender);
	void __fastcall StartColorDialogShow(TObject *Sender);
	void __fastcall EndColorDialogClose(TObject *Sender);
	void __fastcall EndColorDialogShow(TObject *Sender);
	void __fastcall StartColorButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TGradientForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGradientForm *GradientForm;
//---------------------------------------------------------------------------
#endif
