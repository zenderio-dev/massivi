#include <iostream>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    int SIZE; 

    cout << "Введите размер массива через пробел: " << endl;
    cin >> SIZE; // Размер массива

    // Динамическое выделение памяти под массив
    int* array = new int[SIZE]; 
    
    // Заполнение массива
    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < SIZE; ++i) {
        cin >> array[i]; 
    }

    int max_length = 0; // Максимальная длина последовательности нулей
    int current_length = 0; // Текущая длина последовательности нулей

    for (int i = 0; i < SIZE; ++i) {
        if (array[i] == 0) { // Если текущий элемент массива равен нулю
            current_length++; // Прибавляем к значению текущей длины массива единицу
        }
        else {
            current_length = 0; // Сбрасываем значение длины
        }
        
        if (current_length > max_length) { // Если текущая длина больше максимальной
            max_length = current_length;
        }
    }

    cout << "Максимальная последовательность идущих подряд нулей = " << max_length << endl;

    delete[] array; // Чистим память после выделения

    return 0;
}