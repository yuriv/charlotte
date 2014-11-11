#ifndef new_problem_form_h__
#define new_problem_form_h__

/********************************************************************
	created:	2014/11/10
	created:	10:11:2014   13:16
	filename: 	C:\prj\charlotte\src\templates\qt_vtk_template\new_problem_form.h
	file path:	C:\prj\charlotte\src\templates\qt_vtk_template
	file base:	new_problem_form
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Creates new problem from template
*********************************************************************/

#include <QDialog>

#include "ui_new_problem.h"

namespace Ui 
{
	class new_problem_form;
}

class new_problem : public QDialog, public Ui::new_problem_form
{
	Q_OBJECT

public:
	new_problem(QWidget* parent = 0);
	virtual ~new_problem();

public slots:
	virtual void accept();
};

#endif // new_problem_form_h__