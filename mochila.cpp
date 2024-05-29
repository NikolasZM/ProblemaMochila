#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mochila(const vector<int>& pesos, const vector<int>& beneficio, int maxWeight, vector<int>& sol) {
    int n = pesos.size();
    vector<double> proporcion(n);
    vector<int> indices(n);

    for (int i = 0; i < n; i++) {
        proporcion[i] = (double)beneficio[i] / pesos[i];
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&proporcion](int a, int b) {
        return proporcion[a] > proporcion[b];
        });

    int currentWeight = 0;
    sol.resize(n, 0);

    for (int i = 0; i < n; i++) {
        int idx = indices[i];
        if (currentWeight + pesos[idx] <= maxWeight) {
            sol[idx] = 1; 
            currentWeight += pesos[idx];
        }
    }
}

int main() {
    vector<int> pesos = { 3, 6, 2, 12 };
    vector<int> beneficio = { 12, 14, 9, 11 };
    int maxP = 20;
    vector<int> solucion;

    mochila(pesos, beneficio, maxP, solucion);

    cout << "Items seleccionados (1 significa que el objeto está en la mochila, 0 significa que no está): ";
    for (int i = 0; i < solucion.size(); i++) {
        cout << solucion[i] << " ";
    }
    cout << endl;

    return 0;
}
