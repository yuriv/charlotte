#include "ch_cad_window.h"

ch_cad_window::ch_cad_window()
	: _cad_window(NULL)
{

}

ch_cad_window::~ch_cad_window()
{

}

void ch_cad_window::initialize() throw(ch_unknown_exc)
{
	_cad_window = new QVTKWidget(this);
}

void ch_cad_window::finalize() throw(ch_unknown_exc)
{

}
