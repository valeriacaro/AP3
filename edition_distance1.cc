
#include <iostream>
#include <vector>

using namespace std;

int UNDEF = -1;

int pes(char i, const vector<int> &pesos) { return pesos[i - 'a']; }

// Les paraules comencen a partir de l'index i i j
// Recurrència : si les lletres dels dos índexs coincideixent el cost serà el
// mateix de calcular les paraules sense les dues lletres;
// si les lletres son diferents, el cost serà el mínim d'afegir la lletra de la
// paraula 1 a la 2 o afegir la lletra de la paraula 2 a la 1
int cost_min(int i, int j, const string &p1, const string &p2,
             const vector<int> &pesos, vector<vector<int>> &costos) {
  int n = p1.size();
  int m = p2.size();
  if (i == n and j == m) // cas base, les dues paraules són buides
    return 0;
  if (i == n) // si una paraula és buida el cost és la paraula restant
    return pes(p2[j], pesos) + cost_min(i, j + 1, p1, p2, pesos, costos);
  if (j == m) // si una paraula és buida el cost és la paraula restant
    return pes(p1[i], pesos) + cost_min(i + 1, j, p1, p2, pesos, costos);
  if (costos[i][j] != -1) // si ja sabem el resultat el reaprofitem
    return costos[i][j];
  if (p1[i] == p2[j])
    return costos[i][j] = cost_min(i + 1, j + 1, p1, p2, pesos, costos);
  if (p1[i] != p2[j])
    return costos[i][j] = min(
               pes(p1[i], pesos) + cost_min(i + 1, j, p1, p2, pesos, costos),
               pes(p2[j], pesos) + cost_min(i, j + 1, p1, p2, pesos, costos));
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> pesos(n); // vector amb els pes de cada lletra
    for (int &pes : pesos)
      cin >> pes;
    string p1;
    string p2;
    cin >> p1 >> p2;
    vector<vector<int>> costos(p1.size(), vector<int>(p2.size(), UNDEF));
    cout << cost_min(0, 0, p1, p2, pesos, costos) << endl;
  }
}
