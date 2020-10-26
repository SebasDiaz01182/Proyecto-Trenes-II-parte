#include<fstream>
#include <iostream>
#include <stdlib.h>
#include<string>
#include<sstream>
#include "Conexiones.hpp"
#pragma once
using namespace std;

class nodoCiudad {
public:
    nodoCiudad(int v, string cCiudad)
    {
        codCiudad = v;
        ciudad = cCiudad;
        siguiente = NULL;
        anterior = NULL;
        listaConexiones = listaD();
        primeraConexion = listaConexiones.primero;
    }

    nodoCiudad(int v, string cCiudad, nodoCiudad* signodo, nodoCiudad* antnodo)
    {
        codCiudad = v;
        ciudad = cCiudad;
        siguiente = signodo;
        anterior = antnodo;
    }

public:
    int codCiudad;
    string ciudad;
    nodoCiudad* siguiente;
    nodoCiudad* anterior;
    listaD listaConexiones;
    nodoDoble *primeraConexion;
    
    friend class listaDC;
    friend class nodoDoble;
    friend class listaD;
};
typedef nodoCiudad* pnodoCiudad;

class listaDCCiudad {
public:
    listaDCCiudad() { primero = NULL; }
    ~listaDCCiudad();

    void InsertarInicio(int codCiudad, string ciudad);
    void InsertarFinal(int codCiudad, string ciudad);
    void InsertarPos(int codCiudad, string ciudad, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    
public:
    pnodoCiudad primero;

};

int listaDCCiudad::largoLista()
{
    int cont = 0;

    pnodoCiudad aux = primero;
    if (ListaVacia())
    {
        return cont;
    }
    else
    {
        while (aux->siguiente != primero)
        {
            aux = aux->siguiente;
            cont++;
        }
        return cont;
    }

}
listaDCCiudad::~listaDCCiudad()
{
   pnodoCiudad aux;
   int largo = largoLista();

   
   while(largo!=0) {
      aux = primero;
      primero = primero->siguiente;
      primero->anterior=aux->anterior;
      aux->anterior->siguiente=primero;
      largo--;
      delete aux;
   }
   
}

void listaDCCiudad::InsertarInicio(int codCiudad, string ciudad)
{

    if (ListaVacia())
    {
        primero = new nodoCiudad(codCiudad, ciudad);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodoCiudad nuevo = new nodoCiudad(codCiudad, ciudad);
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        nuevo->siguiente->anterior = nuevo;
        primero = nuevo;
    }
}

void listaDCCiudad::InsertarFinal(int codCiudad, string ciudad)
{
    if (ListaVacia())
    {
        primero = new nodoCiudad(codCiudad, ciudad);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodoCiudad nuevo = new nodoCiudad(codCiudad, ciudad);
        nuevo->anterior = primero->anterior;
        nuevo->siguiente = primero->anterior->siguiente;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo;
    }
}


void listaDCCiudad::InsertarPos(int codCiudad, string ciudad, int pos)
{
    if (ListaVacia())
    {
        primero = new nodoCiudad(codCiudad, ciudad);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        if (pos <= 1)
            InsertarInicio(codCiudad, ciudad);
        else
        {
            if (pos == largoLista())
                InsertarFinal(codCiudad, ciudad);
            else
            {
                pnodoCiudad aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != primero))
                {
                    i++;
                    aux = aux->siguiente;
                }
                pnodoCiudad nuevo = new nodoCiudad(codCiudad, ciudad);
                nuevo->siguiente = aux->siguiente;
                aux->siguiente = nuevo;
                aux->siguiente->anterior = aux;
                nuevo->siguiente->anterior = nuevo;
            }
        }
    }
}

void listaDCCiudad::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoCiudad temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCiudad aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodoCiudad temp = aux->siguiente;
            aux->siguiente = primero;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDCCiudad::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodoCiudad temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodoCiudad aux = primero->anterior;
            pnodoCiudad temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDCCiudad::BorrarPosicion(int pos)
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
                pnodoCiudad aux = primero;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }
                pnodoCiudad temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void listaDCCiudad::Mostrar()
{
    pnodoCiudad aux = primero;
    while (aux->siguiente != primero)
    {

        cout << aux->codCiudad << "-" << aux->ciudad << "->";
        aux = aux->siguiente;
    }
    cout << aux->codCiudad << "-" << aux->ciudad << "->";
    cout << endl;
}

