#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct variaveis
{
    char matriz[30][10][50];
    int posicao;
};
void cadastro(char matriz[30][10][50], int *posicao)
{
    system("CLS");
    printf("----------Cadastrar----------\n");

    fflush(stdin);
    printf("\nInforme seu codigo: ");
    fgets(matriz[*posicao][0], 50, stdin);
    printf("Informe seu fabricante: ");
    fgets(matriz[*posicao][1], 50, stdin);
    printf("Informe seu modelo: ");
    fgets(matriz[*posicao][2], 50,stdin);
    printf("Informe o consumo medio (km/l): ");
    fgets(matriz[*posicao][3],50,stdin);
    printf("Informe o ano de fabricacao: ");
    fgets(matriz[*posicao][4],50,stdin);
    printf("Informe o status: ");
    fgets(matriz[*posicao][5],50,stdin);
    printf("Informe o numero do cliente: ");
    fgets(matriz[*posicao][6],50,stdin);
    printf("Informe a data de locacao: ");
    fgets(matriz[*posicao][7],50,stdin);
    printf("Informe a data de devolucao: ");
    fgets(matriz[*posicao][8],50,stdin);
    printf("Informe o valor da diaria: ");
    fgets(matriz[*posicao][9],50,stdin);
    *posicao += 1;
}
void consultar(char matriz[30][10][50], int *posicao)
{
    system("CLS");
    printf("----------Consultar----------\n");

    printf("1 - Pesquisar\n2 - Mostrar Todos\n");
    int menu = 0;scanf("%d",&menu);

    switch(menu)
    {
    case 1:
            printf("Informe o codigo a ser pesquisado: ");
            char codigo[50];
            fflush(stdin);
            fgets(codigo, 50, stdin);

            for (int i = 0; i < 30; i++)
            {
                if (strstr(matriz[i][0], codigo) != NULL)
                {
                    printf("\n\n Codigo : %s Fabricante : %s Modelo : %s consumo medio : %s ano de fabricacao : %s status : %s numero do cliente : %s data de locacao : %s data de devolucao : %s valor da diaria : %s ",matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],matriz[i][5],matriz[i][6],matriz[i][7],matriz[i][8],matriz[i][9],matriz[i][10]);
                }
            }
        break;
    case 2:
        for(int i = 0; i < *posicao;i++)
        {
            printf("\n\n Codigo : %s Fabricante : %s Modelo : %s consumo medio : %s ano de fabricacao : %s status : %s numero do cliente : %s data de locacao : %s data de devolucao : %s valor da diaria : %s ",matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],matriz[i][5],matriz[i][6],matriz[i][7],matriz[i][8],matriz[i][9],matriz[i][10]);
        }
        break;
    default:
        printf("\n Codigo invalido !!\n");
        break;
    }
}
void alterar(char matriz[30][10][50])
{
    system("CLS");
    printf("----------Alterar----------\n");

            printf("Informe o codigo : ");
            char codigo[50];
            fflush(stdin);
            fgets(codigo, 50, stdin);

            for (int i = 0; i < 30; i++)
            {
                if (strstr(matriz[i][0], codigo) != NULL)
                {
                    printf("\n\n Codigo : %s Fabricante : %s Modelo : %s consumo medio : %s ano de fabricacao : %s status : %s numero do cliente : %s data de locacao : %s data de devolucao : %s valor da diaria : %s ",matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],matriz[i][5],matriz[i][6],matriz[i][7],matriz[i][8],matriz[i][9],matriz[i][10]);

                    printf("\nSelecione o campo a ser alterado : \n\n 0 - Codigo\n 1 - Fabricante\n 2 - Modelo\n 3 - consumo medio\n 4 - ano de fabricacao\n 5 - status\n 6 - numero do cliente\n 7 - data de locacao\n 8 - data de devolucao\n 9 -valor da diaria\n");
                    int j ; scanf("%d",&j);
                    printf("\n Valor atual : %s\n",matriz[i][j]);
                    printf(" Informe o novo valor :  ");
                    fflush(stdin);
                    fgets(matriz[i][j], 50,stdin);

                    system("CLS");

                    printf(" \n Valor alterado!!!\n");
                }
            }
}
void excluir(char matriz[30][10][50], int *posicao)
{
    system("CLS");
    printf("----------Excluir----------\n");

            printf("Informe o codigo : ");
            char codigo[50];
            fflush(stdin);
            fgets(codigo, 50, stdin);
            for (int i = 0; i < 30; i++)
            {
                if (strstr(matriz[i][0], codigo) != NULL)
                {
                    printf("\n\n Codigo : %s Fabricante : %s Modelo : %s consumo medio : %s ano de fabricacao : %s status : %s numero do cliente : %s data de locacao : %s data de devolucao : %s valor da diaria : %s ",matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],matriz[i][5],matriz[i][6],matriz[i][7],matriz[i][8],matriz[i][9],matriz[i][10]);

                    printf("\n\nDeseja excluir esse cadastro ?\n  1 - Sim\n  2 - Nao");
                    int rep; scanf("%d",&rep);
                    if(rep == 1)
                    {
                        for(i; i < 30; i++)
                        {
                            for(int j = 0; j < 10;j++)
                            {
                                strcpy(matriz[i][j],matriz[i+1][j]);
                            }
                        }
                        *posicao -= 1;
                        printf("\nCadastro excluido !!\n");
                    }
                }

            }

}
void arquivar(char matriz[30][10][50], int*posicao)
{
    FILE *ponteiro_arquivo;

    ponteiro_arquivo = fopen("relatorio.txt","w");

    if(ponteiro_arquivo == NULL)
    {
        printf("\n  Erro ao abrir arquivo!!\n");
    }
    else
    {
        for(int i = 0; i < *posicao;i++)
        {
            fprintf(ponteiro_arquivo,"\n\n Codigo : %s Fabricante : %s Modelo : %s consumo medio : %s ano de fabricacao : %s status : %s numero do cliente : %s data de locacao : %s data de devolucao : %s valor da diaria : %s ",matriz[i][0],matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],matriz[i][5],matriz[i][6],matriz[i][7],matriz[i][8],matriz[i][9],matriz[i][10]);
        }
        fclose(ponteiro_arquivo);
        printf(" \n Dados gravados com sucesso!!");
    }
}
int main()
{
    struct variaveis struct_variaveis;
    struct_variaveis.posicao = 0;

    int repeticao = 0;
    while(repeticao == 0)
    {
        printf("----------Menu----------");
        printf("\n\n 1 - Cadastrar\n 2 - Consultar\n 3 - Alterar dados\n 4 - Excluir dados\n 5 - Criar arquivo\n");
        int menu = 0; scanf("%d",&menu);

        switch(menu)
        {
        case 1:
                cadastro(&struct_variaveis.matriz, &struct_variaveis.posicao);
            break;
        case 2:
                consultar(struct_variaveis.matriz, &struct_variaveis.posicao);
            break;
        case 3:
                alterar(&struct_variaveis.matriz);
            break;
        case 4:
                excluir(&struct_variaveis.matriz, &struct_variaveis.posicao);
            break;
        case 5:
                arquivar(&struct_variaveis.matriz, &struct_variaveis.posicao);
            break;
        default:
            printf("\nCodigo invalido!!\n");
            break;
        }

        fflush(stdin);
        printf("\n0 - Continuar\n1 - Sair\n");
        repeticao = 1;scanf("%i",&repeticao);
        system("CLS");
    }
    return 0;
}

