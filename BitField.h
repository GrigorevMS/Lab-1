#pragma once
#include<iostream>
using namespace std;
class BitField {
private:
	int BitLen; // длина битового поля
	unsigned int* pMem; // память для битового поля
	int MemLen; // к-во эл-ов для поля
	// методы реализации
	int GetMemInd(const int n) const; // индекс pMem внутри бита
	unsigned int GetMemMask(const int n) const; // битовая маска
public:
	BitField();
	BitField(int len);
	BitField(const BitField& bf);
	~BitField();
	// доступ к битам
	int GetLength(void) const; // получить длину битов
	void SetBit(const int n); // установить бит
	void ClearBit(const int n); // очистить бит
	int GetBit(const int n) const; // получить значение бита
	// битовые операции
	int operator== (const BitField& bf); // сравнение
	BitField& operator= (const BitField& bf); // присваивание
	BitField operator| (const BitField& bf); // операция "или"
	BitField operator& (const BitField& bf); // операция "и"
	BitField operator~ (void); // отрицание
	friend istream& operator>>(istream& istr, BitField& bf);
	friend ostream& operator<<(ostream& ostr, const BitField& bf);
}; 