#include "CocineroInterno.h"
#include <unistd.h>
#include "PuntosDeBeneficio.h"
#define TIEMPO_ESPERA 60000

void CocineroInterno::producir(){
    while (true){
        try{
            inventario.extraerCocinero();
            usleep(TIEMPO_ESPERA);
            puntos.aumentarPuntos(5);
        } catch(InventarioEstaCerradoException& e){
            break;
        }
    }
}
