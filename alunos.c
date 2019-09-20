#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#include "funcoes.h"
#include "alunos.h"
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

int cmpMatAluno(void *a, void *b) {
    char *auxA;
    aluno *auxB;

    auxA = (char *)a;
    auxB = (aluno *)b;

    if (strcmp(auxA, auxB->matricula) == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int cmpNomeAluno(void *a, void *b) {
    char *auxA;
    aluno *auxB;

    auxA = (char *)a;
    auxB = (aluno *)b;

    if (strcmp(auxA, auxB->nome) == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int searchMatricula(hogwarts *h) {

    if(h!=NULL && h->nAlunos > 0) {

        char aux_mat[6];
        aluno * aux_A;

        printf("Informe a matricula do aluno a ser buscada: ");
        scanf("%[^\n]s", aux_mat);

        aux_A = (aluno *) hogwartsQuest(h, (void *)aux_mat, cmpMatAluno);

        if (aux_A != NULL) {
            printf("**************INFORMACOES**************\n");
            printf("Nome: %s\n", aux_A->nome);
            printf("Matricula de %s: %s\n", aux_A->nome, aux_A->matricula);
            printf("Idade de %s: %d\n", aux_A->nome, aux_A->idade);
            printf("O ano letivo de %s: %d\n", aux_A->nome, aux_A->anoCurso);
            printf("A altura de %s: %.2f\n", aux_A->nome, aux_A->altura);
            printf("***************************************\n");

            getchar();

            return TRUE;
        } else {
            printf("Matricula = %s na escola de magia e bruxaria de HOGWARTS nao encontrada!!\n", aux_mat);

            getchar();

            return FALSE;
        }
    }
    printf("HOGWARTS AINDA ESTA SEM ALUNOS!!!\n");
    getchar();
    return FALSE;
}


int searchName(hogwarts *h) {
    char aux_nome[30];
    aluno *aux_A;

    if(h!=NULL && h->nAlunos>0) {
        printf("Informe o nome do aluno a ser buscado: ");
        fflush(stdin);
        scanf("%[^\n]s", aux_nome);
        fflush(stdin);
        aux_A = (aluno *)hogwartsQuest(h, (void *)aux_nome, cmpNomeAluno);
        if (aux_A != NULL) {
            printf("**************INFORMACOES**************\n");
            printf("Nome: %s\n", aux_A->nome);
            printf("Matricula de %s: %s\n", aux_A->nome, aux_A->matricula);
            printf("Idade de %s: %d\n", aux_A->nome, aux_A->idade);
            printf("Ano letivo de %s: %d\n", aux_A->nome, aux_A->anoCurso);
            printf("Altura %s: %.2f\n", aux_A->nome, aux_A->altura);
            printf("***************************************\n");
            getchar();
            return TRUE;
        } else {
            printf("Aluno %s nao encontrado na escola de magia e bruxaria de HOGWARTS\n", aux_nome);
            getchar();
            return FALSE;
        }
    }
    printf("HOGWARTS AINDA ESTA SEM ALUNOS!!!\n");
    getchar();
    return FALSE;
}


int removeViaMat(hogwarts *h) {
    char aux_mat[6];
    aluno *aux_A;
    if(h!=NULL && h->nAlunos>0) {
        printf("Informe a matricula do aluno a ser buscada: ");
        fflush(stdin);
        scanf("%[^\n]s", (aux_mat));
        fflush(stdin);
        aux_A = (aluno *)hogKickOut(h, (void *)aux_mat, cmpMatAluno);
        if (aux_A != NULL) {
            printf("*******************************************************************************\n");
            printf("O aluno com a matricula = %s foi encontrada e EXPULSO de HOGWARTS!!! Que pena T_T\n", aux_mat);
            printf("*******************************************************************************\n");
            getchar();
            return TRUE;
        } else {
            printf("Matricula = %s nao encontrada em HOGWARTS!! Que sorte!\n", aux_mat);
            getchar();
            return FALSE;
        }
    }
    printf("HOGWARTS AINDA ESTA SEM ALUNOS!!!\n");
    return FALSE;
}

int removeViaName(hogwarts *h) {
    char aux_nome[30];
    aluno *aux_A;
    if(h!=NULL && h->nAlunos>0) {
        printf("Informe o nome do aluno a ser buscado: ");
        fflush(stdin);
        scanf("%s", aux_nome);
        fflush(stdin);
        aux_A = (aluno *)hogKickOut(h, (void *)aux_nome, cmpNomeAluno);
        if (aux_A != NULL) {
            printf("*******************************************************************************\n");
            printf("O aluno cujo o nome e %s foi EXPULSO de HOGWARTS!!! Que pena T_T\n", aux_nome);
            printf("*******************************************************************************\n");
            getchar();
            return TRUE;
        } else {
            printf("O aluno cujo o nome e %s nao foi encontrado em HOGWARTS!! Que sorte!\n", aux_nome);
            getchar();
            return FALSE;
        }
    }
    printf("HOGWARTS AINDA ESTA SEM ALUNOS!!!\n");
    return FALSE;
}

int insertAluno(hogwarts *h) {
    if(h!=NULL) {
        if (h->nAlunos < h->maxAlunos) {
            aluno *a = (aluno *) malloc(sizeof(aluno));
            if (a != NULL) {
                printf("Informe o nome do aluno: \n");
                scanf("%s", (a->nome));
                getchar();
                system(CLEAR);
                printf("Informe a matricula do aluno: \n");
                scanf("%s", (a->matricula));
                getchar();
                system(CLEAR);
                printf("Informe a altura do aluno %s: \n", a->nome);
                scanf("%f", &(a->altura));
                system(CLEAR);
                printf("Informe o ano em que da escola o aluno %s deve entrar: \n", a->nome);
                scanf("%d", &(a->anoCurso));
                system(CLEAR);
                printf("Informe a idade do aluno %s: \n", a->nome);
                scanf("%d", &(a->idade));
                system(CLEAR);
                hogwartsNewAluno(h, (void *)a);

                getchar();

                return TRUE;

            }
        }
        printf("SALA CHEIA!!!\n\n");
        getchar();
    }
    printf("Infelismente a escola de magia e bruxaria de HOGWARTS nao existe para esse aluno!!!\n");
    getchar();
    return FALSE;
}

int listaAlunos(hogwarts *h) {
    int i;
    if(h!=NULL) {
        if(h->nAlunos>0) {
            printf("***\tALUNOS CONTEMPLADOS COM A CARTA E MATRICULADOS EM HOGWARTS\t***\n");
            for(i=0; i<h->nAlunos; i++) {
                aluno *aux = (aluno*)h->alunos[i];
                printf("****************************\n");
                printf("Nome: %s\n", aux->nome);
                printf("A matricula de %s: %s\n", aux->nome, aux->matricula);
                printf("Idade de %s: %d\n", aux->nome, aux->idade);
                printf("ano letivo de %s: %d\n", aux->nome, aux->anoCurso);
                printf("A altura de %s: %.2f\n", aux->nome, aux->altura);
                printf("****************************\n");

            }
            printf("***\tALUNOS CONTEMPLADOS COM A CARTA E MATRICULADOS EM HOGWARTS\t***\n");
            getchar();
            return TRUE;
        } else {
            printf("****************************\n");
            printf("HOGWARTS AINDA ESTA SEM ALUNOS!!!\n");
            printf("****************************\n");
            getchar();
        }
    }
    return FALSE;
}

int freeAll(hogwarts *h) {
    int i;
    if(h!=NULL) {
        if(h->nAlunos>0) {
            for(i=0; i<h->nAlunos; i++) {
                free(h->alunos[i]);
            }
            h->nAlunos = 0;
            printf("ALUNOS EXPULSOS COM SUCESSO!!!\n");
            int dbool = hogDestroy(h);
            if(dbool) {
                printf("TURMA RETIRADA COM SUCESSO!!\n");
            }
            getchar();
            return TRUE;
        }
        printf("A ESCOLA AINDA NÃO TINHA ALUNOS PARA EXPULSAR ALGUEM!!!\n");
        int dbool = hogDestroy(h);
        if(dbool) {
            printf("TURMA RETIRADA COM SUCESSO!!\n");
        }
        getchar();
        return FALSE;
    }
    return FALSE;
}
