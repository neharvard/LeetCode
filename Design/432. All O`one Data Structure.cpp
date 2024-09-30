/*
  Leetcode Link : https://leetcode.com/problems/all-oone-data-structure/
*/

/***************************************************************** C++ *****************************************************************/
//Approach (Using map + dll[doubly Linked List])
//T.C : O(1)
//S.C : O(n) , map stores n strings
class AllOne {
public:
    struct Node {
       int count;
       list<string>keys;
       Node* prev;
       Node* next;
       Node(int c){
         count = c;
         prev = nullptr;
         next = nullptr;
       } 
    };

    unordered_map<string, Node*>mp;
    Node* head; // head->next indicate min freq
    // Node* first; // for getting min freq 
    Node* last; // for getting max freq

    void addNode(Node* prevNode, int count){
        Node* newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;

        if(newNode->next != nullptr){
            newNode->next->prev = newNode;
        }
        prevNode->next = newNode;

        if(prevNode == last){
            last = newNode;
        }
    }

    void removeNode(Node* node){
        node->prev->next = node->next;
        if(node->next != nullptr){
            node->next->prev = node->prev;
        }

        if(node == last){
            last = node->prev;
        }

        delete node;
    }

    AllOne() {
      head = new Node(0);
      last = head;
    }
    
    void inc(string key) {
        if(mp.find(key) == mp.end()){ // string not inserted yet
          // the freq is not existed in the linked list then create
           if(head->next == nullptr || head->next->count != 1){
             addNode(head, 1);
           }

           head->next->keys.push_front(key);
           mp[key] = head->next;
           
        } else{
            Node* curNode = mp[key];
            int curCount = curNode->count;
            if(curNode->next == nullptr || curNode->next->count != curCount+1){
                addNode(curNode, curCount+1);
            }
            curNode->next->keys.push_front(key);
            mp[key] = curNode->next;

            curNode->keys.remove(key);
            if(curNode->keys.empty()){
                removeNode(curNode);
            }
        }
    }
    
    void dec(string key) {
      Node* curNode = mp[key];
      int curCount = curNode->count;

      if(curCount == 1){ // remove if the count becomes 0, 1-1=0
        mp.erase(key);
      }else{
        if(curNode->prev->count != curCount-1){
           addNode(curNode->prev, curCount-1);
        }
        curNode->prev->keys.push_front(key);
        mp[key] = curNode->prev;
      }
        curNode->keys.remove(key);

        if(curNode->keys.empty()){
           removeNode(curNode);
        }
      
    }

    string getMaxKey() { 
        if(head == last) return ""; // nothing inserted
        return last->keys.front();
    }
    
    string getMinKey() { 
        if(head->next == nullptr) return "";
        return head->next->keys.front();
    }
};


