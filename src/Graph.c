/*
 * Graph Data Structure */
#include <stdio.h>
#include <malloc.h>

#include "Graph.h"

AdjNode_t *newNode(int dest)
{
    AdjNode_t *node = NULL;
    node = (AdjNode_t *)calloc(1, sizeof(AdjNode_t));
    node->dest = dest;
    node->next = NULL;
    return node;
}

Graph_t *createGraph(int v, int e)
{
    Graph_t *graph = NULL;
    graph = (Graph_t *)calloc(1, sizeof(Graph_t));
    graph->V = v;
    graph->E = e;
    graph->List = calloc(v, sizeof(AdjList_t));
    graph->Visited = calloc(v, sizeof(bool));
    return graph;
}

void insertEdge(Graph_t *graph, int u, int v, int wieght)
{
    AdjNode_t *node1, *node2;

    if (graph == NULL)
        return;

    node1 = newNode(v);
    node2 = newNode(u);

    node1->next = graph->List[u].head;
    graph->List[u].head = node1;

    node2->next = graph->List[v].head;
    graph->List[v].head = node2;
}

void printGraph(Graph_t *graph)
{
    int i;

    if (graph == NULL)
        return;

    for (i = 0; i < graph->V; i++)
    {
        AdjNode_t *nodeptr = graph->List[i].head;
        printf("Adj List of vertex %d -> ", i);
        while (nodeptr) {
            printf("%d -> ", nodeptr->dest);
            nodeptr = nodeptr->next;
        }
        printf("NULL\n");
    }
}

void dfs_traversal(Graph_t *graph, int src)
{
    AdjNode_t *nodeptr = graph->List[src].head;
    graph->Visited[src] = true;
    printf("Node visited %d\n", src);

    while (nodeptr) {
        if ( graph->Visited[nodeptr->dest] != true ) {
            dfs_traversal(graph, nodeptr->dest);
        }
        nodeptr = nodeptr->next;
    }
}
