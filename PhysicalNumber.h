#include "iostream"
using namespace std;
#include "Unit.h"
namespace ariel{
	class PhysicalNumber{
	private:
	double num;
	Unit U;
	public:
	//constructor
	PhysicalNumber(double num, Unit U);
	//onary
	const PhysicalNumber operator+() const; 
	const PhysicalNumber operator-() const; 
	//Addition and subtraction
	const PhysicalNumber& operator+(const PhysicalNumber& n) const; 
	const PhysicalNumber& operator-(const PhysicalNumber& n) const; 
	//Addition and subtraction one
	PhysicalNumber& operator++();
	PhysicalNumber& operator--();

	const PhysicalNumber& operator+=(const PhysicalNumber& n); 
	const PhysicalNumber& operator-=(const PhysicalNumber& n);
	
	friend ostream& operator<<(ostream& out, const PhysicalNumber& n);
	friend istream& operator>>(istream& in, PhysicalNumber& n);

	//logical operator
	friend bool operator>(const PhysicalNumber& n, const PhysicalNumber& n1);
	friend bool operator<(const PhysicalNumber& n, const PhysicalNumber& n1);
	friend bool operator<=(const PhysicalNumber& n, const PhysicalNumber& n1);
	friend bool operator>=(const PhysicalNumber& n, const PhysicalNumber& n1);
	friend bool operator==(const PhysicalNumber& n, const PhysicalNumber& n1);
	friend bool operator!=(const PhysicalNumber& n, const PhysicalNumber& n1);
	};
}