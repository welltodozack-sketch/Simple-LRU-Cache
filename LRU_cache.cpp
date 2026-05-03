#include <iostream>

using namespace std;


// LRU Cache logic
class LRU_cache{
    private:
        int* keys;
        int* values;
        int size;
        int capacity;

        void moveToFirst(int index){
            int k = keys[index];
            int v = values[index];

            for(int i = index; i > 0; i--){
                keys[i] = keys[i - 1];
                values[i] = values[i - 1];
            }

            keys[0] = k;
            values[0] = v;        
        }

    public:

        LRU_cache(int cap) : capacity(cap), size(0){
            keys = new int[cap];
            values = new int[cap];
        };

        ~LRU_cache(){
            delete[] keys;
            delete[] values;
        }

        int get(int key){
            bool found = false;
            for(int i = 0; i < size ; i++){
                if(keys[i] == key){
                    moveToFirst(i);
                    found = true;
                    return 0;
                }
            }
            if(!found){
                return 1;
            }
            return 1;
        }

        void put(int key, int value){

            if(size == capacity){
                size--;
            }

            for(int i = size; i > 0; i--){
                keys[i] = keys[i-1];
                values[i] = values[i-1];
            }

            keys[0] = key;
            values[0] = value;
            size++;
        }

        void print(){
            for(int i = 0; i < size ; i++){
                cout << "[" << keys[i] << ", " << values[i] << "]" << " ";
            }
            cout << "\n";
        }
};

int main(){
    const int size = 3; // change to increase size of array
    LRU_cache lru(size);
    int value = 10;
    int get_count = 0;

    // test LRU Cache
    for(int i = 1; i < 100; i++){

        if(get_count == 4){
            lru.get(i-size); lru.print(); // every 5 loops, get last item inside array. (This moves the item to the start, since it was called)
            get_count = 0;
        }

        lru.put(i, value); lru.print(); // add a new value to the array.
        value+=10;
        get_count+=1;
    }

    return 0;
}