#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
int n;
float Promm[50];
using namespace std;
void registro();
string nombre[50],apellido[50];
struct RNotas
{

    string gmail;
    string correo;
    float nota1;
    float nota2;


} notitas[50];
void registro()
{
    cin.ignore();
    system("cls");
    ofstream archivo;
    archivo.open("Calificaciones.txt",ios::app );
    archivo <<"NOMBRE\tCORREO\t\tNOTA 1\t\tNOTA 2\t\tPROMEDIO\n";
    int i,aprobados=0, suspensos=0, reprobados=0;
    string materia;
    cin.ignore();
    cout<<"              _______________________________________________________________________      "<<endl;
    cout<<"             |_______________________________________________________________________|     "<<endl;
    cout<<"             |                      REGISTRO DE MATERIAS                             |     "<<endl;
    cout<<"             | >>MATERIA: ";
    getline(cin,materia);
    cout<<"             | >>INGRESE EL NUMERO DE ESTUDIANTES A REGISTRAR: ";
    cin >>n;
    system("cls");
    for ( i=0; i<n; i++)
    {
    cout<<"             _______________________________________________________________"<<endl;
    cout<<"            |______________           ESTUDIANTE N"<<i+1<<"          ______________|"<<endl;
    cout<<"             |  >>NOMBRE: ";
    cin>> nombre[i];
    cout<<"             |  >>APELLIDO: ";
    cin>> apellido[i];
    cout<<"             |  >>email: ";
    cin >> notitas[i].correo;
    cout<<"             |  >> NOTA 1: ";
    cin >> notitas[i].nota1;
    cout<<"             |  >> NOTA 2: ";
    cin >> notitas[i].nota2;

    cout<<"             ________________________________________________________________     "<<endl;
    cout<<"            |______________      NOTAS REGISTRADAS CON EXITO   ______________|      "<<endl;
    system("cls");

        Promm[i]  = notitas[i].nota1 +notitas[i].nota2;
        if(Promm[i] <=20&&Promm[i] >=14)
        {
            aprobados++;
        }
        if(Promm[i] &&Promm[i] <9)
        {
            reprobados++;
        }
        if(Promm[i] >=9&&Promm[i] <14)
        {
            suspensos++;
        }
    }

    system("cls");
    cout <<endl;
        cout<<"_____________________________________________________________________________________________________________      "<<endl;
        cout << "|  NOMBRES\tCORREOS\t\tNOTA1\t\tNOTA2\t\tPROMEDIOS       " <<endl;
    for (int i=0; i<n; i++)
    {
        cout <<nombre[i]<<" "<<apellido[i]<<"\t"<<notitas[i].correo<<"\t\t"<<notitas[i].nota1<<"\t\t"<<notitas[i].nota2<<"\t\t";
        cout <<Promm[i] <<endl;
        archivo <<nombre[i]<<" "<<apellido[i] <<"\t"<<notitas[i].correo<<"\t\t"<<notitas[i].nota1<<"\t\t"<<notitas[i].nota2<<"\t\t";
        archivo <<Promm[i] <<endl;
    }
         cout<<" ____________________________________________________________________________________________________________     "<<endl;
         cout<<" |___________________________________________________________________________________________________________ |\n"<<endl;
    cout <<endl <<"              |  APROBADOS: "<<aprobados;
    cout <<endl <<"              |  REPROBADOS: "<<reprobados;
    cout <<endl <<"              |  SUSPESOS: "<<suspensos <<endl;
        cout<<"  ____________________________________________________________________________________________________________     "<<endl;

}


int getsN()
{
    return n;
}
float *getsP()
{
    return Promm;
}
string *getsNom()
{
    return nombre;
}
