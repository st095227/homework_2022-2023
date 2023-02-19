#include"quaternion.h"
using namespace std;

quaternion::quaternion(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}
quaternion::quaternion(const quaternion& q)
{
	this->a = q.a;
	this->b = q.b;
	this->c = q.c;
	this->d = q.d;
}
quaternion::~quaternion()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}

double quaternion::abs()
{
	return sqrt(pow(this->a, 2) + pow(this->b, 2) + pow(this->c, 2) + pow(this->d, 2));
}

double quaternion::abs()
const
{
	return sqrt(pow(this->a, 2) + pow(this->b, 2) + pow(this->c, 2) + pow(this->d, 2));
}

void quaternion::swap(quaternion& q)
{
	quaternion q2;
	q2 = q;
	q.a = this->a;
	q.b = this->b;
	q.c = this->c;
	q.d = this->d;
	this->a = q2.a;
	this->b = q2.b;
	this->c = q2.c;
	this->d = q2.d;
}

void quaternion::setR(double m)
{
	this->a = m;
}
void quaternion::setI1(double m)
{
	this->b = m;
}
void quaternion::setI2(double m)
{
	this->c = m;
}
void quaternion::setI3(double m)
{
	this->d = m;
}

double quaternion::getR()
{
	return this->a;
}
double quaternion::getI1()
{
	return this->b;
}
double quaternion::getI2()
{
	return this->c;
}
double quaternion::getI3()
{
	return this->d;
}


/*quaternion quaternion::operator+(const quaternion& q1)
{
	return quaternion(this->a + q1.a, this->b + q1.b, this->c + q1.c, this->d + q1.d);
}*/
quaternion operator+(const quaternion& q1, const quaternion& q2)
{
	return quaternion(q1.a + q2.a, q1.b + q2.b, q1.c + q2.c, q1.d + q2.d);
}
quaternion operator+(const quaternion& q1, double n)
{
	return quaternion(q1.a + n, q1.b, q1.c, q1.d);
}
quaternion operator+(double n, const quaternion& q2)
{
	return quaternion(q2.a + n, q2.b, q2.c, q2.d);
}

quaternion quaternion::operator-()
{
	return quaternion(-this->a, -this->b, -this->c, -this->d);
}

/*quaternion quaternion::operator-(const quaternion& q1)
{
	return quaternion(this->a - q1.a, this->b - q1.b, this->c - q1.c, this->d - q1.d);
}*/

quaternion operator-(const quaternion& q1, const quaternion& q2)
{
	return quaternion(q1.a - q2.a, q1.b - q2.b, q1.c - q2.c, q1.d - q2.d);
}
quaternion operator-(const quaternion& q1, double n)
{
	return quaternion(q1.a - n, q1.b, q1.c, q1.d);
}
quaternion operator-(double n, const quaternion& q2)
{
	return quaternion(n - q2.a, -q2.b, -q2.c, -q2.d);
}

quaternion operator*(const quaternion& q1, const quaternion& q2)
{
	double i0 = q1.a * q2.a - q1.b * q2.b - q1.c * q2.c - q1.d * q2.d;
	double i1 = q1.a * q2.b + q1.b * q2.a + q1.c * q2.d - q1.d * q2.c;
	double i2 = q1.a * q2.c - q1.b * q2.d + q1.c * q2.a + q1.d * q2.b;
	double i3 = q1.a * q2.d + q1.b * q2.c - q1.c * q2.b + q1.d * q2.a;
		return quaternion(i0, i1, i2, i3);
}
quaternion operator*(const quaternion& q1, double n)
{
	return quaternion(n * q1.a, n * q1.b, n * q1.c, n * q1.d);
}
quaternion operator*(double n, const quaternion& q2)
{
	return quaternion(n * q2.a, n * q2.b, n * q2.c, n * q2.d);
}

quaternion operator/(const quaternion& q1, const quaternion& q2)
{
	quaternion c;
	quaternion q;
	q = q2;
	c = q1*q.conjugate();
	double n = q2.a * q2.a + q2.b * q2.b + q2.c * q2.c + q2.d * q2.d;
	return quaternion(c.a / n, c.b / n, c.c / n, c.d / n);
}
quaternion operator/(const quaternion& q1, double n)
{
	return quaternion(q1.a / n, q1.b / n, q1.c / n, q1.d / n);
}
quaternion operator/(double n, const quaternion& q2)
{
	quaternion c(n, 0, 0, 0);
	return c / q2;
}

quaternion quaternion::operator=(const quaternion& q1)
{
	this->a = q1.a;
	this->b = q1.b;
	this->c = q1.c;
	this->d = q1.d;
	return *this;
}
quaternion quaternion::operator+=(const quaternion& q1)
{
	return *this=q1+*this;
}
quaternion quaternion::operator-=(const quaternion& q1)
{
	return *this = *this - q1;
}
quaternion quaternion::operator+=(double m)
{
	return *this = m + *this;
}
quaternion quaternion::operator-=(double m)
{
	return *this = *this - m;
}
quaternion quaternion::operator*=(const quaternion& q1)
{
	return *this = *this * q1;
}
quaternion quaternion::operator*=(double m)
{
	return *this = *this * m;
}
quaternion quaternion::operator/=(const quaternion& q1)
{
	return *this = *this / q1;
}
quaternion quaternion::operator/=(double m)
{
	return *this = *this / m;
}

quaternion quaternion::conjugate()
{
	return quaternion(this->a, -this->b, -this->c, -this->d);
}

std::ostream& operator<<(std::ostream& stream, const quaternion& q1)
{
	stream << q1.a;
	if (q1.b >= 0)
	{
		stream << '+' << q1.b << 'i';
	}
	else 
	{
		stream << q1.b << 'i';
	}

	if (q1.c >= 0)
	{
		stream << '+' << q1.c << 'j';
	}
	else
	{
		stream << q1.c << 'j';
	}

	if (q1.d >= 0)
	{
		stream << '+' << q1.d << 'k';
	}
	else
	{
		stream << q1.d << 'k';
	}
	return stream;
}
std::istream& operator>>(std::istream& stream, quaternion& q1)
{
	stream >> q1.a >> q1.b >> q1.c >> q1.d;
	return stream;
}