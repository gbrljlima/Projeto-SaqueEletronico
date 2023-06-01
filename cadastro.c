#include "catalogo.h"
#include <stdio.h>
#include "estrutura.h"
//Função para cadastro do cliente
 int c;//contador;

int cadastro(){
    
    printf("Preencha seus dados cadastrais!\n");
    usuario[c].numeroDaConta = 1001 + c;
    printf("Informe seu nome e sobrenome: ");
    getchar(); //Limpa as strings
    scanf(" %29[^\n]", usuario[c].nome);
    printf("Informe seu endereço: \n");
    scanf(" %49[^\n]", usuario[c].endereco);
    printf("Informe uma senha de 4 digitos: ");
    for(int i=0; i<4;i++){
        scanf("%1d", &usuario[c].senha[i]);
    }
    if(getchar()!='\n'){
      printf("Senha inválida\n");
      while(getchar()!='\n');
      return 0;
    }
    printf("Cadastro completo!\n");
    printf("%s\nEndereço:%s\nO número da sua conta é: %d\n\n", usuario[c].nome,usuario[c].endereco, usuario[c].numeroDaConta);
    c++;
}