#ifndef _CHOCO_H
#define _CHOCO_H
#include <string>
#include <iostream>

template <typename T>
class Chocolate{
protected:
    T id;
    virtual bool validateId(const T& id_) = 0;
public:
    Chocolate(const T& id_){
        id = id_;
    }
    virtual ~Chocolate(){}
    const T& getId() const { return id; }
};

///------------------------------------------

class MilkChocolate: virtual public Chocolate<int>{
protected:
    double milk;
    bool validateId(const int& id_){
        return true; ///All int ids are valid ones
    }
public:
    MilkChocolate(const int& id_, const double& milk_ = 35): Chocolate(id_){
        milk = milk_;
        if(!validateId(id_))
            throw std::logic_error("Id is not a valid one!");
    }
    double getMilk() const { return milk; }
};

///-----------------------------------------------

class DarkChocolate: virtual public Chocolate<std::string>{
protected:
    double cocoa;
    bool validateId(const std::string& id_){
        for(int i=0; i< id_.size(); i++)
            if(!((id_[i] >= 'a' && id_[i] <= 'z') || (id_[i] >= 'A' && id_[i] <= 'Z')))
                return false;
        return true;
    }

public:
    DarkChocolate(const std::string& id_, const double& cocoa_ = 80): Chocolate(id_){
        cocoa = cocoa_;
         if(!validateId(id_))
            throw std::logic_error("Id is not a valid one!");
    }
    double getCocoa() const { return cocoa; }
};

///---------------------------------------------

template <typename T>
class Raisins: virtual public Chocolate<T>{
protected:
    double raisins;
    virtual bool validateId(const T& id_){
        return true;
    }

public:
    Raisins(const double& raisins_ = 20): Chocolate<T>(T()){
        raisins = raisins_;
    }
    double getRaisins() const { return raisins; }
};

///----------------------------------------------


class MilkWithRaisins: public MilkChocolate, public Raisins<int>{
private:
    bool validateId(const int& id_) {
        int tmp = id_;
        int x = tmp % 10, y=0;
        tmp /= 10;
        while(tmp > 0){
            y = x;
            x = tmp % 10;
            tmp /= 10;
        }
        return (x*10 + y) == 45;
    }

public:
    MilkWithRaisins(const int& id_, const double& milk_ = 35, const double& raisins_ = 20): MilkChocolate(id_, milk_), Raisins(raisins_), Chocolate(id_){
         if(!validateId(id_))
            throw std::logic_error("Id is not a valid one!");
    }
};

///-----------------------------------------

class DarkWithRaisins: public DarkChocolate, public Raisins<std::string>{
private:
    bool validateId(const std::string& id_){
        return id_[0] == 'S';
    }

public:
    DarkWithRaisins(const std::string& id_, const double& cocoa_ = 80, const double& raisins_ = 20): DarkChocolate(id_, cocoa_), Raisins(raisins_), Chocolate(id_){
        if(!validateId(id_))
            throw std::logic_error("Id is not a valid one!");
    }
};


///-------------------------------------------

Chocolate<int>* createMilkChocolate(int id, double milk){
    try{
        return new MilkWithRaisins(id, milk);
    } catch(...){
        return new MilkChocolate(id, milk);
    }
}


Chocolate<std::string>* createDarkChocolate(std::string id, double cocoa){
    try{
        return new DarkWithRaisins(id, cocoa);
    } catch(...){
        return new DarkChocolate(id, cocoa);
    }
}




#endif // _CHOCO_H
