#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
 
using namespace std;

 
int main(){
    char motCle[15];       // mot clé pour le chiffrement
    cout << "Entrez une chaine de caractères de maximum 15 caractères (il servira de clé pour le déchiffrement) : ";
    cin >> motCle;
    srand(time(NULL));
    int dec = 6;
    
    cout << dec << endl;
        ifstream fichier("non-crypter.txt", ios::in);  // on ouvre en le fichier non crypter en lecture seule
        ofstream crypter("crypter.txt", ios::out);  // on ouvre en le fichier en lecture seule
        if(fichier){  // si l'ouverture a réussi 

            // instructions
            string ligne;  // variable contenant chaque ligne lue
            while(getline(fichier, ligne)){  // tant que l'on peut mettre la ligne dans "contenu"
                cout << ligne << endl;  // on affiche la ligne
                for(int i = 0; i < ligne.size(); i++){
                    if(ligne[i] != ' ' && ligne[i] != ',' && ligne[i] != '.' && ligne[i] != '!' && ligne[i] != '?' && ligne[i] != ';' && ligne[i] != ':' 
                    && ligne[i] != '\'' && ligne[i] != '"' && ligne[i] != '(' && ligne[i] != ')' && ligne[i] != '[' && ligne[i] != ']' && ligne[i] != '{' 
                    && ligne[i] != '}' && ligne[i] != '-' && ligne[i] != '_' && ligne[i] != '+' && ligne[i] != '*' && ligne[i] != '/' && ligne[i] != '\\' 
                    && ligne[i] != '|' && ligne[i] != '&' && ligne[i] != '^' && ligne[i] != '%' && ligne[i] != '$' && ligne[i] != '#' && ligne[i] != '@' 
                    && ligne[i] != '!' && ligne[i] != '~' && ligne[i] != '`'){
                        if(ligne[i] + dec > 122){
                            ligne[i] = ligne[i] + dec - 26;
                        }
                        else
                        ligne[i] = ligne[i] + dec;
                    }
                }
                cout << ligne << endl;
                crypter << ligne << endl;
            }
                  // on affiche le contenu du fichier
                fichier.close();  // on ferme le fichier
        }
        else  // sinon
                cout << "Impossible d'ouvrir le fichier !" << endl;
 
        return 0;
}