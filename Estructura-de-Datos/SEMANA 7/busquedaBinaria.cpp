#include <iostream>
using namespace std;

// Definición de la clase CVector
class CVector {
private:
    int* m_pVect; // Puntero al arreglo
    int m_nCount; // Número de elementos en uso
    int m_nMax;   // Capacidad máxima del arreglo
    int m_nDelta; // Incremento para redimensionar

    // Función para inicializar las variables
    void Init(int delta) {
        m_nCount = 0;
        m_nMax = delta;
        m_nDelta = delta;
        m_pVect = new int[m_nMax]; // Crear el arreglo dinámico
    }

    // Función para redimensionar el arreglo si se sobrepasa la capacidad
    void Resize() {
        m_nMax += m_nDelta; 
        int* temp = new int[m_nMax]; 
        for (int i = 0; i < m_nCount; i++) {
            temp[i] = m_pVect[i]; 
        }
        delete[] m_pVect; 
        m_pVect = temp; 
    }

public:
    // Constructor
    CVector(int delta = 10) {
        Init(delta);
    }

    // Método para insertar un elemento al final del vector
    void Insert(int elem) {
        if (m_nCount == m_nMax) { // Verificar si se ha alcanzado la capacidad máxima
            Resize(); // Redimensionar el vector
        }
        m_pVect[m_nCount++] = elem; // Insertar el elemento y aumentar el contador
    }

    // Método para mostrar los elementos del vector
    void Display() {
        for (int i = 0; i < m_nCount; i++) {
            cout << m_pVect[i] << " ";
        }
        cout << endl;
    }

    // Función de búsqueda binaria iterativa
    int BinarySearchIterative(int target) {
        int left = 0;
        int right = m_nCount - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Si el elemento se encuentra en el medio
            if (m_pVect[mid] == target) {
                return mid; // Elemento encontrado
            }

            // Si el elemento es menor, ignorar la mitad derecha
            if (m_pVect[mid] > target) {
                right = mid - 1;
            }
            // Si el elemento es mayor, ignorar la mitad izquierda
            else {
                left = mid + 1;
            }
        }

        return -1; // Elemento no encontrado
    }

    // Getter para obtener la cantidad de elementos en el vector
    int GetCount() const {
        return m_nCount;
    }

    // Destructor para liberar la memoria
    ~CVector() {
        delete[] m_pVect;
    }
};

// Función principal
int main() {
    CVector gVect; // Crear un objeto CVector

    // Insertar algunos elementos en el vector
    gVect.Insert(5);
    gVect.Insert(10);
    gVect.Insert(15);
    gVect.Insert(20);
    gVect.Insert(30);
    gVect.Insert(50);

    cout << "Elementos en el vector: ";
    gVect.Display(); // Mostrar los elementos antes de la búsqueda

    // Buscar un elemento (ejemplo: 30) usando la búsqueda binaria iterativa
    int target = 30;
    int result = gVect.BinarySearchIterative(target);

    // Verificar si el elemento fue encontrado
    if (result != -1) {
        cout << "Elemento " << target << " encontrado en la posición: " << result << " (Búsqueda Iterativa)" << endl;
    } else {
        cout << "Elemento " << target << " no encontrado. (Búsqueda Iterativa)" << endl;
    }

    return 0;
}