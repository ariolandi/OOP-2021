#ifndef _TICKET_H
#define _TICKET_H
#include <cstring>
#include <stdexcept>
#include <exception>
#include <vector>

/**
cstring -> char* -> strlen, strcpy....
string -> std::string -> +, +=, size....
*/

/**
T -> default constructor, copy constructor, operator=, destructor
*/
template <typename T>
class Ticket{
private:
    char* name;
    T id;

    void copyTicket(const Ticket&);
    void setName(const char*);

protected:
    int price;

public:
    Ticket(const char* = "", const int = 0, const T& = T());
    Ticket(const Ticket<T>&);
    Ticket<T>& operator=(const Ticket<T>&);
    ~Ticket();

    /*virtual */const int getPrice() const;
    virtual int getCountOfPlaces() const { return 1; }
};

template <typename T>
void Ticket<T>::setName(const char* name_){
    name = new char[strlen(name_) + 1];
    strcpy(name, name_);
}

template <typename T>
void Ticket<T>::copyTicket(const Ticket<T>& other){
    setName(other.name);
    id = other.id;
    price = other.price;
}


template <typename T>
Ticket<T>::Ticket(const char* name_, const int price_, const T& id_ ): id(id_), price(price_){
    setName(name_);
}


template <typename T>
Ticket<T>::Ticket(const Ticket<T>& other){
    copyTicket(other);
}


template <typename T>
Ticket<T>& Ticket<T>::operator=(const Ticket<T>& other){
    if(this != &other){
        delete[] name;
        copyTicket(other);
    }
    return *this;
}

template <typename T>
Ticket<T>::~Ticket(){
    delete[] name;
}

template <typename T>
const int Ticket<T>::getPrice() const {
    return price;
}

///--------------------------------------

template <typename T>
class GroupTicket: public Ticket<T> {
private:
    int countOfPlaces;
public:
    GroupTicket(const int = 20, const char* = "", const int = 0, const T& = T());

    int getCountOfPlaces() const {return countOfPlaces;}

    /*const int getPrice() const; */
};

template <typename T>
GroupTicket<T>::GroupTicket(const int countOfPlaces_, const char* name_, const int price_, const T& id_): Ticket<T>(name_, price_, id_){
    if (countOfPlaces_ < 20)
        throw std::logic_error("Group tickets are for at least 20 places");

    countOfPlaces = countOfPlaces_;
    int singlePrice = Ticket<T>::price - countOfPlaces < 0 ? 0 : Ticket<T>::price - countOfPlaces;
    Ticket<T>::price = singlePrice * countOfPlaces;
}

/*
template <typename T>
const int GroupTicket<T>::getPrice() const {
    return price * countOfPlaces;
}
*/

///-------------------------------------

template <typename T>
int getPriceSum(std::vector<Ticket<T> >& tickets){
    int sum = 0;
    for(int i=0; i<tickets.size(); i++){
        sum += tickets[i].getPrice();
    }
    return sum;
}

#endif // _TICKET_H
