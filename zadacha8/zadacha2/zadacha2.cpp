// Даны два целочисленных массива X[n] и Y[n]. 
// Можно ли в первом из них выбрать такие k идущих подряд элементов 
// X[i+1], X[i+2], …, X[i+k], чтобы X[i+1]=Y[1], X[i+2] =Y[2], …, X[i+k] =Y[k]? 
// Написать программу, которая решает эту задачу и печатает ответ ДА или НЕТ.
#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int SIZEX, SIZEY; // Размеры массивов

    cout << "Введите длину массива X: " << endl;
    cin >> SIZEX;
    int* X = new int[SIZEX+1]; // Динамическое выделение памяи дя массива Х
    cout << "Введите целочисленные элементы массива Х через пробел: " << endl;
    for (int i = 0; i < SIZEX; ++i) {
        cin >> X[i];
    }

    cout << "Введите длину массива Y: " << endl;
    cin >> SIZEY;
    int* Y = new int[SIZEY+1]; // Динамическое выделение памяти для массива Y
    cout << "Введите целочисленные элементы массива Y через пробел: " << endl;
    for (int k = 0; k < SIZEY; ++k) {
        cin >> Y[k];
    }

    bool flag = false; // Флаг для отслеживания найденного подмассива

    // проверяем все возможные подмассивы в массиве Х
    for (int i = 0; i <= SIZEX-SIZEY; ++i) {
        int* ptrX = X + i; // Указатель на текущий элемент массива Х
        int* ptrY = Y; // Указатель на первый элемент массива Y

        // Сравнение элементов массивов
        while (ptrY < Y + SIZEY) {
            if ((*ptrX ^ *ptrY) != 0) {
                break;
            }
            ptrX++;
            ptrY++;
        }

        // если дошли до конца Y - значит мы нашли подмассив
        if (ptrY == Y + SIZEY) {
            flag = true;
            break;
        }
    }

    // Вывод результата
    if (flag) {
        cout << "ДА" << endl;
    } else {
        cout << "НЕТ" << endl;
    }

    // Чистим память
    delete[] X;
    delete[] Y;

    return 0;
}