#include "def.h"

//10. замена элемента по индексу на передаваемый элемент
void SubsElem(Form& f) {
	cout << "\n\nФункция 10: Замена элемента по индексу на передаваемый элемент.";

	int ind = 0;
	f.cur = GetElemInd(f, ind);
	if (f.cur == NULL) { cout << "\nОшибка: не удалось найти индекс."; return; }

	cout << "\nВведите число, на которое будет заменен элемент " << f.cur->inf << " с индексом " << ind << ": ";
	cin >> f.cur->inf;
	Check(f);

	if (f.cur == NULL) cout << "\nОшибка: передаваемый элемент пуст.";
}

//19. обмен 2х элементов списка по индексам
void Swap(Form& f, int i, int j) {
	cout << "\n\nФункция 19: Обмен 2х элементов списка по индексам.";

	if (f.head == NULL) { cout << "\nСписок пуст. Нельзя выполнить функцию."; return; }
	if (f.head == f.last) { cout << "\nВ списке только один элемент. Нельзя выполнить функцию."; return; }

	L2* el1, * el2;
	int tmp;

	el1 = GetElemInd(f, i);
	el2 = GetElemInd(f, j);
	if (i == j) return;

	tmp = el1->inf;
	el1->inf = el2->inf;
	el2->inf = tmp;

	el2 = el1 = NULL;
}

//12. изменение порядка элементов в списке на обратный
void ChangeOrd(Form f) {
	L2* left, * right;
	int tmp;

	cout << "\nФункция 12: Изменение порядка элементов в списке на обратный";

	if (f.head == NULL) { cout << "\nСписок пуст."; return; }
	if (f.head == f.last) { cout << "\nВ списке только один элемент."; return; }

	left = f.head;
	right = f.last;

	while (left && right && left != right) {
		tmp = left->inf;
		left->inf = right->inf;
		right->inf = tmp;

		if (left->next == right) {
			left = left->next;
		}
		else {
			right = right->prev;
			left = left->next;
		}
	}
}