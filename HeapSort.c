/*
 * Heapsort
 * comparison based sorting algorithm
 * complete binary tree
 * using MAX heap
 * O(nlogn)
 *
 */

#include <stdio.h>

#include "HeapSort.h"

#define MAX_ELE 20

static void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

static void heapify(int *arr, int n, int i)
{
  int largest = i;
  int lt = 2 * i + 1;
  int rt = 2 * i + 2;

  if (lt < n && arr[lt] > arr[largest])
    largest = lt;

  if (rt < n && arr[rt] > arr[largest])
    largest = rt;

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapsort(int *arr, int n)
{
  int i, j;
  for (i = n/2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (j = n - 1; j >= 0; j--) {
    swap(&arr[0], &arr[j]);
    heapify(arr, j, 0);
  }
}

int main ()
{
  int array[] = {-2, 0, -9, 45, 11, 4, 10};
  int n = sizeof(array)/sizeof(array[0]), i;

  printf("\n");

  for (i = 0; i < n; i++)
    printf("%d ", array[i]);

  printf("\n");

  heapsort(array, n);
  for (i = 0; i < n; i++)
    printf("%d ", array[i]);

  printf("\n");

  return 0;
}
