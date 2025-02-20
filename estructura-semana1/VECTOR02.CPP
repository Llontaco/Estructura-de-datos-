#include <iostream>
using namespace std;

int *gpVect = NULL; 
int gnCount = 0; 
int gnMax = 0; 

void Resize();

void Insertar(int elem)
{
    if (gnCount == gnMax) 
        Resize(); 
    gpVect[gnCount++] = elem; 
}

void Resize()
{
    const int delta = 5; 
    int *pTemp, i;
    pTemp = new int[gnMax + delta]; // Asignar un nuevo vector
    for (i = 0; i < gnMax; i++) 
        pTemp[i] = gpVect[i]; 
    delete[] gpVect; 
    gpVect = pTemp; 
    gnMax += delta; 
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
            return i; 
    }
    return -1; 
}

void Eliminar(int elem)
{
    int index = Buscar(elem);
    if (index != -1)
    {
        for (int i = index; i < gnCount - 1; i++)
        {
            gpVect[i] = gpVect[i + 1]; 
        gnCount--; 
    }
}

int main(int argc, char *argv[])
{
    Insertar(10);  
    Insertar(20);  
    Insertar(30);  
    Insertar(40); 
    Insertar(50);  

    Mostrar();  

    Insertar(60);  
    Mostrar();  

    Eliminar(20); 

    Mostrar();  // Mostrar los elementos en el arreglo después de la eliminación

    return 0;
}