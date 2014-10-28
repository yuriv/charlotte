#ifndef ch_except_h__
#define ch_except_h__

/********************************************************************
	created:	2014/08/13
	created:	13:8:2014   19:35
	filename: 	C:\prj\charlotte\src\ch_except.h
	file path:	C:\prj\charlotte\src
	file base:	ch_except
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Charlotte exception handling
*********************************************************************/

#include <assert.h>
#include <exception>

#include <string>
#include <boost/lexical_cast.hpp>

struct ch_unknown_exc : public std::exception
{
};

struct ch_cfg_exc : public std::exception
{
};

struct ch_module_exc : public std::exception
{
	ch_module_exc() : _retval(0), _msg("Unexpected error!") {}
	ch_module_exc(char const* msg) : _retval(0), _msg(msg) {}
	ch_module_exc(int retval, char const* msg) : _retval(retval), _msg(std::string(msg) + boost::lexical_cast<std::string>(retval)) {}

	int get_result() { return _retval; }
	char const* get_message() { return _msg.c_str(); }

private:
	int _retval;
	std::string _msg;
};

#endif // ch_except_h__