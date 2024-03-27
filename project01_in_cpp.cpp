#include <iostream>
#include <vector>
using namespace std;
int nombreRegle;
struct Regle{
    string G,D;
};

vector<struct Regle> grammaire;

bool checkString(const std::string& str) {
    if (str.length() >= 2) { 
        return false;
    }
    for (char c : str) { 
        if (std::isupper(c)) { 
            return false;
        }
    }
    return true;
}

void creationGammaire(int num_regles) {
    Regle new_regle;
    string G, D;

    for (int i = 0; i < num_regles; i++) {
        cout << "G :" << i + 1 << ": ";
        cin >> G;
        new_regle.G = G;
        cout << "D :" << i + 1 << ": ";
        cin >> D;
        new_regle.D = D;
        grammaire.push_back(new_regle);
    }
};

void affichage() {
    cout << "\nRegle :";
    for (int i = 0; i < grammaire.size(); i++) {
        cout<<"\n" << i + 1 << "\n:" << grammaire[i].G << " -> " << grammaire[i].D;
    }
}

bool type3(vector<struct Regle> grammaire){
    for (int i = 0; i < grammaire.size(); i++){
        if ((grammaire[i].G.length() > 1 || grammaire[i].G.length() == 0) && islower(grammaire[i].G[0])) {
            return false;
        }
    }
    return true;
}

bool regulierGauche(struct Regle regle){
    if (regle.G.length() > 1){
        for (int i = 1; i < regle.G.length(); i++){
            if (isupper(regle.G[i])) {
                return false;
            }
        }
    }
    return true;
}

bool regulierDroite(struct Regle regle){
    if (regle.D.length() > 1){
        for (int i = 1; i < regle.D.length(); i++){
            if (isupper(regle.D[i])) {
                return false;
            }
        }
    }
    return true;
}

string getGrammarType(vector<struct Regle> grammaire) {
    bool isType3 = true;
    bool isRightLinear = true;

    for (int i = 0; i < grammaire.size(); i++) {
        string G = grammaire[i].G;
        string D = grammaire[i].D;
        if (G.length() != 1 || !islower(G[0])) {
            isType3 = false;
        }
        if (D.length() == 1 && !islower(D[0])) {
            continue;
        }
        if (D.length() == 2 && islower(D[0]) && isupper(D[1])) {
            continue;
        }
        isType3 = false;
        if (!regulierDroite(grammaire[i])) {
            isRightLinear = false;
        }
    }
    if (isType3 && isRightLinear) {
        return "Type 3 (Regular right-linear)";
    }
    if (isType3) {
        return "Type 3 (Regular)";
    }
    if (isRightLinear) {
        return "Type 2 (Context-free right-linear)";
    }
    return "Type 0 (Unrestricted)";
}



void menu(){
cout<<"\nGESTION DUN GRAMMAIRE\n\n";
cout<<"\n 1: Creation";
cout<<"\n 2: Afficher";
cout<<"\n 3: Verifier si type 3";
cout<<"\n 4: Le type";
cout<<"\n 5: Quitter";
}

int main(){
     int choix=1;
   while(choix!=0){
     menu();
     cout<<"\ndonner votre choix: ";
    cin>>choix;
    switch(choix){
        case 0:
            exit(1);
            break;
        case 1:
            cout<<"nbr des regles:\n";
            cin >> nombreRegle;
            creationGammaire(nombreRegle);
            break;
        case 2:
            affichage();
            break;
        case 3:
            cout<<" Grammaire :";
            if(type3(grammaire))
            cout<<"\noui grammaire de type 3";
            else
            cout<<"\nnon grammire ne pas de type 3";
            break;
        case 4:
            cout<<"\ntype de Grammaire:"<<getGrammarType( grammaire);
            break;
     }
   }
    return 0;
}

