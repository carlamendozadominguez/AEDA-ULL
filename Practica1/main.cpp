/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carla
 *
 * Created on 13 de febrero de 2018, 22:27
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lista.hpp"
#include "pila.hpp"
#include "cola.hpp"
#include "vector.hpp"
using namespace std;


int main(void){
    
    int option = 0;
    srand(time(NULL));
    int num = 4+rand()%10;
    List<int> lista;
    Pila<char> pila_lista;
    Cola <int> queue;
    Vector <int> w(10);
    Node<int> *nodo;
    int dato;
    
    stack<int> pila1;
    pila1.push(1);
    
    lista.insert_head(new Node<int>(1,pila1));
   
    
    while(option != 5){
        cout<<endl<<"MENU:"<<endl;
        cout<<"1. Lista"<<endl<< "2. Pila"<<endl;
        cout<< "3. Cola"<<endl << "4. Vector"<<endl;
        cout<<"5. Salir"<< endl<<endl;
        cout<< "Opcion:";
        cin >> option;
      switch(option){
          case 1:
              
             for(int i= 0; i < num;i++){
                int random = rand()%10; 
                lista.insert_head(new Node<int>(random));
             }
             cout<<" LISTA:";
             lista.write(cout);
             
             cout<<endl<<"Insertar un 0 en la pos 1:";
             lista.insert_head(new Node<int>(0));
             lista.write(cout);
             
             cout<<endl<<"Extraemos el numero insertado:";
             nodo = lista.extract_head();
             dato = nodo->get_data();
             delete nodo;
             lista.write(cout);
             
             cout<<endl<<"Insertar un 0 en la pos final:";
             lista.insert_tail(new Node<int>(0));
             lista.write(cout);
             
             cout<<endl<<"Extraemos el numero insertado:";
             nodo = lista.extract_tail();
             dato = nodo->get_data();
             delete nodo;
             lista.write(cout);
             
             cout<<endl<<"Devolver numero pos 3:"<<lista.get_pos(3);
             
             cout<<endl<<"Remove pos 3:";
             lista.remove_pos(2);
             lista.write(cout);
             
             
             while(!lista.empty()){
                 nodo = lista.extract_tail();
                 delete nodo;
             }
             
             cout<<endl<<endl;
             
            break;
          
          case 2:
   
            for(int i = 0; i < 10; i++){
                pila_lista.push('a' + i);
                cout << endl;
            }
            cout<<"PILA:";
            pila_lista.write(cout);
            
            cout << endl;
        
            cout<<"Insertamos una w en la primera pos(top):";
            pila_lista.push('w');
            pila_lista.write(cout);
            
            cout<<endl<<"mostramos en top:"<<pila_lista.top();
            
            cout<<endl<<"Eliminar el top de la pila:";
             pila_lista.pop();
             pila_lista.write(cout);
             
            while(!pila_lista.empty()){
                pila_lista.pop();
            }
            
             cout<<endl<<endl;
           break;
                
          case 3:
            for(int i= 0; i < num;i++){
                int random = rand()%10;
                queue.push(random);
            }
            
            cout<<"COLA:";
            queue.write(cout);
          
            cout<<endl<<"Insertamos un 1 en la cola:";
            queue.push(1);
            queue.write(cout);
            
            cout<<endl<<"Borramos elemento cola:";
            queue.pop();
            queue.write(cout);
            
            cout<<endl<<"Mostramos el front de la cola:"<<queue.front()<<endl;
            cout<<"Mostramos el back de la cola:"<<queue.back()<<endl;
             
            while(!queue.empty()){	
                queue.pop();
            }
           break;

    
         case 4:
             for(int i = 0; i < w.get_sz(); i++)
                w.get_set_v(i) = i;
             cout<<"VECTOR:";
             w.write(cout);
             
             cout<<endl<<"Mostrar el elemento 3:"<<w.get_v(3)<<endl;
             cout<<"Cambiar el elemento 3 del vector:";
             w.get_set_v(2)= 0;
             w.write(cout);
             cout << endl;
             
             break;
             
          case 5:
              cout<< "Saliendo...";
             break;
             
          default:
              cout<<"Eleccion invalida";
 
        }  
    }

	
        
        
        
	
        
}
