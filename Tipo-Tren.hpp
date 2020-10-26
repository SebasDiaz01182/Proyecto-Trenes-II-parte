#include<sstream>
#include <iostream> 
#include "Trenes.hpp"
#pragma once 
using namespace std;
class nodoDobleT { 
public: 
    nodoDobleT(int codigoc, string cnombre) 
    { 
    	codTren= codigoc; 
        nombre= cnombre; 
        siguiente = NULL; 
        anterior = NULL; 
        tren = NULL; 
        listaDeTrenes = listaTrenes(); 
        listaCodRutas = lista(); 
    } 
 
    nodoDobleT(int codigoc ,string cnombre, nodoDobleT* signodoDoble, nodoDobleT* sigantDoble) 
    { 
    	codTren= codigoc; 
        nombre= cnombre; 
        siguiente = signodoDoble; 
        anterior = sigantDoble; 
        listaDeTrenes = listaTrenes(); 
    } 
public: 
	int codTren; 
	string nombre; 
	lista listaCodRutas; 
    nodoDobleT* siguiente; 
    nodoDobleT* anterior; 
    nodoDobleT* tren; 
    listaTrenes listaDeTrenes; 
     
    friend class listaDT; 
    friend class listaTrenes; 
    friend class nodoSimpTrenes;
	friend class listaC; 
	friend class nodoCir;
}; 
 
typedef nodoDobleT* pnodoDobleT; 
 
class listaDT { 
public: 
    listaDT() { primero = NULL; } 
    ~listaDT(); 
 
    void InsertarInicioDT(int v, string nombre); 
    void InsertarFinalDT(int codTipo, string nombre); 
    bool ListaVaciaDT() { return primero == NULL; } 
    void Mostrar(); 
    int largoLista(); 
    void llenarListaTipotrenes(); 
    void llenarListaTrenes(); 
    void llenarListaCodRutas(); 
    void InsertarTipoTren(string& ultimoTren); 
    void MostrarUnTipoDeTren(); 
    void ConsultarAsientos(); 
    void ModificarNumAsientos(); 
    void RegistrarTren(); 
    void ModificarTren();  
    bool Verificar(int codTipTren, int codTren);
    void EliminarTren(string& ultimoTrenEliminado);
    void MostrarCodigos();
    pnodoDobleT primero; 
   
 
}; 
 
listaDT::~listaDT() 
{ 
    pnodoDobleT aux; 
 
    while (primero) { 
        aux = primero; 
        primero = primero->siguiente; 
        delete aux; 
    } 
 
} 
 
int listaDT::largoLista() { 
    int cont = 0; 
 
    pnodoDobleT aux; 
    aux = primero; 
    if (ListaVaciaDT()) { 
        return cont; 
    } 
    else { 
        while (aux != NULL) { 
            aux = aux->siguiente; 
            cont++; 
        } 
        return cont; 
    } 
 
} 
 
void listaDT::InsertarInicioDT(int v,string nombre) 
{ 
   if (ListaVaciaDT()) 
   { 
    
     primero = new nodoDobleT(v,nombre); 
     primero->anterior=NULL;      
   } 
   else 
   { 
     primero=new nodoDobleT (v,nombre); 
     primero->siguiente->anterior=primero; 
   } 
} 
  
 
void listaDT::InsertarFinalDT(int codTipo, string nombre) 
{ 
    if (ListaVaciaDT()) { 
        primero = new nodoDobleT( codTipo,  nombre); 
    } 
    else 
    { 
        pnodoDobleT aux = primero; 
        while (aux->siguiente != NULL) { 
            aux = aux->siguiente; 
        } 
        pnodoDobleT nuevo = new nodoDobleT( codTipo,  nombre); 
        aux->siguiente = nuevo; 
        nuevo->anterior = aux; 
 
    } 
} 
void listaDT::Mostrar() 
{ 
    nodoDobleT* aux; 
 
    aux = primero; 
    while (aux!=NULL) { 
    	cout<<"CodTipTren : "<<aux->codTren; 
    	cout<<"  Nombre de Tren : "<<aux->nombre<<endl; 
        aux = aux->siguiente; 
    } 
    cout << endl; 
} 
 
void listaDT::llenarListaTipotrenes(){ 
	ifstream archivoT; 
    string texto; 
    archivoT.open("TipoTren.txt", ios::in); 
    if (archivoT.fail()) { 
        cout << "No se pudo abrir el archivo"; 
        exit(1); 
    } 
    while (!archivoT.eof()) { 
        getline(archivoT, texto); 
         
        int posPC = texto.find(";"); 
        int codTipTren = atoi(texto.substr(0, posPC).c_str()); 
         
        string Todo = texto.substr(posPC + 1, texto.length()); 
        int posPC2 = Todo.find(";"); 
        string nombre = (Todo.substr(0, posPC2)); 
         
        if(ListaVaciaDT()){ 
        	//cout<<"Lista Vacia"<<endl; 
        	InsertarInicioDT(codTipTren,nombre); 
		} 
		else{ 
			pnodoDobleT trenAux = primero;bool existeTren = false; 
			while(trenAux!=NULL){ 
				if(trenAux->codTren==codTipTren){ 
					existeTren= true; 
					break; 
				}else{ 
					trenAux=trenAux->siguiente; 
				} 
			}if(!existeTren){ 
				InsertarFinalDT(codTipTren,nombre); 
			} 
		} 
	} 
	archivoT.close(); 
} 
void listaDT::llenarListaTrenes(){ 
	ifstream archivoT; 
    string texto; 
    archivoT.open("Trenes.txt", ios::in); 
    if (archivoT.fail()) { 
        cout << "No se pudo abrir el archivo"; 
        exit(1); 
    } 
    while (!archivoT.eof()) { 
        getline(archivoT, texto); 
         
        int posPC = texto.find(";"); 
        int codTipTren = atoi(texto.substr(0, posPC).c_str()); 
        cout << "Tipo Tren: " << codTipTren << endl; 
         
        string Todo = texto.substr(posPC + 1, texto.length()); 
        int posPC2 = Todo.find(";"); 
        int codTren = atoi(Todo.substr(0, posPC2).c_str()); 
        cout << "Codigo Tren: " << codTren << endl; 
 
        string Todo2 = Todo.substr(posPC2 + 1, Todo.length()); 
        int posPC3 = Todo2.find(";"); 
        string nomTren = (Todo2.substr(0, posPC3)); 
        cout << "Tren: " << nomTren << endl; 
         
        string Todo3 = Todo2.substr(posPC3 + 1, Todo2.length()); 
        int posPC4 = Todo3.find(";"); 
        int numAsientos = atoi((Todo3.substr(0, posPC4).c_str())); 
        cout << "Numero de asientos: " << numAsientos << endl; 
         
        string Todo4 = Todo3.substr(posPC4 + 1, Todo3.length()); 
        int posPC5 = Todo4.find(";"); 
        int ruta = atoi((Todo4.substr(0, posPC5).c_str())); 
        cout << "Rutas:  " << ruta << endl;       
        //Buscamos que el tipo de tren exista 
        pnodoDobleT tiposTrenes = primero;bool existeTipoTren = false; 
        while(tiposTrenes!=NULL){ 
        	if(tiposTrenes->codTren==codTipTren){ 
        		existeTipoTren = true; 
        		break; 
			} 
			else{ 
				tiposTrenes=tiposTrenes->siguiente; 
			} 
		} 
		if(existeTipoTren){ 
			if(tiposTrenes->listaDeTrenes.primero==NULL){ 
				tiposTrenes->listaDeTrenes.InsertarFinal(codTren,nomTren,numAsientos); 
				cout<<"Lista de Trenes1: "<<endl; 
				tiposTrenes->listaDeTrenes.Mostrar(); 
				cout<<endl; 
				cout<<endl; 
			} 
			else{ 
				pnodoSimpTrenes buscarCod = tiposTrenes->listaDeTrenes.primero;bool codRepetido = false; 
				while(buscarCod!=NULL){ 
					if(buscarCod->codTren==codTren){ 
						codRepetido = true; 
						break; 
					} 
					else{ 
						buscarCod=buscarCod->siguiente; 
					} 
				} 
				if(!codRepetido){ 
					tiposTrenes->listaDeTrenes.InsertarFinal(codTren,nomTren,numAsientos); 
					cout<<"Lista de Trenes2: "<<endl; 
					tiposTrenes->listaDeTrenes.Mostrar(); 
					cout<<endl; 
					cout<<endl; 
				} 
				else{ 
					// por si el codigo esta repetido 
					continue; 
				} 
			} 
		} 
		else{ 
			// por si no existe el tipo de tren 
			continue; 
		} 
         
	} 
	//llave del while del archivo 
	archivoT.close(); 
}  
void listaDT::InsertarTipoTren(string& ultimoTren){ 
	int codNuevo;string nombreNuevo; 
	cout<<"Ingrese el codigo del nuevo tipo de tren: "; 
	cin>>codNuevo; 
	cout<<endl;
	cout<<"Ingrese el nombre del nuevo tipo de tren: "; 
	cin>>nombreNuevo; 
	cout<<endl;
	pnodoDobleT verificar = primero;bool codRepetido = false; 
	while(verificar!=NULL){ 
		if(verificar->codTren==codNuevo){ 
			codRepetido = true; 
			break; 
		} 
		else{ 
			verificar=verificar->siguiente; 
		} 
	} 
	if(!codRepetido){ 
		InsertarFinalDT(codNuevo,nombreNuevo); 
		stringstream ss;
	    ss<<codNuevo;
	    string codNuevoS = ss.str();
        ultimoTren = ("Ultimo tipo de tren ingresado : " + nombreNuevo + "\n" + "Codigo: " + codNuevoS);
		cout<<"Nuevo tipo de tren agregado con exito."<<endl; 
	} 
	else{ 
		cout<<"No se pudo ingresar el nuevo tipo de tren."<<endl; 
		cout<<"Este mismo se encuentra repetido. Recuerde usar caracteres numericos solamente."<<endl; 
	} 
} 
void listaDT::MostrarUnTipoDeTren(){ 
	int codTipTren; 
	cout<<"Ingrese el codigo del tipo de tren para mostrar todos los trenes de ese tipo: "; 
	cin>>codTipTren;cout<<endl;
	pnodoDobleT mostrar = primero;bool existeTipTren = false; 
	while(mostrar!=NULL){ 
		if(mostrar->codTren==codTipTren){ 
			existeTipTren = true; 
			break; 
		} 
		else{ 
			mostrar=mostrar->siguiente; 
		} 
	} 
	if(existeTipTren){ 
		if(mostrar->listaDeTrenes.ListaVacia()){ 
			cout<<"No hay trenes registrados de ese tipo."<<endl; 
		} 
		else{ 
			mostrar->listaDeTrenes.Mostrar();
		} 
	} 
	else{ 
		cout<<"El codigo ingresado no corresponde a ningun tipo de tren."<<endl; 
	} 
} 
 
void listaDT::ConsultarAsientos(){ 
	int codTipTren; 
	int codTren; 
	cout<<"Ingrese el codigo del tipo de tren para mostrar los trenes de ese tipo: "; 
	cin>>codTipTren; cout<<endl; 
	cout<<"Ingrese el codigo del tren para mostrar los asientos disponibles: "; 
	cin>>codTren; cout<<endl; 
	pnodoDobleT mostrar = primero;bool existeTipTren = false; 
	while(mostrar!=NULL){ 
		if(mostrar->codTren==codTipTren){ 
			existeTipTren = true; 
			break; 
		} 
		else{ 
			mostrar=mostrar->siguiente; 
		} 
	} 
	if(existeTipTren){	 
	pnodoSimpTrenes buscarCod = mostrar->listaDeTrenes.primero;bool codRepetido = false; 
		while(buscarCod!=NULL){ 
			if(buscarCod->codTren==codTren){ 
				cout<<"Se dispone de "<<buscarCod->numAsientos<<" asientos disponibles."<<endl; 
				codRepetido=true; 
				break; 
			} 
			else{ 
				buscarCod=buscarCod->siguiente; 
			} 
		}if(!codRepetido){ 
			cout<<"El codigo de Tren digitado es incorrecto"<<endl; 
		} 
	}else{ 
		cout<<"El codigo del tipo de tren no existe"<<endl; 
	} 
} 
 
void listaDT::ModificarNumAsientos(){ 
		int codTipTren; 
		int codTren; 
		int numAsientos; 
		cout<<"Ingrese el codigo del tipo de tren: "; 
		cin>>codTipTren; cout<<endl;
		cout<<"Ingrese el codigo de tren: "; 
		cin>>codTren; cout<<endl;
		cout<<"Ingrese la nueva cantidad de asientos disponibles: "; 
		cin>>numAsientos; cout<<endl;
		pnodoDobleT mostrar = primero;bool existeTipTren = false; 
		while(mostrar!=NULL){ 
			if(mostrar->codTren==codTipTren){ 
				existeTipTren = true; 
				break; 
			} 
			else{ 
				mostrar=mostrar->siguiente; 
			} 
		} 
		if(existeTipTren){	 
		pnodoSimpTrenes buscarCod = mostrar->listaDeTrenes.primero;bool codRepetido = false; 
			while(buscarCod!=NULL){ 
				if(buscarCod->codTren==codTren){ 
					buscarCod->numAsientos=numAsientos; 
					cout<<"Se actualizaron la cantidad de asientos a "<<buscarCod->numAsientos<<" espacios disponibles."<<endl; 
					codRepetido=true; 
					break; 
				} 
				else{ 
					buscarCod=buscarCod->siguiente; 
				} 
			}if(!codRepetido){ 
				cout<<"El codigo de Tren digitado es incorrecto"<<endl; 
			} 
		}else{ 
			cout<<"El codigo del tipo de tren no existe"<<endl; 
		} 
} 
 
void listaDT::RegistrarTren(){ 
		int codTipTren; 
		int codTren; 
		string nomTren; 
		int numAsientos; 
		int ruta; 
		cout<<"Ingrese el codigo del tipo de tren ."<<endl; 
		cin>>codTipTren; 
		cout<<"Ingrese el codigo de tren."<<endl; 
		cin>>codTren; 
		cout<<"Ingrese el nombre del tren."<<endl; 
		cin>>nomTren; 
		cout<<"Ingrese la cantidad de asientos."<<endl; 
		cin>>numAsientos; 
		cout<<"Ingrese las posibles rutas."<<endl; 
		cin>>ruta; 
		pnodoDobleT tiposTrenes = primero;bool existeTipoTren = false; 
        while(tiposTrenes!=NULL){ 
        	if(tiposTrenes->codTren==codTipTren){ 
        		existeTipoTren = true; 
        		break; 
			} 
			else{ 
				tiposTrenes=tiposTrenes->siguiente; 
			} 
		} 
		if(existeTipoTren){ 
			if(tiposTrenes->listaDeTrenes.primero==NULL){ 
				tiposTrenes->listaDeTrenes.InsertarFinal(codTren,nomTren,numAsientos); 
				cout<<"La lista de Trenes fue registrada con exito "<<endl; 
				cout<<endl; 
			} 
			else{ 
				pnodoSimpTrenes buscarCod = tiposTrenes->listaDeTrenes.primero;bool codRepetido = false; 
				while(buscarCod!=NULL){ 
					if(buscarCod->codTren==codTren){ 
						codRepetido = true; 
						break; 
					} 
					else{ 
						buscarCod=buscarCod->siguiente; 
					} 
				} 
				if(!codRepetido){ 
					tiposTrenes->listaDeTrenes.InsertarFinal(codTren,nomTren,numAsientos); 
					cout<<"La lista de Trenes fue registrada con exito "<<endl; 
					cout<<endl; 
				} 
				else{ 
					// por si el codigo esta repetido 
					cout<<"El codigo del tren ya existe"<<endl; 
				} 
			} 
		} 
		else{ 
			cout<<"El codigo de tipo de tren no existe"<<endl; 
			// por si no existe el tipo de tren 
		} 
	}	 
 
void listaDT:: ModificarTren(){ 
	int codTipTren;cout<<"Ingrese el codigo de tipo de tren: "; cin>>codTipTren; cout<<endl; 
	int codTren; cout<<"Ingrese el codigo de tren: "; cin>>codTren; cout<<endl; 
	string nuevoNomTren; cout<<"Ingrese el nuevo nombre de tren: "; cin>>nuevoNomTren; cout<<endl; 
	int nuevoAsientos; cout<<"Ingrese la nueva cantidad de asientos: "; cin>>nuevoAsientos; cout<<endl; 
	int rutas;cout<<"Ingrese la ruta del tren: "; cin>>rutas; cout<<endl; 
	pnodoDobleT tiposTrenes = primero;bool existeTipoTren = false; 
        while(tiposTrenes!=NULL){ 
        	if(tiposTrenes->codTren==codTipTren){ 
        		existeTipoTren = true; 
        		break; 
			} 
			else{ 
				tiposTrenes=tiposTrenes->siguiente; 
			} 
		} 
		if(existeTipoTren){ 
			pnodoSimpTrenes buscarCod = tiposTrenes->listaDeTrenes.primero;bool codRepetido = false; 
			while(buscarCod!=NULL){ 
				if(buscarCod->codTren==codTren){ 
					codRepetido = true; 
					break; 
				}else{ 
					buscarCod=buscarCod->siguiente; 
				} 
			}if(buscarCod->codTren==codTren){ 
				codRepetido= true; 
				if(codRepetido){ 
					 buscarCod->nombre=nuevoNomTren; 
					 buscarCod->numAsientos= nuevoAsientos; 
					 cout<<"El tren fue modificado correctamente"<<endl;	 
				}else{ 
					cout<<"El codigo de tren no existe"<<endl; 
				} 
		}else{ 
			cout<<"El codigo del tipo de tren ingresado no existe"<<endl; 
		} 
	} 
} 
	 
bool listaDT::Verificar(int codTipTren, int codTren){
    pnodoDobleT buscarTipTren = primero;bool existeTipTren = false; 
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
            return true;
        }
        else{
        	return false;
		}
    }
}
int contarPuntos(string prueba){
	int cantidad = 0, largo = prueba.length();
	for(int y = 0;y<=largo-1;y++){
		if(prueba.at(y)==';'){
			cantidad++;
		}
		else{
			continue;
		}
	}
	return cantidad;
	
}

void listaDT::llenarListaCodRutas(){
	ifstream archivoTR; 
    string texto; 
    archivoTR.open("Trenes.txt", ios::in); 
    if (archivoTR.fail()) { 
        cout << "No se pudo abrir el archivo"; 
        exit(1); 
    } 
    while (!archivoTR.eof()) { 
        getline(archivoTR, texto); 
         
        int posPC = texto.find(";"); 
        int codTipTren = atoi(texto.substr(0, posPC).c_str()); 
        //cout << "Tipo Tren: " << codTipTren << endl; 
         
        string Todo = texto.substr(posPC + 1, texto.length()); 
        int posPC2 = Todo.find(";"); 
        int codTren = atoi(Todo.substr(0, posPC2).c_str()); 
        //cout << "Codigo Tren: " << codTren << endl; 
 
        string Todo2 = Todo.substr(posPC2 + 1, Todo.length()); 
        int posPC3 = Todo2.find(";"); 
        string nomTren = (Todo2.substr(0, posPC3)); 
         
        string Todo3 = Todo2.substr(posPC3 + 1, Todo2.length()); 
        int posPC4 = Todo3.find(";"); 
        int numAsientos = atoi((Todo3.substr(0, posPC4).c_str())); 
         
        string Todo4 = Todo3.substr(posPC4 + 1, Todo3.length()); 
        int posPC5 = Todo4.find(";"); 
        int codRuta = atoi((Todo4.substr(0, posPC5).c_str()));
		int cantidadPts = contarPuntos(Todo4);
		int arrayRutas[cantidadPts+1];
		int e = 0;
		int a = cantidadPts+1;
		int z = cantidadPts+1;
		while(a!=0){
			int posAux = Todo4.find(";");
			int agregar = atoi(Todo4.substr(0,posAux).c_str());
			arrayRutas[e]= agregar;
			e++;
			Todo4 = Todo4.substr(posAux+1,Todo4.length());
			a--;
		}
        
        pnodoDobleT tipoTren= primero; bool flag=false;
        while(tipoTren!=NULL){
        	if (tipoTren->codTren==codTipTren){
        		flag=true;
        		break;
			}else{
				tipoTren=tipoTren->siguiente;
			}
		}if(flag){
			pnodoSimpTrenes tren= tipoTren->listaDeTrenes.primero; bool flagT = false;
			while(tren!=NULL){
				if(tren->codTren==codTren){
					flagT=true;
					break;
				}else{
					tren=tren->siguiente;
				}
			}if (flagT){
				if(tren->listaDeCodRutas.primero==NULL){
					int posicion = 0;
					while(z!=0){
						tren->listaDeCodRutas.InsertarFinal(arrayRutas[posicion]);
						tren->listaDeCodRutas.Mostrar();
						posicion++;
						z--;
					}
					
				}else{
					int posicion = 0;
					while(z!=0){
						tren->listaDeCodRutas.InsertarFinal(arrayRutas[posicion]);
						tren->listaDeCodRutas.Mostrar();
						posicion++;
						z--;
					}
					/*
					pnodoSimp buscarCod = tren->listaDeCodRutas.primero;bool codRepetido = false; 
					while(buscarCod!=NULL){ 
						if(buscarCod->valor==codRuta){ 
							codRepetido = true; 
							break; 
						} 
						else{ 
							buscarCod=buscarCod->siguiente; 
						} 
					}if (!codRepetido){
						
						tren->listaDeCodRutas.InsertarFinal(codRuta);
						//tren->listaDeCodRutas.Mostrar();cout<<endl;cout<<endl;xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
					}else{
						//El codigo de ruta esta repetido
						continue;
					}
					*/
				}
			}else{
				//cout<<"El codigo de tren no existe"<<endl;cout<<endl;cout<<endl;
				//El codigo de tren no existe
				continue;
			}
		}else{
			//cout<<"El codigo de tipo tren no existe"<<endl;cout<<endl;cout<<endl;
			//El codigo del tipo tren no existe
			continue;
		}
	}archivoTR.close();
}

void listaDT::EliminarTren(string& ultimoTrenEliminado){
	int codTipTren;
	int codTren;
	cout<<"Ingrese el codigo del tipo de tren que desea eliminar: ";cin>>codTipTren;cout<<endl;
	cout<<"Ingrese el codigo del tren que desea eliminar: ";cin>>codTren;cout<<endl;
	pnodoDobleT buscarTipTren = primero; bool existeTipTren = false;
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
		}
		else{
			cout<<"Error, el codigo del tren es invalido."<<endl;
		}
	}
	else{
		cout<<"Error, el codigo del tipo de tren es invalido."<<endl;
	}
}


void listaDT::MostrarCodigos(){ 
	int codTipTren; 
	cout<<"Ingrese el codigo del tipo de tren para mostrar todos los trenes de ese tipo: "; 
	cin>>codTipTren;cout<<endl;
	int codTren; 
	cout<<"Ingrese el codigo de tren para mostrar todos los codigos de ruta: "; 
	cin>>codTren;cout<<endl;
	pnodoDobleT mostrar = primero;bool existeTipTren = false; 
	while(mostrar!=NULL){ 
		if(mostrar->codTren==codTipTren){ 
			existeTipTren = true; 
			break; 
		} 
		else{ 
			mostrar=mostrar->siguiente; 
		} 
	} 
	if(existeTipTren){ 
		pnodoSimpTrenes mostrarTren = mostrar->listaDeTrenes.primero; bool existeTren = false;
		while(mostrarTren->siguiente != NULL){
			if(mostrarTren->codTren==codTren){ 
			
				existeTren = true; 
				break; 
			}	 
			else{ 
				mostrarTren = mostrarTren->siguiente;
			} 
		}if(existeTren){
			if(mostrarTren->listaDeCodRutas.ListaVacia()){
				cout<<"No hay ningun codigo de ruta"<<endl;
			}else{
				mostrarTren->listaDeCodRutas.Mostrar();
			}
		}else{
			cout<<"El codigo de tren no existe"<<endl;
		}
	} 
	else{ 
		cout<<"El codigo ingresado no corresponde a ningun tipo de tren."<<endl; 
	} 
} 
