#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <ctime>
using namespace std;
void fusionar(float a[100],string auxnom[100],int pinicial,int pfinal,int  medio);

void ordenamientobur(float arc[100],string auxnom[100],int tam)
{
    ofstream archivo1;
    archivo1.open("Ordenamiento.txt",ios::app );
    archivo1<<"ORDENAMIENTO BURBUJA\n";
    int i,j;
    float aux;
    string aux1;
    for(i=0; i<tam; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(arc[j]<arc[i] )
            {
                aux=arc[i];
                aux1=auxnom[i];
                arc[i]=arc[j];
                auxnom[i]= auxnom[j];
                arc[j]=aux;
                auxnom[j]=aux1;

            }
        }
    }
    for(i=0; i<tam; i++)
    {
        archivo1<<" | "<<arc[i]<<" | "<<"-->";
        cout<<" | "<<arc[i]<<" | "<<"-->";
    }
    archivo1.close();
}

void ordenaselect(float arc[100],string auxnom[100], int tam)
{
    ofstream archivo1;
    archivo1.open("Ordenamiento.txt",ios::app );
    archivo1<<"\nORDENAMIENTO POR SELECCION\n";
    int i,j,min;
    float aux;
    string aux1;
    for(i=0; i<tam; i++)
    {
        min=i;
        for(j=i+1; j<tam; j++)
        {
            if(arc[j]<arc[min])
            {
                min=j;
            }
        }
        aux=arc[i];
        aux1=auxnom[i];
        arc[i]=arc[min];
        auxnom[i]=auxnom[min];
        auxnom[min]=aux1;
    }
    for(i=0; i<tam; i++)
    {
        archivo1<<" | "<<arc[i]<<" | "<<"-->";
        cout<<" | "<<arc[i]<<" | "<<"-->";
    }
    archivo1.close();
}

void ordeinsercion(float arc[100],string auxnom[100], int tam)
{
    ofstream archivo1;
    archivo1.open("Ordenamiento.txt",ios::app );
    archivo1<<"\nORDENAMIENTO POR INSERCION\n";
    int i,pos;
    float aux;
    string aux1;
    for(i=0; i<tam; i++)
    {
        pos=i;
        aux=arc[i];
        aux1=auxnom[i];
        while(pos>0&&(arc[pos-1]>aux))
        {
            arc[pos]=arc[pos-1];
            pos--;
        }
        arc[pos]=aux;
        auxnom[pos]=aux1;
    }
    for(i=0; i<tam; i++)
    {
        archivo1<<"|"<<arc[i]<<"|" <<"-->";
        cout<<"|"<<arc[i]<<"|" <<"-->";
    }
    archivo1.close();
}

void dividir(float a[100],string auxnom1[50],int inicial, int pfinal)
{
    int  mitad;
    if(inicial < pfinal)
    {
        mitad=(inicial+pfinal)/2;
        dividir(a,auxnom1, inicial,mitad);
        dividir(a,auxnom1,mitad+1,pfinal);
        fusionar(a,auxnom1, inicial,pfinal,mitad);
    }


}

void fusionar(float a[100],string auxnom [100], int pinicial,int pfinal,int  medio)
{
    int i,j,k;
    float temp[pfinal-pinicial+1];
    string temp1[pfinal-pinicial+1];
    i=pinicial;
    k=0;
    j=medio+1;

    while(i<=medio && j<=pfinal)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            temp1[k]=auxnom[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=a[j];
            temp1[k]= auxnom[j];
            k++;
            j++;
        }
    }
    while (i<=medio)
    {
        temp[k] = a[i];
        temp1[k]=auxnom[i];
        k++;
        i++;
    }
    while(j<=pfinal)
    {
        temp[k]=a[j];
        temp1[k]=auxnom[j];
        k++;
        j++;
    }

    for(i=pinicial; i<=pfinal; i++)
    {
        a[i]= temp[i-pinicial];
        auxnom[i]= temp1[i-pinicial];
    }
}
float mitad(float arc[100],int pinicial,int pfinal)
{

    return arc[(pinicial+pfinal)/2];
}
string  mitad1(string auxnom[100],int pinicial,int pfinal)
{

    return auxnom[(pinicial+pfinal)/2];
}
void ordenarquick(float arc[100],string auxnom[100],int pinicial,int pfinal)
{
    int i=pinicial;
    int j=pfinal;
    float temp;
    string temp1;
    float piv=mitad(arc,pinicial,pfinal);
    string piv1=mitad1(auxnom,pinicial,pfinal);
    do
    {
        while(arc[i]<piv)
        {
            i++;
        }
        while(arc[j]>piv)
        {
            j--;
        }
        while(auxnom[i]<piv1)
        {
            i++;
        }
        while(auxnom[j]>piv1)
        {
            j--;
        }
        if(i<=j)
        {
            temp=arc[i];
            temp1= auxnom[i];
            arc[i]=arc[j];
            auxnom[i]=auxnom[j];
            arc[j]=temp;
            auxnom[j]=temp1;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(pinicial>j)
        ordenarquick(arc,auxnom,pinicial,j);
    if(i<pfinal)
        ordenarquick(arc,auxnom,i,pfinal);
}
