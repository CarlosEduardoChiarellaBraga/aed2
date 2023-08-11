#include <stdio.h>
#include <stdlib.h>

//Estrutura para o Union-Find, armzenando o pai e o valor da ares
struct Subset {
    int parent;
    int rank;
};

//Representação de uma aresta no Grafo
struct Edge {
    int From, To, weight;
};

struct Subset* subsets; 
struct Edge* edges;      

// Criação e alocação do grafo
struct Edge* createGraph(int E) {
    struct Edge* graph = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Função usada para localizar um vértice
int Find(int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = Find(subsets[i].parent);
    return subsets[i].parent;
}

/*Função que realiza a conexão de dois vértices,
usada para evitar ciclos
*/ 
void Union(int x, int y) {
    int root1 = Find(x);
    int root2 = Find(y);

    if (subsets[root1].rank < subsets[root2].rank)
        subsets[root1].parent = root2;
    else if (subsets[root1].rank > subsets[root2].rank)
        subsets[root2].parent = root1;
    else {
        subsets[root2].parent = root1;
        subsets[root1].rank++;
    }
}

// Comparação de arestas determinando a de menor e maior valor
int compareEdges(const void* x, const void* y) {
    return ((struct Edge*)x)->weight - ((struct Edge*)y)->weight;
}

/*Kruskal's algorithm
1-Ordena as arestas de forma que uma nunca seja menor que a passada
2- aloca a memória
3- processa cada aresta
4- verifica se a inclusão da aresta gera um ciclo,
se não, seu peso é somado a mst.
@int mst: contador da arvore geradora minima 
*/ 
void kruskal(int V, int E) {
    int mstWeight = 0; 
    int i;
    int x, y;
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    for (i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    for (i = 0; i < E; ++i) {
        x = Find(edges[i].From);
        y = Find(edges[i].To);
        if (x != y) {
            printf("Aresta %d-%d de peso: %d incluida na MST\n",
                   edges[i].From, edges[i].To, edges[i].weight);
            mstWeight += edges[i].weight;
            Union(x, y);
        }
    }

    printf("Weight of MST: %d\n", mstWeight);
}

int main() {
    int V, E;
    printf("Numero de vertices de arestas: ");
    scanf("%d%d", &V, &E);
    printf("\n");

    subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    edges = createGraph(E);

    for (int i = 0; i < E; ++i) {
        scanf("%d%d%d", &edges[i].From, &edges[i].To, &edges[i].weight);
    }

    kruskal(V, E);

    free(subsets);
    free(edges);

    return 0;
}
