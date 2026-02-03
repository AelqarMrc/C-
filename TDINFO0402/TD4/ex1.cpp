#include <stdlib.h>
#include <iostream>

template <class T>

class List {
    struct Cell
    {
        T data;
        Cell* next = nullptr, *prev = nullptr;
        Cell(const T& d, Cell* c): data(d), 
        prev(c != nullptr ? c->prev : nullptr), next(c) { 
            if (prev!=nullptr)
                prev->next = this; 
            if (next!=nullptr)
                next->prev = this;
            }
        Cell& insert_before(Cell* c) {
            if (c == nullptr)
            {
              perror("ERREUR !"); exit(EXIT_FAILURE);  
            } else if (!(prev == nullptr && next ==nullptr)){
                if (next!=nullptr)
                    next->prev;
                if (prev!=nullptr)
                    prev->next;
                
            } else {
                prev = c->prev;
                next = c;
                if (prev!=nullptr)
                    prev->next;
                if (next!=nullptr)
                    next->prev;

            }
                return *this;
        }

        Cell& insert_after(Cell* c) {
                        if (c == nullptr)
            {
              perror("ERREUR !"); exit(EXIT_FAILURE);  
            } else if (!(prev == nullptr && next ==nullptr)){
                if (next!=nullptr)
                    next->prev;
                if (prev!=nullptr)
                    prev->next;
                
            } else {
                prev = c;
                next = c->next;
                if (prev!=nullptr)
                    prev->next;
                if (next!=nullptr)
                    next->prev;
            }
            return *this;
        }

        Cell& remove(Cell* c){
            if (prev) prev->next = next;
            if (next) next->prev = prev;
            prev =next = nullptr;
            return *this;
        }
    };

    Cell* head = nullptr, tail = nullptr;
    Cell* current = nullptr;
    Cell* CellInsert(Cell* prev, Cell* next, const T& v){
        if (prev && next && prev->next == next && next->prev == prev)
            Cell* c = new Cell(v, next);
        else if (next == nullptr){
            Cell* c = new Cell(v, next);
            c.insert_after(prev);
            tail = c;
        }
        else if (prev == nullptr){
            Cell* c = new Cell(v, next);
            head = c;
        } else {
            c = new Cell(v, next);
            head = tail = c;
        }
        return c;
    };
    Cell* CellDelete(Cell* prev, Cell* cur, Cell* next) {
        if (prev == cur->prev && next == prev->next)
            cur->remove();
            delete cur;
        if (prev == nullptr)
            head=next;
        if(next == nullptr)
            tail=prev;
        return prev != nullptr ? prev : next;
    }
    public: 
        List() = default;
        ~List() { while (head) CellDelete(nullptr, head, head->next); }
        List (const List& other){
            for (Cell* c = other.head; c != nullptr; c = c-> next){
                Cell new_c = new Cell(c->data, nullptr);
                CellInsert(tail, new_c, nullptr);
                if (other.current == c)
                {
                    current =  new_c;
                }
                
            }
            
        }
        List& insert(const T& v){
            for (Cell* c = head; c; c = c-> next;)
            {
                if ((c->prev == nullptr || c->prev->data < v) && v < c->data){
                    CellInsert(c->prev, new Cell(v, nullptr), c);
                    return *this;
                }
            }
            CellInsert(tail, new Cell(v, nullptr), nullptr);
            return this;
        }
        List& remove(const T& v){
            for (Cell* c = head; c; c = c->next){
                if (v==c->data)
                    CellDelete(c->prev, c, c->next);
                else if (v<c->data)
                    return *this;
            }
            return *this;
        }


        friend std::ostream& operator<<(std::ostream& os, const List& l) {
            os << "[";
            for (Cell* c = l.head; c; c = c->next)
            {
                os << c->data << ",";
            }
            os << "]";
            return *this;
        }

};

int main(){
    return EXIT_SUCCESS;
}