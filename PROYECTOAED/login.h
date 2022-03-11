#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
void Registrar ();
void Ingresar();

void Registrar (){

   string NombreDocente;
   string ApellidoDocente;
   string NombreUsuario;
   int Contrasenia,Vefcontrasenia;
   char n;
   ofstream registro;

    registro.open("Registro.txt",ios::app );
  do{
    cout<<"---------------------------------------------\n";
   cout<<"INGRESE EL NOMBRE: ";
    while(getchar()!='\n');
   getline(cin,NombreDocente);

   cout<<"INGRESE EL APELLIDO: ";
   getline(cin,ApellidoDocente);

   cout<<"INGRESE EL NOMBRE DE USUARIO: ";
   getline(cin,NombreUsuario);

   cout<<"INGRESE LA PASSWORD: ";
   cin>>Contrasenia;
   do
        {
            cout <<"\t>>VERIFIQUE CONTRASEÑA"<<endl;
            cin>>Vefcontrasenia;

            if (Contrasenia==Vefcontrasenia)
            {
                cout<<"\t\t>>>>REGISTRADO CON EXITO<<<<"<<endl;
                system("cls");
            }
            else
            {
                cout<<"\t\tERROR INGRESE DE NUEVO CONTRASEÑA "<<endl;
                system("cls");
            }
        }
        while(Contrasenia!=Vefcontrasenia);

   registro<<NombreDocente<<" "<<ApellidoDocente<<" "<<NombreUsuario<<" "<<Vefcontrasenia<<endl;
   cout<<"---------------------------------------------\n";
   system("cls");
   cout<<"PRESIONES >>*<< PARA CONTINUAR";
   cin>>n;
   cin.ignore();
  }while(n!='*');
   registro.close();
}

   void Ingresar(){
   string NombreDocente;
   string ApellidoDocente;
   string NombreUsuario;
   string usuario;
   int Vefcontrasenia,pass;

 ifstream archivolectura("Registro.txt");
 cout<<"---------------------------------------------\n";
 cout<<"\t\t*** INICIO *** \n";
while(!archivolectura.eof()){
archivolectura>>NombreDocente>>ApellidoDocente>>NombreUsuario>>Vefcontrasenia;

if (!archivolectura.eof()){
   do{
    cout<<" USUARIO: ";
    while(getchar()!='\n');
    getline(cin,usuario);
    if(usuario == NombreUsuario){
      cout<<""<<endl;
    }

    }while (usuario != NombreUsuario);

    do{
    cout<<" PASSWORD: ";
    cin>>pass;
    if(pass == Vefcontrasenia){
      cout<<""<<endl;
    }
    else{
      cout<<"PASSWORD INCORRECTO"<<endl;
      cout<<"\nINGRESE NUEVAMENTE ";
    }
    }while (pass != Vefcontrasenia);
    system("cls");
  cout<<"\t\t\t\t------------BIENVENIDO--------------\n";
  cout<<"\t\t\t\tDOCENTE: "<<NombreDocente<<" "<<ApellidoDocente<<endl;
  cout<<"\t\t\t\t------------------------------------\n"<<endl;

}
}
 archivolectura.close();
}

void eliminar()
{
    string NombreDocente;
   string ApellidoDocente;
   string NombreUsuario;
   int Contrasenia,Vefcontrasenia;
    ifstream archivolectura;
    archivolectura.open("Registro.txt", ios::in);
    ofstream entrada;
    entrada.open("Temporal.txt", ios::out);
    string aux;
    cout << "Ingrese Usuario a eliminar: ";
    cin >> aux;
    archivolectura>> NombreDocente>> ApellidoDocente >> NombreUsuario >> Contrasenia>>Vefcontrasenia;
    while (!archivolectura.eof())
    {
        archivolectura>> NombreDocente>> ApellidoDocente >> NombreUsuario >> Contrasenia>>Vefcontrasenia;
        if (aux == NombreUsuario)
        {
            cout << "Usuario eliminado";

        }
        else {
            entrada <<NombreDocente<<ApellidoDocente<< NombreUsuario<<Contrasenia <<Vefcontrasenia<<endl;
        }
        archivolectura >> NombreDocente>> ApellidoDocente>> NombreUsuario >> Contrasenia>>Vefcontrasenia;
        cout<<"SU CUENTA FUE EL ELIMINADA "<<endl;

    }
      cout<<"SU CUENTA FUE EL ELIMINADA "<<endl;
    entrada.close();
    archivolectura.close();
    remove("Registro.txt");
    rename("Temporal.txt", "Registro.txt");
    system("PAUSE");
}


