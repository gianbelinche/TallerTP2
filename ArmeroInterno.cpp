#include "ArmeroInterno.h"
#include <unistd.h>
#include "PuntosDeBeneficio.h"
#define TIEMPO_ESPERA 60000

void ArmeroInterno::producir(){
    while (true){
        try{
            inventario.extraerArmero();
            usleep(TIEMPO_ESPERA);
            puntos.aumentarPuntos(3);
        } catch(InventarioEstaCerradoException& e){
            break;
        }
    }
}
