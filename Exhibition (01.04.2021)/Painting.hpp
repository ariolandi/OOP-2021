#ifndef PAINTING_H
#define PAINTING_H
#include <cstring>
#include <iostream>

class Painting{
private:
	unsigned int id;
	char* name;
	char* author;
	double value;

	void copyPainting(const Painting&);
	void deletePainting();
public:
	Painting(const unsigned int = 0, const char* = "", const char* = "", const double = 0 );
	Painting(const Painting&);
	Painting& operator=(const Painting&);
	~Painting();

	double getValue() const;

	void read(std::istream& in = std::cin);
};

Painting::Painting(const unsigned int id, const char* name , const char* author, const double value){
	this->id = id;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name,name);
	this->author= new char[strlen(author) + 1];
	strcpy(this->author, author);
	this->value= value;
}

Painting::Painting(const Painting& other){
	copyPainting(other);
}

Painting::~Painting(){
	deletePainting();
}

Painting& Painting::operator=(const Painting& other){
	if (this != &other)
	{
		deletePainting();
		copyPainting(other);
	}
	return *this;
}

double Painting::getValue() const{
	return value;
}

void Painting::read(std::istream& in){
    char name[30];
    char author[30];
    unsigned int id;
    double value;
    in >> id >> author >> name >> value;
    *this = Painting(id, name, author, value);
}

void Painting::copyPainting(const Painting& other){
	this->id = other.id;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->author = new char[strlen(other.author) + 1];
	strcpy(this->author, other.author);
	this->value = other.value;
}

void Painting::deletePainting(){
	delete[] name;
	delete[] author;
}

//-------------



#endif //PAINTING_H
