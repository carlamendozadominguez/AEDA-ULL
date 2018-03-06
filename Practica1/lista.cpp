#include "lista.hpp"

template <class T>
List<T>::List(void) {
    head = NULL;
    tail = NULL;
    sz = 0;
}

template <class T>
List<T>::~List(void) {

    Node<T>* aux = NULL;

    while (head != NULL) {
        aux = head;
        head = head->get_next();
        delete aux;
        aux = NULL;
    }
    sz = 0;
    head = NULL;
    tail = NULL;
}

template <class T>
bool List<T>::empty(void) {
	
    if (head == NULL){
	   assert(tail == NULL);
	   assert(sz == 0);
	   return true;
	} 
    
    else{ 
	   return false;
    }
}

template <class T>
void List<T>::insert_head(Node<T>* nodo) {

    assert(nodo != NULL);
        if (empty()) {
            head = nodo;
            tail = head;
        }
        else {
            head->set_prev(nodo);
            nodo->set_next(head);
            head = nodo;
        }

     sz++;
}

template <class T>
void List<T>::insert_tail(Node<T>* nodo) {

    assert(nodo != NULL);

    if (empty()) {
        head = nodo;
        tail = head;
    } 
        
    else {
        tail->set_next(nodo);
        nodo->set_prev(tail);
        tail = nodo;
    }
    sz++;
}

template <class T>
Node<T>* List<T>::extract_tail(void) {
    
    assert(!empty());
    Node<T>* aux = tail;

    tail = tail->get_prev();

    if (tail != NULL)
        tail->set_next(NULL);
    
    else
        head = NULL;

    sz--;

	aux->set_next(NULL);
	aux->set_prev(NULL);

    return aux;
}

template <class T>
Node<T>* List<T>::extract_head(void) {

    assert(!empty());

    Node<T>* aux = head;
    head = head->get_next();

    if (head){
        head->set_prev(NULL);
    }
    else{
        tail = NULL;
    }

    sz--;

	aux->set_next(NULL);
	aux->set_prev(NULL);

    return aux;
}

template <class T>
Node<T>* List<T>::get_head(void) {
	return head;
}

template <class T>
Node<T>* List<T>::get_tail(void) {
	return tail;
}

template <class T>
ostream& List<T>::write(ostream& os) {		
    Node<T>* aux = head;

    while (aux != NULL) {
        aux->write(os);
        aux = aux->get_next();
    }
	return os;
}

template <class T>
void List<T>::remove(Node<T>* nodo) {
			
    assert(nodo != NULL);

    if (nodo->get_prev() != NULL){
        nodo->get_prev()->set_next(nodo->get_next());
    }
    else{
        head = nodo->get_next();
    }
     
    if (nodo->get_next() != NULL)
        nodo->get_next()->set_prev(nodo->get_prev());
    else
        tail = nodo->get_prev();

	delete nodo;

    sz--;

}

template <class T>
void List<T>::remove_pos(int pos){
    assert ( pos < sz );
    Node<T>* aux = get_head();
    int n = 0;
    
    while(n < pos-1){
        aux= aux->get_next();
        n++;
    }
    
    remove(aux->get_next());
 
}
template <class T>
T List<T>::get_pos(int pos){
    assert ( pos < sz );
    Node<T>* aux = get_head();
    int n = 0;
    
    while(n < pos-1){
        aux= aux->get_next();
        n++;
    }
    T dato = aux->get_data();
    return dato;
}
/*
template <class T>
void Lista<T>::set_pos(T& dato, int pos){
    assert ( pos < sz );
    
    if(pos == sz)
        insert_tail(new Node<int>(dato));
    
    else if(pos == 0)
        insert_front(new Node<int>(dato))
    else{
        Node<T>* aux2 = new Node<int>(dato);
        Node<T>* aux = get_head();
        int i = 0;
        
        while( i < pos-1){
            aux = aux->get_next();
	    i++;
	}
        
        aux2->get_next() = aux->get_next();
        
        aux ->get_next()->set_prev(aux)
        nodo->get_next()->set_prev(nodo->get_prev());
    }   
}
*/
template <class T>
int List<T>::get_size(void) {
    return sz;
}	

//PARA EL FALLO DEL ENLAZADOR
template class List<int>;
template class List<float>;
template class List<double>;
template class List<char>;