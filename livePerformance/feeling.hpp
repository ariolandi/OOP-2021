#ifndef _FEELING_H
#define _FEELING_H
#include <cstring>
#include <stdexcept>
#include <exception>
#include <iostream>


class Feeling{
private:
    char name[10];
    char emoji[10];

    void setName(const char*);
    void setEmoji(const char*);

protected:
    double degree;
    void operator+=(const double);
public:
    Feeling(const char* = "", const double = 0, const char* = "");
    Feeling(const Feeling&);
    Feeling& operator=(const Feeling&);


    void print() const;
};

void Feeling::setName(const char* name_){
    if (strlen(name_) > 10)
        throw std::out_of_range("Name must be maximum 10 characters");
    strcpy(name, name_);
}

void Feeling::setEmoji(const char* emoji_){
    if (strlen(emoji_) > 10)
        throw std::out_of_range("Emoji must be maximum 10 characters");
    strcpy(emoji, emoji_);
}

void Feeling::operator+=(const double degree_){
    degree = (degree + degree_) / 2;
}

Feeling::Feeling(const char* name_, const double degree_, const char* emoji_){
    setName(name_);
    setEmoji(emoji_);
    degree = degree_;
}

Feeling::Feeling(const Feeling& other){
    setName(other.name);
    setEmoji(other.emoji);
    degree = other.degree;
}

Feeling& Feeling::operator=(const Feeling& other){
    if(this != &other){
        setName(other.name);
        setEmoji(other.emoji);
        degree = other.degree;
    }
    return *this;
}

void Feeling::print() const{
    std::cout << name << " (" << emoji << "): " << degree << std::endl;
}

///---------------------

class Love: public Feeling{
public:
    Love(const double degree): Feeling("love", degree, "<3"){}
};

class Sadness: public Feeling{
public:
    Sadness(const double degree): Feeling("sadness", degree, ":("){}
};


class Happiness: public Feeling{
public:
    Happiness(const double degree): Feeling("happiness", degree, ":)"){}
};


#endif // _FEELING_H
