# Cryptage

Qui commandera la garde d’honneur M de Rênal vit tout de suite combien 
il importait dans l’intérêt des maisons sujettes à reculer que M de Moirod 
eût ce commandement. Cela pouvait faire titre pour la place de premier adjoint. 
Il n’y avait rien à dire à la dévotion de M.


regler le probleme avec les ('), pour le cryptage te décryptage.
Faire la partie avec le fichier Json pour garder en memoire le decalage lors du cryptage 
regler probleme majuscule

if(ligne[i] - dec < 65 && ligne[i] >= 65 && ligne[i] > 90){
                            ligne[i] = ligne[i] - dec + 26;
                        }
                        if(ligne[i] - dec < 97 && ligne[i] >90 ){
                            ligne[i] = ligne[i] - dec + 26;
                        }
                        else
                             ligne[i] = ligne[i] - dec;

    char motCle[15];       // mot clé pour le chiffrement
    cout << "Entrez une chaine de caractères de maximum 15 caractères (il servira de clé pour le déchiffrement) : ";
    cin >> motCle;
    srand(time(NULL));
    int dec = 6;
    cout << dec << endl;