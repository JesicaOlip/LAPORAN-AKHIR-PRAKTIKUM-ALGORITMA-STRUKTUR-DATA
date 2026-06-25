#include "double_linked_list.h"
#include <iostream>

using namespace std;

int main() {
    int N, R;
    cin >> N >> R;

    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        list.add_back(c);
    }
    
    list.tail->next = list.head;
    list.head->prev = list.tail;

    Node* alpha = list.head;
    Node* beta = list.tail;

    for (int i = 0; i < R; i++) {
        long long X, Y;
        cin >> X >> Y;

        long long langkah_alpha = X % (long long)list.size;
        for (long long j = 0; j < langkah_alpha; j++) {
            alpha = alpha->next;
        }

        long long langkah_beta = Y % (long long)list.size;
        for (long long j = 0; j < langkah_beta; j++) {
            beta = beta->prev;
        }
        if (alpha == beta) {
            Node* next_node = alpha->next;
            Node* prev_node = alpha->prev;

            prev_node->next = next_node;
            next_node->prev = prev_node;

            if (alpha == list.head) list.head = next_node;
            if (alpha == list.tail) list.tail = prev_node;
            
            delete alpha;
            list.size--;
            alpha = next_node;
            beta = prev_node;
            if (list.size == 0) {
                break;
            }
        } else if ((alpha->next == beta && beta != list.head) || (beta->next == alpha && alpha != list.head)) {
            char temp = alpha->data;
            alpha->data = beta->data;
            beta->data = temp;
        } 
    } 
    if(!list.is_empty()) {
        list.head->prev = nullptr;
        list.tail->next = nullptr;
    }
    if (list.is_empty()) {
        cout << "EMPTY" << endl;
    } else {
        Node* curr = list.head; 
        for (int i = 0; i < list.size; i++) {
            cout << curr->data;
            curr = curr->next;
        }
        cout << endl;
    }
    return 0;
}