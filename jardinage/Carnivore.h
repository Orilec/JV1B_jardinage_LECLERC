#ifndef CARNIVORE_H
#define CARNIVORE_H
#include "Plante.cpp"
#include <string>

class Carnivore : public Plante {
    public:
        Carnivore(std::string name, int prix);
        int _joursDepuisNourrie = 0;
        void nourrir();
        void nouveauJour();
        void inspecter();
    
};

#endif