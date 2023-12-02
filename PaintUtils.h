//---------------------------------------------------------------------------

#ifndef PaintUtilsH
#define PaintUtilsH

#include <System.UITypes.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

enum class PaintMode {
	ELLIPSE,
	ERASER,
	LINE,
	RECTANGLE,
	BRUSH,
	FILL,
  TEXT
};

class PaintState {
	private:
		TColor paintColor = clBlack;
		TColor outlineColor = clBlack;
		TColor backgroundColor = clWhite;

		TFont* font;
    String text;

		int penThickness = 1;
    int penThicknessMultiplier = 3;

		void draw(int X, int Y, TImage* Image);

	public:
		bool isDrawing;
		int posX;
		int posY;

		TColor gradientStartColor = clWhite;
    TColor gradientEndColor = clWhite;

		PaintMode paintMode = PaintMode::ELLIPSE;

		void onMouseMove(int X, int Y, TImage* CanvasImage, TImage* MainImage);
		void onMouseDown(int X, int Y, TImage* CanvasImage, TImage* MainImage);
		void onMouseUp(int X, int Y, TImage* CanvasImage, TImage* MainImage);
    void onFormResize(TImage* CanvasImage, TImage* MainImage, TForm* MainForm, TPanel* ToolPanel);

		void setColors(TColor paintColorValue, TColor outlineColorValue);
		void setThickness(int thicknessValue);

		void setBackgroundColor(TColor backgroundColorValue, TImage* CanvasImage, TImage* MainImage);
		void setFont(TFont* fontValue);
		void setText(String textValue);
};

extern PaintState globalPaintState;

#endif
