/*
 *  File : funciopnes.cpp
 *  Autor: Jose Clavero y Charlie parra
 *  Fecha: 19 de octubre del 2022 
 *  Problema: PRACTICA 1 TEORIA COMPUTACIONAL
*/

#include "head.h"

void eleccion_menu (int *opcion) {
    do {
        menu ();
        cout << endl << "-> ";
        cin >> *opcion;
    } while (*opcion > 2 || *opcion < 0);
}

void eleccion_menu_individual (int *cantidad_alfabeto) {
    do {
        cout << "Digita la cantidad de simbolos que tendra el alfabeto (al menos 3 simbolos)" << endl;
        cin >> *cantidad_alfabeto;
    } while (*cantidad_alfabeto < 3);
}

void eleccion_rangoNumeros (int *inicio, int *fin) {
    do {
        cout << "(SOLO ENTRE 0-9)" << endl;
        cout << "Digita el inicio del rango" << endl;
        cin >> *inicio;
        cout << "Digita el fin del rango" << endl;
        cin >> *fin;
    } while (*inicio < 0 || *fin > 9 || *inicio > *fin);
}

void eleccion_rangoLetras_mayusculas (char *inicio, char *fin) {
    do {
        cout << "(SOLO ENTRE A-Z)" << endl;
        cout << "Digita el inicio del rango" << endl;
        cin >> *inicio;
        *inicio = toupper(*inicio);
        cout << "Digita el fin del rango" << endl;
        cin >> *fin;
        *fin = toupper(*fin);
    } while (*inicio < 'A' || *fin > 'Z' || *inicio > *fin);
}

void eleccion_rangoLetras_minusculas (char *inicio, char *fin) {
    do {
        cout << "(SOLO ENTRE a-z)" << endl;
        cout << "Digita el inicio del rango" << endl;
        cin >> *inicio;
        *inicio = tolower(*inicio);
        cout << "Digita el fin del rango" << endl;
        cin >> *fin;
        *fin = tolower(*fin);
    } while (*inicio < 'a' || *fin > 'z' || *inicio > *fin);
}


void menu () {
    cout << "\n|---------------------------------------|";
    cout << "\n|       ° INTRODUCE TU ALFABETO °       |";
    cout << "\n|--------------------|------------------|";
    cout << "\n| 1. INDIVIDUAL      | 2. RANGO         |";
    cout << "\n|--------------------|------------------|";
    puts ("\nSelecciona una opcion:");
}

void menu_rango () {
    cout << "\n|---------------------------------------|";
    cout << "\n|           ° ELIGE LA OPCION °         |";
    cout << "\n|--------------------|------------------|";
    cout << "\n| 1. NUMEROS         | 2. LETRAS        |";
    cout << "\n|--------------------|------------------|";
    puts ("\nSelecciona una opcion:");
}

void menu_rangoLetras () {
    cout << "\n|---------------------------------------|";
    cout << "\n|           ° ELIGE LA OPCION °         |";
    cout << "\n|--------------------|------------------|";
    cout << "\n| 1. MAYUSCULAS      | 2. MINUSCULAS    |";
    cout << "\n|--------------------|------------------|";
    puts ("\nSelecciona una opcion:");
}

void imprimir_alfabeto (alfabeto a) {
    for (string c: a) {
        cout << "[ "<<c<<" ]" << endl;
    }
}

bool verificar_cadena (string s1, set<string> a, int tam2) {
    for (int i = 0; i < s1.size(); i+=tam2) {
        if (a.find(s1.substr(i, tam2)) == a.end()) {
            system("cls");
             cout << "La cadena "<<s1<<" no pertenece al alfabeto" << endl;
            return false;
        }
    }
    system("cls");
    cout << "La cadena "<<s1<<" pertenece al alfabeto" << endl;
    return true;
}
//perro (1,6) --> erro   perro : erro es subfijo de perro

void leer_validar_cadena (string *s1, set<string> a, int tam) {
    int i = 0;
    int tam2 = tam;
    do{
        if(i==0){
        cout << "Digita la cadena a evaluar" << endl;
        cin >> *s1;
        }else{
            cout << "Digita una cadena valida" << endl;
            cin >> *s1;
        }
        i++;
    } while (!verificar_cadena(*s1, a, tam2));

}


