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

struct pentaho_DI_desc : public module_desc
{
	Q_OBJECT

	void read_settings() throw(ch_unknown_exc, ch_cfg_exc);
	void write_settings() throw(ch_unknown_exc, ch_cfg_exc);

public:
	void initialize() throw(ch_unknown_exc, ch_module_exc);
	void finalize();
};

struct pentaho_RD_desc : public module_desc
{
	Q_OBJECT
	Q_PROPERTY(std::string jar_classpath READ jar_classpath)
	Q_PROPERTY(std::string jar_class READ jar_class)
	Q_PROPERTY(std::string jar_method READ jar_method)
	Q_PROPERTY(std::string jar_method_sgn READ jar_method_sgn)

	void read_settings() throw(ch_unknown_exc, ch_cfg_exc);
	void write_settings() throw(ch_unknown_exc, ch_cfg_exc);

public:
	void initialize() throw(ch_unknown_exc, ch_module_exc);
	void finalize();

	std::string jar_classpath() { return _jar_classpath; }
	std::string jar_class() { return _jar_class; }
	std::string jar_method() { return _jar_method; }
	std::string jar_method_sgn() { return _jar_method_sgn; }

private:
	std::string _jar_classpath;
	std::string _jar_class;
	std::string _jar_method;
	std::string _jar_method_sgn;
};

struct ch_config : ch_object
{
	Q_OBJECT
	Q_PROPERTY(pentaho_DI_desc* data_integra_tool READ data_integra_tool)
	Q_PROPERTY(pentaho_RD_desc* report_tool READ report_tool)

public:
	static void initialize(int argc, char* argv[]) throw(ch_unknown_exc, ch_cfg_exc, ch_module_exc);
	static void finalize() throw(ch_unknown_exc, ch_cfg_exc);

	static pentaho_DI_desc* data_integra_tool() { return &_data_integra_tool; }
	static pentaho_RD_desc* report_tool() { return &_report_tool; }

private:
	static pentaho_DI_desc _data_integra_tool;
	static pentaho_RD_desc _report_tool;
};

#define CHARLOTTE_INIT(argc, argv) \
	ch_config::initialize(argc, argv);


#define CHARLOTTE_EXIT() \
	ch_config::finalize();

#endif // ch_config_h__
