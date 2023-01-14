#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região do globo
#include <string.h> //biblioteca de strings

	int funcRegistrar() //criando função de registrar aluno. Função chamada no case 1 do switch-case da função main
	{
		char arquivo[40]; //criando variável CHAR para cada campo a ser preenchido pelo usuário. O valor entre [] é o máximo de caracteres disponíveis
		char cpf[11]; 
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Você escolheu registro de EBACer! \n\n");
		printf("Por favor, digite apenas os números do CPF: ");
		scanf("%s", cpf); //scanf é tipo um input, que está salvando uma STRING (%s) na variável CPF
		
		strcpy(arquivo, cpf); //strcpy coloca os valores na variável arquivo que foram copiados da variável cpf
		
		FILE *file; //função do sistema chamada FILE cria um file
		file = fopen(arquivo,"w"); //abre o file com o nome do conteúdo da variável arquivo no modo gravação "w" (write). Como o file não existia, ele foi criado nesse comando com o nome do que estava contido na variável arquivo
		fprintf(file,"CPF: "); //"imprime" no file nomeado a partir das informações da variável cpf o texto "CPF:" apenas por questão estética para facilitar a visualização
		fclose(file);

		file = fopen(arquivo,"a"); //abre o file de nome arquivo no modo "a" (append)		
		fprintf(file,cpf); //"imprime" informação no file (Fprintf) as informações contidas na variável cpf
		fclose(file); //fecha o file
		
		
		
		printf("\nDigite o nome que deseja registrar: ");
		scanf("%s",nome);
		
		file = fopen(arquivo,"a");
		fprintf(file," Nome: ");
		fclose(file);
		
		file = fopen(arquivo,"a");
		fprintf(file,nome);
		fclose(file);
		
		
		
		printf("\nDigite o sobrenome que deseja registrar: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo,"a");
		fprintf(file," Sobrenome: ");
		fclose(file);
		
		file=fopen(arquivo,"a");
		fprintf(file,sobrenome);
		fclose(file);
		
		
		
		printf("\nDigite o cargo desse EBACer: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo,"a");
		fprintf(file," Cargo: ");
		fclose(file);
		
		file=fopen(arquivo,"a");
		fprintf(file,cargo);
		fclose(file);
		
		
		system("pause"); //chama o comando "pause" diretamente do sistema operacional, que acaba pausando a tela
	}
	
	int funcProcurar() //criando função de procurar aluno. Função chamada no case 2 do switch-case da função main
	{
		setlocale(LC_ALL, "portuguese"); //apesar de já existir na função main, deve-se configurar em cada função
		
		char cpf[11]; //declarar a variável que será usada para armazenar a resposta do usuário
		char conteudo[200]; //variável que armazenará e mostrará todo o conteúdo do banco de dados
		
		printf("Você escolheu procurar EBACer! \n\n");
		printf("Por favor, digite apenas os números do CPF do EBACer que deseja encontrar: ");
		scanf("%s", cpf); //scaneou a informação fornecida pelo usuário e salvou na variável cpf
		
		FILE *file;
		file=fopen(cpf,"r"); //no modo leitura somente ("r" - reading), o sistema tenta abrir um file com o mesmo nome fornecido pelo usuário na pergunta anterior e armazenado na variável cpf
		
		if(file == NULL) //condicionante para validação da pesquisa feita pelo usuário - se o nome do arquivo não encontrar retorno, então mensagem de erro
		{
			printf("Desculpa, mas não conseguimos encontrar esse CPF. Por favor, tente novamente.");
		}
		
		while(fgets(conteudo,200,file) != NULL)
		{
			printf("\nEssas foram as informações encontradas: \n");
			printf("%s", conteudo);
			printf("\n");
		}
		system("pause");
	}

	int funcDeletar() //criando função de deletar aluno. Função chamada no case 3 do switch-case da função main.
	{
		char cpf[11];
		
		printf("Você escolheu deletar cadastro de EBACer! \n\n");
		printf("Digite somente os números do CPF do usuário a ser deletado: ");
		scanf("%s", cpf);
		
			FILE * file;
			file = fopen(cpf,"r");
			fclose(file); //muito importante fechar o arquivo antes de fazer a validação e a consequente remoção do mesmo
			
		if(file != NULL) //se o PONTEIRO do arquivo existir (não for nulo), então...
		{
			remove(cpf); //remova o arquivo de cpf indicado pelo usuário
			printf("Usuário deletado com sucesso!\n");
			system("pause");
		}
		else //se não (ou seja, se o ponteiro for nulo porque o arquivo não foi encontrado), mensagem de erro
		{
			printf("Usuário não encontrado. Por favor, tente novamente.\n");
			system("pause");
		}
		

	}
	
	
	
	int main() //função principal, tem prioridade na execução, por isso pode vir depois de outras funções
	{
	
	int numMenu=0; //declarando variável que armazenará a escolha do usuário
	
	int loopMenu=1; //declarar variável que será utilizada no laço
	for (loopMenu=1; loopMenu=1;) //macete de laço "infinito": o valor é 1 e deve continuar enquanto o valor continuar sendo 1
	{
		
	setlocale(LC_ALL, "portuguese"); //chamando e configurando a biblitoeca <locale.h> para utilizar o texto com caracteres do português
	
	printf("(((CADASTRO DE EBACERS)))\n\n");  // o \t serve para dar um espaço (tab) e o \n para quebra de linha
	printf("Escolha uma das opções:\n");
	printf("\t1) Registrar EBACer\n");
	printf("\t2) Procurar EBACer\n");
	printf("\t3) Deletar cadastro de EBACer\n");
	printf("\t4) Sair do sistema\n\n");
	
	printf("Digite o número: ");
	scanf("%d", &numMenu); // "scanf" é tipo um input para int, que nesse caso está sendo salva na variável 'numMenu'
	
	system("cls"); //chama o comando "cls" diretamente do sistema operacional, que acaba limpando a tela
	
	switch(numMenu)
	{
		case 1:
			funcRegistrar();
			break; //força a saída de um switch case - por isso "break;" PRECISA estar dentro de um loop ou switch-case.
			
		case 2:
			funcProcurar();
			break;
			
		case 3:
			funcDeletar();
			break;
			
		case 4:
			printf("Você optou por sair do sistema.\n");
			return 0;
			break;
		
		default: //praticamente um ELSE
			printf("Opção inválida, por favor tente novamente. \n\n");
			system("pause");
			break;
	}
	
	system("cls");
}
}
