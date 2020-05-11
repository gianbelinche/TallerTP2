#include "Productor.h"

void Productor::terminar(){
    thread.join();
}

Productor::~Productor(){
    if (thread.joinable()){
        thread.join();
    }
}
