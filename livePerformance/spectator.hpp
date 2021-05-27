#ifndef _SPECTATOR_H
#define _SPECTATOR_H
#include "ticket.hpp"
#include <cstring>


template <typename T>
class Spectator{
private:
    Ticket<T>* ticket;

    void copySpectator(const Spectator<T>& other){
        if(!other.hasTicket()){
            ticket = nullptr;
            return ;
        }
        ticket = new Ticket<T>(*other.ticket);
    }

public:
    Spectator(){
        ticket = nullptr;
    }
    Spectator(const Ticket<T>& t){
        ticket = new Ticket<T>(t);
    }
    Spectator(const Spectator<T>& other){
        copySpectator(other);
    }
    Spectator<T>& operator=(const Spectator<T>& other){
        if(this != &other){
            delete ticket;
            copySpectator(other);
        }
        return *this;
    }
    ~Spectator(){
        delete ticket;
    }


    bool hasTicket() const{
        return ticket != nullptr;
    }
};


#endif // _SPECTATOR_H
