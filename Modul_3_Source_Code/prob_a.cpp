#include "single_linked_list.h"
#include <iostream>

using namespace std;

int main() {
    int n;
    long long k;    
    cin >> n >> k;
    long long k_awal = k;

    SingleLinkedList list;
    list.init();
    
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        list.add_back(x);
    }
    
    list.tail->next = list.head; 

    Node *prev = list.tail;
    Node *curr = list.head;

    while (list.size > 1){
        long long langkah = (k -1) % list.size;
        for(long long i = 0; i < langkah; i++) {
            prev = curr;
            curr = curr->next;
        }
        if(curr->data % 2 == 0){
            k++;
        } else {
            k--;
        }

        if (k <= 0){
            k = k_awal;
        }

        Node *to_delete = curr;
        prev->next = curr->next;

        if (curr == list.head) {
            list.head = curr->next;
        }
        if (curr == list.tail) {
            list.tail = prev;
        }
        curr = prev->next;
        delete to_delete;
        list.size--;
    }
    list.tail->next = nullptr;
    cout << list.head->data << endl;
}