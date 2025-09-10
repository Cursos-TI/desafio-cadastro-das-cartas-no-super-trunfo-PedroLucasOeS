#include <stdio.h>

int main() {
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[100], cidade2[100];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;
    float super_poder1, super_poder2;

    // Entrada de dados da Carta 1
    printf("*** Informe os dados da Carta 1: ***\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]%*c", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (em km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Entrada de dados da Carta 2
    printf("\n *** Informe os dados da Carta 2: ***\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta (ex: B03): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]%*c", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    pib_per_capita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    pib_per_capita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    // 1000000000.0f → converte PIB de bilhões para reais.

    super_poder1 = (float)populacao1 + area1 + pib1 + pontos_turisticos1 +
     pib_per_capita1 + (1.0f / densidade1);
    super_poder2 = (float)populacao2 + area2 + pib2 + pontos_turisticos2 + 
    pib_per_capita2 + (1.0f / densidade2);
    // 1.0f -> garante divisão em ponto flutuante ao calcular o inverso da densidade.

    // Comparações
    printf("\nComparação de Cartas:\n");
    // O operador ternário ? : é uma forma curta de escrever um if/else.
    // Se populacao1 > populacao2 → retorna 1 (Carta 1 venceu).
    // Caso contrário → retorna 2 (Carta 2 venceu).
    printf("População: Carta %d venceu\n", (populacao1 > populacao2) ? 1 : 2);
    printf("Área: Carta %d venceu\n", (area1 > area2) ? 1 : 2);
    printf("PIB: Carta %d venceu\n", (pib1 > pib2) ? 1 : 2);
    printf("Pontos Turísticos: Carta %d venceu\n", (pontos_turisticos1 > pontos_turisticos2) ? 1 : 2);
    printf("Densidade Populacional: Carta %d venceu\n", (densidade1 < densidade2) ? 1 : 2);
    printf("PIB per Capita: Carta %d venceu\n", (pib_per_capita1 > pib_per_capita2) ? 1 : 2);
    printf("Super Poder: Carta %d venceu\n", (super_poder1 > super_poder2) ? 1 : 2);

    return 0;
}

