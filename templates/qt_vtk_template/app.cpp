#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);

#include <QT>
#include <QMetaObject>
#include <QObject>

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

#include "app.h"
#include "main_window.h"
#include "new_problem_form.h"

app::app(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

app::~app()
{

}

void app::runNewProblem()
{
	new_problem dlg(this);
	dlg.exec();
}

void app::runOpenProblem()
{

}
