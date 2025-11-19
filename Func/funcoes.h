#ifndef FUNCOES_H
#define FUNCOES_H   

#define MAx 50

typedef struct No
{
    int id;
    char nome[MAx];
    char email[MAx];
    int idade;

    struct No *proximo;
}Usuario;

void InserirNoInicio(Usuario **inicio, const char* dadonome, 
                     const char* dadoemail, int dadoidade);

void Listar(Usuario **inicio);

void RemoverNoInicio(Usuario **inicio);

#endif