#pragma hdrstop
#include<iomanip>
#include<conio.h>
#include"Set.h"
#include"BitField.h"
int main(int argc, char* argv[]) {
	setlocale(LC_CTYPE, "Russian");
	int n, m, k, count;
	cout << "Тестирование Множеств" << endl;
	cout << "		Решето Эратосфена" << endl;
	cout << "Введите верхнюю границу целых значений - ";
	cin >> n;
	Set s(n + 1);
	for (m = 2; m <= n; m++) {
		s.InsElem(m);
	}
	for (m = 2; m * m <= n; m++) {
		if (s.IsMember(m)) {
			for (k = 2 * m; k <= n; k += m) {
				if (s.IsMember(k)) {
					s.DelElem(k);
				}
			}
		}
	}
	cout << "Печать простых чисел" << endl;
	count = 0;
	k = 1;
	for (m = 2; m <= n; m++) {
		if (s.IsMember(m)) {
			count++;
			cout << setw(3) << m << " ";
			if (k++ % 10 == 0) {
				cout << endl;
			}
		}
	}
	cout << endl;
	cout << "В первых " << n << " числах " << count << " простых" << endl;
	return 0;
}