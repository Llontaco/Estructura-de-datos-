#include <iostream>
using namespace std;

int gVect[100]; // Buffer to save the elements
int gnCount = 0; // Counter to know the number of elements used

void Insert(int elem)
{
    if (gnCount < 100) // we can only insert if there is space
        gVect[gnCount++] = elem; // Insert the element at the end
}

void Display()
{
    cout << "Elementos en el arreglo: ";
    for (int i = 0; i < gnCount; i++)
    {
        cout << gVect[i] << " ";
    }
    cout << endl;
    cout << "Cantidad de elementos almacenados: " << gnCount << endl;
}

int Search(int elem)
{
    for (int i = 0; i < gnCount; i++)
    {
        if (gVect[i] == elem)
            return i; // Return the index of the element
    }
    return -1; // Element not found
}

void Delete(int elem)
{
    int index = Search(elem);
    if (index != -1) // Element found
    {
        for (int i = index; i < gnCount - 1; i++)
        {
            gVect[i] = gVect[i + 1]; // Shift elements to the left
        }
        gnCount--; // Decrease the count of elements
    }
}

int main(int argc, char *argv[])
{
    Insert(10);  // Insert element 10
    Insert(20);  // Insert element 20
    Insert(30);  // Insert element 30

    Display();  // Display the elements in the array

    Delete(20); // Delete element 20

    Display();  // Display the elements in the array after deletion

    return 0;
}
