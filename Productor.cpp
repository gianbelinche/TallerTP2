#include "Productor.h"
/*
void Productor::empezar(){
    std::thread thread(productor_interno);
    this->thread = std::move(thread);
}*/

void Productor::terminar(){
    thread.join();
}

Productor::~Productor(){
    if (thread.joinable()){
        thread.join();
    }
}