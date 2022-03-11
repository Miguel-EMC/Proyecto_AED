#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "login.h"
#include "registro.h"
#include "ordenar.h"
#include "busqueda.h"
#include <fstream>
using namespace std;
void menu2();
void menu3();
void menu4();
int  menu()
{
    int opc;
    cout<<"                                            ____________________      "<<endl;
    cout<<"                                        |___|      *LOGIN*       |___| "<<endl;
    cout<<"                                            |____________________|     "<<endl;
    do
    {
        cout<<"\t                                _____________________________ "<<endl;
        cout<<"\t                               |_____________________________|"<<endl;
        cout<<"\t                    ||         | 1- REGISTAR USUARIO         |         ||"<<endl;
        cout<<"\t                    ||_________| 2- INICIAR SESION           |_________||"<<endl;
        cout<<"\t                               | 3- ELIMINAR USUARIO         |"<<endl;
        cout<<"\t                               | 4- SALIR                    |"<<endl;
        cout<<"\t                               |_____________________________|"<<endl;
        cout<<"\t                               |_____________________________|"<<endl;
        cout<<"\t                                       |             |        "<<endl;
        cout<<"\t                                   ____|             |____  \n"<<endl;
        cout<<"\t                                  |__-_|             |_-__|  \n"<<endl;
        cout<<"                              >>Ingrese una opcion:";
        cin>>opc;
        switch(opc)
        {
        case 1:
            Registrar();
            break;

        case 2:
            Ingresar();
            menu2();
            break;

        case 3:
            eliminar ();
            break;

        case 4:
            cout<<"\t\t\t FINALIZANDO.......................................................!";

            break;

        }
    }
    while(opc!=4);
    return opc;
}
void menu2()
{
    string nombre[100];
    int op, i;
    do
    {

        cout <<" \t\t\t        |     ____________________     |"<<endl;
        cout <<" \t\t\t        |____|      MENU          |____| "<<endl;
        cout <<" \t\t\t             |____________________|     "<<endl;
        cout <<" \t\t\t             |____________________|     "<<endl;
        cout <<" \t\t\t"<<endl;
        cout << "\t\t\t           | 1-Registro de Notas   | "<< endl;
        cout << "\t\t\t           | 2-Ordenamiento        | "<< endl;
        cout << "\t\t\t           | 3-Busqueda            | "<< endl;
        cout << "\t\t\t           | 4-Salir               | "<< endl;
        cout << "\t\t\t           |  Escoja una opcion:   ";
        cin >> op;


        switch (op)
        {
        case 1:

            registro();
        break;

        case 2:
            menu3();

            break;
        case 3:
            menu4();
        break;
        }
    }
    while (op!=4);

}
void menu3()
{
    ofstream archivo1;
    archivo1.open("Ordenamiento.txt",ios::app );
    int op3;
    do
    {

        int i=0;
        cout<<"\n";
        cout <<" \t\t\t           |    |____________________|    |"<<endl;
        cout <<" \t\t\t           |____|    ORDENAMIENTOS   |____| "<<endl;
        cout <<" \t\t\t                |____________________|     "<<endl;
        cout<<"\n \t\t\t           | 1-Ordenamiento Burbuja     |"<< endl;
        cout<<" \t\t\t           | 2-Ordenamiento de Seleccion   |"<< endl;
        cout<<" \t\t\t           | 3-Ordenamiento de Insercion   |"<<endl;
        cout<<" \t\t\t           | 4-Ordenamiento Mergesort      |"<<endl;
        cout<<" \t\t\t           | 5-Ordenamineto Quicksort      |"<<endl;
        cout<<" \t\t\t           | 6-Salir                       |"<<endl;
        cout<<"\t\t\t            |  Escoja una opcion:   ";
        cin >>op3;


        switch(op3)
        {
        case 1:
             cout<<"             ________________________________________________________________     "<<endl;
             cout<<"            |______________      ORDENAMIENTO BURBUJA          ______________|      "<<endl;
            ordenamientobur(getsP(), getsNom(), getsN());


            break;
        case 2:
             cout<<"             ________________________________________________________________     "<<endl;
             cout<<"            |______________     ORDENAMIENTO DE SELECCION      ______________|      "<<endl;
            ordenaselect(getsP(), getsNom(), getsN());

        break;

        case 3:
            cout<<"             ________________________________________________________________     "<<endl;
            cout<<"            |______________     ORDENAMIENTO DE INSERCION      ______________|      "<<endl;
            ordeinsercion(getsP(), getsNom(), getsN());

            break;
        case 4:
            cout<<"             ________________________________________________________________     "<<endl;
            cout<<"            |______________     ORDENAMIENTO DE MEGERSORT      ______________|      "<<endl;
            cout<<" ";
            archivo1<<"\nORDENAMIENTO POR MEGERSORT\n";
            dividir(getsP(),getsNom(),0,getsN()-1);
            for( i=0; i<getsN(); i++)
            {
                archivo1<<"|"<<getsP ()[i] <<"|" <<"---->";
                cout<<"|"<<getsP ()[i] <<"|" <<"---->";
            }

            break;

        case 5:
            cout<<"             ________________________________________________________________     "<<endl;
             cout<<"            |______________     ORDENAMIENTO DE QUICKSORT      ______________|      "<<endl;
            archivo1<<"\nORDENAMIENTO POR QUICKSORT\n";
            ordenarquick(getsP(),getsNom(),0,getsN()-1);
            for( i=0; i<getsN(); i++)
            {
                archivo1<<"|"<<getsP ()[i] <<"|" <<"---->";
                cout<<"|"<<getsP ()[i] <<"|" <<"---->";
            }


            break;
        }

    }
    while (op3!=6);
    archivo1.close();
}

void menu4()
{
    int op4;

    do
    {
        cout<<"\n";
        cout <<" \t\t\t           |    |____________________|    |"<<endl;
        cout <<" \t\t\t           |____|     BUSQUEDAS      |____| "<<endl;
        cout <<" \t\t\t                |____________________|     "<<endl;
        cout<<"\n \t\t\t           | 1-Busqueda Lineal          |"<< endl;
        cout<<" \t\t\t           | 2-Busqueda Binaria            |"<< endl;
        cout<<" \t\t\t           | 3- Busqueda Interpolacion     |"<<endl;
        cout<<" \t\t\t           | 4-Salir                       |"<<endl;
        cout<<"\t\t\t            |  Escoja una opcion:   ";
        cin>>op4;
        switch(op4)
        {
        case 1:
            cout<<"             ________________________________________________________________     "<<endl;
            cout<<"            |______________         BUSQUEDA LINEAL            ______________|      "<<endl;
            pedir ();
            break;
        case 2:
            cout<<"             ________________________________________________________________     "<<endl;
            cout<<"            |______________         BUSQUEDA BINARIA           ______________|      "<<endl;
            pedir2();
            break;

        case 3:
            cout<<"             ________________________________________________________________     "<<endl;
            cout<<"            |______________       BUSQUEDA INTERPOLACION       ______________|      "<<endl;
            Interpolacion(getsP(), getsN());
            break;

        }
    }
    while(op4!=4);
}

