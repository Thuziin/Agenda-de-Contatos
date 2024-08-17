#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_NOME 50
#define TAMANHO_ENDERECO 150
#define TAMANHO_EMAIL 50
#define TAMANHO_TELEFONE 11
#define ANIVERSARIO 2

// ESTRUTURA DE CONTATOS

typedef struct {
    char nome[TAMANHO_NOME], endereco[TAMANHO_ENDERECO], email[TAMANHO_EMAIL], telefone[TAMANHO_TELEFONE];
    int aniversario[ANIVERSARIO];
} agenda;

// LISTAR AGENDA DE CONTATOS

void listarAgenda(agenda agendaContatos[], int aux) {
    // Verifica se agenda ta vazia
    if (aux == 0) {
        printf("AGENDA VAZIA!!");
        return ;
    }

    // Printa cabeçalho
    printf("+-----------------------------+-----------------+----------------- AGENDA -----------------+----------------------------+-----------------+\n");
    printf("| %-27s | %-15s | %-40s | %-26s | %-15s |\n", "NOME", "TELEFONE", "ENDERECO", "EMAIL", "ANIVERSARIO");
    printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");

    // Printa os contatos que esta na agenda
    for (int i = 0; i < aux; i++) {
        printf("| %-27s | %-15s | %-40s | %-26s |  %d/%-11d |\n", agendaContatos[i].nome, agendaContatos[i].telefone, agendaContatos[i].endereco, agendaContatos[i].email, agendaContatos[i].aniversario[0], agendaContatos[i].aniversario[1]);
        printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
    }
}

// VERIFICAÇÃO DE CONTATOS

int verificacaoContatos(agenda agendaContatos[], int aux) {
    char nomeVerificacao[TAMANHO_NOME];

    // Pede ao usuario o nome do contato
    printf("Nome contato: ");
    gets(nomeVerificacao);

    // Verifica se há nome igual ao que foi digitado pelo usuario, na agenda
    for (int i = 0; i < aux; i++) {
        if(strcmp(agendaContatos[i].nome, nomeVerificacao) == 0) {
            printf("NOME JA CADASTRADO, RETORNANDO AO MENU...\n");
            return 1;
        }
    }

    // Copia o nome digitado pelo usuario na agenda
    strcpy(agendaContatos[aux].nome, nomeVerificacao);

    return 0;
}

// INCLUSÃO DE CONTATOS

int incluirContatos(agenda agendaContatos[], int aux, int MAXIMO) {
    char resp;
    printf("Voce pode incluir ate %d contatos!\n", MAXIMO);
    do {

        // Verifica se a agenda está cheia
        if(aux < MAXIMO) {
           
            // Verifica se a condição da função 'verificacaoContatos' é valida
            if (verificacaoContatos(agendaContatos, aux)) {
                return aux;
            }

            printf("Telefone do contato: ");
            gets(agendaContatos[aux].telefone);

            printf("Endereco do contato: ");
            gets(agendaContatos[aux].endereco);

            printf("Email do contato: ");
            gets(agendaContatos[aux].email);

                
            printf("Informe a data e o mes do aniversario (dd mm): ");
            scanf("%d %d", &agendaContatos[aux].aniversario[0], &agendaContatos[aux].aniversario[1]);
            fflush(stdin);

        } else {
            // Caso a agenda esteja cheia, retorna uma mensagem 
            printf("AGENDA CHEIA!\n");
            return aux;
        }
        // Incrementa aux para adicionar o contato
        aux++;

        // Pergunta se o usuario deseja adicionar mais um contato
        printf("Voce deseja adicionar mais um contato? (S/N): ");
        resp = getche();
        system("cls");

    // Verifica se a resposta é 'sim', caso afirmativo o laço de repetição é execultado novamente
    } while(resp == 'S' || resp == 's');

    return aux;
}

// ALTERAÇÃO DE CONTATOS

void alterarContato (agenda agendaContatos[], int aux) {
    listarAgenda(agendaContatos, aux);

    char nomeContato[TAMANHO_NOME];
    printf("Informe o nome do contato que deseja alterar: ");
    gets(nomeContato);
    system("cls");

    for (int i = 0; i < aux; i++) {
        if (!strcmp(agendaContatos[i].nome, nomeContato)) {

            printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
            printf("| %-27s | %-15s | %-40s | %-26s | %-15s |\n", "NOME", "TELEFONE", "ENDERECO", "EMAIL", "ANIVERSARIO");
            printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
            printf("| %-27s | %-15s | %-40s | %-26s |  %d/%-11d |\n", agendaContatos[i].nome, agendaContatos[i].telefone, agendaContatos[i].endereco, agendaContatos[i].email, agendaContatos[i].aniversario[0], agendaContatos[i].aniversario[1]);
            printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
            
            printf("\n\nInforme os novos dados!\n");

            printf("Telefone de %s: ", agendaContatos[i].nome);
            gets(agendaContatos[i].telefone);

            printf("Endereco de %s: ", agendaContatos[i].nome);
            gets(agendaContatos[i].endereco);

            printf("Email de %s: ", agendaContatos[i].nome);
            gets(agendaContatos[i].email);


            printf("Informe a data e o mes do aniversario: ");
            scanf("%d %d", &agendaContatos[i].aniversario[0], &agendaContatos[i].aniversario[1]);

            return ;
        }
    }
    system("cls");
    printf("ESSE CONTATO NAO ESTA CADASTRADO!\n");
}

// PESQUISA POR NOME

void pesquisarPorNome(agenda agendaContatos[], int aux) {
    listarAgenda(agendaContatos, aux);

    char nomePesquisado[100];

    printf("Digite o nome do cliente a ser pesquisado: ");
    gets(nomePesquisado);

    for(int i = 0; i < aux; i++) {
        if(strcmp(agendaContatos[i].nome, nomePesquisado) == 0) {
            printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
            printf("| %-27s | %-15s | %-40s | %-26s | %-15s |\n", "NOME", "TELEFONE", "ENDERECO", "EMAIL", "ANIVERSARIO");
            printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
            printf("| %-27s | %-15s | %-40s | %-26s |  %d/%-11d |\n", agendaContatos[i].nome, agendaContatos[i].telefone, agendaContatos[i].endereco, agendaContatos[i].email, agendaContatos[i].aniversario[0], agendaContatos[i].aniversario[1]);
            printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
            return;
        } 
    }
    system("cls");
    printf("CONTATO NAO ENCONTRADO!\n");
}

// PESQUISA DE ANIVERSARIANTES POR MÊS

void pesquisarAniversariantesPorMes(agenda agendaContatos[], int aux) {
    listarAgenda(agendaContatos, aux);

    int mes, verificador = 0;
    printf("\nInforme o mes do contato: ");
    scanf("%d", &mes);
    
    printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
    printf("| %-27s | %-15s | %-40s | %-26s | %-15s |\n", "NOME", "TELEFONE", "ENDERECO", "EMAIL", "ANIVERSARIO");
    printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
    
    for (int i = 0; i < aux; i++) {
        if(mes ==  agendaContatos[i].aniversario[1]) {
            verificador++;
            printf("| %-27s | %-15s | %-40s | %-26s |  %d/%-11d |\n", agendaContatos[i].nome, agendaContatos[i].telefone, agendaContatos[i].endereco, agendaContatos[i].email, agendaContatos[i].aniversario[0], agendaContatos[i].aniversario[1]);
            printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");

        }
    }

    if (verificador == 0) {
        system("cls");
        printf("SEM ANIVERSARIANTES NESTE MES!\n");
    }

}

// EXCLUSÃO DE CONTATO

int excluirContato(agenda agendaContatos[], int aux) {
    listarAgenda(agendaContatos, aux);

    char nomeExclusao[TAMANHO_NOME], resposta;

    printf("Informe o nome que deseja excluir da agenda: ");
    gets(nomeExclusao);
    system("cls");

    for(int i = 0; i < aux; i++) {
        if(strcmp(agendaContatos[i].nome, nomeExclusao) == 0) {
            printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
            printf("| %-27s | %-15s | %-40s | %-26s | %-15s |\n", "NOME", "TELEFONE", "ENDERECO", "EMAIL", "ANIVERSARIO");
            printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
            printf("| %-27s | %-15s | %-40s | %-26s |  %d/%-11d |\n", agendaContatos[i].nome, agendaContatos[i].telefone, agendaContatos[i].endereco, agendaContatos[i].email, agendaContatos[i].aniversario[0], agendaContatos[i].aniversario[1]);
            printf("+-----------------------------+-----------------+------------------------------------------+----------------------------+-----------------+\n");
            
            printf("Deseja realmente excluir esse contato? (s/n): ");
            resposta = getche();

            if (resposta == 's' || resposta == 'S') {
                for (int j = i; j < aux - 1; j++) {
                    agendaContatos[j] = agendaContatos[j + 1];
                }
                return aux - 1;
            } else {
                return aux;
            }
        } 
    }
    printf("NOME NÃO ENCONTRADO!\n");
    return aux;
}

void main () {
    const int MAXIMO = 2;
    int opcao = 0, aux = 0;
    agenda agendaContatos[MAXIMO]; 

    do {
        printf("\nInforme a opcao do menu que deseja acessar:\n\n");
        printf("+ ---------------  MENU  ------------------ + \n");
        printf("|    0 - Sair                               |\n");
        printf("|    1 - Lista agenda                       |\n");
        printf("|    2 - Incluir contato                    |\n");
        printf("|    3 - Alteracao de contato               |\n");
        printf("|    4 - Pesquisa por nome                  |\n");
        printf("|    5 - Pesquisa de aniversariante do mes  |\n");
        printf("|    6 - Exclusao de contato                |\n");
        printf("+ ----------------------------------------- +\n");
            
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");
        fflush(stdin);

switch (opcao) {
            case 1 :
                listarAgenda(agendaContatos, aux);
                break;

            case 2:
                aux = incluirContatos(agendaContatos, aux, MAXIMO);
                break;

            case 3:
                alterarContato(agendaContatos, aux);
                break;

            case 4:
                pesquisarPorNome(agendaContatos, aux);
                break;
            case 5:
                pesquisarAniversariantesPorMes(agendaContatos, aux);
                break;
            case 6:
                aux = excluirContato(agendaContatos, aux);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);
}