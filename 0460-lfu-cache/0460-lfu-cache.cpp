class Node{
    public:
    int key, val, freq;
    Node *prev, *next;
    Node(int k, int v){
        key = k;
         val = v;
         freq = 1;
         prev = next = NULL;
    }
};
class List{
    public:
    int size;
    Node *head, *tail;
    List(){
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void addFront(Node *node){
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }
    void removeNode(Node *node){
        Node *delPrev = node->prev;
        Node *delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};
class LFUCache {
    map<int, Node*>keyNode;
    map<int, List*>freqList;
    int maxSizeCache;
    int minFreq;
    int curSize;
public:
    LFUCache(int capacity) {
       maxSizeCache = capacity;
       minFreq = 0;
       curSize = 0; 
    }
    void updateFreq(Node *node){
        keyNode.erase(node->key);
        freqList[node->freq]->removeNode(node);
        if(node->freq == minFreq && freqList[node->freq]->size == 0){
        freqList.erase(node->freq);
        minFreq++;
    }
    node->freq++;
    if(freqList.find(node->freq) == freqList.end()){
        freqList[node->freq] = new List();
    }
    freqList[node->freq]->addFront(node);
    keyNode[node->key] = node;
}
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end())
        return -1;

        Node *node = keyNode[key];
        int ans = node->val;
        updateFreq(node);
        return ans;
    }
    
    void put(int key, int value) {
      if(maxSizeCache == 0)
      return;

      if(keyNode.find(key) != keyNode.end()){
        Node *node = keyNode[key];
        node->val = value;
        updateFreq(node);
        return;
      }  
      if(curSize == maxSizeCache){
        List *list = freqList[minFreq];
        Node *node = list->tail->prev;
        keyNode.erase(node->key);
        list->removeNode(node);
        curSize--;
      }
      curSize++;
      minFreq = 1;
      Node *node = new Node(key, value);
      if(freqList.find(minFreq) == freqList.end()){
        freqList[minFreq] = new List();
      }
        freqList[minFreq] -> addFront(node);
        keyNode[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */