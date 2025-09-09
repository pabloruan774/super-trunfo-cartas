#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Carta {
    char estado[50];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double densidade;
    double pib_per_capita;
};

void calcularAtributos(struct Carta *c) {
    c->densidade = (double)c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

void exibirMenu(int atributoBloqueado) {
    printf("\nEscolha um atributo para comparação:\n");
    if (atributoBloqueado != 1) printf("1 - População\n");
    if (atributoBloqueado != 2) printf("2 - Área\n");
    if (atributoBloqueado != 3) printf("3 - PIB\n");
    if (atributoBloqueado != 4) printf("4 - Pontos Turísticos\n");
    if (atributoBloqueado != 5) printf("5 - Densidade Demográfica\n");
    if (atributoBloqueado != 6) printf("6 - PIB per Capita\n");
    printf("Opção: ");
}

double obterValorAtributo(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return (double)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (double)c.pontos_turisticos;
        case 5: return c.densidade;
        case 6: return c.pib_per_capita;
        default: return 0;
    }
}

const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

int main() {
    srand(time(NULL));

    // Banco de estados
    struct Carta estados[] = {
        {"SP", "A1", "São Paulo", 123000000, 248209.0, 2600000000000.0, 30},
        {"RJ", "A2", "Rio de Janeiro", 17460000, 43780.0, 900000000000.0, 25},
        {"MG", "A3", "Minas Gerais", 21300000, 586528.0, 850000000000.0, 20},
        {"RS", "A4", "Rio Grande do Sul", 11300000, 281730.0, 500000000000.0, 18},
        {"BA", "A5", "Bahia", 14800000, 564692.0, 450000000000.0, 22},
        {"PR", "A6", "Paraná", 11600000, 199307.0, 430000000000.0, 15},
        {"PE", "A7", "Pernambuco", 9640000, 98312.0, 250000000000.0, 12},
        {"CE", "A8", "Ceará", 9240000, 148894.0, 200000000000.0, 10}
    };

    int totalEstados = sizeof(estados) / sizeof(estados[0]);
    struct Carta cartasSelecionadas[4];

    // Seleção de 4 estados aleatórios
    for (int i = 0; i < 4; i++) {
        int idx;
        int repetido;
        do {
            repetido = 0;
            idx = rand() % totalEstados;
            for (int j = 0; j < i; j++) {
                if (strcmp(estados[idx].estado, cartasSelecionadas[j].estado) == 0) {
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);

        cartasSelecionadas[i] = estados[idx];
        calcularAtributos(&cartasSelecionadas[i]);
    }

    printf("=== Cartas Sorteadas ===\n");
    for (int i = 0; i < 4; i++) {
        printf("%d - %s (%s)\n", i+1, cartasSelecionadas[i].nome, cartasSelecionadas[i].estado);
    }

    // Jogador escolhe 2 cartas
    int c1, c2;
    printf("\nEscolha a primeira carta (1-4): ");
    scanf("%d", &c1);
    printf("Escolha a segunda carta (1-4): ");
    scanf("%d", &c2);

    struct Carta carta1 = cartasSelecionadas[c1-1];
    struct Carta carta2 = cartasSelecionadas[c2-1];

    // Escolha dos atributos
    int escolha1, escolha2;
    exibirMenu(0);
    scanf("%d", &escolha1);

    exibirMenu(escolha1);
    scanf("%d", &escolha2);

    // Valores
    double valor1_c1 = obterValorAtributo(carta1, escolha1);
    double valor1_c2 = obterValorAtributo(carta2, escolha1);

    double valor2_c1 = obterValorAtributo(carta1, escolha2);
    double valor2_c2 = obterValorAtributo(carta2, escolha2);

    // Comparação individual
    int resultado1 = (escolha1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : (valor1_c1 > valor1_c2 ? 2 : 0))
                                     : (valor1_c1 > valor1_c2 ? 1 : (valor1_c1 < valor1_c2 ? 2 : 0));

    int resultado2 = (escolha2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : (valor2_c1 > valor2_c2 ? 2 : 0))
                                     : (valor2_c1 > valor2_c2 ? 1 : (valor2_c1 < valor2_c2 ? 2 : 0));

    // Soma final
    double soma1 = valor1_c1 + valor2_c1;
    double soma2 = valor1_c2 + valor2_c2;
    int vencedorFinal = (soma1 > soma2) ? 1 : (soma1 < soma2 ? 2 : 0);

    // Exibição
    printf("\n=== Comparação Super Trunfo ===\n");
    printf("Carta 1: %s (%s)\n", carta1.nome, carta1.estado);
    printf("Carta 2: %s (%s)\n", carta2.nome, carta2.estado);

    printf("\nAtributo 1: %s\n", nomeAtributo(escolha1));
    printf(" - %s: %.2f\n", carta1.nome, valor1_c1);
    printf(" - %s: %.2f\n", carta2.nome, valor1_c2);
    printf("Vencedor: %s\n", resultado1 == 1 ? carta1.nome : (resultado1 == 2 ? carta2.nome : "Empate"));

    printf("\nAtributo 2: %s\n", nomeAtributo(escolha2));
    printf(" - %s: %.2f\n", carta1.nome, valor2_c1);
    printf(" - %s: %.2f\n", carta2.nome, valor2_c2);
    printf("Vencedor: %s\n", resultado2 == 1 ? carta1.nome : (resultado2 == 2 ? carta2.nome : "Empate"));

    printf("\nSoma dos atributos:\n");
    printf(" - %s: %.2f\n", carta1.nome, soma1);
    printf(" - %s: %.2f\n", carta2.nome, soma2);

    if (vencedorFinal == 1)
        printf("\nResultado Final: %s venceu a rodada!\n", carta1.nome);
    else if (vencedorFinal == 2)
        printf("\nResultado Final: %s venceu a rodada!\n", carta2.nome);
    else
        printf("\nResultado Final: Empate!\n");

    return 0;
}
