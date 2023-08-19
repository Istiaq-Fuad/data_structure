#ifndef STACK_H
#define STACK_H

class Stack {
   private:
    int size;
    int top;
    char* elements;

   public:
    Stack(int size);
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    void push(char data);
    void pop();
    char peek() const;
    void print_stack();
};

#endif