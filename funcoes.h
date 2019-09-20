

typedef struct _HOGWARTS_{
    int nAlunos;
    int maxAlunos;
    void ** alunos;
} hogwarts;


hogwarts *hogCreate(int maximo); //cria a escola de magia e brixaria de HOGWARTS //

int hogDestroy(hogwarts *h); // destroi HOGWARTS //

int hogwartsNewAluno(hogwarts *h, void * aln); // um jovem recebe a carta para adentrar a HOGWARTS //

void * hogwartsQuest(hogwarts *h, void *key, int(*cmp)(void*, void*)); // procura um bruxo que estua em HOGWARTS //

void * hogKickOut(hogwarts *h, void *key, int(*cmp)(void*, void*)); // expulsa um bruxo de HOGWARTS //

int searchMatricula(hogwarts *h); // procura o aluno pela matrícula //

int searchName(hogwarts *h); // procura o aluno pelo nome //

int removeViaMat(hogwarts *h); // remove pela matrícula //

int removeViaName(hogwarts *h); // remove pelo nome //

int insertAluno(hogwarts *h); // insere o aluno na escola //

int listaAlunos(hogwarts *h); // lista todos os alunos da escola //

int freeAll(hogwarts *h); // libera todos os alunos da escola //
