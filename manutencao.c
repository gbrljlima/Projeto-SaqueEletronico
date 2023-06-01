#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"
#include "catalogo.h"


void manutencao(){    
    int condicao=0;
    int opcao, opcaoCedula;
    
    printf("Manutencao ativada!\n\n");
    while(!condicao){
      system("clear");
        for(int i=0;i<7;i++){
            if(tipoCedulas[i].quantidadeCedulas==0){
                if(tipoCedulas[i].disponivel==1) //Necessario para mostrar apenas cédulas habilitadas
                    printf("Não tem cédulas de R$%d\n", tipoCedulas[i].cedulas);
            }
        }
        printf("\nEscolha uma opção: \n");
        printf("(1) Definir a quantidade de notas de cada célula\n");
        printf("(2) Repor cédula faltante\n");            
        printf("(3) Adicionar cédula de diferente valor\n");
        printf("(4) Remover cédula de diferente valor\n");
        printf("(5) Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                maxCedula();
                break;
            case 2:
                printf("(1) Repor todas as cédulas?\n");
                printf("(2) Repor cédulas individualmente?\n");
                printf("Escolha: ");
                scanf("%d", &opcaoCedula);
                switch(opcaoCedula){
                    case 1:
                        reporTudo();
                        break;
                    case 2:
                        reporIndividual();
                        break;
                }
                break;
            case 3:
                while(1){
                    opcaoAddCedula();
                    printf("Gostaria de adicionar outra cédula?\n");
                    printf("(1)Sim\t(2)Não\n\nEscolha uma opção: ");
                    scanf("%d", &opcaoCedula);
                    if(opcaoCedula==2)
                        break;
                }
                break;
            case 4:
                while(1){
                    opcaoRemoverCedula();
                    printf("Gostaria de remover outra cédula?\n");
                    printf("(1)Sim\t(2)Não\n\nEscolha uma opção: ");
                    scanf("%d", &opcaoCedula);
                    if(opcaoCedula==2)
                        break;
                }
                break;
            case 5:    
                condicao=1;
                break;
        }
    }
}