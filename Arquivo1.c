#include <stdio.h>

void preencherVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void imprimirVetor(int v[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

void ordenar(int v[], int n) {
    // Algoritmo de ordenação Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                // Troca os elementos
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void imprimirMaiorImpar(int v[], int n) {
    int maiorImpar = -1;  // Inicializa como -1, valor indicando que não há ímpar.
    
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 != 0) {  // Verifica se o número é ímpar
            if (maiorImpar == -1 || v[i] > maiorImpar) {
                maiorImpar = v[i];
            }
        }
    }

    if (maiorImpar != -1) {
        printf("O maior número ímpar é: %d\n", maiorImpar);
    } else {
        printf("Não há números ímpares no vetor\n");
    }
}

void criarParesImpares(int v[], int n, int pares[], int impares[]) {
    int parIndex = 0, imparIndex = 0;
    
    // Preenche os vetores pares e ímpares
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            pares[parIndex++] = v[i];
        } else {
            impares[imparIndex++] = v[i];
        }
    }
    
    // Preenche as posições restantes com -1
    for (int i = parIndex; i < n; i++) {
        pares[i] = -1;
    }
    for (int i = imparIndex; i < n; i++) {
        impares[i] = -1;
    }
}

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n], pares[n], impares[n];

    // Preenche o vetor com números fornecidos pelo usuário
    preencherVetor(v, n);
    
    printf("Vetor preenchido: ");
    imprimirVetor(v, n);

    // Ordena o vetor
    ordenar(v, n);
    printf("Vetor ordenado: ");
    imprimirVetor(v, n);

    // Imprime o maior valor ímpar
    imprimirMaiorImpar(v, n);

    // Cria os vetores de pares e ímpares
    criarParesImpares(v, n, pares, impares);
    
    printf("Vetor de pares: ");
    imprimirVetor(pares, n);
    printf("Vetor de ímpares: ");
    imprimirVetor(impares, n);

    return 0;
}
