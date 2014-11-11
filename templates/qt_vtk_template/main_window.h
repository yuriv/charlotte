#ifndef main_widow_h__
#define main_widow_h__

/********************************************************************
	created:	2014/11/10
	created:	10:11:2014   11:13
	filename: 	C:\prj\charlotte\src\templates\qt_vtk_template\main_widow.h
	file path:	C:\prj\charlotte\src\templates\qt_vtk_template
	file base:	main_widow
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Problem main window
*********************************************************************/

#include <QWidget>

#include <ch_core.h>

class main_window : public QWidget
{
public:
	main_window();
	~main_window();

	void initialize() throw(ch_unknown_exc, ch_module_exc, std::bad_alloc);
	void finalize() throw(ch_unknown_exc, ch_module_exc);
};

#endif // main_widow_h__