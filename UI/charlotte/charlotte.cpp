#include <jni.h>

#include <../../jvm_wrapper.h>

#include <qmessagebox.h>

#include "charlotte.h"

using namespace std;
#pragma comment (lib,"jvm.lib")

charlotte::charlotte(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

charlotte::~charlotte()
{

}

//void charlotte::runPentahoDI()
//{
//	ch_persistent p;
//
//	ch_oid oid = p.oid();
//	for(size_t i = 0; i < 12; ++i)
//	{
//		qDebug("oid[%lu] = %d", i, oid.bytes[i]);
//	}
//
//	qDebug("Running Pentaho Data Integration.");
//
//	JavaVM *jvm;
//	JNIEnv *env;
//	JavaVMInitArgs vm_args;
//	JavaVMOption options[3];
//
//	options[0].optionString = "-Djava.compiler=NONE";           /* disable JIT */
//	options[1].optionString = "-Djava.class.path=c:\\prj\\charlotte\\pentaho\\report-designer\\launcher.jar"; /* user classes */
//	options[2].optionString = "-verbose:jni";                   /* print JNI-related messages */
//
//	vm_args.version = JNI_VERSION_1_8;
//	vm_args.nOptions = 3;
//	vm_args.options = options;
//	vm_args.ignoreUnrecognized = JNI_FALSE;
//	int ret = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
//	if(ret < 0)
//	{
//		qDebug("JVM running failed, with %d.", ret);
//		jvm->DestroyJavaVM();
//		return;
//	}
//
//	jclass cls = env->FindClass("org/pentaho/commons/launcher/Launcher");
//	if(cls != 0) 
//	{
//		jmethodID meth = env->GetStaticMethodID(cls, "main", "([Ljava/lang/String;)V");
//		jarray args = env->NewObjectArray(0, env->FindClass("java/lang/String"), 0);
//		env->CallStaticVoidMethod(cls, meth, args);
//	}
//
//	jvm->DestroyJavaVM();
//}

void charlotte::runNewProject()
{

}

void charlotte::runOpenProject()
{

}

void charlotte::runDataIntegration()
{
	ch_jvm_wrapper::_launch_data_integration(this);
}

void charlotte::runReportDesigner()
{
	ch_jvm_wrapper::_launch_report_designer(this);
}

void charlotte::runCharlotteHelp()
{

}

void charlotte::runCharlotteAbout()
{
	QString message = tr("<strong>%1</strong> %2<br />Developed by %3")
		.arg(QCoreApplication::applicationName())
		.arg(QCoreApplication::applicationVersion())
		.arg(QString("<a href=\"%1\">%2</a>")
		.arg(QCoreApplication::organizationDomain())
		.arg(QCoreApplication::organizationName()));

	QMessageBox::about(this, tr("About Charlotte"), message);
}
