#ifndef jvm_wrapper_h__
#define jvm_wrapper_h__

/********************************************************************
	created:	2014/08/13
	created:	13:8:2014   17:20
	filename: 	C:\prj\charlotte\src\jvm_wrapper.h
	file path:	C:\prj\charlotte\src
	file base:	jvm_wrapper
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Java Virtual Machine wrapper
*********************************************************************/

#include <jni.h>
#include <qthread.h>

#include "ch_core.h"

struct ch_launcher : QThread
{
	Q_OBJECT

public:
	ch_launcher(QObject* parent = 0) : QThread(parent), _retval(0) {}

	int result() { return _retval; }

private:
	void run() throw(ch_unknown_exc, ch_module_exc);

	int _retval;
};

struct ch_jvm_wrapper 
{
	//ch_jvm_wrapper() {}
	//~ch_jvm_wrapper() { delete _launcher; }

	static int launch_pentaho_DI(QObject* parent = 0);
	static int launch_pentaho_RD(QObject* parent = 0);

	friend class ch_launcher;

	static ch_launcher* _launcher;

private:
	static int _launch_pentaho_DI(pentaho_DI_desc* dsc = 0);
	static int _launch_pentaho_RD(pentaho_RD_desc* dsc = 0);
};

#endif // jvm_wrapper_h__
