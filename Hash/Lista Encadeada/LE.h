#ifndef LE_H_INCLUDED
#define LE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
struct Tcliente
{
    int codigo;
    string nome;
};

template <int M>
struct THashEA
{
    Tcliente *tabela [M];
    int qtd;
};

template <int M>
void inicializaTHEA(THashEA<M> & th)
{
    th.qtd = 0;
    for (int i = 0; i < M; i++)
    {
        th.tabela[i] = NULL;
    }

}

template <int M>
int funcaohash(THashEA <M> & th, int chave)
{
    return chave % M;
}

template <int M>
bool insereTHEA(THashEA <M> & th, Tcliente *c, int &qtd)
{
    qtd=1;
    if (th.qtd == M)
    {
        return false;
    }
    int i = funcaohash(th,c->codigo);
    while (th.tabela[i] != NULL)
    {
        i++;
        if (i == M)
        {
            i = 0;
        }
        qtd++;
    }
    th.tabela[i] = c;
    th.qtd ++;
    return true;
}

template <int M>
Tcliente *pesquisaTHEA (THashEA <M> &th, int codigo, int &qtd)
{
    qtd=1;
    if (th.qtd == 0)
    {
        return NULL;
    }

    int i = funcaohash(th,codigo);
    int aux = i;
    while (th.tabela[i] != NULL)
    {
        if (th.tabela[i]->codigo == codigo)
        {
            return th.tabela[i];
        }
        i++;
        if (i == aux )
        {
            return NULL;
        }
        if (i == M)
        {
            i = 0;
        }
        qtd++;
    }
    return NULL;
}

Tcliente *gerarcliente()
{
    Tcliente *cliente=new Tcliente;
    cliente->codigo=rand()%32000+1;
    cliente->nome="Cliente2";
    return cliente;
}


#endif // LE_H_INCLUDED
