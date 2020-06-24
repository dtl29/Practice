#include "DansLib.hpp"
#include <iostream>

/*
*****************************************************************
*********  fraction member fucntions  *************************
*****************************************************************
*/

/*private*/
/*
Greatest Common Divisor function
**returns the gcd for two integers 
*/
int fraction::gcd(int a, int b)
{
	if(a == 0)
	{
		return b;
	}
	if(b == 0)
	{
		return a;
	}
	if(a == b)
	{
		return a;
	}
	if(a > b)
	{
		return gcd(a-b,b);
	}
	else
	{
		return gcd(a, b-a);
	}
}
fraction fraction::simplifyFraction(fraction OgFraction)
{
	bool wasNeg = false;
	if(OgFraction.numerator < 0)
	{
		wasNeg = true;
		OgFraction.numerator *= -1;
	}
	int d = gcd(OgFraction.numerator, OgFraction.denominator);

	float x = static_cast<float>(OgFraction.numerator) / static_cast<float>(d);
	float y = static_cast<float>(OgFraction.denominator) / static_cast<float>(d);

	if(wasNeg)
	{
		return fraction(static_cast<int>(x) * -1, static_cast<int>(y));
	}
	else
	{
		return fraction(static_cast<int>(x), static_cast<int>(y));
	}
}

/*?Public*/

fraction::fraction()
{
	fraction::numerator = 1;
	fraction::denominator = 1;
}
fraction::fraction(int num, int den)
{
	if(den < 1)
	{
		std::cout << "Denomitor must be greater than one (standard fraction created)." << std::endl;
		fraction::numerator = 1;
		fraction::denominator = 1;
	}
	fraction::numerator = num;
	fraction::denominator = den;
}

/*Will equal off of value not identiacl aperaance */
bool fraction::operator==(fraction other)
{
	fraction otherTemp = simplifyFraction(other);
	fraction thisTemp = simplifyFraction(fraction(fraction::numerator, fraction::denominator));

	if(thisTemp.numerator == otherTemp.numerator && thisTemp.denominator == otherTemp.denominator)
	{
		return true;
	}	
	else
	{
		return false;
	}
}
bool fraction::operator!=(fraction other)
{
	if(!(other == fraction(fraction::numerator, fraction::denominator)))
	{
		return true;
	}
	else 
	{
		return false;
	}
}
bool fraction::operator<(fraction other)
{
	float otherTemp = static_cast<float>(other.numerator) / static_cast<float>(other.denominator);
	float thisTemp = static_cast<float>(fraction::numerator) / static_cast<float>(fraction::denominator);
	if(thisTemp < otherTemp)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool fraction::operator>(fraction other)
{
	if(other < fraction(fraction::numerator, fraction::denominator))
	{
		return true;
	}
	else 
	{
		return false;
	}
}
fraction fraction::operator+(fraction other)
{
	fraction otherTemp = fraction(fraction::denominator * other.numerator, fraction::denominator * other.denominator);
	fraction thisTemp = fraction(fraction::numerator * other.denominator, fraction::denominator * other.denominator);
	fraction newfrac = fraction(otherTemp.numerator + thisTemp.numerator, thisTemp.denominator);
	return simplifyFraction(newfrac);
}
fraction fraction::operator-(fraction other)
{
	fraction otherTemp = fraction(fraction::denominator * other.numerator, fraction::denominator * other.denominator);
	fraction thisTemp = fraction(fraction::numerator * other.denominator, fraction::denominator * other.denominator);
	fraction newfrac = fraction(thisTemp.numerator - otherTemp.numerator, thisTemp.denominator);
	return simplifyFraction(newfrac);
}
fraction fraction::operator*(fraction other)
{
	return simplifyFraction(fraction(fraction::numerator * other.numerator, fraction::denominator * other.denominator));
}
fraction fraction::operator/(fraction other)
{
	int n = fraction::numerator * other.denominator;
	int d = denominator * other.numerator;
	return fraction(static_cast<float>(n)/static_cast<float>(gcd(n,d)),static_cast<float>(d)/static_cast<float>(gcd(n,d)));
}
float fraction::toFloat()
{
	return static_cast<float>(fraction::numerator) / static_cast<float>(fraction::denominator);
}
//will print the function (redundent with << operator)
void fraction::printFraction()
{
	std::cout << fraction::numerator << '/' << fraction::denominator;	
}
//will output using the << operator 
std::ostream& operator<<(std::ostream& os, const fraction& frac)
{
	os << frac.numerator << '/' << frac.denominator;
	return os;
}