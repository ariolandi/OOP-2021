#ifndef EXHIBITION_H
#define EXHIBITION_H
#include "Painting.hpp"
const int MAX_PAINTINGS = 30;

class Exhibition{
private:
	Painting array[MAX_PAINTINGS];
	double price;
	int countOfPaintings;

public:
	Exhibition(const double = 0);
	void addPainting(const Painting&);
	double getValue() const;
};

Exhibition::Exhibition(const double price){
	this->price = price;
	countOfPaintings = 0;
}

void Exhibition::addPainting(const Painting& newPainting){
	array[countOfPaintings] = newPainting;
	countOfPaintings++;
	std::cout <<"added\n";
}

double Exhibition::getValue() const{
	double sumValue = 0;
	for (int i = 0; i < countOfPaintings; i++)
	{
		sumValue += array[i].getValue();
	}
	return sumValue * price;
}


#endif // !EXHIBITION_H
