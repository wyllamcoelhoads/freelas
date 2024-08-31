#include <stdio.h>
#include <stdlib.h>
//declarando as variaveis 
float rendaMensal;
float valorEmprestimo;
float valorEntrada;
char historicoCredito;
char estabilidadeEmprego;
char buffer[10000];
int mesesPagar;


//vai calcular o valor maximo que se pode pagar e o valor que saira a parcela real do emprestimo levando em conta os meses (sem taxas e juros)
int CalculaPorcentagem (float cRendaMensal, float cValorEmprestimo, float cEntrada, int cMesesPagar){
    int validaPorcentagem;
    float parcelaMensal;
    float limiteParcela;
    // calcula o valor da parcela por mes que será paga no emprestimo
    parcelaMensal = (cValorEmprestimo - cEntrada) / cMesesPagar;
    //verificando o valor que no maximo se pode pagar por mês
    limiteParcela = cRendaMensal * 0.30;
    // retorna um valor para ser usado no condicional da função main
    return parcelaMensal;
}
// função principal 
void main () {
    printf ("\t\t**Analise de Empréstimo Financeiro.**\n");
    printf ("\t\t Digite sua renda mensal..........................................: ");
    scanf("%f", &rendaMensal);
    if (scanf("%f", &rendaMensal) != 1) {
         printf("Entrada inválida. Por favor, digite um número de ponto flutuante.\n");
         main();
         system("pause");
         
    }
    printf ("\t\t Digite o valor do empréstimo.....................................: ");
    scanf("%f", &valorEmprestimo);
    printf ("\t\t Digite em quantos meses deseja pagar o empréstimo................: ");
    scanf("%d", &mesesPagar);
    fflush(stdin);
    printf ("\t\t Digite seu historico "); // de crédito (B = Bom, R = Ruim)..............: ");
    scanf(" %c", &historicoCredito);
    printf ("\t\t Digite sua estabilidade "); //no emprego (E = Estável, I = Instável)...: ");
    scanf(" %c", &estabilidadeEmprego);
    fflush(stdin);
    printf ("\t\t Digite o valor da entrada........................................: ");
    scanf("%f", &valorEntrada);
    printf ("\n");
    printf ("O valor da renda é: %f\n, O valor do Empréstimo é: %f\n, O historico é: %c\n, A Estábilidade no Emprego é: %c\n e o Valor da entrada é: %f ",rendaMensal,valorEmprestimo,historicoCredito,estabilidadeEmprego,valorEntrada);
    printf ("\n");

    float total = CalculaPorcentagem(rendaMensal, valorEmprestimo, valorEntrada, mesesPagar);
    printf(" retormo da função CalculaPorcentagem : %.2f", total);
    printf ("\n");
}