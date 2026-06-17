class DynamicArray {
private: 
    int capacity;
    int size;
    int* container;

public:

    DynamicArray(int capacity) {
        size = 0;
        this->capacity = capacity;
        this->container = new int[capacity]; 
    }

    int get(int i) {
        return this->container[i];
    }

    void set(int i, int n) {
        this->container[i] = n;
    }

    void pushback(int n) {
        if(size+1 > capacity) {
            resize();
        }
        this->container[size] = n;
        this->size += 1;
    }

    int popback() {
        if(size > 0) {
            int deleted = container[size-1];
            this->container[size-1] = NULL;
            this->size -= 1;
            return deleted;
        }
    }

    void resize() {
        int* fresh = new int[capacity*2];
        for(size_t i = 0; i < size; i++) {
            int newnum = container[i];
            fresh[i] = newnum;
            container[i] = NULL;
        }
        free(container);
        this->container = fresh;
        capacity *= 2;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }
};
