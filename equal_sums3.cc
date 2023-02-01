#include <iostream>
#include <vector>
using namespace std;

int n, suma;

void write_subset(vector<bool>& used, vector<int>& v){
	bool first = true;
	cout << "{" ;
	for(int i = 0; i < n; ++i){
		if(used[i]){
			if(first){
			 cout << v[i];
			 first = false;
			} else {
				cout << "," << v[i];
			}
		}
	}
	cout << "}" << endl;
}

//funció que dona recursivament els subconjunts d'un vector d'enters que sumen un nombre determinat.

void genera(vector<int>& nombres, vector<bool>& used, int sumaActual, int indexConjunt, int sumaTotal){

	//cas base
	if (sumaActual > suma) return; //hem excedit la suma requerida, tornem
	if (sumaActual + sumaTotal < suma) return; //no arribarem mai a la suma requerida
	if (indexConjunt== n){ //podem garantir que la suma es exactament s
		write_subset(used, nombres);
	}

	//cas recursiu
	//if(indexConjunt < n) {
		sumaTotal -= nombres[indexConjunt];
		used[indexConjunt] = true;
		genera(nombres, used, sumaActual+nombres[indexConjunt], indexConjunt+1, sumaTotal);
		used[indexConjunt] = false;
		genera(nombres, used, sumaActual, indexConjunt+1, sumaTotal);
//	}
}


int main(){
	cin >> suma >> n;
	vector<int> nombres(n);
	vector<bool> used(n, false);
	int sumaTotal = 0;
	for(int& valor : nombres){
		cin >> valor;
		sumaTotal += valor;
	}
	genera(nombres, used, 0, 0, sumaTotal);
}
