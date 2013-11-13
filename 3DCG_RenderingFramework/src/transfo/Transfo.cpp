#include "Transfo.h"

Transfo & Transfo::operator=(const Transfo & transfo){
	if(this == &transfo)
		return *this;
	mat = transfo.mat;
	invMat = transfo.invMat;
	return *this;
}

void Transfo::transform(const Transfo & transfo) {
    mat.postMult(transfo.getMat());
    invMat.preMult(transfo.getInvMat());
}




