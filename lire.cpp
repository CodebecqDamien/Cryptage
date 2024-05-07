#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
 
using namespace std;

 
int main(){
    srand(time(NULL));
    int dec = rand()%26  +1;
    cout << dec << endl;
        ifstream fichier("test1.txt", ios::in);  // on ouvre en le fichier en lecture seule
 
        if(fichier){  // si l'ouverture a réussi 

            // instructions
            string ligne;  // variable contenant chaque ligne lue
            while(getline(fichier, ligne)){  // tant que l'on peut mettre la ligne dans "contenu"
                cout << ligne << endl;  // on affiche la ligne
                for(int i = 0; i < ligne.size(); i++){
                    if(ligne[i] != ' ' && ligne[i] != ',' && ligne[i] != '.' && ligne[i] != '!' && ligne[i] != '?' && ligne[i] != ';' && ligne[i] != ':' && ligne[i] != '\'' && ligne[i] != '"' && ligne[i] != '(' && ligne[i] != ')' && ligne[i] != '[' && ligne[i] != ']' && ligne[i] != '{' && ligne[i] != '}' && ligne[i] != '-' && ligne[i] != '_' && ligne[i] != '+' && ligne[i] != '*' && ligne[i] != '/' && ligne[i] != '\\' && ligne[i] != '|' && ligne[i] != '&' && ligne[i] != '^' && ligne[i] != '%' && ligne[i] != '$' && ligne[i] != '#' && ligne[i] != '@' && ligne[i] != '!' && ligne[i] != '~' && ligne[i] != '`' ){
                    ligne[i] = ligne[i] + dec;
                    }
                }
                cout << ligne << endl;
            }
                  // on affiche le contenu du fichier
                fichier.close();  // on ferme le fichier
        }
        else  // sinon
                cout << "Impossible d'ouvrir le fichier !" << endl;
 
        return 0;
}