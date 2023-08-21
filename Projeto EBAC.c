#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de testo por região
#include <string.h> // biblioteca responsável por cuidar dos string

int registro() //Função responsável por cadastrar os usuários no sistema
{
    //início criação de variáveis/string
    char arquivo[50];
    char cpf[50];
    char nome[50];
    char sobrenome[50];
    char cargo[50];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
    scanf("%s", cpf); //refere-se a string, faz o armazenamento do cpf
    
    strcpy(arquivo, cpf); //responsável por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //"w" - write, cria o arquivo
    fprintf(file,cpf); //salvo o valor da variável
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); // "a" de atualização
    fprintf(file, ",");
    fclose(file);// fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);//refere-se a string, faz o armazenamento do nome
    fclose(file);// fecha o arquivo
    
    file = fopen(arquivo, "a"); // "a" de atualização
    fprintf(file, ",");
    fclose(file);// fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);//refere-se a string, faz o armazenamento do sobrenome
    
    file = fopen(arquivo, "a"); // "a" de atualização
    fprintf(file, ",");
    fclose(file);// fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);//refere-se a string, faz o armazenamento do cargo
    
    file = fopen(arquivo, "a"); // "a" de atualização
    fprintf(file, ",");
    fclose(file);// fecha o arquivo
    
    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, Portuguese); //definindo a linguagem, idioma
    
    //início criação de variáveis/string
    char cpf[50];
    char conteudo[200];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r"); //abre o arquivo armazenado para leitura
    
    if(file == NULL) // caso o número de CPF não esteja cadastrado no sistema
    {
        printf("Não foi possível abrir o arquivo, não localizado! \n");
    }
    
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system("pause");
}

int deletar()
{
    //início da criação de variáveis/string
    char cpf[50];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf); //deleta o cpf digitado do banco de dados
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if (file==NULL) //caso o cpf não coste no banco de dados
    {
        printf("O usuario nao se encontra no sistema!\n");
        system("pause");
    }
}

int main()
{
    int opcao=0; //definido variáveis
    int laco=1;
    
    for (laco=1;laco=1;)
    {
        system ("cls"); //responsável por limpar a tela
        
        setlocale(LC_ALL, Portuguese); //definindo a linguagem, idioma
        
        printf("### Cartório da EBAC ###\n\n"); // início do menu
        printf("Escolha a opção desejada do menu\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: ");//fim do menu
        
        scanf("%d", &opcao); //armazenando a escolha do usuário
        
        system("cls");//responsável por limpar a tela
        
        switch (opcao) // início da seleção
        {
            case 1:
            registro(); //chamada de funções
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
            printf("Essa opção não está disponível!\n");
            system("pause");
            break;
                
        } //fim da seleção
    }
}
