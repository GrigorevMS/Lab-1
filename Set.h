#pragma once
#include <iostream>
#include "BitField.h"
using namespace std;
class Set {
private:
	int MaxPower; // ������������ �������� ���-��
	BitField BitF; // �������� ���� ��� �������� ���-�� �������
public:
	Set(int mp);
	Set(const Set & s); 
	Set(const BitField & bf);
	operator BitField(); // �������������� ���� � �������� ����
	// ������ � �����
	int GetMaxPower(void) const;
	void InsElem(const int n);
	void DelElem(const int n);
	int IsMember(const int n) const;
	// �������-������������� ��������
	int operator== (const Set & s);
	Set& operator= (const Set & s);
	Set operator+ (const int n);
	Set operator- (const int n);
	Set operator+ (const Set & s);
	Set operator* (const Set & s);
	Set operator~ (void);
	friend istream& operator>>(istream & istr, Set & bf);
	friend ostream& operator<<(ostream & ostr, const Set & bf);
};