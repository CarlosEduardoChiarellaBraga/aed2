#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 70

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
#define I 8
#define J 9
#define K 10
#define L 11
#define M 12

void adicionarAresta(int graph[][MAX_NODES], int src, int dest) {
    graph[src][dest] = 1;
}

void printGraph(int graph[][MAX_NODES], int numNodes){
    int i, j, temp;
    for(i=0;i<numNodes;i++){
        printf("%d: ", i);
        for(j=0;j<numNodes;j++){
            if(graph[i][j]!=0) printf("%d ", j);
        }
        printf("\n");
    }
}

void topologicalSort(int graph[][MAX_NODES], int numNodes) {
    int grau_entrada[numNodes], i, j, node;
    for (i = 0; i < numNodes; ++i) {
        grau_entrada[i] = 0;
        for (j = 0; j < numNodes; ++j) {
            grau_entrada[i] += graph[j][i];
        }
    }

    for (i = 0; i < numNodes; ++i) {
        printf("%d: %d, ", i, grau_entrada[i]);
    }
    printf("\n\n\n\n");
    printGraph(graph, numNodes);
    printf("\n\n\n\n");

    for(i = 0; i < numNodes; i++) { 
        node = -1;
        for (j = 0; j < numNodes; j++) {
            if (grau_entrada[j] == 0) {
                node = j; 
                grau_entrada[j] = -1;
                break;
            }
        }
        if (node == -1) {
            //grafo ciclico, pois nenhum grau de entrada é 0
            printf("GRAFO CICLICO\n");
            return;
        }
        printf("%d ", node);


        //Todos os adjacentes do node terao seus graus de entrada reduzidos
        for (int j = 0; j < numNodes; j++) {
            if (graph[node][j] == 1) {
                grau_entrada[j]--;
            }
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {0};
    int numNodes = 15;
    
    adicionarAresta(graph, A, D);
    adicionarAresta(graph, B, D);
    adicionarAresta(graph, C, A);
    adicionarAresta(graph, C, B);
    adicionarAresta(graph, D, H);
    adicionarAresta(graph, D, G);
    adicionarAresta(graph, E, A);
    adicionarAresta(graph, E, D);
    adicionarAresta(graph, E, F);
    adicionarAresta(graph, G, I);
    adicionarAresta(graph, H, J);
    adicionarAresta(graph, H, I);
    adicionarAresta(graph, I, L);
    adicionarAresta(graph, J, M);
    adicionarAresta(graph, K, J);
    
    topologicalSort(graph, numNodes);

    return 0;
}
