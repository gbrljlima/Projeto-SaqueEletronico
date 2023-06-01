#include <stdio.h>
#include "catalogo.h"
#include "estrutura.h"
//Função para seleção de valores
int escolherValor()
{   
  int escolha, valor;
  printf("\n");// Colocar notas que estão disponíveis
  printf("Quanto você quer retirar?\n");
  printf("(1) R$100 - (2) R$250\n");
  printf("(3) R$500 - (4) Outro valor\n");
  printf("Escolha uma opção: ");
  int lidoComSucesso = scanf("%d", &escolha); //Declarado variavel lidoComSucesso para saber se a variavel escolha receberá um valor válido 
  while(lidoComSucesso != 1 || escolha < 1 || escolha > 4){
      printf("Opção inválida!\nDigite a opção novamente: ");
      while(getchar() != '\n'); //limpa o buffer de entrada
          lidoComSucesso = scanf("%d", &escolha);
  }
  switch(escolha){
      case 1:
          valor=100;
          break;
      case 2:
          valor=250;
          break;
      case 3:
          valor=500;
          break;
      case 4:
          printf("Qual valor você deseja?\n");
          lidoComSucesso = scanf("%d", &valor);
          if(tipoCedulas[1].disponivel==1){ //Caso a nota de R$5 esteja disponivel
              while(lidoComSucesso != 1 || valor < 1){
                  printf("Não temos notas compatíveis para R$%d!\nDigite outro valor: ", valor);
                  while(getchar() != '\n'); //limpa o buffer de entrada
                      lidoComSucesso = scanf("%d", &valor);
              }
          }
          else{
              while(lidoComSucesso != 1 || valor < 1 || valor%2==1){
                  printf("Não temos notas compatíveis para R$%d!\nDigite outro valor: ", valor);
                  while(getchar() != '\n'); //limpa o buffer de entrada
                      lidoComSucesso = scanf("%d", &valor);
              }
          }                
          break;
  }
  return valor;
}