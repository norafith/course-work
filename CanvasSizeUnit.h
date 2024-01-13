#ifndef CanvasSizeUnitH
#define CanvasSizeUnitH

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "MainUnit.h"

class TCanvasSizeForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *WidthLabel;
	TEdit *WidthEdit;
	TEdit *HeightEdit;
	TLabel *HeightLabel;
	TButton *SetCanvasSizeButton;
	void __fastcall WidthEditKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall HeightEditKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall SetCanvasSizeButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
//	void __fastcall WidthEditChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCanvasSizeForm(TComponent* Owner);
};

extern PACKAGE TCanvasSizeForm *CanvasSizeForm;

#endif
