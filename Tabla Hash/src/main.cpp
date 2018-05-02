/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carla
 *
 * Created on 1 de abril de 2018, 17:47
 */

#include "Tabla.h"
#include "Dni.hpp"

#include <vector>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <iostream>
#include <random>
#include <ctime> 


using namespace std;

int main (void)
{
    int Tsize, Vsize, Doption, Eoption, Npruebas;
    double Fcarga;
    
    cout << "Número de celdas de la tabla:  ";
    cin >> Tsize;
    cout << "Número de claves de cada celda:  ";
    cin >> Vsize;
    cout << endl;
    
    cout << "Indique la función de dispersión que desea utilizar: " << endl;
    cout << "\t1. Función módulo. " << endl;
    cout << "\t2. Números pseudo-aleatorios. " << endl;
    cout << "\t3. Función suma. " << endl;

    cin >> Doption;
    cout << endl;
    
    cout << "Indique la función de exploración que desea utilizar: " << endl;
    cout << "\t1. Lineal. " << endl;
    cout << "\t2. Cuadrática. " << endl;
    cout << "\t3. Doble dispersión. " << endl;
    cout << "\t4. Rehashing. " << endl;
    cin >> Eoption;
    cout << endl;
    
    cout << "A continuación indique los siguientes parámetros: " << endl;
    cout << "\tFactor de carga, un valor entre 0 y 1 ------>  ";
    cin >> Fcarga;
    cout << "\tNúmero de repeticiones de la operación, inserción o búsqueda, a realizar en el experimento ------>  ";
    cin >> Npruebas;
    cout << endl;
    
    int N = Fcarga * Tsize * Vsize;
    vector<Dni> BancoPruebas (2*N);

    //Aqui genereamos el numero aleatorio entre el 00000000 - 999999999 
    random_device rd; //Returns a new random number.
    string n;
    uniform_int_distribution<unsigned long int> aux (000000000,99999999);
   
    int a =0;

    for (int i=0; i<BancoPruebas.size(); i++){
        BancoPruebas[i] = aux(rd);
        cout<<"Name["<<i<<"]:";
        cin >> n;
        BancoPruebas[i].set_name(n);
        a = i;
    }

    unsigned long int dni_select;
    cout << endl << "Meter un Dni a mano:";
    cin >> dni_select;
    BancoPruebas[a] = dni_select;
    cout<<"Name["<<a<<"]:";
    cin >> n;
    BancoPruebas[a].set_name(n);
    
    int Imax=0, Imin=99999, dummy=0, Itotal=0;
    Tabla<Dni> tabla (Tsize, Vsize, Doption, Eoption, Npruebas);
    
    
    unsigned t0insert, t1insert;
    double timeinsert = 0;
    
    cout << endl << endl << "PRUEBA DE INSERCIÓN. N primeros elementos del banco de pruebas. " << endl << endl;
    for (int i=0; i<N; i++)
    {
        t0insert =clock();
        tabla.insertar(BancoPruebas[i]);
        t1insert = clock();

        timeinsert += (double(t1insert-t0insert)/CLOCKS_PER_SEC);

        dummy = tabla.get_count();

        cout<<"Count insert:"<<tabla.get_count()<<endl;


        tabla.print();

        Itotal += dummy;
        
        if (dummy < Imin)
            Imin = dummy;
        
        if (dummy > Imax)
            Imax = dummy;
        dummy = 0;
        tabla.reset_count();
    }
    
    cout << endl << endl << endl;
    tabla.print();
    cout << endl << endl << endl;
    
    unsigned t0busc, t1busc;
    double timebusc = 0;
    
    cout << "PRUEBA DE BÚSQUEDA. N elementos aleatorios del banco de pruebas. " << endl << endl;
    tabla.print_name();
    uniform_int_distribution<int> bus (0, N);
    int Bmax=0, Bmin=9999, Btotal=0;
    for (int i=0; i<N; i++)
    {
        t0busc =clock();
        tabla.buscar(BancoPruebas[bus(rd)]);
        t1busc = clock();
        
        timebusc += (double(t1busc-t0busc)/CLOCKS_PER_SEC);

        dummy = tabla.get_count();

        cout<<"Count busq:"<<tabla.get_count()<<endl;

        Btotal += dummy;
        
        if (dummy < Bmin)
            Bmin = dummy;
        if (dummy > Bmax)
            Bmax = dummy;
        dummy = 0;
        tabla.reset_count();

    }

    cout<<"Metiendo el dni introducido a mano"<<endl;
    tabla.insertar(BancoPruebas[BancoPruebas.size()-1]);
    cout<<"Dni que quieres buscar:"<<BancoPruebas[BancoPruebas.size()-1]<<endl;
    tabla.buscar(BancoPruebas[BancoPruebas.size()-1]);

    tabla.print_name();

    cout << endl << endl << endl;
    cout << "\tCeldas     Bloques     Exploración     Carga     Pruebas" << endl;
    cout << fixed << setw(6) << Tsize << "     ";
    cout << fixed << setw(6) << Vsize << "      ";
    cout << fixed << setw(6) << Doption << "        ";
    cout << fixed << setw(6) << Eoption << "      ";
    cout << fixed << setw(6) << Npruebas << endl << endl;
    
    
    int Imedio = Itotal / N;
    int Bmedio = Btotal / N;
    
    cout << "\t\t\tNÚMERO DE COMPARACIONES" << endl;
    cout << "            Mínimo     Medio     Máximo" << endl;
    cout << "Búsqueda    " << fixed << setw(8) << Bmin;
    cout << fixed << setw(8) << Bmedio;
    cout << fixed << setw(8) << Bmax << endl;
    cout << "Inserción    " << fixed << setw(8) << Imin;
    cout << fixed << setw(8) << Imedio;
    cout << fixed << setw(8) << Imax << endl;

    cout<<endl<<endl<<"Tiempo medio de insertar:"<<timeinsert/N<<endl;
    cout<<endl<<endl<<"Tiempo medio de buscar:"<<timebusc/N<<endl;

    return 0;
}

