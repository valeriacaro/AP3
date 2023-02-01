#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n; // nº molins dels que disposo
double d; // demanda
vector<double> autonomia; // guarda les hores que cada moli pot estar en funcionament
vector<double> productivitat; // guarda els kg/h que cada moli pot fer
vector<double> consum; // guarda els kw/h que cada moli consumeix

// guardara el rati de productivitat/consum i el num del moli
using Moli = pair<double, int>;

// retorna el vector de ratis ordenat de gran a petit, per tal de maximitzar
// la relacio productivitat/consum
bool comparator(const Moli& a, const Moli& b)
{
    return a.first > b.first;
}

// retorna el consum minim donada la demanda d
double consum_minim(const vector<Moli>& ratio)
{
    // inicialitzem a 0 el consum minim
    double consum_minim = 0;
    // per cada moli en ordre dels reus ratis, i mentre no haguem assolit la demanda,
    for (int i = 0; i < n and d > 0; ++i) {
        int moli = ratio[i].second;
        // agafem el moli i-èssim i mirem si amb la seva maxima autonomia assolim
        // d al complert o parcialment
        if (d - productivitat[moli] * autonomia[moli] >= 0) {
            // afegim al consum minim el consum del moli i-èssim donades les h q esta en funcionament
            consum_minim += consum[moli] * autonomia[moli];
            // calculem que ens queda per assolir la demanda
            d -= productivitat[moli] * autonomia[moli];
        } else {
            // si no, mirem quantes hores necessitem el moli en funcionament per arribar a la demanda
            double hores_necessaries = d / productivitat[moli];
            // afegim al consum_minim el consum del moli i-èssim donades les h q necessitem q funcioni
            consum_minim += consum[moli] * hores_necessaries;
            // ja hem assolit la demanda
            d = 0;
        }
    }
    return consum_minim;
}

int main()
{
    // configurem la sortida a 4 decimals
    cout.setf(ios::fixed);
    cout.precision(4);
    // mentres rebem casos,
    while (cin >> n) {
        autonomia = vector<double>(n);
        productivitat = vector<double>(n);
        consum = vector<double>(n);
        // llegim l'autonomia dels n molins,
        for (double& hores : autonomia)
            cin >> hores;
        // llegim la productivitat dels n molins,
        for (double& kilos : productivitat)
            cin >> kilos;
        // llegim el consum dels n molins
        for (double& kw : consum)
            cin >> kw;
        // i llegim la demanda.
        cin >> d;
        // Creem un vector que ens permeti guardar el radi de productivitat/consum dels molins
        vector<Moli> ratio;
        // Per cada moli,
        for (int i = 0; i < n; ++i) {
            Moli moli;
            // guardem el rati de productivitat/consum del moli i-èssim
            moli.first = productivitat[i] / consum[i];
            // i li assignem un nombre de moli
            moli.second = i;
            ratio.push_back(moli);
        }
        // ordenem el vector de ratis de gran a petit
        sort(ratio.begin(), ratio.end(), comparator);
        // calculem el consum minim
        cout << consum_minim(ratio) << endl;
    }
}
