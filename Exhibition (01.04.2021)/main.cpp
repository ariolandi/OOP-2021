#include <iostream>
#include <cstring>
#include "Painting.hpp"
#include "Exhibition.hpp"

/**
void testPaintingCreation(){
Painting first;
	Painting second(12, "Drawing", "Peter", 0.1);
	Painting third(second);
	first = third;
	std::cout << first.getValue() << std::endl;
}
*/


int main()
{
	int N;
	std::cin >> N;
	int mostProfotable = -1;
	double mostProfit = 0;

	for (int i = 0; i < N; i++){
		int countOfPaintings;
		int price;
		std::cin >>countOfPaintings >> price;
		Exhibition exhibition(price);
		for (int i = 0; i < countOfPaintings; i++){
			char name[10];
			char author[10];
			unsigned int id;
			double value;
			std::cin >> id >> author >> name >> value;
			exhibition.addPainting(Painting(id, name, author, value));
		}
		if(exhibition.getValue() > mostProfit){
            mostProfit = exhibition.getValue();
            mostProfotable = i;
		}
	}

	std::cout << "Most profitable exhibition is  #" << mostProfotable << std::endl;
}
