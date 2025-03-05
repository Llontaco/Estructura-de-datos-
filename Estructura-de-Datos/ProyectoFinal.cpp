#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Representa distancia infinita

// Estructura para representar el mapa con su matriz de adyacencia
struct Mapa {
    int numPuntos;
    vector<vector<int>> distancias;

    Mapa(int n) {
        numPuntos = n;
        distancias.resize(n, vector<int>(n, INF));

        // Distancia de un punto a sí mismo es 0
        for (int i = 0; i < n; i++) {
            distancias[i][i] = 0;
        }
    }

    void agregarConexion(int origen, int destino, int distancia) {
        if (origen >= 0 && origen < numPuntos && destino >= 0 && destino < numPuntos && distancia >= 0) {
            distancias[origen][destino] = distancia;
            distancias[destino][origen] = distancia; // Si el grafo es no dirigido
        } else {
            cout << "Error: conexión inválida.\n";
        }
    }

    void mostrarMapa() {
        cout << "\nMatriz de distancias:\n";
        for (int i = 0; i < numPuntos; i++) {
            for (int j = 0; j < numPuntos; j++) {
                if (distancias[i][j] == INF)
                    cout << "NC\t"; // No conectado
                else
                    cout << distancias[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, conexiones;
    cout << "Ingrese la cantidad de puntos en el mapa: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: La cantidad de puntos debe ser mayor a 0.\n";
        return 1;
    }

    Mapa mapa(n);

    cout << "Ingrese la cantidad de conexiones: ";
    cin >> conexiones;

    if (conexiones < 0) {
        cout << "Error: La cantidad de conexiones no puede ser negativa.\n";
        return 1;
    }

    cout << "Ingrese las conexiones en formato: origen destino distancia\n";
    for (int i = 0; i < conexiones; i++) {
        int origen, destino, distancia;
        cin >> origen >> destino >> distancia;
        mapa.agregarConexion(origen, destino, distancia);
    }

    // Mostrar la matriz de adyacencia
    mapa.mostrarMapa();

    return 0;
}
