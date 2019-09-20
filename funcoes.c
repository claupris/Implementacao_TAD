#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#include "funcoes.h"


hogwarts *hogCreate(int maximo) {
    hogwarts *h;
    if(maximo>0) {
        h = (hogwarts*)malloc(sizeof(hogwarts));
        if (h!= NULL) {
            h->alunos = (void**)malloc(sizeof(void*)*maximo);
            if(h->alunos!=NULL) {
                h-> maxAlunos = maximo;
                h->nAlunos = 0;
                return h;
            }
        }
    }
    return NULL;
}

int hogDestroy(hogwarts *h) {
    if (h != NULL) {
        if(h ->nAlunos==0) {
            free(h ->alunos);
            free(h);
            return TRUE;
        }
    }
    return FALSE;
}

int hogwartsNewAluno(hogwarts *h, void * aln) {
    if (h!=NULL) {
        if(h->nAlunos < h->maxAlunos) {
            h->alunos[h->nAlunos] = aln;
            h->nAlunos ++;
            return TRUE;
        }
    }
    return FALSE;
}

void * hogwartsQuest(hogwarts *h, void *key, int(*cmp)(void*, void*)) {
    int i = 0;
    if(h!= NULL) {
        if(h->nAlunos>0) {
            while(i < h->nAlunos && cmp(key, h->alunos[i])!=TRUE) {
                ++i;
            }
            if (i < h->nAlunos && cmp(key, h->alunos[i])== TRUE) {
                return h->alunos[i];
            }
        }
    }
    return NULL;
}

void * hogKickOut(hogwarts *h, void *key, int(*cmp)(void*, void*)) {
    int i = 0;
    void * aux;
    if(h!= NULL) {
        if(h->nAlunos>0) {
            while(i < h->nAlunos && cmp(key, h->alunos[i])!=TRUE ){
                i++;
            }
            if (i < h->nAlunos && cmp(key, h->alunos[i])== TRUE) {
                aux = h->alunos[i];
                for (; i < h->nAlunos-1; i++) {
                    h->alunos[i] = h->alunos[i+1];
                }
                h->nAlunos --;
                return aux;
            }
        }
    }
    return NULL;
}
