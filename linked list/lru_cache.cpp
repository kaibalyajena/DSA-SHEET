class LRUCache {
public:
    unordered_map<int,int> m;
    unordered_map<int,list<int>::iterator> address;
    list<int> l;
    int size;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        size=0;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        list<int>::iterator it=address[key];
        l.erase(it);
        address.erase(key);
        l.push_front(key);
        address[key]=l.begin();
        return m[key];
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            list<int>::iterator it=address[key];
            m.erase(key);
            address.erase(key);
            l.erase(it);
            size--;
        }
        if(size==cap){
            int k=l.back();
            l.pop_back();
            address.erase(k);
            m.erase(k);
            size--;
        }
        size++;
        m[key]=value;
        l.push_front(key);
        address[key]=l.begin();
    }
};
