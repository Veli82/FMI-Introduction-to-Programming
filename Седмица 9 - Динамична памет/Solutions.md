**Задача 1**

```cpp
int* createArray(int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    return arr;
}
```

**Задача 2**

[Решение](https://github.com/KipoDipo/UP-Seminar/blob/full-course/C%2B%2B/Week11%20-%20heap%20tasks/Solutions/task3.cpp)  

**Задача 3**

[Решение](https://github.com/KipoDipo/UP-Seminar/blob/full-course/C%2B%2B/Week11%20-%20heap%20tasks/Solutions/nextTask2.cpp)  

**Задача 4**

```cpp
int* getCharCount(char* str)
{
	int* arr = new int[128] {};

	for (int i = 0; str[i] != '\0'; i++)
	{
		arr[str[i]]++;
	}
	return arr;
}

int main()
{
	char str[] = "aabs1WWr125#$!%";
	int* arr = getCharCount(str);
	for (int i = 0; i < 128; i++)
	{
		if (arr[i] > 0)
		{
			std::cout << char(i) << " - " << arr[i] << '\n';
		}
	}
    delete[] arr;
}
```

**Задача 5**

```cpp
int** createMatrix(int n, int m)
{
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}
```

**Задача 6**

```cpp
int main()
{
    int n = 3;  //example sizes
    int m = 3;
    int** matrix = createMatrix(n, m);

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
```

**Задача 7**

```cpp
bool isValidSymbol(char symbol)
{
    return (
        (symbol >= 'a') && (symbol <= 'z')      //small letter
        || (symbol >= 'A') && (symbol <= 'Z')   //or capital letter
        || (symbol >= '1') && (symbol <= '9')   //or number
    );
}

int main()
{
    char str[100];
    std::cin >> str;
    int newStrLen = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isValidSymbol(str[i]))
            newStrLen++;
    }
    char* newStr = new char[newStrLen + 1] {};

    for (int i = 0, j = 0; str[i] != '\0'; i++)
    {
        if (isValidSymbol(str[i]))
        {
            newStr[j] = str[i];
            j++;
        }
    }
    std::cout << newStr;
    delete[] newStr;
}
```

**Задача 8**  
В задача 8 и 9 показваме лек teaser на това как работи един динамичен масив (като std::vector). Това подробно се учи в курса по ООП, но вече имаме нужните знания за да имплементираме повечето функционалности на тази структура.
```cpp
void pushBack(int*& arr, int& size, int& cap, int num)
{
    if (size == cap)    //if not enough space, resize!
    {
        cap = cap * 2 > 0 ? cap * 2 : 1;   //if initial cap was 0, cap * 2 would still be 0
        int* newArr = new int[cap] {};
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    arr[size] = num;
    size++;
    //the last 2 rows are the same as:   arr[size++] = num;
    //but NOT the same as:               arr[++size] = num;
}
```

**Задача 9**

```cpp
void popBack(int*& arr, int& size, int& cap)
{
    if (size == 0)  //cant remove an element if there are none
        return;
    arr[size - 1] = 0;
    size--;
    //or arr[--size] = 0;

    if (size * 4 <= cap)
    {
        cap = cap / 2 > 0 ? cap / 2 : 1;   //ensure that cap does not go to 0
        int* newArr = new int[cap] {};
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
}
```

**Задача 10**

[Решение](https://github.com/KipoDipo/UP-Seminar/blob/main/C%2B%2B/Week11%20-%20heap%20tasks/Solutions/task4.cpp)  

**Задача 12**  
Тази задача се оказа с не толкова елегантно решение, колкото си мислихме че ще е когато я писахме. Не е много красив код, но работи. Определено не е най-добрата задача за упражнение, но оставяме решението да го има за пълнота.
```cpp
void printMatrix(int** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

//samo zadelq pamet
int** initializeMatrix(int n, int m)
{
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }
    return matrix;
}

int main()
{
    int n;
    std::cin >> n;

    if (n < 4 || n % 2 != 0)
        return 0;

    int** matrix = createMatrix(n, n);

    int subMatrixSize = n / 2;

    int** matrix1 = initializeMatrix(subMatrixSize, subMatrixSize);
    int** matrix2 = initializeMatrix(subMatrixSize, subMatrixSize);
    int** matrix3 = initializeMatrix(subMatrixSize, subMatrixSize);
    int** matrix4 = initializeMatrix(subMatrixSize, subMatrixSize);

    for (int i = 0; i < subMatrixSize; i++)
    {
        for (int j = 0; j < subMatrixSize; j++)
        {
            matrix1[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < subMatrixSize; i++)
    {
        for (int j = 0; j < subMatrixSize; j++)
        {
            matrix2[i][j] = matrix[i][j + subMatrixSize];
        }
    }

    for (int i = 0; i < subMatrixSize; i++)
    {
        for (int j = 0; j < subMatrixSize; j++)
        {
            matrix3[i][j] = matrix[i + subMatrixSize][j];
        }
    }

    for (int i = 0; i < subMatrixSize; i++)
    {
        for (int j = 0; j < subMatrixSize; j++)
        {
            matrix4[i][j] = matrix[i + subMatrixSize][j + subMatrixSize];
        }
    }

    printMatrix(matrix1, subMatrixSize, subMatrixSize);
    printMatrix(matrix2, subMatrixSize, subMatrixSize);
    printMatrix(matrix3, subMatrixSize, subMatrixSize);
    printMatrix(matrix4, subMatrixSize, subMatrixSize);

    delete[] matrix;
    delete[] matrix1;
    delete[] matrix2;
    delete[] matrix3;
    delete[] matrix4;
}
```