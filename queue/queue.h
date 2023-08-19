#ifndef QUEUE_H
#define QUEUE_H

class Queue {
   private:
    char* data;
    int front;
    int rear;
    int size;

   public:
    Queue(int size);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(char element);
    void dequeue();
    char front_element() const;
    void print_queue() const;
};

#endif