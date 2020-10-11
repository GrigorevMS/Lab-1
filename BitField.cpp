#include"BitField.h"
// Конструкторы
BitField::BitField() {
	MemLen = 0;
	BitLen = 0;
	pMem = NULL;
}
BitField::BitField(int len) : BitLen(len) {
	MemLen = (len + 31) >> 5;
	pMem = new unsigned int[MemLen];
	if (pMem != NULL) {
		for (int i = 0; i < MemLen; i++) {
			pMem[i] = 0;
		}
	}
}
BitField::BitField(const BitField& bf) {
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new unsigned int[MemLen];
	if (pMem != NULL) {
		for (int i = 0; i < MemLen; i++) {
			pMem[i] = bf.pMem[i];
		}
	}
}
BitField::~BitField() {
	delete pMem;
	pMem = NULL;
}
// Методы
int BitField::GetMemInd(const int n) const {
	int ind = n;
	return ind >> 5;
}
unsigned int BitField::GetMemMask(const int n) const {
	unsigned int ind = n % 32;
	return 1 << (n & 31);
}
int BitField::GetLength(void) const {
	return BitLen;
}
void BitField::SetBit(const int n) {
	if ((n > -1) && (n < BitLen)) {
		pMem[GetMemInd(n)] |= GetMemMask(n);
	}
}
void BitField::ClearBit(const int n) {
	if ((n > -1) && (n < BitLen)) {
		pMem[GetMemInd(n)] &= ~GetMemMask(n);
	}
}
int BitField::GetBit(const int n) const {
	if ((n > -1) && (n < BitLen)) {
		return pMem[GetMemInd(n)] & GetMemMask(n);
	}
}
int BitField::operator== (const BitField& bf) {
	int res = 1;
	if (BitLen != bf.BitLen) {
		res = 0;
	}
	else {
		for (int i = 0; i < MemLen; i++) {
			if (pMem[i] != bf.pMem[i]) {
				res = 0;
				break;
			}
		}
	}
	return res;
}
BitField& BitField::operator= (const BitField& bf) {
	BitLen = bf.BitLen;
	if (MemLen != bf.MemLen) {
		MemLen = bf.MemLen;
		if (pMem != NULL) {
			delete pMem;
		}
		pMem = new unsigned int[MemLen];
	}
	if (pMem != NULL) {
		for (int i = 0; i < MemLen; i++) {
			pMem[i] = bf.pMem[i];
		}
	}
	return *this;
}
BitField BitField::operator| (const BitField& bf) {
	int i, len = BitLen;
	if (bf.BitLen > len) {
		len = bf.BitLen;
	}
	BitField temp(len);
	for (int i = 0; i < MemLen; i++) {
		temp.pMem[i] = pMem[i];
	}
	for (int i = 0; i < bf.MemLen; i++) {
		temp.pMem[i] |= bf.pMem[i];
	}
	return temp;
}
BitField BitField::operator& (const BitField& bf) {
	int i, len = BitLen;
	if (bf.BitLen > len) {
		len = bf.BitLen;
	}
	BitField temp(len);
	for (int i = 0; i < MemLen; i++) {
		temp.pMem[i] = pMem[i];
	}
	for (int i = 0; i < bf.MemLen; i++) {
		temp.pMem[i] &= bf.pMem[i];
	}
	return temp;
}
BitField BitField::operator~ (void) {
	int len = BitLen;
	BitField temp(len);
	for (int i = 0; i < MemLen; i++) {
		temp.pMem[i] = ~pMem[i];
	}
	return temp;
}
istream& operator>>(istream& istr, BitField& bf) {
	int i = 0;
	char ch;
	do {
		istr >> ch;
	} while (ch != ' ');
	while (1) {
		istr >> ch;
		if (ch == '0'){
			bf.ClearBit(i++);
		}
		else if (ch == '1') {
			bf.SetBit(i++);
		}
		else {
			break;
		}
	}
	return istr;
}
ostream& operator<<(ostream& ostr, const BitField& bf) {
	int len = bf.GetLength();
	for (int i = 0; i < len; i++) {
		if (bf.GetBit(i)) ostr << '1'; else ostr << '0';
	}
	return(ostr);
}