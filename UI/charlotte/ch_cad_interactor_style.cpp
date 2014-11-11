#include <vtkCommand.h>

#include "ch_cad_interactor_style.h"

ch_cad_interactor_style::ch_cad_interactor_style()
	: vtkInteractorStyle()
	, _state(dsNothing)
{

}

ch_cad_interactor_style::~ch_cad_interactor_style()
{

}

void ch_cad_interactor_style::OnMouseMove()
{

}

void ch_cad_interactor_style::OnLeftButtonUp()
{
	switch(_state) 
	{
	case dsDrawWall:
		draw_wall();
		break;
	default:
		break;
	}
}

void ch_cad_interactor_style::OnLeftButtonDown()
{
	//_state = dsDrawWall;
	//_verteces.Set(this->Interactor->GetEventPosition()[0], this->Interactor->GetEventPosition()[1]);

	//this->InvokeEvent(vtkCommand::StartInteractionEvent);
}

void ch_cad_interactor_style::draw_wall()
{
	//_verteces.Set(this->Interactor->GetEventPosition()[0], this->Interactor->GetEventPosition()[1]);
	//this->Interactor->GetRenderWindow()->SetPixelData(0, 0, size[0]-1, size[1]-1, pixels, 1);

	//this->InvokeEvent(vtkCommand::SelectionChangedEvent);
	//this->InvokeEvent(vtkCommand::EndInteractionEvent);
}

void ch_cad_interactor_style::draw_arc_wall()
{

}

void ch_cad_interactor_style::do_pan()
{

}

void ch_cad_interactor_style::do_zoom()
{

}

void ch_cad_interactor_style::do_select()
{

}
