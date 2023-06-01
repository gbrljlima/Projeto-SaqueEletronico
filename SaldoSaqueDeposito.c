#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"
#include "estrutura.h"
//Função para deposito
void deposito()
{
    float deposito;
    printf("Informe a quantia que você irá depositar: R$");
    int lidoComSucesso = scanf("%f", &deposito);
    while(lidoComSucesso!=1){  
      while(getchar() != '\n');
      printf("Depósito inválido!\nInforme novamente: ");
      lidoComSucesso = scanf("%f", &deposito);
    }
    
    usuario[numeroDaContaEntrada].saldo+=deposito;    
}
void saldo() //Função para verificação de saldo
{
  printf("Seu saldo é: %.2f\n", usuario[numeroDaContaEntrada].saldo);
}
int saqueCedulas(int valor) //Função para o calculo de notas
{ 
  if (usuario[numeroDaContaEntrada].saldo < valor) {
      printf("Saldo insuficiente!\n");
      return 0;          
    }
    int contador=0, cedulaDisponivel[7]={0},i;
    for(i=0;i<7;i++){
        if(tipoCedulas[i].disponivel==1 && tipoCedulas[i].quantidadeCedulas>0){ //Verifica as cedulas disponiveis e a quantidade
            cedulaDisponivel[contador]=i; //Adiciona o tipo de cedula disponivel de 0 a 6
            contador++;
        }
    }
    int numeroDeNotas[contador]; //Será guardado o número de notas de 100, 20 e 2, nessa sequencia.
    int resto;
    contador-=1;
    printf("Você receberá:\n");
    for(i=contador;i>=0;i-- ){ //Começa da cedula de maior valor
        numeroDeNotas[i]=valor/tipoCedulas[cedulaDisponivel[i]].cedulas;
        resto=valor%tipoCedulas[cedulaDisponivel[i]].cedulas;
        valor=resto;
        tipoCedulas[cedulaDisponivel[i]].quantidadeCedulas-=numeroDeNotas[i];
        if(numeroDeNotas[i]!=0) {
            printf("%d cédulas de R$%d\n", numeroDeNotas[i], tipoCedulas[cedulaDisponivel[i]].cedulas);
        }
    }
}
