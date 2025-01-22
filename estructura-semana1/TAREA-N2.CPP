#include <iostream>
using namespace std;

int *gpVect = NULL; // Buffer dinámico para guardar los elementos
int gnCount = 0; // Contador para saber la cantidad de elementos usados
int gnMax = 0; // Variable que contiene el tamaño de la memoria asignada

void Resize();

void Insertar(int elem)
{
    if (gnCount == gnMax) // No hay espacio en este momento para elem
        Resize(); // Redimensionar el vector antes de insertar elem
    gpVect[gnCount++] = elem; // Insertar el elemento al final de la secuencia
}

void Resize()
{
    const int delta = 5; // Usado para aumentar el tamaño del vector
    int *pTemp, i;
    pTemp = new int[gnMax + delta]; // Asignar un nuevo vector
    for (i = 0; i < gnMax; i++) // Transferir los elementos
        pTemp[i] = gpVect[i]; // también podemos usar la función memcpy
    delete[] gpVect; // eliminar el vector antiguo
    gpVect = pTemp; // Actualizar el puntero
    gnMax += delta; // El Max tiene que ser incrementado por delta
}

void Mostrar()
{
    cout << "Elementos en el arreglo: ";
    for (int i = 0; i < gnCount; i++)
    {
        cout << gpVect[i] << " ";
    }
    cout << endl;
    cout << "Cantidad de elementos almacenados: " << gnCount << endl;
}

int Buscar(int elem)
{
    for (int i = 0; i < gnCount; i++)
    {
        if (gpVect[i] == elem)
            return i; // Devolver el índice del elemento
    }
    return -1; // Elemento no encontrado
}

void Eliminar(int elem)
{
    int index = Buscar(elem);
    if (index != -1) // Elemento encontrado
    {
        for (int i = index; i < gnCount - 1; i++)
        {
            gpVect[i] = gpVect[i + 1]; // Desplazar elementos a la izquierda
        }
        gnCount--; // Disminuir la cantidad de elementos
    }
}

int main(int argc, char *argv[])
{
    Insertar(10);  // Insertar elemento 10
    Insertar(20);  // Insertar elemento 20
    Insertar(30);  // Insertar elemento 30
    Insertar(40);  // Insertar elemento 40
    Insertar(50);  // Insertar elemento 50

    Mostrar();  // Mostrar los elementos en el arreglo

    Insertar(60);  // Insertar elemento 60

    Mostrar();  // Mostrar los elementos en el arreglo

    Eliminar(20); // Eliminar elemento 20

    Mostrar();  // Mostrar los elementos en el arreglo después de la eliminación

    return 0;
}