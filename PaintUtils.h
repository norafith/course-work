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
	BRUSH
};

class PaintState {
	private:
		TColor paintColor = clBlack;
		TColor outlineColor = clBlack;
		TColor backgroundColor = clWhite;

		int penThickness = 1;
    int penThicknessMultiplier = 3;

		void draw(int X, int Y, TImage* Image);

	public:
		bool isDrawing;
		int posX;
		int posY;

		PaintMode paintMode = PaintMode::ELLIPSE;

		void onMouseMove(int X, int Y, TImage* CanvasImage, TImage* MainImage);
		void onMouseDown(int X, int Y, TImage* MainImage);
		void onMouseUp(int X, int Y, TImage* CanvasImage, TImage* MainImage);
    void onFormResize(TImage* CanvasImage, TImage* MainImage, TForm* MainForm, TPanel* ToolPanel);

		void setColors(TColor paintColorValue, TColor outlineColorValue);
		void setThickness(int thicknessValue);

    void setBackgroundColor(TColor backgroundColorValue, TImage* CanvasImage, TImage* MainImage);
};

#endif
