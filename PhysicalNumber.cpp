#include "PhysicalNumber.h"
#include <iostream>

using namespace std;
using namespace ariel;

PhysicalNumber::PhysicalNumber(double num1, int U1){
	num = num1;
	U = U1;
}

const PhysicalNumber PhysicalNumber::operator+() const{
	return PhysicalNumber(0,0);
}

const PhysicalNumber PhysicalNumber::operator-() const{
	return PhysicalNumber(0,0);
}

const PhysicalNumber& PhysicalNumber::operator+(const PhysicalNumber& n) const{
	return n;	
}

const PhysicalNumber& PhysicalNumber::operator-(const PhysicalNumber& n) const{
	return n;
}

PhysicalNumber& PhysicalNumber::operator++() {
	return *this;
}

PhysicalNumber& PhysicalNumber::operator--() {
	return *this;
}

const PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& n){
	return n;
}

const PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& n){
	return n;
}

ostream& ariel::operator<<(ostream& out, const PhysicalNumber& n){
	return out;
}

istream& ariel::operator>>(istream& in, PhysicalNumber& n){
	return in;
}

bool operator>(const PhysicalNumber& n, const PhysicalNumber& n1){
	return true;
}
bool operator<(const PhysicalNumber& n, const PhysicalNumber& n1){
	return true;
}
bool operator<=(const PhysicalNumber& n, const PhysicalNumber& n1){
	return true;
}
bool operator>=(const PhysicalNumber& n, const PhysicalNumber& n1){
	return true;
}
bool operator==(const PhysicalNumber& n, const PhysicalNumber& n1){
	return true;
}
bool operator!=(const PhysicalNumber& n, const PhysicalNumber& n1){
	return true;
}