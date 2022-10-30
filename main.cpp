/*
 *  File : main.cpp
 *  Autor: Jose Clavero y Charlie parra
 *  Fecha: 19 de octubre del 2022 
 *  Problema: PRACTICA 1 TEORIA COMPUTACIONAL
*/

#include "head.h"

int main() {
     int opcion, tam_string = 1, cantidad_alfabeto, i = 1, j = 0;
     alfabeto a;
     vt<char> alfabeto_1 = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    //  Se imprime el menu
    eleccion_menu(&opcion);
 
 // PROBLEMA 1: LEER EL ALFABETO DE 2 FORMAS, INVIDIDUAL Y RANGO
      if(opcion == 1){
      //INDIVIDUAL
      eleccion_menu_individual(&cantidad_alfabeto);
      cout<<"Digita la longitud de cada simbolo"<<endl;
      cin>>tam_string;

      while(j < cantidad_alfabeto)
      {
        cout<<"Digita el simbolo "<< i <<endl;
        string aux;
        cin>>aux;
        if(aux.size() == tam_string && !(a.count(aux))){
        a.ins(aux);
        aux.erase();
        i++;
        j++;

        }else{
            cout<<"Simbolo invailo, por favor digite otro simbolo"<<endl;
        }
        
      }
     system("cls");
     cout<<"El alfabeto es: "<<endl;
     imprimir_alfabeto(a);
     cout<<endl;
     getchar();


      }else if(opcion == 2){
        //RANGO
       menu_rango();
       cin>>opcion;
       if(opcion == 1){
            //RANGO NUMEROS
            int inicio, fin;
            eleccion_rangoNumeros(&inicio, &fin);
            for(int i = inicio; i <= fin; i++) {
                string aux = to_string(i);
                a.ins(aux);
            }
           imprimir_alfabeto(a);

            }else if(opcion == 2){
                //RANGO LETRAS
                menu_rangoLetras();
                cin>>opcion;
                
                if(opcion == 1){
                    //RANGO LETRAS MAYUSCULAS
                char inicio, fin;
                eleccion_rangoLetras_mayusculas(&inicio, &fin);
                for(char i = inicio; i <= fin; i++) {
                    string aux = "";
                    aux += i;
                    a.ins(aux);
                }
                imprimir_alfabeto(a);

                }else if(opcion == 2){
                    //RANGO LETRAS MINUSCULAS
                    char inicio, fin;
                    eleccion_rangoLetras_minusculas(&inicio, &fin);
                    for(char i = inicio; i <= fin; i++) {
                    string aux = "";
                    aux += i;
                    a.ins(aux);
                }
                 imprimir_alfabeto(a);

                }
            }
       

      }else{
        cout<<"OPCION IVALIDA"<<endl;
     }

//PROBLEMA 2: LEER DOS CADENAS Y VERIFICAR SI ES VALIDA O NO
    string s1, s2;
    cout << "Ingrese dos cadenas pertenecientas al alfabeto designado (Si desea ingresar una cadena vacia, ingrese el comando _lam) : " << endl<<endl;
    leer_validar_cadena(&s1, a, tam_string);
    leer_validar_cadena(&s2, a, tam_string);
    cout <<endl<<"Las cadenas ingresadas son: " << endl;
    cout << "W1: " << s1 << endl;
    cout << "W2: " << s2 << endl;
    cout << endl;

//PROBLEMA 3: VERIFICAR SI S1 ES SUBCADENA, SUBSECUENCIA, PREFIJO O SUBFIJO DE S2
   prefijo s2_prefijo;
   sufijo  s2_sufijo;

   //almacenamos los prefijos de s2
    for(int i = 0; i < s2.size()-1; i++){
         string aux = "";
         for(int j = 0; j <= i; j++){
              aux += s2[j];
         }
         s2_prefijo.ins(aux);
    }
   cout<<"Los prefijos de la cadena s2 son: "<<endl;
   imprimir_alfabeto(s2_prefijo);
    //almacenamos los sufijos de s2
    for(int i = 0; i < s2.size(); i++){
         string aux = "";
         for(int j = i; j < s2.size(); j++){
              aux += s2[j];
         }
         s2_sufijo.ins(aux);
    }
    s2_sufijo.erase(s2);

    cout<<"Los sufijos de la cadena s2 son: "<<endl;
    imprimir_alfabeto(s2_sufijo);

    //PREFIJOS pajaro: pajar, paja, paj, pa, p
    //SUFIJOS pajaro: ajaro jaro aro ro o 
    cout<<endl;
    comparation(s1, s2, s2_prefijo, s2_sufijo);    
    cout<<endl;
//PROBLEMA 4: GENERAR LENGUAJES ALETAORIOS MEDIANTE EL ALFABETO INGRESADO
    int cantidad_cadenas;
    cout<<"Ingrese el longitud del lenguaje que desea generar: "<<endl;
    cin>>tam_string; //maginutud del lenguaje

    cout<<"Ingrese la cantidad de elementos que desea generar para cada elemento de su lenguaje: "<<endl;
    cin>>cantidad_alfabeto; // cantidad de elementos que tendra cada elemento del lenguaje
    cout<<endl;
    
   lenguaje L1,L2;

 //pasar nuestro alfabeto a un vector
    vt<string> alfabeto;
    for(auto it = a.begin(); it != a.end(); it++){
        alfabeto.push_back(*it);
    }

    //generar lenguaje1 aleatorio
    for(int i = 0; i < tam_string; i++){
        string aux = "";
        for(int j = 0; j < cantidad_alfabeto; j++){
            int random = rand() % alfabeto.size();
            aux += alfabeto[random];
        }
        L1.ins(aux);
    }

    //generar lenguaje2 aleatorio
    for(int i = 0; i < tam_string; i++){
        string aux = "";
        for(int j = 0; j < cantidad_alfabeto; j++){
            int random = rand() % alfabeto.size();
            aux += alfabeto[random];
        }
        L2.ins(aux);
    }

    cout<<"L1: "<<endl;
    imprimir_alfabeto(L1);
    cout<<endl;
    cout<<"L2: "<<endl;
    imprimir_alfabeto(L2);
    cout<<endl;

//PROBLEMA 5: REALIZAR LA RESTA DE LENGUAJES L1 - L2
   for(string s : L2){
       if(L1.count(s)){
           L1.erase(s);
       }
    }

    cout<<"L1 - L2: "<<endl;
    imprimir_alfabeto(L1);
    cout<<endl;

//PROBLEMA 6: OBTENER LA POTENCIA DEL ALFABETO INGRESADO

solve_problemset6(alfabeto, cantidad_alfabeto);

/*PROBLEMA 7: Todas las cadenas de letras en minúsculas (a-z) que contengan las cinco vocales en orden. 
Las vocales pueden estar repetidas (siempre que mantengan el orden), las secuencias de las vocales también pueden repetirse. 
La secuencia completa de vocales también puede repetirse.
Ejemplos de palabras aceptadas: rtaeioujutf, arteheejyibgfohgfdujhfd, aaaejhjhihgghgough, hknalleioomuwraamqekiodsu, aheklinmounmajkertebhiohjju, etc.
- Ejemplos de palabras no aceptadas: kayteemnoyug, ejuyaklengtivdfsojhgu, agheehklinmoythuvbazeyiawqeihjou
*/

//limpiamos memoria
a.clear();   
s2_prefijo.clear();
s2_sufijo.clear();
L1.clear();
L2.clear();
alfabeto.clear();
system("pause");
system("cls");


cout<<"Todas  las  cadenas  de  dígitos  que  tengan  por  lo  menos  un  dígito repetido."<<endl<<"Los dígitos no tienen que estar en orden."<<endl<<"La cadena debe tener una longitud mínima de 5 caracteres"<<endl;

solve_problemset7();
    return 0;
}
