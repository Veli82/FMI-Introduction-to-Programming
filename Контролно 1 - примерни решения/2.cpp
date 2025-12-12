#include <iostream>

bool task2(char str1[100], char str2[100])
{
	char smallLetterCount[26]{};
	char capLetterCount[26]{};
	int starCount = 0;

	for (int i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			int index = str1[i] - 'a';
			smallLetterCount[index]++;
		}
		else if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			int index = str1[i] - 'A';
			capLetterCount[index]++;
		}
		else if (str1[i] == '*')
			starCount++;
	}

	for (int i = 0; str2[i] != '\0'; i++)
	{
		if (str2[i] >= 'a' && str2[i] <= 'z')
		{
			int index = str2[i] - 'a';
			smallLetterCount[index]--;
			if (smallLetterCount[index] < 0)
				return false;
		}
		else if (str2[i] >= 'A' && str2[i] <= 'Z')
		{
			int index = str2[i] - 'A';
			capLetterCount[index]--;
			if (capLetterCount[index] < 0)
				return false;
		}
		else if (str2[i] == '*')
		{
			starCount--;
			if (starCount < 0)
				return false;
		}

	}
	return true;
}

int main()
{
    char str1[100];
    char str2[100];

    std::cin >> str1;
    std::cin >> str2;

    std::cout << std::boolalpha << task2(str1,str2);
}