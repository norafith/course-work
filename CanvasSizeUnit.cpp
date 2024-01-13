#include <vcl.h>
#pragma hdrstop

#include "CanvasSizeUnit.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TCanvasSizeForm *CanvasSizeForm;

__fastcall TCanvasSizeForm::TCanvasSizeForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TCanvasSizeForm::WidthEditKeyPress(TObject *Sender, System::WideChar &Key)
{
	if
	(
		!(
			(Key >= L'0' && Key <= L'9') ||
			Key == L'-'  || Key == L'+' ||
			Key == L'e' || Key ==L'E' ||
			Key == FormatSettings.DecimalSeparator
		) &&
		Key != VK_BACK && Key != VK_RETURN &&
		Key != 3 && Key != 22 &&
		Key != 24 && Key != 26
	) {
		Key = 0;
	}
}

void __fastcall TCanvasSizeForm::HeightEditKeyPress(TObject *Sender, System::WideChar &Key)

{
	if
	(
		!(
			(Key >= L'0' && Key <= L'9') ||
			Key == L'-'  || Key == L'+' ||
			Key == L'e' || Key ==L'E' ||
			Key == FormatSettings.DecimalSeparator
		) &&
		Key != VK_BACK && Key != VK_RETURN &&
		Key != 3 && Key != 22 &&
		Key != 24 && Key != 26
	) {
		Key = 0;
	}
}

void __fastcall TCanvasSizeForm::SetCanvasSizeButtonClick(TObject *Sender)
{
	double canvasWidth, canvasHeight;

	try {
		canvasWidth = WidthEdit->Text.ToDouble();
	}
	catch (...) {
		String message = L"Значение \"" + String(WidthEdit->Text) + L"\" не является числом.";
		ShowMessage(message);
		WidthEdit->SetFocus();
		return;
	}

	try {
		canvasHeight = HeightEdit->Text.ToDouble();
	}
	catch (...) {
		String message = L"Значение \"" + String(WidthEdit->Text) + L"\" не является числом.";
		ShowMessage(message);
		HeightEdit->SetFocus();
		return;
	}

	long newFormWidth = canvasWidth + MainForm->ToolPanel->Width + 5;
	if (newFormWidth > Screen->DesktopWidth) {
		String message =
			L"Ширина формы не может быть больше ширины экрана. ("
			+ String(Screen->DesktopWidth) + L").";
		ShowMessage(message);
		return;
	}

	if (canvasHeight > Screen->DesktopHeight) {

		String message =
			L"Высота формы не может быть больше ширины экрана. ("
			+ String(Screen->DesktopHeight) + L").";

		Application->MessageBox(
			message.w_str(),
			String("Ошибка!").w_str(),
			MB_OK | MB_ICONERROR
		);

		return;
	}

  MainForm->ClientWidth = newFormWidth;
	MainForm->ClientHeight = canvasHeight;
}

void __fastcall TCanvasSizeForm::FormShow(TObject *Sender)
{
	WidthEdit->Text = MainForm->MainImage->Picture->Bitmap->Width;
	HeightEdit->Text = MainForm->MainImage->Picture->Bitmap->Height;
}
//---------------------------------------------------------------------------

void __fastcall TCanvasSizeForm::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (Key == 27) {
		CanvasSizeForm->Close();
	}
}
//---------------------------------------------------------------------------

