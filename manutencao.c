#include "catalogo.h"
#include <stdio.h>
#include <stdlib.h>

void manutencao() {
  int condicao = 0;
  int opcao;
  printf ("___________________________________________\n");
  printf("\nManutencao ativada!\n\n");
  while (condicao == 0) {
    for (int i = 0; i < 7; i++) {
      if (tipoCedulas[i].quantidade == 0 && tipoCedulas[i].disponivel == 1){ // Necessario para mostrar apenas cédulas habilitadas
          printf("Não tem cédulas de R$%d.00\n", tipoCedulas[i].cedulas);
      }
  }
  printf("\nInforme uma escolha: \n");
  printf("\n(1) Repor cédula faltante.\n");
  printf("\n(2) Alterar disponibilidade da cédula.\n");
  printf("\n(3) Mostrar status de todas as cédulas.\n");
  printf("\n(4) Mostrar status das cédulas ativas.\n");
  printf("\n(5) Sair.\n");
  printf("\nSua opção: ");
  scanf("%d", &opcao);
  switch (opcao) {
    case 1:
      printf("\n(1) Repor todas as cédulas?\n");
      printf("\n(2) Repor cédulas individualmente?\n");
      printf("Escolha: ");
      scanf("%d", &opcao);
      switch (opcao) {
        case 1:
          reporTudo();
          break;
        case 2:
          reporIndividual();
          break;
      }
    break;
    case 2:
      disponibilidadeCedula();
      break;
    case 3:
      printf("\nMenu de cédulas:\n\n");
      for(int i=0;i<7;i++){
          printf("(%d) Cédula de R$%d,00 - Disponibilidade: %d - Quantidade: %d \n\n",i+1, tipoCedulas[i].cedulas, tipoCedulas[i].disponivel, tipoCedulas[i].quantidade);
      }
      break;
    case 4:
      printf("\nMenu de cédulas ativas atualmente:\n\n");
      for(int i=0;i<7;i++){
        if(tipoCedulas[i].disponivel == 1)
        printf("(%d) Cédula de R$%d,00 - Disponibilidade: %d - Quantidade: %d \n\n",i+1, tipoCedulas[i].cedulas, tipoCedulas[i].disponivel, tipoCedulas[i].quantidade);
      }
      break;
    case 5:
      condicao = 1;
      break;
    }
  }
}