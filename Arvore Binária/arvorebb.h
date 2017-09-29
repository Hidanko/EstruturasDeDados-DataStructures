#ifndef ARVOREBB_H_INCLUDED
#define ARVOREBB_H_INCLUDED

template <class T>
struct TNodo
{
    int chave;
    T dado;
    TNodo<T> *maior;
    TNodo<T> *menor;
};

template <class T>
struct TABB
{
    TNodo<T>* raiz;
    int qtd;
};

template <typename T>
void inicializarABB(TABB<T> &a)
{
    a.raiz = NULL;
    a.qtd= 0;
}

template <class T>
bool inserirABB (TABB<T> &a, int chave, T dado)
{
    TNodo<T> *novo = new TNodo<T>;
    novo->dado = dado;
    novo->chave = chave;
    novo->menor = NULL;
    novo->maior = NULL;
    if (a.qtd == 0)
    {
        a.raiz = novo;
    }
    else
    {
        TNodo<T> *pai = a.raiz;
        while (!(chave > pai->chave && pai->maior == NULL) || (chave < pai-> chave && pai->menor == NULL))
        {
            if (chave > pai-> chave)
            {
                pai = pai->maior;
            }
            else
            {
                if (chave < pai->chave)
                {
                    pai = pai-> menor;

                }
                else
                {
                    delete novo;
                    return false;
                }
            }
        }
        if (chave > pai-> chave)
        {
            pai->maior = novo;
        }
        else
        {
            pai->menor = novo;
        }
        a.qtd = 1;
        return true;
    }
}

template <class T>
bool inserirTABB_rec (TNodo<T>*& nodo, int chave, T dado) // passar a raiz e não a arvore
{
    if (nodo == NULL)
    {
        nodo = new TNodo<T>;
        nodo->chave = chave;
        nodo->dado = dado;
        nodo->maior = NULL;
        nodo->menor = NULL;
        return true;
    }
    else
    {
        if (chave == nodo->chave)
        {
            return false;
        }
        else
        {
            if (chave > nodo-> chave)
            {
                return inserirTABB_rec (nodo->maior, chave, dado);
            }
            else
            {
                return inserirTABB_rec (nodo->menor, chave, dado);
            }
        }
    }





}
#endif // ARVOREBB_H_INCLUDED
