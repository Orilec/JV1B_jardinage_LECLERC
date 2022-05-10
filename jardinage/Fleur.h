#ifndef FLEUR_H
#define FLEUR_H
#include "Plante.cpp"
#include <string>

class Fleur : public Plante {
    public:
        Fleur(std::string name, int prix);
        bool _isEclot;
        bool _isFanee;
        void nouveauJour();
        void inspecter();
    
};

#endif