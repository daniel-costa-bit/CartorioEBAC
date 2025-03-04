#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de textos por regi�o
#include <string.h> //biblioteca de strings

int inserir()
{	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Insira o CPF que ser� usado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Essa fun��o copia as informa��es da vari�vel CPF na vari�vel arquivo. Abrevia��o de string copy
	
	FILE *file; //Criando o arquivo desejado
	file = fopen(arquivo, "w"); //criando e abrindo o arquivo.
	fprintf(file,cpf); //salvando o valor da vari�vel
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo com "a" porque o objetivo � add, adicionar ou atualizar informa��es	
	fprintf(file,","); //Essa v�rgula � para ajudar na formata��o do arquivo de texto
	fclose(file);
	
	printf("Insira o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Agora insira o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Agora conta pra gente qual seu cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo idioma usado no programa
	char cpf[40];
	char conteudo[200];
	
	printf("Insira o CPF a ser consultado: ");
	scanf("%s",cpf); //Salvar as informa��es inseridas pelo usu�rio
	
	FILE *file;
	file = fopen(cpf,"r"); //Abrindo o arquivo para reading, leitura.
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar, n�o dispon�vel.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //Buscando dentro do arquivo com tamanho m�ximo e que n�o seja nulo
	{
		printf("\nAqui est�o as informa��es solicitadas: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	printf("Insira o CPF do usu�rio que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf); //fun��o importada de bibliotecas para remover itens
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}
	
	else
	{
		printf("Usu�rio deletado com sucesso.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int loop=1;
	
	for(loop=1;loop=1;)
	{
	
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //Definindo idioma usado no programa
		
		
		printf("---Cart�rio da EBAC---\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar os nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Qual sua op��o? ");  //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //Limpa a tela para que o usu�rio n�o tenha que ver o menu toda vez
		
		switch(opcao)
		{
			case 1:
			inserir();
			break; //Ele exibe a mensagem "Pressione qualquer tecla para continuar"
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por usar o sistema da EBAC.");
			return 0;
			break;
			
			default:
			printf("Essa n�o � uma op��o v�lida, tente novamente\n");
			system("pause"); //Fim das op��es do usu�rio
			break;
		}
		
	}
}
