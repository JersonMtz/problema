#include <iostream>
#include <stdlib.h>
using namespace std;

// impuesto de venta agregado
const double IVA = 0.13;

// estructura base para guardar informacion de una fruta
struct Fruta {
	string nombre;
	int precio;
	short cantidad;
};

// funcion que toma datos necesarios para crear una fruta y retorna la una nueva fruta
Fruta crearFruta(string nombre, int precio, short cantidad){
	Fruta fruta;
	fruta.nombre = nombre;
	fruta.precio = precio;
	fruta.cantidad = cantidad;
	return fruta;
}

//  tiendas e inventario de frutas
Fruta tiendas[3][4] = {
	{
		crearFruta("x", 0, 0),
		crearFruta("x", 0, 0),
		crearFruta("x", 0, 0),
		crearFruta("x", 0, 0),
	},
	{
		crearFruta("x", 0, 0),
		crearFruta("x", 0, 0),  
		crearFruta("x", 0, 0), 
		crearFruta("x", 0, 0)
	},
	{
		crearFruta("x", 0, 0),
		crearFruta("x", 0, 0),
		crearFruta("x", 0, 0),  
		crearFruta("x", 0, 0),		
	}
};

int ganancias[3] = { 0, 0, 0 };

void menuPrincipal(){
	system("cls");
	cout<< "*****************************************" <<endl;
	cout<< "* 1-Agregar frutas a tiendas            *" <<endl;
	cout<< "* 2-Ver inventario de frutas por tienda *" <<endl;
	cout<< "* 3-Vender frutas                       *" <<endl;
	cout<< "* 4-Ganancias por tienda                *" <<endl;
	cout<< "* 0-Salir                               *" <<endl;
	cout<< "*****************************************" <<endl;
}

void mostrarTiendas(){
	system("cls");
	cout<< "******************" <<endl;
	cout<< "* 1- Tienda A    *" <<endl;
	cout<< "* 2- Tienda B    *" <<endl;
	cout<< "* 3- Tienda C    *" <<endl;
	cout<< "******************" <<endl;
	cout<< "\nSeleccione una tienda..." <<endl;
}

// funcion que toma un numero del array de tiendas y guarda 1 fruta
void guardarStockFrutas(int numero){
	system("cls");
	for(int i=0; i<4; i++){
		if (tiendas[numero - 1][i].nombre == "x"){
			char nombresTiendas[] = { 'A', 'B', 'C' };
			Fruta frutaNueva;
			cout<< "\tAgregar fruta a tienda "<< nombresTiendas[numero-1] <<endl;
			cout<< "Nombre:  ";
			cin>> frutaNueva.nombre;
			cout<< "Cantidad:  ";
			cin>> frutaNueva.cantidad;
			cout<< "Precio:  ";
			cin>> frutaNueva.precio;
			tiendas[numero - 1][i] = frutaNueva;
			system("pause");
			break;
		}
		
		if(tiendas[numero - 1][i].nombre != "x" && i==3){
			cout<< "\nHa alcanzado el maxima de frutas en almacen\n" <<endl;
			system("pause");
		}
	}
	
}

// muestra el inventario de frutas por tienda
void verInventario(Fruta lista[], int numero){
	system("cls");
	char nombresTiendas[] = { 'A', 'B', 'C' };
	cout<< "\tStock en tienda "<< nombresTiendas[numero-1] <<endl;
	cout<< "FRUTA\t\tPRECIO\t\tCANTIDAD" <<endl;
	for(short f=0; f<4; f++){
		cout<< lista[f].nombre<<"\t\t"<< lista[f].precio <<"\t\t"<< lista[f].cantidad <<endl;
	}
	cout<< "\n";
	system("pause");
}

//funcion que vende fruta de la tienda seleccionada y guarda las ganancias y actualiza el stock
void venderFrutas(int numero){
	system("cls");
	string fruta;
	int cantidad = 0;
	char nombresTiendas[] = { 'A', 'B', 'C' };
	cout<< "\tVenta de fruta"<<endl;
	verInventario(tiendas[numero - 1], numero);
	cout<< "\nEscriba el nombre de la fruta: ";
	cin>> fruta;
	
	for(int i=0; i<4; i++){
		if (tiendas[numero - 1][i].nombre == fruta) {
			cout<< "\nEscriba la cantidad: ";
			cin>> cantidad;
			
			if(cantidad > tiendas[numero - 1][i].cantidad){
				cout<< "\nCantidad de fruta no disponible" <<endl;
				system("pause");
				break;
			}
			
			// actualiza cantidad y realiza los calculos
			tiendas[numero - 1][i].cantidad = tiendas[numero - 1][i].cantidad - cantidad;
			int subtotal = tiendas[numero - 1][i].precio * cantidad; 
			double total = (subtotal * IVA) + subtotal; 
			ganancias[numero - 1] = ganancias[numero - 1] + total;
			cout<< "\nEl total a pagar es de: "<< total<<endl; 
			system("pause");
			break;
			
		} else if (i== 3) {
			cout<< "\nFruta no disponible" <<endl;
			system("pause");
			break;
		}
	}
	
}

void  verGanancias() {
	system("cls");
	cout<< "\tGanacias por tienda"<< endl;
	char nombresTiendas[] = { 'A', 'B', 'C' };
	for(int i=0; i<3; i++){
		cout<< "Tienda "<< nombresTiendas[i]<<": "<< ganancias[i] <<endl; 
	}
	system("pause");
}

// funcion que se encarga de ejecutar las tareas segun la opcion selecionada
void menuOpciones(int opcion){
	int numero;
	switch(opcion){
		case 1:
			mostrarTiendas();
			cin>> numero;
			guardarStockFrutas(numero);
			
			break;
		case 2:
			mostrarTiendas();
			cin>> numero;
			verInventario(tiendas[numero - 1], numero);
			break;
		case 3:
			mostrarTiendas();
			cin>> numero;
			venderFrutas(numero);
			break;
		case 4:
			verGanancias();
			break;
			
	}
}

int main(int argc, char** argv) {
	while(true){
		
		int opcion;
		
		menuPrincipal();
		
		cin>> opcion;	
		menuOpciones(opcion);
		if (opcion == 0){
			break;
		}	
	}
	return 0;
}
