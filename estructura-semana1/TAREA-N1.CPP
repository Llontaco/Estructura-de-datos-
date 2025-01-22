#include <iostream>
using namespace std;

int gVect[100]; // Buffer para guardar los elementos
int gnCount = 0; // Contador para saber la cantidad de elementos usados

void Insertar(int elem)
{
    if (gnCount < 100) // solo podemos insertar si hay espacio
        gVect[gnCount++] = elem; // Insertar el elemento al final
}

void Mostrar()
{
    cout << "Elementos en el arreglo: ";
    for (int i = 0; i < gnCount; i++)
    {
        cout << gVect[i] << " ";
    }
    cout << endl;
    cout << "Cantidad de elementos almacenados: " << gnCount << endl;
}

int Buscar(int elem)
{
    for (int i = 0; i < gnCount; i++)
    {
        if (gVect[i] == elem)
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
            gVect[i] = gVect[i + 1]; // Desplazar elementos a la izquierda
        }
        gnCount--; // Disminuir la cantidad de elementos
    }
}

int main(int argc, char *argv[])
{
    Insertar(10);  // Insertar elemento 10
    Insertar(20);  // Insertar elemento 20
    Insertar(30);  // Insertar elemento 30

    Mostrar();  // Mostrar los elementos en el arreglo

    Eliminar(20); // Eliminar elemento 20

    Mostrar();  // Mostrar los elementos en el arreglo después de la eliminación

    return 0;
}