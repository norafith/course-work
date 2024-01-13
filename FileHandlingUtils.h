#ifndef FileHandlingUtilsH
#define FileHandlingUtilsH
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.ExtCtrls.hpp>

class FileHandler {
	private:
		// перечисление, обозначающее доступные для сохранения расширения файлов.

		// значения членов перечисления соответствуют порядку значений,
		// заданных в поле Filter компонента SaveImageDialog
		enum class FileExtensionIndex {
			PNG = 1,
			JPG = 2,
			JPEG = 3,
			GIF = 4,
			BMP = 5,
			CUSTOM = 6,
		};

		// выбранное сейчас расширение файла для сохранения. например, ".png"
		String selectedExtension = L".png";

		// флаг, показывающий, нужно ли подгонять загружаемое изображение
		// под текущие размеры окна.
		// если true - размеры изображения подстраиваются под размеры холста
		// если false - размеры холста подстраиваются под размеры изображения
		bool shouldResizeImage = true;

	public:
		void setSelectedExtension(TSavePictureDialog* SaveMainImageDialog);
		void setShouldResizeImage(bool value);

		void saveCanvas(TSavePictureDialog* SaveMainImageDialog, TImage* MainImage, bool executeDialog = true);
		int loadImage(TSavePictureDialog* SaveMainImageDialog, TOpenPictureDialog* OpenMainImageDialog, TImage* MainImage, TImage* CanvasImage);
};

// экспорт глобального объекта обработки файлов из файла реализации
extern FileHandler globalFileHandler;
#endif
