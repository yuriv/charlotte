#include "main_app.h"

int main(int argc, char* argv[])
{
	int retval = 0;
	try
	{
		main_app a(argc, argv);
		main_app::initialize();
		retval = main_app::run();
		main_app::finalize();

	}
	catch(ch_module_exc* e)
	{
		qFatal(e->what());		
	}
	catch(ch_unknown_exc* e)
	{
		qFatal(e->what());		
	}
	catch(...)
	{
		qFatal("Unexpected exception.");
	}

	return retval;
}
