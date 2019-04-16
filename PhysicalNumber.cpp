#include "PhysicalNumber.h"
#include <iostream>
#include "Unit.h"
#include <stdexcept>
//#include <string.h>
using namespace std;
using namespace ariel;

const string type[9] = { "cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton" };
const double value[9] = { 1, 100, 100000, 1, 60, 3600, 1, 1000, 1000000 };

PhysicalNumber::PhysicalNumber(double num1, Unit U1){
	num = num1;
	U = U1;
}

bool PhysicalNumber::equalDimension(const PhysicalNumber& pn, const PhysicalNumber& pn1) {
	if (((int)pn.U >= 0 && (int)pn.U <= 2 && (int)pn1.U >= 0 && (int)pn1.U <= 2) || ((int)pn.U >= 3 && (int)pn.U <= 5 && (int)pn1.U >= 3 && (int)pn1.U <= 5)
		|| ((int)pn.U >= 6 && (int)pn.U <= 8 && (int)pn1.U >= 6 && (int)pn1.U <= 8)) {
		return true;
	}
	return false;
}

//onary
const PhysicalNumber PhysicalNumber::operator+(){
	if (this->num < 0) {
		return PhysicalNumber(-num, U);
	}
	else {
		return PhysicalNumber(num, U);
	}
}
const PhysicalNumber PhysicalNumber::operator-(){
	return PhysicalNumber(-num,U);
}
//Addition and subtraction
const PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& n){
	double ans = 0;
	if (equalDimension(n, *this) == false) {
		throw std::invalid_argument("The dimensions are not the same\n");
	}
	else {
		ans = this->num + (n.num * (double(value[(int)n.U]) / value[(int)this->U]));
	}
	return PhysicalNumber(ans, this->U);
}

const PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& n){
	double ans = 0;
	if (equalDimension(n, *this) == false) {
		throw std::invalid_argument("The dimensions are not the same\n");
	}
	else {
		ans = this->num - (n.num * (double(value[(int)n.U]) / value[(int)this->U]));
	}
	return PhysicalNumber(ans, this->U);
}
//Addition and subtraction one
PhysicalNumber& PhysicalNumber::operator++() {
	this->num = this->num + 1;
	return *this;
}

PhysicalNumber& PhysicalNumber::operator--() {
	this->num = this->num - 1;
	return *this;
}

const PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& n){
	if (equalDimension(n, *this) == false) {
		throw std::invalid_argument("The dimensions are not the same\n");
	}
	else {
		this->num = this->num + (n.num * (double(value[(int)n.U]) / value[(int)this->U]));
	}
	return *this;
}

const PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& n){
	if (equalDimension(n, *this) == false) {
		throw std::invalid_argument("The dimensions are not the same\n");
	}
	else {
		this->num = this->num - (n.num * (double(value[(int)n.U]) / value[(int)this->U]));
	}
	return *this;
}

ostream& ariel::operator<<(ostream& os, const PhysicalNumber& n){
	return (os << n.num << "[" << type[(int)n.U] << "]");
}

istream& ariel::operator>>(istream& is, PhysicalNumber& n) {
	string str, number, t;
	is >> str;

	number = str.substr(0, str.find("["));
	t = str.substr(str.find("[") + 1, str.length() - str.find("[") - 2);
	bool flagT = false, flagN = false;
	int index;
	for (int i = 0; i < 9; i++) {
		if (t == type[i]) {
			index = i;
			flagT = true;
		}
	}
	for (int i = 0; i < number.length(); i++) {
		if (isdigit(number.at(i))|| number.at(i) == '.') {
			flagN = true;
		}
	}
	if (str.find("[") == string::npos || str.find("]") == string::npos || flagT == false || flagN == false) {

		return is;
	}
	n.num=stod(number);
	n.U = (Unit)index;
	return is;
}

const bool PhysicalNumber::operator>(const PhysicalNumber& n){
	double ans = 0;
	if (equalDimension(n, *this) == false) {
		throw std::invalid_argument("The dimensions are not the same\n");
	}
	else {
		ans = (n.num * (double(value[(int)n.U]) / value[(int)this->U]));
	}
	return this->num>ans;
}
const bool PhysicalNumber::operator<(const PhysicalNumber& n){
	double ans = 0;
	if (equalDimension(n, *this) == false) {
		throw std::invalid_argument("The dimensions are not the same\n");
	}
	else {
		ans = (n.num * (double(value[(int)n.U]) / value[(int)this->U]));
	}
	return this->num<ans;
}
const bool PhysicalNumber::operator<=(const PhysicalNumber& n){
	double ans = 0;
	if (equalDimension(n, *this) == false) {
		throw std::invalid_argument("The dimensions are not the same\n");
	}
	else {
		ans = (n.num * (double(value[(int)n.U]) / value[(int)this->U]));
	}
	return this->num<=ans;
}
const bool PhysicalNumber::operator>=(const PhysicalNumber& n){
	double ans = 0;
	if (equalDimension(n, *this) == false) {
		throw std::invalid_argument("The dimensions are not the same\n");
	}
	else {
		ans = (n.num * (double(value[(int)n.U]) / value[(int)this->U]));
	}
	return this->num>=ans;
}
const bool PhysicalNumber::operator==(const PhysicalNumber& n){
	double ans = 0;
	if (equalDimension(n, *this) == false) {
		throw std::invalid_argument("The dimensions are not the same\n");
	}
	else {
		ans = (n.num * (double(value[(int)n.U]) / value[(int)this->U]));
	}
	return this->num=ans;
}
const bool PhysicalNumber::operator!=(const PhysicalNumber& n){
	double ans = 0;
	if (equalDimension(n, *this) == false) {
		throw std::invalid_argument("The dimensions are not the same\n");
	}
	else {
		ans = (n.num * (double(value[(int)n.U]) / value[(int)this->U]));
	}
	return this->num!=ans;
}