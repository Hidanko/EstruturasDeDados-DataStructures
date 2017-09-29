#ifndef MIN_HEAP
#define MIN_HEAP
#define Tam 10

template<class T>
struct TElemento{
    T dado;
    int chave;
};

template<class T>
struct Lista{
    int qtd;
    TElemento<T> Lista[Tam];
};

template<class T>
void inicializarLista(Lista<T> &t){
    t.qtd=0;
}

int pai(int i){
    return (i-1)/2;
}

int esq(int i){
    return 2*i+1;
}

int dir(int i){
    return 2*i+2;
}

template<class T>
TElemento<T> topo(Lista<T> t){
    return t.Lista[0];
}

template<class T>
bool inserirLista(Lista<T> &t, int chave, T dado){
    for(int i=0; i<t.qtd; i++){
        if(chave==t.Lista[i].chave){
            return false;
        }
    }
    t.Lista[t.qtd].chave=chave;
    t.Lista[t.qtd].dado=dado;
    int i=t.qtd;
    while(i>0){
        int p=pai(i);
        if(t.Lista[i].chave<t.Lista[p].chave){
            swap(t.Lista[i], t.Lista[p]);
            i=p;
        } else {
            break;
        }
    }
    t.qtd++;
    return true;
}

template<class T>
void removeTopo(Lista<T> &t){
    t.qtd--;
    swap(t.Lista[0], t.Lista[t.qtd]);
    int i=0;
    while(esq(i)<t.qtd || dir(i)<t.qtd){
        int e=esq(i);
        int d=dir(i);
        int menor=i;
        if(e<t.qtd && t.Lista[e].chave<t.Lista[i].chave){
            menor=e;
        }
        if(d<t.qtd && t.Lista[d].chave<t.Lista[menor].chave){
            menor=d;
        }
        if(menor!=i){
            swap(t.Lista[menor], t.Lista[i]);
            i=menor;
        } else {
            break;
        }
    }
}

template<class T>
void limpar(Lista<T> &t){
    int pos=t.qtd;
    for(int i=0; i<pos; i++){
        removeTopo(t);
    }
}

template<class T>
void imprimir(Lista<T> t){
    for(int i=0; i<t.qtd; i++){
        cout<<t.Lista[i].chave<<", ";
    }
}

template<class T>
void trocarDado(Lista<T> &t, T dado, int chave){
    int p;
    for(int i=0; i<t.qtd; i++){
        if(dado==t.Lista[i].dado){
            t.Lista[i].chave=chave;
            p=i;
            break;
        }
    }
    //to up
    while(t.Lista[p].chave<t.Lista[pai(p)].chave && p>0){
        swap(t.Lista[p], t.Lista[pai(p)]);
        p=pai(p);
    }
    //to down
    while(esq(p)<t.qtd || dir(p)<t.qtd){
        int e=esq(p);
        int d=dir(p);
        int menor=p;
        if(e<t.qtd && t.Lista[e].chave<t.Lista[p].chave){
            menor=e;
        }
        if(d<t.qtd && t.Lista[d].chave<t.Lista[menor].chave){
            menor=d;
        }
        if(menor!=p){
            swap(t.Lista[menor], t.Lista[p]);
            p=menor;
        } else {
            break;
        }
    }
}

#endif // MIN_HEAP

