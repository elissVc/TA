#include <iostream>
#include <Windows.h>

using namespace std;

void linearSearch(int arr[], int size, int target) {
    cout << "Лінійний пошук\n";
    int steps = 0;
    for (int i = 0; i < size; i++) {
        steps++;
        if (arr[i] == target) {
            cout << "Елемент " << target << " знайдено за " << steps << " кроків на індексі " << i << ".\n";
            return;
        }
    }
    cout << "Елемент не знайдено. Кроків: " << steps << "\n";
}

void binarySearch(int arr[], int size, int target) {
    cout << "Двійковий пошук\n";
    int left = 0;
    int right = size - 1;
    int steps = 0;

    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            cout << "Елемент " << target << " знайдено за " << steps << " кроків на індексі " << mid << ".\n";
            return;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << "Елемент не знайдено. Кроків: " << steps << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    int* arrForSearch = new int[size];
    cout << "Введіть " << size << " елементів масиву (для двійкового пошуку вводьте відсортовані дані):\n";
    for (int i = 0; i < size; i++) {
        cin >> arrForSearch[i];
    }

    int target;
    cout << "Введіть елемент для пошуку: ";
    cin >> target;

    cout << "\n";
    linearSearch(arrForSearch, size, target);
    cout << "\n";
    binarySearch(arrForSearch, size, target);

    delete[] arrForSearch;
    return 0;
}