#ifndef FLEUR_CPP
#define FLEUR_CPP
#include "Plante.cpp"
#include "Fleur.h"
#include <string>

// bool _isEclot;
// bool _isFanee;

Fleur::Fleur(std::string name, int prix) : Plante()
{
    _name = name;
    _type = "fleur";
    _prixDeVente = prix;
    _isEclot = false;
    _isFanee = false;
}

void Fleur::nouveauJour()
{

    if (_croissance >= 2)
    {
        _maturite++;
    }
    else if (_croissance <= 0)
    {
        _mort = true;
    }
    if (_joursDepuisTaille > 5)
    {
        _croissance--;
    }
    if (_joursDepuisArrosage > 4)
    {
        _croissance--;
    }
    if (_maturite == 7)
    {
        _isMature = true;
        _isEclot = true;
    }
    if (_maturite > 9)
    {
        _isEclot = false;
        _isFanee = true;
    }
    if (_isEclot)
    {
        _prixDeVente = _prixDeVente * 2;
    }
    if (_isFanee)
    {
        _prixDeVente = _prixDeVente / 10;
    }

    _joursDepuisArrosage++;
    _joursDepuisTaille++;
    _engrais = false;
}

void Fleur::inspecter()
{
    std::cout << _name << std::endl;
    if (_joursDepuisTaille > 4)
    {
        std::cout << "Doit être taillée" << std::endl;
    }
    else
    {
        std::cout << "Est taillée" << std::endl;
    }
    if (_joursDepuisArrosage > 3)
    {
        std::cout << "Doit être arrosée" << std::endl;
    }
    else
    {
        std::cout << "Est arrosée" << std::endl;
    }
    if (_croissance >= 2)
    {
        std::cout << "Est en bonne santé" << std::endl;
    }
    else if (_croissance == 1)
    {
        std::cout << "Est en moyenne santé" << std::endl;
    }
    else
    {
        std::cout << "Est en très mauvaise santé" << std::endl;
    }
    if (_isEclot)
    {
        std::cout << "Cette fleur a éclot !" << std::endl;
    }
    else if (_isFanee)
    {
        std::cout << "Cette fleur a fané !" << std::endl;
    }
}

#endif