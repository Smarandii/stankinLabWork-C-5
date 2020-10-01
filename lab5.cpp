#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include "editor.h"

void print(int* Array, int N) {
    int i;
    for (i = 0; i < N; i++) {
        std::cout << Array[i];
        std::cout << " ";
    }

}

int main()
{
    int N, K, i, S = 0, L;
    editor::matrix_editor matrix[10];
    editor::matrix_editor merged;
    std::cout << "input N (0 < N <= 10): ";
    std::cin >> N;
    std::cout << "input K (0 < K <= 10): ";
    std::cin >> K;
    std::cout << "\n";
    for (i = 0; i < N; i++) {
        matrix[i].input(K);
        matrix[i].move2();
        S = S + matrix[i].info();
    }

    for (i = 0; i < N; i++) {
        matrix[i].print();
    }
    std::cout << "\nSorted: " << S;
    
    int* result = matrix[0] + matrix[1];
    L = result[21]; // длинна массива лежит в 21 элементе (под элементы используются ячейки 0 - 20)
    std::cout << "\narray1 + array2 =\n"; 
    print(result, L);

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"