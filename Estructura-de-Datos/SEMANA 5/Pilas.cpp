#include <iostream>
using namespace std;

struct NODE 
{
    int m_data;
    NODE* m_pNext;
};

class Stack 
{
private:
    NODE* m_pTop;  // Apunta al nodo superior (último nodo insertado)
    
public:
    Stack() : m_pTop(nullptr) {}  // Constructor que inicializa la pila vacía
    
    // Método para agregar un nodo a la pila (push)
    void Push(int data) 
    {
        NODE* newNode = new NODE;
        newNode->m_data = data;
        newNode->m_pNext = m_pTop;  // El siguiente de este nuevo nodo será el anterior nodo superior
        m_pTop = newNode;           // Ahora, el nuevo nodo es el nodo superior
    }
    
    // Método para eliminar un nodo de la pila (pop)
    void Pop() 
    {
        if (m_pTop == nullptr) 
        {
            cout << "La pila está vacía, no se puede hacer pop." << endl;
            return;
        }
        NODE* temp = m_pTop;
        m_pTop = m_pTop->m_pNext;  // El nuevo nodo superior será el siguiente nodo
        delete temp;               // Liberar memoria del nodo que se elimina
    }
    
    // Método para obtener el valor superior de la pila (top)
    int Top() const {
        if (m_pTop == nullptr) 
        {
            cout << "La pila está vacía." << endl;
            return -1;  // Devolver un valor que indique que la pila está vacía
        }
        return m_pTop->m_data;
    }
    
    // Método para verificar si la pila está vacía
    bool IsEmpty() const {
        return m_pTop == nullptr;
    }
    
    // Método para imprimir el contenido de la pila
    void Print() const 
    {
        if (m_pTop == nullptr) {
            cout << "La pila está vacía." << endl;
            return;
        }
        
        NODE* current = m_pTop;
        while (current != nullptr) 
        {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }
};

int main() 
{
    Stack stack;
    
    // Insertar algunos elementos en la pila
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(35);
    
    // Imprimir la pila
    cout << "Contenido de la pila: ";
    stack.Print();
    
    // Ver el valor superior de la pila
    cout << "Valor superior de la pila: " << stack.Top() << endl;
    
    // Eliminar el valor superior de la pila
    cout << "Haciendo pop de la pila." << endl;
    stack.Pop();
    stack.Print();
    
    // Ver el valor superior de la pila después de hacer pop
    cout << "Valor superior de la pila después de hacer pop: " << stack.Top() << endl;
    
    // Verificar si la pila está vacía
    if (stack.IsEmpty()) {
        cout << "La pila está vacía." << endl;
    } else {
        cout << "La pila no está vacía." << endl;
    }
    
    return 0;
}