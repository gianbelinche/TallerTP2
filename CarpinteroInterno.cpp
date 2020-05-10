#include "CarpinteroInterno.h"
#include <unistd.h>

void CarpinteroInterno::producir(){
    while(true){
        try{
            inventario.extraer(this);
            usleep(60000);
            puntos.aumentarPuntos(2);
        } catch (InventarioEstaCerradoException& e){
            break;
        }
    }
    
}