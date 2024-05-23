/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
*/
class LRUCache
{
public:
    int size;                                    // Capacity of the cache
    list<int> dll;                               // Doubly linked list to maintain the order of keys based on their usage frequency
    map<int, pair<list<int>::iterator, int>> mp; // Map to store key-value pairs along with iterators pointing to their positions in the doubly linked list

    // Constructor to initialize the cache with a given capacity
    LRUCache(int capacity)
    {
        size = capacity; // Initialize the cache capacity
    }

    // Moves the given key to the front of the doubly linked list, indicating it was recently used
    void makeRecentlyUsed(int key)
    {
        dll.erase(mp[key].first);    // Remove the existing iterator of the key from the doubly linked list
        dll.push_front(key);         // Add the key to the front of the doubly linked list
        mp[key].first = dll.begin(); // Update the iterator of the key in the map
    }

    // Retrieves the value associated with the given key and makes it the most recently used key
    int get(int key)
    {
        if (mp.find(key) == mp.end()) // If key does not exist in the cache
            return -1;                // Return -1 indicating key not found

        makeRecentlyUsed(key); // Make the key the most recently used

        return mp[key].second; // Return the value associated with the key
    }

    // Inserts or updates the value associated with the given key in the cache
    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {                           // If key already exists in the cache
            mp[key].second = value; // Update the value associated with the key
            makeRecentlyUsed(key);  // Make the key the most recently used
        }
        else
        {                                   // If key does not exist in the cache
            dll.push_front(key);            // Add the key to the front of the doubly linked list
            mp[key] = {dll.begin(), value}; // Update the map with the key-value pair and its iterator
            size--;                         // Reduce the remaining capacity of the cache
        }

        if (size < 0)
        {                                    // If cache exceeds its capacity
            int keyToBeDeleted = dll.back(); // Get the least recently used key from the end of the doubly linked list
            mp.erase(keyToBeDeleted);        // Remove the key-value pair from the map
            dll.pop_back();                  // Remove the least recently used key from the end of the doubly linked list
            size++;                          // Increase the remaining capacity of the cache
        }
    }
};
