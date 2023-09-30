#include <iostream>
#include "def.h"

int main() {
    Form list, list2;
    int ind = 0, a = 0, len = 0;
    int count = 0; //счетчик попыток

    setlocale(LC_ALL, "Russian");

    CreateL2(list);
    OutList(list);

    cout << "\n\n1. Добавить элемент в конец списка.\n2. Добавить элемент в начало списка.\n3. Удалить последний элемент.\n"
        "4. Удалить первый элемент.\n5. Добавить элемент по индексу.\n6. Получить элемент по индексу.\n7. Удалить элемент по индексу"
        "\n8. Получить размер списка.\n9. Удалить все элементы списка.\n10. Заменить элемент по индексу на передаваемый элемент."
        "\n11. Проверить список на пустоту.\n12. Изменить порядок элементов в списке на обратный.\n13. Вставить другой список в список,"
        " начиная с индекса.\n14. Вставить другой список в конец.\n15. Вставить другой список в начало.\n16. Проверить список на содержание"
        " другого списка в списке.\n17. Поиск первого вхождения другого списка в список.\n18. Поиск последнего вхождения другого списка"
        " в список.\n19. Обмен двух элементов списка по индексам.\n20. Завершить работу программы.\n";

    while (a != 20 && count < 3) {
        count = 0;
        cout << "\nВведите номер функции, которую необходимо выполнить: ";

        cin >> a;
        while (!cin || a < 1 || a > 20) {
            count += 1;
            if (count == 3) { cout << "Попытки израсходованы."; return 0; }
            Clear();
            cout << "\nНеверный формат ввода. Введите число от 1 до 20: ";
            cin >> a;
        }

        switch (a) {
        case 1:
            AddOneElEnd(list); OutList(list); break;
        case 2:
            AddOneElTop(list); OutList(list); break;
        case 3:
            DelLast(list); OutList(list); break;
        case 4:
            DelHead(list); OutList(list); break;
        case 5:
            AddElInd(list, 0); OutList(list); break;
        case 6:
            cout << "\nФункция 6: Получение элемента по индексу.";
            GetElemInd(list, ind); break;
        case 7:
            DelElemInd(list, 0); OutList(list); break;
        case 8:
            cout << "\nФункция 8: Вычисление размера списка.\n";
            len = LenList(list);
            if (len != -1) cout << "Длина списка равна " << len;
            break;
        case 9:
            DelList(list); break;
        case 10:
            SubsElem(list); OutList(list); break;
        case 11:
            CheckEmpty(list); break;
        case 12:
            ChangeOrd(list); OutList(list); break;
        case 13:
            AddListInd(list, ind); OutList(list); break;
        case 14:
            AddListEnd(list); OutList(list); break;
        case 15:
            AddListBeg(list); OutList(list); break;
        case 16:
            ListInList(list, list2); break;
        case 17:
            FirstListInList(list, list2); break;
        case 18:
            LastListInList(list, list2); break;
        case 19:
            Swap(list, 0, 0); OutList(list); break;
        default:
            break;
        }
    }
    DelList(list);

    return 0;
}

