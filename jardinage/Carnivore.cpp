#ifndef CARNIVORE_CPP
#define CARNIVORE_CPP
#include "Plante.cpp"
#include "Carnivore.h"
#include <string>
#include <iostream>


Carnivore::Carnivore(std::string name, int prix) : Plante()
{
    _name = name;
    _type = "carnivore";
    _prixDeVente = prix;
    _joursDepuisNourrie = 0;
}



void Carnivore::nourrir()
{
    if (_joursDepuisNourrie < 7)
    {
        std::cout << " Cette plante est déjà rassasiée !" << std::endl;
        _croissance--;
        _joursDepuisNourrie = 0;
    }

    else
    {
        std::cout << " Vous nourissez la plante !" << std::endl;
        _joursDepuisNourrie = 0;
    }
}

void Carnivore::inspecter()
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
    if (_joursDepuisNourrie > 6)
    {
        std::cout << "Doit être nourrie" << std::endl;
    }
    else
    {
        std::cout << "Est rassasiée" << std::endl;
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
}

void Carnivore::nouveauJour()
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
    if (_joursDepuisNourrie > 8)
    {
        _croissance--;
    }
    if (_joursDepuisArrosage > 4)
    {
        _croissance--;
    }
    if (_maturite >= 5)
    {
        _isMature = true;
    }

    _joursDepuisArrosage++;
    _joursDepuisTaille++;
    _joursDepuisNourrie++;
    _engrais = false;
}

#endif