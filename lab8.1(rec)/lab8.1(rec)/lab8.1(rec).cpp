// lab8.1(rec).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Квецко Вікторії
//Варіант 32

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int CountIncludes(char* str, char* letters, int count = 0, const int index = 0);
char* Change(char* str, const char* fromPart, const char* toPart);

void ReplaceIncludes(
	char* str, char* tempPoint, char* temp,
	const char* fromPart, const char* toPart,
	const int len, const int lenFromPart, const int lenToPart,
	size_t index = 0
);
int getIncludesIndex(char* findIn, const char* part, const int index);
int getPartIndex(
	char* str, const char* part,
	const int strIndex, const int partIndex = 0
);

bool IncludeLetter(char* findIn, char letter, const int index = 0);


int main()
{
	char str[101];

	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	char letters[] = "BASIC";

	cout << endl;

	cout << "String contained " << CountIncludes(str, letters)
		<< " letters of word: " << letters << endl << endl;

	char* dest = new char[151];
	dest = Change(str, "BASIC", "Delphi");

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}

#pragma region mainFunctions
int CountIncludes(char* str, char* letters, int count, const int index)
{
	if (IncludeLetter(letters, str[index]))
		count++;

	if (str[index + 1] != '\0')
		return CountIncludes(str, letters, count, index + 1);

	return count;
}

char* Change(char* str, const char* fromPart, const char* toPart)
{
	size_t len = strlen(str);
	size_t lenFromPart = strlen(fromPart);
	size_t lenToPart = strlen(toPart);

	char* temp = new char[len * (lenToPart - 1) / (lenFromPart - 1) + 1];
	temp[0] = '\0';

	ReplaceIncludes(str, temp, temp, fromPart, toPart, len, lenFromPart, lenToPart);

	return temp;
}
#pragma endregion

#pragma region subFunctions
void ReplaceIncludes(
	char* str, char* tempPoint, char* temp,
	const char* fromPart, const char* toPart,
	const int len, const int lenFromPart, const int lenToPart,
	size_t index
) {
	if (getIncludesIndex(str, fromPart, index) == index)
	{
		strcat(tempPoint, toPart);

		tempPoint += lenToPart;
		index += lenFromPart;
	}
	else
	{
		*tempPoint++ = str[index++];
		*tempPoint = '\0';
	}

	if (index + 1 < len && str[index + (lenFromPart - lenToPart)] != 0) {
		ReplaceIncludes(
			str, tempPoint, temp,
			fromPart, toPart,
			len, lenFromPart, lenToPart,
			index
		);
	}
	else
	{
		*tempPoint++ = str[index++];
		*tempPoint++ = str[index++];
		*tempPoint = '\0';
	}
}

int getIncludesIndex(char* findIn, const char* part, const int index)
{
	if (part[getPartIndex(findIn, part, index)] == '\0')
		return index;

	if (findIn[index] != '\0')
		return getIncludesIndex(findIn, part, index + 1);

	return -1;
}

int getPartIndex(
	char* str, const char* part,
	const int strIndex, const int partIndex
)
{
	if (str[strIndex] == part[partIndex] && str[strIndex] != '\0')
		return getPartIndex(str, part, strIndex + 1, partIndex + 1);

	return partIndex;
}

bool IncludeLetter(char* findIn, char letter, const int index)
{
	if (findIn[index] == letter)
		return true;

	if (findIn[index] != '\0')
		return IncludeLetter(findIn, letter, index + 1);

	return false;
}
#pragma endregion
