/*
 * taclistacalen.cpp
 *
 *  Created on: 25/2/2015
 *      Author: Diego
 */

//#define _TADLISTA_
#ifdef _TADLISTA_
#include "../include/tcalendario.h"
#include "../include/tvectorcalendario.h"
#include "../include/tlistacalendario.h"
#include <string.h>

int main(void){
	cout<<"Pruebas unitarias: [Expected - Obtained]"<<endl<<endl;

	/* CONSTRUCTOR VACIO */
	cout<<endl<<"Constructor por defecto:"<<endl;
	TListaCalendario lista1;
	cout<<"\t<> - "<<lista1<<endl;

	/* CONSTRUCTOR (lista) */
	cout<<endl<<"Constructor de copia solo lista vacia:"<<endl;
	TListaCalendario lista2(lista1);
	cout<<"\t<> - "<<lista2<<endl;

	/* INSERTAR CALENDARIO */
	cout<<endl<<"Insertar calendarios:"<<endl;
	TCalendario calVacio(13,3,1986,NULL);
	if(lista2.Insertar(calVacio)){
		cout<<"Insertado correctamente"<<endl;
	}else{
		cout<<"Insertado incorrectamente"<<endl;
	}
	cout<<"\t<13/03/1986 \"\"> - "<<lista2<<endl;

	if(lista2.Insertar(calVacio)){
		cout<<"Insertado incorrectamente"<<endl;
	}else{
		cout<<"No insertado, correcto"<<endl;
	}
	cout<<"\t<13/03/1986 \"\"> - "<<lista2<<endl;

	calVacio = calVacio+5;
	if(lista2.Insertar(calVacio)){
		cout<<"Insertado correctamente"<<endl;
	}else{
		cout<<"Insertado incorrectamente"<<endl;
	}
	cout<<"\t<13/03/1986 \"\" 18/03/1986 \"\"> - "<<lista2<<endl;

	calVacio = calVacio-2;
	if(lista2.Insertar(calVacio)){
		cout<<"Insertado correctamente"<<endl;
	}else{
		cout<<"Insertado incorrectamente"<<endl;
	}
	cout<<"\t<13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<lista2<<endl;

	cout<<endl<<"Constructor de copia sin lista vacia:"<<endl;
	TListaCalendario listaCopiada(lista2);
	cout<<"\t<13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaCopiada<<endl;

	/* SOBRECARGA ASIGNACION =  */
	cout<<endl<<"Sobrecarga asignacion = :"<<endl;
	TListaCalendario listaAsignada = lista2;
	cout<<"\t<13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	listaAsignada = lista1;
	cout<<"\t<> - "<<listaAsignada<<endl;

	/* INSERTAR */
	cout<<endl<<"Insertar:"<<endl;
	listaAsignada = lista2;
	cout<<"\t<13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	if(listaAsignada.Insertar(TCalendario()))
		cout<<"\t<01/01/1900 \"\" 13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	else
		cout<<"\t*ERROR*<01/01/1900 \"\" 13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	if(listaAsignada.Insertar(TCalendario()))
		cout<<"\t*ERROR*<01/01/1900 \"\" 13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	else
		cout<<"\t<01/01/1900 \"\" 13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;

	/* BORRAR */
	cout<<endl<<"Borrar (TCalendario):"<<endl;
	if(listaAsignada.Borrar(TCalendario()))
		cout<<"\t<13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	else
		cout<<"\t*ERROR*<13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	if(listaAsignada.Borrar(TCalendario()))
		cout<<"\t*ERROR*<13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	else
		cout<<"\t<13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	cout<<endl<<"Borrar (TListaPos):"<<endl<<
			"** SE USA DE TListaCalendario: Primera() y Ultima() **"<<endl<<
			"** SE USA DE TListaPos: Siguiente(), constructor, constructor de copia, = y == **"<<endl;
	TListaPos posicion = listaAsignada.Primera();
	TListaPos aComparar = posicion.Siguiente();aComparar = aComparar.Siguiente();
	if(listaAsignada.Borrar(posicion))
		cout<<"\t<16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	else
		cout<<"\t*ERROR*<16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	if(listaAsignada.Borrar(posicion))
		cout<<"\t*ERROR*<16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	else
		cout<<"\t<16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	if(listaAsignada.Borrar(TListaPos()))
		cout<<"\t*ERROR*<16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	else
		cout<<"\t<16/03/1986 \"\" 18/03/1986 \"\"> - "<<listaAsignada<<endl;
	TListaPos ultima = listaAsignada.Ultima();
	cout<<"\t1 - "<<(ultima==aComparar)<<endl;
	cout<<"\t0 - "<<(ultima==posicion)<<endl;
	cout<<"\t0 - "<<(ultima==TListaPos())<<endl;
	if(listaAsignada.Borrar(ultima))
		cout<<"\t<16/03/1986 \"\"> - "<<listaAsignada<<endl;
	else
		cout<<"\t*ERROR*<16/03/1986 \"\"> - "<<listaAsignada<<endl;
	cout<<endl<<"Borrar (int,int,int):"<<endl;
	if(listaAsignada.Borrar(31,12,2000))
		cout<<"\t<> - "<<listaAsignada<<endl;
	else
		cout<<"\t*ERROR*<> - "<<listaAsignada<<endl;
	listaAsignada.Insertar(TCalendario(13,3,1986,NULL));
	listaAsignada.Insertar(TCalendario(13,3,1988,NULL));
	listaAsignada.Insertar(TCalendario(13,3,1987,NULL));
	cout<<"\t<13/03/1986 \"\" 13/03/1987 \"\" 13/03/1988 \"\"> - "<<listaAsignada<<endl;
	if(listaAsignada.Borrar(13,4,1987))
		cout<<"\t<13/03/1988 \"\"> - "<<listaAsignada<<endl;
	else
		cout<<"\t*ERROR*<13/03/1988 \"\"> - "<<listaAsignada<<endl;

	/* OPERATOR +*/
	cout<<endl<<"Operator + :"<<endl;
	TListaCalendario lista3;
	calVacio = calVacio - 31;
	lista3.Insertar(calVacio);
	calVacio = calVacio + 3;
	lista3.Insertar(calVacio);
	calVacio = TCalendario(17,3,1986,NULL);
	lista3.Insertar(calVacio);
	cout<<"\t<13/03/1986 \"\" 16/03/1986 \"\" 18/03/1986 \"\"> - "<<lista2<<endl;
	cout<<"\t<13/02/1986 \"\" 16/02/1986 \"\" 17/03/1986 \"\"> - "<<lista3<<endl;
	TListaCalendario lista4 = lista2 + lista3;
	cout<<"\t<13/02/1986 \"\" 16/02/1986 \"\" 13/03/1986 \"\" 16/03/1986 \"\" 17/03/1986 \"\" 18/03/1986 \"\"> - "
			<<lista4<<endl;

	/* OPERATOR -*/
	cout<<endl<<"Operator - :"<<endl;
	cout<<"\t<13/02/1986 \"\" 16/02/1986 \"\" 13/03/1986 \"\" 16/03/1986 \"\" 17/03/1986 \"\" 18/03/1986 \"\"> - "
			<<lista4<<endl;
	TListaCalendario lista5 = lista4 - lista2;
	cout<<"\t<13/02/1986 \"\" 16/02/1986 \"\" 17/03/1986 \"\"> - "<<lista3<<endl;
	lista5 = lista5 - lista3;
	cout<<"\t<> - "<<lista5<<endl;

	/* EsVacia */
	cout<<endl<<"EsVacia :"<<endl;
	cout<<"\t1 - "<<(TListaCalendario().EsVacia())<<endl;
	cout<<"\t0 - "<<(lista3.EsVacia())<<endl;
	cout<<"\t1 - "<<(lista5.EsVacia())<<endl;

	/* Obtener */
	cout<<endl<<"Obtener :"<<endl;
	TListaPos obtenida = lista4.Primera();
	cout<<"\t13/02/1986 \"\" - "<<lista4.Obtener(obtenida)<<endl;
	obtenida = obtenida.Siguiente();
	cout<<"\t16/02/1986 \"\" - "<<lista4.Obtener(obtenida)<<endl;
	obtenida = TListaPos();
	cout<<"\t01/01/1900 \"\" - "<<lista4.Obtener(obtenida)<<endl;

	/* Buscar */
	cout<<endl<<"Buscar :"<<endl;
	cout<<"\t0 - "<<lista4.Buscar(TCalendario())<<endl;
	obtenida = obtenida.Siguiente();
	cout<<"\t1 - "<<lista4.Buscar(TCalendario(16,2,1986,NULL))<<endl;
	obtenida = TListaPos();
	cout<<"\t0 - "<<lista4.Buscar(TCalendario(16,2,1986,(char*)""))<<endl;
	cout<<"\t0 - "<<lista4.Buscar(TCalendario(16,2,1986,(char*)"Algo"))<<endl;

	/* Longitud */
	cout<<endl<<"Longitud :"<<endl;
	cout<<"\t0 - "<<TListaCalendario().Longitud()<<endl;
	cout<<"\t6 - "<<lista4.Longitud()<<endl;
	cout<<"\t3 - "<<lista3.Longitud()<<endl;
	cout<<"\t0 - "<<lista5.Longitud()<<endl;

	/* Sumar semilista */
	cout<<endl<<"Sumar sublistas :"<<endl;
	//Sumo dos listas con elementos y rangos validos
	TListaCalendario sublista;
	cout<<"\tlista3: <13/02/1986 \"\" 16/02/1986 \"\" 17/03/1986 \"\"> - "<<lista3<<endl;
	cout<<"\tlista4: <13/02/1986 \"\" 16/02/1986 \"\" 13/03/1986 \"\" 16/03/1986 \"\" 17/03/1986 \"\" 18/03/1986 \"\"> - "<<lista4<<endl;
	cout<<"\t<13/02/1986 \"\" 16/02/1986 \"\" 13/03/1986 \"\" 16/03/1986 \"\" 17/03/1986 \"\"> - "<<lista3.SumarSubl(1,3,lista4,2,4)<<endl;
	//Sumo dos listas con elementos y rangos invalidos
	cout<<"\t<> - "<<lista3.SumarSubl(4,3,lista4,5,4)<<endl;
	cout<<endl<<"\tPruebas con rangos invalidos:"<<endl;
	//Sumo dos listas con elementos y un rango invalido
	cout<<"\t<16/02/1986 \"\" 13/03/1986 \"\" 16/03/1986 \"\"> - "<<lista3.SumarSubl(4,3,lista4,2,4)<<endl;
	//Sumo dos listas con elementos y otro rango invalido
	cout<<"\t<13/02/1986 \"\" 16/02/1986 \"\" 17/03/1986 \"\"> - "<<lista3.SumarSubl(1,3,lista4,5,4)<<endl;
	//Sumo dos listas, una con elementos y rangos validos
	TListaCalendario nuevaVacia = TListaCalendario();
	cout<<"\t<16/02/1986 \"\" 13/03/1986 \"\" 16/03/1986 \"\"> - "<<nuevaVacia.SumarSubl(1,3,lista4,2,4)<<endl;
	//Sumo dos listas, otra con elementos y rangos validos
	cout<<"\t<13/02/1986 \"\" 16/02/1986 \"\" 17/03/1986 \"\"> - "<<lista3.SumarSubl(1,3,nuevaVacia,2,4)<<endl;

	/* ExtraerRango */
	cout<<endl<<"Extraer Rango :"<<endl;
	cout<<"\tlista3: <13/02/1986 \"\" 16/02/1986 \"\" 17/03/1986 \"\"> - "<<lista3<<endl;
	cout<<"\tRango invalido: <> - "<<lista3.ExtraerRango(4,3)<<endl;
	cout<<"\t<16/02/1986 \"\"> - "<<lista3.ExtraerRango(2,2)<<endl;
	cout<<"\tlista3: <13/02/1986 \"\" 17/03/1986 \"\"> - "<<lista3<<endl;

	cout<<endl<<"********* FIN *********"<<endl;
	return 0;
}
#endif
