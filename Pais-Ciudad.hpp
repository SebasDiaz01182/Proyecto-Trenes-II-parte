#include<fstream>
#include <iostream>
#include <stdlib.h>
#include<string>
#include<sstream>
#include "Conexiones.hpp"
#include "Tipo-Tren.hpp"
#include "Ciudad.hpp"
#pragma once
using namespace std;

class nodo {
public:
    nodo(int v, string cpais)
    {
        valor = v;
        pais = cpais;
        siguiente = NULL;
        anterior = NULL;
        ciudad = NULL;
        listaCiudades= listaDCCiudad();
        listaConexiones = listaD();
        primeraConexion = listaConexiones.primero;
    }

    nodo(int v, string cpais, nodo* signodo, nodo* sigCiudad)
    {
        valor = v;
        pais = cpais;
        siguiente = signodo;
        ciudad = sigCiudad;
    }

public:
    int valor;
    string pais;
    nodo* ciudad;
    nodo* siguiente;
    nodo* anterior;
    listaD listaConexiones;
    listaDCCiudad listaCiudades;
    nodoDoble *primeraConexion;
    
    friend class listaDC;
    friend class nodoDoble;
    friend class listaD;
    friend class nodoCiudad;
    friend class listaDCCiudad;
};
typedef nodo* pnodo;

class listaDC {
public:
    listaDC() { primero = NULL; }

    void InsertarInicio(int v, string pais);
    void InsertarFinal(int v, string pais);
    void InsertarPos(int v, string pais, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    void llenarListaPais();
    void llenarListaCiudad();
    void llenarListaConexiones();
    void ConsultarPaises();
    void ConsultarCiudades();
    void ConsultarConexiones();
    void InsertarPais(string& ultimoPais);
    void InsertarCiudades (string& ultimaCiudad);
    void InsertarConexion(int& ultimaConexion);
    void EliminarPais();
    void EliminarCiudad();
    void ModificarTiempo();
    void RegistroActividad();
    void MostrarActP();
    void MostrarActC();
    void BorrarConexion();
    bool VerificarCodPais(int codAux,int codCiudadAux);
    
public:
    pnodo primero;

};

pnodo UltimoPais(listaDC paises){   
	pnodo aux = paises.primero;
	while(aux->siguiente!=paises.primero){
		aux=aux->siguiente;
	}
	return aux;
}


int listaDC::largoLista()
{
    int cont = 0;

    pnodo aux = primero;
    if (ListaVacia())
    {
        return cont;
    }
    else
    {
        while (aux->siguiente!= primero)
        {
            aux = aux->siguiente;
            cont++;
        }
        return cont;
    }

}

void listaDC::InsertarInicio(int v, string pais)
{

    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodo nuevo = new nodo(v, pais);
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        nuevo->siguiente->anterior = nuevo;
        primero = nuevo;
    }
}

void listaDC::InsertarFinal(int v, string pais)
{
    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodo nuevo = new nodo(v, pais);
        nuevo->anterior = primero->anterior;
        nuevo->siguiente = primero->anterior->siguiente;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo;
    }
}


void listaDC::InsertarPos(int v, string pais, int pos)
{
    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        if (pos <= 1)
            InsertarInicio(v, pais);
        else
        {
            if (pos == largoLista())
                InsertarFinal(v, pais);
            else
            {
                pnodo aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != primero))
                {
                    i++;
                    aux = aux->siguiente;
                }
                pnodo nuevo = new nodo(v, pais);
                nuevo->siguiente = aux->siguiente;
                aux->siguiente = nuevo;
                aux->siguiente->anterior = aux;
                nuevo->siguiente->anterior = nuevo;
            }
        }
    }
}

void listaDC::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodo temp = aux->siguiente;
            aux->siguiente = primero;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDC::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero->anterior;
            pnodo temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDC::BorrarPosicion(int pos)
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
                pnodo aux = primero;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }
                pnodo temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void listaDC::Mostrar()
{
    pnodo aux = primero;
    while (aux->siguiente != primero)
    {

        cout << aux->valor << "-" << aux->pais << "->";
        aux = aux->siguiente;
    }
    cout << aux->valor << "-" << aux->pais << "->";
    cout << endl;
}

void listaDC::MostrarActP()
{
    pnodo aux = primero;
    cout<<"Ultimo pais insertado: "<<endl;
    if(ListaVacia()){
    	cout<<"No se han insertado paises"<<endl;
	}else{
		while (aux->siguiente != primero){
        	
        	aux = aux->siguiente;
		}
    	cout <<"Se ingreso el pais " << aux->pais << " de codigo "<< aux->valor;;
    	cout << endl;
	}
}

void listaDC::llenarListaPais() {
    ifstream archivo;
    string texto;
    archivo.open("Paises.txt", ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo,texto);
        int posPC = texto.find(";");
        int codPais = atoi(texto.substr(0, posPC).c_str());
        string nomPais = texto.substr(posPC + 1, texto.length());
        if (ListaVacia()) {
            InsertarFinal(codPais, nomPais);
        }
        else {
            pnodo puntero = primero; bool flag = true;
            while (puntero->siguiente != primero) {
                if (puntero->valor == codPais) {
                    flag = false;
                    break;
                }
                else {
                    puntero = puntero->siguiente;
                }
            }
            if (flag) {
                InsertarFinal(codPais, nomPais);
            }
            else{
            	continue;
			}
            
        }
        
    }
    archivo.close();
}

void listaDC::llenarListaCiudad() {
    ifstream archivo;
    string texto;
    archivo.open("Ciudades.txt", ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, texto);
        int posPC = texto.find(";");
        int codPais = atoi(texto.substr(0, posPC).c_str());
        pnodo puntero = primero; bool flag = false;
        while (puntero->siguiente!= primero) {
            if (puntero->valor == codPais) {
                flag = true;
                break;
            }
            else {
                puntero = puntero->siguiente;
            }
        }
        if(puntero->valor==codPais){
        	flag=true;
		}
        if (flag) {
            string CiudadTotal = texto.substr(posPC + 1, texto.length());
            int auxPC = CiudadTotal.find(";");
            int codCiudad = atoi(CiudadTotal.substr(0, auxPC).c_str());
            string nomCiudad = CiudadTotal.substr(auxPC+1, CiudadTotal.length());
            pnodo auxiliar = primero;
            while (auxiliar->siguiente != primero) {
                if (auxiliar->valor == codPais) {
                    break;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
            if ((auxiliar->listaCiudades.ListaVacia())) {
            	auxiliar->listaCiudades.InsertarFinal(codCiudad, nomCiudad);
            }
            else {
            	bool bandera= false;
            	pnodoCiudad recorrer = auxiliar->listaCiudades.primero;
            	while(recorrer->siguiente!=auxiliar->listaCiudades.primero){
            		if(recorrer->codCiudad==codCiudad){
            			bandera=true;
            			break;
					}else{
						recorrer=recorrer->siguiente;
					}
				}if(recorrer->codCiudad==codCiudad){
            		bandera=true;
            	}
				if(!bandera){
					auxiliar->listaCiudades.InsertarFinal(codCiudad, nomCiudad);
				}
			}
        }else{
		}	
    }
}

void listaDC::llenarListaConexiones() {
    ifstream archivo;
    string texto;
    archivo.open("Conexiones.txt", ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, texto);
        int posPC = texto.find(";");
        int codPais = atoi(texto.substr(0, posPC).c_str());
        pnodo puntero = primero; bool flag = false;
        while (puntero->siguiente!= primero) {
            if (puntero->valor == codPais) {
                flag = true;
                break;
            }
            else {
                puntero = puntero->siguiente;
            }
        }if(puntero->valor==codPais){
        			flag=true;
        	        if (flag) {
			            //cout << "Estoy entrando al pais: "<<puntero->pais << endl;
			
			            string ConexionTotal = texto.substr(posPC + 1, texto.length());
			            int posPC2 = ConexionTotal.find(";");
			            int codCiudad = atoi((ConexionTotal.substr(0, posPC2).c_str()));
			
			            pnodoCiudad ciudades = puntero->listaCiudades.primero; bool flag2=false; 
			            while (ciudades->siguiente!= puntero->listaCiudades.primero) {
			                if (ciudades->codCiudad == codCiudad) {
			                    flag2 = true;
			                    break;
			                }
			                else {
			                    ciudades = ciudades->siguiente;
			                }
			            }if(ciudades->codCiudad==codCiudad){
			            	flag2=true;
			            	if (flag2) {
				                string Conexion = ConexionTotal.substr(posPC2 + 1, ConexionTotal.length());
				                int posPC3 = Conexion.find(";");
				                int codConexionAux = atoi((Conexion.substr(0, posPC3).c_str()));
				
				                string ConexionPais = Conexion.substr(posPC3 + 1, Conexion.length());
				                int posPC4 = ConexionPais.find(";");
				                int codPais = atoi((ConexionPais.substr(0, posPC4).c_str()));
				
				                string ConexionCiudad = ConexionPais.substr(posPC4 + 1, ConexionPais.length());
				                int posPC5 = ConexionCiudad.find(";");
				                int codCiudad = atoi((ConexionCiudad.substr(0, posPC5).c_str()));
				
				                string Tiempo = ConexionCiudad.substr(posPC5 + 1, ConexionCiudad.length());
				                int posPC6 = Tiempo.find(";");
				                int codTiempo = atoi((Tiempo.substr(0, posPC6).c_str()));
				                /*
				                cout << "Codigo conexion: "<<codConexionAux << endl;
				                cout << "Codigo de Pais: "<<codPais << endl;
				                cout << "Codigo Ciudad: "<<codCiudad << endl;
				                cout << "Tiempo: "<<codTiempo << endl;
				                */
				                //Vamos a verificar de que exista el pais
				                pnodo buscarPais = primero->siguiente;bool existePais = false;
				                while(buscarPais!=primero){
				                	if(buscarPais->valor==codPais){
				                		existePais=true;
				                		break;
									}
									else{
										buscarPais=buscarPais->siguiente;
									}
								}if(buscarPais->valor==codPais){
									existePais=true;
									if(existePais){
										pnodoCiudad buscarCiudad = buscarPais->listaCiudades.primero; bool existeCiudad = false;
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
											if(existeCiudad){
												//Ahora vamos a ver que no se repita la conexionS
												bool conexionRepetida = false;
												pnodo paisesG = primero->siguiente;
												while(paisesG!=primero){
													pnodoCiudad ciudadesG = paisesG->listaCiudades.primero;
													while(ciudadesG->siguiente!=paisesG->listaCiudades.primero){
														pnodoDoble conexionG = ciudadesG->listaConexiones.primero;
														while(conexionG!=NULL){
															if(conexionG->codConexion==codConexionAux){
																conexionRepetida = true;
																break;
															}
															else{
																conexionG = conexionG->siguiente;
															}
														}
														ciudadesG = ciudadesG->siguiente;
													}
													paisesG=paisesG->siguiente;
												}
												if(!conexionRepetida){
													cout<<"Entre"<<endl;
													ciudades->listaConexiones.InsertarFinalD(codConexionAux,codPais,codCiudad,codTiempo);
													continue;
												}
												else{
													// por si la conexion estaba repetida
													continue;
												}
											}else{
												//Else existe ciudad
											}
										}else{
											//este else buscar todo
											continue;
										}	
									}else{
										//Si no exite el pais
										continue;
									}
								}else{
									//Verificar el ultimo
									continue;
								}
				//No tocar estas llaves
				        	}else{
				        		//paso Ciudad
							}
						}else{
							//Verificartodo
						}
			            
			    	}else{
			    		//cout<<"Paso el pais"
					}
		}else{
			//Verificar ultimo
		}
	}
}
void listaDC::ConsultarPaises() {
    pnodo aux = primero;
    cout << "Paises: " << endl;
    while (aux->siguiente != primero)
    {
        cout << aux->pais << "  Codigo: " << aux->valor << endl;
        aux = aux->siguiente;
    }
    cout << aux->pais << "  Codigo: " << aux->valor << endl;
    cout << endl;
}


void listaDC::ConsultarCiudades() {
    int codPais;
    cout << "Ingrese el codigo del pais: ";
    cin >> codPais;
    cout<<endl;
    pnodo puntero = primero->siguiente; bool flag = false;
    while (puntero!= primero) {
        if (puntero->valor == codPais) {
            flag = true;
            break;
        }
        else {
            puntero = puntero->siguiente;
        }
    }
    if(puntero->valor==codPais){
    	//cout<<"Prueba: "<<puntero->ciudad->pais<<endl;
    	flag=true;
	}
    //cout <<"Pais: "<<puntero->pais<< endl;
    if (flag) {
        pnodoCiudad ciudades = puntero->listaCiudades.primero; bool flag2 = false;
        if(puntero->listaCiudades.ListaVacia()){
        	cout<<"El pais no posee ciudades."<<endl;
		}
		else{
			while (ciudades->siguiente != puntero->listaCiudades.primero) {
            cout << ciudades->ciudad << "  Codigo: " << ciudades->codCiudad << endl;
            ciudades = ciudades->siguiente;
        	}
        	cout << ciudades->ciudad << "  Codigo: " << ciudades->codCiudad << endl;
        	cout << endl;
		}
        
    }
    else {
        cout << "El codigo ingresado no existe" << endl;
    }
}

void listaDC::ConsultarConexiones(){
	int codPais;
	int codCiudad;
    cout << "Ingrese el codigo del pais: ";
    cin >> codPais;
    cout<<endl;
    cout << "Ingrese el codigo de la ciudad: ";
    cin >> codCiudad;
    cout<<endl;
    pnodo puntero = primero; bool flag = false;
    while (puntero->siguiente!= primero) {
        if (puntero->valor == codPais) {
            flag = true;
            break;
        }
        else {
            puntero = puntero->siguiente;
        }
    }
    if(puntero->valor==codPais){
    	flag=true;
    }
    	if (flag) {
	        pnodoCiudad ciudades = puntero->listaCiudades.primero; bool flag2 = false;
	        while (ciudades->siguiente != puntero->listaCiudades.primero) {
	        	if(ciudades->codCiudad ==codCiudad){
	        		flag2=true;
	        		break;
				}else{
					ciudades = ciudades->siguiente;
				}   
	        }if(ciudades->codCiudad==codCiudad){
	        	flag2=true;
	        }
	        	if(flag2){
	        		pnodoDoble conexionG = ciudades->listaConexiones.primero;
	        		if(ciudades->listaConexiones.ListaVacia()){
	        			cout<<"La ciudad no tiene conexiones."<<endl;
					}
					else{
						while(conexionG!=NULL){
							cout<<"Codigo de conexion: "<<conexionG->codConexion <<" Codigo del pais: "<<conexionG->codPais <<" Codigo de la ciudad: "<<conexionG->codCiudad<<" Duracion: "<<conexionG->tiempo<<" horas"<<endl;
							conexionG=conexionG->siguiente;
						}
					}
				}else {
				cout<<"El codigo de ciudad no existe"<<endl;
				}
	    }
	    else {
	        cout << "El codigo del pais no existe" << endl;
	    }
}
	
void listaDC::InsertarPais(string& ultimoPais){
	int codPais;
	string nomPais;
	cout<<"Digite el codigo del pais a ingresar: "; cin>> codPais;cout<<endl;
	cout<<"Digite el nombre del pais a ingresar: "; cin>> nomPais;cout<<endl;
	if (ListaVacia()) {
	            InsertarFinal(codPais, nomPais);
	            stringstream ss;
	            ss<<codPais;
	            string codPaisS = ss.str();
	            ultimoPais = ("Ultimo pais insertado: " + nomPais + "\n" + "Codigo: " + codPaisS);
	            cout<<"Pais ingresado con exito"<<endl;
	        }
	        else {
	            pnodo puntero = primero; bool flag = true;
	            while (puntero->siguiente != primero) {
	                if (puntero->valor == codPais) {
	                    flag = false;
	                    break;
	                }
	                else {
	                    puntero = puntero->siguiente;
	                }
	            }if (puntero->valor == codPais) {
	            	flag=false;
	            }
	            if (flag) {
	                InsertarFinal(codPais, nomPais);
	                stringstream ss;
	            	ss<<codPais;
	            	string codPaisS = ss.str();
	            	ultimoPais = ("Ultimo pais insertado: " + nomPais + "\n" + "Codigo: " + codPaisS);
	                
	               	cout<<"Pais ingresado con exito"<<endl;
	           	}else{
	           		cout<<"El codigo del pais ya existe"<<endl;
				}
			}
		}
		    
void listaDC::InsertarCiudades(string& ultimaCiudad){
	int codPais;
	int codCiudad;
	string nomCiudad;
	cout<<"Digite el codigo de pais : "; cin>> codPais;cout<<endl;
	cout<<"Digite el codigo de la ciudad a ingresar: "; cin>> codCiudad;cout<<endl;
	cout<<"Digite el nombre de la ciudad a ingresar: "; cin>> nomCiudad;cout<<endl;
	pnodo puntero = primero; bool flag = false;
        while (puntero->siguiente!= primero) {
            if (puntero->valor == codPais) {
                flag = true;
                break;
            }
            else {
                puntero = puntero->siguiente;
            }
        }
        if(puntero->valor==codPais){
        	flag=true;
		}
        if (flag) {
            
            pnodo auxiliar = primero;
            while (auxiliar->siguiente != primero) {
                if (auxiliar->valor == codPais) {
                    break;
                }
                else {
                    auxiliar = auxiliar->siguiente;
                }
            }
            if ((auxiliar->listaCiudades.primero==NULL)) {
            	auxiliar->listaCiudades.InsertarFinal(codCiudad,nomCiudad);
                cout<<"Ciudad ingresada con exito"<<endl;
                stringstream ss;
	            ss<<codCiudad;
	            string codCiudadS = ss.str();
                ultimaCiudad = ("Ultimo ciudad insertada: " + nomCiudad + "\n" + "Codigo: " + codCiudadS);
            }
            else {
            	bool bandera= false;
            	pnodoCiudad recorrer = auxiliar->listaCiudades.primero;
            	while(recorrer->siguiente!=auxiliar->listaCiudades.primero){
            		if(recorrer->codCiudad==codCiudad){
            			bandera=true;
            			break;
					}else{
						recorrer=recorrer->siguiente;
					}
				}if(recorrer->codCiudad==codCiudad){
            			bandera=true;
            		}
				if(!bandera){
					auxiliar->listaCiudades.InsertarFinal(codCiudad,nomCiudad);
					cout<<"Ciudad ingresada con exito"<<endl;
					stringstream ss;
		            ss<<codCiudad;
		            string codCiudadS = ss.str();
	                ultimaCiudad = ("Ultimo ciudad insertada: " + nomCiudad + "\n" + "Codigo: " + codCiudadS);
				}else{
					cout<<"El codigo de la ciudad ya existe"<<endl;
				}
			}
    }else{
    	cout<<"El codigo del pais no existe"<<endl;
	}
}

void listaDC::InsertarConexion(int& ultimaConexion){
			int codPais;
			int codCiudad;
			int codConexion;
			int codPais2; 
			int codCiudad2;
			int codTiempo;
			cout<<"Digite el codigo de pais de la conexion: "; cin>> codPais;cout<<endl;
			cout<<"Digite el codigo de la ciudad de la conexion: "; cin>> codCiudad;cout<<endl;
			cout<<"Digite el codigo de la conexion: "; cin>> codConexion;cout<<endl;
			cout<<"Digite el codigo del pais destino: "; cin>> codPais2;cout<<endl;
			cout<<"Digite el codigo de la ciudad destino: "; cin>> codCiudad2;cout<<endl;
			cout<<"Digite el tiempo de la conexion: "; cin>> codTiempo;cout<<endl;
				pnodo buscarPais = primero;bool existePais = false;
                while(buscarPais->siguiente!=primero){
                	if(buscarPais->valor==codPais){
                		existePais=true;
                		break;
					}
					else{
						buscarPais=buscarPais->siguiente;
					}
					
					}if(buscarPais->valor==codPais){
						existePais=true;
					}
						if(existePais){
							pnodo buscarPais2 = primero;bool existePais2 = false;
			                while(buscarPais2->siguiente!=primero){
			                	if(buscarPais2->valor==codPais2){
			                		existePais2=true;
			                		break;
								}
								else{
									buscarPais2=buscarPais2->siguiente;
								}
							}if(buscarPais2->valor==codPais2){
								existePais2=true;
							}
								if(existePais2){
									pnodoCiudad buscarCiudad = buscarPais->listaCiudades.primero; bool existeCiudad = false;
									while(buscarCiudad->siguiente!=buscarPais->listaCiudades.primero){
										if(buscarCiudad->codCiudad==codCiudad){
											existeCiudad = true;
											break;
										}
										else{
											buscarCiudad=buscarCiudad->siguiente;
										}
									}if(buscarCiudad->codCiudad==codCiudad){
										existeCiudad== true;
									}
										if(existeCiudad){
											pnodoCiudad buscarCiudad2 = buscarPais2->listaCiudades.primero; bool existeCiudad2 = false;
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
												if(existeCiudad2){
													//Ahora vamos a ver que no se repita la conexionS
													bool conexionRepetida = false;
													pnodo paisesG = primero->siguiente;
													while(paisesG!=primero){
														pnodoCiudad ciudadesG = paisesG->listaCiudades.primero;
														while(ciudadesG->siguiente!=paisesG->listaCiudades.primero){
															pnodoDoble conexionG = ciudadesG->listaConexiones.primero;
															while(conexionG!=NULL){
																if(conexionG->codConexion==codConexion){
																	conexionRepetida = true;
																	break;
																}
																else{
																	conexionG = conexionG->siguiente;
																}
															}
															ciudadesG = ciudadesG->siguiente;
														}
														paisesG=paisesG->siguiente;
													}
													if(!conexionRepetida){
														buscarCiudad->listaConexiones.InsertarFinalD(codConexion,codPais2,codCiudad2,codTiempo);
														ultimaConexion = (codConexion);
														cout<<"Conexion insertada con exito."<<endl;
														//return true;
													}
													else{
														// por si la conexion estaba repetida
														cout<<"El codigo de la conexion ya existe."<<endl;
														//return false;
													}
												}else{
												cout<<"El codigo de la ciudad destino no existe "<<endl;
												}
										}else{	
											cout<<"El codigo de ciudad no existe "<<endl;
										}
								}else{
									cout<<"El codigo del pais destino no existe "<<endl;
								}
							}else{
							cout<<"El codigo de pais no existe "<<endl;
							}
}
void listaDC::ModificarTiempo(){
	int codPais;
	int codCiudad;
	int codConexion;
	int codTiempo;
    cout << "Ingrese el codigo del pais: ";
    cin >> codPais;
    cout<<endl;
    cout << "Ingrese el codigo de la ciudad: ";
    cin >> codCiudad;
    cout<<endl;
    cout << "Ingrese el codigo de conexion: ";
    cin >> codConexion;
    cout<<endl;
    cout << "Ingrese la nueva duracion del viaje: ";
    cin >> codTiempo;
    cout<<endl;
    pnodo puntero = primero->siguiente; bool flag = false;
    while (puntero!= primero) {
        if (puntero->valor == codPais) {
            flag = true;
            break;
        }
        else {
            puntero = puntero->siguiente;
        }
    }
    if(puntero->valor==codPais){
    	flag=true;
	}
    	if (flag) {
	        pnodoCiudad ciudades = puntero->listaCiudades.primero; bool flag2 = false;
	        while (ciudades->siguiente != puntero->listaCiudades.primero) {
	        	if(ciudades->codCiudad==codCiudad){
	        		flag2=true;
	        		break;
				}else{
					ciudades = ciudades->siguiente;
				}   
	        }if(ciudades->codCiudad==codCiudad){
	        	flag2=true;
	        }
	        	if(flag2){
	        		pnodoDoble conexionG = ciudades->listaConexiones.primero; bool flag=false;
					while(conexionG!=NULL){
						if(conexionG->codConexion==codConexion){
							cout<<"El nuevo tiempo estimado del viaje es de "<<(conexionG->tiempo=codTiempo)<< " horas"<<endl;
							flag=true;
							break;
						}else{
							conexionG=conexionG->siguiente;
						}	
					}if(!flag){
						cout<<"El codigo de conexion es incorrecto"<<endl;
					}
				}else {
				cout<<"El codigo de ciudad no existe"<<endl;
				}
	    }
	    else {
	        cout << "El codigo del pais no existe" << endl;
	    }	
}
void listaDC::BorrarConexion(){
	int codPais;
	int codCiudad;
	int codConexion;
    cout << "Ingrese el codigo del pais: ";
    cin >> codPais;
    cout<<endl;
    cout << "Ingrese el codigo de la ciudad: ";
    cin >> codCiudad;
    cout<<endl;
    cout << "Ingrese el codigo de conexion: ";
    cin >> codConexion;
    cout<<endl;
    pnodo puntero = primero->siguiente; bool flag = false;
    while (puntero!= primero) {
        if (puntero->valor == codPais) {
            flag = true;
            break;
        }
        else {
            puntero = puntero->siguiente;
        }
    }
    if(puntero->valor==codPais){
    	flag=true;
	}
    	if (flag) {
	        pnodoCiudad ciudades = puntero->listaCiudades.primero; bool flag2 = false;
	        while (ciudades->siguiente != puntero->listaCiudades.primero) {
	        	if(ciudades->codCiudad==codCiudad){
	        		flag2=true;
	        		break;
				}else{
					ciudades = ciudades->siguiente;
				}   
	        }if(ciudades->codCiudad==codCiudad){
	        	flag2=true;
	        }
	        	if(flag2){
	        		pnodoDoble conexionG = ciudades->listaConexiones.primero; bool flag=false;
	        		int cont = 1;
					while(conexionG!=NULL){
						if(conexionG->codConexion==codConexion){
							flag=true;
							break;
						}else{
							cont++;
							conexionG=conexionG->siguiente;
						}	
					}if(!flag){
						cout<<"El codigo de conexion es incorrecto"<<endl;
					}
					else{
						ciudades->listaConexiones.BorrarPosicion(cont);
						cout<<"La conexion se elimino con exito"<<endl;
						
					}
				}else {
				cout<<"El codigo de ciudad no existe"<<endl;
				}
	    }
	    else {
	        cout << "El codigo del pais no existe" << endl;
	    }
}
bool listaDC::VerificarCodPais(int codAux,int codCiudad){
	pnodo buscar = primero;bool flag = false;
	while(buscar->siguiente!=primero){
		if(buscar->valor==codAux){
			flag =  true;	
		}
		else{
			buscar=buscar->siguiente;
		}
	}
	if(buscar->valor==codAux){
		flag = true;
	}
	if(flag){
		pnodoCiudad ciudades = buscar->listaCiudades.primero; bool flag2 = false;
	        while (ciudades->siguiente != buscar->listaCiudades.primero) {
	        	if(ciudades->codCiudad==codCiudad){
	        		flag2=true;
	        		break;
				}else{
					ciudades = ciudades->siguiente;
				}   
	        }if(ciudades->codCiudad==codCiudad){
	        	flag2=true;
	        }
	        if(flag2){
			return true;
			}
			else{
				return false;
			}
	}
	else{
		return false;
	}
	
}


