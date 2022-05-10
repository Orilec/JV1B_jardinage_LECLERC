#ifndef PLANTE_H
#define PLANTE_H
#include <string>



class Plante{

    protected:

        std::string _name ;
        int _joursDepuisTaille;
        int _joursDepuisArrosage;
        bool _engrais;
        int _maturite;
        int _croissance;
        int _prixDeVente;
        bool _mort;
        bool _isMature;
        std::string _type;





    public:
        Plante();
        Plante(std::string name, int prix);
        std::string getName();
        std::string getType();
        bool getTaille();
        bool getArrosage();
        bool getEngrais();
        int getMaturite();
        int getCroissance();
        int getPrix();
        bool getMort();
        void tailler();
        void arroser();
        void donnerEngrais();
        void inspecter();
        void nouveauJour();
        void vendue();
 





};
#endif