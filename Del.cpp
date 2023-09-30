#include "def.h"

//9. удаление всех элементов списка
void DelList(Form& f) {
	cout << "\nФункция 9: Удаление всех элементов списка.";

	if (f.head == NULL) { cout << "\nСписок уже не содержит элементов"; return; }

	f.cur = f.head;
	while (f.head) {
		f.head = f.head->next;
		delete f.cur;
		f.cur = f.head;
	}
	f.cur = NULL;

	cout << "\nСписок пуст.\n";
}

//3. удаление последнего элемента
void DelLast(Form& f) {
	cout << "\nФункция 3: Удаление последнего элемента списка.";
	
	clock_t start = clock();

	if (f.head == NULL) { cout << "\nИз пустого списка нельзя удалить элемент"; return; }

	if (f.head == f.last) {
		delete f.head;
		f.head = f.last = NULL;
		cout << "\nПолучен пустой список.";

		cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы                  
		system("pause");

		return;
	}

	f.last->prev->next = NULL;
	f.cur = f.last;
	f.last = f.cur->prev;

	delete f.cur;
}

//4. удаление первого элемента
void DelHead(Form& f) {
	cout << "\nФункция 4: Удаление первого элемента списка.";
	if (f.head == NULL) { cout << "\nИз пустого списка нельзя удалить элемент"; return; }

	if (f.head == f.last) {
		delete f.head;
		f.head = f.last = NULL;
		cout << "\nПолучен пустой список.";
		return;
	}

	f.head->next->prev = NULL;
	f.cur = f.head;
	f.head = f.cur->next;

	delete f.cur;
}

//7. Удаление элемента по индексу
void DelElemInd(Form& f, int ind) {
	cout << "\nФункция 7: Удаление элемента по индексу.";

	f.cur = GetElemInd(f, ind);

	if (f.cur == NULL) cout << "\nНельзя удалить элемент из пустого списка.";
	else if (f.cur == f.head) DelHead(f);
	else if (f.cur == f.last) DelLast(f);
	else {
		L2* tmp = f.cur;
		f.cur->prev->next = f.cur->next;
		f.cur->next->prev = f.cur->prev;
		f.cur = f.cur->prev;
		delete tmp;
	}
}