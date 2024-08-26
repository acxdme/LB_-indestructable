// LRU cache
// get,put,delete,print
// lc - 146

class LRUCache {
public:
    list<int> lru;
    unordered_map<int, pair<int, list<int>::iterator>>
        mp; // <key , {value,location}>
    int totalCapacity;
    LRUCache(int capacity) { totalCapacity = capacity; }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // delete from current location
        lru.erase(mp[key].second);

        // insert in front
        lru.push_front(key);
        // update ump
        mp[key].second = lru.begin();

        // return the value
        return mp[key].first;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) // found key
        {
            lru.erase(mp[key].second);
            lru.push_front(key);
            mp[key] = {value, lru.begin()};
        } else { // key not found
            if (lru.size() == totalCapacity) {
                mp.erase(lru.back());
                lru.pop_back();
            }
            lru.push_front(key);
            mp[key] = {value, lru.begin()};
        }
    }
};
