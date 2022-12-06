#include <stdio.h>
#include <stdlib.h>

typedef struct produto
{
    int codigo;
    int qtd_comprar;
    int preco;
    int disponivel;
}produto;

void insere()
{
    FILE *cad;
    produto novo;

    printf("\ncodigo do produto: ");
    scanf("%d",&novo.codigo);
    printf("\nquantidade a ser comprada: ");
    scanf("%d",&novo.qtd_comprar);
    printf("\npreco do produto: ");
    scanf("%d",&novo.preco);
    printf("\nesta disponivel sim[1] ou nao[0]: ");
    scanf("%d",&novo.disponivel);

    cad = fopen("lista_mercado.txt", "a+");
    
    if (cad == NULL)
    {
        printf("\nERRO na abertura do arquivo");
    }
    else
    {
        fprintf(cad, "%d", novo.codigo);
        fprintf(cad, "%d", novo.preco);
        fprintf(cad, "%d", novo.qtd_comprar);
        fprintf(cad, "%d", novo.disponivel);
    }

    fclose(cad);
}

void insere_situacao()
{
    
}

int main()
{
    FILE *CAD;
    int op;

    do
    {
        printf("\n---MENU---");
        printf("\n1- Insere item na lista de compras ");
        printf("\n2- Insere situação (disponível ou em falta)");
        printf("\n3- Valor do item ");
        printf("\n4- Imprime a lista de compras");
        printf("\n5- Fim");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            insere();
            break;

        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        default:
            break;
        }

    } while (op!=5);

    return 0;
}


/*
1) Desenvolva um programa que controle as compras do supermercado. 
Para isso deve-se inserir os itens da lista de compras em um arquivo. 
Você irá armazenar o produto (pode ser código ou nome) e a quantidade 
a ser comprada. Durante a compra o arquivo deve ser atualizado com a 
informação sobre o preço do item e se ele estava disponível ou não no 
mercado. Você deve implementar um menu:

1-   Insere item na lista de compras 

2-   Insere situação (disponível ou em falta)

3-   Valor do item 

4 -  Imprime a lista de compras

5 - Fim
*/