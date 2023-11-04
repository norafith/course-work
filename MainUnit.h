//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
#include "cgrid.h"
#include <Vcl.ColorGrd.hpp>
#include <Vcl.ActnColorMaps.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TImage *MainImage;
	TSpeedButton *SelectBrush;
	TSpeedButton *SelectEraser;
	TSpeedButton *SelectLine;
	TSpeedButton *SelectRectangle;
	TSpeedButton *SelectCircle;
	TTrackBar *TrackBar1;
	TTrackBar *TrackBar2;
	TLabel *Label1;
	TColorGrid *ColorGrid1;
	TLabel *Label2;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *SaveAsMenuItem;
	TMenuItem *LoadFileMenuItem;
	TSavePictureDialog *SaveMainImageDialog;
	TOpenPictureDialog *OpenMainImageDialog;
	TColorBox *ColorBox1;
	TLabel *Label3;
	void __fastcall SelectCircleClick(TObject *Sender);
	void __fastcall SaveAsMenuItemClick(TObject *Sender);
	void __fastcall LoadFileMenuItemClick(TObject *Sender);
	void __fastcall SaveMainImageDialogTypeChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
