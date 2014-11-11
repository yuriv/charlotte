#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);

#include <vtkSmartPointer.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkWidgetEvent.h>
#include <vtkWidgetEventTranslator.h>
#include <vtkMath.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkCellArray.h>
#include <vtkPolyDataPointPlacer.h>
#include <vtkLinearContourLineInterpolator.h>
#include <vtkInteractorStyleDrawPolygon.h>
#include <vtkContextInteractorStyle.h>
#include <vtkOrientedGlyphContourRepresentation.h>
#include <vtkContourWidget.h>
#include <vtkRenderer.h>

#include <Qt>
#include <QApplication>
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>

#include <..\..\..\UI\qvtk_lib\QVTKInteractor.h>
#include <..\..\..\UI\qvtk_lib\QVTKWidget.h>

#include "main_window.h"
#include "main_app.h"

main_window::main_window()
{

}

main_window::~main_window()
{

}

void main_window::initialize() throw(ch_unknown_exc, ch_module_exc, std::bad_alloc)
{
	QMdiArea* mdi = main_app::mdi();
	std::shared_ptr<QVTKWidget> draw_window(new QVTKWidget(mdi, Qt::SubWindow));
	vtkSmartPointer<vtkRenderWindow> render_window = draw_window->GetRenderWindow();

	vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkInteractorStyleDrawPolygon> style = vtkSmartPointer<vtkInteractorStyleDrawPolygon>::New();

	interactor->SetInteractorStyle(style);
	interactor->SetRenderWindow(render_window);

	// Create the RenderWindow, Renderer and both Actors
	//
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	render_window->AddRenderer(renderer);

	renderer->SetBackground(0, 0, 0);
	//render_window->SetSize(600, 600);

	vtkSmartPointer<vtkContourWidget> contour_widget = vtkSmartPointer<vtkContourWidget>::New();

	//	vtkSmartPointer<vtkOrientedGlyphContourRepresentation> contourRep = vtkSmartPointer<vtkOrientedGlyphContourRepresentation>::New();
	vtkOrientedGlyphContourRepresentation *contour_rep = vtkOrientedGlyphContourRepresentation::SafeDownCast(contour_widget->GetRepresentation());
	vtkSmartPointer<vtkLinearContourLineInterpolator> contour_style = vtkSmartPointer<vtkLinearContourLineInterpolator>::New();
	contour_rep->GetLinesProperty()->SetColor(1, 0, 0); //set color to red
	contour_rep->SetLineInterpolator(contour_style);

	contour_widget->SetInteractor(interactor);
	contour_widget->SetRepresentation(contour_rep);
	contour_widget->On();

	//contourWidget->SetProcessEvents(true);
	//contourWidget->SetContinuousDraw(1);
	//contourWidget->AllowNodePickingOn();
	//contourWidget->FollowCursorOn();

	//for (int i = 0; i < argc; i++)
	//{
	//	if (strcmp("-Shift", argv[i]) == 0)
	//	{
	contour_widget->GetEventTranslator()->RemoveTranslation(vtkCommand::LeftButtonPressEvent);
	contour_widget->GetEventTranslator()->SetTranslation(vtkCommand::LeftButtonPressEvent, vtkWidgetEvent::Translate);
	//	}
	//	else if (strcmp("-Scale", argv[i]) == 0)
	//	{
	//contour_widget->GetEventTranslator()->RemoveTranslation(vtkCommand::MouseWheelForwardEvent);
	//contour_widget->GetEventTranslator()->SetTranslation(vtkCommand::MouseWheelForwardEvent, vtkWidgetEvent::Scale);
	//	}
	//}


	vtkSmartPointer<vtkPolyData> pd = vtkSmartPointer<vtkPolyData>::New();

	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
	vtkIdType* lineIndices = new vtkIdType[21];
	for(int i = 0; i< 20; i++)
	{
		const double angle = 2.0*vtkMath::Pi()*i/20.0;
		points->InsertPoint(static_cast<vtkIdType>(i), 0.1*cos(angle), 0.1*sin(angle), 0.0 );
		lineIndices[i] = static_cast<vtkIdType>(i);
	}

	lineIndices[20] = 0;
	lines->InsertNextCell(21,lineIndices);
	delete [] lineIndices;
	pd->SetPoints(points);
	pd->SetLines(lines);

	mdi->addSubWindow(draw_window.get());
	draw_window->showMaximized();

	contour_widget->Initialize(pd);
	contour_widget->Render();
	renderer->ResetCamera();
	render_window->Render();

	interactor->Initialize();
	interactor->Start();

	contour_widget->Off();
}

void main_window::finalize() throw(ch_unknown_exc, std::bad_alloc)
{

}
