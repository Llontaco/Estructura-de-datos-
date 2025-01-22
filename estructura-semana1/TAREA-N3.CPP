#include <iostream>
using namespace std;

struct Vector
{
    int*m_pVect, // Puntero al buffer
        m_nCount, // Controla cuántos elementos se están usando realmente
        m_nMax, // Controla cuántos están asignados como máximo
        m_nDelta; // Para controlar el crecimiento
};

void Resize(Vector *pThis);


void Insertar(Vector *pThis, int elem)
{
    if( pThis->m_nCount == pThis->m_nMax )
        Resize(pThis);
    
    pThis->m_pVect[pThis->m_nCount++] = elem;
}
void Resize(Vector *pThis)
{
    
    const int delta = 5; // Usado para aumentar el tamaño del vector
    int *pTemp, i;
    pTemp = new int[pThis->m_nMax + pThis->m_nDelta]; // Asignar un nuevo vector
    for(i = 0 ; i < pThis->m_nMax ; i++) // Transferir los elementos
        pTemp[i] = pThis->m_pVect[i]; // también podemos usar la función memcpy
    delete [ ] pThis->m_pVect; // eliminar el vector antiguo
    pThis->m_pVect = pTemp; // Actualizar el puntero
    pThis->m_nMax += pThis->m_nDelta; // El Max tiene que ser incrementado por delta
    
    
//	pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta)); (REVISARRR)
//	pThis->m_nMax += pThis->m_nDelta;
}

void Mostrar(Vector *pThis)
{
    cout << "Elementos en el arreglo: ";
    for (int i = 0; i < pThis->m_nCount; i++) 
    {
        cout << pThis->m_pVect[i] << " ";
    }
    cout << endl;
    cout << "Cantidad de elementos almacenados:" << pThis->m_nCount <<endl;
}

int Buscar(Vector* pThis, int elem)
{
    for (int i = 0; i < pThis->m_nCount; i++)
    {
        if (pThis->m_pVect[i] == elem)
            return i;
    }
    return -1;  // No encontrado
}

void Eliminar(Vector* pThis, int elem)
{
    int index = Buscar(pThis, elem);
    if (index == -1)
    {
        cout << "Elemento no encontrado: " << elem << endl;
        return;
    }

    for (int i = index; i < pThis->m_nCount - 1; i++)
    {
        pThis->m_pVect[i] = pThis->m_pVect[i + 1];
    }
    pThis->m_nCount--;  // Reducir el contador
}

int main(int argc, char *argv[]) 
{
    Vector myVect;
    myVect.m_nCount = 0;
    myVect.m_nMax = 0;
    myVect.m_nDelta = 5;
    
        
    Insertar(&myVect, 10);  // Insertar elemento 10
    Insertar(&myVect, 20);  // Insertar elemento 20
    Insertar(&myVect, 30);  // Insertar elemento 30
        
    Mostrar(&myVect);  // Mostrar los elementos en el arreglo
    
    Eliminar(&myVect, 20);
    
    Mostrar(&myVect);
    return 0;
}