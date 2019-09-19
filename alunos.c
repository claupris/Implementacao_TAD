#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#include "alunos.h"

int cmpMatAluno(void *a, void *b){
  char *auxA;
  aluno *auxB;

  auxA = (char *)a;
  auxB = (aluno *)b;

  if (strcmp(auxA, auxB->matricula) == 0){
    return TRUE;
  }
  else {
    return FALSE;
  }
}

int cmpNomeAluno(void *a, void *b){
  char *auxA;
  aluno *auxB;

  auxA = (char *)a;
  auxB = (aluno *)b;

  if (strcmp(auxA, auxB->nome) == 0){
    return TRUE;
  }
  else {
    return FALSE;
  }
}

int searchMatricula(hogwarts *h){

    char aux_mat[6];
    aluno *aux_A;
    if(h!=NULL && h->nAlunos>0){
        printf("Informe a matricula do aluno a ser buscada: ");
        fflush(stdin);
        scanf("%[^\n]s", &aux_mat);
        fflush(stdin);
        aux_A = (aluno *)hogwartsQuest(h, (void *)aux_mat, cmpMatAluno);
        if (aux_A != NULL){
            printf("**************INFORMACOES**************\n");
            printf("Nome: %s\n", aux_A->nome);
            printf("Matricula de %s: %s\n", aux_A->nome, aux_A->matricula);
            printf("Idade de %s: %d\n", aux_A->nome, aux_A->idade);
            printf("O ano letivo de %s: %d\n", aux_A->nome, aux_A->anoCurso);
            printf("A altura de %s: %.2f\n", aux_A->nome, aux_A->altura);
            printf("***************************************\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("Matricula = %s escola de magia e bruxaria de HOGWARTS\n", aux_mat);
            system("PAUSE");
            return FALSE;
        }
    }
    printf("HOGWARTS AINDA ESTA SEM ALUNOS!!!\n");
    system("PAUSE");
    return FALSE;
}


int searchName(hogwarts *h){
    char aux_nome[30];
    aluno *aux_A;

    if(h!=NULL && h->nAlunos>0) {
        printf("Informe o nome do aluno a ser buscado: ");
        fflush(stdin);
        scanf("%[^\n]s", &aux_nome);
        fflush(stdin);
        aux_A = (aluno *)hogwartsQuest(h, (void *)aux_nome, cmpNomeAluno);
        if (aux_A != NULL){
            printf("**************INFORMACOES**************\n");
            printf("Nome: %s\n", aux_A->nome);
            printf("Matricula de %s: %s\n", aux_A->nome, aux_A->matricula);
            printf("Idade de %s: %d\n", aux_A->nome, aux_A->idade);
            printf("Ano letivo de %s: %d\n", aux_A->nome, aux_A->anoCurso);
            printf("Altura %s: %.2f\n", aux_A->nome, aux_A->altura);
            printf("***************************************\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("Aluno %s nao encontrado na escola de magia e bruxaria de HOGWARTS\n", aux_nome);
            system("PAUSE");
            return FALSE;
        }
    }
    printf("HOGWARTS AINDA ESTA SEM ALUNOS!!!\n");
    system("PAUSE");
    return FALSE;
}


int removeViaMat(hogwarts *h){
    char aux_mat[6];
    aluno *aux_A;
    if(h!=NULL && h->nAlunos>0){
        printf("Informe a matricula do aluno a ser buscada: ");
        fflush(stdin);
        scanf("%[^\n]s", &(aux_mat));
        fflush(stdin);
        aux_A = (aluno *)hogKickOut(h, (void *)aux_mat, cmpMatAluno);
        if (aux_A != NULL){
            printf("**********************************************************************************\n");
            printf("O aluno com a matricula = %s foi encontrada e EXPULSO de HOGWARTS!!! Que pena T_T\n", aux_mat);
            printf("**********************************************************************************\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("Matricula = %s nao encontrada em HOGWARTS!! Que sorte!\n", aux_mat);
            system("PAUSE");
            return FALSE;
        }
    }
    printf("HOGWARTS AINDA ESTA SEM ALUNOS!!!\n");
    return FALSE;
}

int removeViaName(hogwarts *h){
    char aux_nome[30];
    aluno *aux_A;
    if(h!=NULL && h->nAlunos>0){
        printf("Informe o nome do aluno a ser buscado: ");
        fflush(stdin);
        scanf("%[^\n]s", &(aux_nome));
        fflush(stdin);
        aux_A = (aluno *)hogKickOut(h, (void *)aux_nome, cmpNomeAluno);
        if (aux_A != NULL){
            printf("**********************************************************************************\n");
            printf("O aluno cujo o nome é %s foi EXPULSO de HOGWARTS!!! Que pena T_T\n", aux_nome);
            printf("**********************************************************************************\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("O aluno cujo o nome é %s nao foi encontrado em HOGWARTS!! Que sorte!\n", aux_nome);
            system("PAUSE");
            return FALSE;
        }
    }
    printf("HOGWARTS AINDA ESTA SEM ALUNOS!!!\n");
    return FALSE;
}

int insertAluno(hogwarts *h){
    if(h!=NULL) {
        aluno *a = (aluno *) malloc(sizeof(aluno));
        if (a != NULL) {
            printf("Informe o nome do aluno: ");
            fflush(stdin);
            scanf("%[^\n]s", (a->nome));
            fflush(stdin);
            printf("Informe a matricula do aluno: ");
            fflush(stdin);
            scanf("%[^\n]s", (a->matricula));
            fflush(stdin);
            printf("Informe a altura do aluno %s: ", a->nome);
            scanf("%lf", &(a->altura));
            printf("Informe o ano em que da escola o aluno %s deve entrar: ", a->nome);
            scanf("%d", &(a->anoCurso));
            printf("Informe a idade do aluno %s: ", a->nome);
            scanf("%d", &(a->idade));
            hogwartsNewAluno(h, (void *)a);
            system("PAUSE");
            return TRUE;
        }
    }
    printf("Infelismente a escola de magia e bruxaria de HOGWARTS nao existe para esse aluno!!!\n");
    system("PAUSE");
    return FALSE;
}

int listaAlunos(hogwarts *h){
    int i;
    if(h!=NULL) {
        if(h->nAlunos>0){
            printf("***\ALUNOS CONTEMPLADOS COM A CARTA E MATRICULADOS EM HOGWARTS\t***\n");
            for(i=0;i<h->nAlunos; i++){
                aluno *aux = (aluno*)h->alunos[i];
                printf("****************************\n");
                printf("Nome: %s\n", aux->nome);
                printf("A matricula de %s: %s\n", aux->nome, aux->matricula);
                printf("Idade de %s: %d\n", aux->nome, aux->idade);
                printf("ano letivo de %s: %d\n", aux->nome, aux->anoCurso);
                printf("A altura de %s: %.2f\n", aux->nome, aux->altura);
                printf("****************************\n");

            }
            printf("***\ALUNOS CONTEMPLADOS COM A CARTA E MATRICULADOS EM HOGWARTS\t***\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("****************************\n");
            printf("HOGWARTS AINDA ESTÁ SEM ALUNOS!!!\n");
            printf("****************************\n");
            system("PAUSE");
        }
    }
    return FALSE;
}

int freeAll(hogwarts *h){
    int i;
    if(h!=NULL) {
        if(h->nAlunos>0){
            for(i=0;i<h->nAlunos;i++){
                free(h->alunos[i]);
            }
            h->nAlunos = 0;
            printf("ALUNOS EXPULSOS COM SUCESSO!!!\n");
            system("PAUSE");
            return TRUE;
        }
        printf("A ESCOLA AINDA NÃO TINHA ALUNOS PARA EXPULSAR ALGUEM!!!\n");
        system("PAUSE");
        return FALSE;
    }
    return FALSE;
}
