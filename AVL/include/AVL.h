#include "ABB.h"

template <class T>
class AVL : public ABB<T>{
    
    public:
    
     AVL(void){
        this->raiz_ = NULL;
    }
            
    AVL (nodoBB<T>* raiz){
        ABB<T>(this->raiz_);
    }
            
     ~AVL (void){
        this->podar(this->raiz_);
    }
    
    void insertar(T dato){
        nodoBB<T> * nuevo = new nodoBB<T>(dato);
        nuevo->set_factor(0);
        bool crece = false;
        inserta_bal(this->raiz_, nuevo, crece);
    }
    
    void inserta_bal( nodoBB<T>* &nodo, nodoBB<T>* &nuevo, bool& crece) {
        if (!nodo) {
            nodo = nuevo;
            crece = true;
        }
 
	else{
		
		if (nuevo->get_dato() == nodo->get_dato()){
        	cerr << "Clave ya insertada!" << endl;
        }
		
        else if (nuevo->get_dato() < nodo->get_dato()) {
            inserta_bal(nodo->get_izq(),nuevo,crece);
                if (crece) {
                    insert_re_balancea_izq(nodo,crece);
                }
            }
        
         else {
            inserta_bal(nodo->get_dch(),nuevo,crece);
                if (crece) {
                    insert_re_balancea_dch(nodo,crece);
                }
        }
	}
}


void insert_re_balancea_dch(nodoBB<T>* &nodo, bool& crece){
	switch(nodo->get_factor()){
		case 1:	nodo->set_factor(0);
					crece = false;
					break;

		case 0:		nodo->set_factor(-1);
					break;

		case -1:	nodoBB<T>* nodo1 = nodo->get_dch();
					if(nodo1->get_factor()== -1)
						rotacion_DD(nodo);
					else
						rotacion_DI(nodo);
					crece = false;
					break;
					
	}
}

void insert_re_balancea_izq(nodoBB<T>* &nodo, bool& crece){
	switch(nodo->get_factor()){
		case -1:	nodo->set_factor(0);
					crece = false;
					break;

		case 0:		nodo->set_factor(1);
					break;

		case 1:	nodoBB<T>* nodo1 = nodo->get_izq();
					if(nodo1->get_factor() == 1)
						rotacion_II(nodo);
					else
						rotacion_ID(nodo);
					crece = false;
					break;
	}
}

void rotacion_II(nodoBB<T>* &nodo){	
	cout<<"ROTACION 2 ENLACES II"<<endl;
	nodoBB<T>* nodo1 = nodo->get_izq();
	nodo->izq_ = nodo1->get_dch();
	nodo1->dch_ = nodo;

	if(nodo1->get_factor() == 1){
		nodo->set_factor(0);
		nodo1->set_factor(0);
	}
	else{
		nodo->set_factor(1);
		nodo1->set_factor(-1);
	}
	nodo = nodo1;
}

void rotacion_DD(nodoBB<T>* &nodo){ 
	cout<<"ROTACION 2 ENLACES DD"<<endl;

	nodoBB<T>* nodo1 = nodo->get_dch();
	nodo->dch_ = nodo1->get_izq();
	nodo1->izq_ = nodo;

    if(nodo1->get_factor() == -1){
		nodo->set_factor(0);
		nodo1->set_factor(0);
	}
	else{
		nodo->set_factor(-1);
		nodo1->set_factor(1);
	}
	nodo = nodo1;
}

void rotacion_ID(nodoBB<T>* &nodo){ 
	cout<<"ROTACION 3 ENLACES ID"<<endl;
	nodoBB<T>* nodo1 = nodo->get_izq();
	nodoBB<T>* nodo2 = nodo1->get_dch();
	nodo->izq_ = nodo2->get_dch();
	nodo2->dch_ = nodo;
	nodo1->dch_ = nodo2->izq_;
	nodo2->izq_ = nodo1;
	

    if(nodo2->get_factor() == -1){
		nodo1->set_factor(1);
	}
	else{
		nodo1->set_factor(0);
	}
	if(nodo2->get_factor() == 1)
    	nodo->set_factor(-1);
	else
	    nodo->set_factor(0);
	
	nodo2->set_factor(0);    
	nodo = nodo2;
}


void rotacion_DI(nodoBB<T>* &nodo){ 
	cout<<"ROTACION 3 ENLACES DI"<<endl;

	nodoBB<T>* nodo1 = nodo->get_dch();
	nodoBB<T>* nodo2 = nodo1->get_izq();
	nodo->dch_ = nodo2->get_izq();
	nodo2->izq_ = nodo;
	nodo1->izq_ = nodo2->dch_;
	nodo2->dch_ = nodo1;
	

    if(nodo2->get_factor() == 1){
		nodo1->set_factor(-1);
	}
	else{
		nodo1->set_factor(0);
	}
	if(nodo2->get_factor() == -1)
    	nodo->set_factor(1);
	else
	    nodo->set_factor(0);
	
	nodo2->set_factor(0);    
	nodo = nodo2;
}

void eliminar(T dato){
  bool decrece = false;
	eliminar(this->raiz_,dato, decrece);  
}



void eliminar(nodoBB<T>* &nodo, T valor, bool& decrece){
	if(!nodo){
         cerr << "El nodo a eliminar no esta en el arbol!" << endl;
         return;
	}
	
	if(valor < nodo->get_dato()){
		eliminar(nodo->get_izq(), valor, decrece);
		if(decrece)
			eliminar_re_bal_I(nodo, decrece);
	}
	else if(valor > nodo->get_dato()){
		eliminar(nodo->get_dch(), valor,decrece);
		if(decrece)
			eliminar_re_bal_D(nodo, decrece);
	}
	else{
		nodoBB<T>* eliminado = nodo;
		if(!nodo->get_izq()){
			nodo = nodo->get_dch();
			decrece = true;
		}
		else if(!nodo->get_dch()){
			nodo = nodo->get_izq();
			decrece = true;
		}
		else{
			sustituye(eliminado, nodo->get_izq(), decrece);
			if(decrece)
				eliminar_re_bal_I(nodo, decrece);
		}
		delete eliminado;
	}
}

void  sustituye(nodoBB<T>* &eliminado, nodoBB<T>* &sust, bool &decrece){
	if(sust->get_dch()){
		sustituye(eliminado, sust->get_dch(), decrece);
		if(decrece)
			eliminar_re_bal_D(sust, decrece);
	}
	else{
		eliminado->dato_ = sust->get_dato();
		eliminado = sust;	// Cuidado con esto.
		sust = sust->get_izq();
		decrece = true;
	}
}

void eliminar_re_bal_I(nodoBB<T>* &nodo, bool& decrece){
	nodoBB<T>* nodo1 = nodo->get_dch();
	switch(nodo->get_factor()){
		case -1:	if(nodo1->get_factor() > 0)
						rotacion_DI(nodo);
					else{
						if(nodo1->get_factor() == 0)
							decrece = false;
						rotacion_DD(nodo);
					}
					break;
		case 0:		nodo->set_factor(-1);
					decrece = false;
					break;
		case 1:		nodo->set_factor(0);
	}
}


void eliminar_re_bal_D(nodoBB<T>* &nodo, bool& crece){
	nodoBB<T>* nodo1 = nodo->get_izq();
	switch(nodo->get_factor()){
		case 1:		if(nodo1->get_factor() < 0)
						rotacion_ID(nodo);
					else{
						if(nodo1->get_factor() == 0)
							crece = false;
						rotacion_II(nodo);
					}
					break;
		case 0:		nodo->set_factor(1);
					crece = false;
					break;
		case -1:	nodo->set_factor(0);
	}
}

};