#include "def.h"

//9. �������� ���� ��������� ������
void DelList(Form& f) {
	cout << "\n������� 9: �������� ���� ��������� ������.";

	if (f.head == NULL) { cout << "\n������ ��� �� �������� ���������"; return; }

	f.cur = f.head;
	while (f.head) {
		f.head = f.head->next;
		delete f.cur;
		f.cur = f.head;
	}
	f.cur = NULL;

	cout << "\n������ ����.\n";
}

//3. �������� ���������� ��������
void DelLast(Form& f) {
	cout << "\n������� 3: �������� ���������� �������� ������.";
	
	clock_t start = clock();

	if (f.head == NULL) { cout << "\n�� ������� ������ ������ ������� �������"; return; }

	if (f.head == f.last) {
		delete f.head;
		f.head = f.last = NULL;
		cout << "\n������� ������ ������.";

		cout << "runtime = " << clock() / 1000.0 << endl; // ����� ������ ���������                  
		system("pause");

		return;
	}

	f.last->prev->next = NULL;
	f.cur = f.last;
	f.last = f.cur->prev;

	delete f.cur;
}

//4. �������� ������� ��������
void DelHead(Form& f) {
	cout << "\n������� 4: �������� ������� �������� ������.";
	if (f.head == NULL) { cout << "\n�� ������� ������ ������ ������� �������"; return; }

	if (f.head == f.last) {
		delete f.head;
		f.head = f.last = NULL;
		cout << "\n������� ������ ������.";
		return;
	}

	f.head->next->prev = NULL;
	f.cur = f.head;
	f.head = f.cur->next;

	delete f.cur;
}

//7. �������� �������� �� �������
void DelElemInd(Form& f, int ind) {
	cout << "\n������� 7: �������� �������� �� �������.";

	f.cur = GetElemInd(f, ind);

	if (f.cur == NULL) cout << "\n������ ������� ������� �� ������� ������.";
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