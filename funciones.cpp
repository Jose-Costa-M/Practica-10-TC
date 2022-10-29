/*
 *  File : funciopnes.cpp
 *  Autor: Jose Clavero y Charlie parra
 *  Fecha: 19 de octubre del 2022 
 *  Problema: PRACTICA 1 TEORIA COMPUTACIONAL
*/
#include "head.h"
void eleccion_menu(int *opcion){
    do {
        menu();
        cout<<endl<<"-> ";
        cin>>*opcion;

    } while (*opcion > 2 || *opcion < 0);
}	
void eleccion_menu_individual(int *cantidad_alfabeto){
    do {
        cout<<"Digita la cantidad de simbolos que tendra el alfabeto (al menos 3 simbolos)"<<endl;
        cin>>*cantidad_alfabeto;
    } while (*cantidad_alfabeto < 3);

  
}


void menu() {
        cout<<"\n|---------------------------------------|";
        cout<<"\n|       ° INTRODUCE TU ALFABETO °       |";
        cout<<"\n|--------------------|------------------|";
        cout<<"\n| 1. INDIVIDUAL      | 2. RANGO         |";
        cout<<"\n|--------------------|------------------|";
        puts("\nSelecciona una opcion:");
}

void menu_rango(){
        cout<<"\n|---------------------------------------|";
        cout<<"\n|           ° ELIGE LA OPCION °         |";
        cout<<"\n|--------------------|------------------|";
        cout<<"\n| 1. NUMEROS         | 2. LETRAS        |";
        cout<<"\n|--------------------|------------------|";
        puts("\nSelecciona una opcion:");
}

void menu_rangoLetras(){
        cout<<"\n|---------------------------------------|";
        cout<<"\n|           ° ELIGE LA OPCION °         |";
        cout<<"\n|--------------------|------------------|";
        cout<<"\n| 1. MAYUSCULAS      | 2. MINUSCULAS    |";
        cout<<"\n|--------------------|------------------|";
        puts("\nSelecciona una opcion:");
}

void imprimir_alfabeto(alfabeto a){
    for(string c: a) {
        cout<<"[ "<<c<<" ]"<<endl;
    }
}