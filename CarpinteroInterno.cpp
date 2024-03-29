#include "CarpinteroInterno.h"
#include <unistd.h>
#include "PuntosDeBeneficio.h"
#define TIEMPO_ESPERA 60000

void CarpinteroInterno::producir(){
    while (true){
        try{
            inventario.extraerCarpintero();
            usleep(TIEMPO_ESPERA);
            puntos.aumentarPuntos(2);
        } catch(InventarioEstaCerradoException& e){
            break;
        }
    }
}
