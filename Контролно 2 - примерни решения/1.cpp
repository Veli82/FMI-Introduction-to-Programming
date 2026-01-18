#include <iostream>

void rotateArrRight(int* arr, int size, int k)
{
    for (int i = 0; i < k; i++)
    {
        int last = arr[size - 1];
        
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        
        arr[0] = last * 2;
    } 
}

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';
}

int main()
{
    int size;
    std::cin >> size;

    int *arr = new int[size]; 
    
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    int k;
    std::cin >> k;
    
    rotateArrRight(arr, size, k);

    printArr(arr, size);

    delete[] arr;
}