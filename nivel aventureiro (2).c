#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura que representa uma carta de país
struct Carta {
    char nome[50];          // Nome do país
    int populacao;          // População
    float area;             // Área em km²
    float pib;              // PIB em bilhões
    int pontos_turisticos;  // Pontos turísticos
    float densidade;        // Densidade demográfica
};

// Lista de países para sortear
const char *paises[] = {"Brasil", "Argentina", "Chile", "Peru", "Colombia", 
                        "Mexico", "Canada", "EUA", "Japao", "Alemanha", "Franca", "Italia"};
int total_paises = 12;

// Função para gerar uma carta aleatória
struct Carta gerarCartaAleatoria() {
    struct Carta c;

    // Sorteia nome de país
    strcpy(c.nome, paises[rand() % total_paises]);

    // Gera valores aleatórios
    c.populacao = rand() % 200000000 + 1000000;  // 1M até 200M
    c.area = (rand() % 9000000) + 50000;         // 50k até 9M km²
    c.pib = (rand() % 3000) + 100;               // 100 até 3000 bilhões
    c.pontos_turisticos = rand() % 100 + 1;      // 1 até 100 pontos turísticos

    // Calcula densidade
    c.densidade = (float)c.populacao / c.area;

    return c;
}

// Função para exibir carta
void exibirCarta(struct Carta c) {
    printf("\n--- %s ---\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", c.densidade);
}

// Função de comparação
void compararCartas(struct Carta c1, struct Carta c2, int opcao) {
    printf("\n=== Comparação de Cartas ===\n");
    switch (opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d | %s: %d\n", c1.nome, c1.populacao, c2.nome, c2.populacao);
            if (c1.populacao > c2.populacao)
                printf("Resultado: %s venceu!\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("Resultado: %s venceu!\n", c2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km² | %s: %.2f km²\n", c1.nome, c1.area, c2.nome, c2.area);
            if (c1.area > c2.area)
                printf("Resultado: %s venceu!\n", c1.nome);
            else if (c2.area > c1.area)
                printf("Resultado: %s venceu!\n", c2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhões | %s: %.2f bilhões\n", c1.nome, c1.pib, c2.nome, c2.pib);
            if (c1.pib > c2.pib)
                printf("Resultado: %s venceu!\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("Resultado: %s venceu!\n", c2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d | %s: %d\n", c1.nome, c1.pontos_turisticos, c2.nome, c2.pontos_turisticos);
            if (c1.pontos_turisticos > c2.pontos_turisticos)
                printf("Resultado: %s venceu!\n", c1.nome);
            else if (c2.pontos_turisticos > c1.pontos_turisticos)
                printf("Resultado: %s venceu!\n", c2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // Densidade demográfica (menor vence)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km² | %s: %.2f hab/km²\n", c1.nome, c1.densidade, c2.nome, c2.densidade);
            if (c1.densidade < c2.densidade)
                printf("Resultado: %s venceu!\n", c1.nome);
            else if (c2.densidade < c1.densidade)
                printf("Resultado: %s venceu!\n", c2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida!\n");
    }
}

int main(void) {
    srand(time(NULL)); // inicializa semente do rand

    // Gera duas cartas aleatórias
    struct Carta carta1 = gerarCartaAleatoria();
    struct Carta carta2 = gerarCartaAleatoria();

    // Garante que os países não sejam iguais
    while (strcmp(carta1.nome, carta2.nome) == 0) {
        carta2 = gerarCartaAleatoria();
    }

    int opcao;
    printf("=== Super Trunfo - Nivel Aventureiro (Aleatorio) ===\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    compararCartas(carta1, carta2, opcao);

    return 0;
}
