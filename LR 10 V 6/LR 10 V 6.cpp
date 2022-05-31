//Разработайте программу методом пошаговой детализации для работы с целочисленным двумерным массивом.
//Реализовать возможность ввода размерности массива и его элементов из текстового файла.
//Вычислить сумму кратных 5 элементов массива и вывести его на экран.
//Найти в каждом столбце сумму четных элементов и вывести найденные значения в текстовый в новый текстовый файл в столбик.
//Найти первый двузначный элемент массива и вывести его на экран. Если двузначных элементов нет, то выведите соответствующее сообщение.
//Заменить во второй строке все однозначные элементы на второй элемент массива.
//Вывести измененный массив в текстовый файл в виде матрицы.
//Проверить, в каждой ли строке все элементы четные. Ответ вывести на экран.



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Sum5(int(&arr)[10][100], int size1, int size2) {
    int sum = 0;
    for (int i = 0; i < size1; ++i) {
        for (size_t k = 0; k < size2; k++)
        {

            if (arr[i][k] % 5 == 0) {
                sum += arr[i][k];
            }
        }

    }
    return sum;
}

int First2Digit(int(&arr)[10][100], int size1, int size2) {

    int el = 0;

    for (int i = 0; i < size1; ++i) {
        for (size_t k = 0; k < size2; k++)
        {
            if (arr[i][k] > 9 && arr[i][k] < 100) {
                el = arr[i][k];
                break;
            }
        }
        if (el != 0) {
            break;
        }
    }
    return el;
}

void Change(int(&arr)[10][100], int size2) {
    for (size_t i = 0; i < size2; i++)
    {
        if (arr[1][i] >= 0 && arr[1][i] <= 9) {
            arr[1][i] = arr[0][1];
        }
    }
}
bool AllEven(int(&arr)[10][100], int size1, int size2) {
    bool a = true;

    for (int i = 0; i < size1; ++i) {
        for (size_t k = 0; k < size2; k++)
        {
            if (arr[i][k] % 2 != 0) {
                a = false;
                break;
            }
        }
        if (!a) {
            break;
        }
    }
    return a;
}

int main() {

    setlocale(0, "");


    fstream file("Array.txt", ios::in);

    int arr[10][100];
    int size1 = 0;
    int size2 = 0;
    int size2_cop = 0;

    if (!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        cout << "Файл открыт" << endl;
        char ch;
        int n;
        string num;
        while (!file.eof()) {

            file >> size1 >> size2;
            for (size_t i = 0; i < size1; i++)
            {
                for (size_t j = 0; j < size2; j++)
                {
                    file >> arr[i][j];
                }
            }

        }
    }

    file.close();


    for (int i = 0; i < size1; ++i) {
        for (size_t k = 0; k < size2; k++)
        {

            cout << arr[i][k] << ' ';
        }
        cout << endl;
    }

    cout << endl << "Сумма кратных 5 элементов массива: " << Sum5(arr, size1, size2) << endl;

    fstream sum_even_file("SumEven.txt", ios::out);

    for (size_t i = 0; i < size2; i++)
    {
        int sum_even = 0;
        for (size_t j = 0; j < size1; j++)
        {
            if (arr[j][i] % 2 == 0) {
                sum_even += arr[j][i];
            }
        }
        sum_even_file << sum_even << endl;
    }
    sum_even_file.close();

    if (First2Digit(arr, size1, size2) == 0) {
        cout << "двузначных элементов нет" << endl;
    }
    else {
        cout << "Первый двузначный элемент = " << First2Digit(arr, size1, size2) << endl;
    }


    if (AllEven(arr, size1, size2)) {

        cout << "Все элементы четные" << endl;
    }
    else {
        cout << "Не все элементы четные" << endl;
    }

    Change(arr, size2);
    file.open("Array.txt", ios::app);
    file << endl;
    for (int i = 0; i < size1; ++i) {
        for (size_t k = 0; k < size2; k++)
        {
            if (k == 3) {
                file << arr[i][k];
            }
            else {
                file << arr[i][k] << ' ';
            }

        }
        file << endl;
    }
    file.close();

    return 0;
}
