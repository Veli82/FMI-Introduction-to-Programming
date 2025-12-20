**Задача 1**

```cpp
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i = 0; i < 10; i++)
    {
        std::cout << *(arr + i);
    }
}
```

**Задача 2**

В тази задача може и без да взимаме дължината на char масива (просто ще въртим цикъла докато `*(str + i) != '\0'`).

```cpp
int getLength(char* str)
{
    int length = 0;

    for (int i = 0; *(str + i) != '\0'; i++)
    {   
        length++;
    }

    return length;
}

void copyStr(char* input, char* result, int size)
{
    for (int i = 0; *(input + i) != '\0' /* или до size*/; i++)
    {
        char currSymbol = *(input + i);

        if (currSymbol >= '0' && currSymbol <= '9')
        {
            *(result + i) = ' ';
        }
        else
        {
            *(result + i) = currSymbol;
        }
    }
}

int main()
{
    char input[100];
    std::cin >> input;

    char result[100];

    int length = getLength(input);

    copyStr(input, result, length);

    for (int)
}
```

**Задача 3**

```cpp
void operatorPlusEquals(int& ref, int increment)
{
    ref += increment;
}

int main()
{
    int a = 5;
    int b = 3;

    operatorPlusEquals(a, b);

    std::cout << a; // 8
}
```

**Задача 4**

```cpp
int getLength(char* str)
{
    char* currPtr = str;

    while (currPtr + 1 != '\0')
    {
        currPtr++;
    }

    return currPtr - str;
}

int main()
{
    char str[100];
    std::cin >> str;

    std::cout << getLength(str);
}
```

**Задача 5**

Единственото нещо, което правим тук е да пренасочим `ptr` към `*(matrix + largestAvgIndex)`, което ще ни даде редът от матрицата (масив/указател към първия елемент от този масив) с най-голямо средно аритметично на елементите в него. Забележете, че подаваме псевдоним/референция към указател на функцията `findLargestAvgArr`. Това е защото, искаме да променим точно този указател, който сме подали отвън (да сменим адреса към който сочи). Ако вместо това бяхме подали само указател към int, щяхме да копираме указателя и нямаше да афектираме този, който сме подали отвън.

```cpp
void fillMatrix(int matrix[100][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void findLargestAvgArr(int *&ptr, int matrix[100][100], int rows, int cols)
{
    int largestAvgIndex = 0;
    int largestAvg = 0;
    int currAvg = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            currAvg += matrix[i][j];
        }

        currAvg /= cols;

        if (currAvg > largestAvg)
        {
            largestAvg = currAvg;
            largestAvgIndex = i;
        }
    }

    ptr = *(matrix + largestAvgIndex);
}

int main()
{
    const int size = 100;

    int matrix[size][size];
    
    int rows, cols;
    std::cin >> rows >> cols;

    fillMatrix(matrix, rows, cols);

    int* largestAvgArr = nullptr;

    findLargestAvgArr(largestAvgArr, matrix, rows, cols);

    for (int i = 0; i < cols; i++)
    {
        std::cout << *(largestAvgArr + i) << ' ';
    }
}
```