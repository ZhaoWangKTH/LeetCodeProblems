//Leetcode Problems/LRUCache.cpp

/* Problem Statement: Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.*/

/* Solution: Hashtable(unordered_map in STL) + double linked list(list in STL). One trick is to only save the iterator/index of cache node in the list to Hashtable. At meantime, the list is maintained in the following way: the newly accessed in the front, the oldest accessed in the rear. Therefore, whenever access a cache node, we should move the node to the front of list, and also update its index/iterator. The key data structure of this problem are the following three:
    struct cacheEntry;
    list<cacheEntry> cacheList;
    unordered_map<int, list<cacheEntry>::iterator> cacheMap; 
*/


class LRUCache{
private:
    struct cacheEntry {
        int key;
        int val;
        cacheEntry(int k, int v): key(k), val(v) {}
    };
    
    list<cacheEntry> cacheList;
    unordered_map<int, list<cacheEntry>::iterator> cacheMap;
    int cacheCap;

private:
    void moveToFront(int key) {
        // find the entry in the cache
        auto temp = *cacheMap[key];
        // remove it from the list
        cacheList.erase(cacheMap[key]);
        // put it in front
        cacheList.push_front(temp);
        // update the cacheMap
        cacheMap[key] = cacheList.begin();
    }
    
public:
    LRUCache(int capacity) {
        cacheCap = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end())
            return -1;
            
        moveToFront(key);
        return cacheMap[key]->val;
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()) {
            // insert this node
            cacheEntry newEntry(key, value);
            // if full, remove the LRU 
            if(cacheMap.size() >= cacheCap) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(newEntry);
            cacheMap[key] = cacheList.begin();
        }
        else {
            // update the specific cache entry
            cacheMap[key]->val = value;
            moveToFront(key);
        }
    }
};
