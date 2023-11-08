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
	TTrackBar *SetThicknessBar;
	TTrackBar *TrackBar2;
	TLabel *Label1;
	TColorGrid *ColorGrid;
	TLabel *Label2;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *SaveAsMenuItem;
	TMenuItem *LoadFileMenuItem;
	TSavePictureDialog *SaveMainImageDialog;
	TOpenPictureDialog *OpenMainImageDialog;
	TColorBox *SelectBackgroundColor;
	TLabel *Label3;
	TImage *CanvasImage;
	void __fastcall SelectCircleClick(TObject *Sender);
	void __fastcall SaveAsMenuItemClick(TObject *Sender);
	void __fastcall LoadFileMenuItemClick(TObject *Sender);
	void __fastcall SaveMainImageDialogTypeChange(TObject *Sender);
	void __fastcall SelectEraserClick(TObject *Sender);
	void __fastcall SelectLineClick(TObject *Sender);
	void __fastcall SelectRectangleClick(TObject *Sender);
	void __fastcall SelectBrushClick(TObject *Sender);
	void __fastcall CanvasImageMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall CanvasImageMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall CanvasImageMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall ColorGridChange(TObject *Sender);
	void __fastcall SetThicknessBarChange(TObject *Sender);
	void __fastcall SelectBackgroundColorChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
