#include <iostream>
using namespace std;

struct Vector
{
    int *m_pVect; // Pointer to the buffer
    int m_nCount; // Control how many elements are actually used
    int m_nMax; // Control how many are allocated as maximum
    int m_nDelta; // To control the growing
};

void Resize(Vector *pThis);

void Insert(Vector *pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax)
        Resize(pThis);

    pThis->m_pVect[pThis->m_nCount++] = elem;
}

void Resize(Vector *pThis)
{
    int *pTemp, i;
    pTemp = new int[pThis->m_nMax + pThis->m_nDelta]; // Alloc a new vector
    for (i = 0; i < pThis->m_nMax; i++) // Transfer the elements
        pTemp[i] = pThis->m_pVect[i]; // we can also use the function memcpy
    delete[] pThis->m_pVect; // delete the old vector
    pThis->m_pVect = pTemp; // Update the pointer
    pThis->m_nMax += pThis->m_nDelta; // The Max has to be increased by delta
}

void Display(Vector *pThis)
{
    cout << "Elementos en el arreglo: ";
    for (int i = 0; i < pThis->m_nCount; i++)
    {
        cout << pThis->m_pVect[i] << " ";
    }
    cout << endl;
    cout << "Cantidad de elementos almacenados: " << pThis->m_nCount << endl;
}

int Search(Vector *pThis, int elem)
{
    for (int i = 0; i < pThis->m_nCount; i++)
    {
        if (pThis->m_pVect[i] == elem)
            return i; // Return the index of the element
    }
    return -1; // Element not found
}

void Delete(Vector *pThis, int elem)
{
    int index = Search(pThis, elem);
    if (index != -1) // Element found
    {
        for (int i = index; i < pThis->m_nCount - 1; i++)
        {
            pThis->m_pVect[i] = pThis->m_pVect[i + 1]; // Shift elements to the left
        }
        pThis->m_nCount--; // Decrease the count of elements
    }
}

int main(int argc, char *argv[])
{
    Vector myVect;
    myVect.m_nCount = 0;
    myVect.m_nMax = 0;
    myVect.m_nDelta = 5;

    Insert(&myVect, 10);  // Insert element 10
    Insert(&myVect, 20);  // Insert element 20
    Insert(&myVect, 30);  // Insert element 30

    Display(&myVect);  // Display the elements in the array

    Delete(&myVect, 20); // Delete element 20

    Display(&myVect);  // Display the elements in the array after deletion

    return 0;
}