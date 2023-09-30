#include "def.h"

void InitForm(Form& f) { //инициализаци€ формул€ра
	f.cur = NULL; f.head = NULL; f.last = NULL;
}

void CreateHead(Form& f) {
	L2* tmp = new L2;

	if (tmp != NULL) {
		cin >> tmp->inf;

		if (!cin) { Clear(); delete tmp; return; }

		tmp->next = NULL;
		tmp->prev = NULL;
		f.head = tmp;
		f.last = tmp;
		f.cur = tmp;
	}
}

int CreateL2(Form& f) {
	int len = 0;
	cout << "\n¬ведите числа дл€ формировани€ списка: ";

	InitForm(f);
	CreateHead(f);

	if (f.head) f.cur = f.head;
	while (f.cur) { len++; AddElemEnd(f); }

	return len;
}