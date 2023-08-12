#ifndef HEAP_H
#define HEAP_H

class Heapp {
   private:
    int *heap;
    int size;
    void destroy_heap(int *heap);
    void heapify(int i, bool max);

   public:
    Heapp() : heap(nullptr), size(0){};
    ~Heapp() { destroy_heap(heap); };
    void insert(int key);
    void max_heapify();
    void min_heapify();
    void delete_node(int element);
    void print_heap() const;
};

#endif
