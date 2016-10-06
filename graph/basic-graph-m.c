#include <stdio.h>
#include <stdlib.h>

#define Vertex int

struct digraph {
  int V; 
  int A; 
  int** adj; 
};
typedef struct digraph *Digraph;

struct graph {
  int V; 
  int E; 
  int** adj; 
};
typedef struct graph *Graph;

int** initMatrix (int r, int c, int val) { 
  Vertex i, j;
  int **m = malloc(r * sizeof (int *));
  for (i = 0; i < r; i++)
    m[i] = malloc(c * sizeof (int));
  for (i = 0; i < r; i++)
    for (j = 0; j < c; j++)
      m[i][j] = val;
  return m;
}

Digraph initDigraph (int V) { 
  Digraph G = malloc (sizeof (*G));
  G->V = V; 
  G->A = 0;
  G->adj = initMatrix (V, V, 0);
  return G;
}

void insertArcDigraph (Digraph G, Vertex v, Vertex w) { 
  if (v != w && G->adj[v][w] == 0) {
    G->adj[v][w] = 1; 
    G->A++;
  }
}

void removeArcDigraph (Digraph G, Vertex v, Vertex w) { 
  if (G->adj[v][w] == 1) {
    G->adj[v][w] = 0; 
    G->A--;
  }
}

void printDigraph (Digraph G) { 
  Vertex v, w; 
  for (v = 0; v < G->V; v++) {
    printf("%2d:", v);
    for (w = 0; w < G->V; w++)
      if (G->adj[v][w] == 1) 
	printf(" %2d", w);
    printf("\n");
  }
}

Graph initGraph (int V) { 
  Graph G = malloc(sizeof (*G));
  G->V = V;
  G->E = 0;
  G->adj = initMatrix (V, V, 0);
   return G;
}

void insertEdgeGraph (Graph G, Vertex v, Vertex w) { 
  if (v != w && G->adj[v][w] == 0) {
    G->adj[v][w] = 1; 
    G->adj[w][v] = 1; 
    G->E++;
  }
}

void removeEdgeGraph (Graph G, Vertex v, Vertex w) {
   if (G->adj[v][w] == 1 && G->adj[w][v] = 1) {
	G->adj[v][w] = 0;
	G->adj[w][v] = 0;
	G->E--;
   }
}
