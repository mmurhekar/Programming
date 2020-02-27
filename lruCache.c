// Implement the LRU (Least Recently Used) Cache Memory

#include <stdio.h>
#include <malloc.h>

// Link List Node
typedef struct Node {
   int PageNumber;
   struct Node *next, *prev;
} Node;

// Queue
typedef struct Queue {
   int NumbetOframes;
   int Count;
   struct Node *front, *rear;
} Queue;

// Hash Map
typedef struct HashMap {
   int NumberOfPages;
   struct Node **Array;
} HashMap;

struct Node *CreateNode( int PageNumber )
{
   struct Node *qnode;

   qnode = (Node *) malloc(sizeof(struct Node));
   qnode->PageNumber = PageNumber;
   qnode->next = qnode->prev = NULL;

   return qnode;
}

struct Queue *CreateQueue( int NumbetOframes )
{
   struct Queue *queue;

   queue = (Queue *) malloc(sizeof(struct Queue));
   queue->NumbetOframes = NumbetOframes;
   queue->Count = 0;
   queue->front = queue->rear = NULL;

   return queue;
}

struct HashMap *CreateHashMap( int NumberOfPages )
{
   struct HashMap *hashmap;

   hashmap = (HashMap *) malloc(sizeof(struct HashMap));
   hashmap->NumberOfPages = NumberOfPages;
   hashmap->Array = (Node **) malloc( NumberOfPages * sizeof(struct Node*));

   for (int i = 0; i < NumberOfPages; i++)
      hashmap->Array[i] = NULL;

   return hashmap;
}

int IsQueueEmpty( Queue *queue )
{
   if ( queue && queue->rear == NULL )
      return 1;

   return 0;
}

int IsQueueFull( Queue *queue )
{
   if ( queue->Count == queue->NumbetOframes )
      return 1;

   return 0;
}

void Dequeue( Queue *queue )
{
   if ( IsQueueEmpty( queue ) )
      return;

   if ( queue->front == queue->rear )
      queue->front = NULL;

   Node *temp = queue->rear;
   queue->rear = queue->rear->prev;

   if ( queue->rear )
      queue->rear->next = NULL;

   free(temp);

   queue->Count--;
}

void Enqueue( Queue *queue, HashMap *hashmap, int PageNumber )
{
   if ( IsQueueFull( queue ) )
   {
      hashmap->Array[queue->rear->PageNumber] = NULL;
      Dequeue( queue );
   }

   Node *node = CreateNode( PageNumber );

   if ( queue->front )
   {
      queue->front->prev = node;
      node->next = queue->front;
      queue->front = node;
   }
   else
   {
      queue->front = queue->rear = node;
   }

   hashmap->Array[node->PageNumber] = node;
   queue->Count++;
}

void ProcessCacheMemory( Queue *queue, HashMap *hashmap, int PageNumber )
{
   Node *temp = hashmap->Array[ PageNumber ];

   if ( temp == NULL )
   {
      // Add new Frame to the Cache
      Enqueue( queue, hashmap, PageNumber );
      return;
   }

   if ( temp != queue->front )
   {
      // Put this Page to the front
      temp->prev->next = temp->next;
      if ( temp->next )
         temp->next->prev = temp->prev;

      if ( queue->rear == temp )
      {
         queue->rear = temp->prev;
         queue->rear->next = NULL;
      }

      temp->next = queue->front;
      temp->prev = NULL;
      temp->next->prev = temp;

      queue->front = temp;
   }
}

int main(int argc, char const *argv[])
{
   /* code */
   Queue *queue = CreateQueue( 4 );

   HashMap *hashmap = CreateHashMap( 10 );

   ProcessCacheMemory( queue, hashmap, 1 );
   ProcessCacheMemory( queue, hashmap, 2 );
   ProcessCacheMemory( queue, hashmap, 3 );
   ProcessCacheMemory( queue, hashmap, 1 );
   ProcessCacheMemory( queue, hashmap, 4 );
   ProcessCacheMemory( queue, hashmap, 5 );
   ProcessCacheMemory( queue, hashmap, 6 );

   printf("%d ", queue->front->PageNumber);
   printf("%d ", queue->front->next->PageNumber);
   printf("%d ", queue->front->next->next->PageNumber);
   printf("%d ", queue->front->next->next->next->PageNumber);

   return 0;
}
