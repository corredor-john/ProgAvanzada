/*
Programa Parcial #1
Gabriel Martín 
Programación avanzada 
*/

//Inclusión librerías
#include <iostream>
#include <string.h>

using namespace std;

//Prototipo funciones 
void funcionCaracteres(string cadena, int n);

//Función principal
int main()
{
    int n;
    string cadena;

    cout<<"Ingrese la cantidad de caracteres a procesar"<<endl;
    cin>>n;
    cout<<"Ingrese caracteres a procesar"<<endl;
    cin>> cadena;
    funcionCaracteres(cadena, n);
}
void funcionCaracteres(string cadena, int n)
{
    char caracteres[n];
    int cont=0;
    
    for(int i=0;i<n;i++)
        caracteres[i]=cadena[i];
    for(int i=0;i<n;i++)
    {
        cont=0;
        for(int j=0;j<i;j++)
        {
            if(strcmp(caracteres[i],caracteres[j]))
                cont++;
            if(cont>9)
                cout<<"0 ";
            else
                cout<<cont<<" ";
        }
    }
}
