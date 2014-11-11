#ifndef ch_cad_window_h__
#define ch_cad_window_h__

/********************************************************************
	created:	2014/11/03
	created:	3:11:2014   13:31
	filename: 	C:\prj\charlotte\src\UI\charlotte\ch_cad_window.h
	file path:	C:\prj\charlotte\src\UI\charlotte
	file base:	ch_cad_window
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Represent CAD window
*********************************************************************/

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);

#include <vtkSmartPointer.h>
#include <vtkOrientedGlyphContourRepresentation.h>
#include <vtkContourWidget.h>
#include <vtkRenderer.h>
#include <QWidget>

#include <..\..\qvtk_lib\QVTKInteractor.h>
#include <..\..\qvtk_lib\QVTKWidget.h>

#include <ch_core.h>

class ch_cad_window : public QWidget
{
public:
	ch_cad_window();
	~ch_cad_window();

	void initialize() throw(ch_unknown_exc, std::bad_alloc);
	void finalize() throw(ch_unknown_exc, std::bad_alloc);
};

#endif // ch_cad_window_h__