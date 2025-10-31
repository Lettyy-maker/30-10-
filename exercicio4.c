#include <stdio.h>
#include <stdlib.h>

// Função para ordenar o vetor (Bubble Sort)
void bubbleSort(int *vetor, int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Função de busca binária
int buscaBinaria(int *vetor, int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == valor)
            return meio; // Encontrado
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1; // Não encontrado
}

int main() {
    int quantidade;

    printf("Digite a quantidade de produtos a serem cadastrados: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    int *codigos = (int *) malloc(quantidade * sizeof(int));
    if (codigos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Cadastro dos códigos
    for (int i = 0; i < quantidade; i++) {
        printf("Digite o codigo do produto %d: ", i + 1);
        scanf("%d", &codigos[i]);
    }

    // Ordena os códigos em ordem crescente
    bubbleSort(codigos, quantidade);

    // Exibe os códigos cadastrados e ordenados
    printf("\nCodigos cadastrados (ordenados em ordem crescente):\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Produto %d -> Codigo: %d\n", i + 1, codigos[i]);
    }

    // Busca de código
    int codigoBusca;
    printf("\nDigite o codigo do produto que deseja consultar: ");
    scanf("%d", &codigoBusca);

    int posicao = buscaBinaria(codigos, quantidade, codigoBusca);

    if (posicao != -1) {
        printf("\nProduto encontrado!\n");
        printf("Codigo %d localizado na posicao %d do vetor (Produto %d).\n",
               codigoBusca, posicao, posicao + 1);
    } else {
        printf("\nProduto nao encontrado no sistema.\n");
    }

    free(codigos);
    return 0;
}
