#ifndef BOTANISTE_H
#define BOTANISTE_H
#include "Plante.cpp"
#include <string>
#include <vector>
class Botaniste
{
protected:
    std::vector<Plante*> _plantes;
    int _argent;
    int _engrais;

public:
    Botaniste();
    std::vector<Plante*> getPlantes();
    int getArgent();
    int getEngrais();
    void dormir();
    void utiliseEngrais(Plante * plante);
    void achatPlante(std::string name, int prix, std::string type);
    void ventePlante(Plante * plante);
    void achatEngrais();
    void afficheRessources();
};
#endif