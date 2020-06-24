#include <iostream>

//fraction class
class fraction
{
private:
	int numerator;
	int denominator;
	int gcd(int a, int b);
	fraction simplifyFraction(fraction OgFraction);
public:
	fraction();
	fraction(int num, int den);
	bool operator==(fraction other);
	bool operator!=(fraction other);
	bool operator<(fraction other); 
	bool operator>(fraction other);
	fraction operator+(fraction other);
	fraction operator-(fraction other);
	fraction operator*(fraction other);
	fraction operator/(fraction other);
	float toFloat();
	friend std::ostream& operator<<(std::ostream& os, const fraction& frac);
	void printFraction();
	/* to be done

	*/
};