//TEMA 02 LISTA ENLAZADA SIMPLE

#include <iostream>
using namespace std;

template <typename T>
class CLinkedList
{
private:
    struct NODE
    {
        T m_data;
        struct NODE* m_pNext;

        NODE(T data, NODE* next = NULL) : m_data(data), m_pNext(next) {}
    };

    NODE* m_pRoot;

public:
    CLinkedList() : m_pRoot(NULL) {}

    ~CLinkedList() {
        while (m_pRoot != NULL) {
            NODE* temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
        }
    }

    void Insert(int data)
    {
        NODE* newNode = new NODE(data);
        if (m_pRoot == NULL)
        {
            m_pRoot = newNode;
        }
        else
        {
            NODE* current = m_pRoot;
            while (current->m_pNext != NULL)
            {
                current = current->m_pNext;
            }
            current->m_pNext = newNode;
        }
    }

    void InsertAtBeginning(int data)
    {
        NODE* newNode = new NODE(data, m_pRoot);
        m_pRoot = newNode;
    }

    void Print() const
    {
        NODE* current = m_pRoot;
        while (current != NULL)
        {
            cout << current->m_data << " -> ";
            current = current->m_pNext;
        }
        cout << "nullptr" << endl;
    }

    void Delete(int data)
    {
        if (m_pRoot == NULL)
            return;

        if (m_pRoot->m_data == data)
        {
            NODE* temp = m_pRoot;
            m_pRoot = m_pRoot->m_pNext;
            delete temp;
            return;
        }

        NODE* current = m_pRoot;
        while (current->m_pNext != NULL && current->m_pNext->m_data != data)
        {
            current = current->m_pNext;
        }

        if (current->m_pNext != NULL)
        {
            NODE* temp = current->m_pNext;
            current->m_pNext = current->m_pNext->m_pNext;
            delete temp;
        }
        else
        {
            cout << "Value " << data << " not found in the list!" << endl;
        }
    }
};

int main(int argc, char* argv[])
{
    CLinkedList<int> list;

    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(5);

    list.Print();

    cout << "Inserting 50 at the beginning." << endl;
    list.InsertAtBeginning(50);
    list.Print();

    cout << "Deleting 20 from the list." << endl;
    list.Delete(20);
    list.Print();

    return 0;
}

