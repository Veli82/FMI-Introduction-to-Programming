#include <iostream>

int strLen(const char* str)
{
    int length = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    
    return length;
}

char* strCopy(const char* src)
{
    char* copy = new char[strLen(src) + 1] {};

    for (int i = 0; src[i] != '\0'; i++)
    {
        copy[i] = src[i];
    }

    return copy;
}

int findPatternStart(const char* str, const char* pattern)
{
    int patternStartIdx = -1;
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        bool wasFound = true;

        if (str[i] == pattern[0])
        {
            patternStartIdx = i;

            for (int j = 1; pattern[j] != '\0'; j++)
            {
                if (str[i + j] != pattern[j])
                {
                    wasFound = false;

                    break;
                }
            }
            
            if (wasFound)
            {
                return patternStartIdx;
            }
        }
    }

    return -1;
}

void censorWord(char* strAt, const char* pattern)
{
    for (int i = 0; pattern[i] != '\0'; i++)
    {
        strAt[i] = '*';
    }
}

void censorWordsInString(char* str, char** badWords, int badWordCount)
{
    for (int i = 0; i < badWordCount; i++)
    {
        int wordStartIndex = findPatternStart(str, badWords[i]);

        if (wordStartIndex != -1)
        {
            censorWord(str + wordStartIndex, badWords[i]);
        } 
    } 
}

int main()
{
    char buffer[100];
    std::cin >> buffer;

    char* strToRedact = strCopy(buffer);

    int badWordCount;
    std::cin >> badWordCount;

    char** badWords = new char*[badWordCount];
    
    for (int i = 0; i < badWordCount; i++)
    {
        std::cin >> buffer;

        badWords[i] = strCopy(buffer);
    }

    censorWordsInString(strToRedact, badWords, badWordCount);

    std::cout << strToRedact;

    delete[] strToRedact;

    for (int i = 0; i < badWordCount; i++)
    {
        delete[] badWords[i];
    }
    
    delete[] badWords;
}