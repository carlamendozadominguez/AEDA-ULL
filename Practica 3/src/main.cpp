/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carla
 *
 * Created on 24 de febrero de 2018, 11:56
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>


#include "Maquina.h"

using namespace std;

int main(int argc, char** argv) {
    
     int numero_iter = 200;
    Maquina maquina(25,25,12,12,200);
    maquina.siguiente_paso();
       
    return 0;
}

