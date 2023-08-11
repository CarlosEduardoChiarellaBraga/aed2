#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    int i,k;
    int peso, choose;
    int vert, arest;
    vert = 1000;
    arest = 1200;
    choose = 30;
    int alt1,alt2;
    int vet[vert];
    srand( time(0) );
    for(i=0; i<vert; i++){
        vet[i] = i+1;
    } 
    printf("%d %d\n",vert,arest);
    for(k=0; k<arest; k++){
        peso = rand() % choose;
        alt1 = rand() %vert;
        alt2 = rand() %vert;
        printf("%d %d %d",alt1,alt2,peso);
        printf("\n");
    }
    return 0;
}
