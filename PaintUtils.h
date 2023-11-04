//---------------------------------------------------------------------------

#ifndef PaintUtilsH
#define PaintUtilsH

#include <System.UITypes.hpp>


enum class PaintMode {
	CIRCLE,
	ERASER,
	LINE,
	RECTANGLE,
	BRUSH
};

class PaintOptions {
	public:
		PaintMode paintMode;
		TColor foregroundColor;
		TColor backgroundColor;
};



#endif
