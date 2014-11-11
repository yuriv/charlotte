#ifndef ch_core_h__
#define ch_core_h__

/********************************************************************
	created:	2014/08/13
	created:	13:8:2014   19:58
	filename: 	C:\prj\charlotte\src\ch_core.h
	file path:	C:\prj\charlotte\src
	file base:	ch_core
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Charlotte core components
*********************************************************************/
#include <stdint.h>
#include <string>
#include <memory>
#include <assert.h>

#include "ch_except.h"
#include "ch_logger.h"
#include "ch_config.h"
#include "ch_object.h"

#define EXCASS(stmt, exc) \
	assert(stmt); \
	if(!stmt) throw exc;

#endif // ch_core_h__
