#include <iostream>

void transformText(char word[50], int key)
{
    for(int i = 0; word[i] != '\0'; i++)
    {
        word[i] += key;
    }
}

void print(char word[50])
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        std::cout << word[i];
    } 
}

int main()
{
    char word[50];
    std::cin >> word;

    char command;
    std::cin >> command;

    int key;
    std::cin >> key;

    if (command == 'e')
    {
        transformText(word, key);
    }
    else if (command == 'd')
    {
        transformText(word, -key);
    }

    print(word);
}