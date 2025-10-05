class myQueue {
    int front;
    int rear;
    int* arr;
    int size;

  public:
    myQueue(int n) {
        // Define Data Structures
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front == -1 && rear == -1;
    }

    bool isFull() {
        // check if the queue is full
        return (rear + 1) % size == front;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isEmpty()){
            front = rear = 0;
        }else{
            rear++;
        }
        arr[rear] = x;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1) % size ;
        }
    }

    int getFront() {
        // Returns the front element of the queue.
        return isEmpty()? -1 : arr[front];
    }

    int getRear() {
        // Return the last element of queue
        return isEmpty()? -1 : arr[rear];
    }
};
