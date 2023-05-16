/**************************************************************************************************************************************************
 * Fecha: 13 - 02 - 2023
 *  ===== Programación Avanzada =====
 * Problema: Se requiere hacer una aplicación que capture los datos de usuarios según tipo de cliente. El resultado será
 * el valor a pagar según la cantidad de canales Premiun a pagar y conexiones de servicios básicos.
 * 	1.- Inicialmente el usuario deberá digitar el número de cuenta.
 * 	2.- Existen 2 tipos de cliente: r/R (Residencial) n/N (Negocios).
 * 	3.- El valor si es residencial es igual a 20.7 más 8.7 veces la (cantidad_canales_premium);
 * 	4.- El valor si es negocios, vendra definido por:
 * 		- Si la cantidad de conexiones_servicios_basicos es mayor a 10:
 * 			el valor es igual a el restante de los 10 (conexiones_servicios_basicos) más 78.9 más 18.9 veces (cantidad_canales_premium) 
 * 		- En caso contrario el valor es igual a 78.9 más 18.9 veces (cantidad_canales_premium) 
 * 	5.- Al final se pregunta al usuario si quiere ingresar otro cliente o no.
 **************************************************************************************************************************************************/


#include <iostream>

using namespace std;

int main()
{
    int NCuenta, prueba;
    float Con = 0, Can = 0, Kant = 0;
    bool centinela=true;
    char tipoCliente;

   while(centinela)
   {
        Con = 0;
        Can = 0;
        Kant = 0;

        cout <<"Digite el numero de cuenta: ";
        cin >>NCuenta;

        cout <<endl <<"Elija (r o R) si es residencial o (n o N) si es de negocios: ";
        cin >>tipoCliente;

        if (tipoCliente == 'r' || tipoCliente == 'R')
        {
            cout <<endl <<"Ingrese el numero de canales Premium: ";
            cin >>Can;
            Kant = 20.5 + (Can*7.5) + 4.5;
        }

        else if (tipoCliente == 'n' || tipoCliente == 'N')
        {
            cout <<endl <<"Ingrese el numero de conexiones de servicio basico: ";
            cin >>Con;
            cout <<endl <<"Ingrese el numero de canales Premium: ";
            cin >>Can;
            if ( Con > 10)
            {
                Con-=10;
                Kant = 75 + (Con*5) + (Can*5) + 15;
            }
            else
            {
                Kant =75 + (Can*5) + 15;
            }
        }
        cout <<endl << "Numero de cuenta = " << NCuenta << " Cantidad a pagar: $" << Kant;

        cout <<endl <<"Quiere ingresar otro cliente? Si=0 No=1 ";
        cin>>prueba;

        if(prueba==1)
            centinela=false;
    }
}
