typedef struct _hogwarts{
    int nAlunos;
    int maxAlunos;
    void ** alunos;
}hogwarts;

hogwarts *hogCreate(int max) //cria a escola de magia e brixaria de HOGWARTS //

int hogDestroy(hogwarts *h,) // destroi HOGWARTS //

int hogwartsNewAluno(hogwarts *h, void * aln) // um jovem recebe a carta para adentrar a HOGWARTS //

void * hogwartsQuest(hogwarts *h, void key, int(*cmp)(void*, void*)) // procura um bruxo que estua em HOGWARTS //

void * hogKickOut(hogwarts *h, void key, int(*cmp)(void*, void*)) // expulsa um bruxo de HOGWARTS //
