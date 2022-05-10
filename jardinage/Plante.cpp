#ifndef PLANTE_CPP
#define PLANTE_CPP

#include <string>
#include <iostream>
#include "Plante.h"

// std::string _name ;
// bool _isTaillee;
// bool _isArrosee;
// bool _engrais;
// int _maturite;
// int _croissance;

Plante::Plante() : _name("default"), _prixDeVente(50), _joursDepuisTaille(0), _joursDepuisArrosage(0), _engrais(false), _maturite(0), _croissance(2), _mort(false), _isMature(true), _type("plante")
{
}

Plante::Plante(std::string name, int prix) : _name(name), _prixDeVente(prix), _joursDepuisTaille(0), _joursDepuisArrosage(0), _engrais(false), _maturite(0), _croissance(2), _mort(false), _isMature(true), _type("plante")
{
}

std::string Plante::getName()
{
    return _name;
}

std::string Plante::getType()
{
    return _type;
}

bool Plante::getTaille()
{
    return _joursDepuisTaille;
}

bool Plante::getArrosage()
{
    return _joursDepuisArrosage;
}

bool Plante::getEngrais()
{
    return _engrais;
}
bool Plante::getMort()
{
    return _mort;
}
int Plante::getMaturite()
{
    return _isMature;
}
int Plante::getPrix()
{
    return _prixDeVente;
}

int Plante::getCroissance()
{
    return _croissance;
}

void Plante::tailler()
{
    if (_joursDepuisTaille < 5)
    {
        std::cout << " Vous abîmez la plante en la taillant trop !" << std::endl;
        _croissance--;
        _joursDepuisTaille = 0;
    }

    else
    {
        std::cout << " Vous taillez la plante !" << std::endl;
        _joursDepuisTaille = 0;
    }
}

void Plante::arroser()
{
    if (_joursDepuisArrosage < 4)
    {
        std::cout << " Vous noyez la plante en l'arrosant trop !" << std::endl;
        _croissance--;
        _joursDepuisArrosage = 0;
    }

    else
    {
        std::cout << " Vous arrosez la plante !" << std::endl;
        _croissance++;
        _joursDepuisArrosage = 0;
    }
}

void Plante::donnerEngrais()
{
    if (_engrais)
    {
        std::cout << " Vous avez déjà donné de l'engrais a cette plante aujourd'hui !" << std::endl;
    }
    else
    {
        std::cout << " Vous donnez de l'engrais à cette plante" << std::endl;
        _engrais = true;
    }
}

void Plante::inspecter()
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
}

void Plante::nouveauJour()
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
    if (_maturite >= 5)
    {
        _isMature = true;
    }

    _joursDepuisArrosage++;
    _joursDepuisTaille++;
    _engrais = false;
}

void Plante::vendue()
{
    _mort = true;
}

#endif