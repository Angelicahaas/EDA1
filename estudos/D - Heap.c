#include <stdio.h>


typedef int item;

typedef struct {
    int tam;
    item *v;
} Heap;

Heap *Heap_new(int capacidade) {
    Heap* newHeap = malloc(sizeof(Heap));
    newHeap->v = malloc(sizeof(item) * capacidade);
    newHeap->tam = 0 + 1;       ///0 + 1 pq a primeira posição vai começar em 1
}


 //forma recurssiva
void fixUp(Heap *h, int i) {
    if (i <= 1) {
        return                  //verificando se i não é a raiz
    }

    int pai = i / 2;
    if (h->v[pai] < h->v[i]) {
       //exch(h->v[i/2] ,h->v[i]);
       item tmp = h->v[i];
       h->v[pai] = h->v[i];
       h->v[i] = tmp;
       fixUp(h, pai);      
    }
     
}

// forma interativa
//void fixUpInterativo(Heap* h, int i) {
//   while (i > 1 && h->v[i/2] < h->v[i]) { 
//       //exch(h->v[i/2] ,h->v[i]);
//     item tmp = h->v[i / 2];
//     h->v[i / 2] = h->v[i];
//     h->v[i] = tmp;
       
//     i = i / 2;      
// }
 

//}

void insertion(Heap *h, item *i) {
    h->v[h->tam + 1] = i;
    h->tam++;
    fixUp(h, h->tam);

}

//verifica se tá vazia
int isEmpty(Heap *h) {
    return h->tam == 0;
}

//verifica a raiz
item top(Heap *h) {
    return h->v[1];
}

void fixDown(Heap *h, int i) {

    int filho;
    while (i=2 <= h->tam)
    {
        filho = i * 2;
        if (filho == h->tam && h->v[filho] < h->v[filho + 1]) {
            filho++;
        }
        if (h->v[i] < h->v[filho]) {
            item tmp = h->v[filho];
            h->v[filho] = h->v[i];
            h->v[i] = tmp;  

            i = filho;
             
        } else {
        break;
        }
    } 
}

//remove o item da fila e faz fixdowm pra organizar
void pop (Heap *h){
    // exch (root, last)
    item tmp = h->v[i];
    h->v[i] = h->v[h->tam];
    h->v[h->tam] = tmp;  
    h->tam--;

    fixDown(h, 1);

}
