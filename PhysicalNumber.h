#include "iostream"
using namespace std;
#include "Unit.h"
namespace ariel{
	class PhysicalNumber{

	private:
	double num;
	Unit U;


	

	public:

	bool equalDimension(const PhysicalNumber& pn, const PhysicalNumber& pn1);
	

	//constructor
	PhysicalNumber(double num, Unit U);
	//onary
	const PhysicalNumber operator+(); 
	const PhysicalNumber operator-(); 
	//Addition and subtraction
	 PhysicalNumber operator+(const PhysicalNumber& n); 
	 PhysicalNumber operator-(const PhysicalNumber& n); 
	//Addition and subtraction one
	PhysicalNumber& operator++();
	PhysicalNumber& operator--();
	PhysicalNumber operator++(int);
	PhysicalNumber operator--(int);

	const PhysicalNumber& operator+=(const PhysicalNumber& n); 
	const PhysicalNumber& operator-=(const PhysicalNumber& n);
	
	friend ostream& operator<<(ostream& os, const PhysicalNumber& n);
	friend istream& operator>>(istream& is, PhysicalNumber& n);

	//logical operator
	 const bool operator>(const PhysicalNumber& n);
	 const bool operator<(const PhysicalNumber& n);
	 const bool operator<=(const PhysicalNumber& n);
	 const bool operator>=(const PhysicalNumber& n);
	 const bool operator==(const PhysicalNumber& n);
	 const bool operator!=(const PhysicalNumber& n);
	};
	 ostream& operator<<(ostream& os, const PhysicalNumber& n);
	 istream& operator>>(istream& is, PhysicalNumber& n);
}