/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ABB.h
 * Author: carla
 *
 * Created on 28 de abril de 2018, 11:34
 */

#ifndef ABB_H
#define ABB_H

#include <cstdio>
#include <iostream>

#include "nodoBB.h"
#include "cola_ABB.h"


//Variables externas
extern int contador; 
extern bool MODO;  

template <class T>
class ABB {
    private:
        nodoBB<T> *raiz_;  // Nodo raíz del árbol
        
        public:

            ABB (void){
                raiz_ = NULL;
            }
            
            ABB (nodoBB<T>* raiz){
                raiz_ = raiz;
            }
            
            ~ABB (void){
                podar(raiz_);
            }
            
            /* Elimina la rama cuya raíz se pasa como parámetro */
            void podar (nodoBB<T>* &nodo){
                if (nodo != NULL){  
                    podar(nodo->get_izq());  // Elimina el sub-árbol izquierdo
                    podar(nodo->get_dch());  // Elimina el sub-árbol derecho
                    delete nodo;  // Elimina el nodo
                    nodo = NULL;
                }
            }
            
            /* Busca un dato en todo el árbol */
            nodoBB<T>* buscar (T dato){
                return buscar_rama (raiz_, dato);
            }
            
            /* Busca un dato en una rama */
            nodoBB<T>* buscar_rama (nodoBB<T>* nodo, T dato){
                
                // Si el nodo está vacío, no se ha encontrado el dato buscado
                if (nodo == NULL){
                    return NULL;
                }
                if (dato == nodo->get_dato()){
                    return nodo;
                }
                if (dato < nodo->get_dato()){
                    return buscar_rama (nodo->get_izq(), dato);
                }
                if (dato > nodo->get_dato()){
                    return buscar_rama (nodo->get_dch(), dato);
                }
            }
            
            /* Inserta un dato en todo el árbol */
            void insertar (T dato){
                insertar_rama(raiz_, dato);
            }
            
            /* Inserta un dato en una rama */
            void insertar_rama (nodoBB<T>* &nodo, T dato){
                // Si el nodo está vacío, lo inserta en ese nodo
                if (nodo == NULL){
                    nodo = new nodoBB<T>(dato);
                }
                else{
                    // Si el dato es igual que el que se quiere insertar, se muestra un mensaje de error
                    if (dato == nodo->get_dato()){
                        cerr << "Clave ya insertada!" << endl;
                    }
                    // Si el dato NO es igual que el que se quiere insertar...
                    else{
                        // Si el dato es mayor que el que se quiere insertar, se inserta en la rama izquierda
                        if (dato < nodo->get_dato()){
                            insertar_rama(nodo->get_izq(), dato);
                        }
                        // Si el dato NO es mayor que el que se quiere insertar...
                        else{
                            // Si el dato es menor que el que se quiere insertar, se inserta en la rama derecha
                            if (dato > nodo->get_dato()){
                                insertar_rama(nodo->get_dch(), dato);
                            }
                        }
                    }
                }
            }
            
            /* Elimina un dato de todo el árbol */
            void eliminar (T dato){
                eliminar_rama(raiz_, dato);
            }
            
            /* Elimina un dato de una rama */
            void eliminar_rama (nodoBB<T>* &nodo, T dato){
                // Si la rama de la que se va a eliminar está vacía...
                if (nodo == NULL){
                    cerr << "El nodo a eliminar no esta en el arbol!" << endl;
                }
                // Si la rama de la que se va a eliminar NO está vacía...
                else{
                    // Si el dato es igual al que se quiere eliminar...
                    if (dato == nodo->get_dato()){
                        // Si la rama derecha está vacía, se sustituye el nodo a eliminar por el nodo raíz de la rama izquierda
                        if (nodo->get_dch() == NULL){
                            nodo = nodo->get_izq();
                        }
                        // Si la rama derecha NO está vacía...
                        else{
                            // Si la rama izquierda está vacía, se sustituye el nodo a eliminar por el nodo raíz de la rama derecha
                            if (nodo->get_izq() == NULL){
                                nodo = nodo->get_dch();
                            }
                            // Si el nodo tiene 2 hijos, se intercambia el dato a eliminar con el mayor de la rama izquierda
                            else{
                                nodoBB<T>* eliminar = nodo;  // Nodo que se pretende eliminar
                                sustituir(eliminar, nodo->get_izq());
                            }
                        }
                    }
                    // Si el dato NO es igual al que se quiere eliminar...
                    else{
                        // Si el dato es mayor que el que se quiere eliminar, se vuelve a llamar al método con la rama izquierda
                        if (dato < nodo->get_dato()){
                            eliminar_rama(nodo->get_izq(), dato);
                        }
                        // Si el dato NO es mayor que el que se quiere eliminar...
                        else{
                            // Si el dato es menor que el que se quiere eliminar, se vuelve a llamar al método con la rama derecha
                            if (dato > nodo->get_dato()){
                                eliminar_rama(nodo->get_dch(), dato);
                            }
                        }
                    }
                }
            }
            
            /* Intercambia el dato a eliminar con el mayor de la rama especificada (normalmente la izquierda) */
            void sustituir (nodoBB<T>* &eliminar, nodoBB<T>* &sust){
                // Si el nodo tiene hijo derecho (mayor), vuelve a llamar a la función con dicho hijo derecho
                if (sust->get_dch() != NULL){
                    sustituir(eliminar, sust->get_dch());
                }
                // Si el nodo no tiene hijo derecho, ya se ha encontrado el valor mayor de la rama
                else{  // Se intercambia el dato a eliminar con el valor mayor encontrado
                    eliminar->set_dato(sust->get_dato());
                    eliminar = sust;
                    sust = sust->get_izq();
                }
            }
            
            /* Imprime el árbol formateado */
            void mostrar(void) const {
                cola_ABB<T> cola;  // Cola para guardar los nodos por niveles
                nodoBB<T>* nodo;  // Nodo auxiliar
                int nivel = 0;  // Nivel auxiliar
                int nivel_actual = 0;  // Nivel actual
                cola.insertar(raiz_, nivel);  // Se inserta el primer nodo y nivel (nodo raíz y nivel 0)
                cout << "Nivel 0: ";
                // Mientras la cola no esté vacía...
                while (!cola.vacia()){
                    cola.extraer(nodo, nivel);  // Se extrae un nodo y nivel
                    // Si el nivel extraído es mayor que el nivel actual, se aumenta el nivel actual
                    if (nivel > nivel_actual){
                        nivel_actual = nivel;
                        cout << "\nNivel " << nivel_actual << ": ";
                    }
                    nodo->mostrar();
                    // Si el nodo extraído no está vacío, se insertan sus dos hijos en la cola
                    if (nodo != NULL){
                        cola.insertar(nodo->get_izq(), nivel+1);
                        cola.insertar(nodo->get_dch(), nivel+1);
                    }
                }
            }
            
            
};

#endif /* ABB_H */

