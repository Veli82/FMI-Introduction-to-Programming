#include <iostream>

bool isPowOf(int n, int k)
{
    if (n == 1)
    {
        return true;
    } 
    
    if (n % k != 0)
    {
        return false;
    }

    return isPowOf(n / k, k);
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    
    std::cout << std::boolalpha << isPowOf(n, k);
}