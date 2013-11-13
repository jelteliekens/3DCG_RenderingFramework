#include "Matrix.h"
#include <ostream>

Matrix::Matrix(){
	for(int i=0; i<4;++i){
		for(int j=0; j<4;++j){
			m[i][j]=0;
		}
	}
	for(int i=0; i<4;++i){
		m[i][i]=1;
	}
}

Matrix::Matrix(const Matrix & a){
	for(int i=0; i<4;++i){
		for(int j=0; j<4;++j){
			m[i][j]=a.m[i][j];
		}
	}
}

Matrix & Matrix::operator=(const Matrix & a){
	if(this == &a){
		return *this;
	}
	for(int i=0; i<4;++i){
		for(int j=0; j<4;++j){
			m[i][j]=a.m[i][j];
		}
	}
	return *this;
}

Point operator*(const Matrix & m, const Point & p){
	double x = m.m[0][0]*p.x + m.m[0][1]*p.y + m.m[0][2]*p.z + m.m[0][3];
	double y = m.m[1][0]*p.x + m.m[1][1]*p.y + m.m[1][2]*p.z + m.m[1][3];
	double z = m.m[2][0]*p.x + m.m[2][1]*p.y + m.m[2][2]*p.z + m.m[2][3];
	return Point(x,y,z);
}

Vector operator*(const Matrix & m, const Vector & v){
    double x = m.m[0][0]*v.x + m.m[0][1]*v.y + m.m[0][2]*v.z;
    double y = m.m[1][0]*v.x + m.m[1][1]*v.y + m.m[1][2]*v.z;
    double z = m.m[2][0]*v.x + m.m[2][1]*v.y + m.m[2][2]*v.z;
	return Vector(x,y,z);
}

Matrix Matrix::getTranspose() const{
	Matrix t;
    
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            t.m[r][c] = m[c][r];
        }
    }
    
    return t;
}

void Matrix::preMult(const Matrix & a) {
    double sum = 0;
    Matrix copy (*this);
    
    for(int r=0; r<4; r++) {
        for(int c=0; c<4; c++) {
            for(int i=0; i<4;i++){
                sum += a.m[r][i]*copy.m[i][c];
            }
            m[r][c] = sum;
            sum = 0;
        }
    }
}

void Matrix::postMult(const Matrix & a) {
    double sum = 0;
    Matrix copy(*this);
    
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            for (int i = 0; i < 4; i++) {
                sum += copy.m[r][i] * a.m[i][c];
            }
            m[r][c] = sum;
            sum = 0;
        }
    }
}

std::ostream & operator<<(std::ostream & out, const Matrix & matrix) {
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            out << matrix.m[r][c] << "\t";
        }
        out << std::endl;
    }
    return out;
}



