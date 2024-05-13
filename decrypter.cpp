#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
 
using namespace std;

int cle(){
    char motCle[15];       // mot clé pour le chiffrement
    cout << "Entrez votre mot clé pour le dechiffrement : ";
    cin >> motCle;
    int dec = 6;
    return dec;
}

void decrypter(){
    int dec = cle();
    ifstream fichier("crypter.txt", ios::in);  // on ouvre en le fichier non crypter en lecture seule
        ofstream crypter("non-crypter.txt", ios::out);  // on ouvre en le fichier en lecture seule
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
                        if(ligne[i] - dec < 65 && ligne[i] >= 65 && ligne[i] > 90){
                            ligne[i] = ligne[i] - dec + 26;
                        }
                        if(ligne[i] - dec < 97 && ligne[i] >90 ){
                            ligne[i] = ligne[i] - dec + 26;
                        }
                        else
                             ligne[i] = ligne[i] - dec;
                    }
                }
                cout << ligne << endl;
                crypter << ligne << endl;
            }
                fichier.close();  // on ferme le fichier
        }
        else  // sinon
        cout << "Impossible d'ouvrir le fichier !" << endl;
}

int main(){
    decrypter();
    return 0;
}