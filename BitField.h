#pragma once
#include<iostream>
using namespace std;
class BitField {
private:
	int BitLen; // ����� �������� ����
	unsigned int* pMem; // ������ ��� �������� ����
	int MemLen; // �-�� ��-�� ��� ����
	// ������ ����������
	int GetMemInd(const int n) const; // ������ pMem ������ ����
	unsigned int GetMemMask(const int n) const; // ������� �����
public:
	BitField();
	BitField(int len);
	BitField(const BitField& bf);
	~BitField();
	// ������ � �����
	int GetLength(void) const; // �������� ����� �����
	void SetBit(const int n); // ���������� ���
	void ClearBit(const int n); // �������� ���
	int GetBit(const int n) const; // �������� �������� ����
	// ������� ��������
	int operator== (const BitField& bf); // ���������
	BitField& operator= (const BitField& bf); // ������������
	BitField operator| (const BitField& bf); // �������� "���"
	BitField operator& (const BitField& bf); // �������� "�"
	BitField operator~ (void); // ���������
	friend istream& operator>>(istream& istr, BitField& bf);
	friend ostream& operator<<(ostream& ostr, const BitField& bf);
}; 