#pragma once
#include "BitString.h"
#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
using namespace std;

class Set {
private:
	BitString data;
public:
	Set() {};
	Set(unsigned long f1, unsigned long f2) : data(f1, f2) {};
	Set(const Set&);


	void Init(unsigned long value1, unsigned long value2);

	unsigned long getField_1() const { return data.getField_1(); }
	unsigned long getField_2() const { return data.getField_2(); }

	void setField_1(unsigned long value) { data.setField_1(value); }
	void setField_2(unsigned long value) { data.setField_2(value); }

	friend ostream& operator <<(ostream&, const Set& set);
	friend istream& operator >>(istream&, Set& set);

	Set& operator = (const BitString& other);
	friend Set operator+(const Set& set, int element);
	friend Set operator-(const Set& set, int element);
	Set& operator+=(const Set& other);
	friend Set operator/(const Set& set1, const Set& set2);
	Set operator()(const Set& other) const;

	int operator[](int index) const;

	friend Set operator <(const Set& other, int bits);
	friend Set operator >(const Set& other, int bits);
	operator string() const;
};