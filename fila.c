#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

typedef struct{
    int RA;
    char nome_arquivo[10];
    char extensao_arquivo[5];
    char matricula[10];
}talunos;

talunos fila[5];
int tamanho;

void inserir(){
    int continuar;
    do{
        printf("\n\t\t\t-----INSERIR-ELEMENTOS-----\n\n");
        if(tamanho < 5){
           printf("\n\t\t\tRA do aluno...: ");
           scanf("%d", &fila[tamanho].RA);
           printf("\n\t\t\tNome do arquivo...: ");
           fflush(stdin);
           gets(fila[tamanho].nome_arquivo);
           printf("\n\t\t\tExtensao do arquivo...: ");
           fflush(stdin);
           gets(fila[tamanho].extensao_arquivo);
           printf("\n\t\t\tMatricula do Professor...: ");
           gets(fila[tamanho].matricula);
           tamanho++;
           printf("\n\n\t\t\tInserido com sucesso\n\n");
        }
        else
        {
            printf("\n\n\t\t\tFila lotada! \n\n");
            getche();
            break;
        }
        printf("\t\t\tContinuar inserindo? 1 - SIM | 2 - NAO...:");
        scanf("%d",&continuar);
    }while(continuar == 1);
}


void remover(){
    int i, confRemo, continuar;
    do{
        printf("\n\t\t\tREMOVER ELEMENTOS DA FILA\n");
        if(tamanho != 0){
            printf("\n\n\t\t\tRA    Nome Arquivo    Extensao    Matricula Prof(a)\n");
            printf("\t\t\t-----------------------------------------------\n");
            printf("\t\t\t%3d      %-15s   %-10s    %-15s\n", fila[0].RA, fila[0].nome_arquivo, fila[0].extensao_arquivo, fila[0].matricula);
            printf("\t\t\t-----------------------------------------------\n");
            printf("\t\t\tConfirmar remocao do aluno? 1 - SIM | 2 - NAO...:");
            scanf("%d",&confRemo);
            if(confRemo == 1){
                printf("\n");
                printf("\t\t\t%3d      %-15s   %-10s    %-15s\n", fila[0].RA, fila[0].nome_arquivo, fila[0].extensao_arquivo, fila[0].matricula);
                printf("\n");
                for(i=0; i<tamanho; i++)
                    fila[i] = fila[i+1];
                tamanho--;
                printf("\t\t\tRemovido da fila com sucesso\n\n");
            }
            else
            {
                printf("\n\n\t\t\tCancelado pelo usuario!\n\n");
            }
        }
        else
        {
            printf("\t\t\tFila vazia - Sem alunos para remocao\n");
            getche();
            break;
        }
        printf("\t\t\t\Deseja remover outro aluno? 1 - SIM | 2 - NAO...:");
        scanf("%d",&continuar);
    }while(continuar == 1);

}
void esvaziar(){
    printf("\n\t\t\tESVAZIAR FILA\n");
    int i, resposta;
    printf("\n\t\t\tDeseja esvaziar a fila? 1 - SIM | 2 - NAO...:\n");
    scanf("%d",&resposta);
    if(tamanho != 0){
        if(resposta == 1){
            for(i=0; i<tamanho; i++){
                    fila[i] = fila[i+1];
                    tamanho--;
            }
            for(i=0; i<tamanho; i++){
                    fila[i] = fila[i+1];
                    tamanho--;
            }
            for(i=0; i<tamanho; i++){
                    fila[i] = fila[i+1];
                    tamanho--;
            }
                printf("\t\t\tFila esvaziada com sucesso\n\n");
        }
        else{
                if(resposta == 2){
                    printf("\t\t\tCancelado pelo usuario\n\n");
                }
                else{
                    if((resposta != 1)&&(resposta != 2)){
                        printf("\t\t\tOpcao Invalida\n\n");
                    }
                }
        }
    }
    else
    {
        printf("\t\t\tFila vazia - Sem alunos para remocao\n");
        getche();
    }
}
void imprimir(){
    int i;
    if(tamanho != 0){
        printf("\n\n\t\t\tDados da fila\n\n");
        printf("\n\n\t\t\tRA    Nome Arquivo    Extensao    Matricula Prof(a)\n");
        printf("\t\t\t-----------------------------------------------\n");
        for(i=0; i<tamanho; i++)
            printf("\t\t\t%3d      %-15s   %-10s    %-15s\n", fila[i].RA, fila[i].nome_arquivo, fila[i].extensao_arquivo, fila[i].matricula);
        printf("\t\t\t-----------------------------------------------\n");
        printf("\n\n\t\t\tQuantidade de alunos na fila = %d\n\N.",tamanho);
    }
    else
         {
            printf("\n.");
         }
}
void sair(){
    printf("\t\t\tPressione qualquer tecla pra sair...\n");
}
int main(){
    int opcao;
    int tamanho = 0;
    do
    {
        imprimir();
        printf("\n\t\t\t-------------MENU------------\n\n");
        printf("\t\t\t1 - Inserir Elemento na Fila\n");
        printf("\t\t\t2 - Remover Elemento da Fila\n");
        printf("\t\t\t3 - Esvaziar Fila\n");
        printf("\t\t\t0 - Encerrar o Programa\n");
        scanf("%d", &opcao);
        fflush(stdin);
        switch(opcao){
            case 1:
                system("cls");
                inserir();
                system("pause");
                break;
            case 2:
                system("cls");
                remover();
                system("pause");
                break;
            case 3:
                system("cls");
                esvaziar();
                system("pause");
                break;
            case 0:
                system("cls");
                sair();
                break;
            default:
                printf("\t\t\tErro: Opcao Invalida!\n");

        }
    }while(opcao!=0);
}


