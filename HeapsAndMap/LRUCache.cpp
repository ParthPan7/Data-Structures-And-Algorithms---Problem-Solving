/*
LRU Cache Problem : https://www.interviewbit.com/problems/lru-cache/
Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.
*/

 unordered_map< int, pair< int,list<int>::iterator > > map;
    list<int> items; 
    int cacheCapacity;
    LRUCache(int capacity) 
    {
        cacheCapacity = capacity;
    }
    
    int get(int key) 
    {
        if ( map.find(key) != map.end() )
        {
            items.erase( map[key].second );
            items.push_front(key);
            map[key].second = items.begin();
            return map[key].first;
        }
        return -1;
    }
    
    void set(int key, int value) 
    {
        if ( map.find(key) != map.end() )
        {
            items.erase( map[key].second );
        }
        else if ( items.size() == cacheCapacity )
        {
            map.erase( items.back() );
            items.pop_back(); 
        }
        items.push_front(key);
        map[key] = { value,  items.begin() };
    }
