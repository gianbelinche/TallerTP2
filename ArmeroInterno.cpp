#include "ArmeroInterno.h"
#include <unistd.h>

void ArmeroInterno::producir(){
    while (true){
        try{
            inventario.extraer(this);
            usleep(60000);
            puntos.aumentarPuntos(3);
        } catch(InventarioEstaCerradoException& e){
            break;
        }
    }
}
