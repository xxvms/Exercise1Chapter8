// Exercise1Chapter8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
class Distance
{
	int feet;
	double inches;
public:
	Distance() : feet(0), inches(0.0) // constructor No arguments
	{}
	Distance(int feet_, double inches_): feet(feet_), inches(inches_) // constructor 2 arguments
	{}
	void getDistance()				// get distance from user
	{
		std::cout << "\nEnter feet: ";
		std::cin >> feet;
		std::cout << "\nEnter inches: ";
		std::cin >> inches;
	}
	void showDistance() const // display distance
	{
		std::cout << feet << "\' - " << inches << "\"";
	}
	Distance operator + (Distance) const; // add 2 distances
	Distance operator - (Distance) const; // substruct 2 distances
};

Distance Distance::operator+ (Distance d2) const // add this distance to d2 and return sum
{
	int feet_ = feet + d2.feet; // add feet to feet
	double inches_ = inches + d2.inches; // add inches to inches

	if (inches_ >= 12)
	{
		inches_ -= 12;
		feet_++;
	}
	return Distance(feet_, inches_);
}

Distance Distance::operator- (Distance d2) const // add this distance to d2 and return sum
{
	int feet_ = feet - d2.feet; // substruct feet to feet
	double inches_ = inches - d2.inches; // substruct inches to inches

	return Distance(feet_, inches_);
}
int main()
{
	Distance dist1, dist3, dist4;	// define distances
	dist1.getDistance();			// get distance from user

	Distance dist2(11, 6.25);		// define and initialize dist2

	dist3 = dist1 + dist2;			// single + operator
	dist4 = dist1 + dist2 + dist3; // multiple + operators


	std::cout << "dist1 = "; dist1.showDistance(); std::cout << std::endl;
	std::cout << "dist2 = "; dist2.showDistance(); std::cout << std::endl;
	std::cout << "dist3 = "; dist3.showDistance(); std::cout << std::endl;
	std::cout << "dist4 = "; dist4.showDistance(); std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;

	dist3 = dist1 - dist2;
	dist4 = dist1 - dist2 - dist3;

	std::cout << "dist1 = "; dist1.showDistance(); std::cout << std::endl;
	std::cout << "dist2 = "; dist2.showDistance(); std::cout << std::endl;
	std::cout << "dist3 = "; dist3.showDistance(); std::cout << std::endl;
	std::cout << "dist4 = "; dist4.showDistance(); std::cout << std::endl;

	system("pause");
    return 0;
}

