#ifndef LISTA_ESTATICA_H_INCLUDED
#define LISTA_ESTATICA_H_INCLUDED

#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 10;

template <class t>
struct Tlista
{
    t elementos[MAX];
    int qtd;
};

template <class t>
bool inserefinallista(Tlista<t> &l, t c)
{
    if(l.qtd<MAX)
    {
        l.elementos[l.qtd]=c;
        l.qtd++;
        return true;
    }
    else
    {
        return false;
    }
}

template <class t>
bool insereiniciolista(Tlista<t> &l, t c)
{
    if(l.qtd<MAX)
    {
        for(int i=l.qtd; i>0; i--)
        {
            l.elementos[i]=l.elementos[i-1];
        }
        l.elementos[0]=c;
        l.qtd++;
        return true;
    }
    else
    {
        return false;
    }
}

template <class t>
bool insereposlista(Tlista<t> &l, t c, int pos)
{
    if(l.qtd<MAX && pos>=0 && pos<=l.qtd)
    {
        for(int i=l.qtd; i>pos; i--)
        {
            l.elementos[i]=l.elementos[i-1];
        }
        l.elementos[pos]=c;
        l.qtd++;
        return true;
    }
    else
    {
        return false;
    }
}

template <class t>
bool removefimlista(Tlista<t> &l)
{
    if(l.qtd > 0)
    {
        l.qtd--;
        return true;
    }
    else
    {
        return false;
    }
}


template <class t>
bool removeiniciolista(Tlista<t> &l)
{
    if(l.qtd==1)
    {
        return removefimlista(l);
    }
    else
    {
        for(int i=0; i <l.qtd-1; i++)
        {
            l.elementos[i]=l.elementos[i+1];
        }
        l.qtd--;
        return true;
    }
}

template <class t>
bool removeposlista(Tlista<t> &l, int pos)
{
    if(pos==l.qtd-1 && l.qtd > 0)
    {
        l.qtd--;
        return true;
    }
    if(l.qtd>0 && pos >= 0 && pos < l.qtd)
    {
        for(int i=pos; i <l.qtd-1; i++)
        {
            l.elementos[i]=l.elementos[i+1];
        }
        l.qtd--;
        return true;
    }
    else
    {
        return false;
    }
}

template <class t>
void bubble(Tlista<t> &l)
{
    t aux;
    for(int i=l.qtd-1; i >= 1; i--)
    {

        for( int j=0; j < i ; j++)
        {

            if(l.elementos[j]>l.elementos[j+1])
            {

                aux = l.elementos[j];
                l.elementos[j] = l.elementos[j+1];
                l.elementos[j+1] = aux;

            }
        }
    }

}

template <class t>
void merge2(t vec[], int vecSize)
{
    int mid;
    int i, j, k;
    t* tmp;
    tmp = (t*) new t[vecSize * sizeof(t)];
    mid = vecSize / 2;
    i = 0;
    j = mid;
    k = 0;
    while (i < mid && j < vecSize)
    {
        if (vec[i] <= vec[j])
        {
            tmp[k] = vec[i++];
        }
        else
        {
            tmp[k] = vec[j++];
        }
        ++k;
    }
    if (i == mid)
    {
        while (j < vecSize)
        {
            tmp[k++] = vec[j++];
        }
    }
    else
    {
        while (i < mid)
        {
            tmp[k++] = vec[i++];
        }
    }
    for (i = 0; i < vecSize; ++i)
    {
        vec[i] = tmp[i];
    }
    delete[] tmp;
}

template <class t>
void mergeSort(t vec[], int lqtd)
{
    int mid;
    if (lqtd > 1)
    {
        mid = lqtd / 2;
        mergeSort(vec, mid);
        mergeSort(vec + mid, lqtd - mid);
        merge2(vec, lqtd);
    }
}



#endif // LISTA_ESTATICA_H_INCLUDED
