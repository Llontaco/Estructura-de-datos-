#include <iostream>
using namespace std;

struct Vector
{
    int*m_pVect, 
        m_nCount, 
        m_nMax, 
        m_nDelta; 
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
    
    const int delta = 5; 
    int *pTemp, i;
    pTemp = new int[pThis->m_nMax + pThis->m_nDelta]; 
    for(i = 0 ; i < pThis->m_nMax ; i++) 
        pTemp[i] = pThis->m_pVect[i]; 
    delete [ ] pThis->m_pVect; 
    pThis->m_pVect = pTemp; 
    pThis->m_nMax += pThis->m_nDelta; 
    
    

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