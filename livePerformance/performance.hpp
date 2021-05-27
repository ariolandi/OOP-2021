#ifndef _PERFORMANCE_H
#define _PERFORMANCE_H
#include "spectator.hpp"
#include "feeling.hpp"
#include <string>
#include <vector>


template <typename T>
class LivePerformance: Love, Happiness, Sadness{
private:
    std::string performer;
    std::vector<Spectator<T> > spectators;
public:
    LivePerformance(const std::string& name = ""): Love(50), Sadness(50), Happiness(50), performer(name){}

    void addSpectators(const Ticket<T>* ticket){
        spectators.push_back(Spectator<T>(*ticket));
        int numOfSpectators = ticket->getCountOfPlaces();
        for(int i=1; i<numOfSpectators; i++){
            spectators.push_back(Spectator<T>());
        }
    }

    void askForOpinion(){
        for(int i=0; i<spectators.size(); i++)
            if spectators[i].hasTicket(){
                double love, sadness, happiness;
                cin >> love >> sadness >> happiness;
                Love::operator+=(love);
                Happiness::operator+=(happiness);
                Sadness::operator+=(sadness);
            }
        Love::print();
        Sadness::print();
        Happiness::print();
    }
};




#endif // _PERFORMANCE_H
