/* Autor: John Corredor
   Fecha: 25 noviembre 2021
   Tema: JavaScritp */

/* Se requiere crear una plantilla para generar celdas con 
   filas y columnas. La cantidad de celdas debe ser ingresada
   a la función por el usuario. La idea es que se presente como una
   HOJA DE CALCULO. Se requiere generar las funciones de forma modular */

// columnas: es el número de columnas
// filas: es el número de filas 

function cNombre(column){
	var name= ''
	do {
		name= String.fromCharCode(column%26+65) + name 
		column = Math.floor(column/26)
	} while( column > 0)
	return name 
}

function c2Nombre(){
	var name= cNombre(this.column)
	name += this.row + 1
	return name 
}

function sToString() {
	var ssMostrar = '<table width="' + (50 + this.length*100) + '"' + 
			'border="1" cellspacing="1" cellpadding="1">' +
			'<tr><td width="50" align="center"></td>'  
	for (var column=0; column<this.length; column++){
		ssMostrar+='<td width="100" align="center"><b>'+
			   cNombre(column) + '</b></td>'
	}
	for (row=0; row<this[0].length; row++){
		ssMostrar += '</tr><tr><td align="center"><b>'+(row+1)+'</b>' 
		for (column=0; column<this.length; column++){
			ssMostrar+='</td><td align="center">'+
				   '<form name="' + this[column][row].name()+
				   '"><input type="text" size="10" value="'+
				   this[column][row].value+ '" onChange="'+
				   this.name +'['+column+']['+row+
				   '].value = this.value' + '"></form>'
		}
	} 
	ssMostrar+='</td></tr></table>'
	return ssMostrar
}

function sCelda(column,row,value){
	this.column = column
	this.row = row 
	this.name = c2Nombre
	this.value = value ? value : ''
}

function sColumna(column,rows){
	var i
	var auxCol = new Array(rows)
	for(i=0;i<rows;i++){
		auxCol[i] = new sCelda(column,i)
	}
	return auxCol
}

function sHoja(name, columns, rows){
	var i
	var sshoja = new Array(columns)
	for(i=0;i<columns;i++){
		sshoja[i] = new sColumna(i,rows)
	}
	sshoja.name = name 
	sshoja.toString = sToString
	return sshoja 
}

miHojaCalculo = sHoja("HojaMintic",3,3)

document.write(miHojaCalculo)

