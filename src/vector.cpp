/* ----------------------------------------------------------------------------
 * ----------------------------------------------------------------------------
 *
 * ��ѧ��Ӧ��ģ��ĸ��ܻ���
 * Enabling Environment for Multi-displinary Application Simulations
 *
 * �½��� �й� �㽭��ѧ�������ѧ�����о�����
 * ��Ȩ����	  2007��10��15��
 * Chen Jianjun  Center for Engineering & Scientific Computation,
 * Zhejiang University, P. R. China
 * Copyright reserved, Oct. 15, 2007
 * 
 * ��ϵ��ʽ (For further information, please conctact)
 *   �绰 (Tel)��+86-571-87953165
 *   ���� (Fax)��+86-571-87953167
 *   ���� (Mail)��chenjj@zju.edu.cn
 *
 * �ļ����� (File Name)��vector.h
 * ��ʼ�汾 (Initial Version): V1.0
 * ���ܽ��� (Function Introduction��
 *     ������һ���ܶȿ��ƻ���
 *     Define a set of element spacing controlling scheme.
 * 
 *
 * -----------------------------�޸ļ�¼ (Revision Record)------------------------
 * �޸��� (Revisor):
 * �޸����� (Revision Date):
 * ��ǰ�汾 (Current Version):
 * �޸Ľ��� (Revision Introduction):
 * ------------------------------------------------------------------------------
 * ------------------------------------------------------------------------------*/

#include "vector.h"
#include <math.h>


/* *********************************************************************************
 * ������άʸ��
 * define 3-dimensional vector
 * **********************************************************************************/

/* ʸ����ģ calc. magnitude */
double Vector::magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

/* ��һ normalization */
void Vector::normalize()
{
	double m = magnitude();
	x = x / m;
	y = y / m;
	z = z / m;
}

/* **********************************
 * ���ز����� overloaded operator 
 * **********************************/

/* ��ֵ assignment */
const Vector& Vector::operator = (const Vector& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

const Vector& Vector::operator = (double v)
{
	x = y = z = v;
	return *this;
}

/* �������� simple mathamatic operator */
const Vector Vector::operator + (const Vector& v) const
{
	Vector vr;
	vr.x = x + v.x;
	vr.y = y + v.y;
	vr.z = z + v.z;
	return vr;
}

const Vector Vector::operator - (const Vector& v) const
{
	Vector vr;
	vr.x = x - v.x;
	vr.y = y - v.y;
	vr.z = z - v.z;
	return vr;
}

const Vector Vector::operator * (double s) const
{
	Vector vr;
	vr.x = x * s;
	vr.y = y * s;
	vr.z = z * s;
	return vr;
}
 
const Vector Vector::operator / (double s) const
{
	Vector vr;
	vr.x = x / s;
	vr.y = y / s;
	vr.z = z / s;
	return vr;
}


const Vector& Vector::operator += (const Vector& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

const Vector& Vector::operator -= (const Vector& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

const Vector& Vector::operator += (double delta)
{
	x += delta;
	y += delta;
	z += delta;
	return *this;
}

const Vector& Vector::operator -= (double delta)
{
	x -= delta;
	y -= delta;
	z -= delta;
	return *this;
}


/* ��� & ��� dot & cross */
double Vector::operator * (const Vector& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

const Vector Vector::operator ^ (const Vector& v) const
{
	Vector vr;
    vr.x = y * v.z - v.y * z;
	vr.y = v.x * z - x * v.z;
	vr.z = x * v.y - y * v.x;
	return vr;
}


const Vector Vector::operator - ()
{
	Vector vr;
	vr.x = -x;
	vr.y = -y;
	vr.z = -z;
	return vr;
}

const Vector operator * (double scale, const Vector& v)
{
	 return v * scale;
}

