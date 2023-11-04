//---------------------------------------------------------------------------

#ifndef PaintUtilsH
#define PaintUtilsH

#include <System.UITypes.hpp>

class PaintState {
	private:
    enum class PaintMode {
			CIRCLE,
			ERASER,
			LINE,
			RECTANGLE,
			BRUSH
		};

	public:
		bool isDrawing;
		float xPos;
    float yPos;

		PaintMode paintMode;
		TColor foregroundColor;
		TColor backgroundColor;

		void onMouseMove();
		void onMouseDown();
		void onMouseUp();
};

#endif
