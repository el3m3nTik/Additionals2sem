#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#define N 100

void Shell1(int arr[], int n)
{
    int d = n / 2;                      

    while (d > 0)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i;
            while (j >= 0 && arr[j] > arr[j + d])
            {
                int temp = arr[j];
                arr[j] = arr[j + d];
                arr[j + d] = temp;

                j--;
            }
        }
        d = d / 2;
    }

}

int main()
{

    int n = 100;                          //число элементов

    int* arr = new int[n];                  //создание массива из n элементов

    for (int i = 0; i < n; i++)             //инициализируем массив
        arr[i] = rand();

    Shell1(arr, n);

    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << std::endl;
    }

    delete[] arr;

    return 0;
}