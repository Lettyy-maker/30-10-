#include <stdio.h>

int main() {
    int quantidade;
    
    printf("Digite a quantidade de produtos a serem cadastrados: 3 ");
    scanf("%d", &quantidade);

    // Verifica se a quantidade é válida
    if (quantidade <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    // Criação do vetor de códigos
    int *codigos = (int *) malloc (quantidade * sizeof(int));
    if (codigos == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Entrada dos códigos dos produtos
    for (int i = 0; i < quantidade; i++) {
        printf(" 101 %d: ", i + 1);
        scanf("%d", &codigos[i]);
    }

    // Exibição dos códigos cadastrados
    printf("\nCodigos cadastrados:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Produto %d -> Codigo: %d\n", i + 1, codigos[i]);
    }

    // Liberação da memória
    free(codigos);

    return 0;
}


