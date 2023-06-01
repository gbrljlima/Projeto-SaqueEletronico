/******************************************************************************
Teste manutencao

                                Patch notes
Criar valores de cédulas fixas, criar condição para serem usados, fazer um for
continue caso condição 0. - ok Criar case para todos os valores, mas só permitir
os que não estão sendo utilizados - ok Colocar no inicio do código principal as
notas q estão disponíveis colocar no inicio da manutencao a quantidade de notas
disponiveis - ok limitar somente para as notas habilitadas - ok Criar a
reposição de notas (case 2) - repor todas de vez (melhor) ou individualmente -
ok Criar a remoção de um valor de cedula do sistema (Não é importante) - ok
Limitar a mudança max de notas para somente cedulas disponiveis - ok
Transformar o que der em funções para limpar o código - ok
Adaptar o projeto principal para rodar esse código (chato) - 70%
    - Diminuir o número de notas no saque.- ok
    - Adaptar a nota de R$5 (chato) //o problema é entre o 0 e o 5
        int valor, dez, cinco, dois, unidade;
        printf("Informe um valor: ");
        scanf("%d", &valor);
        unidade=valor%10;
        if(valor%2==0){
            dez=valor/10;
            valor%=10;
            dois=valor/2;
        }
        else if(unidade==1||unidade==3){
            dez=valor/10 - 1;
            valor= valor%10 + 10;
            cinco=valor/5 - 1;
            valor=valor%5 + 5;
            dois=valor/2;
        }
        else{
            dez=valor/10;
            valor%=10;
            cinco=valor/5;
            valor%=5;
            dois=valor/2;
        }
        printf("%d\n%d\n%d", dez, cinco, dois);
        Conta do mantenedor -if (valor == 111000) { // Código do mantenedor
            manutencao();
            valor = 0;
          }
        Limite de saque de acordo com o número de cédulas dísponiveis-
          - Informar a quantia máxima que pode ser sacada
          - Limitar quantia de saque por uso
        Fazer mais funções para o código principal - 
        Fazer o limite da senha para apenas 4 digitos - 50%
        Colocar as cedulas disponiveis no inicio do sistema-
        Refatorar as funções de adicionar e remover cédulas-
*******************************************************************************/
#include "catalogo.h"
#include "estrutura.h"
#include <stdio.h>
#include <stdlib.h>

cedulas tipoCedulas[7];
cliente usuario[100];
int numeroDaContaEntrada;

int main() {
  int condicao;
  status();
  for (int i = 0; i < 7; i++) { // Inicia a quantidade maxima de notas com 50                                
    tipoCedulas[i].maxQntCedulas = 50;// para todos os valores
    tipoCedulas[i].quantidadeCedulas = 50;
  }
  char repetir = 's';
  while(1) {
    system("clear");
    printf("Bem vindo ao caixa 24 horas!\n\n");
    printf("%d notas disponíveis de R$2\n%d notas disponíveis de R$20\n%d "
           "notas disponíveis de R$100\n",
           tipoCedulas[0].quantidadeCedulas, tipoCedulas[3].quantidadeCedulas,
           tipoCedulas[5].quantidadeCedulas);
    while (condicao == 0) { // Condicao para verificação de conta, se, no caso
                            // 2, a conta existir a condição é 1
      switch (menu()) {
      case 1:
        cadastro();
        break;
      case 2:
        condicao = souCliente();
        break;
      default:
        printf("Opção inválida!\n");
      }    
    }
    while (condicao == 2){
      manutencao();
      break;
    }
    do {
      system("clear");
      switch (subMenu()) {
      case 1:
        saldo();
        break;
      case 2:
        saqueCedulas(escolherValor());
        break;
      case 3:
        deposito();
        break;
      default:
        printf("Opção inválida!\n");
        break;
      }
      printf("Gostaria de fazer outra operação? (S/N)\n");
      scanf("%s", &repetir);
    } while (repetir == 's' || repetir == 'S');
    condicao = 0;
  }
  return 0;
}
