#include "double_linked_list.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void DoubleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {
    return size == 0;
}

void DoubleLinkedList::add_front(char val) {
    Node* new_node = new Node;
    new_node->data = val;

    if (is_empty()) {
        head = tail = new_node;
        new_node->prev = nullptr;
        new_node->next = nullptr;
    } else {
        new_node->prev = tail;
        new_node->next = head;
        head->prev = new_node;
        tail->next = new_node;
        head = new_node;
    }   
    size++;
}

void DoubleLinkedList::add_back(char val) {
    Node* new_node = new Node;
    new_node->data = val;

    if (is_empty()) {
        head = tail = new_node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
    } else {
        new_node->prev = tail;
        new_node->next = head;
        tail->next = new_node;
        head->prev = new_node;
        tail = new_node;
    }
    size++;
}

void DoubleLinkedList::add_idx(char val, int idx) {
    if (idx < 0 || idx > size) {
        return;
    }
    if (idx <= 0) {
        add_front(val);
    } else if (idx >= size) {
        add_back(val);
    } else {    
        Node* new_node = new Node;
        new_node->data = val;
        Node* curr = head;

        for (int i = 0; i < idx - 1; i++) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        new_node->prev = curr;
        curr->next->prev = new_node;
        curr->next = new_node;
        size++;
    }
}

void DoubleLinkedList::delete_front() {
    if (is_empty()){
        return;
    }else if    (size == 1) {
        Node* temp = head;
        delete temp;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
    size--;
}

void DoubleLinkedList::delete_back() {
    if (is_empty()) {
        return;
    } else if (size == 1) {
        Node* temp = head;
        delete temp;
        head = tail = nullptr;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;   
    }
    size--;
}

void DoubleLinkedList::delete_idx(int idx) {
    if (is_empty() || idx < 0 || idx >= size) {
        return;
    }
    if (idx == 0) {
        delete_front();
    } else if (idx == size - 1) {
        delete_back();
    } else {
        Node *curr = head;
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;
    }
}

void DoubleLinkedList::display() {
    if (is_empty()){
        std::cout << "List kosong" << std::endl;
    } else {
        Node *curr = head;
        for (int i = 0; i < size; i++) {
            std::cout << curr->data;
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}

char DoubleLinkedList::get(int idx){
    if (is_empty()) {
        throw std::out_of_range("List is empty");
    }
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    if (idx == 0) {
        return head->data;
    } else if (idx == size - 1) {
        return tail->data;
    } else {
        Node *curr = head;
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
        return curr->data;
    }
}

void DoubleLinkedList::set(char val, int idx){
    if (is_empty()) {
        throw std::out_of_range("List is empty");
    }
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    if (idx == 0) {
       head->data = val;
    } else if (idx == size - 1) {
        tail->data = val;
    } else {
        Node *curr = head;
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
        curr->data = val;
    }
}

void DoubleLinkedList::clear(){
    while (!is_empty()) {
        delete_front();
    }
}