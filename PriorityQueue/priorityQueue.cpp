#include<iostream>
#define N 8
using namespace std;

class PriorityQueue0
{
    int A[N], head = 0, tail = 0;

public:
    // Function to insert an element in the priority queue while maintaining order
    bool InsertinOrder(int x)
    {
        unblock(); // Check and unblock the queue if necessary
        int flag = 0, size = 0;

        // Check if the queue is not full
        if (!isFull())
        {
            // Iterate through the elements to find the correct position for the new element
            for (int i = 0; i < tail; i++)
            {
                if (A[i] >= x)
                {
                    shifting(i); // Shift elements to make space for the new element
                    A[i] = x;    // Insert the new element
                    flag = 1;
                    size++;
                    tail++;
                    break;
                }
            }

            // If the new element is greater than all existing elements, insert at the end
            if (flag == 0)
            {
                A[tail] = x;
                tail++;
            }
            return true; // Element successfully inserted
        }
        return false; // Queue is full
    }

    // Function to shift elements to make space for a new element
    void shifting(int index)
    {
        for (int i = N; i >= index; i--)
        {
            A[i] = A[i - 1];
        }
    }

    // Function to remove an element from the front of the priority queue
    bool Remove(int &x)
    {
        if (!isEmpty())
        {
            x = A[head++];
            return true; // Element successfully removed
        }
        return false; // Queue is empty
    }

    // Function to check if the priority queue is full
    bool isFull()
    {
        if (tail == N && head == 0)
        {
            return true; // Queue is full
        }
        return false; // Queue is not full
    }

    // Function to check if the priority queue is empty
    bool isEmpty()
    {
        if (head == tail)
        {
            return true; // Queue is empty
        }
        return false; // Queue is not empty
    }

    // Function to unblock the queue by moving elements to the beginning
    bool unblock()
    {
        if (tail == N && head > 0)
        {
            // Move elements to the beginning of the array
            for (int i = head; i < tail; i++)
            {
                A[i - head] = A[i];
            }
            tail = tail - head;
            head = 0;
            return true; // Queue successfully unblocked
        }
        return false; // Queue is not unblocked
    }

    // Function to traverse and print the elements in the priority queue
    bool traverse()
    {
        if (isEmpty())
        {
            return false; // Queue is empty
        }
        cout << "\n";
        for (int i = head; i < tail; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
        return true; // Successfully traversed and printed the elements
    }

    // Function to display the elements in the priority queue with their indices
    void Display()
    {
        for (int i = head; i < tail; i++)
        {
            cout << "Index = " << i << " Data = " << A[i] << endl;
        }
    }

    // Constructor for the PriorityQueue0 class
    PriorityQueue0()
    {
        head = 0;
        tail = 0;
    }

    // Destructor for the PriorityQueue0 class
    ~PriorityQueue0() {}
};

int main()
{
    PriorityQueue0 Q;

    // Inserting elements into the priority queue
    Q.InsertinOrder(9);
    Q.InsertinOrder(0);
    Q.InsertinOrder(1);
    Q.InsertinOrder(5);
    Q.InsertinOrder(2);
    Q.InsertinOrder(6);

    // Displaying the elements in the priority queue
    Q.Display();

    return 0;
}

