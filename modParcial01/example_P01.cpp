/*
Programación avanzada 
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <map>

using namespace std;

//Estructura para capturar los resultados Max y N
struct resultados{
	int max_valor;
	int size_array;
	int *int_array;
};

//Prototipo funciones 
resultados generarVectorAleatorio();
void generarHistograma(resultados arg_generar);

//Función principal
int main() {
    //Declaración de variables
    bool centinela=true, centinela1=false;
    int op;
    resultados valores;
    int *p;

    //Loop para mostrar el menú
    while(centinela)
    {
        cout<<endl<<endl<<"MENU Parcial #1"<<endl;
        cout<<"\t0.Salir del programa"<<endl;
        cout<<"\t1.Crear vector aleatorio con numeros del 1 al 9 de tamaño n"<<endl;
        cout<<"\t2.Generar matriz de histograma"<<endl;
        
        //Pedida de opción a desarrollar
        cin>>op;
        switch(op)
        {
            case 0: 
                centinela=false;
                break;
            case 1: 
                valores=generarVectorAleatorio();
		cout << "\nMax: " << valores.max_valor << endl;
		cout << "Size:  " << valores.size_array << endl;
		p = valores.int_array;
		/*cout << "Vector:   " << endl;
		for (int i = 0; i < valores.size_array; i++, p++)
			cout << *p << " ";*/
                centinela1 = true;
                break;
            case 2: 
                //Verificación de ejecución de las funciones anteriores
                if(centinela1)
                {
                    //Llamado a función
                    generarHistograma(valores);
                }
                else
                    cout<<endl<<"Ejecute la primera opcion para crear vector a procesar"<<endl;
                break;
                
            default:
                //Opción de reserva en caso de entrada de datos errónea
                cout<<"Valor incorrecto, ingrese opcion valida"<<endl;
                break;
        }
    }
}

resultados generarVectorAleatorio() {
	//Declaración variables 
	resultados valor_funcion;
	valor_funcion.max_valor = 0;
	valor_funcion.size_array = 0;

	//Solicitud de datos 
	cout << endl << "Ingrese la cantidad de dias " << endl;
	cin >> valor_funcion.size_array;
	int *array_v = new int[valor_funcion.size_array];

	//Creación de array e impresión de datos
	cout << endl << "Vector aleatorio: " << endl;
	srand(time(0));
	for(int i=0; i< valor_funcion.size_array; i++){
		*(array_v + i) = (1+rand()%20);
		cout << *(array_v + i) << " ";
		if(valor_funcion.max_valor < *(array_v + i))
			valor_funcion.max_valor = *(array_v + i);
		}
	
	valor_funcion.int_array = array_v;
	
	return valor_funcion;
}

void generarHistograma(resultados arg_generar){
	//Declaración variables
	int T = arg_generar.size_array;
	int M = arg_generar.max_valor;
	int *v = arg_generar.int_array;
	int array_final[T] = {};
	int array_frec[T] = {};
	int new_size = 0;


	bool aux[T];
	for(int i=0; i < T; i++)
		aux[i] = 0;

	for(int i=0; i<T; i++){
		if(aux[i]== 1){
			continue;
		}
		int count = 1;
		for(int j = i+1; j<T; j++){
			if (v[i] == v[j]){
				aux[j] = 1;
       		     		count++;
			}
		}
		array_final[i] = v[i];
		array_frec[i] = count;
		//cout<<"frequency of "<< array_final[i]<<" is: " << array_frec[i] << endl;
	}

	cout << endl;
	cout << endl;


	vector<int> val_orig;
	vector<int> val_frec;
	for(int i=0;i<T;i++){
		int check1 = array_final[i];
		int check2 = array_frec[i];
		if(check1!=0){
			val_orig.push_back(check1);
			val_frec.push_back(check2);
		}
	}

vector<int>::iterator it1, it2;
/*
for ( it1=val_orig.begin() ; it1 < val_orig.end(); it1++,it2++){
	cout << " " << *it1 <<  "     " << *it2;
	cout << endl;
}
	cout << endl;
	cout << endl;
	cout << endl;
*/
	int c=19;
	int i=0;

	cout<<setw(9)  << "Index";
	cout<<setw(9)  << "Valor"<<" ";
	cout<<setw(12) << "Histograma\n";

for (it1=val_orig.begin(); it1 < val_orig.end(); it1++,it2++,i++){
//for(int i = 0; i< val_orig.size(); i++)
    cout<<setw(9) << i;
    cout<<setw(9) << val_orig[i];
    cout<<setw(12);
    for(int j = 0; j<val_frec[i]; j++)
    {
        cout<<"*";
    }
    cout<<endl;

}

}
