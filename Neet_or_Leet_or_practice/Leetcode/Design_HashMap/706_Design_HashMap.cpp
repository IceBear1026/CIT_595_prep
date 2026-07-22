class MyHashMap {
private:
    map<int, int> newmap;
public:
    // member initializer list
    MyHashMap() : newmap() {
        
    }
    
    void put(int key, int value) {
        newmap[key] = value;
    }
    
    int get(int key) {
        if (newmap.find(key) != newmap.end()){
            return newmap[key];
        }
        return -1;
    }
    
    void remove(int key) {
        newmap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */