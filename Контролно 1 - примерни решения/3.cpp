#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1)
            {
                if (j % 2 == 0)
                    std::cout << '*';
                else
                    std::cout << ' ';
            }
            else if (j == n - 1 || j == 0)
            {
                if (i % 2 == 0)
                    std::cout << '*';
                else
                    std::cout << ' ';
            }
            else if (i == n / 2 && j == n / 2)
                std::cout << '0';
            else if (j == i)
                std::cout << '+';
            else if (n - i - 1 == j)
                std::cout << '-';
            else
                std::cout << ' ';
        }
        std::cout << '\n';
    }
}