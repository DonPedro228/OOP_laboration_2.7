#pragma once
#include <bitset>
#include <iostream>
#include <string>
using namespace std;

class BitString
{
private:
	unsigned long field_1;
	unsigned long field_2;
public:
	BitString() : field_1(0), field_2(0) {}
	BitString(unsigned long f1, unsigned long f2) : field_1(f1), field_2(f2) {}
	BitString(const BitString& other);

	void Init(unsigned long value1, unsigned long value2);

	unsigned long getField_1() const { return field_1; }
	unsigned long getField_2() const { return field_2; }

	void setField_1(unsigned long value) { field_1 = value; }
	void setField_2(unsigned long value) { field_2 = value; }

	operator string() const;
	BitString& operator = (const BitString&);
	friend ostream& operator <<(ostream&, const BitString&);
	friend istream& operator >>(istream&, BitString&);

	BitString& operator ++();
	BitString& operator --();

	BitString operator &(const BitString& other) const;
	BitString operator |(const BitString& other) const;
	BitString operator ^(const BitString& other);
	friend BitString operator!=(const BitString& lhs, const BitString& rhs);
	friend BitString operator <(const BitString& other, int bits);
	friend BitString operator >(const BitString& other, int bits);
};