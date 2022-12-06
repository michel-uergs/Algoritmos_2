#include <stdio.h>
#include <stdlib.h>


typedef struct paciente

{
   char nome[30];
   int idade;
   int peso;
}cadpaciente;

int main()
{

    int qtd_pecientes;

    printf("\ndigite a quantidade de pacientes: ");
    scanf("%d",&qtd_pecientes);

    cadpaciente lista[qtd_pecientes];

    for (int i = 0; i<qtd_pecientes ; i++)
    {
        printf("\ndigite o nome do paciente: ");
        scanf("%s",&lista[i].nome);
        printf("\ndigite a idade do paciente: ");
        scanf("%d",&lista[i].idade);
        printf("\ndigite o peso do paciente: ");
        scanf("%d",&lista[i].peso);
    }
    
    for (int i = 0; i<qtd_pecientes ; i++)
    {
        for (int o = 0; o <qtd_pecientes ; o++)
        {
            if (lista[i].peso > lista[o].peso)
            {
                cadpaciente aux;
                aux = lista[i];
                lista[i] = lista[o];
                lista[o] = aux;
            }
            
        }
        
    }
    
    for (int i=0; i<qtd_pecientes; i++)
    {
        printf("\nnome do paciente: %s", lista[i].nome);
        printf("\nidade do paciente: %d", lista[i].idade);
        printf("\npeso do paciente: %d", lista[i].peso);
        printf("\n----------------------------------");
    }
    

    return 0;
}

/*
3) Você deverá implementar um programa para controlar os pacientesde uma clinica, 
a capacidade (quantidade de pacientes) deve ser informada pelo usuário. 
Utilize a struct definida abaixo:

typedef struct paciente

{
   char nome[30];
   int idade;
   int peso;
}cadpaciente;

 Escreva um programa que cadastra os pacientes (preenchendo as informações do cadastro), 
 posteriormente ordene a estrutura em ordem decrescente de peso. 
 Use obrigatoriamente um algoritmo de ordenação rápida. 
 Use obrigatoriamente uma função para para a impressão.
*/