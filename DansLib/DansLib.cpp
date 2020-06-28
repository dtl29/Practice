#pragma once
#include "DansLib.hpp"
#include <iostream>

/*
*****************************************************************
****************  Random usful functions  ***********************
*****************************************************************
*/
//will return num!
int factorial(int num)
{
	if(num > 1)
	{
		return num * factorial(num-1);
	}
	return 1;
}

/*******************************
**  Pow overloaded functions  ** 
********************************/
//will return a^x 
int DansPow(int a, int x)
{
	bool negative = false;
	//need to deal with negative expoinents (sposed to be over 1/answer)
	if(x < 0)
	{
		negative = true;
		x *= -1;
	}
	int temp = 1;
	for(int i = 0; i < x; i++)
	{
		temp *= a;
	}
	if(negative)
	{
		return static_cast<int>(1.0 / static_cast<float>(temp));
	}
	return temp;
}
float DansPow(float a, int x)
{
	bool negative = false;
	if(x<0)
	{
		negative = true;
		x *= -1;
	}
	float temp = 1;
	for(int i = 0; i < x; i++)
	{
		temp *= a;
	}
	if(negative)
	{
		return 1.0 / temp;
	}
	return temp;
}
double DansPow(double a, int x)
{
	bool negative = false;
	if(x < 0)
	{
		negative = true;
		x *= -1;
	}
	double temp = 1;
	for(int i = 0; i < x; i++)
	{
		temp *= a;
	}
	if(negative)
	{
		return 1.0 / temp;
	}
	return temp;
}

int DansABV(int a)
{
	if(a < 0)
	{
		return a * -1;
	}
	else 
	{
		return a;
	}
}
float DansABV(float a)
{
	if(a < 0)
	{
		return a * -1;
	}
	else 
	{
		return a;
	}
}
double DansABV(double a)
{
	if(a < 0)
	{
		return a * -1;
	}
	else 
	{
		return a;
	}
}