#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>// Recursos para medir tiempos
#include <random>
#include <string>
#include <limits>
#include <iomanip>      // std::setw
#include "termcolor.hpp"
#include "ordenacion.h"
#include "Dni.hpp"


using namespace std;
using namespace std::chrono;


int modo;
int contador;


int main(int argc, char * argv[]) {
    
    int op = 0; //Opcion para el menu de ESTADISTICA O DEMOSTRACION
    int tam; //Tamanio del vector
    int nPruebas; //Numero de veces que repetimos el algortimo con distintos vectores
    int ord_opcion = 0;  // Opción para el menú de algoritmos de ordenación
    double del; //Variable delta para el algoritmo de shellsort
    int n_algoritmo;
    op = atoi(argv[1]);
    tam = atoi(argv[2]);
    nPruebas = atoi(argv[3]);
    del = 0.5;  
    n_algoritmo = atoi(argv[4]);        

    //  Menú principal del programa
    //while (op != 3){  // Mientras no se elija la opción para salir...
        //ord_opcion =0;
       /* cout << endl;
        cout << "----- MENU -----" << endl;
        cout << "\t1. Modo demostracion" << endl;
        cout << "\t2. Modo estadistico" << endl;
        cout << "\t3. Salir" << endl;
        cout << "Elija el modo de ejecucion: ";
        cin >> op;
        cout << endl;*/
        

        // Menu para elegir el algortimo que se quiere y nos ensene la traza
        switch(op){
             
            /**************************************
             *          MODO DEMOSTRACION         *
             * ************************************/
            case 1:{
                cout<<"Modo demostracion elegido"<<endl;
                modo = 0;
                cout << "\nTamaño de la secuencia a ordenar: ";
                cin >> tam;
                while ((ord_opcion < 1) || (ord_opcion > 7)){  // Mientras no se introduzca una opción válida
                    cout << endl;
                    cout << "----- ALGORITMO DE ORDENACION -----" << endl;
                    cout << "\t1. Ordenacion por insercion" << endl;
                    cout << "\t2. Ordenacion burbuja" << endl;
                    cout << "\t3. Ordenacion quicksort" << endl;
                    cout << "\t4. Ordenacion por shellsort" << endl;
                    cout << "\t5. Ordenacion por heapsort" << endl;
                    cout << "Elija el algoritmo de ordenacion: ";
                    cin >> ord_opcion;
                    cout << endl;
                }
                system("clear");
               
        
                //Creamos el vector de tamanio TAM introducido por el usuario
                vector<Dni> v (tam);
                
                //Aqui genereamos el numero aleatorio entre el 00000000 - 999999999 
                random_device rd; //Returns a new random number.
                uniform_int_distribution<unsigned long int> aux (000000000,999999999);
                
                for (int j=0; j< tam; j++){
                    v[j]= aux(rd);
                }
                
                //Nos muestra el vector resultante
                cout<<"---VECTOR GENERADO ALEATORIAMENTE:---"<<endl;
                for (int i = 0; i < tam; i++)
                    cout<<v[i]<<" ";
                
                //Ensenia la traza
                switch (ord_opcion){
                    case 1:  // Si se ha elegido insercion
                        cout << "\n\n--- ORDENACION POR INSERCION ---" << endl;
                        // Se llama a la función de la libreria ordenacion
                        insercion(v);
                        break;   
                        
                    case 2:
                        cout << "\n\n--- ORDENACION POR BURBUJA ---" << endl;
                        // Se llama a la función de la libreria ordenacion
                        burbuja(v);
                        break; 
                        
                    case 3:
                        cout << "\n\n--- ORDENACION POR QUICKSORT ---" << endl;
                        // Se llama a la función de la libreria ordenacion
                        Qsort(v,0,v.size()-1);
                        break; 
                        
                    case 4:{
                        cout << "\n\n--- ORDENACION POR SHELLSORT ---" << endl;
                        // Se llama a la función de la libreria ordenacion
                        del = -1; //Definimos delta a -1 para que entre en el bucle

                        //Pedimos el delta que el usuario quiera
                        while ((del < 0.1) || (del > 1)){
                            cout << "Introduzca la constante de reducción para la ordenación por incrementos 0 < alpha < 1: ";
                            cin >> del;
                        }
                        
                        // Se llama a la función de la libreria ordenacion
                        shellsort(v.size()*del,v);
                        break; 
                    }
                    
                    case 5:
                        cout << "\n\n--- ORDENACION POR HEAPSORT ---" << endl;
                        // Se llama a la función de la libreria ordenacion
                        heapsort(v);
                        break;
                        
                }                                   
                
                //Mostramos el vector ya ordenado
                cout<<endl<<endl<<"VECTOR ORDENADO:"<<endl;
                for (int i = 0; i < tam; i++)
                    cout<<v[i]<<" ";         
                break;
            }
            
            /**************************************
             *          MODO ESTADISTICO          *
             * ************************************/
            
            case 2:{
                modo = 1;
                //Pedimos los datos al usuario, numero de pruebas y tamanio de los vectores
               /* cout << "Tamaño de la secuencia a ordenar: ";
                cin >> tam;
                cout << endl << "Numero de pruebas:";
                cin >> nPruebas;*/
                
                //Creamos un vector de vectores de tipo clave y tamanio Npruebas * TAM
                vector<vector<Dni>> banco_pruebas;
                banco_pruebas.clear();
                banco_pruebas.resize(nPruebas,vector<Dni>(tam));
                const char * alg[] = {"Insercion", "Burbuja", "Quicksort", "Shellsort","Heapsort"}; //Vector de char para mostrar los algortimos
                
                
                unsigned t0, t1; //Variables para medir el tiempo empleado de cada algoritmo
                double time = 0;
                
                
                //Aqui genereamos el numero aleatorio entre el 00000000 - 999999999 
                random_device rd; //Returns a new random number.
                uniform_int_distribution<unsigned long int> aux (000000000,999999999);
                
                for (int i=0; i< nPruebas; i++)
                    for (int j=0; j<tam; j++)
                        banco_pruebas[i][j] = aux(rd);
                
               /* del = -1;
                
                while ((del < 0.1) || (del > 1)){
                    cout << "Introduzca la constante de reducción para la ordenación por incrementos 0 < alpha < 1: ";
                    cin >> del;
                }*/
                
               // cout << "---ESTADISTICAS---"<<endl;
                //cout << setw(30) << "MINIMO" << setw(10) << "MEDIO" << setw(10) << "MAXIMO"<< setw(15) << "T.MEDIO" << endl;
                
                
                int med_aux = 0;
                int min;
                int max;
                int med = 0;
                
                
                //while(n_algoritmo < 5){
                    contador = 0;
                    med_aux = 0;
                    min = std::numeric_limits<int>::max();
                    max = std::numeric_limits<int>::min();
                    med = 0;
                    time = 0;

                    for(int i = 0; i <nPruebas; i++){
                        contador = 0;
                        
                        if(n_algoritmo == 0){
                            t0 = clock();
                            insercion(banco_pruebas[i]);
                            t1=clock(); //anotamos el punto de de fin
                            
                        }
                        else if(n_algoritmo == 1){
                            t0 = clock();                            
                            burbuja(banco_pruebas[i]);
                            t1=clock(); //anotamos el punto de de fin
                            
                        }
                        else if(n_algoritmo == 2){
                            t0 = clock();                            
                            Qsort(banco_pruebas[i],0,banco_pruebas[i].size()-1);
                            t1=clock(); //anotamos el punto de de fin
                            
                        }
                        else if(n_algoritmo == 3){
                            t0 = clock();    
                            shellsort(banco_pruebas[i].size()*del,banco_pruebas[i]);
                            t1=clock(); //anotamos el punto de de fin
                            
                        }
                        else if(n_algoritmo == 4){
                            t0 = clock();                            
                            heapsort(banco_pruebas[i]);
                            t1=clock(); //anotamos el punto de de fin

                        }
                        
                         if (contador < min){  // Si el nuevo contador es menor que el mínimo
                            min = contador;  // El contador pasa a ser el nuevo mínimo
                        }
                        if (contador > max){  // Si el nuevo contador es mayor que el máximo
                            max = contador;  // El contador pasa a ser el nuevo máximo
                        }
                        
                        med_aux += contador;  // Se suma el contador a los anteriores
    
                        time += (double(t1-t0)/CLOCKS_PER_SEC);
                    }
                   
                    med = med_aux / nPruebas;
                    time /=  nPruebas;
                    cout<< tam <<"\t" << time<<endl;
                    //cout << setw(15) << alg[n_algoritmo]<< setw(10)<<"   " << min << setw(10) << med << setw(10) << max << setw(10) <<"   "<< time << endl;
                    
                  //  n_algoritmo++;
                    
                //}
                
            }
        }
   // }
    
    
    
}
