#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

string IsTriangle(int a, int b, int c)
{
	if(a<=0||a>200)
		return "Invalid Input";
	if(b<=0||b>200)
		return "Invalid Input";
	if(c<=0||c>200)
		return "Invalid Input";
	if((a<b+c)&&(b<a+c)&&(c<a+b))
	{
		if(a==b&&b==c)
		{
			return "Equilateral";
		}
		else if(a!=b&&a!=c&&b!=c)
		{
			return "Scalene";
		}
		else
		{
			return "Isosceles";
		}
	}
	else
	{
		return "Not a Triangle";
	}
	return "Error";
}
