/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Maquina.cpp
 * Author: carla
 * 
 * Created on 25 de febrero de 2018, 17:49
 */

#include "Maquina.h"

Maquina::Maquina(){}

Maquina::Maquina(int m, int n, int x, int y,int m_iter){
    
    hormiga.push_back(new HormigaDDII(x,y,m_iter));
    
    hormiga.push_back(new HormigaDIDI(x+5,y+5,m_iter));
    
    hormiga.push_back(new HormigaIIDD(x-4,y-4,m_iter));

    
    rejilla = Tablero(m,n);
    iter = 0;
}

Maquina::~Maquina(){}
    
int Maquina::get_iter(void){
    return iter;
}

void Maquina::incrementar_iter(void){
    iter ++;
}
   
int Maquina::max_iter(){
    return 1000;
}
void Maquina::siguiente_paso(void){
    
    while(get_iter() < max_iter() ){
        write(cout);
        for(int i = 0; i < hormiga.size(); i++)
             hormiga[i]->caminar(rejilla);
       
        // delay for 1 seconds
        for(int i = 0 ; i < 1 ; i++) { usleep(1000 * 1000); }
            cout << "\x1B[2J\x1B[H";  //Limpiamos pantalla
    }
    
    
    incrementar_iter();           
}

void Maquina::write(ostream& os){
    rejilla.write(os,hormiga);
}