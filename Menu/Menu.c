#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "../Func/funcoes.h"


void exibirMenu(Usuario **inicio)
{
    int opcao;

    do {
        printf("1 - Cadastrar usuário\n");
        printf("2 - Listar usuários\n");
        printf("3 - Remover usuário\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1: {
                char nome[MAx], email[MAx];
                int idade;

                printf("Nome: ");
                fgets(nome, MAx, stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Email: ");
                fgets(email, MAx, stdin);
                email[strcspn(email, "\n")] = 0;

                printf("Idade: ");
                scanf("%d", &idade);
                getchar();

                InserirNoInicio(inicio, nome, email, idade);
                break;
            }

            case 2:
                Listar(inicio);
                break;

            case 3:
                RemoverNoInicio(inicio);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 4);
}
