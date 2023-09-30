#include "def.h"

void Clear() { //�������� ������ � ������������� �������� � ���
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
}

void Check(Form& f) { //�������� �� ������ ����� 
	int i = 0;
	while (!cin) {
		i++;
		if (i == 3) { f.cur = NULL; return; }
		if (!cin) Clear();
		
		cout << "\n�������� ������ �����. ������� �����: ";
		cin >> f.cur->inf;
	}
}

void OutList(Form f) {
	cout << "\n���������� ������: ";

	if (f.head == NULL) return;
	
	f.cur = f.head;
	while (f.cur) {
		cout << f.cur->inf << ' ';
		f.cur = f.cur->next;
	}
	cout << '\n';
}

//8. ��������� ������� ������
int LenList(Form f) {
	if (f.head == NULL) {
		cout << "\n������ ����. ��� ������ - 0 ���������.\n";
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

//11. �������� �� ������� ������
void CheckEmpty(Form f) {
	cout << "\n������� 11: �������� �� ������� ������. ";
	if (!f.head) cout << "\n���������: ������ ����.";
	else cout << "\n���������: ������ �� �������� ������.";
}

