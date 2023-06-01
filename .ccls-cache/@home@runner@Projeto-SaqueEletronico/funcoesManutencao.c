#include <stdio.h>
#include <string.h>
#include "estrutura.h"
#include "catalogo.h"
//Funções do switch case 1,2,3,4

void maxCedula() //Função para definir a qntd max de cédulas
{
    printf("Defina a quantidade de notas!\n");
                for(int i=0;i<7;i++){
                    if(tipoCedulas[i].disponivel==1){
                        printf("R$%d: ",tipoCedulas[i].cedulas);
                        scanf("%d", &tipoCedulas[i].maxQntCedulas);
                    }
                }
}
void reporTudo() //Função para repor a qntd de todas as cédulas
{
    for(int i=0;i<7;i++){
        if(tipoCedulas[i].disponivel==1) //Necessario para mostrar apenas cédulas habilitadas
            tipoCedulas[i].quantidadeCedulas=tipoCedulas[i].maxQntCedulas;
    }
    printf("\nAs cédulas foram depósitadas!\n");
}
void reporIndividual() //Função para repor individualmente a qntd de cédula
{
    int opcaoCedula;
    for(int i=0;i<7;i++){ //Não gosto dessa opção
        if(tipoCedulas[i].disponivel==1){ //Necessario para mostrar apenas cédulas habilitadas
            printf("\nA quantidade máxima da cédula de R$%d é: %d\n",tipoCedulas[i].cedulas, tipoCedulas[i].maxQntCedulas);
            printf("Restam %d notas no caixa!\nGostaria de repor as cédulas faltantes?\n\n", tipoCedulas[i].quantidadeCedulas);
            printf("(1)Sim\t(0)Não\n\nEscolha uma opção: ");
            scanf("%d", &opcaoCedula);
            if(opcaoCedula)
                tipoCedulas[i].quantidadeCedulas=tipoCedulas[i].maxQntCedulas;
        }
    }
}
void opcaoAddCedula() //Função para adicionar um tipo de cédula
{
    int opcaoCedula;
    char notaUtilizada[7][30];
    for(int i=0;i<7;i++){
        if(tipoCedulas[i].disponivel==1) //Necessario para mostrar apenas cédulas habilitadas
            strcpy(notaUtilizada[i], " - Utilizado");
        else
            strcpy(notaUtilizada[i], " - Não Utilizado");
    }
    printf("Qual o valor da cédula que gostaria de adicionar?\n");
    printf("(1)R$2%s\n", notaUtilizada[0]);
    printf("(2)R$5%s\n", notaUtilizada[1]);
    printf("(3)R$10%s\n", notaUtilizada[2]);
    printf("(4)R$20%s\n", notaUtilizada[3]);
    printf("(5)R$50%s\n", notaUtilizada[4]);
    printf("(6)R$100%s\n", notaUtilizada[5]);
    printf("(7)R$200%s\n", notaUtilizada[6]);
    printf("Escolha uma opção: ");
    scanf("%d", &opcaoCedula);
    switch(opcaoCedula){
        case 1:
            tipoCedulas[0].disponivel=1; //criar 7 cases habilitando a disponibilidade da celula tipoCedulas[i].disponivel
            break;                      
        case 2:
            tipoCedulas[1].disponivel=1;
            break;
        case 3:
            tipoCedulas[2].disponivel=1;
            break;
        case 4:
            tipoCedulas[3].disponivel=1;
            break;
        case 5:
            tipoCedulas[4].disponivel=1;
            break;
        case 6:
            tipoCedulas[5].disponivel=1;
             break;
        case 7:
            tipoCedulas[6].disponivel=1;
            break;
        default:
            printf("Opção inválida!");
    }
}
void opcaoRemoverCedula() //Função para remover um tipo de cédula
{
    int opcaoCedula;
    char notaUtilizada[7][30];
    for(int i=0;i<7;i++){
        if(tipoCedulas[i].disponivel==1) //Necessario para mostrar apenas cédulas habilitadas
            strcpy(notaUtilizada[i], " - Utilizado");
        else
            strcpy(notaUtilizada[i], " - Não Utilizado");
    }
    printf("Qual o valor da cédula que gostaria de adicionar?\n");
    printf("(1)R$2%s\n", notaUtilizada[0]);
    printf("(2)R$5%s\n", notaUtilizada[1]);
    printf("(3)R$10%s\n", notaUtilizada[2]);
    printf("(4)R$20%s\n", notaUtilizada[3]);
    printf("(5)R$50%s\n", notaUtilizada[4]);
    printf("(6)R$100%s\n", notaUtilizada[5]);
    printf("(7)R$200%s\n", notaUtilizada[6]);
    printf("Escolha uma opção: ");
    scanf("%d", &opcaoCedula);
    switch(opcaoCedula){
        case 1:
            tipoCedulas[0].disponivel=0; //criar 7 cases habilitando a disponibilidade da celula             tipoCedulas[i].disponivel
            break;                      
        case 2:
            tipoCedulas[1].disponivel=0;
            break;
        case 3:
            tipoCedulas[2].disponivel=0;
            break;
        case 4:
            tipoCedulas[3].disponivel=0;
            break;
        case 5:
            tipoCedulas[4].disponivel=0;
            break;
        case 6:
            tipoCedulas[5].disponivel=0;
            break;
        case 7:
            tipoCedulas[6].disponivel=0;
            break;
        default:
            printf("Opção inválida!");
    }
}
void status()
{
    tipoCedulas[0].cedulas=2; //inicializando o valor de todas as cedulas
    tipoCedulas[1].cedulas=5;
    tipoCedulas[2].cedulas=10;
    tipoCedulas[3].cedulas=20;
    tipoCedulas[4].cedulas=50;
    tipoCedulas[5].cedulas=100;
    tipoCedulas[6].cedulas=200;
    tipoCedulas[0].disponivel=1; //Indicado que as cedulas 2,20 e 100 estão disponiveis
    tipoCedulas[3].disponivel=1;
    tipoCedulas[5].disponivel=1;
}