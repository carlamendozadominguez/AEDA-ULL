/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Agente.cpp
 * Author: carla
 * 
 * Created on 25 de febrero de 2018, 17:15
 */

#include "Agente.h"
#include "Tablero.hpp"


Agente::Agente(){
    x_ = 0;
    y_ = 0;
    orientacion_ = 0;
    max_move = 100;
    
}

Agente::Agente(int x, int y, int m_iter) {
    x_ = x;
    y_ = x;
    orientacion_ = 0;
    max_move = m_iter;
}

Agente::~Agente(){}



 int Agente::get_x(){
    return x_;
}

 int Agente::max_iter(){
    return max_move;
}

 int Agente::get_y(){
    return y_;
}

 int Agente::get_orientacion(void){
    return orientacion_;
}

 void Agente::set(int x, int y){
    x_ = x;
    y_ = y;
}

 void Agente::forward(){
    
    //Segun para donde mire la hormiga ir para delante sera distinto
    switch(orientacion_){
        case 0:   //NORTE
            x_--;
            break;
            
        case 1: //ESTE
            y_++;
            break;
            
        case 2: //SUR
            x_++;
            break;
            
        case 3:   //OESTE
            y_--;
            break;
    }
}
 
 void Agente::turn_r(void){   
    orientacion_ = (orientacion_ + 1) % 4;   
}

 void Agente::turn_l(void){
    orientacion_ = (orientacion_ + 3) % 4;  
}

 void Agente::go_back(void){
    orientacion_ = (orientacion_ + 2) % 4;
}

 void Agente::set_orientacion(int o){
    orientacion_ = o;
}

 void Agente::write(ostream& os) const{
     
     os<<setw(2);
    switch(orientacion_){
        case 0:   //NORTE
            os << "^";
            break;
            
        case 1: //ESTE
            os << ">";
            break;
            
        case 2: //SUR
            os << "v";
            break;
            
        case 3:   //OESTE
            os << "<";
            break;
    }
}
 
 void Agente::caminar(Tablero &rejilla){
     
     
    siguiente_paso(rejilla);
    forward(); 
     
     if(rejilla.get_color(get_x(),get_y()) == -1){
         go_back();
         forward();
     }
    
         

     //Si la hormiga se sale del tablero aparece por el otro lado
    if(get_y() >= rejilla.get_n()){
        set(get_x(),0);
    }
    
    else if(get_x() >= rejilla.get_m()){
        set(0,get_y());
    }
    
    else if (get_y() < 0){
        set(get_x(),rejilla.get_n()-1);
    }
    else if(get_x() < 0){
        set(rejilla.get_m()-1,get_y());
    }
 } 

Agente& Agente::operator=(const Agente& other){
  
    if(this != &other){
        this->x_ = other.x_; 
        this->y_ = other.y_;
        this->orientacion_ = other.orientacion_;
        this->max_move = other.max_move;
    }
    return *this;
    
}