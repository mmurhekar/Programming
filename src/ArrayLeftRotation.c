#include <stdio.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7};

void LeftRotate(int *arr, int size, int d)
{
  int mod;

  mod = d % n;
  for (i = 0; i < size - 1; i++)
    printf("%d ", arr[(mod+i)%n];
}

int main(int argc, char const *argv[]) {

  int i;
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Array := ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  LeftRotate(arr, n);
  LeftRotate(arr, n);

  printf("Array := ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
