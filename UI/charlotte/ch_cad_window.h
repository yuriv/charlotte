#ifndef ch_cad_window_h__
#define ch_cad_window_h__

/********************************************************************
	created:	2014/11/03
	created:	3:11:2014   13:31
	filename: 	C:\prj\charlotte\src\UI\charlotte\ch_cad_window.h
	file path:	C:\prj\charlotte\src\UI\charlotte
	file base:	ch_cad_window
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Represent CAD window
*********************************************************************/

#include <QWidget>
#include <QVTKWidget.h>

#include "..\..\ch_core.h"

class ch_cad_window : public QWidget
{
public:
	ch_cad_window();
	~ch_cad_window();

	void initialize() throw(ch_unknown_exc);
	void finalize() throw(ch_unknown_exc);

private:
	QVTKWidget* _cad_window;
};

#endif // ch_cad_window_h__