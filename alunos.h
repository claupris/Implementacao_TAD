#include "funcoes.h"

typedef struct _ALUNO_{
        char matricula[6];
        char nome[30];
        int anoCurso;
        float altura;
        int idade;
}aluno;

int cmpMatAluno(void *a, void *b); // compara a matricula do aluno //

int cmpNomeAluno(void *a, void *b); // compara o nome do aluno //

int searchMatricula(hogwarts *h); // procura o aluno pela matrícula //

int searchName(hogwarts *h); // procura o aluno pelo nome //

int removeViaMat(hogwarts *h); // remove pela matrícula //

int removeViaName(hogwarts *h); // remove pelo nome //

int insertAluno(hogwarts *h); // insere o aluno na escola //

int listaAlunos(hogwarts *h); // lista todos os alunos da escola //

int freeAll(hogwarts *h); // libera todos os alunos da escola //
