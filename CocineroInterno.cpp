#include "CocineroInterno.h"
#include "Inventario.h"
#include <unistd.h>

void CocineroInterno::producir(){
    while(true){
        try{
            inventario.extraer(this);
            usleep(60000);
            puntos.aumentarPuntos(5);
        } catch (InventarioEstaCerradoException& e){
            break;
        }
    }
    
}