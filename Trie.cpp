#include <stdio.h>
#include <malloc.h>

/**
 * @input A : String termination by '\0'
 * @input B : array of strings termination by '\0'
 * @input n2 : number of strings in array B
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

#define ALPHA 26

typedef struct node_t {
	struct node_t* child[ALPHA];
	int eow;
	int count;
} node_t;

void InsertWord(node_t* trie, char* str)
{
	int i, index;
	for (i = 0; str[i] != '\0'; i++)
	{
		index = str[i] - 'a';
		if (trie->child[index] == NULL)
		{
			trie->child[index] = (node_t*)calloc(1, sizeof(node_t));
		}

		trie = trie->child[index];
	}

	if (trie) {
		trie->eow = 1;
		trie->count++;
	}
}

int SearchWord(node_t* trie, char* str)
{
	int i, index;
	for (i = 0; str[i] != '\0'; i++)
	{
		index = str[i] - 'a';
		if (trie->child[index] == NULL)
			return 0;
		trie = trie->child[index];
	}

	if (trie->eow)
		return trie->count;

	return 0;
}

int* solve(char* A, char B[][100], int n2, int* len1)
{
	node_t trie;
	int i, j;
	int* goodness = (int *)calloc(n2, sizeof(int));
	for (int i = 0; i < ALPHA; i++)
		trie.child[i] = NULL;

	char* start = A;
	i = 0;

	// Insert Words
	while (A[i] != '\0')
	{
		if (A[i] == '_') {
		A[i] = '\0';
		InsertWord(&trie, start);
		A[i] = '_';
		start = &A[i] + sizeof(char);
		}
		i++;
	}
	// Insert last word
	InsertWord(&trie, start);

	for (i = 0; i < n2; i++)
	{
		char* str = B[i];
		start = str;
		j = 0;
		while (str[j] != '\0')
		{
			if (str[j] == '_') {
				str[j] = '\0';
				if (SearchWord(&trie, start))
					goodness[i]++;
				str[j] = '_';
				start = &str[j] + sizeof(char);
				
			}
		}
	}


	return NULL;
}
#if 0
int main()
{
	char s[] = "cool_ice_wifi";
	char arr[][100] = {
		"water_is_cool",
		"cold_ice_drink",
		"cool_wifi_speed"
		};

	int len = 3;
	solve(s, arr, 3, &len);

	return 0;
}
#endif