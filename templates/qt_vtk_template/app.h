#ifndef app_h__
#define app_h__

/********************************************************************
	created:	2014/11/09
	created:	9:11:2014   11:39
	filename: 	C:\prj\charlotte\src\templates\qt_vtk_template\app.h
	file path:	C:\prj\charlotte\src\templates\qt_vtk_template
	file base:	app
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	
*********************************************************************/

#include <QMainWindow>

#include <ch_core.h>

#include "ui_app.h"

class app : public QMainWindow
{
	Q_OBJECT

public:
	app(QWidget* parent = 0);
	~app();

public slots:
	void runNewProblem();
	void runOpenProblem();

private:
	Ui::MainWindow ui;
};

#endif // app_h__
