
typedef struct{
    int cedulas;
    int maxQntCedulas;
    int quantidadeCedulas;
    int disponivel;
}cedulas;
typedef struct{
    int numeroDaConta;
    char nome[30], endereco[50];
    float saldo;
    int senha[4];
}cliente;
extern cedulas tipoCedulas[7];
extern cliente usuario[100];
extern int numeroDaContaEntrada;