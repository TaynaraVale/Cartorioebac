#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de testo por regi�o
#include <string.h> // biblioteca respons�vel por cuidar dos string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
    //in�cio cria��o de vari�veis/string
    char arquivo[50];
    char cpf[50];
    char nome[50];
    char sobrenome[50];
    char cargo[50];
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
    scanf("%s", cpf); //refere-se a string, faz o armazenamento do cpf
    
    strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //"w" - write, cria o arquivo
    fprintf(file,cpf); //salvo o valor da vari�vel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // "a" de atualiza��o
    fprintf(file, ",");
    fclose(file);// fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);//refere-se a string, faz o armazenamento do nome
    fclose(file);// fecha o arquivo
    
    file = fopen(arquivo, "a"); // "a" de atualiza��o
    fprintf(file, ",");
    fclose(file);// fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);//refere-se a string, faz o armazenamento do sobrenome
    
    file = fopen(arquivo, "a"); // "a" de atualiza��o
    fprintf(file, ",");
    fclose(file);// fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);//refere-se a string, faz o armazenamento do cargo
    
    file = fopen(arquivo, "a"); // "a" de atualiza��o
    fprintf(file, ",");
    fclose(file);// fecha o arquivo
    
    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, Portuguese); //definindo a linguagem, idioma
    
    //in�cio cria��o de vari�veis/string
    char cpf[50];
    char conteudo[200];
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r"); //abre o arquivo armazenado para leitura
    
    if(file == NULL) // caso o n�mero de CPF n�o esteja cadastrado no sistema
    {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
    }
    
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas s�o as informa��es do usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system("pause");
}

int deletar()
{
    //in�cio da cria��o de vari�veis/string
    char cpf[50];
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf); //deleta o cpf digitado do banco de dados
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if (file==NULL) //caso o cpf n�o coste no banco de dados
    {
        printf("O usuario nao se encontra no sistema!\n");
        system("pause");
    }
}

int main()
{
    int opcao=0; //definido vari�veis
    int laco=1;
    
    for (laco=1;laco=1;)
    {
        system ("cls"); //respons�vel por limpar a tela
        
        setlocale(LC_ALL, Portuguese); //definindo a linguagem, idioma
        
        printf("### Cart�rio da EBAC ###\n\n"); // in�cio do menu
        printf("Escolha a op��o desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: ");//fim do menu
        
        scanf("%d", &opcao); //armazenando a escolha do usu�rio
        
        system("cls");//respons�vel por limpar a tela
        
        switch (opcao) // in�cio da sele��o
        {
            case 1:
            registro(); //chamada de fun��es
            break;
            
            case 2:
            consulta();
            break;
            
            case 3:
            deletar();
            break;
            
            case 4:
            printf("Obrigado por utilizar o sistema!\n");
            return 0;
            break;
                
            default:
            printf("Essa op��o n�o est� dispon�vel!\n");
            system("pause");
            break;
                
        } //fim da sele��o
    }
}
