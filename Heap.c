/*
 * MAX HEAP DATA STRUCTURE in Ca
 *
 */

#include <stdio.h>
#include <malloc.h>

typedef struct {
	int data;
} heapNode;

typedef struct {
	int size;
	int count;
	heapNode *elem;
} heap_t;

#define PARENT(x) (x - 1) / 2
#define LCHILD(x) (2 * x + 1)
#define RCHILD(x) (2 * x + 2)


heap_t max_heap;

void init_heap (int size)
{
  max_heap.size = size;
  max_heap.elem = (heapNode *) calloc (size, sizeof(heapNode));
  return;
}

static void swap (heapNode *n1, heapNode *n2)
{
  heapNode temp = *n1;

  *n1 = *n2;
  *n2 = temp;
}

static void heapify (int i)
{
  int largest = i;

  if (LCHILD(i) < max_heap.size && max_heap.elem[LCHILD(i)].data >
      max_heap.elem[largest].data)
    largest = LCHILD(i);

  if (RCHILD(i) < max_heap.size && max_heap.elem[RCHILD(i)].data >
      max_heap.elem[largest].data)
    largest = RCHILD(i);

  if (largest != i)
  {
    swap (&(max_heap.elem[i]), &(max_heap.elem[largest]));
    heapify (largest);
  }
}

void create_max_heap (int *elem, int size)
{
  int i;

  for (i = 0; i < size; i++)
  {
    max_heap.elem[i].data = elem[i];
  }

  for (i = (max_heap.size - 1)/2; i >= 0; i--)
    heapify (i);
}

void insert_node (int data)
{
  int i = max_heap.size++;

  while (i && data > max_heap.elem[PARENT(i)].data)
  {
    max_heap.elem[i] = max_heap.elem[PARENT(i)];
    i = PARENT(i);
  }
  max_heap.elem[i].data = data;
}

void delete_node(void)
{
  printf("Deleteing node = %d\n", max_heap.elem[0].data);
  max_heap.elem[0].data = max_heap.elem[max_heap.size - 1].data;
  max_heap.size -= 1;
  heapify (0);
}

void display_heap(void)
{
  int i;

  for (i = 0; i < max_heap.size; i++)
    printf("%d  ", max_heap.elem[i].data);
  printf("\n");
}
