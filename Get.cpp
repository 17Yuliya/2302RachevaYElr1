#include "def.h"

L2* GetInd(Form f, int& ind, bool type) {
	int i = 0;

	int len = LenList(f);
	if (len == -1) return NULL;

	cout << "\n������� ������ ��������";
	int count = 0;

	if (type) {
		cout << "(������ ������ ���� ������ �� 0 �� " << len - 1 << "): ";
		cin >> ind;

		while (!cin || ind < 0 || ind > len - 1) {
			if (!cin) Clear();

			count += 1;
			if (count == 3) { cout << "\n������: ������� �������������, ������ �� ���������."; return NULL; }

			cout << "\n�������� ������ �����. ������� ����� �� 0 �� " << len - 1 << ": ";
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

//6. ��������� �������� �� �������
L2* GetElemInd(Form f, int& ind) {
	f.cur = GetInd(f, ind, 1);

	if (f.cur != NULL) {
		cout << "������� ��� �������� " << ind << " �������� ����� " << f.cur->inf << "\n";
		return f.cur;
	}

	cout << "\n������ �������� ������� ������.";
	return NULL;
}