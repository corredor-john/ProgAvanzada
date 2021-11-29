function control(opcion){
	switch(opcion){
		case 'a': return "Se elige la opcion A";
			break;
		case 1: return "Se elige la opcion 1";
			break;
		case 'z': return "Se elige la opcion z";
			break;
		default:  return "Se elige cualquier otra cosa!!!"
			break;
	}
}

alert("Se envia a la funcion la opcion 1: " + control('a'));
