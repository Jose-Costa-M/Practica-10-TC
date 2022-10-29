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

     imprimir_alfabeto(a);



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
   cout<<"Ingrese dos cadenas pertenecientas al alfabeto designado: "<<endl;
   leer_validar_cadena(&s1, a, tam_string);
   leer_validar_cadena(&s2, a, tam_string);
   
//PROBLEMA 3: VERIFICAR SI S1 ES SUBCADENA, SUBSECUENCIA, PREFIJO O SUBFIJO DE S2
    
        if(subcadena(s1, s2)){
            cout<<"La cadena "<<s1<<" es subcadena de "<<s2<<endl;
        }else{
            cout<<"La cadena "<<s1<<" no es subcadena de "<<s2<<endl;
        }
  
        if(subsecuencia(s1, s2)){
            cout<<"La cadena "<<s1<<" es subsecuencia de "<<s2<<endl;
        }else{
            cout<<"La cadena "<<s1<<" no es subsecuencia de "<<s2<<endl;
        }
        if(prefijo(s1, s2)){
            cout<<"La cadena "<<s1<<" es prefijo de "<<s2<<endl;
        }else{
            cout<<"La cadena "<<s1<<" no es prefijo de "<<s2<<endl;
        }

        if(subfijo(s1, s2)){
            cout<<"La cadena "<<s1<<" es subfijo de "<<s2<<endl;
        }else{
            cout<<"La cadena "<<s1<<" no es subfijo de "<<s2<<endl;
        }




 
        return 0;
}
