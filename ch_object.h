#ifndef ch_object_h__
#define ch_object_h__

/********************************************************************
	created:	2014/08/20
	created:	20:8:2014   15:36
	filename: 	C:\prj\charlotte\src\ch_object.h
	file path:	C:\prj\charlotte\src
	file base:	ch_object
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Charlotte base class
*********************************************************************/

#include <qobject.h>

#include <bson.h>

typedef bson_oid_t ch_oid;

struct ch_object : QObject
{
	Q_OBJECT
};

struct ch_persistent : ch_object
{
	Q_OBJECT
	Q_PROPERTY(ch_oid oid READ oid)

public:
	ch_persistent() { bson_oid_init(&_oid, NULL); }

	ch_oid oid() const { return _oid; }

protected:
	ch_persistent(ch_oid oid) : _oid(oid) {}

private:
	ch_oid _oid;
};

#endif // ch_object_h__
