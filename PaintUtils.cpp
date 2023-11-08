//---------------------------------------------------------------------------

#pragma hdrstop

#include "PaintUtils.h"

void PaintState::draw(int X, int Y, TImage* Image) {
	Image->Picture->Bitmap->Canvas->Brush->Color = paintColor;
	// set opacity

	switch (paintMode) {
		case PaintMode::ELLIPSE:
      Image->Picture->Bitmap->Canvas->Ellipse(posX, posY, X, Y);
			break;

		case PaintMode::ERASER:
			break;

		case PaintMode::LINE:
      Image->Picture->Bitmap->Canvas->MoveTo(posX, posY);
			Image->Picture->Bitmap->Canvas->LineTo(X, Y);
			break;

		case PaintMode::RECTANGLE:
    	Image->Picture->Bitmap->Canvas->Rectangle(posX, posY, X, Y);
			break;

    case PaintMode::BRUSH:
			break;
	}

}

void PaintState::onMouseDown(int X, int Y) {
	isDrawing = true;
	posX = X;
	posY = Y;
}

void PaintState::onMouseMove(int X, int Y, TImage* CanvasImage) {
	if (!isDrawing) return;

  CanvasImage->Picture->Bitmap->Canvas->Rectangle(0, 0, clWhite, CanvasImage->Width);
	draw(X, Y, CanvasImage);
}

void PaintState::onMouseUp(int X, int Y, TImage* CanvasImage, TImage* MainImage) {
	if (!isDrawing) return;

	CanvasImage->Picture->Bitmap->Canvas->Rectangle(0, 0, clWhite, CanvasImage->Width);
	draw(X, Y, MainImage);

  isDrawing = false;
}

#pragma package(smart_init)
