#include <iostream>

using namespace std;

int main()
{
   int casilleros, cont, CantBuenas = 0;

   cout <<"Digite el numero de casilleros: ";
   cin >>casilleros;

    cout<<endl<<"Casilleros abiertos: ";
    for (int i = 1; i < 1+casilleros; i++)
    {
        cont=0;
        for (int j = 1; j <i; j++)
            if(i%j==0) 
                cont++;
        if(cont%2!=0)
        {
            cout<<i<<" "; 
            CantBuenas++;
        }
    }
   cout <<endl <<"Hay "<<CantBuenas<<" casilleros abieros"<<endl;
}
