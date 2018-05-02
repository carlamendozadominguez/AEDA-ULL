#include <climits>
#include <vector>
#include <ctime>
#include <map>
#include <iomanip>
#include <algorithm>


using namespace std;

bool MODO;  
int contador;  
#include "ABB.h"
#include "Dni.h"



int main (void){
    int opcion = 0;  
    
    //  Menú principal del programa
    while (opcion != 3){  
        cout << endl;
        cout << "----- MENU -----" << endl;
        cout << "\t1. Modo demostracion" << endl;
        cout << "\t2. Modo estadistico" << endl;
        cout << "\t3. Salir" << endl;
        cout << "Elija el modo de ejecucion: ";
        cin >> opcion;
        cout << endl;
        
        switch (opcion){
            case 1:{  // Si se ha elegido el modo demostración...
                MODO = 1;  
                
                cout << "Creando arbol binario de busqueda vacio...";
                ABB<Dni> ABB;  // Se crea el ABB vacío
                cout << endl;
                ABB.mostrar();  // Se muestra el ABB vacío
                cout << endl;
                
                int opcion_demo = 0;
                // Menú del modo demostración
                while (opcion_demo != 3){  
                    cout << endl;
                    cout << "----- MODO DEMOSTRACION -----" << endl;
                    cout << "\t1. Insertar clave" << endl;
                    cout << "\t2. Eliminar clave" << endl;
                    cout << "\t3. Menu principal" << endl;
                    cout << "Elija el modo de ejecucion: ";
                    cin >> opcion_demo;
                    cout << endl;
                    
                    switch (opcion_demo){
                        case 1:{  
                            long int aux; 
                            cout << "Introduzca la clave a insertar: ";
                            cin >> aux;
                            Dni new_dni(aux);
                            ABB.insertar(new_dni);  // Se inserta la clave en el ABB
                            cout << endl;
                            ABB.mostrar();  // Se muestra cómo ha quedado el ABB
                            cout << endl;
                            break;
                        }
                        case 2:{  
                            long int aux;  
                            cout << "Introduzca la clave a eliminar: ";
                            cin >> aux;
                            Dni new_dni(aux);
                            ABB.eliminar(new_dni);  // Se elimina la clave del ABB
                            cout << endl;
                            ABB.mostrar();  // Se muestra
                            cout << endl;
                            break;
                        }
                        case 3:{  //salir
                            break;
                        }
                        default:{  
                            cerr << "OPCION INCORRECTA!" << endl;
                        }
                    }
                }
                break;
            }
            
            case 2:{  
                MODO = 0;  
                srand(time(NULL));  // Se inicializa la semilla de generación aleatoria con la hora
                
                int N;  // Tamaño del ABB
                int nPruebas;  // Número de pruebas
                
                //Para las mediciones
                int med_aux = 0;  
                int min_ins = std::numeric_limits<int>::max();
                int max_ins = std::numeric_limits<int>::min();
                int min_busq = std::numeric_limits<int>::max();
                int max_busq = std::numeric_limits<int>::min();
                int med_busq = 0;
                int med_ins = 0;
                
                //Para elegir al azar 
                
                bool iguales;  // Para que no hayan Dni iguales
                vector<int> pos;  //Para evaluar y que no salga un mismo numero 2 veces
                vector<Dni> banco_pruebas;  
                ABB <Dni> ABB;  // Se crea el ABB vacío
                
                
                
                cout << "----- MODO ESTADISTICO -----" << endl;
                cout << "\nTamaño del arbol: ";
                cin >> N;
                cout << "Numero de pruebas: ";
                cin >> nPruebas;
                while ((nPruebas < 1) || (nPruebas > N)){
                    cerr << "Numero de pruebas fuera de rango!" << endl;
                    cout << "Numero de pruebas: ";
                    cin >> nPruebas;
                }
                
                banco_pruebas.clear();
                banco_pruebas.resize(2*N);  // Se redimensiona el banco de pruebas
                
                
                
                for (int i=0; i<banco_pruebas.size(); i++){
                    iguales = true;
                    while (iguales){
                        //Aqui genereamos el numero aleatorio entre el 00000000 - 999999999 
                        random_device rd; //Returns a new random number.
                        uniform_int_distribution<unsigned long int> dni (00000000,99999999);
                        
                        Dni aux(dni(rd)); 
                        
                        iguales = false;
                        
                        // Se comprueba que la posición generada no esté repetida
                        if(find (banco_pruebas.begin(),banco_pruebas.end(),aux)!= banco_pruebas.end()){
                            iguales = true;
                        }else{
                            banco_pruebas[i] = aux;
                        }
                        
                    }
                }
                
                // Se insertan en el árbol las N primeras matrículas del banco de pruebas
                for (int i=0; i< N; i++){
                    ABB.insertar(banco_pruebas[i]);
                    
                }
                
                
                //busqueda, media,max,min
                med_aux = 0;  
                int alea;
                pos.clear();  // Se limpia el vector de posiciones por si no estuviera vacío
                
                // Se realiza la búsqueda en el ABB de los nPruebas elementos extraídos de las N primeras posiciones del banco de pruebas
                for (int i=0; i<nPruebas; i++){
                    contador = 0;  // Se reinicia el contador
                    iguales = true;
                    // Mientras la posición generada ya haya sido escogida, se escoge otra aleatoriamente
                    while (iguales){
                        alea = rand() % N;  // Se genera una posición aleatoria entre 0 y N
                        
                        iguales = false;
                        
                        // Se comprueba que la posición generada no esté repetida
                        if(find (pos.begin(),pos.end(),alea)!= pos.end()){
                            iguales = true;
                        }else{
                            pos.push_back(alea);
                        }
                    }
                    
                    ABB.buscar(banco_pruebas[alea]);  // Se busca en el ABB el elemento del banco de pruebas correspondiente a la última posición generada
                    
                    
                    if (contador < min_busq){
                        min_busq = contador;
                    }
                    if (contador > max_busq){
                        max_busq = contador;
                    }
                    med_aux += contador;  // Se suma el contador a los anteriores
                }
                med_busq = med_aux / nPruebas;  // Se guarda el valor medio de comparaciones
                
                
                ////////// ESTUDIO DE LA INSERCIÓN //////////
                med_aux = 0; 
                
                pos.clear(); 
                pos.resize(nPruebas);  
                // Se realiza la búsqueda en el ABB de los nPruebas elementos extraídos de las N últimas posiciones del banco de pruebas
                for (int i=0; i<nPruebas; i++){
                    contador = 0;  // Se reinicia el contador
                    iguales = true;
                    // Mientras la posición generada ya haya sido escogida, se escoge otra aleatoriamente
                    while (iguales){
                        alea = rand() % N + N;  // Se genera una posición aleatoria entre N y 2N
                        
                        iguales = false;
                        // Se comprueba que la posición generada no esté repetida
                        if(find (pos.begin(),pos.end(),alea)!= pos.end()){
                            iguales = true;
                        }else{
                            pos.push_back(alea);
                        }
                    }
                    
                    ABB.buscar(banco_pruebas[alea]);  // Se busca en el ABB el elemento del banco de pruebas correspondiente a la última posición generada
                    // Si el nuevo contador es menor que el mínimo, el contador pasa a ser el nuevo mínimo
                    if (contador < min_ins){
                        min_ins = contador;
                    }
                    // Si el nuevo contador es mayor que el máximo, el contador pasa a ser el nuevo máximo
                    if (contador > max_ins){
                        max_ins = contador;
                    }
                    med_aux += contador;  // Se suma el contador a los anteriores
                }
                med_ins = med_aux / nPruebas;  // Se guarda el valor medio de comparaciones
                
                ////////// SE MUESTRA LOS RESULTADOS OBTENIDOS //////////
                cout << "\n\t\t----- NUMERO DE COMPARACIONES -----\n" << endl;
                cout << setw(15) << "" << setw(10) << "MINIMO" << setw(10) << "MEDIO" << setw(10) << "MAXIMO" << endl;
                cout << setw(15) << "Busqueda" << setw(10) << min_busq << setw(10) << med_busq << setw(10) << max_busq << endl;
                cout << setw(15) << "Insercion" << setw(10) << min_ins << setw(10) << med_ins << setw(10) << max_ins << endl;
                cout << endl;
                
                break;
            }
            case 3:{  // Salir
                break;
            }
            default:{  // Si no se ha elegido una opción de entre las del menú...
                cerr << "OPCION INCORRECTA!" << endl;
            }
        }
    }
    
    return 0;
}