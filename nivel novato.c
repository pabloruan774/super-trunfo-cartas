#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma carta
struct Carta {
    char estado[3];              // Estado (ex: "SP")
    char codigo[4];              // Código da carta (ex: "A01")
    char nome[50];               // Nome da cidade
    int populacao;               // População
    float area;                  // Área (km²)
    float pib;                   // PIB (em bilhões)
    int pontos_turisticos;       // Número de pontos turísticos
    float densidade;             // Densidade populacional
    float pib_per_capita;        // PIB per capita
};

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *carta) {
    printf("Estado (ex: SP): ");
    scanf("%2s", carta->estado);

    printf("Codigo da carta (ex: A01):\n");
    scanf("%3s", carta->codigo);

    printf("Nome da cidade:\n");
    getchar(); // limpa o \n que sobra no buffer
    fgets(carta->nome, sizeof(carta->nome), stdin);
    carta->nome[strcspn(carta->nome, "\n")] = '\0'; // remove quebra de linha

    printf("Populacao: ");
    scanf("%d", &carta->populacao);

    printf("Area (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (bilhoes): ");
    scanf("%f", &carta->pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta->pontos_turisticos);

    // Calcula atributos derivados
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = (carta->pib * 1e9) / carta->populacao; // PIB estava em bilhões
}

// Função para exibir resultado da comparação
void compararCartas(struct Carta c1, struct Carta c2, int atributo) {
    printf("\n=== Comparacao de Cartas ===\n");

    if (atributo == 1) { // População
        printf("Atributo: Populacao\n");
        printf("Carta 1 - %s (%s): %d\n", c1.nome, c1.estado, c1.populacao);
        printf("Carta 2 - %s (%s): %d\n", c2.nome, c2.estado, c2.populacao);

        if (c1.populacao > c2.populacao)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
        else if (c2.populacao > c1.populacao)
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");

    } else if (atributo == 2) { // Área
        printf("Atributo: Area\n");
        printf("Carta 1 - %s (%s): %.2f km²\n", c1.nome, c1.estado, c1.area);
        printf("Carta 2 - %s (%s): %.2f km²\n", c2.nome, c2.estado, c2.area);

        if (c1.area > c2.area)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
        else if (c2.area > c1.area)
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");

    } else if (atributo == 3) { // PIB
        printf("Atributo: PIB\n");
        printf("Carta 1 - %s (%s): %.2f bilhoes\n", c1.nome, c1.estado, c1.pib);
        printf("Carta 2 - %s (%s): %.2f bilhoes\n", c2.nome, c2.estado, c2.pib);

        if (c1.pib > c2.pib)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
        else if (c2.pib > c1.pib)
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");

    } else if (atributo == 4) { // Densidade populacional (menor vence)
        printf("Atributo: Densidade Populacional\n");
        printf("Carta 1 - %s (%s): %.2f hab/km²\n", c1.nome, c1.estado, c1.densidade);
        printf("Carta 2 - %s (%s): %.2f hab/km²\n", c2.nome, c2.estado, c2.densidade);

        if (c1.densidade < c2.densidade)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
        else if (c2.densidade < c1.densidade)
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");

    } else if (atributo == 5) { // PIB per capita
        printf("Atributo: PIB per capita\n");
        printf("Carta 1 - %s (%s): %.2f R$/hab\n", c1.nome, c1.estado, c1.pib_per_capita);
        printf("Carta 2 - %s (%s): %.2f R$/hab\n", c2.nome, c2.estado, c2.pib_per_capita);

        if (c1.pib_per_capita > c2.pib_per_capita)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
        else if (c2.pib_per_capita > c1.pib_per_capita)
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
        else
            printf("Resultado: Empate!\n");
    }
}

int main(void) {
    struct Carta carta1, carta2;
    int escolha;

    printf("=== Cadastro da Carta 1 ===\n");
    cadastrarCarta(&carta1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    cadastrarCarta(&carta2);

    // Menu de atributos para comparar
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per capita\n");
    printf("Opcao: ");
    scanf("%d", &escolha);

    compararCartas(carta1, carta2, escolha);

    return 0;
}
