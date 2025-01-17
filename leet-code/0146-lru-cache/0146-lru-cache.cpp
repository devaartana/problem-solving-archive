struct LinkedList {
    int key, val;
    LinkedList* next;
    LinkedList* prev;

    LinkedList(int key, int value, LinkedList* nextNode = nullptr,
               LinkedList* prevNode = nullptr)
        : key(key), val(value), next(nextNode), prev(prevNode) {}
};

class LRUCache {
public:
    unordered_map<int, LinkedList*> ump;
    LinkedList *top, *bottom;
    int capacity, size;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->top = this->bottom = nullptr;
    }

    int get(int key) {
        if (ump.find(key) != ump.end()) {
            LinkedList* temp = ump[key];

            if (this->bottom == temp) {
                return temp->val;
            }

            temp->prev->next = temp->next;

            if (temp->next) {
                temp->next->prev = temp->prev;
            }

            if(this->top == temp) {
                top = top->prev;
            }

            temp->next = bottom;
            temp->prev = nullptr;
            if (this->bottom) {
                this->bottom->prev = temp;
            }
            this->bottom = temp;

            return temp->val;
        }
        return -1;
    }

    void printList() {
        LinkedList *temp = this->top;
        while(temp) {
            cout << temp->key << " ";
            temp = temp->prev;
        }

        cout << endl;
    }

    void put(int key, int value) {
        if (ump.find(key) != ump.end()) {
            ump[key]->val = value;
            get(key);
            return;
        }

        if (size == capacity) {
            ump.erase(top->key);

            LinkedList* temp = this->top;
            this->top = this->top->prev;
            if (this->top) {
                this->top->next = nullptr;
            }

            this->size--;
        }

        LinkedList* newNode = new LinkedList(key, value, bottom);
        if (this->bottom) {
            this->bottom->prev = newNode;
        }
        this->bottom = newNode;

        if (!this->top) {
            this->top = newNode;
        }

        this->size++;
        ump[key] = newNode;
        return;
    }
};
