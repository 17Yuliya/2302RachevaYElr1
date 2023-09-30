#include "def.h"

L2* GetInd(Form f, int& ind, bool type) {
	int i = 0;

	int len = LenList(f);
	if (len == -1) return NULL;

	cout << "\nВведите индекс элемента";
	int count = 0;

	if (type) {
		cout << "(индекс должен быть числом от 0 до " << len - 1 << "): ";
		cin >> ind;

		while (!cin || ind < 0 || ind > len - 1) {
			if (!cin) Clear();

			count += 1;
			if (count == 3) { cout << "\nОшибка: Попытки израсходованы, индекс не определен."; return NULL; }

			cout << "\nНеверный формат ввода. Введите число от 0 до " << len - 1 << ": ";
			cin >> ind;
		}
	}

	f.cur = f.head;
	while (i < ind) {
		i += 1;
		f.cur = f.cur->next;
	}

	return f.cur;
}

//6. получение элемента по индексу
L2* GetElemInd(Form f, int& ind) {
	f.cur = GetInd(f, ind, 1);

	if (f.cur != NULL) {
		cout << "Элемент под индексом " << ind << " содержит число " << f.cur->inf << "\n";
		return f.cur;
	}

	cout << "\nНельзя получить элемент списка.";
	return NULL;
}