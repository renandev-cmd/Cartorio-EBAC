#include <stdio.h> //Biblioteca de Comunica��o (IN/OUT)
#include <stdlib.h> //Biblioteca de Aloca��o de Memoria
#include <locale.h> //Biblioteca de linguagem
#include <string.h> 
int main() //Fun��o "principal" (inteira)
{
	
	int escolha=0; //Variavel "escolha" (inteira)
	int loop=1; //Variavel "loop" (inteira), para voltar pro inicio da pagina sempre
	
	for(loop=1;loop=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Setando linguagem para portugues
	
		printf("\t\nBanco de Nomes EBAC\n\nEscolha a op��o desejada:\n\n\t1 - Registrar Nome\n\t2 - Consultar Nome\n\t3 - Deletar Nome\n\nDigite aqui:"); //Menu de op��es
	
		scanf ("%d", &escolha); //Scanear a tela para aguardar um input do usuario
	
		system("cls"); //Limpar a tela ap�s alguma escolha
		
		switch(escolha) //Switch case
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("\n\tEssa op��o n�o esta dispon�vel\t\n\n");
			system("pause");
			break;	
		}	
		}
}

int registrar() //Fun��o "Registro"
	{		
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[30];
	char cpf[30];
	char nome[30];
	char sobrenome[30];
	char cargo[30];	
								
		printf("\nDigite o CPF a ser cadastrado:\n");
		
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf);
	
		FILE *file; //Criando o arquivo
		file = fopen(arquivo, "w"); //Abrindo e "escrevendo" novo arquivo
		fprintf(file, cpf); //Salvando a informa��o
		fclose(file); //Fechando arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("\nDigite o NOME a ser cadastrado:\n");
		scanf("%s", nome);
		
		file = fopen(arquivo, "a");
		fprintf(file, nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, "_");
		fclose(file);
		
		printf("\nDigite o SOBRENOME a ser cadastrado:\n");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("\nDigite o CARGO a ser cadastrado:\n");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		
		
	}

int consultar() //Fun��o "Consulta"
	{
	char cpf[30];
	char conteudo[200];
	char nome[30];
	char sobrenome[30];
	char cargo[30];
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\nDigite o CPF a ser consultado:\n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file == NULL)	
	{
		printf("\nN�o foi possivel abrir o arquivo,n�o localizado!\n\n");
		system("pause");
	}
	
	while(fgets(conteudo, 200, file) != NULL)	
	
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
		printf("%s", conteudo);	
		printf("\n\n");	
		system("pause");
	}
	fclose(file);
	}

int deletar() //Fun��o "Delete"
	{
	char cpf[30];
	char conteudo[200];
	int decisao=0;

	printf("Qual usu�rio deseja deletar?");
	scanf("%s", cpf);	
	
	FILE *file;
	file = 	fopen(cpf, "r");

	if(file == NULL)
	{
	printf("Usu�rio n�o encontrado!\n");
	system("pause");
	main();
	}
	else(file != NULL); 
	{
	printf("Tem certeza que deseja deletar esse usu�rio?\n");
	fgets(conteudo, 200, file);
	printf("%s", conteudo);
	printf("\n");
	printf("1 - Sim\n2 - N�o\n");
	scanf("%d", &decisao);
	fclose(file);
		if(decisao == 1)
		{	
		remove(cpf);
		printf("O usu�rio foi deletado!\n");			
		system("pause");
		}		
		else(decisao == 2);
		{
		system("cls");
		main();
		};
	}
	}
