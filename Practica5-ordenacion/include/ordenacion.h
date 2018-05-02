#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>


using namespace std;

extern int modo;
//CORRECTO

template<class Clave>
void heapsort(vector<Clave> &v){
    for (int i = (v.size()/2) -1; i >= 0; i--){
        baja(i,v,v.size());
    }
    for (int i = v.size() -1; i >=0 ; i--){
        Clave aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        baja(0,v,i);
    }
}

template<class Clave>
void baja (int i, vector<Clave> &v,int n){
    int larg = i;
    int l = 2*i +1;
    int r = 2*i + 2;
    
    if(modo == 0){
       getchar();

        for(int k = 0;k< n;k++){
            if(k == larg)
                cout<<termcolor::red<<v[k]<<" "<<termcolor::reset;
            else if( k == l)
                cout<<termcolor::blue<<v[k]<<" "<<termcolor::reset;
            else if(k == r)
                cout<<termcolor::yellow<<v[k]<<" "<<termcolor::reset;
            else
                cout<<v[k]<<" ";

        }
        cout<<endl;
    }
    
    if(l < n && v[l] > v[larg]){
        larg = l;
        //cout<<"BAJA "<<endl;
    }
    if(r < n && v[r]>v[larg]){
        larg = r;
        //cout<<" SUBE "<<endl;
    }
    if(larg != i){
        //cout<<"COLOCADO "<<endl;
        Clave x = v[i];
        v[i] = v[larg];
        v[larg] = x;
        
        baja(larg,v,n);
    }
}
template<class Clave>
void shellsort(int d,vector<Clave> &v){
    Clave x;
    int j;
    int it = 0;
    while( d > 0){
        d = d/2;
        for(int i = d; i < v.size(); i++){
            x = v[i];
            j = i;
            it++;
            
            if (modo == 0){
                getchar();
                cout<<"Iteracion: "<<it<<endl;
                for(int k = 0 ; k < v.size(); k++){
                    if(k == j)
                        cout<<termcolor::red<<v[j]<<" "<<termcolor::reset;
                    else if(k == (j-d))
                        cout<<termcolor::red<<v[j-d]<<" "<<termcolor::reset;
                    else
                        cout<<v[k]<<" ";
                }
                cout<<endl;
            }
            
            while((j >= d) && (x < v[j-d])){
                
                v[j] = v[j-d];
                j = j - d;
            }
            v[j] = x;
            
        }
    }
}



template<class Clave>
void insercion(vector<Clave> &v) {
    Clave temp;
    //vector<Clave> v = a;
    int j;
    for(int i = 1;i <= v.size()-1; i++) {
        temp = v[i];
        if(modo == 0){
           // getchar();
            cout << endl << "i = " << i << " ";
            for(int k = 0; k < v.size(); k++)
                if(k < i)
                    cout<<termcolor::green<<v[k]<<" "<<termcolor::reset;
                else if(k == i)
                    cout<<termcolor::red<<v[k]<<" "<<termcolor::reset;
                else
                    cout << " " << v[k] << " ";
        }
        j = i-1;
        
        while(( j >= 0 ) && ( temp < v[j] ) ){
            v[j+1] = v[j];    
            j = j-1;
        }
        if(modo == 0)
            cout << "  j = " << j+1;
        v[j+1] = temp; 
    }
    
   // a = v;
    
}


template<class Clave>
void burbuja(vector<Clave> &v) {
    Clave temp;
    int j;
    for(int i=1;i<v.size();++i){
        for(j= v.size()-1;j>= i;j--){
            if(modo == 0){
              //  getchar();
                cout <<endl<<"pos = (" << j <<"," << j-1 <<") ";
                for(int k = 0; k < v.size(); k++){
                    if((k == j) || (k == j-1))
                        cout<<termcolor::red<<" "<<v[k]<<termcolor::reset;
                    else
                        cout<<" " <<v[k];
                }
            cout<<endl;

            }
            
            if(v[j]<v[j-1]) {
                temp=v[j-1];
                v[j-1]=v[j];
                v[j]=temp;
                
                if(modo == 0){
                    cout<<"Intercambio:";
                    for(int k = 0; k < v.size(); k++)
                        if((k == j) || (k == j+1))
                            cout<<termcolor::green<<" "<<v[k]<<termcolor::reset;
                        else
                            cout<<" " <<v[k];
                }
            }
            
        }
    }
    
}


template<class Clave>
void Qsort(vector<Clave> &v, int ini, int fin) {
    
    int i = ini;
    int f = fin;
    Clave p = v[(i+f)/2];
    Clave x;
    
    if(modo == 0){
        getchar();
        cout<<"Pivote:"<<p<<", i ="<<i<<", f="<<f<<endl;
        for(int k = 0; k < v.size(); k++){
            if(k == i)
                cout<<termcolor::blue<<" "<<v[k]<<termcolor::reset;
            else if( k == f)
                cout<<termcolor::magenta<<" "<<v[k]<<termcolor::reset;
            
            else
                cout<<" "<<v[k];
        }
        
        cout<<endl;
    }
    
    while( i <= f){
        while (v[i] < p){
            i++;
            if(modo == 0){
                getchar();
                cout<<"Pivote:"<<p<<", i ="<<i<<", f="<<f<<endl;
                
                for(int k = 0; k < v.size(); k++){
                    if(k == i)
                        cout<<termcolor::blue<<" "<<v[k]<<termcolor::reset;
                    else if( k == f)
                        cout<<termcolor::magenta<<" "<<v[k]<<termcolor::reset;
                    
                    else
                        cout<<" "<<v[k];
                }
                cout<<endl;
            }
            
            
            
        }
        while (v[f] > p){
            f--;
            
            if(modo == 0){
                getchar();
                cout<<"Pivote:"<<p<<", i ="<<i<<", f="<<f<<endl;
                
                for(int k = 0; k < v.size(); k++){
                    if(k == i)
                        cout<<termcolor::blue<<" "<<v[k]<<termcolor::reset;
                    else if( k == f)
                        cout<<termcolor::magenta<<" "<<v[k]<<termcolor::reset;
                    
                    else
                        cout<<" "<<v[k];
                }
                cout<<endl;
            }
            
        }
        if( i <= f ){
            x = v[i];
            v[i] = v[f];
            v[f] = x;
            i++;
            f--;
            
            if(modo == 0){
                getchar();
                cout<<"Pivote:"<<p<<", i ="<<i<<", f="<<f<<endl;
                
                for(int k = 0; k < v.size(); k++){
                    if(k == i)
                        cout<<termcolor::blue<<" "<<v[k]<<termcolor::reset;
                    else if( k == f)
                        cout<<termcolor::magenta<<" "<<v[k]<<termcolor::reset;
                    
                    else
                        cout<<" "<<v[k];
                }
                cout<<endl;
            }
        }
    }
    
    if( ini < f)
        Qsort(v,ini,f);
    if( i < fin )
        Qsort(v,i,fin);
}
