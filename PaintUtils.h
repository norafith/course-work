#ifndef PaintUtilsH
#define PaintUtilsH

#include <System.UITypes.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.GraphUtil.hpp>

// режимы рисования.
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
		TFont* font; // текущий объект шрифта для режима рисования "текст"

		TColor backgroundColor = clWhite;

		int penThickness = 1; // значение толщины обводки из слайдера на форме
		// коэффициент для получения итогового значения толщины обводки
		int penThicknessMultiplier = 3;

		// функция рисования. в зависимости от выбранного режима рисования,
    // вызывает соответствующую встроенную функцию из VCL
		void draw(int X, int Y, TImage* Image);

	public:
		TColor paintColor = clBlack;
		TColor outlineColor = clBlack;

		bool isDrawing; // флаг, отображающий, происходит ли сейчас рисование
		int posX; // начальная координата X при рисовании фигур
		int posY; // начальная координата Y при рисовании фигур

		String text; // текущее значение текста для режима рисования "текст"

		TColor gradientStartColor = clWhite;
		TColor gradientEndColor = clWhite;
		TGradientDirection gradientDirection = gdHorizontal;

		PaintMode paintMode = PaintMode::ELLIPSE; // текущий режим рисования

    void resetState(PaintState& currentState);

		void onMouseMove(int X, int Y, TImage* CanvasImage, TImage* MainImage);
		void onMouseDown(int X, int Y, TImage* CanvasImage, TImage* MainImage);
		void onMouseUp(int X, int Y, TImage* CanvasImage, TImage* MainImage);
		void onFormResize(TImage* CanvasImage, TImage* MainImage, TForm* MainForm, TPanel* ToolPanel);

		void setThickness(int thicknessValue);

		void setBackgroundColor(TColor backgroundColorValue, TImage* CanvasImage, TImage* MainImage);
    TColor getBackgroundColor();

		void setFont(TFont* fontValue);

		void fillGradient(TImage* Image);
};

// экспорт глобального объекта состояния из файла реализации
extern PaintState globalPaintState;

#endif
