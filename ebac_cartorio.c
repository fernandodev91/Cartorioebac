#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca de alocação de string

int registrar() //Função responsável por cadastrar os usuários
{
	char arquivo[40]; //inicio da criação das variaveis/strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // Final da criação das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); // %s Refere-se a strings
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
	FILE *file; //cria o arquivo
	
	file = fopen(arquivo, "w"); // abertura, arquivo de escrita
	fprintf(file, "\nCPF: ");
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // atualizar
	fprintf(file,"\nNOME: "); //colocou virgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, "\nSOBRENOME: "); 
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" , sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, "\nCARGO: "); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" ,cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file,"\n\n");
	fclose(file);
	
}

int consultar()
{
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nArquivo não localizado!\n\n\n");
	}
	
	if(file != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
	}

	
	while(fgets(conteudo, 200, file) != NULL)
	{
		
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");
	
	fclose(file);
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s" ,cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("\n**Usuário deletado com sucesso!**\n\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n"); 
		printf("Digite a opção: ");  //Fim do menu
	
		scanf("%d" , &opcao); // Armazenando a escolha do usuário
	
		system("cls"); // limpar tela
		
		switch(opcao)
		{
			case 1:
			registrar(); //chamada de funções
			break;
				
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!\n"); 
			system("pause");
			break;
					
		}
	
	}
		
}
