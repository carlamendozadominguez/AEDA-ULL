/*#include "nodoBB.h"

template <class T>
class nodoAVL : public nodoBB<T>{
    
    private:
        int factor_balanceo;
        
    public:
    
      nodoAVL(void){
          
      }
        
        ~nodoAVL(){
            factor_balanceo = 0;
        }
    
        nodoAVL(const T dato, nodoBB<T> *izq=NULL, nodoBB<T> *dch=NULL,int f){
            nodoBB(dato,izq,dch);
            factor_balanceo = f;
            
        }
        
        
        int get_factor(){
            return factor_balanceo;
        }

        void set_factor(int f){
            factor_balanceo = f;
        }    

    
    
     ~ nodoAVL (void){
                izq_ = NULL;
                dch_ = NULL;
            }
            

            
        
};*/