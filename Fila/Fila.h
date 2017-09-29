#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

template <class T>
struct TElementoF
{
    T dado;
    TElementoF<T> * prox;
};

template <class T>
struct TFila
{
    TElementoF<T> * inicio;
    TElementoF<T> *  fim;
    int qtd;
};

template <class T>
void inicializarFila (TFila<T> &f)
{
    f.inicio = NULL;
    f.fim = NULL;
    f.qtd = 0;
}

template <class T>
void enfileirar(TFila<T> &f, T dado)
{
    TElementoF<T> *novo = new TElementoF<T>;
    if (novo == NULL)
    {
        return false;
    }
    novo->dado = dado;

    if (f.qtd == 0)
    {
        f.inicio = *novo;

    }
    else
    {
        f.fim->prox = *novo;
    }
    f.fim = novo;
    novo->prox = NULL;
    f.qtd++;
}

template <class T>
void desenfilerar (TFila<T> &f, T dado)
{
    TElementoF<T> * aux;
    aux = f.inicio;
    f.inicio = f.inicio->prox;
    delete aux;
    if (f.qtd == 1)
    {
        f.fim = NULL;
    }
    f.qtd--;
    return true;
}







#endif // FILA_H_INCLUDED
