#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// RETORNA 0 CASO VALIDADO!
int MODULO_ONZE(char cpf[12])
{
	int digito_1=0, digito_2=0, rst_div, VALIDADO=1;

	
	if( cpf[0] == cpf[1] == cpf[2] == cpf[3] == cpf[4] == cpf[5] == cpf[6] == cpf[7] == cpf[8] == cpf[9] == cpf[10] ) 
	{
		return VALIDADO;
	}
	
	//CAST CHAR TO INT
	for (int i=0; i<12 ; i++)
	{
		cpf[i] = cpf[i] - '0';
	}

	//CALCULA O DIGITO 1
	for (int i=0,j=10 ; i<9 ; i++,j--)
	{
		digito_1 = digito_1 + cpf[i]*j;
	}

	rst_div = digito_1 % 11;
	
	if (rst_div<2)
	{
		digito_1 = 0;
	}
	else
	{
		digito_1 = 11 - rst_div;
	} 
	
	//CALCULA O DIGITO 2
	for (int i=0,j=11; i<9 ; i++,j--)
	{
		digito_2 = digito_2 + cpf[i]*j;
	}
	digito_2 = digito_2 + digito_1*2;

	rst_div = digito_2 % 11;

	if (rst_div<2)
	{
		digito_2 = 0;
	}
	else
	{
		digito_2 = 11 - rst_div;
	} 

	//COMPARA OS DIGITOS
	if (digito_1==cpf[9] && digito_2==cpf[10])
	{
		VALIDADO = 0;
	}
	else
	{
		VALIDADO = 1;
	}

	//COMPARAR SE TODOS OS CARACTERES SAO IGUAIS
	
	//CAST INT TO CHAR
	for (int i=0; i<12 ; i++)
	{
		cpf[i]=cpf[i]+'0';
	}

	return VALIDADO;
}

// RETORNA 0 CASO VALIDADO!
int VALIDA_TEL(char tel[10])
{
	int VALIDADO=0;

	if (tel[0]!=57)
	{
		VALIDADO=1;
	}
	
	for (int i=0 ; i<9 ; i++)
	{
		if ( tel[i]>=48 && tel[i]<=57 && VALIDADO==0)
		{
			VALIDADO = 0;
		}
		else
		{
			VALIDADO = 1;
		}
	}
	
	return VALIDADO;
}

// RETORNA 0 CASO VALIDADO!
int VALIDA_EMAIL(char email[80])
{
	int VALIDADO=0, count_arroba=0, count_point=0;
	
	//CONTA ARROBA E PONTO 
	for (int i=0; i<strlen(email) ; i++)
	{
		if(email[i] == '@')
		{
			count_arroba++;
		}
		if(email[i] == '.')
		{
			count_point++;
		}
	}
	
	if (count_arroba == 1 && count_point >= 1)
	{
		VALIDADO = 0;
	}
	else
	{
		VALIDADO = 1;
	}
	
	return VALIDADO;
}

