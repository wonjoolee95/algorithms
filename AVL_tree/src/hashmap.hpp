#ifndef __HASHMAP_HPP__
#define __HASHMAP_HPP__
#define INITIAL_CAPACITY 10
#include <iostream>
#include <functional>
 
// A simple node struct for your separate chaining
template <class K,class V>
struct KVNode
{
    K key;
    V value;
    KVNode<K,V>* next;
};
 
template <class K, class V>
class HashMap {
    public:
        // Default constructor: creates an empty hash map
        HashMap();
        // Constructor setting the default value for our map
        HashMap(V value);
        // Destructor: deallocates all memory associated
        // with the hash map
        ~HashMap();
        // size() returns the number of elements currently
        // stored in the hash map.
        unsigned int size() const;
        // set() inserts the given key value pair into the
        // hash map.  If the key is already in the map, then
        // the value for that key is overwritten.
        void set(const K& key, const V& value);
        // resize() resizes the current hashmap into a bigger
        // hashmap while transfering all the elements
        void resize();
        // get() returns the value associated with the key.
        // If the key is not in the hash map, the default
        // value should be returned.
        V get(const K& key) const;
        // get_default_value() returns the default value
        // that is returned when key was not found in hash map
        V get_default_value() const;
    private:
        KVNode<K,V>** map;
        std::hash<K> hash;
        // This is the default value to return if a key is not
        // in the hash map
        V default_value;
        // This is the number of current elements 
        int n;
        // This is the max number of elements allowed
        int N;
        // This is the load factor threshold for resizing
        double threshold;
};
 
 
template <class K, class V>
HashMap<K,V>::HashMap() : default_value(), n(0), N(INITIAL_CAPACITY), threshold(1.0)
{
    //TODO: Implement this method
    map = new KVNode<K,V>*[N];
    for (int i=0; i<N; ++i)
    {
        map[i] = nullptr;
    }
}
 
template <class K, class V>
HashMap<K,V>::HashMap(V value) : default_value(value), n(0), N(INITIAL_CAPACITY), threshold(1.0)
{
    //TODO: Implement this method
    map = new KVNode<K,V> * [N];
    for (int i=0; i<N; ++i)
    {
        map[i] = nullptr;
    }
}
 
template <class K, class V>
HashMap<K,V>::~HashMap()
{
    //TODO: Implement this method
    for (int i=0; i<N; ++i)
    {
        KVNode<K,V> * temp = map[i];
        while (temp != nullptr)
        {
            map[i] = map[i]->next;
            delete temp;
            --n;
            temp = map[i];
        }
    }
    delete[] map;
}
 
template <class K, class V>
unsigned int HashMap<K,V>::size() const
{ 
    //TODO: Implement this method
    return n;
}
 
template <class K, class V>
void HashMap<K,V>::resize()
{
    N = 2*N;
    n = 0;
    KVNode<K,V>** bigger_map;
    bigger_map = new KVNode<K,V>*[N];
    for (int i=0; i<N; ++i)
        bigger_map[i] = nullptr;
    for (int i=0; i<(N/2); ++i)
    {
        while (map[i] != nullptr)
        {
            size_t hash_value = hash(map[i]->key) % N;
            KVNode<K,V>* temp = bigger_map[hash_value];
            if (temp == nullptr)
            {
                bigger_map[hash_value] = new KVNode<K,V>;
                bigger_map[hash_value]->key = map[i]->key;
                bigger_map[hash_value]->value = map[i]->value;
                bigger_map[hash_value]->next = nullptr;
                ++n;
            }
            else
            {
                while (temp->next != nullptr)
                    temp = temp->next;
                KVNode<K,V>* new_node = new KVNode<K,V>;
                new_node->key = map[i]->key;
                new_node->value = map[i]->value;
                new_node->next = nullptr;
                temp->next = new_node;
                ++n;
            }
            KVNode<K,V>* old_bucket = map[i];
            map[i] = map[i]->next;
            delete old_bucket;
        }
    }
    delete[] map;
    map = bigger_map;
}
 
template <class K, class V>
void HashMap<K,V>::set(const K& key, const V& value)
{
    //TODO: Implement this method
    double load_factor = (double(n) / double(N));
    if (load_factor >= threshold)
    {
        resize();
        set(key, value);
    }
    else
    {
        size_t hash_value = hash(key) % N;
        KVNode<K,V> * temp = map[hash_value];
        if (temp == nullptr)
        {
            map[hash_value] = new KVNode<K,V>;
            map[hash_value]->key = key;
            map[hash_value]->value = value;
            map[hash_value]->next = nullptr;
            ++n;
            return;
        }
        else
        {
            if (temp->key == key)
            {
                temp->value = value;
                return;
            }
            while (temp->next != nullptr)
            {
                if ( (temp->next)->key == key)
                {
                    (temp->next)->value = value;
                    return;
                }
                else
                    temp = temp->next;
            }
            KVNode<K,V> * new_node = new KVNode<K,V>;
            new_node->key = key;
            new_node->value = value;
            new_node->next = nullptr;
            temp->next = new_node;
            ++n;
        }
    }
}
 
template <class K, class V>
V HashMap<K,V>::get(const K& key) const
{
    //TODO: Implement this method
    size_t hash_value = hash(key) % N;
    KVNode<K,V> * temp = map[hash_value];
    while (temp != nullptr)
    {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return default_value;
}
 
template <class K, class V>
V HashMap<K,V>::get_default_value() const
{
    return default_value;
}
 
#endif // __HASHMAP_HPP__
