#ifndef STACK_H
#define STACK_H

class Stack {
   private:
    int size;
    int top;
    int* elements;

   public:
    Stack(int size);
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(int data);
    void pop();
    int peek() const;
    void print_stack();
};

#endif