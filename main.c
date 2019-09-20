#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "alunos.h"

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void clear_keyboard_buffer(void)
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}

int main(int argc, char * argv[]) {
    int control;
    int op;
    int busca;
    int rem;
    int maxVagas;
    hogwarts *h = NULL;


    do {

        system(CLEAR);
        printf("*********************************************************\n");
        printf("BEM VINDO A ESCOLA DE MAGIA E BRUXARIA DE HOGWARTS!!!\n\n");

        printf("*********\tEscolha uma opcao:\t**********\n");
        printf("1 - Criar uma turma em HOGWARTS\n");
        printf("2 - Matricular um novo aluno\n");
        printf("3 - Buscar um aluno já matriculado\n");
        printf("4 - EXPULSAR  um aluno indisciplinado\n");
        printf("5 - Listar todos os alunos matriculados\n");
        printf("6 - Remover a turma de HOGWARTS\n");
        printf("0 - Sair\n");
        printf("*********\tEscolha uma opcao:\t**********\n");
        scanf("%d",&op);
        clear_keyboard_buffer();
        /*if(h!=NULL) {
            printf("Quantidade de alunos já matriculados em HOGWARTS: %d\n", h->nAlunos);
            printf("Quantidade maxima de alunos a matriculados em HOGWARTS: %d\n\n", h->maxAlunos);
        } else {
            printf("A turma ainda não foi criada!!!\n");
        }*/

        switch(op) {
            case 1:{
                printf("digite o máximo de vagas a ter nessa nova turma\n");
                scanf("%d", &maxVagas);
                clear_keyboard_buffer();
                while(maxVagas<=0) {
                    printf("Valor inválido!!!\nPor favor digite uma quantidade MAIOR que ZERO");
                    scanf("%d", &maxVagas);
                    clear_keyboard_buffer();
                }
                h = hogCreate(maxVagas);
                //getchar();
                break;
            }
            case 2:{
                insertAluno(h);
                break;
            }
            case 3:{
                printf("1 - buscar por matricula\n");
                printf("2 - buscar por nome\n");
                scanf("%d", &busca);
                clear_keyboard_buffer();
                switch(busca) {
                    case 1: {
                        searchMatricula(h);
                        break;
                    }
                    case 2: {
                        searchName(h);
                        break;
                    }
                    default:{
                        break;
                    }
                }
                getchar();
                break;
            }
            case 4:{
                printf("1 - EXPULSAR via matricula\n");
                printf("2 - EXPULSAR via nome\n");
                scanf("%d", &rem);
                clear_keyboard_buffer();
                switch(rem) {
                    case 1:{
                        removeViaMat(h);
                        getchar();
                        break;
                    }
                    case 2:{
                        removeViaName(h);
                        getchar();
                        break;
                    }
                    default:{
                        break;
                    }
                }
                break;
            }
            case 5:{
                listaAlunos(h);
                getchar();
                break;
            }
            case 6:{
                freeAll(h);
                getchar();
                break;
            }
            case 0:{
                control = -1;
                break;
            }
            default:{
                break;
            }
        }
    } while(control==0);

    return 0;
}
