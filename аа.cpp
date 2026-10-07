#include <iostream>
#include <Windows.h>

using namespace std;

void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << "]";
}

void bubbleSort(int arr[], int size) {
    cout << "Сортування бульбашкою\n";
    int totalSteps = 0;

    for (int i = 0; i < size - 1; i++) {
        int stepsInIteration = 0;
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            stepsInIteration++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                stepsInIteration++;
            }
        }
        totalSteps += stepsInIteration;
        cout << "Етап " << (i + 1) << ": ";
        printArray(arr, size);
        cout << "  Виконано дій: " << stepsInIteration << "\n";

        if (!swapped) break;
    }
    cout << "Загальна кількість виконаних дій під час сортування: " << totalSteps << "\n";
}

void selectionSort(int arr[], int size) {
    cout << "Сортування вибором\n";
    int totalSteps = 0;

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        int stepsInIteration = 0;

        for (int j = i + 1; j < size; j++) {
            stepsInIteration++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            stepsInIteration++;
        }

        totalSteps += stepsInIteration;
        cout << "Етап " << (i + 1) << ": ";
        printArray(arr, size);
        cout << " Виконано дій: " << stepsInIteration << "\n";
    }
    cout << "Загальна кількість виконаних дій під час сортування: " << totalSteps << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    int* arrForBubble = new int[size];
    int* arrForSelection = new int[size];

    cout << "Введіть " << size << " елементів масиву:\n";
    for (int i = 0; i < size; i++) {
        cin >> arrForBubble[i];
        arrForSelection[i] = arrForBubble[i];
    }

    cout << "\nПочатковий масив (Бульбашка): ";
    printArray(arrForBubble, size);
    cout << "\n";
    bubbleSort(arrForBubble, size);


    cout << "Початковий масив (Вибір): ";
    printArray(arrForSelection, size);
    cout << "\n";
    selectionSort(arrForSelection, size);

    delete[] arrForBubble;
    delete[] arrForSelection;

    return 0;
}