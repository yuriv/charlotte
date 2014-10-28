#include "ch_config.h"
#include "ch_logger.h"

#include <qcoreapplication.h>
#include <qsettings.h>

pentaho_DI_desc ch_config::_data_integra_tool;
pentaho_RD_desc ch_config::_report_tool;

void pentaho_DI_desc::read_settings() throw(ch_unknown_exc, ch_cfg_exc)
{
}

void pentaho_DI_desc::write_settings() throw(ch_unknown_exc, ch_cfg_exc)
{
}

void pentaho_DI_desc::initialize() throw(ch_unknown_exc, ch_module_exc)
{
	read_settings();
}

void pentaho_DI_desc::finalize() throw(ch_unknown_exc, ch_module_exc)
{
	write_settings();
}

void pentaho_RD_desc::initialize() throw(ch_unknown_exc, ch_cfg_exc, ch_module_exc)
{
	_jar_classpath = "c:\\prj\\charlotte\\pentaho\\report-designer\\launcher.jar";
	_jar_class = "org/pentaho/commons/launcher/Launcher";
	_jar_method = "main";
	_jar_method_sgn = "([Ljava/lang/String;)V";

	read_settings();
}

void pentaho_RD_desc::finalize() throw(ch_unknown_exc, ch_module_exc)
{
	write_settings();
}

void pentaho_RD_desc::read_settings() throw(ch_unknown_exc, ch_cfg_exc)
{
	QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

	settings.beginGroup("Modules");
	_jar_classpath = settings.value("RDTOOL", QString("c:\\prj\\charlotte\\pentaho\\report-designer\\launcher.jar"))
		.toString().toStdString();
	settings.endGroup();
}

void pentaho_RD_desc::write_settings() throw(ch_unknown_exc, ch_cfg_exc)
{
	QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

	settings.beginGroup("Modules");
	settings.value("RDTOOL", QString(_jar_classpath.c_str()));
	settings.endGroup();
}

void ch_config::initialize(int argc, char* argv[]) throw(ch_unknown_exc, ch_module_exc)
{
	_data_integra_tool.initialize();
	_report_tool.initialize();
}

void ch_config::finalize()
{
	_data_integra_tool.finalize();
	_report_tool.finalize();
}
