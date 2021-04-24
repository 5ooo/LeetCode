#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;


class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head_ = NULL;
        tail_ = NULL;
    }
    
    int get(int key) {
        int ret = -1;
        
        auto it = map_.find(key);
        if (it != map_.end())
        {
            ret = it->second->val;
            
            list_erase(it->second);
            
            list_set_head(it->second);
        }
        
        return ret;
    }
    
    void put(int key, int value) {
        auto it = map_.find(key);
        if (it != map_.end())
        {
            it->second->val = value;
            
            list_erase(it->second);
            
            list_set_head(it->second);
        }
        else
        {
            if (map_.size() == capacity_)
            {
                map_.erase(map_.find(tail_->key));
                
                list_erase(tail_);
            }

            Node *p = new Node(key, value);

            list_set_head(p);

            map_[key] = p;
        }
        
    }
    
    struct Node
    {
        int key;
        int val;
        
        Node *prev;
        Node *next;
        
        Node(int key, int val) : key(key), val(val), prev(NULL), next(NULL) {}
    };
    
    void list_erase(Node *p)
    {
        if (p->prev != NULL)
        {
            p->prev->next = p->next;
        }
        else
        {
            head_ = p->next;
        }
        
        if (p->next != NULL)
        {
            p->next->prev = p->prev;
        }
        else
        {
            tail_ = p->prev;
        }
    }
    
    void list_set_head(Node *p)
    {
        if (head_ == NULL)
        {
            head_ = p;
            tail_ = p;
        }
        else
        {
            p->next = head_;
            head_->prev = p;
            p->prev = NULL;
            
            head_ = p;
        }
    }
    
    unordered_map<int, Node *> map_;
    Node *head_, *tail_;
    
    int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
	Solution s;

	return 0;
}
