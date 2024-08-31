#include <stdio.h>
#include <stdlib.h>

// Declarando as variáveis 
float rendaMensal;
float valorEmprestimo;
float valorEntrada;
char historicoCredito;
char estabilidadeEmprego;
int mesesPagar;

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

void formulario() {
    printf("\t\t**Análise de Empréstimo Financeiro. v2.3**\n");
    
    rendaMensal = lerFloat("Digite sua renda mensal: ");
    valorEmprestimo = lerFloat("Digite o valor do empréstimo: ");
    mesesPagar = lerInteiro("Digite em quantos meses deseja pagar o empréstimo: ");
    historicoCredito = lerChar("Digite seu histórico de crédito (B = Bom, R = Ruim): ", "B", "R");
    estabilidadeEmprego = lerChar("Digite sua estabilidade no emprego (E = Estável, I = Instável): ", "E", "I");
    valorEntrada = lerFloat("Digite o valor da entrada: ");

    printf("\nO valor da renda é: %.2f\nO valor do Empréstimo é: %.2f\nO histórico é: %c\nA Estabilidade no Emprego é: %c\nO Valor da entrada é: %.2f\n",
           rendaMensal, valorEmprestimo, historicoCredito, estabilidadeEmprego, valorEntrada);

    int aprovalor30Porcento = calculaPorcentagem(rendaMensal, valorEmprestimo, valorEntrada, mesesPagar);
    printf("Retorno da função calculaPorcentagem: %d\n", aprovalor30Porcento);
    
    
}

// Função principal
int main() {
    formulario();
    return 0;
}
