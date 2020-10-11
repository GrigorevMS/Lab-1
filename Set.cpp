#include"Set.h"
Set::Set(int mp) {
	MaxPower = mp;
	BitF = mp;
}
Set::Set(const Set& s) {
	MaxPower = s.MaxPower;
	BitF = s.BitF;
}
Set::Set(const BitField& bf) {
	MaxPower = bf.GetLength();
	BitF = bf;
}
Set::operator BitField() {
	BitField temp(this->BitF);
	return(temp);
}
int Set::GetMaxPower(void) const {
	return MaxPower;
}
void Set::InsElem(const int n) {
	BitF.SetBit(n);
}
void Set::DelElem(const int n) {
	BitF.ClearBit(n);
}
int Set::IsMember(const int n) const {
	return BitF.GetBit(n);
}
int Set::operator== (const Set& s) {
	return BitF == s.BitF;
}
Set& Set::operator= (const Set& s) {
	BitF = s.BitF;
	MaxPower = s.GetMaxPower();
	return *this;
}
Set Set::operator+ (const Set& s) {
	Set temp(BitF | s.BitF);
	return temp;
}
Set Set::operator* (const Set& s) {
	Set temp(BitF & s.BitF);
	return temp;
}
Set Set::operator~ (void) {
	Set temp(~BitF);
	return temp;
}
istream& operator>>(istream& istr, Set& bf) {
	int temp;
	char ch;
	do {
		istr >> ch;
	} while (ch != '{');
	do {
		istr >> temp;
		bf.InsElem(temp);
		do {
			istr >> ch;
		} while (ch != ',' && ch != '}');
	} while (ch != '}');
	return(istr);
}
ostream& operator<<(ostream& ostr, const Set& bf) {
	int i, n;
	char ch = ' ';
	ostr << "{";
	n = bf.GetMaxPower();
	for (i = 0; i < n; i++) {
		if (bf.IsMember(i)) {
			ostr << ch << ' ' << i;
			ch = ',';
		}
	}
	ostr << " }";
	return ostr;
}