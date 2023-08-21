#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de testo por região
#include <string.h> // biblioteca responsável por cuidar dos string

int registro()
{
    char arquivo[50];
    char cpf[50];
    char nome[50];
    char sobrenome[50];
    char cargo[50];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); //responsável por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //"w" - write, cria o arquivo
    fprintf(file,cpf); //salvo o valor da variável
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // "a" de atualização
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // "a" de atualização
    fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // "a" de atualização
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a"); 
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a"); // "a" de atualização
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    file = fopen(arquivo, "a"); // "a" de atualização
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
    	printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");	
	
	
}

int deletar()
{
    printf("Você escolheu deletar os nomes!\n");
    system("pause");
}

int main()
{
    int opcao=0; //definido variáveis
    int laco=1;
    
    for (laco=1;laco=1;)
    {
        system ("cls");
        
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem, idioma
        
        printf("### Cartório da EBAC ###\n\n"); // início do menu
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Opção: ");//fim do menu
        
        scanf("%d", &opcao); //armazenando a escolha do usuário
        
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
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
        } //fim da seleção
    }
}
