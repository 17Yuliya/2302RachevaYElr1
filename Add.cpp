#include "def.h"

//1. добавление в конец списка
void AddOneElEnd(Form& f) { //нет проверки на корректность 

	cout << "\nФункция 1: Добавление элемента в конец списка.\nВведите число, которое нужно добавить в конец списка: ";
		
	if (f.head == NULL) CreateHead(f);
	else AddElemEnd(f);

	if (!f.cur) cout << "\nНе удалось выполнить функцию.";
}

//2. добавление элемента в начало списка
void AddOneElTop(Form& f) {
	cout << "\nФункция 2: Добавление элемента в начало списка.\nВведите число, которое нужно добавить в начало списка: ";

	if (f.head == NULL) CreateHead(f);
	else {
		L2* tmp = new L2;

		if (tmp != NULL) {
			cin >> tmp->inf;

			if (!cin) { Clear(); delete tmp; cout << "\nНе удалось выполнить функцию."; return; }

			f.head->prev = tmp;
			tmp->next = f.head;
			tmp->prev = NULL;
			f.head = tmp;
		}
	}
	if (!f.head) cout << "\nНе удалось выполнить функцию.";
}

//5. добавление элемента по индексу (вставка перед элементом, который был ранее доступен по этому индексу)
void AddElInd(Form& f, int ind) {
	cout << "\nФункция 5: Добавление элемента по индексу.";
	f.cur = GetElemInd(f, ind);

	if (f.cur == NULL) { cout << "\nОшибка: не удалось найти индекс.\n"; return; }
	else if (f.cur == f.head) AddOneElTop(f);
	else {
		L2* tmp = new L2;

		cout << "\nВведите число, которое нужно добавить в список: ";
		cin >> tmp->inf;
		Check(f);

		if (f.cur != NULL) {
			tmp->next = f.cur;
			tmp->prev = f.cur->prev;
			f.cur->prev = tmp;
			tmp->prev->next = tmp;
			f.cur = tmp;
		}
		else cout << "\nОшибка: элемент, который необходимо добавить, пуст.";
	}
}

void AddElemEnd(Form& f) {
	L2* tmp = new L2;

	if (tmp != NULL) {
		cin >> tmp->inf;

		if (!cin) { Clear(); delete tmp; f.cur = NULL; return; }
		
		f.last->next = tmp;
		tmp->prev = f.last;
		tmp->next = NULL;
		f.last = tmp;
		f.cur = tmp;
	}
	
}

//14. вставка другого списка в конец
void AddListEnd(Form& f) {
	cout << "\nФункция 14: Вставка другого списка в конец.";

	if (!f.head) CreateL2(f);
	else {
		cout << "\nВведите список: ";
		f.cur = f.head;
		while (f.cur) AddElemEnd(f);
	}
}

void AddElemCur(Form& f) {
	L2* tmp = new L2;

	if (tmp != NULL) {

		cin >> tmp->inf;

		if (!cin) { Clear(); delete tmp; f.cur = NULL; return; }

		if (f.cur == f.head) {
			f.head->prev = tmp;
			tmp->next = f.head;
			tmp->prev = NULL;
			f.head = tmp;
		}
		else {
			tmp->next = f.cur;
			tmp->prev = f.cur->prev;
			f.cur->prev = tmp;
			tmp->prev->next = tmp;
		}
		f.cur = tmp->next;

	}
}

//15. вставка другого списка в начало
void AddListBeg(Form& f) {
	cout << "\nФункция 15: Вставка другого списка в начало.";

	if (!f.head) CreateL2(f);
	else {
		cout << "\nВведите список: ";
		f.cur = f.head;
		while (f.cur) AddElemCur(f);
	}
}

//13. вставка другого списка в список, начиная с индекса
void AddListInd(Form& f, int ind) {
	cout << "\nФункция 13: Вставка другого списка в список, начиная с индекса.";

	if (!f.head) { cout << "\nОшибка: в пустом списке нельзя выполнить данную функцию, т.к. он не содержит индексов."; return; }

	L2* el = GetInd(f, ind, 1);
	if (el == f.last) AddListEnd(f);
	else if (el == f.head) AddListBeg(f);
	else {
		cout << "\nВведите список: ";
		f.cur = el->next;
		while (f.cur) AddElemCur(f);
	}

	el = NULL;
}