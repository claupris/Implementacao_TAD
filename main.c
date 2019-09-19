#include <stdio.h>
#include <stdlib.h>
#include "alunos.h"


int main(int argc, char ** argv) {
    int control;
    int op;
    int maxVagas;
    hogwarts *h = NULL;


    do {
        printf("*********************************************************\n");
        printf("BEM VINDO A ESCOLA DE MAGIA E BRUXARIA DE HOGWARTS!!!\n");
        printf("*********************************************************\n");
        printf("*********\tEscolha uma opcao:\t**********\n");
        printf("1 - Criar uma turma em HOGWARTS\n");
        printf("2 - Matricular um novo aluno\n");
        printf("3 - Buscar um aluno já matriculado\n");
        printf("4 - EXPULSAR  um aluno indisciplinado\n");
        printf("5 - Listar todos os alunos matriculados\n");
        printf("6 - Remover a turma de HOGWARTS\n");
        printf("7 - Sair\n");
        printf("*********\tEscolha uma opcao:\t**********\n");
        scanf("%d",&op);

        switch(op){
        case 1:
            printf("digite o máximo de vagas a ter nessa nova turma");
            scanf("%d", &maxVagas);
            while(maxVagas<=0){
                printf("Valor inválido!!!\nPor favor digite uma quantidade MAIOR que ZERO");
                scanf("%d", &maxVagas);
            }
            h = hogCreate(maxVagas);
            system("PAUSE");
            break;
        case 2:
            insertAluno(h);
            break;
        case 3:
            break;
        }

    } while(control!=7);

    return 0;
}
