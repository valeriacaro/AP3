#include <iostream>
#include <vector>
using namespace std;
typedef long long int lint;

int main()
{
	int n, m;
	while(cin >> n >> m){
		vector<lint> c (n, 0);
		c[0] = m; // sense parentesis tindrem tantes expressions com lletres

		for(int i = 0; i < n; ++i){
			if((i+1)%2 == 0) c[i] = 0; // amb una longitud parell no podem fer expressions, ja que ens cal posar les variables
			else{
				for(int n1 = 0; n1 < i -5; n1 += 2){ // recursivitat catalan numbers
					int n2 = i - n1 -6;
					c[i] += c[n1]*c[n2];
				}

				if(i > 0) c[i] += c[i -2];
			}
		}

		cout << c[n-1] << endl;
	}
}
