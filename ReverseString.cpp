// Reverse a given string.

#include <stdio.h>
#include <string.h>

void ReverseWord(char* str, int start, int end);

void ReverseString(char* str, int size)
{
	int start, end;

	end = size - 1;
	start = 0;

	for (int i = 0; i < size; i++)
	{
		if (str[i] == ' ' && i > 0) {
			ReverseWord(str, start, i - 1);
			start = i + 1;
		}
		else if (i == size - 1) {
			ReverseWord(str, start, size - 1);
		}
	}

	ReverseWord(str, 0, size - 1);
}

int main()
{
	char str[] = "The world is good";
	ReverseString(str, sizeof(str)-1);
	printf("%s\n", str);
	return 0;
}

void ReverseWord(char* str, int start, int end)
{
	char temp;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
