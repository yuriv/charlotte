#include "charlotte.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	CHARLOTTE_INIT(argc, argv);

	QApplication a(argc, argv);

	a.setApplicationName("Charlotte");
	a.setApplicationVersion("0.0.1a");
	a.setOrganizationName("IMT, Ltd.");
	a.setOrganizationDomain("http://www.i-m-t.com");

	charlotte w;
	w.show();

	int retval = a.exec();

	CHARLOTTE_EXIT();

	return retval;
}
