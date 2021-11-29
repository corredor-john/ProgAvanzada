/* Autor: John Corredor
   Fecha: 25 noviembre 2021
   Tema: JavaScritp */

/* Se requiere un bucle for, para calculo matemático, 
con un menu (case switch) */

var n = 3;

for (i = 1; i < n; i++){
	//Se quiere crear un número aleatorio
	//Y en función de número aleatorio, entrará en el menu
	opcion = Math.floor((Math.random()*4) + 1)
	switch(opcion){
		case 1: document.writeln("Menu opcion 1");
			break
		case 2: document.writeln("Menu opcion 2");
			break
		case 3: document.writeln("Menu opcion 3");
			break
		default: document.writeln("Menu opcion no contemplada");
			break
	}
}

