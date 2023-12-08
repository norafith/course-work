//---------------------------------------------------------------------------

#pragma hdrstop

#include "PaintUtils.h"

PaintState globalPaintState;

void PaintState::draw(int X, int Y, TImage* Image) {
	Image->Picture->Bitmap->Canvas->Brush->Color = paintColor;
	Image->Picture->Bitmap->Canvas->Pen->Color = outlineColor;
	Image->Picture->Bitmap->Canvas->Pen->Width = penThickness;
	int thicknessAdditive = penThickness * penThicknessMultiplier;

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

		case PaintMode::TEXT:
			// TODO
 			Image->Picture->Bitmap->Canvas->Font = font;
			TRect tmpRect = TRect(posX, posY, X, Y);
      Image->Picture->Bitmap->Canvas->Font = font;
//      Image->Picture->Bitmap->Canvas->Font->Color = outlineColor;
			Image->Picture->Bitmap->Canvas->TextRect(tmpRect, posX, posY, text);

			break;

//		case PaintMode::FILL:
//      TColor colorToFill = Image->Picture->Bitmap->Canvas->Pixels[X][Y];
//			Image->Picture->Bitmap->Canvas->FloodFill(X, Y, colorToFill, fsSurface);
//			break;

	}
}

void PaintState::onMouseDown(int X, int Y, TImage* CanvasImage, TImage* MainImage) {
	if (paintMode == PaintMode::FILL) {
    draw(X, Y, CanvasImage);
		draw(X, Y, MainImage);
    return;
	}
	isDrawing = true;
	posX = X;
	posY = Y;
//
//	if (paintMode == PaintMode::BRUSH || paintMode == PaintMode::ERASER) {
//		draw(X, Y, MainImage);
//	}

}

void PaintState::onMouseMove(int X, int Y, TImage* CanvasImage, TImage* MainImage) {
	if (!isDrawing || paintMode == PaintMode::FILL) return;

	if (paintMode == PaintMode::BRUSH || paintMode == PaintMode::ERASER) {
		draw(X, Y, MainImage);
	}
//
//	TRect tmpRect = Rect(Point(posX, posY), Point(X, Y));
//	CanvasImage->Picture->Bitmap->Canvas->CopyRect(tmpRect, CanvasImage->Picture->Bitmap->Canvas, tmpRect);
//	draw(X, Y, CanvasImage);

	CanvasImage->Picture->Bitmap->Assign(MainImage->Picture->Bitmap);
	draw(X, Y, CanvasImage);

}

void PaintState::onMouseUp(int X, int Y, TImage* CanvasImage, TImage* MainImage) {
	if (!isDrawing || paintMode == PaintMode::FILL) return;
	if (paintMode == PaintMode::BRUSH || paintMode == PaintMode::ERASER) {
		isDrawing = false;
		return;
	}



	draw(X, Y, MainImage);
  CanvasImage->Picture->Bitmap->Assign(MainImage->Picture->Bitmap);
	isDrawing = false;
}

void PaintState::onFormResize(TImage* CanvasImage, TImage* MainImage, TForm* MainForm, TPanel* ToolPanel) {
	MainImage->Picture->Bitmap->Canvas->Brush->Color = backgroundColor;
	MainImage->Width = MainForm->Width - ToolPanel->Width - 5;
	MainImage->Picture->Bitmap->Width = MainForm->ClientWidth - ToolPanel->Width - 5;
	MainImage->Height = MainForm->Height;
	MainImage->Picture->Bitmap->Height = MainForm->ClientHeight;
	MainImage->Picture->Bitmap->Canvas->Brush->Color = paintColor;

	MainImage->Picture->Bitmap->Canvas->Brush->Color = backgroundColor;
	CanvasImage->Picture->Bitmap->Canvas->Brush->Color = backgroundColor;
	CanvasImage->Width = MainForm->Width - ToolPanel->Width - 5;
	CanvasImage->Picture->Bitmap->Width = MainForm->ClientWidth - ToolPanel->Width - 5;
	CanvasImage->Height = MainForm->Height;
	CanvasImage->Picture->Bitmap->Height = MainForm->ClientHeight;
	CanvasImage->Picture->Bitmap->Canvas->Brush->Color = paintColor;
	MainImage->Picture->Bitmap->Canvas->Brush->Color = paintColor;
 }

void PaintState::setColors(TColor paintColorValue, TColor outlineColorValue) {
	paintColor = paintColorValue;
	outlineColor = outlineColorValue;
}

void PaintState::setThickness(int thicknessValue) {
	penThickness = thicknessValue;
}

void PaintState::setBackgroundColor(TColor backgroundColorValue, TImage* CanvasImage, TImage* MainImage) {
//  backgroundMode = BackgroundMode::COLOR;
	backgroundColor = backgroundColorValue;
	MainImage->Picture->Bitmap->Canvas->Brush->Color = backgroundColor;
	MainImage->Picture->Bitmap->Canvas->Rectangle(0, 0, MainImage->Width, MainImage->Height);
	CanvasImage->Picture->Bitmap->Canvas->Brush->Color = backgroundColor;
	CanvasImage->Picture->Bitmap->Canvas->Rectangle(0, 0, CanvasImage->Width, CanvasImage->Height);
}

void PaintState::setFont(TFont* fontValue) {
  font = fontValue;
};

void PaintState::setText(String textValue) {
  text = textValue;
}

void PaintState::fillGradient(TImage* Image) {
	GradientFillCanvas(
		Image->Picture->Bitmap->Canvas,
		gradientStartColor,
		gradientEndColor,
		TRect(TPoint(0, 0), Image->Width, Image->Height),
    gradientDirection
	);

  Image->Picture->Bitmap->Assign(Image->Picture->Bitmap);
}

#pragma package(smart_init)
