#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o do globo
#include <string.h> //biblioteca de strings

	int funcRegistrar() //criando fun��o de registrar aluno. Fun��o chamada no case 1 do switch-case da fun��o main
	{
		char arquivo[40]; //criando vari�vel CHAR para cada campo a ser preenchido pelo usu�rio. O valor entre [] � o m�ximo de caracteres dispon�veis
		char cpf[11]; 
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Voc� escolheu registro de EBACer! \n\n");
		printf("Por favor, digite apenas os n�meros do CPF: ");
		scanf("%s", cpf); //scanf � tipo um input, que est� salvando uma STRING (%s) na vari�vel CPF
		
		strcpy(arquivo, cpf); //strcpy coloca os valores na vari�vel arquivo que foram copiados da vari�vel cpf
		
		FILE *file; //fun��o do sistema chamada FILE cria um file
		file = fopen(arquivo,"w"); //abre o file com o nome do conte�do da vari�vel arquivo no modo grava��o "w" (write). Como o file n�o existia, ele foi criado nesse comando com o nome do que estava contido na vari�vel arquivo
		fprintf(file,"CPF: "); //"imprime" no file nomeado a partir das informa��es da vari�vel cpf o texto "CPF:" apenas por quest�o est�tica para facilitar a visualiza��o
		fclose(file);

		file = fopen(arquivo,"a"); //abre o file de nome arquivo no modo "a" (append)		
		fprintf(file,cpf); //"imprime" informa��o no file (Fprintf) as informa��es contidas na vari�vel cpf
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
	
	int funcProcurar() //criando fun��o de procurar aluno. Fun��o chamada no case 2 do switch-case da fun��o main
	{
		setlocale(LC_ALL, "portuguese"); //apesar de j� existir na fun��o main, deve-se configurar em cada fun��o
		
		char cpf[11]; //declarar a vari�vel que ser� usada para armazenar a resposta do usu�rio
		char conteudo[200]; //vari�vel que armazenar� e mostrar� todo o conte�do do banco de dados
		
		printf("Voc� escolheu procurar EBACer! \n\n");
		printf("Por favor, digite apenas os n�meros do CPF do EBACer que deseja encontrar: ");
		scanf("%s", cpf); //scaneou a informa��o fornecida pelo usu�rio e salvou na vari�vel cpf
		
		FILE *file;
		file=fopen(cpf,"r"); //no modo leitura somente ("r" - reading), o sistema tenta abrir um file com o mesmo nome fornecido pelo usu�rio na pergunta anterior e armazenado na vari�vel cpf
		
		if(file == NULL) //condicionante para valida��o da pesquisa feita pelo usu�rio - se o nome do arquivo n�o encontrar retorno, ent�o mensagem de erro
		{
			printf("Desculpa, mas n�o conseguimos encontrar esse CPF. Por favor, tente novamente.");
		}
		
		while(fgets(conteudo,200,file) != NULL)
		{
			printf("\nEssas foram as informa��es encontradas: \n");
			printf("%s", conteudo);
			printf("\n");
		}
		system("pause");
	}

	int funcDeletar() //criando fun��o de deletar aluno. Fun��o chamada no case 3 do switch-case da fun��o main.
	{
		char cpf[11];
		
		printf("Voc� escolheu deletar cadastro de EBACer! \n\n");
		printf("Digite somente os n�meros do CPF do usu�rio a ser deletado: ");
		scanf("%s", cpf);
		
			FILE * file;
			file = fopen(cpf,"r");
			fclose(file); //muito importante fechar o arquivo antes de fazer a valida��o e a consequente remo��o do mesmo
			
		if(file != NULL) //se o PONTEIRO do arquivo existir (n�o for nulo), ent�o...
		{
			remove(cpf); //remova o arquivo de cpf indicado pelo usu�rio
			printf("Usu�rio deletado com sucesso!\n");
			system("pause");
		}
		else //se n�o (ou seja, se o ponteiro for nulo porque o arquivo n�o foi encontrado), mensagem de erro
		{
			printf("Usu�rio n�o encontrado. Por favor, tente novamente.\n");
			system("pause");
		}
		

	}
	
	
	
	int main() //fun��o principal, tem prioridade na execu��o, por isso pode vir depois de outras fun��es
	{
	
	int numMenu=0; //declarando vari�vel que armazenar� a escolha do usu�rio
	
	int loopMenu=1; //declarar vari�vel que ser� utilizada no la�o
	for (loopMenu=1; loopMenu=1;) //macete de la�o "infinito": o valor � 1 e deve continuar enquanto o valor continuar sendo 1
	{
		
	setlocale(LC_ALL, "portuguese"); //chamando e configurando a biblitoeca <locale.h> para utilizar o texto com caracteres do portugu�s
	
	printf("(((CADASTRO DE EBACERS)))\n\n");  // o \t serve para dar um espa�o (tab) e o \n para quebra de linha
	printf("Escolha uma das op��es:\n");
	printf("\t1) Registrar EBACer\n");
	printf("\t2) Procurar EBACer\n");
	printf("\t3) Deletar cadastro de EBACer\n");
	printf("\t4) Sair do sistema\n\n");
	
	printf("Digite o n�mero: ");
	scanf("%d", &numMenu); // "scanf" � tipo um input para int, que nesse caso est� sendo salva na vari�vel 'numMenu'
	
	system("cls"); //chama o comando "cls" diretamente do sistema operacional, que acaba limpando a tela
	
	switch(numMenu)
	{
		case 1:
			funcRegistrar();
			break; //for�a a sa�da de um switch case - por isso "break;" PRECISA estar dentro de um loop ou switch-case.
			
		case 2:
			funcProcurar();
			break;
			
		case 3:
			funcDeletar();
			break;
			
		case 4:
			printf("Voc� optou por sair do sistema.\n");
			return 0;
			break;
		
		default: //praticamente um ELSE
			printf("Op��o inv�lida, por favor tente novamente. \n\n");
			system("pause");
			break;
	}
	
	system("cls");
}
}
