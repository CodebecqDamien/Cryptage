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