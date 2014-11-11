#ifndef ch_config_h__
#define ch_config_h__

/********************************************************************
	created:	2014/08/13
	created:	13:8:2014   18:59
	filename: 	C:\prj\charlotte\src\ch_config.h
	file path:	C:\prj\charlotte\src
	file base:	ch_config
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Charlotte configuration 
*********************************************************************/

#include <QDir>

#include "ch_object.h"
#include "ch_core.h"

struct module_desc : public ch_object
{
	Q_OBJECT

	virtual void read_settings() throw(ch_unknown_exc, ch_cfg_exc) = 0;
	virtual void write_settings() throw(ch_unknown_exc, ch_cfg_exc) = 0;

public:
	virtual void initialize() throw(ch_unknown_exc, ch_cfg_exc, ch_module_exc) = 0;
	virtual void finalize() throw(ch_unknown_exc, ch_cfg_exc) = 0; 
};

struct data_integration_desc : public module_desc
{
	Q_OBJECT

	void read_settings() throw(ch_unknown_exc, ch_cfg_exc);
	void write_settings() throw(ch_unknown_exc, ch_cfg_exc);

public:
	void initialize() throw(ch_unknown_exc, ch_module_exc);
	void finalize();
};

struct report_designer_desc : public module_desc
{
	Q_OBJECT

	Q_PROPERTY(QDir jar_classpath READ jar_classpath)
	Q_PROPERTY(QString jar_class READ jar_class)
	Q_PROPERTY(QString jar_method READ jar_method)
	Q_PROPERTY(QString jar_method_sgn READ jar_method_sgn)

	void read_settings() throw(ch_unknown_exc, ch_cfg_exc);
	void write_settings() throw(ch_unknown_exc, ch_cfg_exc);

public:
	void initialize() throw(ch_unknown_exc, ch_module_exc);
	void finalize();

	QDir jar_classpath();
	QString jar_class();
	QString jar_method();
	QString jar_method_sgn();

private:
	QDir _jar_classpath;
	QString _jar_class;
	QString _jar_method;
	QString _jar_method_sgn;
};

struct ch_config : ch_object
{
	Q_OBJECT

	Q_PROPERTY(QDir workspace_name READ QDir WRITE workspace_name)
	Q_PROPERTY(QDir workspace_path READ QDir WRITE workspace_path)
	Q_PROPERTY(QDir project_name READ QDir WRITE project_name)
	Q_PROPERTY(QDir project_path READ QDir WRITE project_path)
	Q_PROPERTY(StartupLoadProject startup_load_project READ StartupLoadProject WRITE startup_load_project)
	Q_PROPERTY(data_integration_desc* data_integration READ data_integration)
	Q_PROPERTY(report_designer_desc* report_designer READ report_designer)

	static void read_settings() throw(ch_unknown_exc, ch_cfg_exc);
	static void write_settings() throw(ch_unknown_exc, ch_cfg_exc);

public:
	enum StartupLoadProject
	{
		slpNever,
		slpNew,
		slpLast
	};

	static void initialize(int argc, char* argv[]) throw(ch_unknown_exc, ch_cfg_exc, ch_module_exc);
	static void finalize() throw(ch_unknown_exc, ch_cfg_exc);

	static QDir workspace_name() throw(ch_unknown_exc, ch_cfg_exc);
	static void workspace_name(QDir const& workspace_name) throw(ch_unknown_exc, ch_cfg_exc);
	static QDir workspace_path() throw(ch_unknown_exc, ch_cfg_exc);
	static void workspace_path(QDir const& workspace_path) throw(ch_unknown_exc, ch_cfg_exc);
	static QDir project_name() throw(ch_unknown_exc, ch_cfg_exc);
	static void project_name(QDir const& project_name) throw(ch_unknown_exc, ch_cfg_exc);
	static QDir project_path() throw(ch_unknown_exc, ch_cfg_exc);
	static void project_path(QDir const& project_path) throw(ch_unknown_exc, ch_cfg_exc);
	static StartupLoadProject startup_load_project() throw(ch_unknown_exc, ch_cfg_exc);
	static void startup_load_project(StartupLoadProject startup_load_project) throw(ch_unknown_exc, ch_cfg_exc);
	static data_integration_desc* data_integration() throw(ch_unknown_exc, ch_cfg_exc);
	static report_designer_desc* report_designer() throw(ch_unknown_exc, ch_cfg_exc);

private:
	static QDir _workspace_name;
	static QDir _workspace_path;
	static QDir _project_name;
	static QDir _project_path;
	static StartupLoadProject _startup_load_project;
	static data_integration_desc _data_integration;
	static report_designer_desc _report_designer;
};

#define CHARLOTTE_INIT(argc, argv) \
	ch_config::initialize(argc, argv); 


#define CHARLOTTE_EXIT() \
	ch_config::finalize();

#endif // ch_config_h__
