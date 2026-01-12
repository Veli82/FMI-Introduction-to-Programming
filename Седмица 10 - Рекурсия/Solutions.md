**Задача 1**

```cpp
long long factorial(int number)
{
    if (number == 1)
    {
        return 1;
    }

    return number * factorial(number - 1);
}
```

**Задача 2**

```cpp
int power(int number, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }

    return number * power(number, exponent - 1);
}
```

**Задача 3**

```cpp
int fib(int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }
    
    return fib(n - 1) + fib(n - 2);
}
```

**Задача 4**

```cpp
int sumOfDigits(int num)
{
    if (num == 0)
    {
        return 0;
    }
    
    return num % 10 + sumOfDigits(num / 10);
}
```

**Задача 5**

```cpp
void print(int n)
{
	if (n == 0)
    {
        return;
    }
	for (int i = 1; i <= n; i++)
	{
		std::cout << i;
	}
	std::cout << '\n';
	print(n - 1);
}
```

**Задача 6**

```cpp
int strLen(char* str)
{
	if (*str == '\0') return 0;

	return 1 + strLen(str + 1);
}
```

**Задача 7**

```cpp
int numLength(int num)
{
    if (num == 0)
    {
        return 0;   
    }
    
    return 1 + numLength(num / 10);
}

int revNum(int num)
{
    if (num < 10)
        return num;

    int numLen = numLength(num);

    return (num % 10) * pow(10, numLen - 1) + revNum(num / 10);
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << revNum(n) << '\n';
}
```

**Задача 8**

```cpp
bool find(const char* str, char symbol)
{
    if (*str == '\0')   //if we reached the end of the string
        return false;   //we didnt find it

    if (*str == symbol) //we found it
        return true;

    find(str + 1, symbol);  //continue searching
}
```

**Задача 9**

```cpp
bool areEqual(const char* str1, const char* str2)
{
    if (*str1 == '\0' && *str2 == '\0')     //if both end at the same time
        return true;
    if (
        (*str1 == '\0' && *str2 != '\0')    //if str1 ended and str2 not
        || (*str1 != '\0' && *str2 == '\0') //or str2 ended and str1 not
        || (*str1 != *str2)                 //or 2 chars at the same position are not equal
        )
        return false;
    return areEqual(str1 + 1, str2 + 1);
}
```

**Задача 10**  
Тук въвеждаме концепцията за помощна функция. Честа практика е, когато за рекурсивното решение ни трябва допълнителен параметър,
да си направим помощна функция (с този параметър), която да извикваме веднъж в основната функция. Това е с цел да не променяме сигнатурата на крайната функция, за да може използването и да е интуитивно. (ще е странно ако функция isPalindrome, която казва дали 1 низ е палиндром или не приема 2 низа като параметри)  
```cpp
bool isPalindromeHelper(const char* str1, const char* str2)
{
    if (str1 >= str2)
        return true;

    if (*str1 != *str2)
        return false;

    return isPalindromeHelper(str1 + 1, str2 - 1);
}

bool isPalindrome(const char* str)
{
    return isPalindromeHelper(str, str + strLen(str) - 1);
}
```