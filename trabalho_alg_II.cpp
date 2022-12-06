#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmosII.cpp"

using namespace std;

typedef struct RECLAMACAO
{
    char cpf[12], tel[10], email[80], reclamacao[256];
}RECLAMACAO;

void Cadastro_Reclamacao(FILE *Cad)
{
    RECLAMACAO cadastro_pessoa;
    int opcao;
    
    //CPF
    fflush(stdin);
    printf("\ndigite seu cpf: ");
    scanf("%11s",cadastro_pessoa.cpf);
    fflush(stdin);
    while (MODULO_ONZE(cadastro_pessoa.cpf))
    {
        fflush(stdin);
        printf("\ndigite um cpf VALIDO: ");
        scanf("%11s",cadastro_pessoa.cpf);
        fflush(stdin);
    }

    //TELEFONE 
    fflush(stdin);
    printf("\ndigite seu numero de telefone: ");
    scanf("%9s",cadastro_pessoa.tel);
    fflush(stdin);
    while (VALIDA_TEL(cadastro_pessoa.tel))
    {
        fflush(stdin);
        printf("\ndigite um numero de telefone VALIDO: ");
        scanf("%9s",cadastro_pessoa.tel);
        fflush(stdin);
    }

    //EMAIL
    fflush(stdin);
    printf("\ndigite seu email: ");
    scanf("%80s",cadastro_pessoa.email);
    fflush(stdin);
    while (VALIDA_EMAIL(cadastro_pessoa.email))
    {
        fflush(stdin);
        printf("\ndigite uma email VALIDO: ");
        scanf("%80s",cadastro_pessoa.email);
        fflush(stdin);
        fflush(stdin);
    }

    //RECLAMACAO
    fflush(stdin);
    printf("\ndigite sua reclamacao: ");
    gets(cadastro_pessoa.reclamacao);
    fflush(stdin);
    if (strlen(cadastro_pessoa.reclamacao) < 255)
    {
        printf("\nVoce digitou %d caracteres quer digitar uma reclamcao maior? [1/0]\n", strlen(cadastro_pessoa.reclamacao));
        scanf("%d",&opcao);
        if (opcao==1)
        {
            fflush(stdin);
            printf("\ndigite sua reclamacao: ");
            gets(cadastro_pessoa.reclamacao);
            fflush(stdin);
        }
        
    }
    

    //INSERE ARQUIVO
    Cad = fopen("RECLAMACAO.txt","a+");
    if (Cad == NULL)
    {
        printf("\nERRO ao tentar abrir o arquvo! ");
    }
    else
    {
        printf("\narquivo aberto com sucesso! ");
        fprintf(Cad, "%s\n",cadastro_pessoa.cpf);
        fprintf(Cad, "%s\n",cadastro_pessoa.tel);
        fprintf(Cad, "%s\n",cadastro_pessoa.email);
        fprintf(Cad, "%s\n",cadastro_pessoa.reclamacao);
        fprintf(Cad, "--------------------------------------\n");
    }
    fclose(Cad);

    //TESTE PRINTF DO QUE TA ARMAZENADO NAS STRINGS
    printf("\n");
    printf("\nCPF: [%s]",cadastro_pessoa.cpf);
    printf("\nEMAIL: [%s]",cadastro_pessoa.email);
    printf("\nTELEFONE: [%s]",cadastro_pessoa.tel);
    printf("\nRECLAMACAO: %s",cadastro_pessoa.reclamacao);
    printf("\n");

}

/*
void imprimi_reclamacao(RECLAMACAO rec)
{
    printf("CPF: %s\n",rec.cpf);
    printf("TELEFONE: %s\n",rec.tel);
    printf("EMAIL: %s\n",rec.email);
    printf("RECLAMACAO: %s\n",rec.reclamacao);
}
*/

void mostra_arquivo(FILE *Cad)
{
    Cad = fopen("RECLAMACAO.txt","rt");
    
    if (Cad == NULL)
    {
        printf("\nERRO ao abrir o arquivo!");
    }
    else
    {
        printf("\nArquivo aberto com sucesso!");
        printf("\n");
        while (!feof(Cad))
        {
            RECLAMACAO Cadastro_Reclamacao;
            char quebra_linha[40];   
            
            //cpf
            fscanf(Cad, "%11s\n"    ,Cadastro_Reclamacao.cpf);
            fscanf(Cad, "%9s\n"     ,Cadastro_Reclamacao.tel);
            fscanf(Cad, "%80s\n"    ,Cadastro_Reclamacao.email);
            fgets(Cadastro_Reclamacao.reclamacao, 256, Cad);


            printf("\n");
            printf("CPF: %s\n",Cadastro_Reclamacao.cpf);
            printf("TELEFONE: %s\n",Cadastro_Reclamacao.tel);
            printf("EMAIL: %s\n",Cadastro_Reclamacao.email);
            printf("RECLAMACAO: %s\n",Cadastro_Reclamacao.reclamacao);
            printf("\n");

            fgets(quebra_linha, 40, Cad);
            printf("\n%s",quebra_linha);
        }
    }
    fclose(Cad);
}

int main(int argc, char const *argv[])
{
    FILE *Cadastro;
    int opcao=0;

    while (opcao != 3)
    {
        printf("\n      ---- MENU ----   ");
        printf("\n1- Cadastrar reclamacao");
        printf("\n2- Mostrar arquivo");
        printf("\n3- Fim\n [opcao]: ");
        scanf("%d",&opcao);

        switch (opcao)
        {
            case 1:
                Cadastro_Reclamacao(Cadastro);
                break;

            case 2:
                mostra_arquivo(Cadastro);
                break;

            case 3:
                printf("\nPrograma Encerrado! ");
                opcao = 3;
                break;
            
            default:
                printf("\nOPCAO INVALIDA!");
                break;
        }
    }
    return 0;
}
