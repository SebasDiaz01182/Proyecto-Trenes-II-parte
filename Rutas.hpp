#include <fstream> 
#include <iostream> 
#include <stdlib.h> 
#include<string> 
#include "Pais-Ciudad.hpp"
#include "Tipo-Tren.hpp" 
#include "Conexiones.hpp" 
#include "Trenes.hpp" 
#include "Usuario.hpp"
#pragma once 
using namespace std; 
 
class nodoCir { 
public: 
    nodoCir(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c, int precioc) 
    { 
        codTipTren = v; 
        codTren= trenc; 
        codRutas = rutac; 
        codPais1 = paisc; 
        codCiudad1 = ciudadc; 
        codPais2 = pais2c; 
        codCiudad2 = ciudad2c; 
        precio = precioc; 
        siguiente = NULL; 
    } 
 
    nodoCir(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc, nodoCir* signodo) 
    { 
        codTipTren = v; 
        codTren= trenc; 
        codRutas = rutac; 
        codPais1 = paisc; 
        codCiudad1 = ciudadc; 
        codPais2 = pais2c; 
        codCiudad2 = ciudad2c; 
        precio = precioc; 
        siguiente = signodo; 
    } 
     
public: 
    int codTipTren; 
    int codTren; 
    int codRutas ; 
    int codPais1 ; 
    int codCiudad1 ; 
    int codPais2 ; 
    int codCiudad2 ; 
    int precio; 
    nodoCir* siguiente; 
 
 
    friend class listaC; 
    friend class listaDC; 
    friend class listaDT; 
    friend class nodoDobleT; 
    friend class nodo;
	friend class nodoUsuario;
	friend class listaDCUsuario; 
}; 
 
typedef nodoCir* pnodoCir; 
 
class listaC { 
public: 
    listaC() { primero = NULL; } 
    ~listaC(); 
 
    void InsertarInicio(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc); 
    void InsertarFinal(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc); 
    void InsertarPos(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc, int pos); 
    bool ListaVacia() { return primero == NULL; } 
    void Mostrar(); 
    void BorrarFinal(); 
    void BorrarInicio(); 
    void borrarPosicion(int pos); 
    int largoLista(); 
    void llenarListaRutas(listaDC& paises, listaDT& tipoTrenes); 
    void ConsultarPrecio(listaDT tipoTrenes); 
    void InsertarRuta(listaDC& paises, listaDT& tipoTrenes); 
    void ConsultarRuta();
    void ModificarPrecio();
    void ModificarRuta(listaDC& paises);
 	void BorrarCiudades(listaDT& listaTrenes, listaDC& paises,listaDCUsuario& usuarios);
 	void BorrarPais(listaDC& paises,listaDCUsuario& usuarios);
 	void BorrarRuta(int& ultimaRutaEliminada);
 	void EliminarTren(string& ultimoTrenEliminado, listaDT& tipoTren);
public:
    pnodoCir primero; 
 
}; 
 
listaC::~listaC() 
{ 
    pnodoCir aux; 
 
    while (primero) { 
        aux = primero; 
        primero = primero->siguiente; 
        delete aux; 
    } 
 
} 
 
int listaC::largoLista() { 
    int cont = 0; 
 
    pnodoCir aux = primero; 
    if (ListaVacia()) 
        return cont; 
    else 
    { 
        while (aux->siguiente != primero) 
        { 
            cont++; 
            aux = aux->siguiente; 
        } 
        cont = cont + 1; 
        return cont; 
    } 
} 
 
void listaC::InsertarInicio(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc) 
{ 
     if (ListaVacia()){ 
    primero = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc, primero); 
    primero->siguiente=primero; 
    } 
   else{ // La funcionalidad de esta parte es que crea un nuevo nodo con el valor asignado y la direccion de primero, luego crea un aux con el valor de primero 
   // Al entrar al while con el parametro actualizado encontraremos el valor del aux que necesitamos para enlazar el nodo con la dirrecion anterior 
   // y posterior por lo que no se hara basura. 
       pnodoCir nuevo = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
       pnodoCir aux = primero; 
       while(aux->siguiente!=primero){ 
           aux=aux->siguiente; 
       } 
       aux->siguiente=nuevo; 
       primero=nuevo; 
   } 
} 
 
void listaC::InsertarFinal(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc) 
{ 
    if (ListaVacia()) 
    { 
    	cout<<"ListaVacia"<<endl; 
    	pnodoCir nuevo = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
    	primero= nuevo; 
    	primero->siguiente=primero; 
    } 
    else 
    { 
        pnodoCir nuevo = new nodoCir( v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
        pnodoCir aux = primero; 
        while (aux->siguiente != primero){ 
        	aux = aux->siguiente; 
		} 
		aux->siguiente=nuevo; 
		nuevo->siguiente=primero; 
    } 
} 
 
void listaC::InsertarPos(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc ,int pos) 
{ 
    if (ListaVacia()) 
    { 
        pnodoCir nuevo = new nodoCir( v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
        primero = nuevo; 
        nuevo->siguiente = primero; 
    } 
    else 
    { 
        if (pos <= 1) 
        { 
            InsertarInicio(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
        } 
        else 
        { 
            pnodoCir aux = primero; 
            int i = 2; 
            while ((i != pos) && (aux->siguiente != primero)) 
            { 
                i++; 
                aux = aux->siguiente; 
            } 
            pnodoCir nuevo = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
            nuevo->siguiente = aux->siguiente; 
            aux->siguiente = nuevo; 
        } 
    } 
} 
 
void listaC::BorrarFinal() 
{ 
    if (ListaVacia()) 
        cout << "No hay elementos en la lista:" << endl; 
    else 
    { 
        if (primero->siguiente == primero) 
        { 
            pnodoCir temp = primero; 
            primero = NULL; 
            delete temp; 
        } 
        else 
        { 
            pnodoCir aux = primero; 
            while (aux->siguiente->siguiente != primero) 
                aux = aux->siguiente; 
            pnodoCir temp = aux->siguiente; 
            aux->siguiente = primero; 
            delete temp; 
        } 
    } 
} 
 
void listaC::BorrarInicio() 
{ 
    if (ListaVacia()) 
        cout << "No hay elementos en la lista:" << endl; 
    else 
    { 
        if (primero->siguiente == primero) 
        { 
            pnodoCir temp = primero; 
            primero = NULL; 
            delete temp; 
        } 
        else 
        { 
            pnodoCir aux = primero; 
            pnodoCir temp = primero; 
            while (aux->siguiente != primero) 
                aux = aux->siguiente; 
            primero = primero->siguiente; 
            aux->siguiente = primero; 
            delete temp; 
        } 
    } 
} 
 
void listaC::borrarPosicion(int pos) 
{ 
    if (ListaVacia()) 
        cout << "Lista vacia" << endl; 
    else 
    { 
        if ((pos > largoLista()) || (pos < 0)) 
            cout << "Error en posicion" << endl; 
        else 
        { 
            if (pos == 1) 
                BorrarInicio(); 
            else 
            { 
                int cont = 2; 
                pnodoCir aux = primero; 
                while (cont < pos) 
                { 
                    aux = aux->siguiente; 
                    cont++; 
                } 
                pnodoCir temp = aux->siguiente; 
                aux->siguiente = aux->siguiente->siguiente; 
                delete temp; 
            } 
        } 
    } 
} 
 
void listaC::Mostrar() 
{ 
    pnodoCir aux = primero; 
    while (aux->siguiente != primero) 
    { 
        cout << aux->codTipTren << "-" << aux->codTren << "-" << aux->codRutas << "-" << aux->codPais1 << "-"<< aux->codCiudad1 << "-"<< aux->codPais2 << "-"<< aux->codCiudad2 <<"-"<< aux->precio << "-> "; 
        aux = aux->siguiente; 
    } 
    cout << aux->codTipTren << "-" << aux->codTren << "-" << aux->codRutas << "-" << aux->codPais1 << "-"<< aux->codCiudad1 << "-"<< aux->codPais2 << "-"<< aux->codCiudad2 <<"-"<< aux->precio << "-> "; 
    cout << endl; 
} 
 
void listaC::llenarListaRutas(listaDC& paises,listaDT& listaTrenes) { 
    ifstream archivo2; 
    string texto; 
    archivo2.open("Rutas.txt", ios::in); 
    if (archivo2.fail()) { 
        cout << "No se pudo abrir el archivo"; 
        exit(1); 
    } 
    while (!archivo2.eof()) { 
        getline(archivo2, texto); 
 
        int posPC = texto.find(";"); 
        int codTipTren = atoi(texto.substr(0, posPC).c_str()); 
        //cout << "Tipo Tren: " << codTipTren << endl; 
         
        string Todo = texto.substr(posPC + 1, texto.length()); 
        int posPC2 = Todo.find(";"); 
        int codTren = atoi(Todo.substr(0, posPC2).c_str()); 
        //cout << "Codigo Tren: " << codTren << endl; 
 
        string Todo2 = Todo.substr(posPC2 + 1, Todo.length()); 
        int posPC3 = Todo2.find(";"); 
        int codRuta = atoi((Todo2.substr(0, posPC3).c_str())); 
        //cout << "Codigo Ruta: " << codRuta << endl; 
 
        string Todo3 = Todo2.substr(posPC3 + 1, Todo2.length()); 
        int posPC4 = Todo3.find(";"); 
        int codPais = atoi((Todo3.substr(0, posPC4).c_str())); 
        //cout << "Codigo Pais: " << codPais << endl; 
 
        string Todo4 = Todo3.substr(posPC4 + 1, Todo3.length()); 
        int posPC5 = Todo4.find(";"); 
        int codCiudad = atoi((Todo4.substr(0, posPC5).c_str())); 
        //cout << "Codigo Ciudad: " << codCiudad << endl; 
 
        string Todo5 = Todo4.substr(posPC5 + 1, Todo4.length()); 
        int posPC6 = Todo5.find(";"); 
        int codPais2 = atoi((Todo5.substr(0, posPC6).c_str())); 
        //cout << "Codigo Pais: " << codPais2 << endl; 
 
        string Todo6 = Todo5.substr(posPC6 + 1, Todo5.length()); 
        int posPC7 = Todo6.find(";"); 
        int codCiudad2 = atoi((Todo6.substr(0, posPC7).c_str())); 
        //cout << "Codigo Ciudad: " << codCiudad2 << endl; 
 
        string Todo7 = Todo6.substr(posPC7 + 1, Todo6.length()); 
        int posPC8 = Todo7.find(";"); 
        int codPrecio = atoi((Todo7.substr(0, posPC8).c_str())); 
        //cout << "Precio: " << codPrecio << endl; 
         
        pnodo buscarPais = paises.primero; bool existePais = false; 
        while(buscarPais->siguiente!=paises.primero){ 
        	//cout<<buscarPais->valor<<"=="<<codPais<<endl; 
        	if(buscarPais->valor==codPais){ 
        		existePais = true; 
        		break; 
			} 
			else{ 
				buscarPais=buscarPais->siguiente; 
			} 
		}if(buscarPais->valor==codPais){ 
			existePais=true; 
		} 
		if(existePais){ 
			//cout<<"Pase pais1"<<endl; 
			pnodo buscarPais2 = paises.primero; bool existePais2 = false; 
        	while(buscarPais2->siguiente!=paises.primero){	 
        		if(buscarPais2->valor==codPais2){ 
        			existePais2 = true; 
        			break; 
				} 
				else{ 
					buscarPais2=buscarPais2->siguiente; 
				} 
			}if(buscarPais2->valor==codPais2){ 
				existePais2=true; 
			} 
			if(existePais2){ 
				//cout<<"Pase pais2"<<endl; 
				pnodoCiudad buscarCiudad = buscarPais->listaCiudades.primero;bool existeCiudad = false; 
				while(buscarCiudad->siguiente!=buscarPais->listaCiudades.primero){ 
					if(buscarCiudad->codCiudad==codCiudad){ 
						existeCiudad = true; 
						break; 
					} 
					else{ 
						buscarCiudad=buscarCiudad->siguiente; 
					} 
				}if(buscarCiudad->codCiudad==codCiudad){ 
					existeCiudad=true; 
				} 
				if(existeCiudad){ 
					//cout<<"Pase ciudad1"<<endl; 
					pnodoCiudad buscarCiudad2 = buscarPais2->listaCiudades.primero;bool existeCiudad2 = false; 
					while(buscarCiudad2->siguiente!=buscarPais2->listaCiudades.primero){ 
						if(buscarCiudad2->codCiudad==codCiudad2){ 
							existeCiudad2 = true; 
							break; 
						} 
						else{ 
							buscarCiudad2=buscarCiudad2->siguiente; 
						}	 
					}if(buscarCiudad2->codCiudad==codCiudad2){ 
						existeCiudad2=true; 
					} 
					bool existeCodTren = false;
					if(existeCiudad2){ 
						if(listaTrenes.Verificar(codTipTren,codTren)){
							existeCodTren=true;
						}
						if(existeCodTren){ 
								//cout<<"Entre hasta el final"<<endl; 
								if(ListaVacia()){ 
									//cout<<"if"<<endl; 
									InsertarInicio(codTipTren, codTren, codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio); 
								}else{ 
									//cout<<"else"<<endl; 
									pnodoCir buscarRepetidos = primero; bool repetido= false; 
									while(buscarRepetidos->siguiente!=primero){ 
										if(buscarRepetidos->codRutas==codRuta){ 
											repetido=true; 
											break; 
										}else{ 
											buscarRepetidos=buscarRepetidos->siguiente; 
										} 
									}if(!repetido){ 
										InsertarFinal(codTipTren, codTren, codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio);	 
									}else{ 
										//cout<<"ESTOY repetido"<<endl; 
										// por si esta repetido 
										continue; 
									} 
								} 
							} 
						 
					} 
					else{ 
						//cout<<"NO Pase ciudad2"<<endl; 
						// por si no existe la ciudad 2 
						continue; 
					}		 
				} 
				else{ 
					//cout<<"NO Pase ciudad1"<<endl; 
					//por si no existe la ciudad 1 
					continue; 
				} 
			} 
			else{ 
				//cout<<"NO Pase pais2"<<endl; 
				//por si no existe el pais2 
				continue; 
			} 
		} 
		else{ 
			//cout<<"NO Pase pais1"<<endl; 
			// por si no existe el pais 
			continue; 
		} 
    } 
    archivo2.close(); 
} 
 
 
void listaC::ConsultarPrecio(listaDT tipoTrenes){ 
	int codTipTren; 
	int codTren; 
	int codRuta; 
	cout<<"Ingrese el codigo de tipo de tren: "; cin>>codTipTren; cout<<endl; 
	cout<<"Ingrese el codigo de tren: "; cin>>codTren; cout<<endl; 
	cout<<"Ingrese el codigo de la ruta: "; cin>>codRuta; cout<<endl; 
	pnodoDobleT buscarTipTren = tipoTrenes.primero;bool existeTipTren = false; 
	while(buscarTipTren!=NULL){ 
		if(buscarTipTren->codTren==codTipTren){ 
			existeTipTren=true; 
			break; 
		} 
		else{ 
			buscarTipTren=buscarTipTren->siguiente; 
		} 
	} 
	if(existeTipTren){ 
		pnodoSimpTrenes buscarCodTren = buscarTipTren->listaDeTrenes.primero;bool existeCodTren = false; 
		while(buscarCodTren!=NULL){ 
			if(buscarCodTren->codTren==codTren){ 
				existeCodTren = true; 
				break; 
			} 
			else{ 
				buscarCodTren=buscarCodTren->siguiente; 
			} 
		} 
		if(existeCodTren){ 
			pnodoCir buscarRepetidos = primero; bool repetido= false; 
			while(buscarRepetidos->siguiente!=primero){ 
				if(buscarRepetidos->codRutas==codRuta){ 
					repetido=true; 
					break; 
				}else{ 
					buscarRepetidos=buscarRepetidos->siguiente; 
				} 
			}if(!repetido){ 
				cout<<"El codigo de ruta no existe"<<endl;	 
			}else{ 
				// por si esta repetido 
				cout<<"El precio de la ruta es "<<buscarRepetidos->precio<<endl; 
			} 
		} 
		else{ 
			cout<<"No existe el codigo de tren"<<endl; 
			//por si no existe el tren 
		} 
	} 
	else{ 
		cout<<"No existe el codigo de tipo de tren"<<endl; 
		// por si no existe el codTipotren 
	} 
}
 
void listaC::ConsultarRuta(){
 	int codTipTren; 
	int codTren; 
	cout<<"Ingrese el codigo de tipo de tren: "; cin>>codTipTren; cout<<endl; 
	cout<<"Ingrese el codigo de tren: "; cin>>codTren; cout<<endl; 
	if(ListaVacia()){
		cout<<"No hay ninguna ruta registrada"<<endl;
	}else{
		pnodoCir aux = primero; bool bandera=false;
		while (aux->siguiente != primero) { 	
	    	if ((aux->codTipTren==codTipTren)&&(aux->codTren==codTren)){
	    		cout <<"Codigo de ruta: " << aux->codRutas << " Pais: " << aux->codPais1 << " Ciudad: "<< aux->codCiudad1 << " Pais destino: "<< aux->codPais2 << " Ciudad destino: "<< aux->codCiudad2 <<" Precio: "<< aux->precio <<endl; 
	        	cout << endl;
	        	bandera=true;
				aux = aux->siguiente; 
			}else{
				aux = aux->siguiente; 
			}  
	    }if ((aux->codTipTren==codTipTren)&&(aux->codTren==codTren)){
	    		cout <<"Codigo de ruta: " << aux->codRutas << " Pais: " << aux->codPais1 << " Ciudad: "<< aux->codCiudad1 << " Pais destino: "<< aux->codPais2 << " Ciudad destino: "<< aux->codCiudad2 <<" Precio: "<< aux->precio <<endl; 
	        	cout << endl;
	        	bandera=true;
	    }
		if(!bandera){
	    	cout<<"No se encontro el codigo ingresado, porfavor vuelva a intentarlo"<<endl;
		}	
	}
 }
 
void listaC::ModificarPrecio(){
	int codRuta; 
	int nPrecio;
	cout<<"Ingrese el codigo de la ruta: "; cin>>codRuta; cout<<endl;
	cout<<"Ingrese el nuevo precio: "; cin>>nPrecio; cout<<endl;
	pnodoCir buscarRepetidos = primero; bool repetido= false; 
	while(buscarRepetidos->siguiente!=primero){ 
		if(buscarRepetidos->codRutas==codRuta){ 
			repetido=true; 
			break; 
		}else{ 
			buscarRepetidos=buscarRepetidos->siguiente; 
		} 
	}if(!repetido){ 
		cout<<"El codigo de ruta no existe"<<endl;	 
	}else{ 
		// por si esta repetido 
		buscarRepetidos->precio=nPrecio;
		cout<<"El nuevo precio de la ruta es "<<buscarRepetidos->precio<<endl; 
	}
}

void listaC::ModificarRuta(listaDC& paises){
	int codRuta;
	int codPais1;
	int codPais2;
	int codCiudad1;
	int codCiudad2;
	int nPrecio;
	cout<<"Ingrese el codigo de la ruta: "; cin>>codRuta; cout<<endl;
	cout<<"Ingrese el nuevo codigo de pais: "; cin>>codPais1; cout<<endl;
	cout<<"Ingrese el nuevo codigo de ciudad: "; cin>>codCiudad1; cout<<endl;
	cout<<"Ingrese el nuevo codigo de pais destino: "; cin>>codPais2; cout<<endl;
	cout<<"Ingrese el nuevo codigo de ciudad destino: "; cin>>codCiudad2; cout<<endl;
	cout<<"Ingrese el nuevo precio: "; cin>>nPrecio; cout<<endl;
	 pnodo buscarPais = paises.primero; bool existePais = false; 
        while(buscarPais->siguiente!=paises.primero){ 
        	//cout<<buscarPais->valor<<"=="<<codPais<<endl; 
        	if(buscarPais->valor==codPais1){ 
        		existePais = true; 
        		break; 
			} 
			else{ 
				buscarPais=buscarPais->siguiente; 
			} 
		}if(buscarPais->valor==codPais1){ 
			existePais=true; 
		} 
		if(existePais){ 
			//cout<<"Pase pais1"<<endl; 
			pnodo buscarPais2 = paises.primero; bool existePais2 = false; 
        	while(buscarPais2->siguiente!=paises.primero){	 
        		if(buscarPais2->valor==codPais2){ 
        			existePais2 = true; 
        			break; 
				} 
				else{ 
					buscarPais2=buscarPais2->siguiente; 
				} 
			}if(buscarPais2->valor==codPais2){ 
				existePais2=true; 
			} 
			if(existePais2){ 
				//cout<<"Pase pais2"<<endl; 
				pnodoCiudad buscarCiudad = buscarPais->listaCiudades.primero;bool existeCiudad = false; 
				while(buscarCiudad->siguiente!=buscarPais->listaCiudades.primero){ 
					if(buscarCiudad->codCiudad==codCiudad1){ 
						existeCiudad = true; 
						break; 
					} 
					else{ 
						buscarCiudad=buscarCiudad->siguiente; 
					} 
				}if(buscarCiudad->codCiudad==codCiudad1){ 
					existeCiudad=true; 
				} 
				if(existeCiudad){ 
					//cout<<"Pase ciudad1"<<endl; 
					pnodoCiudad buscarCiudad2 = buscarPais2->listaCiudades.primero;bool existeCiudad2 = false; 
					while(buscarCiudad2->siguiente!=buscarPais2->listaCiudades.primero){ 
						if(buscarCiudad2->codCiudad==codCiudad2){ 
							existeCiudad2 = true; 
							break; 
						} 
						else{ 
							buscarCiudad2=buscarCiudad2->siguiente; 
						}	 
					}if(buscarCiudad2->codCiudad==codCiudad2){ 
						existeCiudad2=true; 
					} 
					bool existeCodTren = false;
					if(existeCiudad2){ 
						pnodoCir buscarRepetidos = primero; bool repetido= false; 
						while(buscarRepetidos->siguiente!=primero){ 
							if(buscarRepetidos->codRutas==codRuta){ 
								repetido=true; 
								break; 
							}else{ 
								buscarRepetidos=buscarRepetidos->siguiente; 
							} 
						}if(!repetido){ 
							cout<<"El codigo de ruta no existe"<<endl;	 
						}else{ 
							// por si esta repetido 
							buscarRepetidos->precio=nPrecio;
							buscarRepetidos->codPais1=codPais1;
							buscarRepetidos->codPais2=codPais2;
							buscarRepetidos->codCiudad1=codCiudad1;
							buscarRepetidos->codCiudad2=codCiudad2;
							cout<<"La ruta modificada es: "<<endl;
							cout <<"Codigo de ruta: " << buscarRepetidos->codRutas << " Pais: " << buscarRepetidos->codPais1 << " Ciudad: "<< buscarRepetidos->codCiudad1 << " Pais destino: "<< buscarRepetidos->codPais2 << " Ciudad destino: "<< buscarRepetidos->codCiudad2 <<" Precio: "<< buscarRepetidos->precio <<endl; 
						}
				}else{
					cout<<"La ciudad destino no existe"<<endl;
				}
			}else{
				cout<<"La ciudad de origen no existe"<<endl;
			}
		}else{
			cout<<"El pais destino no existe"<<endl;
		}
	}else{
		cout<<"El pais de origen no existe"<<endl;
	}
}

void listaC::InsertarRuta(listaDC& paises, listaDT& tipoTrenes){ 
	int codPais; 
	int codPais2; 
	int codCiudad; 
	int codCiudad2; 
	int codPrecio; 
	int codTipTren; 
	int codTren; 
	int codRuta; 
	cout<<"Ingrese el codigo de tipo de tren: "; cin>>codTipTren; cout<<endl; 
	cout<<"Ingrese el codigo de tren: "; cin>>codTren; cout<<endl; 
	cout<<"Ingrese el codigo de la ruta: "; cin>>codRuta; cout<<endl; 
	cout<<"Ingrese el codigo del primer pais: "; cin>>codPais; cout<<endl; 
	cout<<"Ingrese el codigo de la primera ciudad: "; cin>>codCiudad; cout<<endl; 
	cout<<"Ingrese el codigo del segundo pais: "; cin>>codPais2; cout<<endl; 
	cout<<"Ingrese el codigo de la segunda ciudad: "; cin>>codCiudad2; cout<<endl; 
	cout<<"Ingrese el precio de la ruta: "; cin>>codPrecio; cout<<endl; 
	
        pnodo buscarPais = paises.primero; bool existePais = false; 
        while(buscarPais->siguiente!=paises.primero){ 
        	//cout<<buscarPais->valor<<"=="<<codPais<<endl; 
        	if(buscarPais->valor==codPais){ 
        		existePais = true; 
        		break; 
			} 
			else{ 
				buscarPais=buscarPais->siguiente; 
			} 
		}if(buscarPais->valor==codPais){ 
			existePais=true; 
		} 
		if(existePais){ 
			//cout<<"Pase pais1"<<endl; 
			pnodo buscarPais2 = paises.primero; bool existePais2 = false; 
        	while(buscarPais2->siguiente!=paises.primero){	 
        		if(buscarPais2->valor==codPais2){ 
        			existePais2 = true; 
        			break; 
				} 
				else{ 
					buscarPais2=buscarPais2->siguiente; 
				} 
			}if(buscarPais2->valor==codPais2){ 
				existePais2=true; 
			} 
			if(existePais2){ 
				//cout<<"Pase pais2"<<endl; 
				pnodoCiudad buscarCiudad = buscarPais->listaCiudades.primero;bool existeCiudad = false; 
				while(buscarCiudad->siguiente!=buscarPais->listaCiudades.primero){ 
					if(buscarCiudad->codCiudad==codCiudad){ 
						existeCiudad = true; 
						break; 
					} 
					else{ 
						buscarCiudad=buscarCiudad->siguiente; 
					} 
				}if(buscarCiudad->codCiudad==codCiudad){ 
					existeCiudad=true; 
				} 
				if(existeCiudad){ 
					//cout<<"Pase ciudad1"<<endl; 
					pnodoCiudad buscarCiudad2 = buscarPais2->listaCiudades.primero;bool existeCiudad2 = false; 
					while(buscarCiudad2->siguiente!=buscarPais2->listaCiudades.primero){ 
						if(buscarCiudad2->codCiudad==codCiudad2){ 
							existeCiudad2 = true; 
							break; 
						} 
						else{ 
							buscarCiudad2=buscarCiudad2->siguiente; 
						}	 
					}if(buscarCiudad2->codCiudad==codCiudad2){ 
						existeCiudad2=true; 
					} 
					bool existeCodTren = false;
					if(existeCiudad2){ 
						if(tipoTrenes.Verificar(codTipTren,codTren)){
							existeCodTren=true;
						}
						if(existeCodTren){ 
								//cout<<"Entre hasta el final"<<endl; 
								if(ListaVacia()){ 
									//cout<<"if"<<endl; 
									InsertarInicio(codTipTren, codTren, codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio); 
								}else{ 
									//cout<<"else"<<endl; 
									pnodoCir buscarRepetidos = primero; bool repetido= false; 
									while(buscarRepetidos->siguiente!=primero){ 
										if(buscarRepetidos->codRutas==codRuta){ 
											repetido=true; 
											break; 
										}else{ 
											buscarRepetidos=buscarRepetidos->siguiente; 
										} 
									}if(!repetido){ 
										InsertarFinal(codTipTren, codTren, codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio);	 
									}else{ 
										//cout<<"ESTOY repetido"<<endl; 
										// por si esta repetido 
									} 
								} 
							}  
						 
					} 
					else{ 
						cout<<"El codigo de ciudad destino no existe"<<endl; 
						// por si no existe la ciudad 2 
						
					}		 
				} 
				else{ 
					cout<<"El codigo de ciudad origen no existe"<<endl; 
					//por si no existe la ciudad 1 
					
				} 
			} 
			else{ 
				cout<<"El codigo de pais destino no existe"<<endl; 
				//por si no existe el pais2 
				 
			} 
		} 
		else{ 
			cout<<"El codigo de pais origen no existe"<<endl; 
			// por si no existe el pais 
			 
		}  
} 


void listaC::BorrarCiudades(listaDT& listaTrenes, listaDC& paises,listaDCUsuario& usuarios){
	int codPais;
	int codBorrar;
	cout<<"Ingrese el codigo del pais por borrar: ";cin>>codPais;cout<<endl;
	cout<<"Ingrese el codigo de la ciudad por borrar: ";cin>>codBorrar;cout<<endl;
	//ELIMINA LAS CONEXIONES QUE TIENEN EL CODCIUDAD
	pnodo recorrerPais = paises.primero;
	while(recorrerPais->siguiente!=paises.primero){
		pnodoCiudad recorrerCiudad = recorrerPais->listaCiudades.primero;
		while(recorrerCiudad->siguiente!=recorrerPais->listaCiudades.primero){
			pnodoDoble recorrerConexion = recorrerCiudad->listaConexiones.primero;
			int cont = 1;
			while(recorrerConexion!=NULL){
				if(recorrerConexion->codCiudad==codBorrar){
					recorrerCiudad->listaConexiones.BorrarPosicion(cont);
					recorrerConexion = recorrerConexion->siguiente;
				}
				else{
					recorrerConexion = recorrerConexion->siguiente;
					cont++;
				}
			}
			recorrerCiudad = recorrerCiudad->siguiente;
		}
		recorrerPais = recorrerPais->siguiente; 
	}
	//ELIMINA LAS CONEXIONES DE LA CIUDAD
	pnodo auxPais = paises.primero;bool existePais = false;
	while(auxPais->siguiente!=paises.primero){
		if(auxPais->valor==codPais){
			existePais=true;
			break;
		}
		else{
			auxPais = auxPais->siguiente;
		}
	}
	if(auxPais->valor==codPais){
		existePais = true;
	}
	if(existePais){
		pnodoCiudad auxCiudad = auxPais->listaCiudades.primero;
		while(auxCiudad->siguiente!=auxPais->listaCiudades.primero){
			if(auxCiudad->codCiudad==codBorrar){
				auxCiudad->listaConexiones.~listaD();
				break;
			}
			else{
				auxCiudad = auxCiudad->siguiente;
			}
		}
	}
	//ELIMINA LOS USUARIOS
	pnodoUsuario auxUsuario = usuarios.primero;
	int contador = 1;
	while(auxUsuario->siguiente!=usuarios.primero){
		if(auxUsuario->codCiudad==codBorrar){
			usuarios.BorrarPosicion(contador);
			auxUsuario=auxUsuario->siguiente;
		}
		else{
			auxUsuario=auxUsuario->siguiente;
			contador++;
		}
	}if(auxUsuario->codCiudad==codBorrar){
		usuarios.BorrarFinal();
	}
	//ELIMINA LAS RUTAS
	pnodoCir auxRuta= primero; int contRuta = 1;
	while(auxRuta->siguiente != primero){
		if((auxRuta->codCiudad1==codBorrar)||(auxRuta->codCiudad2==codBorrar)){
			borrarPosicion(contRuta);
			auxRuta=auxRuta->siguiente;
		}
		else{
			auxRuta=auxRuta->siguiente;
			contRuta++;
		}
	}if((auxRuta->codCiudad1==codBorrar)||(auxRuta->codCiudad2==codBorrar)){
		BorrarFinal();
	}
	//ELIMINA LA CIUDAD
	pnodo recorrerPais2 = paises.primero; bool existePais2 = false;
	while(recorrerPais2->siguiente != paises.primero){
		if (recorrerPais2->valor== codPais){
			existePais2 = true;
			break;
		}else{
			recorrerPais2 = recorrerPais2->siguiente;
		}
	}if (recorrerPais2->valor== codPais){
		existePais2 = true;
		
	}if(existePais2){
		pnodoCiudad recorrerCiudad2 = recorrerPais2->listaCiudades.primero; int contCiudad = 1;
		while(recorrerCiudad2->siguiente!=recorrerPais2->listaCiudades.primero){
			if(recorrerCiudad2->codCiudad==codBorrar){
				recorrerPais2->listaCiudades.BorrarPosicion(contCiudad);
				cout<<"Ciudad borrada con exito"<<endl;
				break;
				
			}else{
				recorrerCiudad2 = recorrerCiudad2->siguiente;
				contCiudad++;
			}
		}if(recorrerCiudad2->codCiudad==codBorrar){
				recorrerPais2->listaCiudades.BorrarPosicion(contCiudad);
				cout<<"Ciudad borrada con exito"<<endl;
			}
	}
}

void listaC::BorrarRuta(int& ultimaRutaEliminada){
	int rutaBorrar;
	cout<<"Ingrese el codigo de ruta que desea borrar: ";cin>>rutaBorrar;cout<<endl;
	pnodoCir recorrerRutas = primero;bool flag = false;
	int cont = 1;
	while(recorrerRutas->siguiente!=primero){
		if(recorrerRutas->codRutas==rutaBorrar){
			flag = true;
			break;
		}
		else{
			recorrerRutas=recorrerRutas->siguiente;
			cont++;
		}
	}if(recorrerRutas->codRutas==rutaBorrar){
		flag = true;
	}
	if(flag){
		borrarPosicion(cont);
		ultimaRutaEliminada= rutaBorrar;
		cout<<"Ruta borrada con exito"<<endl;	
	}
	else{
		cout<<"Error, el codigo de ruta ingresado no existe"<<endl;
	}
}
void listaC::BorrarPais(listaDC& paises,listaDCUsuario& usuarios){
	int codPais;
	cout<<"Ingrese el codigo del pais por borrar: ";cin>>codPais;cout<<endl;
	//ELIMINA LAS CONEXIONES QUE TIENEN EL CODCIUDAD
	pnodo recorrerPais1=paises.primero; bool banderaP= false;
	while(recorrerPais1->siguiente != paises.primero){
		if(recorrerPais1->valor==codPais){
			banderaP=true;
			break;
		}else{
			recorrerPais1=recorrerPais1->siguiente;
		}
	}if(recorrerPais1->valor==codPais){
		banderaP=true;
	}
	if(banderaP){
		pnodo recorrerPais = paises.primero;
		while(recorrerPais->siguiente!=paises.primero){
			pnodoCiudad recorrerCiudad = recorrerPais->listaCiudades.primero;
			while(recorrerCiudad->siguiente!=recorrerPais->listaCiudades.primero){
				pnodoDoble recorrerConexion = recorrerCiudad->listaConexiones.primero;
				int cont = 1;
				while(recorrerConexion!=NULL){
					if(recorrerConexion->codPais==codPais){
						recorrerCiudad->listaConexiones.BorrarPosicion(cont);
						recorrerConexion = recorrerConexion->siguiente;
					}
					else{
						recorrerConexion = recorrerConexion->siguiente;
						cont++;
					}
				}
				recorrerCiudad = recorrerCiudad->siguiente;
			}
			recorrerPais = recorrerPais->siguiente; 
		}
		//Borra conexiones de las conexiones de esa ciudad.
		pnodo auxPais = paises.primero;bool existePais = false;
		while(auxPais->siguiente!=paises.primero){
			if(auxPais->valor==codPais){
				existePais=true;
				break;
			}
			else{
				auxPais = auxPais->siguiente;
			}
		}
		if(auxPais->valor==codPais){
			existePais = true;
		}
		if(existePais){
			pnodoCiudad auxCiudad = auxPais->listaCiudades.primero;
			while(auxCiudad->siguiente!=auxPais->listaCiudades.primero){
				auxCiudad->listaConexiones.~listaD();
				auxCiudad=auxCiudad->siguiente;
			}
			auxCiudad->listaConexiones.~listaD();
			auxPais->listaCiudades.~listaDCCiudad();
			auxPais->listaCiudades.BorrarFinal();
		}
		pnodoUsuario auxUsuario = usuarios.primero;
		int contador = 1;
		while(auxUsuario->siguiente!=usuarios.primero){
			if(auxUsuario->codPais==codPais){
				usuarios.BorrarPosicion(contador);
				auxUsuario=auxUsuario->siguiente;
			}
			else{
				auxUsuario=auxUsuario->siguiente;
				contador++;
			}
		}if(auxUsuario->codPais==codPais){
			usuarios.BorrarFinal();
		}
		pnodoCir auxRuta= primero; int contRuta = 1;
		while(auxRuta->siguiente != primero){
			if((auxRuta->codPais1==codPais)||(auxRuta->codPais2==codPais)){
				borrarPosicion(contRuta);
				auxRuta=auxRuta->siguiente;
			}
			else{
				auxRuta=auxRuta->siguiente;
				contRuta++;
			}
		}if((auxRuta->codPais1==codPais)||(auxRuta->codPais2==codPais)){
			BorrarFinal();
		}
		pnodo finalBorrar = paises.primero; int cantidad = 1; bool banderaS= false;
		while(finalBorrar->siguiente!=paises.primero){
			if(finalBorrar->valor==codPais){
				paises.BorrarPosicion(cantidad);
				cout<<"Pais eliminado con exito"<<endl;
				banderaS=true;
				break;
			}
			else{
				finalBorrar=finalBorrar->siguiente;
				cantidad++;
			}
		}if(!banderaS){
			if(finalBorrar->valor = codPais){
				paises.BorrarFinal();
				cout<<"Pais eliminado con exito"<<endl;
			}
		}
	}else{
		cout<<"El codigo de pais no existe"<<endl;
	}	
}


void listaC::EliminarTren(string& ultimoTrenEliminado , listaDT& tipoTren){
	int codTipTren;
	int codTren;
	cout<<"Ingrese el codigo del tipo de tren que desea eliminar: ";cin>>codTipTren;cout<<endl;
	cout<<"Ingrese el codigo del tren que desea eliminar: ";cin>>codTren;cout<<endl;
	pnodoDobleT buscarTipTren = tipoTren.primero; bool existeTipTren = false;
	while(buscarTipTren!=NULL){
		if(buscarTipTren->codTren==codTipTren){
			existeTipTren = true;
			break;
		}
		else{
			buscarTipTren=buscarTipTren->siguiente;
		}
	}
	if(existeTipTren){
		pnodoSimpTrenes buscarTren = buscarTipTren->listaDeTrenes.primero;bool borrado = false;
		int cont = 1;
		while(buscarTren!=NULL){
			if(buscarTren->codTren==codTren){
				ultimoTrenEliminado = ("Ultimo tren eliminado: " + (buscarTren->nombre) + "\n");
				buscarTipTren->listaDeTrenes.borrarPosicion(cont);
				buscarTren->listaDeCodRutas.~lista();
				borrado = true;
				break;
			}
			else{
				buscarTren = buscarTren->siguiente;
				cont++;
			}
		}
		if(borrado){
			cout<<"Tren borrado con exito."<<endl;
			pnodoCir recorrerRutas = primero;bool flag = false;
			int cont = 1;
			while(recorrerRutas->siguiente!=primero){
				if(recorrerRutas->codTren==codTren){
					flag = true;
					borrarPosicion(cont);
					recorrerRutas=recorrerRutas->siguiente;
				}
				else{
					recorrerRutas=recorrerRutas->siguiente;
					cont++;
				}
			}if(recorrerRutas->codTren==codTren){
				flag = true;
			}
			if(flag){
				borrarPosicion(cont);	
			}		
		}
		else{
			cout<<"Error, el codigo del tren es invalido."<<endl;
		}
	}
	else{
		cout<<"Error, el codigo del tipo de tren es invalido."<<endl;
	}
}






