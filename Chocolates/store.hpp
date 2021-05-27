#ifndef _STORE_H
#define _STORE_H
#include "chocolates.hpp"
#include <vector>
#include <iostream>

class Store{
private:
    std::vector<MilkChocolate*> milkChocolates;
    std::vector<DarkChocolate*> darkChocolates;


    void copyStore(const Store& other);
    void deleteStore();
public:
    Store(){}
    Store(const Store& other);
    Store& operator=(const Store& other);
    ~Store();

    template <typename T>
    void addChocolate(const Chocolate<T>* chocolate){
        if(typeid(T) == typeid(int)){
            ///During class, we forgot to dynamic cast the type here
            const MilkChocolate* mChocolate = dynamic_cast<const MilkChocolate*>(chocolate);
            milkChocolates.push_back(new MilkChocolate(*mChocolate));
        } else {
            const DarkChocolate* dChocolate = dynamic_cast<const DarkChocolate*>(chocolate);
            darkChocolates.push_back(new DarkChocolate(*dChocolate));
        }
    }

};



void Store::copyStore(const Store& other){
    for(int i=0; i<other.milkChocolates.size(); i++)
        addChocolate(other.milkChocolates[i]);
    for(int i=0; i<other.darkChocolates.size(); i++)
        addChocolate(other.darkChocolates[i]);
}

void Store::deleteStore(){
    for(int i=0; i<milkChocolates.size(); i++)
        delete milkChocolates[i];
    for(int i=0; i<darkChocolates.size(); i++)
        delete darkChocolates[i];
}

Store::Store(const Store& other){
    copyStore(other);
}

Store& Store::operator=(const Store& other){
    if(this != &other){
        deleteStore();
        copyStore(other);
    }
}

Store::~Store(){
    deleteStore();
}

///------------------------------------


class SingletonStore{
protected:
public:
    static Store store;
};

Store SingletonStore::store = Store();




#endif // _STORE_H
