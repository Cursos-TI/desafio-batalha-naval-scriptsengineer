#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int fields[10][10];
int max_ships = 2;
const int ship_size = 3;

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

int check_normal_has_ship_on_positions(int pos_x, int pos_y, int width, int height)
{
    for (int x = pos_x; x < pos_x + ship_size; x++)
    {
        for (int y = pos_y; y < pos_y + ship_size; y++)
        {
            if (fields[x][y] != 0)
            {
                return 2;
            }
        }
    }
    return 0;
}

int check_diagonal_has_ship_on_positions(int pos_x, int pos_y, int width, int height)
{
    for (int x = pos_x; x < pos_x + ship_size; x++)
    {
        for (int y = pos_y; y < pos_y + ship_size; y++)
        {
            if (x == y && fields[x][y] != 0)
            {
                return 2;
            }
        }
    }
    return 0;
}

int setup_vertical_ship(int pos_x, int pos_y)
{
    // Checa se não posicao não valida
    if (pos_x + ship_size > 10)
    {
        printf("A posição X não encaixa no tabuleiro");
        return 1;
    }

    if (pos_y >= 10)
    {
        printf("A posição Y não encaixa no tabuleiro.");
        return 1;
    }

    // Checa se não existe outro navio
    if(check_normal_has_ship_on_positions(pos_x, pos_y, ship_size, 1) != 0)
    {
        printf("Na posição existe outro navio tente novamente.");
        return 2;
    }

    for (int x = pos_x; x < pos_x + ship_size; x++)
    {
        fields[x][pos_y] = 3;
    }
    return 0;
}

int setup_horizontal_ship(int pos_x, int pos_y)
{
    // Checa se não posicao não valida
    if (pos_x >= 10)
    {
        printf("A posição X não encaixa no tabuleiro");
        return 1;
    }

    if (pos_y + ship_size >= 10)
    {
        printf("A posição Y não encaixa no tabuleiro.");
        return 1;
    }

    // Checa se não existe outro navio
    if(check_normal_has_ship_on_positions(pos_x, pos_y, 1, ship_size) != 0)
    {
        printf("Na posição existe outro navio tente novamente.");
        return 2;
    }
    
    for (int y = pos_y; y < pos_y + ship_size; y++)
    {
        fields[pos_x][y] = 3;
    }
    return 0;
}

int setup_diagonal_ship(int pos_x, int pos_y)
{
    if (pos_x + ship_size > 10)
    {
        printf("A posição X não encaixa no tabuleiro");
        return 1;
    }

    if (pos_y + ship_size > 10)
    {
        printf("A posição Y não encaixa no tabuleiro.");
        return 1;
    }

    //Checa se não existe outro navio
    if(check_diagonal_has_ship_on_positions(pos_x, pos_y, ship_size, 1) != 0)
    {
        printf("Na posição existe outro navio tente novamente.");
        return 2;
    }

    for (int x = pos_x; x < pos_x + ship_size; x++)
    {
        for (int y = pos_y; y < pos_y + ship_size; y++)
        {
            if(x == y)
            {
                fields[x][y] = 3;
            }
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
    setup_vertical_ship(0, 0);
    setup_horizontal_ship(0, 1);
    setup_diagonal_ship(5, 5);

    show_fields();
    return 0;
}
