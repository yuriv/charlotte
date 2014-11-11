#include <QMdiArea>

#include "ch_application.h"
#include "charlotte.h"

std::shared_ptr<charlotte> ch_application::_main_window = NULL;
std::shared_ptr<QMdiArea> ch_application::_mdi = NULL;

ch_application::ch_application(int argc, char *argv[]) 
	: QVTKApplication(argc, argv)
{

}

ch_application::~ch_application()
{

}

void ch_application::initialize() throw(ch_unknown_exc, ch_module_exc)
{
	_main_window.reset(new charlotte());
	EXCASS((_main_window != NULL), ch_module_exc("Application main window isn't initialized."))

	QWidget* cw = _main_window->centralWidget();
	QMdiArea* mdi = cw->findChild<QMdiArea*>("mdiArea");
	EXCASS((mdi != NULL), ch_module_exc("MDI area isn't initialized."))

	_mdi.reset(mdi);

	setApplicationName("Charlotte");
	setApplicationVersion("0.0.1a");
	setOrganizationName("IMT, Ltd.");
	setOrganizationDomain("http://www.i-m-t.com");
}

void ch_application::finalize() throw(ch_unknown_exc, ch_module_exc)
{

}

charlotte* ch_application::main_window() throw(ch_unknown_exc, ch_module_exc)
{
	return _main_window.get();
}

QMdiArea* ch_application::mdi() throw(ch_unknown_exc, ch_module_exc) 
{ 
	return _mdi.get(); 
}

int ch_application::run() throw(ch_unknown_exc, ch_module_exc)
{
	_main_window->show();
	return exec();
}
