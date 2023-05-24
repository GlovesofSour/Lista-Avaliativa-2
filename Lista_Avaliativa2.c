#include <stdio.h>
#include <string.h>
#define TAM_PROFESSOR 3
#define TAM_DISCIPLINA 2
#define TAM_ESTUDANTE 15

typedef struct{
    char nome[50];
    char funcional[30];
    char titulacao[15];
}Professor;

typedef struct{
    char nome[50];
    int codigo;
    int carga_horaria;
    Professor professor;
}Disciplina;

typedef struct{
    char nome[50];
    char matricula[30];
    int idade;
    Disciplina disciplina;
}Estudante;

int le_valida_idade();
void bubbleSort(Estudante estudantes[], Estudante aux, int num_estudantes);
void bubbleSort_decrescente(Estudante alunos[], Estudante aux, int num_alunos);
void imprime_relatorio(Estudante alunos[], int num_alunos, Disciplina disciplina[], int a);

int main(){

    Professor professores[TAM_PROFESSOR];
    Disciplina disciplinas[TAM_DISCIPLINA];
    Estudante estudantes[TAM_ESTUDANTE], aux;

    int i=0, acao=0, qtd_alunos=0, materia1=0, materia2=0;

    printf("----------------------------------------\n\tCadastro Professor\n");

    for(i=0;i<TAM_PROFESSOR;i++){
        printf("----------------------------------------\n=> Professor %d\n", i+1);
        printf("\nNome: ");
        scanf(" %[^\n]s", &professores[i].nome);
        printf("Funcional: ");
        scanf(" %[^\n]s", &professores[i].funcional);
        
        do{
            acao =0;
            printf("Titulacao\n");
            printf("\t1 - Especialista\n\t2 - Mestre\n\t3 - Doutor\n\n>");
            scanf("%d", &acao);
        }while(acao < 1 || acao > 3);

        switch (acao){
        case 1 :
            strcpy(professores[i].titulacao, "Especialista");
            break;
        case 2 :
            strcpy(professores[i].titulacao, "Mestre");
            break;
        case 3 :
            strcpy(professores[i].titulacao, "Doutor");
            break;
        }
        
    }

    printf("\n\n----------------------------------------\n\tCadastro Disciplina\n");

    for(i=0;i<TAM_DISCIPLINA;i++){
        printf("----------------------------------------\n=> Disciplina %d\n", i+1);
        printf("\nNome: ");
        scanf(" %[^\n]s", &disciplinas[i].nome);
        printf("Codigo: ");
        scanf("%d", &disciplinas[i].codigo);
        printf("Carga Horaria: ");
        scanf("%d", &disciplinas[i].carga_horaria);
        
        do{
            printf("Professor Responsavel\n");
            printf("\t1 - %s\n\t2 - %s\n\t3 - %s\n\n>", professores[0].nome, professores[1].nome, professores[2].nome);
            scanf("%d", &acao);
        }while(acao < 1 || acao > 3);
        
        switch (acao){
        case 1 :
            disciplinas[i].professor = professores[0];
            break;
        case 2 :
            disciplinas[i].professor = professores[1];
            break;
        case 3 :
            disciplinas[i].professor = professores[2];
            break;
        }
                
    }

    printf("\n\n----------------------------------------\n\tCadastro Estudante\n");
    i=0;
    do{
        printf("----------------------------------------\n=> Estudante %d\n", i+1);
        printf("\n\nNome: ");
        scanf(" %[^\n]s", &estudantes[i].nome);
        estudantes[i].idade = le_valida_idade();
        printf("Matricula: ");
        scanf(" %[^\n]s", &estudantes[i].matricula);

        do{ 
            if(materia1<10 && materia2<10){ 
                printf("Disciplina\n");
                printf("\t1 - %s\n\t2 - %s\n", disciplinas[0].nome, disciplinas[1].nome);  
                printf("Escolha: ");
                scanf("%d", &acao);
            }else{
                if (materia1==10){
                    do{
                        printf("Disciplina\n");
                        printf("\t2 - %s\n\n>", disciplinas[1].nome);
                        scanf("%d", &acao);
                    }while(acao != 2);
                }
                if (materia2==10){
                    do{
                        printf("Disciplina\n");
                        printf("\t1 - %s\n\n", disciplinas[0].nome);
                        scanf("%d", &acao);
                    }while(acao != 1);
                }
            }
        }while(acao < 1 && acao > 2);

        switch (acao){
        case 1:
            estudantes[i].disciplina = disciplinas[0];
            materia1++;
            break;
        case 2:
            estudantes[i].disciplina = disciplinas[1];
            materia2++;
            break;
        }

        do{
            printf("Deseja continuar cadastrando\n");
            printf("\t1 - Sim\n\t2 - Nao\n\n>");
            scanf("%d", &acao);
        }while(acao < 1 || acao > 2);
        qtd_alunos++;
        i++;
    }while(acao != 2 && qtd_alunos != TAM_ESTUDANTE);

    printf("\n-------------------------------------------------------------------------------------\nRelatorio de Alunos na Disciplina: %s\n-------------------------------------------------------------------------------------\n", disciplinas[0].nome);
    bubbleSort(estudantes, aux, qtd_alunos);
    imprime_relatorio(estudantes, qtd_alunos, disciplinas, 0);
    printf("-------------------------------------------------------------------------------------");

    printf("\n-------------------------------------------------------------------------------------\nRelatorio de Alunos na Disciplina: %s\n-------------------------------------------------------------------------------------\n",disciplinas[1].nome);
    bubbleSort_decrescente(estudantes, aux, qtd_alunos);
    imprime_relatorio(estudantes, qtd_alunos, disciplinas, 1);
    printf("-------------------------------------------------------------------------------------");


    return 0;
}

int le_valida_idade() {
    int idade;
    do {
        printf("Idade (16-26): ");
        scanf("%d", &idade);
    } while (idade < 16 || idade > 26);
    return idade;
}

void bubbleSort(Estudante alunos[], Estudante aux, int num_alunos) {
    for (int i = 0; i < num_alunos - 1; i++) {
        for (int j = 0; j < num_alunos - i - 1; j++) {
            if (alunos[j].idade > alunos[j + 1].idade) {
                aux = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = aux;
            }
        }
    }
}

void bubbleSort_decrescente(Estudante alunos[], Estudante aux, int num_alunos) {
    for (int i = 0; i < num_alunos - 1; i++) {
        for (int j = 0; j < num_alunos - i - 1; j++) {
            if (alunos[j].idade < alunos[j + 1].idade) {
                aux = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = aux;
            }
        }
    }
}

void imprime_relatorio(Estudante alunos[], int num_alunos, Disciplina disciplina[], int a){
    int i=0;

    for(i=0;i<num_alunos;i++){
        if(strcmp(alunos[i].disciplina.nome, disciplina[a].nome) == 0){
            printf("Codigo da Disciplina: %d\tProfessor: %s\t Estudante: %s\t Idade: %d\n", alunos[i].disciplina.codigo, alunos[i].disciplina.professor.nome, alunos[i].nome, alunos[i].idade);
        }
    }
}