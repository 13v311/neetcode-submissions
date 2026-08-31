class LRUCache {
public:
    using ListIt = list<pair<int, int>>::iterator;

    int capacity;

    // key -> iterator pointing to that key's node in the list
    unordered_map<int, ListIt> cache;

    // front = least recently used
    // back  = most recently used
    list<pair<int, int>> used;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // Key doesn't exist
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        // Find the node in the list
        auto it = cache[key];

        // Save its value before removing it
        int value = it->second;

        // Remove it from its current position
        used.erase(it);

        // Put it at the back (most recently used)
        used.push_back({key, value});

        // Update the map to point to its new position
        cache[key] = prev(used.end());

        return value;
    }

    void put(int key, int value) {
        // Key already exists
        if (cache.find(key) != cache.end()) {
            // Remove its old position
            used.erase(cache[key]);

            // Remove old map entry
            cache.erase(key);
        }

        // If we're at capacity, remove the LRU item
        if (cache.size() == capacity) {
            int lruKey = used.front().first;

            used.pop_front();
            cache.erase(lruKey);
        }

        // Add new item as MRU
        used.push_back({key, value});

        // Point map to the new list node
        cache[key] = prev(used.end());
    }
};