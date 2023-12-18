//---------------------------------------------------------------------------

#ifndef FileHandlingUtilsH
#define FileHandlingUtilsH
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.ExtCtrls.hpp>
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
		bool shouldResizeImage = true;

	public:
		void setSelectedExtension(TSavePictureDialog* SaveMainImageDialog);
    void setShouldResizeImage(bool value);

		void saveCanvas(TSavePictureDialog* SaveMainImageDialog, TImage* MainImage);
		int loadImage(TSavePictureDialog* OpenMainImageDialog, TImage* MainImage, TImage* CanvasImage);
};

extern FileHandler globalFileHandler;
#endif
