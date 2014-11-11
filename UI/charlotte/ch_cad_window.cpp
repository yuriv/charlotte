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

#include <Qt>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QMdiSubWindow>

#include "ch_cad_window.h"
#include "ch_application.h"

ch_cad_window::ch_cad_window()
{
	initialize();
}

ch_cad_window::~ch_cad_window()
{
	finalize();
}

void ch_cad_window::initialize() throw(ch_unknown_exc, std::bad_alloc)
{
	QMdiArea* mdi = ch_application::mdi();
	std::shared_ptr<QVTKWidget> cad_window(new QVTKWidget(mdi, Qt::SubWindow));
	vtkSmartPointer<vtkRenderWindow> renderWindow = cad_window->GetRenderWindow();

	vtkSmartPointer<vtkRenderWindowInteractor> interactor = /*_cad_window->GetInteractor();*/
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkInteractorStyleDrawPolygon> style = vtkSmartPointer<vtkInteractorStyleDrawPolygon>::New();
	//vtkSmartPointer<vtkContextInteractorStyle> style = vtkSmartPointer<vtkContextInteractorStyle>::New();

	interactor->SetInteractorStyle(style);
	interactor->SetRenderWindow(renderWindow);

	// Create the RenderWindow, Renderer and both Actors
	//
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
//	vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);

	renderer->SetBackground(0, 0, 0);
	renderWindow->SetFullScreen(true);

	vtkSmartPointer<vtkContourWidget> contourWidget = vtkSmartPointer<vtkContourWidget>::New();

//	vtkSmartPointer<vtkOrientedGlyphContourRepresentation> contourRep = vtkSmartPointer<vtkOrientedGlyphContourRepresentation>::New();
	vtkOrientedGlyphContourRepresentation *contourRep = vtkOrientedGlyphContourRepresentation::
		SafeDownCast(contourWidget->GetRepresentation());
	vtkSmartPointer<vtkLinearContourLineInterpolator> contourStyle = vtkSmartPointer<vtkLinearContourLineInterpolator>::New();
	contourRep->GetLinesProperty()->SetColor(1, 0, 0); //set color to red
	contourRep->SetLineInterpolator(contourStyle);

	contourWidget->SetInteractor(interactor);
	contourWidget->SetRepresentation(contourRep);
	contourWidget->On();

	//contourWidget->SetProcessEvents(true);
	//contourWidget->SetContinuousDraw(1);
	//contourWidget->AllowNodePickingOn();
	//contourWidget->FollowCursorOn();

	//for (int i = 0; i < argc; i++)
	//{
	//	if (strcmp("-Shift", argv[i]) == 0)
	//	{
			contourWidget->GetEventTranslator()->RemoveTranslation( 
				vtkCommand::LeftButtonPressEvent );
			contourWidget->GetEventTranslator()->SetTranslation( 
				vtkCommand::LeftButtonPressEvent,
				vtkWidgetEvent::Translate );
	//	}
	//	else if (strcmp("-Scale", argv[i]) == 0)
	//	{
			contourWidget->GetEventTranslator()->RemoveTranslation( 
				vtkCommand::MouseWheelForwardEvent);
			contourWidget->GetEventTranslator()->SetTranslation( 
				vtkCommand::MouseWheelForwardEvent,
				vtkWidgetEvent::Scale);
	//	}
	//}


	vtkSmartPointer<vtkPolyData> pd = vtkSmartPointer<vtkPolyData>::New();

	vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
	vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
	vtkIdType* lineIndices = new vtkIdType[21];
	for (int i = 0; i< 20; i++)
	{
		const double angle = 2.0*vtkMath::Pi()*i/20.0;
		points->InsertPoint(static_cast<vtkIdType>(i), 0.1*cos(angle),
			0.1*sin(angle), 0.0 );
		lineIndices[i] = static_cast<vtkIdType>(i);
	}

	lineIndices[20] = 0;
	lines->InsertNextCell(21,lineIndices);
	delete [] lineIndices;
	pd->SetPoints(points);
	pd->SetLines(lines);

	//vtkSmartPointer<vtkPolyDataPointPlacer> pdPlacer = vtkSmartPointer<vtkPolyDataPointPlacer>::New();
	//vtkSmartPointer<vtkActor> pdActor = vtkSmartPointer<vtkActor>::New();
	//pdPlacer->AddProp(pdActor);
	//contourRep->SetPointPlacer(pdPlacer);

	mdi->addSubWindow(cad_window.get());
	cad_window->showMaximized();

	contourWidget->Initialize(pd);
	contourWidget->Render();
	renderer->ResetCamera();
	renderWindow->Render();

	interactor->Initialize();
	interactor->Start();

	contourWidget->Off();
}

void ch_cad_window::finalize() throw(ch_unknown_exc, std::bad_alloc)
{

}
