#include <iostream>
using namespace std;

// Clase CVector para manejar un vector din�mico
class CVector {
private:
    int* m_pVect;      // Puntero al buffer
    int m_nCount;      // N�mero de elementos actuales en uso
    int m_nMax;        // Capacidad m�xima del vector
    int m_nDelta;      // Incremento para redimensionar el vector

    void Init(int delta) {
        m_pVect = NULL; // Inicializamos el puntero a nullptr
        m_nCount = 0;
        m_nMax = 0;
        m_nDelta = delta;  // Establece el delta para controlar el crecimiento
    }

    void Resize() {
        // Incrementar el tama�o del buffer
        m_nMax += m_nDelta;
        int* newBuffer = new int[m_nMax];

        // Copiar los elementos existentes al nuevo buffer
        for (int i = 0; i < m_nCount; i++) {
            newBuffer[i] = m_pVect[i];
        }

        // Liberar el buffer antiguo y reasignar
        delete[] m_pVect;
        m_pVect = newBuffer;
    }

public:
    CVector(int delta = 10) {
        Init(delta); // Llama a la funci�n Init para inicializar las variables
    }

    ~CVector() {
        delete[] m_pVect; // Libera la memoria asignada
    }

    void Insert(int elem) {
        // Verificar si se necesita redimensionar
        if (m_nCount == m_nMax) {
            Resize();
        }

        // Insertar el elemento al final
        m_pVect[m_nCount++] = elem;
    }

    void Print() const {
        // Imprime los elementos del vector
        cout << "Elementos en el vector: ";
        for (int i = 0; i < m_nCount; i++) {
            cout << m_pVect[i] << " ";
        }
        cout << endl;
        cout << "Cantidad de elementos almacenados: " << m_nCount << endl;
    }
};

// Funci�n principal
int main(int argc, char* argv[]) {
    // Crear el vector din�mico gVect
    CVector gVect;

    // Insertar los valores 10, 20 y 30
    cout << "Insertando los valores 10, 20, 30..." << endl;
    gVect.Insert(10);
    gVect.Insert(20);
    gVect.Insert(30);

    // Mostrar los valores del vector
    cout << "Valores en gVect---------------------- " << endl;
    gVect.Print();
    cout << "-------------------------------------- " << endl;

    return 0;
}
