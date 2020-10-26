#include <fstream>
#include <iostream>
#include <stdlib.h>
#include<string>
using namespace std;

class nodoCir2 {
public:
    nodoCir2(int v, string nNombre)
    {
        valor = v;
        nombre = nNombre;
        siguiente = NULL;
    }

    nodoCir2(int v, string nNombre, nodoCir2* signodo)
    {
        valor = v;
        nombre = nNombre;
        siguiente = signodo;
    }
private:
    int valor;
    string nombre;
    nodoCir2* siguiente;


    friend class listaC2;
};

typedef nodoCir2* pnodoCir2;

class listaC2 {
public:
    listaC2() { primero = NULL; }
    ~listaC2();

    void InsertarInicio(int v, string nombre);
    void InsertarFinal(int v, string nombre);
    void InsertarPos(int v, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void llenarListaAdmin();
    bool VerificarAdmin(int codAdmin);

private:
    pnodoCir2 primero;

};

listaC2::~listaC2()
{
    pnodoCir2 aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

int listaC2::largoLista() {
    int cont = 0;

    pnodoCir2 aux = primero;
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

void listaC2::InsertarInicio(int v,string nombre)
{
   if (ListaVacia()){
    primero = new nodoCir2(v,nombre);
    primero->siguiente=primero;
    }
   else{ // La funcionalidad de esta parte es que crea un nuevo nodo con el valor asignado y la direccion de primero, luego crea un aux con el valor de primero
   // Al entrar al while con el parametro actualizado encontraremos el valor del aux que necesitamos para enlazar el nodo con la dirrecion anterior
   // y posterior por lo que no se hara basura.
       pnodoCir2 nuevo = new nodoCir2(v,nombre);
       pnodoCir2 aux = primero;
       while(aux->siguiente!=primero){
           aux=aux->siguiente;
       }
       aux->siguiente=nuevo;
       primero=nuevo;
   }
}

void listaC2::InsertarFinal(int v,string nombre){
	if (ListaVacia()){
	 primero = new nodoCir2(v,nombre);
	 primero->siguiente=primero;
	}
   else{ 
   pnodoCir2 aux = primero;
    while ( aux->siguiente != primero){
    	aux=aux->siguiente;
	}
	pnodoCir2 nuevo= new nodoCir2(v,nombre);
	aux->siguiente=nuevo;
	nuevo->siguiente=primero;
    } 
}


void listaC2::InsertarPos(int v, string nombre, int pos)
{
    if (ListaVacia())
    {
        pnodoCir2 nuevo = new nodoCir2(v,nombre);
        primero = nuevo;
        nuevo->siguiente = primero;
    }
    else
    {
        if (pos <= 1)
        {
            InsertarInicio(v,nombre);
        }
        else
        {
            pnodoCir2 aux = primero;
            int i = 2;
            while ((i != pos) && (aux->siguiente != primero))
            {
                i++;
                aux = aux->siguiente;
            }
            pnodoCir2 nuevo = new nodoCir2(v,nombre);
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
}

void listaC2::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoCir2 temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCir2 aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodoCir2 temp = aux->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void listaC2::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoCir2 temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCir2 aux = primero;
            pnodoCir2 temp = primero;
            while (aux->siguiente != primero)
                aux = aux->siguiente;
            primero = primero->siguiente;
            aux->siguiente = primero;
            delete temp;
        }
    }
}

void listaC2::borrarPosicion(int pos)
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
                pnodoCir2 aux = primero;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }
                pnodoCir2 temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}
void listaC2::Mostrar()
{
    pnodoCir2 aux = primero;
    while (aux->siguiente != primero)
    {

        cout << aux->valor << "-" << aux->nombre << "->";
        aux = aux->siguiente;
    }
    cout << aux->valor << "-" << aux->nombre << "->";
    cout << endl;
}

void listaC2::llenarListaAdmin() {
	ifstream archivo;
    string texto;
    archivo.open("Administradores.txt", ios::in);
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }else{
    	while (!archivo.eof()) {
	    	getline(archivo, texto);
	    	int posC= texto.find(";");
	    	int codAdmin=atoi(texto.substr(0, posC).c_str());
	    	string nombreAdmin= texto.substr(posC+1, texto.length());
	    	//cout<<codAdmin;cout<<nombreAdmin<<endl;
	    	if (primero==NULL){
	    		//cout<<"La lista esta vacia"<<endl; 
	    		//InsertarInicio(codAdmin,nombreAdmin);
	    		primero= new nodoCir2(codAdmin,nombreAdmin);
	    		primero->siguiente=primero;
			}else{
				pnodoCir2 recorrer=primero; bool bandera=true;
				while(recorrer->siguiente!=primero){
					if (recorrer->valor==codAdmin){
						//cout<<"Encontre un repetido"<<recorrer->nombre<<endl;
						bandera=false;
						break;
					}else{
						recorrer=recorrer->siguiente;
					}
				}if (bandera){
					if(recorrer->valor!=codAdmin){
						//cout<<"No estoy repetido voy a entrar"<<endl;
						InsertarFinal(codAdmin,nombreAdmin);
					}
				}else{
					continue;
				}
			}
		}archivo.close();
	}	
}

bool listaC2::VerificarAdmin(int codAdmin){
	pnodoCir2 puntero=primero;
	bool flag= false;
	while(puntero->siguiente != primero){
		if (puntero->valor==codAdmin){
			return true;
		}else{
			puntero=puntero->siguiente;
		}
	}if (puntero->valor==codAdmin){
		return true;
	}else{
		return false;	
	}
}
