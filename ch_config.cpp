#include "ch_config.h"
#include "ch_logger.h"

#include <qcoreapplication.h>
#include <qsettings.h>

QDir ch_config::_workspace_name;
QDir ch_config::_workspace_path;
QDir ch_config::_project_name;
QDir ch_config::_project_path;
ch_config::StartupLoadProject ch_config::_startup_load_project;
data_integration_desc ch_config::_data_integration;
report_designer_desc ch_config::_report_designer;

void data_integration_desc::read_settings() throw(ch_unknown_exc, ch_cfg_exc)
{
}

void data_integration_desc::write_settings() throw(ch_unknown_exc, ch_cfg_exc)
{
}

void data_integration_desc::initialize() throw(ch_unknown_exc, ch_module_exc)
{
	read_settings();
}

void data_integration_desc::finalize() throw(ch_unknown_exc, ch_module_exc)
{
	write_settings();
}

void report_designer_desc::initialize() throw(ch_unknown_exc, ch_cfg_exc, ch_module_exc)
{
	_jar_classpath = "c:\\prj\\charlotte\\pentaho\\report-designer\\launcher.jar";
	_jar_class = "org/pentaho/commons/launcher/Launcher";
	_jar_method = "main";
	_jar_method_sgn = "([Ljava/lang/String;)V";

	read_settings();
}

void report_designer_desc::finalize() throw(ch_unknown_exc, ch_module_exc)
{
	write_settings();
}

void report_designer_desc::read_settings() throw(ch_unknown_exc, ch_cfg_exc)
{
	QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

	settings.beginGroup("Modules");
	_jar_classpath = settings.value("ReportDesigner", QString("c:\\prj\\charlotte\\pentaho\\report-designer\\launcher.jar")).toString();
	settings.endGroup();
}

void report_designer_desc::write_settings() throw(ch_unknown_exc, ch_cfg_exc)
{
	QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

	settings.beginGroup("Modules");
	settings.setValue("ReportDesigner", _jar_classpath.path());
	settings.endGroup();
}

QDir report_designer_desc::jar_classpath() 
{ 
	return _jar_classpath; 
}

QString report_designer_desc::jar_class() 
{ 
	return _jar_class; 
}

QString report_designer_desc::jar_method() 
{ 
	return _jar_method; 
}

QString report_designer_desc::jar_method_sgn() 
{ 
	return _jar_method_sgn; 
}

void ch_config::read_settings() throw(ch_unknown_exc, ch_cfg_exc)
{
	QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

	settings.beginGroup("Config");
	_workspace_name = settings.value("WorkspaceName").toString();
	_workspace_path = settings.value("WorkspacePath").toString();
	_project_name = settings.value("ProjectName").toString();
	_project_path = settings.value("ProjectPath").toString();
	_startup_load_project = static_cast<StartupLoadProject>(settings.value("StartupLoadProject").toUInt());
	settings.endGroup();
}

void ch_config::write_settings() throw(ch_unknown_exc, ch_cfg_exc)
{
	QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

	settings.beginGroup("Config");
	settings.setValue("WorkspaceName", _workspace_name.path());
	settings.setValue("WorkspacePath", _workspace_path.path());
	settings.setValue("ProjectName", _project_name.path());
	settings.setValue("ProjectPath", _project_path.path());
	settings.setValue("StartupLoadProject", _startup_load_project);
	settings.endGroup();
}

void ch_config::initialize(int argc, char* argv[]) throw(ch_unknown_exc, ch_module_exc)
{
	_data_integration.initialize();
	_report_designer.initialize();

	ch_config::read_settings();
}

void ch_config::finalize()
{
	_data_integration.finalize();
	_report_designer.finalize();

	ch_config::write_settings();
}

QDir ch_config::workspace_name() throw(ch_unknown_exc, ch_cfg_exc) 
{ 
	return _workspace_name; 
}

void ch_config::workspace_name(QDir const& workspace_name) throw(ch_unknown_exc, ch_cfg_exc)
{
	_workspace_name = workspace_name;
}

QDir ch_config::workspace_path() throw(ch_unknown_exc, ch_cfg_exc) 
{
	return _workspace_path; 
}

void ch_config::workspace_path(QDir const& workspace_path) throw(ch_unknown_exc, ch_cfg_exc)
{
	_workspace_path = workspace_path;
}

QDir ch_config::project_name() throw(ch_unknown_exc, ch_cfg_exc) 
{ 
	return _project_name; 
}

void ch_config::project_name(QDir const& project_name) throw(ch_unknown_exc, ch_cfg_exc)
{
	_project_name = project_name;
}

QDir ch_config::project_path() throw(ch_unknown_exc, ch_cfg_exc)
{
	return _project_path;
}

void ch_config::project_path(QDir const& project_path) throw(ch_unknown_exc, ch_cfg_exc) 
{ 
	_project_path = project_path; 
}

ch_config::StartupLoadProject ch_config::startup_load_project() throw(ch_unknown_exc, ch_cfg_exc) 
{ 
	return _startup_load_project;
}

void ch_config::startup_load_project(ch_config::StartupLoadProject startup_load_project) throw(ch_unknown_exc, ch_cfg_exc) 
{ 
	_startup_load_project = startup_load_project; 
}

data_integration_desc* ch_config::data_integration() throw(ch_unknown_exc, ch_cfg_exc) 
{ 
	return &_data_integration; 
}

report_designer_desc* ch_config::report_designer() throw(ch_unknown_exc, ch_cfg_exc) 
{ 
	return &_report_designer; 
}
