#ifndef EA_H_INCLUDED
#define EA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std; 
struct TCliente
{
    int codigo;
    string nome;
};

template <typename t>
struct TelementosE
{
    TCliente * dado;
    TelementosE<t> *prox;
};

template <typename t>
struct TlistaE
{
    TelementosE<t>*inicio;
    int qtd;
};

template <typename t>
void inicializa_listaE(TlistaE<t> &l)
{
    l.inicio=NULL;
    l.qtd=0;
}

//tabela hash em lista encadeada
template <int M>
struct THashLE
{
    TlistaE<TCliente *>  tabela[M];
    int qtd;
};
//inicialização da tabela hash
template <int M>
void inicializaTLE(THashLE<M> &th)
{
    th.qtd=0;
    for(int i=0; i<M; i++)
    {
        inicializa_listaE(th.tabela[i]);
    }
}
//função hash que gera um codigo que é usado como indice
template <int M>
int funcaohashE(THashLE<M> &th, int chave)
{
    return chave%5;
}

//insere um novo dado na lista hash
template <int M>
int insereTHLE(THashLE<M> & th, TCliente * c)
{
    int qtd=1;
    TelementosE<TCliente *> * novo = new TelementosE<TCliente *>;
    novo->dado=c;
    novo->prox=NULL;
    int indice = funcaohashE(th,c->codigo);
    TelementosE<TCliente *> * aux = th.tabela[indice].inicio;
    if(aux==NULL)
    {
        th.tabela[indice].inicio=novo;
    }
    else
    {
        while(aux->prox!=NULL)
        {
            qtd++;
            aux=aux->prox;
        }
        aux->prox=novo;
    }

    th.qtd++;
    return qtd;
}
//pesquisa na tabela hash encadeada
template <int M>
TCliente * pesquisaTHLE(THashLE <M> & th, int codigo, int &qtdOp)
{
    qtdOp = 1;
    if(th.qtd==0)
    {
        return NULL;
    }
    int indice= funcaohashE(th,codigo);
    TelementosE<TCliente *> * aux = th.tabela[indice].inicio;
    while( aux != NULL)
    {
        qtdOp++;
        if( ((TCliente*)aux->dado)->codigo == codigo)
        {
            return aux->dado;
        }
        aux=aux->prox;
    }
    return NULL;
}

TCliente * geraCliente()
{
    TCliente * c = new TCliente;
    c->codigo=rand()%32000+1;
    c->nome="Cliente";
    return c;
}


#endif // EA_H_INCLUDED
