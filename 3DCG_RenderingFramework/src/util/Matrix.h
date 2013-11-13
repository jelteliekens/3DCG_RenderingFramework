#ifndef MATRIX_H_
#define MATRIX_H_

#include "Point.h"
#include "Vector.h"
#include <ostream>

class Matrix {
	public:
		double m[4][4];

		Matrix();
		Matrix(const Matrix & a);
		Matrix & operator=(const Matrix & a);
		friend Point operator*(const Matrix & m, const Point & p);
		friend Vector operator*(const Matrix & m, const Vector & v);
		Matrix getTranspose() const;
        void preMult(const Matrix & a);
        void postMult(const Matrix & a);

    friend std::ostream & operator<<(std::ostream & out, const Matrix & matrix);

};

#endif /* MATRIX_H_ */
