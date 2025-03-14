#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // respons�vel por aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // funcao responsavel por registro
{
	//inicio criacao de de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); 
	fprintf(file,cpf); 
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[100];
	
	printf("digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado!\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas sao as informacoes do usuario.");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()

{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *(file);
	file = fopen(cpf,"r");
		
	if(file == NULL)
	{
		printf("Usuario n�o se encontra no sistema.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo as vari�veis 
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagen
		
		printf("### Cart�rio EBAC ### \n\n"); // in�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); // fim do menu
		
		scanf("%d", &opcao); //salvando informa��es
					
		system("cls");
			
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2: 
			consulta();
			break;
				
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por tulizar o sistema!\n");
			return 0;
			break;
					
			
			default:
				printf("Essa op��o n�o est� dispon�vel! Tente novamente\n");
				system("pause");
			break;
		}
	
	}	
}
