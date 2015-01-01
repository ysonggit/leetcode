#include "utils.h"
#include <list>

using namespace std;

/*
class LRUCache{
private:
    struct Entry{
        int key;
        int value;
        Entry(int k, int v) : key(k), value(v){}
    };
    list<Entry> values;
    // map key and the iterator of the values
    unordered_map<int, list<Entry>::iterator > cached;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
        values.clear();
        cached.clear();
    }
    
    void moveToHead(int key){
        auto it = cached[key]; // O(1)
        Entry e = *it;
        values.erase(it);
        values.push_front(e);
        cached[key] = values.begin();
    }
    
    // Get the value (will always be positive) of the key if the key exists in the cache,
    // otherwise return -1.
    int get(int key) {
        if(cached.find(key) == cached.end()) return -1; 
        // recently cached this value, then move this value to the head of the list
        moveToHead(key);
        return values.begin()->value; 
    }
    // Set or insert the value if the key is not already present.
    // When the cache reached its capacity,
    // it should invalidate the least recently used item before inserting a new item. 
    void set(int key, int value) {
        if(cached.find(key) != cached.end()){
            cached[key]->value = value;
            moveToHead(key);
            return;
        }
        if(values.size()==size){
            // remove the least used item (last item in the list)
            auto iter = values.end();
            --iter;
            int key_to_rm = iter->key;
            cached.erase(key_to_rm);
            values.erase(iter);
        }
        // insert value into list while updating the hashmap
        Entry new_entry(key, value);
        values.push_front(new_entry);
        cached[key] = values.begin();
    }
};
*/

class LRUCache{
private:
    struct Entry{
        int key;
        int value;
        Entry * prev;
        Entry * next;
        Entry(int k, int v) : key(k), value(v){ prev = NULL; next = NULL;}
    };
    // map key and the iterator of the entries
    unordered_map<int, Entry*> cached;
    int size;
    Entry *head;
    Entry *tail;
public:
    LRUCache(int capacity) {
        size = capacity;
        cached.clear();
        head = NULL;
        tail = NULL;
    }
    //  prev <-> cur <-> next
    //           |
    //  NULL <-> cur <->  ... prev <-> next
    void moveToHead(int key){
        Entry * entry_to_mv = cached[key]; // O(1)
        if(entry_to_mv == head) return;
        Entry * pre = entry_to_mv->prev;
        Entry * nex = entry_to_mv->next;
        pre->next = nex;
        if(entry_to_mv != tail){
            nex->prev = pre;
        }else{
            tail = pre;
        }
        Entry * head_cp = head;
        entry_to_mv->prev = NULL;
        entry_to_mv->next = head_cp;
        head_cp->prev = entry_to_mv;
        head = entry_to_mv;
        cached[key] = head;
    }
    // pre <-> tail <-> NULL
    //        |
    // pre <-> NULL
    void removeTail(){
        if(tail==nullptr) return;
        Entry * to_rm = tail;
        Entry * pre = tail->prev;
        if(pre != nullptr){
            pre->next = NULL;
            tail = pre;
        }else{
            // tail == head
        }
        delete to_rm;
        to_rm = NULL; // avoid dangling pointer
    }
    // insert to the tail of the list
    // return the new tail
    Entry * insert(int key, int value){
        Entry * new_entry = new Entry(key, value);
        if(tail == nullptr){
            tail = new_entry;
            head = tail;
            return tail;
        }
        Entry * tail_cp = tail;
        new_entry->prev = tail_cp;
        new_entry->next = NULL;
        tail_cp->next = new_entry;
        tail = new_entry;
        return tail;
    }

    // Get the value (will always be positive) of the key if the key exists in the cache,
    // otherwise return -1.
    int get(int key) {
        if(cached.find(key) == cached.end()) return -1; 
        // recently cached this value, then move this value to the head of the list
        moveToHead(key);
        return head->value; 
    }
    // Set or insert the value if the key is not already present.
    // When the cache reached its capacity,
    // it should invalidate the least recently used item before inserting a new item. 
    void set(int key, int value) {
        if(cached.find(key) != cached.end()){
            // if insert the same key but different value, then, update the value
            cached[key]->value = value;
            moveToHead(key);
            return;
        }
        if(cached.size()==size){
            // remove the least used item (last item in the list)
            int key_to_rm = tail->key;
            cached.erase(key_to_rm);
            removeTail();
        }
        // insert value into list while updating the hashmap
        cached[key] = insert(key, value); 
        moveToHead(key);
    }

    void printList(){
        Entry * cur = head;
        while(cur != NULL){
            cout<<"("<<cur->key<<") -> ["<<cur->value<<"] \n";
            cur=cur->next;
        }
    }
};

int main(int argc, char *argv[])
{
    LRUCache lru(2);
    lru.set(2,1);
    cout<<"set(2,1):\n";
    lru.printList();
    cout<<"set(1,1):\n";
    lru.set(1,1);
    lru.printList();
    cout<<"get(2) = "<<lru.get(2)<<endl;
    cout<<"set(4,1):\n";
    lru.set(4,1);
    lru.printList();
    cout<<"get(1) = "<<lru.get(1)<<endl;
    cout<<"get(2) = "<<lru.get(2)<<endl; 
    return 0;
}


