//Clase Main 
 
//Incluimos todos los headers
 
#include <iostream> 
#include "CodigosRuta.hpp" 
#include "Rutas.hpp" 
#include "Pais-Ciudad.hpp"
#include "Ciudad.hpp" 
#include "Conexiones.hpp" 
#include "Admin.hpp" 
#include "Usuario.hpp" 
#include"Tipo-Tren.hpp" 
#include "Trenes.hpp" 
#include<stdlib.h> 
#include<string.h> 
#include<fstream> 
using namespace std;
//Definicion de clases
 
 
 
 
 
 
//Definicion de Funciones
 
 
 
 
//Funcion main 
 
int main() { 
	//------------------------------------------------------------Creacion de listas------------------------------------------- 
	listaDC paises; 
	listaDT tipoTren;
    listaC rutas; 
    listaC2 admin;
	listaDCUsuario usuario; 
	listaTrenes trenes;
	lista codigoRuta;
	string ultimoPais;
	string ultimaCiudad;
	int ultimaConexion;
	string ultimoTipoTren;
	string ultimoTrenEliminado;
	int ultimaRutaEliminada;
	//-----------------------------------------------------Llamar a las funciones de crear la estructura------------------------ 
	//PRIMERA ESTRUCTURA PAIS-CIUDAD-CONEXION 
	paises.llenarListaPais();
    paises.llenarListaCiudad();
    paises.llenarListaConexiones();

    //SEGUNDA ESTRUCTURA TIPO DE TRENES TRENES CODIGOS DE RUTAS 
    tipoTren.llenarListaTipotrenes();
    tipoTren.llenarListaTrenes();
    tipoTren.llenarListaCodRutas();
    //TERCERA USUARIO ADMINISTRADOR RUTAS  
	usuario.llenarListaUsuario(paises);	
	admin.llenarListaAdmin();
	rutas.llenarListaRutas(paises,tipoTren);
	//Campo de testing
    //------------------------------------------------------Inicializar Variables---------------------------------------------- 
	int opcion; 
	int codPais;
	string nomPais; 
	int codCiudad;
	string nomCiudad;
	int codConexion;
	int codPais2; 
	int codCiudad2;
	int codTiempo;
	int codUsuario;
	int registrar;
	//---------------------------------------------------------Menu Principal------------------------------------------------- 
    do { 
        system("cls");      // Para limpiar la pantalla 
         
        // Texto del men? que se ver? cada vez 
         
        cout << "\n\nSistema de Trenes" << endl; 
        cout << "\n\nInicio de sesion" << endl; 
        cout << "1. Iniciar como Administrador" << endl; 
        cout << "2. Iniciar como Usuario" << endl; 
        cout << "3. Salir" << endl; 
         
        cout << "\nIngrese una opcion: "; 
        cin >> opcion; 
         
        switch (opcion) { 
            case 1: 
                // Lista de instrucciones de la opci?n 1 
				int codAdmin;                 
                cout<<"Ingrese el codigo de Administrador: "; 
                cin>> codAdmin; 
                if (admin.VerificarAdmin(codAdmin)){ 
                	cout<<"Bienvenido"<<endl; 
                		int opcion; 
                		 
						do { 
					        system("cls");      // Para limpiar la pantalla 
					         
					        // Texto del men? que se ver? cada vez 
					         
					        cout << "\n\nSistema de Trenes" << endl; 
					        cout << "\n\nMenu del Administrador" << endl; 
					        cout << "1. Insertar" << endl; 
					        cout << "2. Eliminar" << endl; 
					        cout << "3. Modificar" << endl; 
					        cout << "4. Consultar paises" << endl; 
					        cout << "5. Consultar conexiones de una ciudad" << endl; 
					        cout << "6. Consultar ciudades de un pais" << endl; 
					        cout << "7. Consultar rutas de un tren" << endl; 
					        cout << "8. Consultar trenes de un tipo" << endl; 
					        cout << "9. Registrar trenes" << endl; 
					        cout << "10. Consultar Precio" << endl; 
					        cout << "11. Numero de asientos disponibles" << endl; 
					        cout << "12. Salir" << endl; 
					        cout << "\nIngrese una opcion: "; 
					        cin >> opcion; 
					        cout<<endl; 
					         
					        switch (opcion) { 
					            case 1: 
					            	int opcion; 
										do { 
									        system("cls");      // Para limpiar la pantalla 
									     
									        cout << "\n\nSistema de Trenes" << endl; 
									        cout << "\n\nMenu de insertar" << endl; 
									        cout << "1. Pais" << endl; 
									        cout << "2. Ciudad" << endl; 
									        cout << "3. Conexion" << endl; 
									        cout << "4. Tipo de tren " << endl; 
									        cout << "5. Ruta " << endl; 
									        cout << "6. Reporte de actividad " << endl; 
									        cout << "7. Salir" << endl; 
									        cout << "\nIngrese una opcion: "; 
									        cin >> opcion; 
									        cout<<endl; 
									         
									        switch (opcion) { 
									        	 
									            case 1: 
									            	paises.InsertarPais(ultimoPais); 
													system("pause>nul"); 
													break;  
									            case 2: 
									            	paises.InsertarCiudades(ultimaCiudad); 
									            	system("pause>nul"); 
									                break;    
												case 3: 
									            	paises.InsertarConexion(ultimaConexion); 
									                system("pause>nul"); // Pausa 
									                break;                 
									    	 	case 4: 
									    	 		tipoTren.InsertarTipoTren(ultimoTipoTren); 
									                system("pause>nul"); // Pausa 
									                break;    
									            case 5: 
  													rutas.InsertarRuta(paises,tipoTren);
									                system("pause>nul"); // Pausa 
									                break;  
												case 6: 
													if(ultimoPais==""){
														cout<<"No se ha insertado ningun pais"<<endl;
													}else{
														cout<<ultimoPais<<endl;
													}
													if(ultimaCiudad==""){
														cout<<"No se ha insertado ninguna ciudad"<<endl;
													}else{
														cout<<ultimaCiudad<<endl;
													}
													if(ultimaConexion==0){
														cout<<"No se ha insertado ninguna conexion"<<endl;
													}else{
														cout<<"La ultima conexion insertada es: "<<ultimaConexion<<endl;
													}
													if(ultimoTipoTren==""){
														cout<<"No se ha insertado ningun tipo de tren"<<endl;
													}else{
														cout<<ultimoTipoTren<<endl;
													}
									                system("pause>nul"); // Pausa 
									                break;         
											} 
										}while (opcion != 7); 
									    system("pause>nul"); // Pausa 
									    break;    
					            case 2: 
					                int opcion2; 
										do { 
									        system("cls");      // Para limpiar la pantalla 
									     
									        cout << "\n\nSistema de Trenes" << endl; 
									        cout << "\n\nMenu de eliminar" << endl; 
									        cout << "1. Pais" << endl; 
									        cout << "2. Ciudad" << endl; 
									        cout << "3. Conexion" << endl; 
									        cout << "4. Tren " << endl; 
									        cout << "5. Ruta " << endl; 
									        cout << "6. Reporte de actividad " << endl; 
									        cout << "7. Salir" << endl; 
									        cout << "\nIngrese una opcion: "; 
									        cin >> opcion2; 
									        cout<<endl;
									         
									        switch (opcion2) { 
									            case 1: 
									            	rutas.BorrarPais(paises,usuario);
									                system("pause>nul"); // Pausa 
									                break; 
									                 
									            case 2: 
									                // Lista de instrucciones de la opci?n 2                 
									                 rutas.BorrarCiudades(tipoTren,paises,usuario);
									                system("pause>nul"); // Pausa 
									                break; 
									                 
												case 3: 
									                // Lista de instrucciones de la opci?n 2                 
									                 paises.BorrarConexion();
									                system("pause>nul"); // Pausa 
									                break;   
													                   
									    	 	case 4: 
									    	 		rutas.EliminarTren(ultimoTrenEliminado, tipoTren);
									                system("pause>nul"); // Pausa 
									                break;
									                 
									            case 5: 
									            	rutas.BorrarRuta(ultimaRutaEliminada);
									                system("pause>nul"); // Pausa 
									                break; 
									       
												case 6: 
												if(ultimoTrenEliminado==""){
														cout<<"No se ha eliminado ningun tren"<<endl;
													}else{
														cout<<ultimoTrenEliminado<<endl;
													}
													if(ultimaRutaEliminada==0){
														cout<<"No se ha eliminado ninguna ruta"<<endl;
													}else{
														cout<<"La ultima ruta elimianda es la "<<ultimaRutaEliminada<<endl;
													}
									                system("pause>nul"); // Pausa 
									                break;          
											} 
										}while (opcion2 != 7); 
									    system("pause>nul"); // Pausa 
									    break; 
								case 3: 
					                int opcion3; 
										do { 
									        system("cls");      // Para limpiar la pantalla 
									     
									        cout << "\n\nSistema de Trenes" << endl; 
									        cout << "\n\nMenu de Modificar" << endl; 
									        cout << "1. Precio" << endl; 
									        cout << "2. Tiempo" << endl; 
									        cout << "3. Numero de asientos" << endl; 
									        cout << "4. Tren " << endl; 
									        cout << "5. Ruta " << endl; 
									        cout << "6. Estado migratorio " << endl; 
									        cout << "7. Salir" << endl; 
									        cout << "\nIngrese una opcion: "; 
									        cin >> opcion3; 
									        cout<<endl; 
									         
									        switch (opcion3) { 
									            case 1: 
									            	 rutas.ModificarPrecio();
									                system("pause>nul"); // Pausa 
									                break;									                 
									            case 2: 
									                // Lista de instrucciones de la opci?n 2                 
									                paises.ModificarTiempo(); 
									                system("pause>nul"); // Pausa 
									                break; 
												case 3: 
									                // Lista de instrucciones de la opci?n 2                 
									                tipoTren.ModificarNumAsientos(); 
									                system("pause>nul"); // Pausa 
									                break;                     
									    	 	case 4: 
									    	 		tipoTren.ModificarTren(); 
									                system("pause>nul"); // Pausa 
									                break; 
									            case 5: 
  													rutas.ModificarRuta(paises);
									                system("pause>nul"); // Pausa 
									                break;       
												case 6: 
													usuario.ModificarEstadoMigratorio(); 
									                system("pause>nul"); // Pausa 
									                break;      
											} 
										}while (opcion3 != 7); 
									    system("pause>nul"); // Pausa 
									    break;                     
					    	 	case 4: 
					                paises.ConsultarPaises();            
					                system("pause>nul"); // Pausa 
					                break; 
								case 5: 
					                // Lista de instrucciones de la opci?n 2                 
					                paises.ConsultarConexiones(); 
					                system("pause>nul"); // Pausa 
					                break; 
								case 6: 
					                paises.ConsultarCiudades();               
					                system("pause>nul"); // Pausa 
					                break; 
								case 7: 
					                // Lista de instrucciones de la opci?n 2                 
					                rutas.ConsultarRuta();
					                system("pause>nul"); // Pausa 
					                break; 
								case 8: 
					                // Lista de instrucciones de la opci?n 2                 
					                tipoTren.MostrarUnTipoDeTren(); 
					                system("pause>nul"); // Pausa 
					                break;                     
					    	 	case 9: 
					                // Lista de instrucciones de la opci?n 2                 
					                tipoTren.RegistrarTren(); 
					                system("pause>nul"); // Pausa 
					                break; 
								case 10: 
					                // Lista de instrucciones de la opci?n 2                 
					                rutas.ConsultarPrecio(tipoTren); 
					                system("pause>nul"); // Pausa 
					                break; 
								case 11: 
									tipoTren.ConsultarAsientos(); 
					                // Lista de instrucciones de la opci?n 2                 
					                system("pause>nul"); // Pausa 
					                break;                       
						} 
				}while (opcion != 12); 
				 
				}else{ 
					cout<<"El codigo ingresado no existe por favor vuelva a intentarlo"<<endl; 
				} 
                system("pause>nul"); 
                break;	 
            case 2:
            	cout<<"Si desea iniciar sesion digite 1 o si desea registrarse como usuario digite 2"<<endl;cin>>registrar;cout<<endl;
            	if(registrar==1){
            		cout<<"Ingrese la identificacion de usuario: "; cin>>codUsuario; cout<<endl;
	            	if(usuario.VerificarUsuario(codUsuario)){
		                int opcion; 
								do { 
							        system("cls");      // Para limpiar la pantalla 
							        cout << "\n\nSistema de Trenes" << endl; 
							        cout << "\n\nMenu de Usuario" << endl; 
							        cout << "1. Consultar paises" << endl; 
							        cout << "2. Consultar ciudades de un pais" << endl; 
							        cout << "3. Consultar conexiones de un pais" << endl; 
							        cout << "4. Consultar rutas " << endl; 
							        cout << "5. Consultar trenes" << endl; 
							        cout << "6. Consultar Precio" << endl; 
							        cout << "7. Numero de asientos disponibles" << endl; 
							        cout << "8. Salir" << endl; 
							        cout << "\nIngrese una opcion: "; 
							        cin >> opcion; 
							        cout<<endl; 
							         
							        switch (opcion) { 
							            case 1: 
							            	paises.ConsultarPaises(); 
							                system("pause>nul"); // Pausa 
							                break; 
							                 
							            case 2: 
							                // Lista de instrucciones de la opci?n 2                 
							                paises.ConsultarCiudades(); 
							                system("pause>nul"); // Pausa 
							                break; 
										case 3: 
							                // Lista de instrucciones de la opci?n 2                 
							                 paises.ConsultarConexiones();
							                system("pause>nul"); // Pausa 
							                break;                     
							    	 	case 4: 
							                rutas.ConsultarRuta();        
							                system("pause>nul"); // Pausa 
							                break; 
										case 5: 
							                // Lista de instrucciones de la opci?n 2                 
							                tipoTren.MostrarUnTipoDeTren();
							                system("pause>nul"); // Pausa 
							                break; 
										case 6: 
							                rutas.ConsultarPrecio(tipoTren);             
							                system("pause>nul"); // Pausa 
							                break; 
										case 7: 
							                // Lista de instrucciones de la opci?n 2                 
							                tipoTren.ConsultarAsientos();
							                system("pause>nul"); // Pausa 
							                break;      
								} 
							}while (opcion != 8); 
					}else{
						cout<<"La identificacion del usuario no es valida"<<endl<<endl;
						cout<<"Si desea registrarse ingrese 1 de lo contrario ingrese 2 para regresar: ";cin>>registrar;cout<<endl;
						if(registrar==1){
							usuario.RegistrarUsuario(paises);
						}
					}  
				}else{
					usuario.RegistrarUsuario(paises);	
					}         
	                system("pause>nul"); // Pausa 
	                break;           
    	} 		 
	}while (opcion != 3);
    	return 0; 
}
