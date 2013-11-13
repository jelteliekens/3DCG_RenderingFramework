#ifndef TRANSFO_H_
#define TRANSFO_H_

#include "Matrix.h"

class Transfo {

protected:

	Matrix mat;
	Matrix invMat;

public:

	Transfo(){}
	Transfo(const Transfo & transfo):mat(transfo.mat),invMat(transfo.invMat){}
    Transfo & operator=(const Transfo & transfo);

    const Matrix& getInvMat() const { return invMat; }
    const Matrix& getMat() const { return mat; }
	void setInvMat(const Matrix& invMat) { this->invMat = invMat; }
	void setMat(const Matrix& mat) { this->mat = mat; }
    void transform(const Transfo & transfo);
};


#endif /* TRANSFO_H_ */
