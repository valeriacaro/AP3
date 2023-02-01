/*Feu un programa que, donades n paraules diferents s1, …, sn i un nombre p,
escrigui totes les maneres de repartir les paraules entre p subconjunts.

Entrada

L’entrada consisteix en un natural n > 0, seguit de s1, …, sn, seguit d’un
natural p > 0.

Sortida

Escriviu totes les maneres de repartir les paraules entre p subconjunts. Els
elements dins de cada subconjunt han d’aparèixer en el mateix ordre que a
l’entrada. Escriviu una línia en blanc després de cada partició.

Observació

De fet, una partició no pot tenir subconjunts buits, però en aquest exercici
ignorem aquesta restricció.

Informació sobre el corrector
Podeu escriure les solucions d’aquest exercici en qualsevol ordre.*/

// INCLUDES
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// FUNCIONS
void escriu(const vector<string>& paraules, vector<int>& combinacio, int p)
{
    int n = paraules.size();
    for (int i = 0; i < p; i++) {
        cout << "subconjunt " << i + 1 << ": {";
        bool primer = true;
        //Si la paraula j va al subconjunt i la donem
        for (int j = 0; j < n; j++) {
            if (combinacio[j] == i) {
                if (primer)
                    primer = false;
                else
                    cout << ",";
                cout << paraules[j];
            }
        }
        cout << "}" << endl;
    }
    cout << endl;
}

void genera(const vector<string>& paraules, vector<int>& combinacio, int p, int k)
{
    int n = combinacio.size();
    // Cas base: combinacio acabada
    if (k == n) {
        escriu(paraules, combinacio, p);
    } else {
        for (int i = 0; i < p; i++) {
            combinacio[k] = i;
            genera(paraules, combinacio, p, k + 1);
        }
    }
}

// COS PRINCIPAL
int main()
{
    int n;
    cin >> n;
    vector<string> paraules(n);
    for (int i = 0; i < n; i++)
        cin >> paraules[i];

    int p;
    cin >> p;
    vector<int> combinacio(n);

    genera(paraules, combinacio, p, 0);
}
