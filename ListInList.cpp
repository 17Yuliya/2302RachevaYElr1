#include "def.h"

//16. проверка на содержание другого списка в списке
void ListInList(Form f1, Form& f2) {
	int count = 0, len2;
	L2* first;
	cout << "\n\nФункция 16: Проверка на содержание другого списка в списке.\n";

	len2 = CreateL2(f2);

	if (!f1.head && !f2.head) { cout << "\nПустой список содержится в пустом списке."; return; }
	if (!f2.head) { cout << "\nВведен пустой список. Пустой список содержится в любом списке."; return; }

	f1.cur = f1.head;
	f2.cur = f2.head;
	first = f1.cur;

	while (f1.cur && f2.cur) {
		if (f1.cur->inf == f2.cur->inf) {
			if (count == 0) first = f1.cur->next;
			++count;
			f1.cur = f1.cur->next;
			f2.cur = f2.cur->next;
		}
		else if (count < len2) {
			f2.cur = f2.head;
			if (count == 0) f1.cur = f1.cur->next;
			else f1.cur = first;
			count = 0;
		}
		if (count == len2) {
			cout << "Результат: Введенный список содержится в исходном.\n";
			DelList(f2);
			return;
		}
	}
	DelList(f2);
	cout << "Результат: Введенный список не содержится в исходном.\n";
}

//17. Поиск первого вхождения другого списка в список
void FirstListInList(Form f1, Form& f2) {
	int count = 0, len2, ind = 0;
	L2* first;
	cout << "\n\nФункция 17: Поиск первого вхождения другого списка в список\n";
	if (!f1.head) { cout << "\nОшибка: Исходный список пуст. Выполнить функцию невозможно."; return; }

	len2 = CreateL2(f2);
	if (!f2.head) { cout << "\nОшибка: Введен пустой список. Выполнить функцию невозможно."; return; }

	f1.cur = f1.head;
	f2.cur = f2.head;
	first = f1.cur;  

	while (f1.cur && f2.cur) {
		if (f1.cur->inf == f2.cur->inf) {
			if (count == 0) first = f1.cur->next;
			++count;
			f1.cur = f1.cur->next;
			f2.cur = f2.cur->next;
		}
		else if (count < len2) {
			f2.cur = f2.head;
			if (count == 0) f1.cur = f1.cur->next;
			else f1.cur = first;
			ind++;
			count = 0;
		}
		if (count == len2) {
			cout << "Результат: Первое вхождение введенного списка в исходный начинается с индекса " << ind << ".\n";
			DelList(f2);
			return;
		}
	}
	DelList(f2);
	cout << "Результат: Введенный список не содержится в исходном.\n";

}

//17. Поиск последнего вхождения другого списка в список
void LastListInList(Form f1, Form& f2) {
	int count = 0, len2, ind = 0;
	cout << "\n\nФункция 18: Поиск последнего вхождения другого списка в список\n";

	if (!f1.head) { cout << "\nОшибка: Исходный список пуст. Выполнить функцию невозможно."; return; }
	len2 = CreateL2(f2);
	if (!f2.head) { cout << "\nОшибка: Введен пустой список. Выполнить функцию невозможно."; return; }

	int len1 = LenList(f1);

	f1.cur = f1.last;
	f2.cur = f2.last;
	L2* first = f1.cur;

	while (f1.cur && f2.cur) {
		if (f1.cur->inf == f2.cur->inf) {
			if (count == 0) first = f1.cur->prev;
			++count;
			f1.cur = f1.cur->prev;
			f2.cur = f2.cur->prev;
		}
		else if (count < len2) {
			f2.cur = f2.last;
			if (count == 0) { f1.cur = f1.cur->prev; ind++; }
			else { f1.cur = first; ind += count; }

			count = 0;
		}
		if (count == len2) {
			ind = len1 - len2 - ind;
			cout << "Результат: Последнее вхождение введенного списка в исходный начинается с индекса " << ind << ".\n";
			DelList(f2);
			return;
		}
	}
	DelList(f2);
	cout << "Результат: Введенный список не содержится в исходном.\n";
}