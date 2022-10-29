/*
 *  File : main.cpp
 *  Autor: Jose Clavero y Charlie parra
 *  Fecha: 19 de octubre del 2022 
 *  Problema: PRACTICA 1 TEORIA COMPUTACIONAL
*/

#include "head.h"

int main() {
     int opcion, tam_string, cantidad_alfabeto, i = 1, j = 0;
     alfabeto a;
     vt<char> alfabeto_1 = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    //  Se imprime el menu
    eleccion_menu(&opcion);
 
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

     imprimir_alfabeto(a);



      }else if(opcion == 2){
        //RANGO
       menu_rango();
       cin>>opcion;
       if(opcion == 1){
            //RANGO NUMEROS
            int inicio, fin;
            do{
              cout<<"(SOLO ENTRE 0-9)"<<endl;
              cout<<"Digita el inicio del rango"<<endl;
              cin>>inicio;
              cout<<"Digita el fin del rango"<<endl;
              cin>>fin;
            } while (inicio < 0 || fin > 9 || inicio > fin);
            
            for(int i = inicio; i <= fin; i++) {
                string aux = to_string(i);
                a.ins(aux);
            }
           
            }else if(opcion == 2){
                //RANGO LETRAS
                menu_rangoLetras();
                cin>>opcion;
                
                if(opcion == 1){
                    //RANGO LETRAS MAYUSCULAS
                char inicio, fin;
                do{
                cout<<"(SOLO ENTRE A-Z)"<<endl;
                cout<<"Digita el inicio del rango"<<endl;
                cin>>inicio;
                inicio = toupper(inicio);
                cout<<"Digita el fin del rango"<<endl;
                cin>>fin;
                fin = toupper(fin);
                } while (inicio < 'A' || fin > 'Z' || inicio > fin);
                
                for(char i = inicio; i <= fin; i++) {
                    string aux = "";
                    aux += i;
                    a.ins(aux);
                }
                }else if(opcion == 2){
                    //RANGO LETRAS MINUSCULAS
                    char inicio, fin;
                    do{
                    cout<<"(SOLO ENTRE a-z)"<<endl;
                    cout<<"Digita el inicio del rango"<<endl;
                    cin>>inicio;
                    inicio = tolower(inicio);
                    cout<<"Digita el fin del rango"<<endl;
                    cin>>fin;
                    fin = tolower(fin);
                    } while (inicio < 'a' || fin > 'z' || inicio > fin);
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

   



 
        return 0;
}