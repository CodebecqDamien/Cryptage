#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
        ifstream fichier("test1.txt", ios::in);  // on ouvre en le fichier en lecture seule
 
        if(fichier)  // si l'ouverture a réussi
        {       
            // instructions
            string ligne;  // variable contenant chaque ligne lue
            while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
            {
                cout << ligne << endl;  // on affiche la ligne
            }
                fichier.close();  // on ferme le fichier
        }
        else  // sinon
                cout << "Impossible d'ouvrir le fichier !" << endl;
 
        return 0;
}