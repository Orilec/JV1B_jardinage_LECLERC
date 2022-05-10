#ifndef BOTANISTE_CPP
#define BOTANISTE_CPP
#include "Plante.cpp"
#include "Fleur.cpp"
#include "Carnivore.cpp"
#include "Botaniste.h"
#include <string>
#include <vector>
#include <iostream>

// std::vector<Plante*> _plantes;
// int _argent;
// int _engrais;

Botaniste::Botaniste() : _argent(100), _engrais(1)
{
    Plante *plante = new Plante("Plant de radis", 60);
    _plantes.push_back(plante);
}

std::vector<Plante *> Botaniste::getPlantes()
{
    return _plantes;
}

int Botaniste::getArgent()
{
    return _argent;
}
int Botaniste::getEngrais()
{
    return _engrais;
}

void Botaniste::utiliseEngrais(Plante * plante){
    if (_engrais > 0){
        _engrais --;
        plante->donnerEngrais();
    }
    else{
        std::cout << "Vous n'avez pas d'engrais" << std::endl;
    }

}
void Botaniste::dormir()
{
    for (int i = 0; i < _plantes.size(); i++)
    {
        _plantes[i]->nouveauJour();
    }
}

void Botaniste::afficheRessources()
{
    std::cout << "Argent : " << _argent << std::endl;
    std::cout << "Engrais : " << _engrais << std::endl;
    for (int i = 0; i < _plantes.size(); i++)
    {
        if (!(_plantes[i]->getMort()))
        {
            std::cout << i << " - " << _plantes[i]->getName() << std::endl;
        }
    }
}
void Botaniste::achatPlante(std::string name, int prix, std::string type)
{
    if (_argent >= 50)
    {
        std::cout << "Vous achetez une pousse de " << name << std::endl;
        if (type == "plante")
        {
            Plante *plante = new Plante(name, prix);
            _plantes.push_back(plante);
        }
        else if (type == "fleur")
        {
            Fleur *plante = new Fleur(name, prix);
            _plantes.push_back(plante);
        }
        else
        {
            Carnivore *plante = new Carnivore(name, prix);
            _plantes.push_back(plante);
        }
        _argent -= 50;
    }
    else
    {
        std::cout << "Vous n'avez pas assez d'argent pour acheter une nouvelle pousse" << std::endl;
    }
}

void Botaniste::ventePlante(Plante *plante)
{
    if (plante->getMaturite())
    {
        std::cout << "Vous vendez cette plante" << std::endl;
        plante->vendue();
        _argent += plante->getPrix();
    }
    else
    {
        std::cout << "Cette plante n'est pas assez mature pour être vendue" << std::endl;
    }
}

void Botaniste::achatEngrais()
{
    if (_argent >= 20)
    {
        std::cout << "Vous achetez un engrais" << std::endl;
        _engrais++;
        _argent -= 20;
    }
    else
    {
        std::cout << "Vous n'avez pas assez d'argent pour acheter un engrais" << std::endl;
    }
}

#endif