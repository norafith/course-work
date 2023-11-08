//---------------------------------------------------------------------------

#ifndef PaintUtilsH
#define PaintUtilsH

#include <System.UITypes.hpp>
#include "MainUnit.h"

enum class PaintMode {
	ELLIPSE,
	ERASER,
	LINE,
	RECTANGLE,
	BRUSH
};

class PaintState {
	private:
    void draw(int X, int Y, TImage* Image);

	public:
		bool isDrawing;
		int posX;
		int posY;

		PaintMode paintMode = PaintMode::ELLIPSE;
		TColor paintColor = clWhite;
		TColor backgroundColor;
    int opacity;

		void onMouseMove(int X, int Y, TImage* CanvasImage);
		void onMouseDown(int X, int Y);
		void onMouseUp(int X, int Y, TImage* CanvasImage, TImage* MainImage);
};

#endif
