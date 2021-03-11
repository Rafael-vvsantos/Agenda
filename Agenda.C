#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Tamanho_Vetor_Pessoa 10 //definindo o tamanho ddo vetor
typedef struct Pessoa          //criando a lista e já definindo novo dado como agenda
{
    int codigo;
    char nome_completo[50];
    char telefone[11];
    char email[30];
    char data_de_nascimento[10];
    char obs[25];
} Pessoa;

void menu(); //menu feito
void cadastro();

int main(void) // programa principal a ser trabalhado
{

    int opcao;

    while (opcao != 0)
    {

        menu();
        printf("\n\nEscolha uma opcao:");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastro();
            break;
        }
    }
}

void menu()
{
    printf("******************************************A genda *****************************************************\n\n");
    printf(">>>>>>>>>>>MENU<<<<<<<<\n\n");
    printf("1 - Cadastro\n");
    printf("2 - Listar\n");
    printf("3 - Buscar\n");
    printf("4 - Alterar\n");
    printf("5 - Excluir\n");
    printf("0 - Sair\n");
    printf(">>>>>>>>>>>>>><<<<<<<<<<<<\n");
}

void cadastro() //Cadastramentos do dos nomes, zerando todas a posições e seguindo para guardas os dados 
{

    Pessoa contato[Tamanho_Vetor_Pessoa];
    int i, op = 1;

    for (i = 0; i < Tamanho_Vetor_Pessoa; i++)
    {
        contato[i].codigo = 0;
    }

    while (op > 0)
    {
        for (i = 0; contato[i].codigo != 0 && i < Tamanho_Vetor_Pessoa; i++)
        {
        }

        if (i < Tamanho_Vetor_Pessoa)
        {
            do
            {
                printf("Digite novamente o codigo:");
                scanf("%d", &contato[i].codigo);
            } while (contato[i].codigo < 1);

            printf("Digite o nome completo:");
            scanf("%s", contato[i].nome_completo);

            printf("Digite o telefone:");
            scanf("%s", contato[i].telefone);

            printf("Digite o email:");
            scanf("%s", contato[i].email);

            printf("Digite o data de nascimento:");
            scanf("%s", contato[i].data_de_nascimento);

            printf("Digite a observacao:");
            scanf("%s", contato[i].obs);
        }
        else
        {
            printf("Agenda Cheia!\n");
        }
        printf("Pressione 0 para retornar ao menu:\n"); //* pedir para o usuraio retornar
        scanf("%i", &op);
    }
}