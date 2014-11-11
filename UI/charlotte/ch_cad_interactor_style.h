#ifndef ch_cad_interactor_style_h__
#define ch_cad_interactor_style_h__

/********************************************************************
	created:	2014/11/08
	created:	8:11:2014   13:45
	filename: 	C:\prj\charlotte\src\UI\charlotte\ch_cad_interactor_style.h
	file path:	C:\prj\charlotte\src\UI\charlotte
	file base:	ch_cad_interactor_style
	file ext:	h
	author:		Yuri Volodine
	
	purpose:	Implements CAD window interactor
*********************************************************************/

#include <vtkVector.h>
#include <vtkInteractorStyle.h>

#include <ch_core.h>

class ch_cad_interactor_style : public vtkInteractorStyle
{
	enum DrawState
	{
		dsNothing,
		dsDrawWall,
		dsDrawArcWall,
		dsPan,
		dsZoom,
		dsSelect
	};

public:
	ch_cad_interactor_style();
	~ch_cad_interactor_style();

	virtual void OnMouseMove();
	virtual void OnLeftButtonUp();
	virtual void OnLeftButtonDown();

private:
	void draw_wall();
	void draw_arc_wall();
	void do_pan();
	void do_zoom();
	void do_select();

	DrawState _state;
	vtkVector2i _verteces;
};

#endif // ch_cad_interactor_style_h__