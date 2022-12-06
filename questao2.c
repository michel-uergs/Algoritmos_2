#include <stdio.h>
#include <stdlib.h>

typedef struct func
{
    int cod;
    float sal;
    struct func *next;
}func;

void imprimi(func **lista)
{
    func *aux;

    aux = *lista;
    
    while (aux != NULL)
    {
        printf("\nCODIGO: %d",aux->cod);
        printf("\nSALARIO: %.2f", aux->sal);
        aux = aux->next;
    }
    
}

void insere(func **lista, int codigo, float salario)
{
    func *novo, *percorre, *percorre2, *aux;
    int continua=1;

    novo = (func*) malloc(sizeof(func));
    if (novo==NULL)
    {
        printf("\nERRO NA MEMORIA");
    }
    novo->cod = codigo;
    novo->sal = salario;
    novo->next = NULL;

    if (*lista == NULL)
    {
        *lista = novo;
        continua = 0;
    }
    else
    {
    
        percorre = *lista;
        //insere inicio
        if (percorre->sal > novo->sal && continua)
        {
            novo->next = percorre;
            percorre = novo;
            *lista = novo;
            continua = 0;
        }
        
        //insere meio
        percorre2 = percorre;
        while (percorre->next != NULL )
        {
            if (percorre->sal > novo->sal)
            {
                novo->next = percorre;
                percorre2->next = novo;
                continua = 0;
            }
            percorre2 = percorre;
            percorre = percorre->next; 
        }
        
        if (continua)
        {
            percorre->next = novo;
        }
        
    }
}

int main()
{
    int codigo=0, cont=1;
    float salario;
    func *lista;

    lista = NULL;

    while (cont)
    {
        printf("\ndigite o salario do funcionario: ");
        scanf("%f",&salario);

        insere(&lista, codigo, salario);
        
        printf("\ndigite se quer continuar sim[1] nao[0]: ");
        scanf("%d",&cont);
        codigo++;
    }
    
    imprimi(&lista);

    return 0;
}


/*
Elabore um programa que armazene o código do funcionário (sequencial e sem repetição) 
e o salário do último mês em uma lista simplesmente encadeada. A inserção deve ser em 
ordem crescente de salário. A quantidade de funcionários deve ser controlada pelo usuário 
do programa. A cada inserção deve-se verificar a posição a ser inserido o novo funcionário 
devido ao valor do salário (que pode ser no início, no meio ou no fim). Sugiro que inclua 
uma função de impressão da lista para facilitar seu teste. 
Observe que não serão avaliados programas que não tenham utilizado lista encadeada.

*/