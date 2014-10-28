#include "jvm_wrapper.h"

int ch_jvm_wrapper::_launch_pentaho_RD(pentaho_RD_desc* dsc)
{
	const size_t options_count = 2;

	JavaVM *jvm;
	JNIEnv *env;
	JavaVMInitArgs vm_args;
	JavaVMOption options[options_count];

	if(dsc == NULL)
	{
		dsc = ch_config::report_tool();
	}

	std::string classpath("-Djava.class.path=");
	classpath += dsc->jar_classpath();

//	options[0].optionString = "-Djava.compiler=NONE";           /* disable JIT */
//	options[1].optionString = const_cast<char*>(classpath.c_str());				//"-Djava.class.path=c:\\prj\\charlotte\\pentaho\\report-designer\\launcher.jar"; /* user classes */
//	options[2].optionString = "-verbose:jni";                   /* print JNI-related messages */
	options[0].optionString = const_cast<char*>(classpath.c_str());				//"-Djava.class.path=c:\\prj\\charlotte\\pentaho\\report-designer\\launcher.jar"; /* user classes */
	options[1].optionString = "-verbose:jni";                   /* print JNI-related messages */

	vm_args.version = JNI_VERSION_1_8;
//	vm_args.nOptions = 3;
	vm_args.nOptions = options_count;
	vm_args.options = options;
	vm_args.ignoreUnrecognized = JNI_FALSE;
	int ret = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
	if(ret < 0)
	{
		logd("JVM running failed, with %d.", ret);
		jvm->DestroyJavaVM();
		return ret;
	}

//	jclass cls = env->FindClass("org/pentaho/commons/launcher/Launcher");
	jclass cls = env->FindClass(dsc->jar_class().c_str());
	if(cls != 0) 
	{
		jmethodID meth = env->GetStaticMethodID(cls, dsc->jar_method().c_str(), dsc->jar_method_sgn().c_str()
			/*"([Ljava/lang/String;)V"*/);
		jstring js = env->NewStringUTF("Default");
		env->CallStaticVoidMethod(cls, meth, js);
	}

	return jvm->DestroyJavaVM();
}

void ch_launcher::run() throw(ch_unknown_exc, ch_module_exc)
{
	pentaho_RD_desc* dsc = ch_config::report_tool();

	_retval = ch_jvm_wrapper::_launch_pentaho_RD(dsc);
	if(_retval < 0)
	{
		char const* msg = "Module \"Pentaho Report Designer\" failed to run, with code: ";
		logd(msg, _retval);
		throw ch_module_exc(_retval, msg);
	}
	// Modal state, if will be uncommented
	//exec();
}

ch_launcher* ch_jvm_wrapper::_launcher = NULL;

int ch_jvm_wrapper::launch_pentaho_RD(QObject* parent)
{
//	ch_launcher launcher(parent);

	//launcher.start();
	//launcher.wait();
	if(ch_jvm_wrapper::_launcher == NULL)
	{
		ch_jvm_wrapper::_launcher = new ch_launcher();
	}

	ch_jvm_wrapper::_launcher->start();
	ch_jvm_wrapper::_launcher->wait();

//	return launcher.result();
	return ch_jvm_wrapper::_launcher->result();
}

int ch_jvm_wrapper::launch_pentaho_DI(QObject* parent)
{
	return 0;
}
