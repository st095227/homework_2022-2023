#pragma once
#include<iostream>
#include <cmath>

class quaternion
{
	double a, b, c, d;
public:
	quaternion(double a = 0, double b = 0, double c = 0, double d = 0);
	quaternion(const quaternion& q);
	~quaternion();

	double abs();
	void swap(quaternion& q);
	void setR(double m);
	void setI1(double m);
	void setI2(double m);
	void setI3(double m);

	double getR();
	double getI1();
	double getI2();
	double getI3();

	//quaternion operator+(const quaternion& q1);
	friend quaternion operator+(const quaternion& q1, const quaternion& q2);
	friend quaternion operator+(const quaternion& q1, double n);
	friend quaternion operator+(double n, const quaternion& q2);

	quaternion operator-();

	//quaternion operator-(const quaternion& q1);
	friend quaternion operator-(const quaternion& q1, const quaternion& q2);
	friend quaternion operator-(const quaternion& q1, double n);
	friend quaternion operator-(double n, const quaternion& q2);

	friend quaternion operator*(const quaternion& q1, const quaternion& q2);
	friend quaternion operator*(const quaternion& q1, double n);
	friend quaternion operator*(double n, const quaternion& q2);

	friend quaternion operator/(const quaternion& q1, const quaternion& q2);
	friend quaternion operator/(const quaternion& q1, double n);
	friend quaternion operator/(double n, const quaternion& q2);

	quaternion operator=(const quaternion& q1);
	quaternion operator+=(const quaternion& q1);
	quaternion operator-=(const quaternion& q1);
	quaternion operator+=(double m);
	quaternion operator-=(double m);
	quaternion operator*=(const quaternion& q1);
	quaternion operator*=(double m);
	quaternion operator/=(const quaternion& q1);
	quaternion operator/=(double m);

	quaternion conjugate();

	
	friend std::ostream& operator<<(std::ostream& stream, const quaternion& c1);
	friend std::istream& operator>>(std::istream& stream, quaternion& q1);
};