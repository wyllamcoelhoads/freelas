#include <stdio.h>
#include <stdlib.h>

// Declarando as variáveis 
float rendaMensal;
float valorEmprestimo;
float valorEntrada;
char historicoCredito;
char estabilidadeEmprego;
int mesesPagar;
int aprovalor30Porcento;

// Função para calcular o valor máximo que se pode pagar e o valor da parcela real do empréstimo
int calculaPorcentagem(float cRendaMensal, float cValorEmprestimo, float cEntrada, int cMesesPagar) {
    float parcelaMensal;
    float limiteParcela;
    int valorAprova;

    // Calcula o valor da parcela por mês que será paga no empréstimo
    parcelaMensal = (cValorEmprestimo - cEntrada) / cMesesPagar;
    
    // Verifica o valor que no máximo se pode pagar por mês
    limiteParcela = cRendaMensal * 0.30;

    if (parcelaMensal < limiteParcela){
        valorAprova = 1;
    }else{
        valorAprova = 0;
    }

    // Retorna 1 para aprovado e 0 para reprovador por esse criterio
    return valorAprova;

}

// Função para ler um número de ponto flutuante
float lerFloat(char* mensagem) {
    float valor;
    int status;

    while (1) {
        printf("%s", mensagem);
        status = scanf("%f", &valor);

        // Verifica se a entrada foi bem-sucedida
        if (status == 1) {
            return valor;
        } else {
            // Limpa o buffer de entrada
            while (getchar() != '\n');
            printf("Entrada inválida. Por favor, digite um número de ponto flutuante.\n");
        }
    }
}

// Função para ler um inteiro
int lerInteiro(char* mensagem) {
    int valor;
    int status;

    while (1) {
        printf("%s", mensagem);
        status = scanf("%d", &valor);

        // Verifica se a entrada foi bem-sucedida
        if (status == 1) {
            return valor;
        } else {
            // Limpa o buffer de entrada
            while (getchar() != '\n');
            printf("Entrada inválida. Por favor, digite um número inteiro.\n");
        }
    }
}

// Função para ler um caractere e validar se é 'B' ou 'R'
char lerChar(const char *mensagem, const char *valido1, const char *valido2) {
    char valor;
    int status;

    while (1) {
        printf("%s", mensagem);
        status = scanf(" %c", &valor);

        // Limpa o buffer de entrada se a leitura falhar
        while (getchar() != '\n');

        // Verifica se a entrada foi bem-sucedida e se é um dos caracteres válidos
        if (status == 1 && (valor == valido1[0] || valor == valido2[0])) {
            return valor;
        } else {
            printf("Entrada inválida. Por favor, digite '%c' ou '%c'.\n", valido1[0], valido2[0]);
        }
    }
}

void informacoes(){
     printf("Dados Informados!\n");
    printf("Renda informada: R$%.2f\n", rendaMensal);
    printf("Valor do empréstimo solicitado: R$%.2f\n", valorEmprestimo);
    printf("Valor da entrada informada: R$%.2f\n", valorEntrada);
    printf("Quantidades de meses para pagar: %d\n", mesesPagar);
    printf("Valor maximo da parcela: R$%.2f\n", rendaMensal * 0.30);
    printf("Valor real da parcela: R$%.2f\n", (valorEmprestimo - valorEntrada) / mesesPagar);
    printf("Historico de Credito anterior B-Bom , R-Ruim: %c\n", historicoCredito);
    printf("Estabilidade no emprego E-Estável, I-Instável: %c\n", estabilidadeEmprego);
    
    printf("-----------------------------------------------------------------------\n");

}

void desicao(){
    // conforme funcao calculaPorcentagem retorna 1 para aprovado e 0 para reprovador por esse criterio
    if(aprovalor30Porcento != 1){
        system("clear");
        informacoes();
        printf("Infelizmente não podemos aceitar sua solicitação!\n");
        printf("Motivo: Parcela do empretimo compromete em mais de 30%% a sua renda.\n");
        printf("Fim do Programa! \n");
    }else if(historicoCredito == 'R' && (valorEntrada >= valorEmprestimo*0.60)){
        system("clear");
        informacoes();
        printf("Podemos aceitar sua solicitação!\n");
        printf("Motivo: Mesmo com historico de credito ruim você esta pagando 60%% ou mais do emprestimo.\n");
        printf("Fim do Programa! \n");
    }else if (historicoCredito == 'R' && estabilidadeEmprego == 'I')
    {
        system("clear");
        informacoes();
        printf("Não podemos aceitar sua solicitação!\n");
        printf("Motivo: Devido a historico e fonte de renda Instável\n");
        printf("Fim do Programa! \n");
    }else{
        system("clear");
        informacoes();
        printf("Parabéns! Seu empréstimo foi aprovado.\n");
        printf("Fim do Programa! \n");
    }
    
}

void formulario() {
    printf("\t\t**Análise de Empréstimo Financeiro. v3.1**\n");
    
    rendaMensal = lerFloat("Digite sua renda mensal: ");
    valorEmprestimo = lerFloat("Digite o valor do empréstimo: ");
    mesesPagar = lerInteiro("Digite em quantos meses deseja pagar o empréstimo: ");
    historicoCredito = lerChar("Digite seu histórico de crédito (B = Bom, R = Ruim): ", "B", "R");
    estabilidadeEmprego = lerChar("Digite sua estabilidade no emprego (E = Estável, I = Instável): ", "E", "I");
    valorEntrada = lerFloat("Digite o valor da entrada: ");

    aprovalor30Porcento = calculaPorcentagem(rendaMensal, valorEmprestimo, valorEntrada, mesesPagar);
    printf("Retorno da função calculaPorcentagem: %d\n", aprovalor30Porcento);

    desicao();
}

// Função principal
int main() {
    formulario();
    return 0;
}
