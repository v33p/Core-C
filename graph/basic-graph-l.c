#include <stdio.h>
#include <stdlib.h>

#define Vertex int

struct node { 
  Vertex v; 
  struct node* next; 
};
typedef struct node* link;

struct digraph {
  int V; 
  int A; 
  link* adj; 
};
typedef struct digraph* Digraph;

struct graph {
  int V; 
  int E; 
  link* adj; 
};
typedef struct graph* Graph;

link newNode (Vertex v, link next) { 
  link x = malloc (sizeof (*x));
  x->v = v; 
  x->next = next;     
  return x;
}

Digraph initDigraph (int V) { 
  Vertex v;
  Digraph G = malloc(sizeof (*G));
  G->V = V; 
  G->A = 0;
  G->adj = malloc(V * sizeof (link));
  for (v = 0; v < V; v++) 
    G->adj[v] = NULL;
  return G;
}

void insertArcDigraph (Digraph G, Vertex v, Vertex w) { 
  link p;
  if (v == w) return;
  for (p = G->adj[v]; p != NULL; p = p->next) 
    if (p->v == w) return;
  G->adj[v] = newNode (w, G->adj[v]);
  G->A++;
}

Graph initGraph (int V) { 
  Vertex v;
  Graph G = malloc(sizeof (*G));
  G->V = V; 
  G->E = 0;
  G->adj = malloc(V * sizeof (link));
   for (v = 0; v < V; v++) 
     G->adj[v] = NULL;
   return G;
}

void insertEdgeGraph (Graph G, Vertex v, Vertex w) { 
  link p;
  if (v == w) return;
  for (p = G->adj[v]; p != NULL; p = p->next) 
    if (p->v == w) return;
  G->adj[v] = newNode (w, G->adj[v]);
  G->adj[w] = newNode (v, G->adj[w]);
  G->E++;
}

/*
void removeEdgeGraph (Graph G, Vertex v, Vertex w) {
	link p;
	for (p = G->adj[v]; p != NULL; p = p->next) {
		if (p->v == w) {
			G->E--;
		}
	}
}*/

void printDigraph (Digraph G) {
  Vertex v, w;
  link p;
  for (v = 0; v < G->V; v++) {
    printf ("%2d:", v);
    for (p = G->adj[v]; p != NULL; p = p->next)
      printf(" %2d", G->adj[v]->v);
    printf ("\n");
  }
}

void printGraph (Graph G) {
  Vertex v, w;
  link p;
  for (v = 0; v < G->V; v++) {
    printf ("%2d:", v);
    for (p = G->adj[v]; p != NULL; p = p->next)
      printf(" %2d", G->adj[v]->v);
    printf ("\n");
  }
}
