#include <vtkSmartPointer.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkOrientedGlyphContourRepresentation.h>
#include <vtkContourWidget.h>
#include <vtkRenderWindow.h>
#include <vtkInteractorStyleDrawPolygon.h>
#include <vtkLinearContourLineInterpolator.h>
#include <vtkCellArray.h>
#include <vtkMath.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkLinearContourLineInterpolator.h>
#include <vtkWidgetEvent.h>
#include <vtkWidgetEventTranslator.h>

#include <Qt>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QMdiSubWindow>

#include <UI\qvtk_lib\QVTKApplication.h>
#include <UI\qvtk_lib\QVTKWidget.h>

#include "main_app.h"
#include "app.h"
#include "main_window.h"

std::shared_ptr<app> main_app::_main_window = NULL;
std::shared_ptr<QMdiArea> main_app::_mdi = NULL;

main_app::main_app(int argc, char *argv[]) : QVTKApplication(argc, argv)
{

}

main_app::~main_app()
{

}

void main_app::initialize() throw(ch_unknown_exc, ch_module_exc)
{
	_main_window.reset(new app());
	EXCASS((_main_window != NULL), ch_module_exc("Application main window isn't initialized."))

	QWidget* cw = _main_window->centralWidget();
	QMdiArea* mdi = cw->findChild<QMdiArea*>("mdiArea");
	EXCASS((mdi != NULL), ch_module_exc("MDI area isn't initialized."))

	_mdi.reset(mdi);

	// Fill it please
	setApplicationName("");
	setApplicationVersion("");
	setOrganizationName("");
	setOrganizationDomain("");
}

void main_app::finalize() throw(ch_unknown_exc, ch_module_exc)
{

}

app* main_app::main_window() throw(ch_unknown_exc, ch_module_exc)
{
	return _main_window.get();
}

QMdiArea* main_app::mdi() throw(ch_unknown_exc, ch_module_exc)
{
	return _mdi.get();
}

int main_app::run() throw(ch_unknown_exc, ch_module_exc)
{
	_main_window->show();
	return exec();
}
