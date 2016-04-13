#include "stdafx.h"

void Vertices::setVertices(sf::Rect<float> box){
	//top left
	_tl.x = box.left;
	_tl.y = box.top;
	//top right
	_tr.x = box.left + box.width;
	_tr.y = box.top;
	//bottom left
	_bl.x = box.left;
	_bl.y = box.top + box.height;
	//bottom right
	_br.x = box.left + box.width;
	_br.y = box.top + box.height;

	vertices[0] = _tl;		
	vertices[1] = _tr;		
	vertices[2] = _bl;		
	vertices[3] = _br;		

	// 0 - top left
	// 1 - top right
	// 2 - bottom left
	// 3 - bottom right
	
}

