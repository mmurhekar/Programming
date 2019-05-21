/*
 * Graph Data Structures
 * Graph Traversal & Algorithms */

#ifndef __GRAPH__
#define __GRAPH__
#include <stdbool.h>

typedef struct AdjNode_t {
    int dest;
    int wieght;
    struct AdjNode_t *next;
} AdjNode_t;

typedef struct {
    struct AdjNode_t *head;
} AdjList_t;

typedef struct {
    int V;
    int E;
    AdjList_t *List;
    bool *Visited;
} Graph_t;

Graph_t *createGraph(int v, int e);
void insertEdge(Graph_t *graph, int u, int v, int wieght);
void printGraph(Graph_t *graph);
void dfs_traversal(Graph_t *graph, int src);

#endif /* __GRAPH__ */
