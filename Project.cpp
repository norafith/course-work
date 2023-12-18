//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("MainUnit.cpp", MainForm);
USEFORM("DrawTextUnit.cpp", DrawTextForm);
USEFORM("GradientUnit.cpp", GradientForm);
USEFORM("CanvasSizeUnit.cpp", CanvasSizeForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->Title = "Графический редактор";
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TGradientForm), &GradientForm);
		Application->CreateForm(__classid(TDrawTextForm), &DrawTextForm);
		Application->CreateForm(__classid(TCanvasSizeForm), &CanvasSizeForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
