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
        cout << "\nDigita el inicio del rango: " << endl;
        cin >> *inicio;
        *inicio = toupper(*inicio);
        cout << "\nDigita el fin del rango: " << endl;
        cin >> *fin;
        *fin = toupper(*fin);
    } while (*inicio < 'A' || *fin > 'Z' || *inicio > *fin);
}

void eleccion_rangoLetras_minusculas (char *inicio, char *fin) {
    do {
        cout << "(SOLO ENTRE a-z)" << endl;
        cout << "\nDigita el inicio del rango: " << endl;
        cin >> *inicio;
        *inicio = tolower(*inicio);
        cout << "\nDigita el fin del rango: " << endl;
        cin >> *fin;
        *fin = tolower(*fin);
    } while (*inicio < 'a' || *fin > 'z' || *inicio > *fin);
}


void menu () {
    cout << "\n|---------------------------------------|";
    cout << "\n|       - INTRODUCE TU ALFABETO -       |";
    cout << "\n|--------------------|------------------|";
    cout << "\n| 1. INDIVIDUAL      | 2. RANGO         |";
    cout << "\n|--------------------|------------------|";
    cout << "\n";
    puts ("\nSelecciona una opcion:");
}

void menu_rango () {
    cout << "\n|---------------------------------------|";
    cout << "\n|           - ELIGE LA OPCION -         |";
    cout << "\n|--------------------|------------------|";
    cout << "\n| 1. NUMEROS         | 2. LETRAS        |";
    cout << "\n|--------------------|------------------|";
    cout << "\n";
    puts ("\nSelecciona una opcion:");
}

void menu_rangoLetras () {
    cout << "\n|---------------------------------------|";
    cout << "\n|           - ELIGE LA OPCION -         |";
    cout << "\n|--------------------|------------------|";
    cout << "\n| 1. MAYUSCULAS      | 2. MINUSCULAS    |";
    cout << "\n|--------------------|------------------|";
    cout << "\n";
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
        cout << "Digita la cadena a evaluar:" << endl;
        cin >> *s1;
        }else{
            cout << "Digita una cadena valida" << endl;
            cin >> *s1;
        }

        if (*s1 == "_lam") {
            *s1 = lambda;
            break;
        }

        i++;
    } while (!verificar_cadena(*s1, a, tam2));
}

bool isSubsecuence (string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
        if (s1[j] == s2[i])
            j++;
    return (j==m);
    
}

void comparation(string s1,string s2,prefijo s2_prefijo,sufijo s2_sufijo){
  
  if (s1.compare(s2) == 0|| s1.compare(lambda) == 0) {
        cout << "W1:  "<<s1<<" es prefijo impropio de W2: "<<s2<<"."<< endl;
        cout << "W1: "<<s1<<" es sufijo impropio de W2: "<<s2<<"."<< endl;
        cout << "W1: "<<s1<<" es subcadena impropia de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" es subsecuencia de W2: "<<s2<<"." << endl;
    }else if(s2_prefijo.count(s1)){
        cout << "W1: "<<s1<<" es prefijo propio de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" no es sufijo de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" es subcadena propia de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" es subsecuencia de W2: "<<s2<<"." << endl;
    }else if(s2_sufijo.count(s1)){
        cout << "W1: "<<s1<<" no es prefijo de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" es sufijo propio de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" es subcadena propia de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" es subsecuencia de W2: "<<s2<<"." << endl;
    }else if(s2.find(s1) != string::npos){
        cout << "W1: "<<s1<<" no es prefijo de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" no es sufijo de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" es subcadena propia de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" es subsecuencia de W2: "<<s2<<"." << endl;
    }else if(isSubsecuence(s1,s2)){
        cout << "W1: "<<s1<<" no es prefijo de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" no es sufijo de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" no es subcadena de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" es subsecuencia de W2: "<<s2<<"." << endl;
    }else{
         cout << "W1: "<<s1<<" no es prefijo de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" no es sufijo de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" no es subcadena de W2: "<<s2<<"." << endl;
        cout << "W1: "<<s1<<" no es subsecuencia de W2: "<<s2<<"." << endl;
    }

}

// 1a, 2a, 3a     1a1a 1a2a 1a3a 2a1a 2a2a 2a3a 3a1a 3a2a 3a3a
string reverse(string const &s)
{
    string rev(s.rbegin(), s.rend());
    return rev;
}


void potencia(vt<string> alfabeto, int cantidad_alfabeto){
// a1, a2, a3     a1a1 a1a2 a1a3 a2a1 a2a2 a2a3 a3a1 a3a2 a3a3
   vt<string> potencia;
    for(int i=0;i<alfabeto.size();i++){
         for(int j=0;j<alfabeto.size();j++){
              potencia.push_back(alfabeto[i]+alfabeto[j]);
         }
    }
    cout << "Potencia del alfabeto: " << endl;
    for(int i=0;i<potencia.size();i++){
        cout << potencia[i] << " ";
    }
    cout << endl;

}


void solve_problemset6(vt<string> alfabeto, int cantidad_alfabeto){

do {
  cout << "Ingrese la potencia a la cual desea elevar el alfabeto (mayor a -5 y menor a 5):" << endl;
  cin >> cantidad_alfabeto;
}while (cantidad_alfabeto < -5 || cantidad_alfabeto > 5);


  if(cantidad_alfabeto == 0){
        cout<<"El alfabeto elevado a la potencia 0 es: lamda"<<endl;
  }else if(cantidad_alfabeto > 0){
        cout<<"El alfabeto elevado a la potencia "<<cantidad_alfabeto<<" es: "<<endl;
        potencia(alfabeto, cantidad_alfabeto);
    }else{
        cout<<"El alfabeto elevado a la potencia "<<cantidad_alfabeto<<" es: "<<endl;
        for(int i= 0; i<alfabeto.size();i++){
            alfabeto[i]= reverse(alfabeto[i]);
        }
        potencia(alfabeto, cantidad_alfabeto);
    }
}



/*
prueba de escritorio
 paro   pajaro
m = 4
n = 6
j = 0 
i = 0
s1[0] = p
s2[0] = p
j = 1

i = 1
s1[1] = a
s2[1] = a
j = 2

i = 2
s1[2] = r
s2[2] = j
j = 2

i = 3
s1[3] = o
s2[3] = a
j = 2

i = 4
s1[4] = r
s2[4] = r
j = 3

i = 5
s1[5] = o
s2[5] = o
j = 4

j = 4
m = 4
j == m
*/






/*
    int aux = 0;

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == s2[aux])
            aux++;

        if (aux == s2.size()) {
            return true;
        }

    return false;
}
*/
