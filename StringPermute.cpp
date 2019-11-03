// String permutaion "ABC"

#include <stdio.h>

void swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void permute(char* str, int l, int r)
{
	if (l == r)
	{
		printf("%s\n", str);
		return;
	}

	for (int i = l; i <= r; i++)
	{
		swap(&str[l], &str[i]);

		permute(str, l + 1, r);

		swap(&str[l], &str[i]);
	}
}

int main()
{
	char str[] = { "ABC" };
	permute(str, 0, 2);
	return 0;
}

