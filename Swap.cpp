#include "def.h"

//10. ������ �������� �� ������� �� ������������ �������
void SubsElem(Form& f) {
	cout << "\n\n������� 10: ������ �������� �� ������� �� ������������ �������.";

	int ind = 0;
	f.cur = GetElemInd(f, ind);
	if (f.cur == NULL) { cout << "\n������: �� ������� ����� ������."; return; }

	cout << "\n������� �����, �� ������� ����� ������� ������� " << f.cur->inf << " � �������� " << ind << ": ";
	cin >> f.cur->inf;
	Check(f);

	if (f.cur == NULL) cout << "\n������: ������������ ������� ����.";
}

//19. ����� 2� ��������� ������ �� ��������
void Swap(Form& f, int i, int j) {
	cout << "\n\n������� 19: ����� 2� ��������� ������ �� ��������.";

	if (f.head == NULL) { cout << "\n������ ����. ������ ��������� �������."; return; }
	if (f.head == f.last) { cout << "\n� ������ ������ ���� �������. ������ ��������� �������."; return; }

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

//12. ��������� ������� ��������� � ������ �� ��������
void ChangeOrd(Form f) {
	L2* left, * right;
	int tmp;

	cout << "\n������� 12: ��������� ������� ��������� � ������ �� ��������";

	if (f.head == NULL) { cout << "\n������ ����."; return; }
	if (f.head == f.last) { cout << "\n� ������ ������ ���� �������."; return; }

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