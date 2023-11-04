//---------------------------------------------------------------------------

#ifndef FileHandlingUtilsH
#define FileHandlingUtilsH
#include "MainUnit.h"
//---------------------------------------------------------------------------

class FileHandler {
	private:
		enum class FileExtensionIndex {
			PNG = 1,
			JPG = 2,
			JPEG = 3,
			GIF = 4,
			BMP = 5,
			CUSTOM = 6,
		};

		String selectedExtension;

	public:
		void setSelectedExtension(TSavePictureDialog* SaveMainImageDialog);

		void saveCanvas(TSavePictureDialog* SaveMainImageDialog, TImage* MainImage);

		void loadImage(TSavePictureDialog* OpenMainImageDialog, TImage* MainImage);
};

#endif
