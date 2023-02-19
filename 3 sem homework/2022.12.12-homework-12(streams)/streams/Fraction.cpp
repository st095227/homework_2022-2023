#include <iostream>
#include "Fraction.h"

Fraction::Fraction(long long int p, long long int q) : p(p), q(q) {}
Fraction::Fraction(const Fraction& fr) : p(fr.p), q(fr.q) {}
Fraction::~Fraction()
{
	this->p = 0;
	this->q = 0;
}

void Fraction::setP(long long int p)
{
	this->p = p;
}
void Fraction::setQ(long long int q)
{
	this->q = q;
}
long long int Fraction::getP()
{
	return this->p;
}
long long int Fraction::getQ()
{
	return this->q;
}
void Fraction::print()
{
	cout << p << "\\" << q << endl;
}

long long int Fraction::gcd()
{
	int a = abs(this->p);
	int b = abs(this->q);
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}
long long int Fraction::gcdM(const Fraction& r2)
{
	int a = abs(this->q);
	int b = abs(r2.q);
	while (a != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}
long long int Fraction::lcm(const Fraction& r2)
{
	return abs(this->q * r2.q) / gcdM(r2);
}

Fraction Fraction::operator=(const Fraction& r1)
{
	this->p = r1.p;
	this->q = r1.q;
	return *this;
}

bool operator>(Fraction& r1, Fraction& r2)
{
	Fraction r3 = r1 - r2;
	if ((r3.p > 0 && r3.q > 0) || (r3.p < 0 && r3.q < 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<(Fraction& r1, Fraction& r2)
{
	Fraction r3 = r1 - r2;
	if ((r3.p > 0 && r3.q > 0) || (r3.p < 0 && r3.q < 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator>=(Fraction& r1, Fraction& r2)
{
	Fraction r3 = r1 - r2;
	if ((r3.p >= 0 && r3.q > 0) || (r3.p <= 0 && r3.q < 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<=(Fraction& r1, Fraction& r2)
{
	Fraction r3 = r1 - r2;
	if ((r3.p >= 0 && r3.q > 0) || (r3.p <= 0 && r3.q < 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator==(Fraction& r1, Fraction& r2)
{
	Fraction r3 = r1 - r2;
	if (r3.p == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool operator>(long long int m, Fraction& r2)
{
	Fraction r3 = m - r2;
	if ((r3.p > 0 && r3.q > 0) || (r3.p < 0 && r3.q < 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<(long long int m, Fraction& r2)
{
	Fraction r3 = m - r2;
	if ((r3.p > 0 && r3.q > 0) || (r3.p < 0 && r3.q < 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator>=(long long int m, Fraction& r2)
{
	Fraction r3 = m - r2;
	if ((r3.p >= 0 && r3.q > 0) || (r3.p <= 0 && r3.q < 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<=(long long int m, Fraction& r2)
{
	Fraction r3 = m - r2;
	if ((r3.p >= 0 && r3.q > 0) || (r3.p <= 0 && r3.q < 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator==(long long int m, Fraction& r2)
{
	Fraction r3 = m - r2;
	if (r3.p == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool operator>(Fraction& r1, long long int m)
{
	Fraction r3 = r1 - m;
	if ((r3.p > 0 && r3.q > 0) || (r3.p < 0 && r3.q < 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<(Fraction& r1, long long int m)
{
	Fraction r3 = r1 - m;
	if ((r3.p > 0 && r3.q > 0) || (r3.p < 0 && r3.q < 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator>=(Fraction& r1, long long int m)
{
	Fraction r3 = r1 - m;
	if ((r3.p >= 0 && r3.q > 0) || (r3.p <= 0 && r3.q < 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<=(Fraction& r1, long long int m)
{
	Fraction r3 = r1 - m;
	if ((r3.p >= 0 && r3.q > 0) || (r3.p <= 0 && r3.q < 0))
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator==(Fraction& r1, long long int m)
{
	Fraction r3 = r1 - m;
	if (r3.p == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Fraction Fraction::operator-()
{
	return Fraction(-this->p, this->q);
}

Fraction operator*(int m, const Fraction& r1)
{
	Fraction r2(r1.p * m, r1.q);
	int c = r2.gcd();
	return Fraction(r2.p / c, r2.q / c);
}
Fraction operator*(const Fraction& r1, int m)
{
	Fraction r2(r1.p * m, r1.q);
	int c = r2.gcd();
	return Fraction(r2.p / c, r2.q / c);
}

Fraction operator*(const Fraction& r1, const Fraction& r2)
{
	Fraction r3(r1.p * r2.p, r1.q * r2.q);
	int c = r3.gcd();
	return Fraction(r3.p / c, r3.q / c);
}

Fraction operator/(int m, const Fraction& r1)
{
	Fraction r2(r1.q * m, r1.p);
	int c = r2.gcd();
	return Fraction(r2.p / c, r2.q / c);
}
Fraction operator/(const Fraction& r1, int m)
{
	Fraction r2(r1.p, r1.q * m);
	int c = r2.gcd();
	return Fraction(r2.p / c, r2.q / c);
}
Fraction operator/(const Fraction& r1, const Fraction& r2)
{
	Fraction r3(r1.p * r2.q, r1.q * r2.p);
	int c = r3.gcd();
	return Fraction(r3.p / c, r3.q / c);
}

Fraction operator+(int m, const Fraction& r1)
{
	return Fraction(r1.p + (m * r1.q), r1.q);
}
Fraction operator+(const Fraction& r1, int m)
{
	return Fraction(r1.p + (m * r1.q), r1.q);
}
Fraction operator+(const Fraction& r1, const Fraction& r2)
{
	Fraction r3(r1.p * r2.q + r1.q * r2.p, r1.q * r2.q);
	int c = r3.gcd();
	return Fraction(r3.p / c, r3.q / c);
}

Fraction operator-(int m, const Fraction& r1)
{
	return Fraction((m * r1.q) - r1.p, r1.q);
}
Fraction operator-(const Fraction& r1, int m)
{
	return Fraction(r1.p - (m * r1.q), r1.q);
}
Fraction operator-(const Fraction& r1, const Fraction& r2)
{
	Fraction r3(r1.p * r2.q - r1.q * r2.p, r1.q * r2.q);
	int c = r3.gcd();
	return Fraction(r3.p / c, r3.q / c);
}
ostream& operator<<(ostream& stream, const Fraction& r1)
{
	if (r1.q == 0)
	{
		stream << "division by zero";
	}
	else if (r1.q == 1)
	{
		stream << r1.p;
		return stream;
	}
	else if (r1.q == -1 && r1.p > 0)
	{
		stream << -r1.p;
		return stream;
	}
	else if (r1.p == 0)
	{
		stream << "0";
	}
	else if (r1.p < 0 && r1.q == -1)
	{
		stream << -r1.p;
		return stream;
	}
	else if (r1.p < 0 && r1.q < 0)
	{
		stream << -r1.p << "\\" << -r1.q;
		return stream;
	}
	else if (r1.p > 0 && r1.q > 0)
	{
		stream << r1.p << "\\" << r1.q;
		return stream;
	}
	else if (r1.p > 0 && r1.q < 0)
	{
		stream << -r1.p << "\\" << -r1.q;
		return stream;
	}
	else
	{
		stream << r1.p << "\\" << r1.q;
		return stream;
	}
}
Fraction Fraction::reverse()
{
	return Fraction(this->q, this->p);
}
Fraction Fraction::absF()
{
	if (this->p >= 0 && this->q > 0)
	{
		return Fraction(this->p, this->q);
	}
	if (this->p < 0 && this->q < 0)
	{
		return Fraction(-this->p, -this->q);
	}
	if (this->p >= 0 && this->q < 0)
	{
		return Fraction(this->p, -this->q);
	}
	if (this->p < 0 && this->q > 0)
	{
		return Fraction(-this->p, this->q);
	}
}
Fraction Fraction::power(int m)
{
	Fraction rf(this->p, this->q);
	Fraction r1 = rf;
	for (int i = 1; i < m; ++i)
	{
		rf = rf * r1;
	}
	return rf;
}