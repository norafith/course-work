//---------------------------------------------------------------------------

#pragma hdrstop

#include "PaintUtils.h"

void PaintState::draw(int X, int Y, TImage* Image) {
	Image->Picture->Bitmap->Canvas->Brush->Color = paintColor;
	Image->Picture->Bitmap->Canvas->Pen->Color = outlineColor;
	int thicknessAdditive = brushThickness * brushThicknessMultiplier;

	switch (paintMode) {
		case PaintMode::ELLIPSE:
			Image->Picture->Bitmap->Canvas->Ellipse(posX, posY, X, Y);
			break;

		case PaintMode::ERASER:
			Image->Picture->Bitmap->Canvas->Brush->Color = backgroundColor;
			Image->Picture->Bitmap->Canvas->Pen->Color = backgroundColor;
			Image->Picture->Bitmap->Canvas->Ellipse(
				X - thicknessAdditive,
				Y - thicknessAdditive,
				X + thicknessAdditive,
				Y + thicknessAdditive
			);
			break;

		case PaintMode::LINE:
			Image->Picture->Bitmap->Canvas->MoveTo(posX, posY);
			Image->Picture->Bitmap->Canvas->LineTo(X, Y);
			break;

		case PaintMode::RECTANGLE:
			Image->Picture->Bitmap->Canvas->Rectangle(posX, posY, X, Y);
			break;

		case PaintMode::BRUSH:
			Image->Picture->Bitmap->Canvas->Pen->Color = paintColor;
			Image->Picture->Bitmap->Canvas->Ellipse(
				X - thicknessAdditive,
				Y - thicknessAdditive,
				X + thicknessAdditive,
				Y + thicknessAdditive
			);
			break;
	}
}

void PaintState::onMouseDown(int X, int Y, TImage* MainImage) {
	isDrawing = true;
	posX = X;
	posY = Y;
//
//	if (paintMode == PaintMode::BRUSH || paintMode == PaintMode::ERASER) {
//		draw(X, Y, MainImage);
//	}

}

void PaintState::onMouseMove(int X, int Y, TImage* CanvasImage, TImage* MainImage) {
	if (!isDrawing) return;

	if (paintMode == PaintMode::BRUSH || paintMode == PaintMode::ERASER) {
		draw(X, Y, MainImage);
	}
	CanvasImage->Picture->Bitmap->Canvas->Brush->Color = backgroundColor;
	CanvasImage->Picture->Bitmap->Canvas->Rectangle(0, 0, CanvasImage->Width, CanvasImage->Height);
	CanvasImage->Picture->Bitmap->Canvas->Brush->Color = paintColor;
	draw(X, Y, CanvasImage);
}

void PaintState::onMouseUp(int X, int Y, TImage* CanvasImage, TImage* MainImage) {
	if (!isDrawing) return;
	if (paintMode == PaintMode::BRUSH || paintMode == PaintMode::ERASER) {
		isDrawing = false;
		return;
	}

	CanvasImage->Picture->Bitmap->Canvas->Brush->Color = backgroundColor;
	CanvasImage->Picture->Bitmap->Canvas->Rectangle(0, 0, CanvasImage->Width, CanvasImage->Height);
	CanvasImage->Picture->Bitmap->Canvas->Brush->Color = paintColor;

	draw(X, Y, MainImage);

	isDrawing = false;
}

void PaintState::setColors(TColor paintColorValue, TColor outlineColorValue) {
	paintColor = paintColorValue;
	outlineColor = outlineColorValue;
}

void PaintState::setThickness(int thicknessValue) {
	brushThickness = thicknessValue;
}

void PaintState::setBackgroundColor(TColor backgroundColorValue, TImage* CanvasImage, TImage* MainImage) {
	backgroundColor = backgroundColorValue;
	MainImage->Picture->Bitmap->Canvas->Brush->Color = backgroundColor;
	MainImage->Picture->Bitmap->Canvas->Rectangle(0, 0, MainImage->Width, MainImage->Height);
	CanvasImage->Picture->Bitmap->Canvas->Brush->Color = backgroundColor;
	CanvasImage->Picture->Bitmap->Canvas->Rectangle(0, 0, CanvasImage->Width, CanvasImage->Height);
}

#pragma package(smart_init)
