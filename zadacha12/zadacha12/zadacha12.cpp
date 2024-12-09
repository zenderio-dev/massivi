// Задан числовой массив A[n]. 
// Найти отрезок массива максимальной длины, 
// в котором первое число равно последнему, 
// второе – предпоследнему и т.д. Напечатать длину этого отрезка 
#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int SIZE; // Размер массива
  
    cout << "Введите длину массива array: " << endl;
    cin >> SIZE;

    int* array = new int[SIZE + 1]; // Динамическое выделение памяти

    cout << "Введите элементы массива array через пробел: " << endl;
    for (int i = 0; i < SIZE; ++i) {
        cin >> array[i];
    }

    int maxLenght = 0;

    // Начинаем проверять симметричность с каждого элемента массива
    for (int i = 0; i < SIZE; ++i) {
        int* left = array + i;
        int* right = array + (SIZE - 1);

        int currentLenght = 0;

        while (left <= right) {
            if (*left == *right) {
                // Если указатели указывают на один и тот же элемент то длину увеличиваем не на 2 а на 1
                if (left == right) {
                    currentLenght += 1;
                } else {
                    currentLenght += 2;
                }
                // переходим на следующие элементы
                left++;
                right--;

            } else {
                break;
            }
        }
        // Если текущая длина больше максимальной то перезаписываем максимальную
        if (currentLenght > maxLenght) {
            maxLenght = currentLenght;
        }
    }
    
    // Вывод результатов
    cout << "Максимальная длина симметричной части массива = " << maxLenght << endl;

    
    delete[] array; // Почистили память

    return 0;
}
