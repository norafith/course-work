#ifndef PaintUtilsH
#define PaintUtilsH

#include <System.UITypes.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.GraphUtil.hpp>

// ������ ���������.
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
		TFont* font; // ������� ������ ������ ��� ������ ��������� "�����"

		TColor backgroundColor = clWhite;

		int penThickness = 1; // �������� ������� ������� �� �������� �� �����
		// ����������� ��� ��������� ��������� �������� ������� �������
		int penThicknessMultiplier = 3;

		// ������� ���������. � ����������� �� ���������� ������ ���������,
    // �������� ��������������� ���������� ������� �� VCL
		void draw(int X, int Y, TImage* Image);

	public:
		TColor paintColor = clBlack;
		TColor outlineColor = clBlack;

		bool isDrawing; // ����, ������������, ���������� �� ������ ���������
		int posX; // ��������� ���������� X ��� ��������� �����
		int posY; // ��������� ���������� Y ��� ��������� �����

		String text; // ������� �������� ������ ��� ������ ��������� "�����"

		TColor gradientStartColor = clWhite;
		TColor gradientEndColor = clWhite;
		TGradientDirection gradientDirection = gdHorizontal;

		PaintMode paintMode = PaintMode::ELLIPSE; // ������� ����� ���������

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

// ������� ����������� ������� ��������� �� ����� ����������
extern PaintState globalPaintState;

#endif
