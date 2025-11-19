#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAx 50

static int proxID = 1;

int gerarID()
{
    return proxID++;
}


void InserirNoInicio(Usuario **inicio, const char* dadonome, 
                     const char* dadoemail, int dadoidade)
{
    Usuario *novoNo = (Usuario*) malloc(sizeof(Usuario));
    if(novoNo == NULL){
        printf("Erro ao alocar memoria\n");
        return;
    }
    novoNo->id = gerarID();
    strcpy(novoNo->nome, dadonome);
    strcpy(novoNo->email, dadoemail);
    novoNo->idade = dadoidade;
    novoNo->proximo = *inicio;
    *inicio = novoNo;

}

void Listar(Usuario **inicio)
{
    Usuario *atual = *inicio;
    while(atual != NULL)
    {
        printf("ID: %d\n", atual->id);
        printf("Nome: %s\n", atual->nome);
        printf("Email: %s\n", atual->email);
        printf("Idade: %d\n", atual->idade);
        atual = atual->proximo;
    }
}


void RemoverNoInicio(Usuario **inicio)
{
    if(*inicio == NULL)
    {
        printf("Lista vazia, nada para remover\n");
        return;
    }
    Usuario *temp = *inicio;
    *inicio = (*inicio)->proximo;
    free(temp);
}
