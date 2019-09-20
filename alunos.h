
//#include "funcoes.h"

typedef struct _ALUNO_{
        char matricula[6];
        char nome[30];
        int anoCurso;
        float altura;
        int idade;
}aluno;

int cmpMatAluno(void *a, void *b); // compara a matricula do aluno //

int cmpNomeAluno(void *a, void *b); // compara o nome do aluno //
