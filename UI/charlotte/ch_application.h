#ifndef ch_application_h__
#define ch_application_h__

/********************************************************************
	created:	2014/11/08
	created:	8:11:2014   7:26
	filename: 	C:\prj\charlotte\src\UI\charlotte\ch_application.h
	file path:	C:\prj\charlotte\src\UI\charlotte
	file base:	ch_application
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Implements main 'Charlotte' application
*********************************************************************/

#include <UI\qvtk_lib\QVTKApplication.h>
#include <ch_core.h>

class charlotte;
class QMdiArea;

class ch_application : public QVTKApplication
{
	Q_OBJECT

public:
	ch_application(int argc, char *argv[]);
	~ch_application();

	static void initialize() throw(ch_unknown_exc, ch_module_exc);
	static void finalize() throw(ch_unknown_exc, ch_module_exc);
	
	static charlotte* main_window() throw(ch_unknown_exc, ch_module_exc);
	static QMdiArea* mdi() throw(ch_unknown_exc, ch_module_exc);

	static int run() throw(ch_unknown_exc, ch_module_exc);

private:
	static std::shared_ptr<charlotte> _main_window;
	static std::shared_ptr<QMdiArea> _mdi;
};

#endif // ch_application_h__