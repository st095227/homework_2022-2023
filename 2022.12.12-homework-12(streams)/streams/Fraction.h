#pragma once
#include <iostream>

using namespace std;
class Fraction
{
private:
	long long int p;
	long long int q;
public:
	Fraction(long long int p = 0, long long int q = 0);
	Fraction(const Fraction& fr);
	~Fraction();

	void setP(long long int p);
	void setQ(long long int q);
	long long int getP();
	long long int getQ();
	void print();
	long long int gcd();
	long long int gcdM(const Fraction& r2);
	long long int lcm(const Fraction& r2);

	Fraction operator=(const Fraction& r1);


	friend bool operator>(Fraction& r1, Fraction& r2);
	friend bool operator<(Fraction& r1, Fraction& r2);
	friend bool operator>=(Fraction& r1, Fraction& r2);
	friend bool operator<=(Fraction& r1, Fraction& r2);
	friend bool operator==(Fraction& r1, Fraction& r2);

	friend bool operator>(long long int m, Fraction& r2);
	friend bool operator<(long long int m, Fraction& r2);
	friend bool operator>=(long long int m, Fraction& r2);
	friend bool operator<=(long long int m, Fraction& r2);
	friend bool operator==(long long int m, Fraction& r2);

	friend bool operator>(Fraction& r1, long long int m);
	friend bool operator<(Fraction& r1, long long int m);
	friend bool operator>=(Fraction& r1, long long int m);
	friend bool operator<=(Fraction& r1, long long int m);
	friend bool operator==(Fraction& r1, long long int m);


	Fraction operator-();

	friend Fraction operator*(int m, const Fraction& r1);
	friend Fraction operator*(const Fraction& r1, int m);
	friend Fraction operator*(const Fraction& r1, const Fraction& r2);

	friend Fraction operator/(int m, const Fraction& r1);
	friend Fraction operator/(const Fraction& r1, int m);
	friend Fraction operator/(const Fraction& r1, const Fraction& r2);

	friend Fraction operator+(int m, const Fraction& r1);
	friend Fraction operator+(const Fraction& r1, int m);
	friend Fraction operator+(const Fraction& r1, const Fraction& r2);

	friend Fraction operator-(int m, const Fraction& r1);
	friend Fraction operator-(const Fraction& r1, int m);
	friend Fraction operator-(const Fraction& r1, const Fraction& r2);

	friend ostream& operator<<(ostream& stream, const Fraction& r1);

	Fraction reverse();
	Fraction absF();
	Fraction power(int m);
};