#ifndef MainUnitH
#define MainUnitH

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

#include "FileHandlingUtils.h"
#include "PaintUtils.h"
#include "GradientUnit.h"
#include "DrawTextUnit.h"
#include "CanvasSizeUnit.h"

class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TImage *MainImage;
	TMainMenu *MainMenu;
	TMenuItem *FileMenu;
	TMenuItem *SaveAsMenuItem;
	TMenuItem *OpenFileMenuItem;
	TSavePictureDialog *SaveImageDialog;
	TOpenPictureDialog *OpenImageDialog;
	TImage *CanvasImage;
	TPanel *ToolPanel;
	TMenuItem *CanvasMenu;
	TMenuItem *SetCanvasSizeMenuItem;
	TMenuItem *ShouldResizeImageMenuItem;
	TColorDialog *PaintColorDialog;
	TColorDialog *OutlineColorDialog;
	TColorDialog *BackgroundColorDialog;
	TScrollBox *ToolScrollBox;
	TSpeedButton *SelectBrush;
	TSpeedButton *SelectCircle;
	TSpeedButton *SelectEraser;
	TPanel *PaintColorPanel;
	TSpeedButton *PaintColorButton;
	TLabel *PaintColorLabel;
	TPanel *OutlineColorPanel;
	TSpeedButton *OutlineColorButton;
	TLabel *OutlineColorLabel;
	TPanel *BackgroundColorPanel;
	TSpeedButton *BackgroundColorButton;
	TButton *GradientBackgroundButton;
	TLabel *BackgroundColorLabel;
	TSpeedButton *SelectFill;
	TSpeedButton *SelectLine;
	TSpeedButton *SelectRectangle;
	TSpeedButton *SelectText;
	TTrackBar *SetThicknessBar;
	TLabel *ThicknessLabel;
	TMenuItem *SaveMenuItem;
	TMenuItem *CloseMenuItem;
	TMenuItem *NewMenuItem;
	void __fastcall SelectCircleClick(TObject *Sender);
	void __fastcall SaveAsMenuItemClick(TObject *Sender);
	void __fastcall OpenFileMenuItemClick(TObject *Sender);
	void __fastcall SaveImageDialogTypeChange(TObject *Sender);
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
	void __fastcall SetThicknessBarChange(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall SelectFillClick(TObject *Sender);
	void __fastcall GradientBackgroundButtonClick(TObject *Sender);
	void __fastcall SelectTextClick(TObject *Sender);
	void __fastcall ShouldResizeImageMenuItemClick(TObject *Sender);
	void __fastcall SetCanvasSizeMenuItemClick(TObject *Sender);
	void __fastcall OutlineColorDialogShow(TObject *Sender);
	void __fastcall PaintColorDialogShow(TObject *Sender);
	void __fastcall PaintColorButtonClick(TObject *Sender);
	void __fastcall OutlineColorButtonClick(TObject *Sender);
	void __fastcall BackgroundColorDialogShow(TObject *Sender);
	void __fastcall BackgroundColorButtonClick(TObject *Sender);
	void __fastcall SaveMenuItemClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall CloseMenuItemClick(TObject *Sender);
	void __fastcall NewMenuItemClick(TObject *Sender);
private:	// User declarations
	void removePaintButtonsSelectedFocus();
  void initializeImagesBitmap();
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};

extern PACKAGE TMainForm *MainForm;

#endif
