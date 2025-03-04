#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de textos por região
#include <string.h> //biblioteca de strings

int inserir()
{	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Insira o CPF que será usado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Essa função copia as informações da variável CPF na variável arquivo. Abreviação de string copy
	
	FILE *file; //Criando o arquivo desejado
	file = fopen(arquivo, "w"); //criando e abrindo o arquivo.
	fprintf(file,cpf); //salvando o valor da variável
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //Abrindo com "a" porque o objetivo é add, adicionar ou atualizar informações	
	fprintf(file,","); //Essa vírgula é para ajudar na formatação do arquivo de texto
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
	scanf("%s",cpf); //Salvar as informações inseridas pelo usuário
	
	FILE *file;
	file = fopen(cpf,"r"); //Abrindo o arquivo para reading, leitura.
	
	if(file == NULL)
	{
		printf("Não foi possível localizar, não disponível.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //Buscando dentro do arquivo com tamanho máximo e que não seja nulo
	{
		printf("\nAqui estão as informações solicitadas: ");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	printf("Insira o CPF do usuário que deseja deletar: ");
	scanf("%s",cpf);
	
	remove(cpf); //função importada de bibliotecas para remover itens
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema.\n");
		system("pause");
	}
	
	else
	{
		printf("Usuário deletado com sucesso.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int loop=1;
	
	for(loop=1;loop=1;)
	{
	
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //Definindo idioma usado no programa
		
		
		printf("---Cartório da EBAC---\n\n"); //início do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar os nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Qual sua opção? ");  //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); //Limpa a tela para que o usuário não tenha que ver o menu toda vez
		
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
			printf("Essa não é uma opção válida, tente novamente\n");
			system("pause"); //Fim das opções do usuário
			break;
		}
		
	}
}
