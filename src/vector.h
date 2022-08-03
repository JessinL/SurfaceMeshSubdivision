#ifndef __iso3d_vector_h__
#define	__iso3d_vector_h__

/* *********************************************************************************
 * ������άʸ��
 * define 3-dimensional vector
 * **********************************************************************************/
class Vector
{
public:
	Vector() { x = y = z = 0.; }
	Vector(double v1, double v2, double v3) {
		x = v1; y = v2; z = v3;
	}
	Vector(const Vector& v) {
		x = v.x;  y = v.y; z = v.z;
	}

	// Ϊ����data_io.cpp�е�ʹ�ã������µĺ���
	//double X() { return this->x; }
	//double Y() { return this->y; }
	//double Z() { return this->z; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	void setZ(double z) { this->z = z; }
	
	/* ʸ����ģ calc. magnitude */
	double magnitude() const;
	
	/* ��һ normalization */
	void normalize();

	/* **********************************
	 * ���ز����� overloaded operator 
	 * **********************************/

	/* ��ֵ assignment */
	const Vector& operator = (const Vector& v);
	const Vector& operator = (double v);

	/* �������� simple mathamatic operator */
    const Vector operator + (const Vector& v) const;
    const Vector operator - (const Vector& v) const;
    const Vector operator * (double s) const;  
    const Vector operator / (double s) const;
    
    const Vector& operator += (const Vector& v);
    const Vector& operator -= (const Vector& v);
    const Vector& operator += (double delta);
    const Vector& operator -= (double delta);

	/* ��� & ��� dot & cross */
	double operator * (const Vector& v) const;
	const Vector operator ^ (const Vector& V) const;
	const Vector operator - ();

//	friend const Vector operator - (const Vector& p);
	friend const Vector operator * (double scale, const Vector& v);

public:
	double x, y, z;
};

#endif /* __iso3d_vector_h__*/
