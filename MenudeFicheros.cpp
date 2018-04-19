#include<iostream>
#include<stdlib.h>
#include<fstream>
	using namespace std;
	void escribir();
	void leer();
	void transformar();
	

	int main()
	{
		int opcion, resp;
		do{
		cout <<"\n\t1. Escribir archivo (Crea, abre y escribe datos en el archivo)" << endl;
		cout <<"\n\t2. Lectura de archivo (Busca, abre y lee los datos del archivo)" <<endl;
		cout <<"\n\t3. Convertir Minúsculas a Mayúsculas (Convierte a mayúsculas los caracteres almacenados en un archivo)\n";
		cout <<"\n\t4. Salir" << endl;
		
		cout << "\nSelecciona una opcion: ";
		cin >> opcion;
			system("cls");
		switch (opcion) {
			case 1:
			escribir();
			escribir();
				break;
			case 2:
				leer();
				break;
			case 3:
			transformar();
				break;
			case 4:
			cout<<"\n\tUsted ha salido del menu";
				return 0;
				break;
			default:
			cout<<"\n\tValor no valido"<<endl;
				break;
			}
		cout<<"\n\tSi desea terminar ingrese 0, si desea continuar ingrese cualquier valor: ";cin>>resp; 
			system("cls");
		}while (resp!=0);
	} 
	
	
	void escribir(){
		fstream archivo;
		string frase;
		string nombreArchivo;
		cout<<"\n\tComo quiere llamar al nuevo archivo:  ";
		cin>>nombreArchivo;
		archivo.open(nombreArchivo.c_str(),ios::out);	
		if(archivo.fail()){ //Si ocurre un error
			cout<<"\n\tNo se pudo abrir el archivo";
			exit(1);
		}
		else{
			fflush(stdin);
			cout<<"\n\tDigite una frase: ";
			getline(cin,frase);
			archivo<<frase<<endl;}
		archivo.close();
	}
	

	void leer()
	{
		fstream archivo;
		string nombreArchivo;
		string frase;
		cout << "\n\tEscriba el nombre del archivo que desea abrir: ";
		cin>>nombreArchivo;	
	    archivo.open ( nombreArchivo.c_str() , ios::in);
	    if (archivo.is_open()) {
	    	cout<<"\n\tEl contenido del archivo es: ";
	        while (! archivo.eof() ) {
	            getline (archivo,frase);
	            cout<<"\t";cout<< frase << endl;
	        }
	        archivo.close();
	    }
	    else cout << "\tFichero inexistente o faltan permisos para abrirlo" << endl;  
	}
	
	

	void transformar()
	{
		fstream archivo;
		fstream h;
		string nombreArchivo,nuevo;
		char dato;
		cout<<"\n\tDigite el nombre del archivo que desea abrir: \t";
		cin>>nombreArchivo;
		archivo.open(nombreArchivo.c_str(),ios::in);
		cout<<"\n\tDigite el nombre del nuevo archivo: \t";
		cin>>nuevo;
		h.open(nuevo.c_str(),ios::out);
		if(!archivo){
			cout<<"\n\tNo se pudo abrir el fichero"<<endl;
		} else {
			cout<<"\n\tEl contenido de su nuevo archivo es: ";
			while(!archivo.eof()){
				dato=archivo.get();
				dato=toupper(dato);
				h<<dato;
				
				cout<<dato;
				}
		
			}
		archivo.close();
		h.close();
	}
		

