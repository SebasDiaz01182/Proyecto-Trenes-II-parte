#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<string>
#pragma once
using namespace std;
//TDA Tipo abstractos de Datos, no pertenece al lenguaje, sin embargo, cuando el programador lo define se puede empezar a utilizar

class nodoSimp { //clase NODO

public:
    nodoSimp(int v) // 20 Tiene diferente cantidad de parametros, diferente tipos. Mismo nombre de la clase
    {
        valor = v;//20
        siguiente = NULL;
    }


    nodoSimp(int v, nodoSimp* signodo) // 2 dirprimero direccion de memoria
    {
        valor = v;//2
        siguiente = signodo;//primero
    }


public: // atributos
    int valor; // tipo entero. Ej clase estudiante nombre,dir,tel,siguente
    nodoSimp* siguiente; // tipo de la clase, clase autoreferencia. Direccion 


    friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores
    friend class listaDT;
    friend class nodoDobleT;

};
typedef nodoSimp* pnodoSimp; //alias redefinir los punteros

class lista {
public:
    lista()
    {
        primero = NULL;

    }
    ~lista();
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos(int v, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Mostrar();
    void Primero();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
public:
    pnodoSimp primero; // nodo *primero; tipo nodo tiene derechoi direccionar un nodo

};

lista::~lista() //Destructor
{
    pnodoSimp aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

int lista::largoLista() { //largo
    int cont = 0;

    pnodoSimp aux; //nodo *aux;
    aux = primero;
    if (ListaVacia()) {
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

void lista::InsertarInicio(int v)
{
    if (ListaVacia())
        primero = new nodoSimp(v);
    else
        primero = new nodoSimp(v, primero);
}

void lista::InsertarFinal(int v)
{
    if (ListaVacia())
        primero = new nodoSimp(v);
    else
    {
        pnodoSimp aux = primero;
        while (aux->siguiente != NULL)
            aux = aux->siguiente;
        aux->siguiente = new nodoSimp(v);
    }
}

void lista::InsertarPos(int v, int pos)
{
    if (ListaVacia())
        primero = new nodoSimp(v);
    else {
        if (pos <= 1) {                     //InsertarInicio(v);
            pnodoSimp nuevo = new nodoSimp(v);
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        else
        {
            if (pos >= largoLista())
                InsertarFinal(v);
            else
            {

                pnodoSimp aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != NULL)) {
                    i++;
                    aux = aux->siguiente;
                }
                pnodoSimp nuevo = new nodoSimp(v); //1 NODO
                nuevo->siguiente = aux->siguiente; // 2 Nuevo con el valor siguiente 20
                aux->siguiente = nuevo;// 3 aux con nuevo
            }

        }
    }
}

void lista::BorrarFinal()
{
    if (ListaVacia()) {
        cout << "No hay elementos en la lista:" << endl;

    }
    else {
        if (primero->siguiente == NULL) {
            primero = NULL;
        }
        else {

            pnodoSimp aux = primero;
            while (aux->siguiente->siguiente != NULL) {
                aux = aux->siguiente;

            }

            pnodoSimp temp = aux->siguiente;
            aux->siguiente = NULL;


            delete temp;
        }
    }
}

void lista::BorrarInicio()
{
    if (ListaVacia()) {
        cout << "No hay elementos en la lista:" << endl;

    }
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoSimp temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {

            pnodoSimp aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}



void lista::borrarPosicion(int pos) {
    if (ListaVacia()) {
        cout << "Lista vacia" << endl;
    }
    else {
        if ((pos > largoLista()) || (pos < 0)) {
            cout << "Error en posicion" << endl;
        }
        else {
            if (pos == 1) {
                primero = primero->siguiente;
            }
            else {
                int cont = 2;
                pnodoSimp aux = primero;
                while (cont < pos) {
                    aux = aux->siguiente;
                    cont++;
                }
                aux->siguiente = aux->siguiente->siguiente;
            }
        }
    }

}


void lista::Mostrar()
{
    nodoSimp* aux;
    if (primero == NULL)
        cout << "No hay elementos";
    else
    {
        aux = primero;
        while (aux)
        {
            cout << aux->valor << "-> ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
}



