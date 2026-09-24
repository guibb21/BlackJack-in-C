#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int ler_inteiro(char buffer[150], int tamanho, int valor);

void exibir_cartas(int mao[10], int esconder_ultima);

void distribuir_duas(int baralho[13], int mao_jogador[10], int mao_dealer[10], int contador);

void comprar_carta(int baralho[13], int mao[10], int contador);

int calcular_mao(int mao[10]);

int main(void)
{
    srand(time(NULL));
    char buffer[150];
    int aposta = 0, cartas_jogador = 2, cartas_dealer = 2, opcao, total_jogador, total_dealer;
    int baralho[13];
    int mao_jogador[10];
    int mao_dealer[10];

    while(1)
    {
        printf("voce e um fodinha? entao deixe seu joinha [1-10]\n");
        aposta = ler_inteiro(buffer, sizeof(buffer), aposta);
        if(aposta > 10)
        {
            printf("numero muito alto\n");
            continue;
        }
        else if (aposta < 1)
        {
            printf("numero muito baixo\n");
            continue;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < 13; i++)
    {
        baralho[i] = 4 * aposta;
        if(i < 10)
        {
            mao_dealer[i] = 67;
            mao_jogador[i] = 67;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        distribuir_duas(baralho, mao_jogador, mao_dealer, i);
    }

    while (1)
    {
        system("clear");
        printf("  suas cartas seu viado                        cartas do carinha legal\n\n  ");
        exibir_cartas(mao_jogador, 0);
        int espacos_meio = 46 - (cartas_jogador * 4);
        if (espacos_meio < 2) espacos_meio = 2;
        for(int i = 0; i < espacos_meio; i++)
        {
            printf(" ");
        }
        exibir_cartas(mao_dealer, 1);
        printf("\n");

        total_jogador = calcular_mao(mao_jogador);
        if(total_jogador == 69)
        {
            printf("\n\n\n\n\n\nvoce perdeu\n");
            printf("aceita a derrota?");
            scanf("%149s", buffer);
            system("clear");
            printf("\n\n\n\n\n\n\n                    nao me importo");
            system("eject");
            sleep(2);
            system("clear");
            return 0;
        }
        printf("\n\n\n\n\n\n1-hit\n");
        printf("2-stand\n");
        opcao = ler_inteiro(buffer, sizeof(buffer), opcao);
        if (opcao == 1)
        {
            comprar_carta(baralho, mao_jogador, cartas_jogador);
            cartas_jogador++;
        }
        else if (opcao == 2)
        {
           break;
        }
    }

    while (1)
    {
        system("clear");
        printf("  suas cartas seu viado                        cartas do carinha legal\n\n  ");
        exibir_cartas(mao_jogador, 0);
        int espacos_meio = 46 - (cartas_jogador * 4);
        if (espacos_meio < 2) espacos_meio = 2;
        for(int i = 0; i < espacos_meio; i++)
        {
            printf(" ");
        }
        exibir_cartas(mao_dealer, 0);
        printf("\n");

        total_jogador = calcular_mao(mao_jogador);
        total_dealer = calcular_mao(mao_dealer);

        if (total_dealer == 69)
        {
            sleep(1);
            system("clear");
            printf("voce ganhou :(\n");
            sleep(4);
            system("clear");
            return 0;
        }
        
        if(total_dealer >= 17)
        {
            if (total_dealer > total_jogador)
            {
                printf("\n\n\n\n\n\nvoce perdeu\n");
                printf("aceita a derrota?");
                scanf("%149s", buffer);
                system("clear");
                printf("\n\n\n\n\n\n\n                    nao me importo\n");
                system("eject");
                sleep(2);
                system("clear");
                return 0;
            }
            else if (total_dealer < total_jogador)
            {
                sleep(1);
                system("clear");
                printf("voce ganhou :(\n");
                sleep(4);
                system("clear");
                return 0;
            }
            else
            {
                sleep(1);
                system("clear");
                printf("empate :/\n");
                sleep(4);
                system("clear");
                return 0;
            }
        }
        sleep(2);
        comprar_carta(baralho, mao_dealer, cartas_dealer);
        cartas_dealer++;
    }
}

int ler_inteiro(char buffer[150], int tamanho, int valor)
{
    while (1)
    {
        if (fgets(buffer, tamanho, stdin) != NULL)
        {
            if (sscanf(buffer, "%d", &valor) == 1)
            {
                return valor;
            }
        }
    }
}

void exibir_cartas(int mao[10], int esconder_ultima)
{
    const char *nomes[13] = {
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
    };
    int i = 0;
    if(esconder_ultima == 1)
    {
        while (mao[i] != 67)
        {
            i++;
        }
        for (int j = 0; j < i - 1; j++)
        {
            printf("%-3s ", nomes[mao[j]]);
        }
        printf("%-3s ", "#");
    }
    else
    {
        while (mao[i] != 67)
        {
            printf("%-3s ", nomes[mao[i]]);
            i++;
        }
    }
}

void distribuir_duas(int baralho[13], int mao_jogador[10], int mao_dealer[10], int contador)
{
    int carta;
    carta = (rand() % 13);
    baralho[carta]--;
    mao_jogador[contador] = carta;
    carta = (rand() % 13);
    baralho[carta]--;
    mao_dealer[contador] = carta;
}

void comprar_carta(int baralho[13], int mao[10], int contador)
{
    int carta;
    while (1)
    {
        carta = (rand() % 13);
        if (baralho[carta] == 0)
        {
            continue;
        }
        baralho[carta]--;
        mao[contador] = carta;
        break;
    }
}

int calcular_mao(int mao[10])
{
    int total = 0, ases = 0, i = 0;
    while (mao[i] != 67)
    {
        int carta = mao[i];
        if(carta == 0)
        {
            total += 11;
            ases++;
        }
        else if(carta >= 10)
        {
            total += 10;
        }
        else
        {
            total += (carta + 1);
        }
        i++;
    }
    if(total > 21)
    {
        while(ases > 0)
        {
            total -= 10;
            ases--;
        }
        if(total > 21)
        {
            return 69;
        }
    }
    return total;
}
