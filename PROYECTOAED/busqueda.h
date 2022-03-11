int lineal (float arc[100],int tam,float dato)
{
    int i,j;
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam; j++)
        {
            if(arc[j]==dato)
            {
                return j;
            }
        }
    }
    return -1;
}
void pedir()
{
    ofstream archivo2;
    archivo2.open("Busqueda.txt",ios::app );
    archivo2<<"BUSQUEDA LINEAL\n";
    float  id;
    int x;
    cout <<"\t\t >> Ingrese Promedio a buscar a buscar: ";
    cin >> id;
    x=lineal(Promm,n,id );
    if (x!=-1)
    {
        cout <<" \t\t La nota  " <<id <<"  pertenete a  " <<nombre[x] <<endl;
        archivo2 <<" \t\t La nota  " <<id <<"  pertenete a  " <<nombre[x] <<endl;
    }
    else
    {

        archivo2<<"ELEMENTO NO ENCONTRADO" <<endl;
        cout<<"ELEMENTO NO ENCONTRADO"<<endl;
    }
    archivo2.close();

}
int binaria(float arc[100],int tam,float dato)
{
    int i,j,k,n;
    i=0;
    j=tam-1;
    k=(i+j)/2;
    while(i<=j)
    {

        if(arc[k]<dato)
            i=k+1;
        else if(arc[k]==dato)
        {
            return k;
        }
        else
            j=k-1;

        k=(i+j)/2;
    }

    if(i>j)
        n=-1;
    return n;
}
void pedir2()
{
    ofstream archivo2;
    archivo2.open("Busqueda.txt",ios::app );
    archivo2<<"BUSQUEDA BINARIA\n";
    float  id;
    int x;
    cout <<"\t\t >> Ingrese Promedio a buscar a buscar: ";
    cin >> id;
    x=binaria(Promm,n,id );
    if (x!=-1)
    {
        cout <<" \t\t La nota  " <<id <<"  pertenete a  " <<nombre[x] <<endl;
        archivo2 <<" \t\t La nota  " <<id <<"  pertenete a  " <<nombre[x] <<endl;
    }
    else
    {

        archivo2<<"ELEMENTO NO ENCONTRADO" <<endl;
        cout<<"ELEMENTO NO ENCONTRADO"<<endl;
    }
    archivo2.close();

}

void Interpolacion (float a[], int n)
{
    ofstream archivo2;
    archivo2.open("Busqueda.txt",ios::app );
    archivo2<<"BUSQUEDA POR INTERPOLACION\n";
    int primero = 0;

    int ultimo = n-1;

    int medio;

    int cont=0;

    float num;
    cout <<"Ingrese numero a buscar: ";
    cin >> num;
    while(a[primero] != num && cont<=7 )
    {
        medio = primero + ((num - a[primero])*(ultimo-primero))/(a[ultimo]-a[primero]);
        if(a[medio]<num)
        {
            primero = medio +1;
        }
        else if(a[medio]>num)
        {
            ultimo = medio-1;
        }
        else
        {
            primero = medio;
        }
        cont++;
    }
    if(a[primero]==num)
   {
        archivo2<<"\t\t La nota corresponde a " << getsNom()[primero] <<endl;
        cout<<"\t\t La nota corresponde a " << getsNom()[primero];
    }
    else
    {

        archivo2<<"ELEMENTO NO ENCONTRADO" <<endl;
        cout<<"ELEMENTO NO ENCONTRADO"<<endl;
    }
    archivo2.close();
}
