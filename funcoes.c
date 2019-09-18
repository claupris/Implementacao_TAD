#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#include "funcoes.h"


hogwarts *hogCreate(int max) {
    hogwarts *h;
    if(max>0) {
        h = (hogwarts*)malloc(sizeof(hogwarts));
        if (h!= NULL) {
            h-> alunos(void**)malloc(sizeof(void)*n);
            if(h->alunos!=NULL) {
                h-> maxAlunos = max;
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
            h->aln[h->nAlunos] = aln;
            h->nAlunos ++;
            return TRUE;
        }
    }
    return FALSE;
}

void * hogwartsQuest(hogwarts *h, void key, int(*cmp)(void*, void*)) {
    int i = 0;
    if(h!= NULL) {
        if(h->nAlunos>0) {
            while(cmp(h->alunos[i],key)!=TRUE && i < h->nAlunos) {
                i++
            }
            if (cmp(h->alunos[i], key)== TRUE) {
                return h->alunos[i];
            }
        }
    }
    return NULL;
}

void * hogKickOut(hogwarts *h, void key, int(*cmp)(void*, void*)) {
    int i = 0;
    void * aux;
    if(h!= NULL) {
        if(h->nAlunos>0) {
            while(cmp(h->alunos[i],key)!=TRUE && i < h->nAlunos) {
                i++
            }
            if (cmp(h->alunos[i], key)== TRUE) {
                aux = h->alunos[i];
                for (i = key, i < h->nAlunos-1; i++) {
                    h->alunos[i] = h->alunos[i+1];
                }
                h->nAlunos --;
                return aux;
            }
        }
    }
    return NULL;
}
