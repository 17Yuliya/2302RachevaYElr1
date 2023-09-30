#include "def.h"

//16. �������� �� ���������� ������� ������ � ������
void ListInList(Form f1, Form& f2) {
	int count = 0, len2;
	L2* first;
	cout << "\n\n������� 16: �������� �� ���������� ������� ������ � ������.\n";

	len2 = CreateL2(f2);

	if (!f1.head && !f2.head) { cout << "\n������ ������ ���������� � ������ ������."; return; }
	if (!f2.head) { cout << "\n������ ������ ������. ������ ������ ���������� � ����� ������."; return; }

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
			cout << "���������: ��������� ������ ���������� � ��������.\n";
			DelList(f2);
			return;
		}
	}
	DelList(f2);
	cout << "���������: ��������� ������ �� ���������� � ��������.\n";
}

//17. ����� ������� ��������� ������� ������ � ������
void FirstListInList(Form f1, Form& f2) {
	int count = 0, len2, ind = 0;
	L2* first;
	cout << "\n\n������� 17: ����� ������� ��������� ������� ������ � ������\n";
	if (!f1.head) { cout << "\n������: �������� ������ ����. ��������� ������� ����������."; return; }

	len2 = CreateL2(f2);
	if (!f2.head) { cout << "\n������: ������ ������ ������. ��������� ������� ����������."; return; }

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
			cout << "���������: ������ ��������� ���������� ������ � �������� ���������� � ������� " << ind << ".\n";
			DelList(f2);
			return;
		}
	}
	DelList(f2);
	cout << "���������: ��������� ������ �� ���������� � ��������.\n";

}

//17. ����� ���������� ��������� ������� ������ � ������
void LastListInList(Form f1, Form& f2) {
	int count = 0, len2, ind = 0;
	cout << "\n\n������� 18: ����� ���������� ��������� ������� ������ � ������\n";

	if (!f1.head) { cout << "\n������: �������� ������ ����. ��������� ������� ����������."; return; }
	len2 = CreateL2(f2);
	if (!f2.head) { cout << "\n������: ������ ������ ������. ��������� ������� ����������."; return; }

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
			cout << "���������: ��������� ��������� ���������� ������ � �������� ���������� � ������� " << ind << ".\n";
			DelList(f2);
			return;
		}
	}
	DelList(f2);
	cout << "���������: ��������� ������ �� ���������� � ��������.\n";
}