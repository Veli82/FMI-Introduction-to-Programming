# Задачи

**Задача 1**

```cpp
void fillMatrix(int matrix[100][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[100][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        
        std::cout << std::endl;
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    int matrix[100][100];

    fillMatrix(matrix);

    printMatrix(matrix);
}
```

**Задача 2**

От тук надолу ще използваме функциите, които написахме в първа задача.

```cpp
int getSmallestNum(int matrix[100][100], int n, int m)
{
    int smallestNum = matrix[0][0];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] < smallestNum)
            {
                smallestNum = matrix[i][j];
            }
        }
    }
    
    return smallestNum;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    int matrix[100][100];

    fillMatrix(matrix, n, m);
    
    std::cout << getSmallestNum(matrix, n, m);
}
```

**Задача 3**

```cpp
    int main()
{
    int n, m;
    std::cin >> n >> m;

    int firstMatrix[100][100];
    fillMatrix(firstMatrix, n, m);
    
    int secondMatrix[100][100];
    fillMatrix(secondMatrix, n, m);
    
    int sumMatrix[100][100];
    
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sumMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
    
    printMatrix(sumMatrix, n, m);
}
```

**Задача 4**

За тази задача използваме функция, която сменя символа на този, който искаме да редуваме (`' '` с `'#'`). Правим го във вложения цикъл, за да сменяме символа на всяка клетка и след вложения цикъл, за да сменим началния символ за следващата начална клетка (най-горният ред започва с `' '`). Освен функцията, за смяна на символа ни трябва и нова print функция, тъй като тук имаме матрица от символи, а не от цели числа.

```cpp
char switchSymbol(char currSymbol)
{
    if (currSymbol == ' ')
    {
        return '#';
    }

    return ' ';
}

void printBoard(char board[100][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << board[i][j];
        }

        std::cout << std::endl;
    }
}

int main()
{
    const int size = 8;
    
    char board[100][100];
    
    char currSymbol = ' ';
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = currSymbol;
            currSymbol = switchSymbol(currSymbol);
        }
        
        currSymbol = switchSymbol(currSymbol);
    }

    printBoard(board, size);
}
```
**Задача 4 (Бонус)**

За първото бонус условие трябва да добавим `rows - i`, в първата клетка на всеки ред, за да получим числените координати. Обърнете внимание на вложения цикъл. Тук `j` започва от 1 и върти до `< size + 1`.Това е нужно, за да не презапишем числовия координат в началото на всеки ред. За буквите трябва след последния ред от дъската да добавим интервал в първата клетка, за да може буквите да съвпадат с клетките на дъската, след което да завъртим цикъл 8 пъти, който поставя буквата, започвайки от `'А'` и увеличава стойността ѝ с 1. Тук подаваме `size + 1`, на функцията printBoard, за да принтираме и координатите.

```cpp
int main()
{
    const int size = 8;
    
    char board[100][100];
    
    char currSymbol = ' ';
    
    for (int i = 0; i < size; i++)
    {
        board[i][0] = size - i + '0';
        
        for (int j = 1; j < size + 1; j++)
        {
            board[i][j] = currSymbol;
            currSymbol = switchSymbol(currSymbol);
        }
        
        currSymbol = switchSymbol(currSymbol);
    }
    
    board[size][0] = ' ';
    
    char letterCoord = 'A';
    
    for (int i = 1; i < size + 1; i++)
    {
        board[size][i] = letterCoord++;
    }
    
    printBoard(board, size + 1);
}
```

**Задача 4 (Бонус 2)**

Единственото, което променихме по предишното решение е да добавим while цикъл, който се върти докато първия символ прочетен от конзолата е различен от `Q`. В него вземаме първия символ от координатите, изваждаме `'А'` и прибавяме `1`. По този начин конвертираме буквата в число (позиция от 1 до 9). За втория координат искаме да извадим символа `'0'`, за да получим число, което искаме да извадим от size, за да получим правилния индекс за реда, тъй като редовете се запълват отгоре надолу. 

```cpp
int main()
{
    const int size = 8;
    
    char board[100][100];
    
    char currSymbol = ' ';
    
    for (int i = 0; i < size; i++)
    {
        board[i][0] = size - i + '0';
        
        for (int j = 1; j < size + 1; j++)
        {
            board[i][j] = currSymbol;
            currSymbol = switchSymbol(currSymbol);
        }
        
        currSymbol = switchSymbol(currSymbol);
    }
    
    board[size][0] = ' ';
    
    char letterCoord = 'A';
    
    for (int i = 1; i < size + 1; i++)
    {
        board[size][i] = letterCoord++;
    }
  
    char coords[3] {};
    std::cin >> coords;
    
    while (coords[0] != 'Q')
    {
        int letterCoord = coords[0] - 'A' + 1;
        int numberCoord = size - (coords[1] - '0');
        
        board[numberCoord][letterCoord] = '0';
        
        printBoard(board, size + 1);
        
        std::cin >> coords;
    }
}
```

**Задача 5**

Тук искаме да пропуснем размяна на елементите на главния диагонал, защото няма смисъл (главният диагонал на една матрица е еднакъв с транспонираната ѝ матрица). Затова започваме вложения цикъл от i + 1 (j никога не е 0). По този начин i и j никога няма да равни и следователно никога няма да афектираме главния диагонал.

```cpp
int main()
{
    int n;
    std::cin >> n;

    int matrix[100][100];
    fillMatrix(matrix, n, n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tempCell = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tempCell;
        }
    }
    
    printMatrix(matrix, n, n);
}
```

**Задача 6**

Тук искам да итерираме през клетките на matrixProduct като за всяко итериране искаме да прибавим произведенията за съответния ред от първата и колона от втората матрица. Ако имаме две матрици като първата има различен брой колони от броя редове на втората, не можем да умножим матриците ("Invalid input!"). Нека сега имаме матрица с размери `pxm` и друга с размери `mxn`, то тяхното произведение е матрица с размери `pxn`. Първият цикъл итерира до firstRow (редовете както на първата така и на получената матрица), вторият до secondCol (колоните както на втората так аи на получената матрица), а последният цикъл итерира до общия размер за двете матрици (в нашия случай или firstCol, или secondRow без значение кое от двете използваме). За `matrixProduct[i][j]` (една клетка от получената матрица) искаме да прибававяме `+=` резултата от произведението на `firstMatrix[i][k]` и `secondMatrix[k][j]` (с други думи "ред по стълб").

```cpp
int main()
{
    int firstRow, firstCol;
    std::cin >> firstRow >> firstCol;

    int firstMatrix[100][100];
    fillMatrix(firstMatrix, firstRow, firstCol);
    
    int secondRow, secondCol;
    std::cin >> secondRow >> secondCol;
    
    if (firstCol != secondRow)
    {
        std::cout << "Invalid input!";
        
        return 0;
    }
    
    int secondMatrix[100][100];
    fillMatrix(secondMatrix, secondRow, secondCol);
    
    int matrixProduct[100][100] { {} };
    
    for (int i = 0; i < firstRow; i++)
    {
        for (int j = 0; j < secondCol; j++)
        {
            for (int k = 0; k < firstCol; k++)
            {
                matrixProduct[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
    
    printMatrix(matrixProduct, firstRow, secondCol);
}
```