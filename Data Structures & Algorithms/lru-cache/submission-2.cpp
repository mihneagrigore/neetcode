class LRUCache {
public:

    struct ListNode {
        int key, val;
        ListNode *next, *prev;

        ListNode(): key(0), val(0), next(nullptr), prev(nullptr) {}
        ListNode(int x): key(x), val(0), next(nullptr), prev(nullptr) {}
        ListNode(int x, int y): key(x), val(y), next(nullptr), prev(nullptr) {}
        ListNode(int x, int y, ListNode* nxt): key(x), val(y), next(nxt), prev(nullptr) {}
        ListNode(int x, int y, ListNode* nxt, ListNode* prv): key(x), val(y), next(nxt), prev(prv) {}

    };

    struct ll {
        ListNode* head;
        ListNode* last;
        int size, cap;
    } lst;

    unordered_map<int, ListNode*> cache;

    LRUCache(int capacity) {
        lst.head = new ListNode();
        lst.last = lst.head;
        lst.cap = capacity;
        lst.size = 0;
    }
    
    int get(int key) {

        // ListNode *copy = lst.head;
        // while(copy != nullptr) {
        //     cout<<copy->val<<" ";
        //     copy = copy->next;
        // }

        // cout<<endl;

        if(cache.find(key) != cache.end()) {
            ListNode *access = cache[key];

            if (access == lst.last)
                return access->val;

            if(access->prev != nullptr)
                access->prev->next = access->next;
            else
                lst.head = access->next;

            if(access->next != nullptr) 
                access->next->prev = access->prev;
            else 
                return cache[key]->val;

            access->prev = lst.last;
            access->next = nullptr;
            lst.last->next = access;
            lst.last = access;

            return cache[key]->val;
        }

        return -1;
    }
    
    void put(int key, int value) {

        // ListNode *copy = lst.head;
        // while(copy != nullptr) {
        //     cout<<copy->val<<" ";
        //     copy = copy->next;
        // }

        // cout<<endl;


        if(get(key) == -1) {
            if(lst.size == lst.cap) {
                cache.erase(lst.head->key);
                ListNode* old = lst.head;

                if (lst.size == 1) {
                    lst.head = new ListNode(key, value);
                    lst.last = lst.head;
                    cache.insert({key, lst.head});
                    delete old;
                } else {
                    lst.head = lst.head->next;
                    lst.head->prev = nullptr;

                    lst.last->next = new ListNode(key, value, nullptr, lst.last);
                    lst.last = lst.last->next;

                    cache.insert({key, lst.last});
                    delete old;
                }
            } else {
                if(lst.size == 0) {
                    lst.head->key = key;
                    lst.head->val = value;
                    cache.insert({key, lst.head});
                    lst.size++;
                } else {
                    lst.last->next = new ListNode(key, value, nullptr, lst.last);
                    lst.last = lst.last->next;
                    cache.insert({key, lst.last});
                    lst.size++;
                }
            }
        } else {
            cache[key]->val = value;
        }
    }
};
