#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Tamanho_Vetor_Pessoa 10 //definindo o tamanho ddo vetor
typedef struct Pessoa           //criando a lista e já definindo novo dado como agenda
{
    int codigo;
    char nome_completo[50];
    char telefone[15];
    char email[40];
    char data_de_nascimento[10];
    char obs[100];
} Pessoa;

void menu(); //menu feito
void cadastro();
void listar();
void buscar();

Pessoa contato[Tamanho_Vetor_Pessoa];
int numero_de_contatos = 0, i;
int codi = 0;
int voltar;

int main(void) // programa principal a ser trabalhado contendo while e switch
{

    int opcao;

    while (opcao != 0)
    {

        menu();
        printf("\n\nEscolha uma opcao:");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao)
        {
        case 1:
            cadastro();
            break;

        case 2:
            listar();
            break;

        case 3:
            buscar();
            break;
        }
    }
}

void menu()
{
    printf(" ________________________________________________________________________________\n");
    printf("|                                                                                |\n");
    printf("|                               AGENDA                                           |\n");
    printf("|________________________________________________________________________________|\n\n");

    printf(" ___________________________\n");
    printf("|                           |\n");
    printf("|            MENU           |\n");
    printf("|___________________________|\n");
    printf("| 1 - Cadastro              |\n");
    printf("| 2 - Listar                |\n");
    printf("| 3 - Buscar                |\n");
    printf("| 4 - Alterar               |\n");
    printf("| 5 - Excluir               |\n");
    printf("| 0 - Sair                  |\n");
    printf("|___________________________|\n");
}

void cadastro() //Cadastramentos do dos nomes, zerando todas a posições e seguindo para guardas os dados
{

    int op = 1;

    while (op > 0)
    {
        for (i = 0; contato[i].codigo != 0 && i < Tamanho_Vetor_Pessoa; i++)
        {
        }

        if (i < Tamanho_Vetor_Pessoa)
        {
            do
            {
                printf("Digite codigo:");
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

            numero_de_contatos = numero_de_contatos + 1;
        }
        else
        {
            printf("Agenda Cheia!\n");
        }
        printf("Pressione [0] e depois o [Enter] para retornar ao menu:\n"); //* pedir para o usuraio retornar
        scanf("%i", &op);
    }
}

void listar() //imprime uma lista de todos os contatos da cadastrado na agenda
{
    printf(" ________________________________________________________________________________\n");
    printf("|                                                                                |\n");
    printf("|                                CONTATOS                                        |\n");
    printf("|________________________________________________________________________________|\n\n");

    if (numero_de_contatos > 0)
    {
        for (i = 0; i < numero_de_contatos; i++)
        {

            printf("Codigo : %i\n", contato[i].codigo);

            printf("Nome Completo : %s\n", contato[i].nome_completo);

            printf("Telefone : %s\n", contato[i].telefone);

            printf("Email : %s\n", contato[i].email);

            printf("Data de Nascimento :%s\n", contato[i].data_de_nascimento);

            printf("Obervacoes : %s\n\n", contato[i].obs);

            printf(" ______________________________________________________\n\n");
        }
    }
    else
    {
        printf("Agenda Vazia!\n\n");
    }
    printf("Pressione [0] e depois o [Enter] para retornar ao menu:\n"); //* pedir para o usuraio retornar
    scanf("%i", &voltar);
}

void buscar() // verifica se existe o nome/nome iguais, se estiver imprimi os dados na tela se não informa a usuario que não existe
{
    int codigo_de_busca = 0, tipo_busca = 0;
    char nome_da_busca[50];

    printf(" ________________________________________________________________________________\n");
    printf("|                                                                                |\n");
    printf("|                                 BUSCA                                          |\n");
    printf("|________________________________________________________________________________|\n\n");

    printf(" ___________________________\n");
    printf("|                           |\n");
    printf("|  ESCOLHA O TIPO DE BUSCA. |\n");
    printf("|___________________________|\n");
    printf("| 1 - codigo                |\n");
    printf("| 2 - nome                  |\n");
    printf("|___________________________|\n\n");

    printf("Escolha uma opcao : ");
    scanf("%d", &tipo_busca);

    switch (tipo_busca)
    {
    case 1:
        printf("Informe o codigo : ");
        scanf("%d", &codigo_de_busca);
        break;

    case 2:
        printf("Informe o nome : ");
        scanf("%s", nome_da_busca);
        break;

    default:
        printf("Opcao inválida!");
        break;
    }

    printf(" ______________________________________________________\n\n");

    for (i = 0; i < Tamanho_Vetor_Pessoa; i++)
    {
        if ((codigo_de_busca == contato[i].codigo) || (strcmp(nome_da_busca, contato[i].nome_completo) == 0)) //strcmp faz a comparação da strings
        {
            printf("Codigo : %i\n", contato[i].codigo);

            printf("Nome Completo : %s\n", contato[i].nome_completo);

            printf("Telefone : %s\n", contato[i].telefone);

            printf("Email : %s\n", contato[i].email);

            printf("Data de Nascimento :%s\n", contato[i].data_de_nascimento);

            printf("Obervacoes : %s\n", contato[i].obs);

            break;
        }
    }

    if (i == Tamanho_Vetor_Pessoa)
    {
        printf("Contato nao encontrado!\n");
        printf("Confira os dados no listar, para relizar a busca corretamente!\n\n");
    }
    printf("Pressione [0] e depois o [Enter] para retornar ao menu:\n");
    scanf("%i", &voltar);
}