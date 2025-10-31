#include <stdio.h>
#include <stdlib.h>

// Função para ordenar o vetor usando Bubble Sort
void bubbleSort(int *vetor, int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os valores
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    int quantidade;

    printf("Digite a quantidade de produtos a serem cadastrados:5 ");
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

    // Entrada dos códigos
    for (int i = 0; i < quantidade; i++) {
        printf("Digite o codigo do produto %d: 1 ", i + 1);
        printf(" 20 %d: ", i + 1);
        scanf("%d", &codigos[i]);
        
    }

    // Ordenação dos códigos (Bubble Sort)
    bubbleSort(codigos, quantidade);

    // Exibição dos códigos ordenados
    printf("\nCodigos cadastrados (ordenados em ordem crescente):\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Produto %d -> Codigo: %d\n", i + 1, codigos[i]);
    }

    free(codigos);
    return 0;
}
