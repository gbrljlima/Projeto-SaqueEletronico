#include "catalogo.h"
#include <stdio.h>
#include "estrutura.h"
//Função para o menu
int menu()
{
  int opcao;
  printf("Escolha uma opção!\n");
  printf("(1) Não sou cliente\t (2) Sou cliente\n");
  printf("Opção: ");
  int lidoComSucesso =scanf("%d", &opcao);
  if(lidoComSucesso!=1){  
    while(getchar() != '\n');  
    return 0;
  }
  return opcao;
}

int subMenu()
{
  int opcao;
  printf("Escolha uma opção!\n");
  printf("(1) Consultar Saldo\n");
  printf("(2) Saque\n");
  printf("(3) Deposito\n");
  printf("Opção: ");
  int lidoComSucesso = scanf("%d", &opcao);
  if(lidoComSucesso!=1){  
      while(getchar() != '\n');
      return 0;
  }   
  return opcao;
}