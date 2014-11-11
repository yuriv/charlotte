#include "new_problem_form.h"
#include "main_window.h"

new_problem::new_problem(QWidget* parent)
	: QDialog(parent)
{
	setupUi(this);
}

new_problem::~new_problem()
{

}

void new_problem::accept()
{
	QDialog::accept();

	main_window subwin;
	subwin.setWindowTitle("Problem");
	subwin.initialize();
	subwin.finalize();
}
