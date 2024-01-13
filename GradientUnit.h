#ifndef GradientUnitH
#define GradientUnitH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Samples.Spin.hpp>
#include <Vcl.Dialogs.hpp>

#include "PaintUtils.h"
#include "MainUnit.h"

class TGradientForm : public TForm
{
__published:	// IDE-managed Components
	TImage *GradientPreviewImage;
	TPanel *GradientToolsPanel;
	TLabel *StartColorLabel;
	TLabel *EndColorLabel;
	TColorDialog *StartColorDialog;
	TColorDialog *EndColorDialog;
	TPanel *StartColorPanel;
	TSpeedButton *StartColorButton;
	TPanel *EndColorPanel;
	TSpeedButton *EndColorButton;
	TRadioGroup *GradDirectionGroup;
	TRadioButton *SelectHorizontalRadio;
	TRadioButton *SelectVerticalRadio;
	TButton *ApplyGradientButton;
	TSpeedButton *SwitchColorsButton;
	void __fastcall StartColorDialogShow(TObject *Sender);
	void __fastcall EndColorDialogShow(TObject *Sender);
	void __fastcall StartColorButtonClick(TObject *Sender);
	void __fastcall EndColorButtonClick(TObject *Sender);
	void __fastcall SelectHorizontalRadioClick(TObject *Sender);
	void __fastcall SelectVerticalRadioClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall ApplyGradientButtonClick(TObject *Sender);
	void __fastcall SwitchColorsButtonClick(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TGradientForm(TComponent* Owner);
};

extern PACKAGE TGradientForm *GradientForm;

#endif
