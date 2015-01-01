#include "utils.h"
#include <list>

using namespace std;


class LRUCache{
private:
    struct Entry{
        int key;
        int value;
        Entry(int k, int v) : key(k), value(v){}
    };
    list<Entry> entries;
    // map key and the iterator of the entries
    unordered_map<int, list<Entry>::iterator > cached;
    int size;
public:
    LRUCache(int capacity) {
        size = capacity;
        entries.clear();
        cached.clear();
    }

    void moveToHead(int key){
        auto it = cached[key]; // O(1)
        Entry e = *it;
        entries.erase(it);
        entries.push_front(e);
        cached[key] = entries.begin();
    }

    // Get the value (will always be positive) of the key if the key exists in the cache,
    // otherwise return -1.
    int get(int key) {
        if(cached.find(key) == cached.end()) return -1; 
        // recently cached this value, then move this value to the head of the list
        moveToHead(key);
        return entries.begin()->value; 
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
        if(entries.size()==size){
            // remove the least used item (last item in the list)
            auto iter = entries.end();
            --iter;
            int key_to_rm = iter->key;
            cached.erase(key_to_rm);
            entries.erase(iter);
        }
        // insert value into list while updating the hashmap
        Entry new_entry(key, value);
        entries.push_front(new_entry);
        cached[key] = entries.begin();
    }

    void printList(){
        for(Entry e : entries){
            cout<<"("<<e.key<<") -> ["<<e.value<<"] \n";
        }
    }
};

int main(int argc, char *argv[])
{
    LRUCache lru(2);
    cout<<"set(2,1):\n";
    lru.set(2,1);
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


