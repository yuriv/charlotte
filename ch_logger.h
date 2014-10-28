#ifndef ch_logger_h__
#define ch_logger_h__

/********************************************************************
	created:	2014/08/13
	created:	13:8:2014   18:44
	filename: 	C:\prj\charlotte\src\ch_logger.h
	file path:	C:\prj\charlotte\src
	file base:	ch_logger
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Charlotte log engine
*********************************************************************/

#include <QtCore/qlogging.h>

#define logd qDebug
#define logw qWarning
#define logc qCritical
#define logf qFatal

#endif // ch_logger_h__
