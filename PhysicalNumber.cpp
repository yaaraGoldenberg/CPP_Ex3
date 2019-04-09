#include "PhysicalNumber.h"
#include <iostream>
#include "Unit.h"
using namespace std;
using namespace ariel;

PhysicalNumber::PhysicalNumber(double num1, Unit U1){
	num = num1;
	U = U1;
}

const PhysicalNumber PhysicalNumber::operator+() const{
	return PhysicalNumber(0,Unit::KM);
}
const PhysicalNumber PhysicalNumber::operator-() const{
	return PhysicalNumber(0,Unit::KM);
}

const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& n) const{
	return PhysicalNumber(0,Unit::KM);	
}

const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& n) const{
	return PhysicalNumber(0,Unit::KM);
}

PhysicalNumber& PhysicalNumber::operator++() {
	return *this;
}

PhysicalNumber& PhysicalNumber::operator--() {
	return *this;
}

const PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& n){
	return *this;
}

const PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& n){
	return *this;
}

ostream& ariel::operator<<(ostream& out, const PhysicalNumber& n){
	return out;
}

istream& ariel::operator>>(istream& in, PhysicalNumber& n){
	return in;
}

const bool PhysicalNumber::operator>(const PhysicalNumber& n){
	return true;
}
const bool PhysicalNumber::operator<(const PhysicalNumber& n){
	return true;
}
const bool PhysicalNumber::operator<=(const PhysicalNumber& n){
	return true;
}
const bool PhysicalNumber::operator>=(const PhysicalNumber& n){
	return true;
}
const bool PhysicalNumber::operator==(const PhysicalNumber& n){
	return true;
}
const bool PhysicalNumber::operator!=(const PhysicalNumber& n){
	return true;
}