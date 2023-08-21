#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de testo por regi�o
#include <string.h> // biblioteca respons�vel por cuidar dos string

int registro()
{
    char arquivo[50];
    char cpf[50];
    char nome[50];
    char sobrenome[50];
    char cargo[50];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //"w" - write, cria o arquivo
    fprintf(file,cpf); //salvo o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // "a" de atualiza��o
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // "a" de atualiza��o
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // "a" de atualiza��o
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a"); 
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // "a" de atualiza��o
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    file = fopen(arquivo, "a"); // "a" de atualiza��o
    fprintf(file, ",");
    fclose(file);
    
    system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem, idioma
	
	char cpf [50];
	char conteudo[200];
	
    printf("Digite o CPF a ser consultado: \n");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); // "r" de read
    
    if(file == NULL)
    {
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	
	
	
}

int deletar()
{
    printf("Voc� escolheu deletar os nomes!\n");
    system("pause");
}

int main()
{
    int opcao=0; //definido vari�veis
    int laco=1;
    
    for (laco=1;laco=1;)
    {
        system ("cls");
        
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem, idioma
        
        printf("### Cart�rio da EBAC ###\n\n"); // in�cio do menu
        printf("Escolha a op��o desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Op��o: ");//fim do menu
        
        scanf("%d", &opcao); //armazenando a escolha do usu�rio
        
        system("cls");
        
        switch (opcao)
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
                
            default:
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        } //fim da sele��o
    }
}
