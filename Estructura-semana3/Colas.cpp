#include <iostream>
using namespace std;

struct NODE 
{
	int m_data;
	NODE* m_pNext;
};

class Queue 
{
private:
	NODE* m_pFront;  // Apunta al nodo frontal (primer nodo insertado)
	NODE* m_pRear;   // Apunta al nodo trasero (último nodo insertado)
	
public:
	Queue() : m_pFront(nullptr), m_pRear(nullptr) {}  // Constructor que inicializa la cola vacía
	
	// Método para agregar un nodo al final de la cola (enqueue)
	void Enqueue(int data) 
	{
		NODE* newNode = new NODE;
		newNode->m_data = data;
		newNode->m_pNext = nullptr;
		
		if (m_pRear == nullptr) 
		{
			// Si la cola está vacía, tanto el frente como el trasero apuntan al nuevo nodo
			m_pFront = newNode;
			m_pRear  = newNode;
			
		} 
		else 
		{
			// Si la cola no está vacía, el nodo trasero apunta al nuevo nodo
			m_pRear->m_pNext = newNode;
			m_pRear = newNode;  // Ahora, el nuevo nodo es el nodo trasero
		}
	}
	
	// Método para eliminar un nodo de la cola (dequeue)
	void Dequeue() 
	{
		if (m_pFront == nullptr) 
		{
			cout << "La cola está vacía, no se puede hacer dequeue." << endl;
			return;
		}
		NODE* temp = m_pFront;
		m_pFront = m_pFront->m_pNext;  // El nuevo frente será el siguiente nodo
		delete temp;  // Liberar memoria del nodo que se elimina
		
		if (m_pFront == nullptr) 
		{
			m_pRear = nullptr;  // Si la cola está vacía, el nodo trasero también debe ser nulo
		}
	}
	
	// Método para obtener el valor del frente de la cola (front)
	int Front() const {
		if (m_pFront == nullptr) {
			cout << "La cola está vacía." << endl;
			return -1;  // Devolver un valor que indique que la cola está vacía
		}
		return m_pFront->m_data;
	}
	
	// Método para verificar si la cola está vacía
	bool IsEmpty() const {
		return m_pFront == nullptr;
	}
	
	// Método para imprimir el contenido de la cola
	void Print() const 
	{
		if (m_pFront == nullptr) {
			cout << "La cola está vacía." << endl;
			return;
		}
		
		NODE* current = m_pFront;
		while (current != nullptr) {
			cout << current->m_data << " -> ";
			current = current->m_pNext;
		}
		cout << "nullptr" << endl;
	}
};

int main() {
	Queue queue;
	
	// Insertar algunos elementos en la cola
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	
	// Imprimir la cola
	cout << "Contenido de la cola: ";
	queue.Print();
	
	// Ver el valor del frente de la cola
	cout << "Valor del frente de la cola: " << queue.Front() << endl;
	
	// Eliminar el valor frontal de la cola
	cout << "Haciendo dequeue de la cola." << endl;
	queue.Dequeue();
	queue.Print();
	
	// Ver el valor del frente de la cola después de hacer dequeue
	cout << "Valor del frente de la cola después de hacer dequeue: " << queue.Front() << endl;
	
	// Verificar si la cola está vacía
	if (queue.IsEmpty()) 
	{
		cout << "La cola está vacía." << endl;
	} 
	else 
	{
		cout << "La cola no está vacía." << endl;
	}
	
	return 0;
}