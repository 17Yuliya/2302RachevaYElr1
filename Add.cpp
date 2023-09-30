#include "def.h"

//1. ���������� � ����� ������
void AddOneElEnd(Form& f) { //��� �������� �� ������������ 

	cout << "\n������� 1: ���������� �������� � ����� ������.\n������� �����, ������� ����� �������� � ����� ������: ";
		
	if (f.head == NULL) CreateHead(f);
	else AddElemEnd(f);

	if (!f.cur) cout << "\n�� ������� ��������� �������.";
}

//2. ���������� �������� � ������ ������
void AddOneElTop(Form& f) {
	cout << "\n������� 2: ���������� �������� � ������ ������.\n������� �����, ������� ����� �������� � ������ ������: ";

	if (f.head == NULL) CreateHead(f);
	else {
		L2* tmp = new L2;

		if (tmp != NULL) {
			cin >> tmp->inf;

			if (!cin) { Clear(); delete tmp; cout << "\n�� ������� ��������� �������."; return; }

			f.head->prev = tmp;
			tmp->next = f.head;
			tmp->prev = NULL;
			f.head = tmp;
		}
	}
	if (!f.head) cout << "\n�� ������� ��������� �������.";
}

//5. ���������� �������� �� ������� (������� ����� ���������, ������� ��� ����� �������� �� ����� �������)
void AddElInd(Form& f, int ind) {
	cout << "\n������� 5: ���������� �������� �� �������.";
	f.cur = GetElemInd(f, ind);

	if (f.cur == NULL) { cout << "\n������: �� ������� ����� ������.\n"; return; }
	else if (f.cur == f.head) AddOneElTop(f);
	else {
		L2* tmp = new L2;

		cout << "\n������� �����, ������� ����� �������� � ������: ";
		cin >> tmp->inf;
		Check(f);

		if (f.cur != NULL) {
			tmp->next = f.cur;
			tmp->prev = f.cur->prev;
			f.cur->prev = tmp;
			tmp->prev->next = tmp;
			f.cur = tmp;
		}
		else cout << "\n������: �������, ������� ���������� ��������, ����.";
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

//14. ������� ������� ������ � �����
void AddListEnd(Form& f) {
	cout << "\n������� 14: ������� ������� ������ � �����.";

	if (!f.head) CreateL2(f);
	else {
		cout << "\n������� ������: ";
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

//15. ������� ������� ������ � ������
void AddListBeg(Form& f) {
	cout << "\n������� 15: ������� ������� ������ � ������.";

	if (!f.head) CreateL2(f);
	else {
		cout << "\n������� ������: ";
		f.cur = f.head;
		while (f.cur) AddElemCur(f);
	}
}

//13. ������� ������� ������ � ������, ������� � �������
void AddListInd(Form& f, int ind) {
	cout << "\n������� 13: ������� ������� ������ � ������, ������� � �������.";

	if (!f.head) { cout << "\n������: � ������ ������ ������ ��������� ������ �������, �.�. �� �� �������� ��������."; return; }

	L2* el = GetInd(f, ind, 1);
	if (el == f.last) AddListEnd(f);
	else if (el == f.head) AddListBeg(f);
	else {
		cout << "\n������� ������: ";
		f.cur = el->next;
		while (f.cur) AddElemCur(f);
	}

	el = NULL;
}