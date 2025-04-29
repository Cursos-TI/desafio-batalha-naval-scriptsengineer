#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int fields[10][10];
int max_ships = 2;

void initialization()
{
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            fields[x][y] = 0;
        }
    }
}

int check_has_ship_on_positions(int pos_x, int pos_y, int width, int height)
{
    for (int x = pos_x; x < pos_x + width; x++)
    {
        for (int y = pos_y; y < pos_y + height; y++)
        {
            if (fields[x][y] != 0)
            {
                return 2;
            }
        }
    }
    return 0;
}

int setup_ship(int width, int height)
{
    int pos_x = 0;
    int pos_y = 0;
    printf("Diga a posição que quer colocar o navio [Tamanho %ix%i]:\n", width, height);
    printf("X:");
    scanf("%i", &pos_x);
    printf("Y:");
    scanf("%i", &pos_y);

    printf("%i%i\n", pos_x, pos_y);

    // Checa se não posicao não valida
    if (pos_x + width > 10)
    {
        printf("A posição X não encaixa no tabuleiro");
        return 1;
    }

    if (pos_y + height > 10)
    {
        printf("A posição Y não encaixa no tabuleiro.");
        return 1;
    }

    // Checa se não existe outro navio
    if(check_has_ship_on_positions(pos_x, pos_y, width, height) != 0)
    {
        printf("Na posição existe outro navio tente novamente.");
        return 2;
    }

    for (int x = pos_x; x < pos_x + width; x++)
    {
        for (int y = pos_y; y < pos_y + height; y++)
        {
            printf("test\n");
            fields[x][y] = 3;
        }
    }
    return 0;
}

void show_fields()
{
    printf("Imprimindo o tabuleiro:\n");
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            printf("(%i)", fields[x][y]);
        }
        printf("\n");
    }
}

int main()
{
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    initialization();
    int response = -1;
    do
    {
        response = setup_ship(3, 1);

    } while (response != 0);
    do
    {
        response = setup_ship(1, 3);

    } while (response != 0);
    show_fields();
    return 0;
}
