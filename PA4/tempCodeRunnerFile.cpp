/*  Program: PA 4 EX 3
    Author: Ricardo Diaz
    Class: CSCI 240
    Date: 9/29/24
    Description: PA 4 Exercise 3
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class myLinkedQueue {
private:
    struct Node {
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}

};
    Node* frontNode;
    Node* rearNode;
    int count;

public:
    myLinkedQueue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    int size() const {
        return count;
    }

    bool empty() const {
        return count == 0;
    }

    T front() const {
        if (!empty()) {
            return frontNode->data;
        }
    }

    void enqueue(T e) {
        Node* newNode = new Node(e);
        if (empty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    T dequeue() {
        if (!empty()) {
            Node* temp = frontNode;
            T data = frontNode->data;
            frontNode = frontNode->next;
            delete temp;
            count--;
            if (count == 0) {
                rearNode = nullptr;
            }
            return data;
        }
    }

    ~myLinkedQueue() {
        while (!empty()) {
            dequeue();
        }
    }
};

void simulateHardcoded() {
    myLinkedQueue<int> jobQueue;
    int jobUnits[] = {2, 1, 2, 1, 1};
    const int numJobs = 5;
    cout << "Simulating queue with hardcoded units.\n";

    for (int i = 0; i < numJobs; ++i) {
        std::cout << "Enqueue job " << i + 1 << " with " << jobUnits[i] << " units\n";
        jobQueue.enqueue(jobUnits[i]);
    }

    int cycle = 1;
    while (!jobQueue.empty()) {
        int job = jobQueue.dequeue();
        cout << cycle << " Processing job with " << job << " units\n";
        job--;
        if (job > 0) {
            jobQueue.enqueue(job);
        } else {
            cout << "Done with job " << cycle << endl;
        }
        cycle++;
    }

    cout << "Done with all hardcoded jobs.\n";
}

void simulateRandom() {
    myLinkedQueue<int> jobQueue;
    const int numJobs = 5;
    int jobUnits[numJobs];

    srand(static_cast<unsigned>(time(0)));

    cout << "Simulating queue with random units.\n";
    for (int i = 0; i < numJobs; ++i) {
        jobUnits[i] = rand() % 6 + 1;
        cout << "Enqueue job " << i + 1 << " with " << jobUnits[i] << " units.\n";
        jobQueue.enqueue(jobUnits[i]);
    }

    int cycle = 1;
    while (!jobQueue.empty()) {
        int job = jobQueue.dequeue();
        cout << cycle << " Processing job with " << job << " units\n";
        job--;
        if (job > 0) {
            jobQueue.enqueue(job);
        } else {
            cout << "Done with job " << cycle << endl;
        }
        cycle++;
    }
    cout << "Done with all random jobs.\n";
}

int main() {
    cout << "Author: Ricardo Diaz" << endl;

    simulateHardcoded();
    simulateRandom();

    return 0;
}