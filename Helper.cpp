#include "def.h"

void Clear() { //очищение буфера и игнорирование символов в нем
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}

void Check(Form& f) { //проверка на формат ввода 
	int i = 0;
	while (!cin) {
		i++;
		if (i == 3) { f.cur = NULL; return; }
		if (!cin) Clear();
		
		cout << "\nНеверный формат ввода. Введите число: ";
		cin >> f.cur->inf;
	}
}

void OutList(Form f) {
	cout << "\nПолученный список: ";

	if (f.head == NULL) return;
	
	f.cur = f.head;
	while (f.cur) {
		cout << f.cur->inf << ' ';
		f.cur = f.cur->next;
	}
	cout << '\n';
}

//8. получение размера списка
int LenList(Form f) {
	if (f.head == NULL) {
		cout << "\nСписок пуст. Его размер - 0 элементов.\n";
		return -1;
	}

	int len = 0;
	f.cur = f.head;
	while (f.cur) {
		len += 1;
		f.cur = f.cur->next;
	}

	return len;
}

//11. проверка на пустоту списка
void CheckEmpty(Form f) {
	cout << "\nФункция 11: Проверка на пустоту списка. ";
	if (!f.head) cout << "\nРезультат: Список пуст.";
	else cout << "\nРезультат: Список не является пустым.";
}

