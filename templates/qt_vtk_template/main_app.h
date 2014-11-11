#ifndef main_app_h__
#define main_app_h__

/********************************************************************
	created:	2014/11/10
	created:	10:11:2014   11:31
	filename: 	C:\prj\charlotte\src\templates\qt_vtk_template\main_app.h
	file path:	C:\prj\charlotte\src\templates\qt_vtk_template
	file base:	main_app
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Implements problem application
*********************************************************************/

#include <..\..\..\UI\qvtk_lib\QVTKApplication.h>

#include <ch_core.h>

class QMdiArea;
class app;

class main_app : public QVTKApplication
{
	Q_OBJECT

public:
	main_app(int argc, char *argv[]);
	~main_app();

	static void initialize() throw(ch_unknown_exc, ch_module_exc);
	static void finalize() throw(ch_unknown_exc, ch_module_exc);

	static app* main_window() throw(ch_unknown_exc, ch_module_exc);
	static QMdiArea* mdi() throw(ch_unknown_exc, ch_module_exc);

	static int run() throw(ch_unknown_exc, ch_module_exc);

private:
	static std::shared_ptr<app> _main_window;
	static std::shared_ptr<QMdiArea> _mdi;
};

#endif // main_app_h__