#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;
 
// fonction pour demander la clé de chiffrement
// ecriture de la clé dans le fichier data.json
// et retourner le décalage
int cle(){
    char motCle[15];       // mot clé pour le chiffrement
    std::cout << "Entrez une chaine de caractères de maximum 15 caractères (il servira de clé pour le déchiffrement) : ";
    cin >> motCle;
    srand(time(NULL));  // initialiser le générateur de nombre aléatoire
    int dec = rand() %6 + 1;  // générer un nombre aléatoire entre 1 et 6
    ifstream dataFileRead("data.json", ios::in);  
    ofstream dataFileWrite("data.json", ios::out);  
    if(dataFileRead && dataFileWrite){
        string line;
        bool found = false;
        while (getline(dataFileRead, line)) {
            if (line.find(motCle) != string::npos) {
                found = true;
                break;
            }else{
                
            }
        }
        if(found == true){
            std::cout << "Le mot clé existe déjà !" << endl;
            exit(0);
        }
        else{
            dataFileWrite << "{\n" << "    \"cle\": \"" << motCle << "\",\n";  
            dataFileWrite << "    \"dec\": " << dec << "\n}";  
            std::cout << "Le mot clé a été ajouté !" << endl;
        }
        dataFileRead.close(); 
        dataFileWrite.close();
    }
    else{
        std::cout << "Impossible d'ouvrir le fichier data.json !" << endl;
    }
    return dec;
}
    

// fonction pour crypter le fichier 
void crypter(){
    int dec = cle();
    std::cout << "dec: " << dec << endl; 
    ifstream fichier("non-crypter.txt", ios::in);  // on ouvre en le fichier non crypter en lecture seule
    ofstream crypter("crypter.txt", ios::out);  // on ouvre en le fichier en lecture seule
    if(fichier){  // si l'ouverture a réussi 

        string ligne;  // variable contenant chaque ligne lue
        while(getline(fichier, ligne)){  // tant que l'on peut mettre la ligne dans "contenu"
            std::cout << ligne << endl;  // on affiche la ligne
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
            std::cout << ligne << endl;
            crypter << ligne << endl;
        }
              // on affiche le contenu du fichier
            fichier.close();  // on ferme le fichier
    }
    else  // sinon
            std::cout << "Impossible d'ouvrir le fichier !" << endl;
}


// fonction principale
int main(){
    crypter();
    return 0;
}