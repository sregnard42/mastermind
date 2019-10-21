#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <limits>

using namespace std;

#include "winMP1.h"

int main()
{
    const int NBMIN=5;
    const int NBMAX=20;

    bool okUn; // Variable vraie si la couleur propos�e par le joueur pour le pion 1 correspond � celle g�n�r�e al�atoirement.
    bool okDeux; // Variable vraie si la couleur propos�e par le joueur pour le pion 2 correspond � celle g�n�r�e al�atoirement.
    bool okTrois; // Variable vraie si la couleur propos�e par le joueur pour le pion 3 correspond � celle g�n�r�e al�atoirement.
    bool okQuatre; // Variable vraie si la couleur propos�e par le joueur pour le pion 4 correspond � celle g�n�r�e al�atoirement.
    bool courant_valide; // Variable vraie lorsque la s�quence propos�e par le joueur est possible.
    bool un_valide; // Variable vraie lorsque la couleur propos�e par le joueur pour le pion 1 est possible.
    bool deux_valide; // Variable vraie lorsque la couleur propos�e par le joueur pour le pion 2 est possible.
    bool trois_valide; // Variable vraie lorsque la couleur propos�e par le joueur pour le pion 3 est possible.
    bool quatre_valide; // Variable vraie lorsque la couleur propos�e par le joueur pour le pion 4 est possible.

    char choixOrdi[4]; // La s�quence g�n�r�e al�atoirement par le programme est stock�e dans ce tableau.
    char pionUn; // Variable stockant la proposition du joueur pour la couleur du pion 1.
    char pionDeux; // Variable stockant la proposition du joueur pour la couleur du pion 2.
    char pionTrois; // Variable stockant la proposition du joueur pour la couleur du pion 3.
    char pionQuatre; // Variable stockant la proposition du joueur pour la couleur du pion 4.

    int nbEssais; // Variable contenant le nombre d'essais que souhaite avoir le joueur.
    int nbAlea; // Nombre al�atoire g�n�r� par le programme pour ensuite d�terminer les couleurs.
    int pionsOk; // Variable stockant le nombre de pions corrects lorsque le joueur propose une s�quence.
    int i; // Compteur.

    string exit; // Variable prenant l'information pour savoir si le joueur d�sire quitter le jeu ou non.

    //R�gles du jeu.
    cout << "-- MASTERMIND --" << endl << endl;
    cout << "-- REGLES DU JEU --" << endl << endl;
    cout << "- Le jeu genere aleatoirement une sequence que vous devez deviner" << endl << endl;
    cout << "- Une sequence est composee de 4 couleurs aleatoires, avec un total" << endl;
    cout << "de 6 couleurs possibles" << endl << endl;
    cout << "- Les couleurs susceptibles d'etre dans la sequence sont le rouge," << endl;
    cout << "le vert, le jaune, le magenta, le bleu et le cyan : ";
    imp('R');
    imp('V');
    imp('J');
    imp('M');
    imp('B');
    imp('C');
    cout << endl << endl;
    cout << "- Au debut du jeu vous devez egalement dire combien d'essais vous desirez" << endl;
    cout << "pour tenter de deviner la sequence" << endl << endl;
    cout << "- Votre reponse doit etre ecrite sous cette forme : 'C J V M' " << endl;
    cout << "Si vous pensez que la sequence est Cyan Jaune Vert Magenta" << endl << endl;
    cout << "Bonne chance !" << endl << endl;
    cout << endl << "-- FIN DES REGLES --" << endl;

    //Boucle du jeu.
    do
    {
        //Demande du nombre d'essais souhait�.
        do
        {
            cout << endl << "Combien d'essais souhaitez-vous ? (entre " << NBMIN << " et " << NBMAX << ") : ";
            if (!(cin >> nbEssais))
            {
                //G�re l'�ventualit� o� l'utilisateur entre un caract�re � la place d'un nombre, �vitant ainsi une boucle infinie.
                cout << "Erreur, veuillez entrer un nombre entier !" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }while (nbEssais > NBMAX || nbEssais < NBMIN);


        //G�n�ration de la s�quence al�atoire.
        cout << "Generation de la sequence..." << endl;
        srand(time(NULL));
        for (i=0; i <= 3; i++)
        {
            nbAlea = rand()%6 +1;
            //Affectation du chiffre al�atoire � la couleur correspondante.
            switch (nbAlea)
            {
                case (1) : choixOrdi[i]='R'; break;
                case (2) : choixOrdi[i]='V'; break;
                case (3) : choixOrdi[i]='J'; break;
                case (4) : choixOrdi[i]='M'; break;
                case (5) : choixOrdi[i]='B'; break;
                case (6) : choixOrdi[i]='C'; break;
            }
        }

        //Boucle dans laquelle l'utilisateur peut tenter sa chance.
        i = 0;
        while (i < nbEssais && (pionsOk!=4))
        {
            courant_valide=0;
            okUn=0;
            okDeux=0;
            okTrois=0;
            okQuatre=0;

            pionsOk = 0;
            cout << endl << "Quelle est la sequence selon vous ? (essai " << i+1 << '/' << nbEssais << ')' << endl;
            cin >> pionUn >> pionDeux >> pionTrois >> pionQuatre;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Permet d'ignorer les caract�res en trop entr�s par le joueur.

            //Test de chacun des pions propos�s par le joueur, pour savoir s'il propose une couleur possible dans le jeu.
            un_valide=(pionUn=='R' || pionUn=='V' || pionUn=='J' || pionUn=='M' || pionUn=='B' || pionUn=='C');
            deux_valide=(pionDeux=='R' || pionDeux=='V' || pionDeux=='J' || pionDeux=='M' || pionDeux=='B' || pionDeux=='C');
            trois_valide=(pionTrois=='R' ||pionTrois=='V' || pionTrois=='J' || pionTrois=='M' || pionTrois=='B' || pionTrois=='C');
            quatre_valide=(pionQuatre=='R' || pionQuatre=='V' || pionQuatre=='J' || pionQuatre=='M' || pionQuatre=='B' || pionQuatre=='C');
            courant_valide=(un_valide && deux_valide && trois_valide && quatre_valide);

            //Dans le cas o� un des pions propos� ne poss�de pas une couleur connue du jeu.
            if (!courant_valide)
            {
                cout << "L'une des couleurs indiquee n'est pas presente dans le jeu, veuillez reessayer.";
            }

            //Dans le cas o� la s�quence propos�e est au moins th�oriquement possible.
            else
            {
                //Affichage de la s�quence propos�e en couleur.
                imp(pionUn);
                imp(pionDeux);
                imp(pionTrois);
                imp(pionQuatre);

                //V�rification de la concordance entre la s�quence propos�e par le joueur et la s�quence � trouver.
                okUn=(pionUn==choixOrdi[0]);
                okDeux=(pionDeux==choixOrdi[1]);
                okTrois=(pionTrois==choixOrdi[2]);
                okQuatre=(pionQuatre==choixOrdi[3]);

                //Nombre de pions bien choisies, selon l'emplacement et la couleur.
                if(okUn) pionsOk++;
                if(okDeux) pionsOk++;
                if(okTrois) pionsOk++;
                if(okQuatre) pionsOk++;
                cout << endl << pionsOk << " pion(s) correct(s) !" << endl;
                i++;
            }
        }
        cout << endl;

        //R�sultat final.

        //Si le joueur a trouv� la s�quence.
        if (okUn && okDeux && okTrois && okQuatre)
        {
            cout << "Vous avez trouve au bout de " << i << " essai(s) ! Felicitations !";
        }

        //S'il n'a pas trouv� apr�s le nombre d'essais impos�.
        else
        {
            cout << "Vous n'avez pas trouve au bout de " << nbEssais << " essais. Reessayez !";
        }
        cout << endl;

        //Affichage de la s�quence � trouver dans tous les cas.
        cout << "La sequence a trouver etait :" << endl << endl;
        imp(choixOrdi[0]);
        imp(choixOrdi[1]);
        imp(choixOrdi[2]);
        imp(choixOrdi[3]);
        cout << endl << endl;

        //Demande � l'utilisateur s'il souhaite quitter le jeu.
        do
        {
            cout << "Quitter le jeu ? ";
            cin >> exit;
        }while(exit != "oui" && exit != "Oui" && exit != "non" && exit != "Non");

        cout << endl;
    }while (exit != "oui" && exit != "Oui");

    return 0;
}
