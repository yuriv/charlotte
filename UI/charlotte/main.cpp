#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);

//#include <vtkSmartPointer.h>
//#include <vtkRenderer.h>
//#include <vtkRenderWindowInteractor.h>
//#include <vtkOrientedGlyphContourRepresentation.h>
//#include <vtkContourWidget.h>
//#include <vtkRenderWindow.h>
//
//#include <UI\qvtk_lib\QVTKApplication.h>
//#include <UI\qvtk_lib\QVTKWidget.h>

#include "ch_application.h"
#include "charlotte.h"

int main(int argc, char *argv[])
{
	int retval = 0;

	try
	{
		CHARLOTTE_INIT(argc, argv);

		ch_application a(argc, argv);

		ch_application::initialize();
		retval = ch_application::run();
		ch_application::finalize();

		CHARLOTTE_EXIT();
	}
	catch(std::exception& exc)
	{
		qFatal(exc.what());
	}

	return retval;
}
