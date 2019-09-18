#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
  Pessoa *auxB;

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
        aux_A = (aluno *)hogwartsQuest(h, (void *)aux_mat, cmpNomeAluno);
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
        aux_A = (aluno *)hogKickOut(h, (void *)aux_mat, cmpNomeAluno);
        if (aux_A != NULL){
            printf("================================================================================\n");
            printf("O aluno cujo o nome é %s foi EXPULSO de HOGWARTS!!! Que pena T_T\n", aux_nome);
            printf("================================================================================\n");
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
