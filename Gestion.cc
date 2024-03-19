
/*INTEGRANTES:
              LUIS DAVID ARIAS ISAZA Y WALTER DAVID ESTUPIÑAN CASTILLO
                               IS03D1 - 2024-1
              
              
*/

#include <iostream>
#include <malloc.h>
using namespace std;
#include <conio.h>
struct producto{
    int id;
    char nombre[50];
    int cantidad;
    float precio;
    int ganancias = 0;
    producto *sig;

};

struct producto *cab, *aux, *aux2;


//Registrar Producto: Agregar un nuevo producto al final de la cola del inventario.
int registrarProducto(){

aux = (struct producto *) malloc(sizeof(struct producto));

//cout<<"--->";  \n  cout<<"========================================================================================================================\n";
cout<<"     Ingrese el ID del producto: \n";
cout<<"     ---> "; cin>>aux->id;
cout<<"========================================================================================================================\n";

aux2 = cab;
while (aux2 != NULL) {
    if (aux2->id == aux->id) {
            cout << "     El ID ya está registrado. Cancelando el registro del producto.\n";
            cout<<"========================================================================================================================\n";

            free(aux);
            return 0;
        }
        aux2 = aux2->sig;
    }

aux->sig = NULL;
cout<<"     Ingrese el nombre del producto: \n";
cout<<"     ---> "; cin>>aux->nombre;
cout<<"========================================================================================================================\n";
aux->sig = NULL;
cout<<"     Ingrese la cantidad de unidades disponibles: \n";
cout<<"     ---> "; cin>>aux->cantidad;
cout<<"========================================================================================================================\n";
aux->sig = NULL;
cout<<"     Ingrese el precio para cada unidad: \n";
cout<<"     ---> $"; cin>>aux->precio;
cout<<"========================================================================================================================\n";
aux->sig = NULL;

if (cab==NULL){
    cab=aux;
    aux=NULL;
    free(aux);
}else{
    aux2 = cab;
    while(aux2->sig != NULL){
        aux2 = aux2->sig;
    }
    aux2->sig = aux;
    aux2 = aux = NULL;
    free(aux);
    free(aux2);
    }
}

//Mostrar Inventario: Listar todos los productos en el inventario, mostrando su ID, nombre, cantidad y precio por unidad.
int mostrarInventario(){
   
    for (aux = cab; aux != NULL; aux=aux->sig)
    
    cout<<"  "<<aux->id<<"                             "<<aux->nombre<<"                      "<<aux->cantidad<<"                              "<<"$"<<aux->precio<<"                             \n";
    cout<<"========================================================================================================================\n";
    cout<<" \n";
    cout<<" \n";
    cout<<" \n";
    cout<<" \n";
    cout<<"========================================================================================================================\n";
}

//Buscar Producto por ID: Buscar y mostrar la información de un producto utilizando su ID.
int buscarID(){
	
	int buscar=0;

	cout<<"     Digite el ID del producto que desea buscar: \n";
	cout<<"     ---> "; cin>>buscar;
    cout<<"========================================================================================================================\n";
	
	aux=cab;

	for (aux = cab; aux != NULL; aux=aux->sig){

		if(aux->id==buscar){
            
		    cout<<"     El producto digitado ha sido encontrado\n";
            cout<<"========================================================================================================================\n";
		    cout<<"     ID: "<<aux->id<<endl;
		    cout<<"     Producto: "<<aux->nombre<<endl;
		    cout<<"     Cantidad de unidades en stock: "<<aux->cantidad<<endl;
		    cout<<"     Valor unitario: $"<<aux->precio<<endl;
            cout<<"========================================================================================================================\n";	
            return 0;
		    } 
		
	}

    cout<<"     El ID digitado no concuerda con ninguno de los producto de nuestro inventario\n";
    cout<<"========================================================================================================================\n";
    return 0;
}

//Eliminar Producto: Eliminar un producto del inventario basado en su ID. Esta operación debe remover el primer producto que coincida con el ID proporcionado.
int eliminarProducto(){
    int eliminar;
    cout<<"     Ingrese el ID del producto que desea eliminar: \n";
    cout<<"     ---> ";cin>>eliminar;

    
    if (cab != NULL && cab->id == eliminar) {
        aux = cab;
        cab = cab->sig;
        free(aux);
        cout << "     El producto ha sido eliminado correctamente \n";
        return 0;
    }

   
    aux2 = cab;

    while (aux2->sig != NULL) {
        if (aux2->sig->id == eliminar) {
            aux = aux2->sig;
            aux2->sig = aux->sig;
            free(aux);
            cout << "     El producto ha sido eliminado correctamente \n";
            return 0;
        }
        aux2 = aux2->sig;
    }

    cout << "     El ID ingresado no concuerda con ninguno de los disponibles en nuestro inventario \n";
    return 0;
}

//Calcular el Valor Total del Inventario: Sumar el valor total de todos los productos en el inventario (Cantidad * Precio por unidad) y mostrar el resultado. 
int valorTotal(){
    
    int total = 0;
    int cantidadTot = 0;

    for (aux = cab; aux != NULL; aux=aux->sig){

    cantidadTot = aux->cantidad * aux->precio;

    total = total + cantidadTot;

    }

    cout<<"El valor total del inventario general es igual a: $"<<total<<endl;
    cout<<"========================================================================================================================\n";
    return 0; 
}


//Calcular el Promedio de Precios: Determinar el precio promedio por unidad de todos los productos en el inventario. 
int promedioPrecios(){
        int totalp = 0;
        int totalFinal = 0;
        int cantidadtotal = 0;
        int cantidadFinal = 0;
        double promedio = 0.0;
        for (aux = cab; aux != NULL; aux=aux->sig){


            cantidadtotal = aux->cantidad;
            cantidadFinal = cantidadFinal + cantidadtotal;

            totalp = aux->precio * aux->cantidad;
            totalFinal = totalFinal + totalp;
            //totalFinal = totalFinal + total; totalfinal += total;

        }

            promedio = totalFinal / cantidadFinal;
            cout<<"Cantidad total de productos en el mercado: "<<cantidadFinal<<"\n";
            cout<<"Precio promedio por unidad: $"<<promedio<<"\n";
            cout<<"========================================================================================================================\n";
            return 0;
}

//Vender Productos: Permitir la venta de productos mediante el siguiente proceso:
/*
+Solicitar al usuario el ID del producto a vender.
+Buscar el producto por su ID y mostrar su información.
+Preguntar al usuario la cantidad de unidades que desea comprar. 
+Verificar si hay existencias suficientes del producto. Si no hay suficientes, informar al usuario y cancelar la venta.(+10 Puntos)
+Si hay existencias suficientes, descontar la cantidad vendida del inventario y calcular el total a pagar (Cantidad * Precio por unidad). (+10 Puntos)
+Mostrar al usuario el total a pagar por los productos vendidos. (+10 Puntos)
*/

int venta(){

    int nCantVenta = 0;
    int idventa = 0;
    cout<<"     Ingrese el ID del producto que desea vender: \n";
    cout<<"     --->";cin>>idventa;
    cout<<"========================================================================================================================" << endl;
            

    for (aux = cab; aux != NULL; aux = aux->sig){

        if (idventa == aux->id){
            cout<<"El producto digitado ha sido encontrado\n";
            cout<<"========================================================================================================================" << endl;
            cout<<"     ID: " << aux->id << endl;
            cout<<"     Producto: " << aux->nombre << endl;
            cout<<"     Cantidad: " << aux->cantidad << endl;
            cout<<"     V/U: $" << aux->precio<< endl;
            cout<<"========================================================================================================================" << endl;
            cout<<"     Ingrese la cantidad de unidades del producto: \n";
            cout<<"     ---> ";cin >> nCantVenta;
            cout<<"========================================================================================================================" << endl;

            if (nCantVenta <= aux->cantidad){
                aux->cantidad = aux->cantidad - nCantVenta;

                cout<<"     La venta se ha realizado con éxito! " << endl;
                cout<<"========================================================================================================================" << endl;
                cout<<"                                             Actualizacion de producto                                                   \n";
                cout<<"========================================================================================================================" << endl;
                cout<<"     ID: " << aux->id << endl;
                cout<<"     Producto: " << aux->nombre << endl;
                cout<<"     Cantidad: " << aux->cantidad << endl;
                cout<<"     V/U: $" << aux->precio<< endl;
                cout<<"========================================================================================================================" << endl;

                int ganancias = 0;

                ganancias = nCantVenta * aux->precio;

                cout<<"Dinero obtenido de la venta: $" << ganancias << endl;
            }
            
            if (nCantVenta > aux->cantidad){
                cout<<"     Error. Insuficiencia de productos almacenados" << endl;
                cout<<"     Venta cancelada...." << endl;
                cout<<"========================================================================================================================" << endl;
            }
        }
    }
    return 0;
}
//método principal
int main(){


    //menu dinámico

    int opcion=0;

    cout<<"========================================================================================================================\n";
    cout<<"                                                                                                                        \n";
    cout<<"                                             Bienvenido Sistema de Gestion                                              \n";
    cout<<"                                                    de Inventarios                                                      \n";
    cout<<"                                                                                                                        \n";
    cout<<"========================================================================================================================\n";

    do{
        cout<<"     1. Registrar Producto\n";
        cout<<"     2. Mostrar Inventario\n";
        cout<<"     3. Buscar Producto \n";
        cout<<"     4. Eliminar producto \n";
        cout<<"     5. Calcular El Valor Total Del Inventario \n";
        cout<<"     6. Calcular el Promedio de Precios \n";
        cout<<"     7. Vender Producto \n";
        cout<<"     8. Salir del Programa\n";
        cout<<"========================================================================================================================\n";
        cout<<"     Ingrese lo que desea realizar:\n";
        cout<<"     ---> "; cin>>opcion;
        cout<<"========================================================================================================================\n";
    
        


    switch (opcion){

        case 1:
        registrarProducto();
            break;

        case 2:
        cout<<" \n";
        cout<<" \n";
        cout<<" \n";
        cout<<" \n";
        cout<<"========================================================================================================================\n";
        cout<<"                                          INVENTARIO GENERAL                                                            \n";
        cout<<"========================================================================================================================\n";
        cout<<"  ID                             Producto                Cantidad                         V/U                           \n";
        cout<<"========================================================================================================================\n";
        mostrarInventario();
            break;

        case 3:
        buscarID();
            break;

        case 4:
        eliminarProducto();
            break;

        case 5:
        valorTotal();
            break;

        case 6:
        promedioPrecios();
            break;

        case 7:
        venta();
            break;

        case 8:
        cout<<"     Saliendo...\n";
        cout<<"========================================================================================================================\n";
            break;
        
        
    
        default:
        cout<<"     Valor incorrecto\n";
        cout<<"========================================================================================================================\n";          
            break;
        }
    } while (opcion!=8);


    getch();
    cout<<"     !!Gracias por usar nuestro programa, Vuelva pronto!! :D \n";
    cout<<"========================================================================================================================\n";
    return 0;
}