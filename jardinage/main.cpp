#include "Plante.cpp"
#include "Botaniste.cpp"
#include <iostream>
using namespace std;

int main()
{
    Botaniste *joueur = new Botaniste();
    bool gameover = false;
    bool tourSuivant = false;
    int choix;
    int choix2;
    int choix3;
    Plante *planteChoisie;

    while (!gameover)
    {
        tourSuivant = false;
        cout << "Le jour se lève. " << endl;
        while (!tourSuivant)
        {
            joueur->afficheRessources();
            cout << "Que voulez-vous faire ? 1- Acheter une plante (50$) 2- Acheter un engrais(20$) 3- S'occuper de vos plantes 4- Vendre une plante 5- Aller dormir " << endl;
            cin >> choix;
            if (choix == 1)
            {
                cout << "Quelle plante voulez-vous acheter? 1- Romarin 2- Coquelicot 3- Droséras" << endl;
                cin >> choix2;
                if (choix2 == 1)
                {
                    joueur->achatPlante("Romarin", 70, "plante");
                }
                else if (choix2 == 2)
                {
                    joueur->achatPlante("Coquelicot", 60, "fleur");
                }
                else
                {
                    joueur->achatPlante("Droséras", 90, "carnivore");
                }
            }
            else if (choix == 2)
            {
                joueur->achatEngrais();
            }
            else if (choix == 3)
            {
                joueur->afficheRessources();
                cout << "Entrez le numéro de la plante dont vous voulez-vous occuper: " << endl;
                cin >> choix2;
                planteChoisie = joueur->getPlantes()[choix2];
                cout << "Que voulez-vous faire: 1- Arroser 2- Tailler 3- Donner de l'engrais 4- Inspecter" << endl;
                if (planteChoisie->getType() == "carnivore")
                {
                    cout << "5- Nourrir" << endl;
                }
                cin >> choix3;
                if (choix3 == 1)
                {
                    planteChoisie->arroser();
                }
                else if (choix3 == 2)
                {
                    planteChoisie->tailler();
                }
                else if (choix3 == 3)
                {
                    joueur->utiliseEngrais(planteChoisie);
                }
                else if (choix3 == 5)
                {
                    planteChoisie->nourrir();
                }
                else
                {
                    planteChoisie->inspecter();
                }
            }
            else if (choix == 4)
            {
                joueur->afficheRessources();
                cout << "Entrez le numéro de la plante que vous voulez vendre: " << endl;
                cin >> choix2;
                joueur->ventePlante(joueur->getPlantes()[choix2]);
            }
            else
            {
                cout << "Vous allez dormir. " << endl;
                tourSuivant = true;
                joueur->dormir();
            }
        }
    }
}