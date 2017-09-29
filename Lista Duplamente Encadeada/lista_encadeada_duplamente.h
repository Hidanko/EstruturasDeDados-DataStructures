#ifndef LISTA_ENCADEADA_DUPLAMENTE_H_INCLUDED
#define LISTA_ENCADEADA_DUPLAMENTE_H_INCLUDED

template <class t> // Utilizando Class em vez de Typename para aceitar string
struct TelementoDE
{
    t dado;
    TelementoDE<t>*ant;
    TelementoDE<t>*prox;
};

template <class t>
struct TlistaDE
{
    TelementoDE<t>*inicio;
    TelementoDE<t>*fim;
    int qtd;
};

template <class t>
void inicializa_lista(TlistaDE<t> &l)
{
    l.inicio=NULL;
    l.fim=NULL;
    l.qtd=0;
}

template <class t>
bool Insereinicio(TlistaDE<t> &l, t dado)
{
    TelementoDE<t> * novo = new TelementoDE<t>;
    novo->dado=dado;
    novo->ant=NULL;
    novo->prox=l.inicio;
    if(l.qtd==0)
    {
        l.fim=novo;
    }
    else
    {
        l.inicio->ant=novo;
    }
    l.inicio=novo;
    l.qtd++;
    return true;
}

template <typename t>
bool InserefimDE(TlistaDE<t> &l, t dado)
{
    TelementoDE<t> * novo = new TelementoDE<t>;
    if(l.qtd==0)
    {
        Insereinicio(l,dado);
        return true;
    }
    else
    {
        novo->dado=dado;
        novo->prox=NULL;
        novo->ant=l.fim;
        l.fim->prox=novo;
        l.fim=novo;
        l.qtd++;
        return true;
    }
}

template <typename t>
bool removeinicio(TlistaDE<t>&l)
{
    if(l.qtd==0)
    {
        return false;
    }
    else
    {
        if(l.qtd==1)
        {
            delete l.inicio;
            l.inicio=NULL;
            l.fim=NULL;
        }
        else
        {
            l.inicio=l.inicio->prox;
            delete l.inicio->ant;
            l.inicio->ant=NULL;
        }
        l.qtd--;
    }

}


template <typename t>
bool removefim(TlistaDE<t> & l)
{
    if(l.qtd==0)
    {
        return false;
    }
    else
    {
        if(l.qtd==1)
        {
            delete l.inicio;
            l.inicio=NULL;
            l.fim=NULL;
        }
        else
        {
            l.fim=l.fim->ant;
            delete l.fim->prox;
            l.fim->prox=NULL;
        }
        l.qtd--;
    }

}

template <typename t>
bool removepos(TlistaDE<t>&l,int pos)
{
    if(l.qtd==0||pos>=l.qtd||pos<0)
    {
        return false;
    }
    if(pos==0)
    {
        return removeinicio(l);
    }
    if(pos==l.qtd-1)
    {
        return removefim(l);
    }
    else
    {
        TelementoDE<t>*nav=l.inicio;
        int cont=0;
        while(cont!=pos-1)
        {
            nav=nav->prox;
            cont++;
        }
        TelementoDE<t>*del=nav->prox;
        del->prox->ant=nav;
        nav->prox=del->prox;
        delete del;
        l.qtd--;
        return true;
    }
}

template <typename t>
bool insereposicao(TlistaDE<t> &l, t dado, int pos)
{
    if(pos>l.qtd)
    {
        return false;
    }
    if(pos==0)
    {
        Insereinicio(l,dado);
        return true;
    }
    if(pos==l.qtd)
    {
        InserefimDE(l,dado);
        return true;
    }
    else
    {
        TelementoDE<t> * novo = new TelementoDE<t>;
        TelementoDE<t> * nav=l.inicio;
        novo->dado=dado;
        int cont=0;
        while(cont!=pos-1)
        {
            nav=nav->prox;
            cont++;
        }
        novo->prox=nav->prox;
        novo->ant=nav;
        nav->prox->ant=novo;
        nav->prox=novo;
        l.qtd++;
        return true;
    }
}

template <typename t>
bool mostrar(TlistaDE<t> l, int pos)
{
    TelementoDE<t>*nav=l.inicio;
    int cont=0;
    while(cont!=pos)
    {
        nav=nav->prox;
        cont++;
    }
    cout<<nav->dado<<endl;
    return true;
}

template <typename t>
void bubbleDE(TlistaDE<t> &l)
{
    TelementoDE<t> *aux;
    TelementoDE<t> *troca;
    for(int i=l.qtd-1; i >= 1; i--)
    {
        aux=l.inicio;

        for( int j=0; j < i ; j++)
        {

            if(aux->dado>aux->prox->dado)
            {

                troca->dado = aux->dado;
                aux->dado = aux->prox->dado;
                aux->prox->dado = troca->dado;

            }
            aux=aux->prox;
        }
    }

}


template<class comum>
void copialista(TlistaDE<comum> *origem, TlistaDE<comum> *destino)
{
    int i;
    TelementoDE<comum> *o=origem->inicio;//nó para percorrer a lista
    TelementoDE<comum> *d;//nó auxiliar para atribuir os indices

    for(i=0; i<origem->qtd; i++) //percorre toda a lista
    {
        InserefimDE(destino,o->dado);//insere na lista o valor contido na origem
        o=o->prox;//avança para o proximo nó
    }

    d=destino->inicio;
    o=origem->inicio;

    for(i=0; i<origem->qtd; i++) //percorre toda a lista
    {
        d->dado=o->dado;//atribui o indice da origem para o destino
        o=o->prox;// avança para o proximo nó de origem
        d=d->prox;//avança para o proximo nó de destino
    }


}

template <class comum>
void divide(TlistaDE<comum> *l, TlistaDE<comum> *E, TlistaDE<comum> *D) //divide a lista em duas
{
    int i,p=0,r=l.qtd-1,q;//p e r recebem os indices
    TelementoDE<comum> *Q=l->inicio;//nó para percorrer a lista

    q=((r-p)/2)+1;//encontra o indice do meio
    for(i=0; i<=q-1; i++) //percorre a lista até o meio
    {
        Q=Q->prox;
    }
    //atribui os valores respectivos para a lista da esquerda
    D->inicio=l->inicio;
    D->qtd=q;
    D->fim=Q->ant;

    //atribui os valores respectivos para a lista da direita
    E->inicio=Q;
    E->qtd=(r-p)-(q-1);
    E->fim=l->fim;
}

template<class comum>
void Merge(TlistaDE<comum> *l,TlistaDE<comum> *DIREITA, TlistaDE<comum> *ESQUERDA)
{
    TelementoDE<comum> *direita;
    TelementoDE<comum> *esquerda;
    TelementoDE<comum> *lista=l->inicio;
    TlistaDE<comum> *E,*D;
    inicializa_lista(E);
    inicializa_lista(D);
    int i;

    copialista(DIREITA,D);
    copialista(ESQUERDA,E);

    direita=D->inicio;
    esquerda=E->inicio;
    for(i=0; i<l->qtd; i++) //percorre toda a lista
    {
        if(esquerda->dado < direita->dado) //compara se o valor da esquerda é maior que o valor da direita
        {
            lista->dado=esquerda->dado;//copia pra lista o valor da esquerda
            esquerda=esquerda->prox;//avança para o proximo nó da esquerda;
        }
        else
        {
            lista->dado=direita->dado;//copia o valor da direta para a lista
            direita=direita->prox;//avança para o proximo nó da direita
        }
        lista=lista->prox;//avança para o proximo nó da lista
    }
}

template<class comum>
void MergeSort(TlistaDE<comum> *l, int p=0, int r=0)
{
    r=l->qtd;
    TlistaDE<comum> *E,*D;
    inicializa_lista(E);
    inicializa_lista(D);
    int metadelista=(p-r)/2;

    if(r-p>0)
    {

        divide(l,E,D);//divide a lista em duas

        MergeSort(E,p,metadelista);//faz recursão para a lista da esquerda
        MergeSort(D,metadelista+1,r);//faz recursão para a lista da direita
        Merge(l,E,D);//une as listas
    }

}

#endif // LISTA_ENCADEADA_DUPLAMENTE_H_INCLUDED
