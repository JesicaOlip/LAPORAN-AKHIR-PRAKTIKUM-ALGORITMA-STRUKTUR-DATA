#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void SingleLinkedList::init(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty(){
    return size == 0;
}

void SingleLinkedList::add_front(int val){
    Node *new_node = new Node;
    new_node->data = val;
    new_node->next = nullptr;

    if (is_empty()){
        head = tail = new_node;
        tail->next = head;
    } else {
        new_node->next = head;
        head = new_node;
        tail->next = new_node;
    }
    size++;
}

void SingleLinkedList::add_back(int val){
    Node *new_node = new Node;
    new_node->data = val;
    new_node->next = head;

    if (is_empty()){
        head = tail = new_node;
        tail->next = head;
    } else {
        tail->next = new_node;
        tail = new_node;
        new_node->next = head;  
    }
    size++;
}

void SingleLinkedList::add_idx(int val, int idx){
    if (idx < 0 || idx > size) {
        throw std::out_of_range("Index out of bounds");
    }
    if (idx == 0) {
        add_front(val);
    } else if (idx == size) {
        add_back(val);
    } else {
        Node *new_node = new Node;
        new_node->data = val;
        Node *curr = head;

        for (int i = 0; i < idx - 1; i++) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
        size++;
    }
}

void SingleLinkedList::delete_front(){
    if (is_empty()){
        throw std::out_of_range("List is empty");
    } else if (size == 1){
        delete head;
        head = tail = nullptr;
    } else {
        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    size--;
}

void SingleLinkedList::delete_back(){
    if (is_empty()){
        throw std::out_of_range("List is empty");
    } else if (size == 1){
        delete head;
        head = tail = nullptr;
    } else {
        Node *curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }
        delete tail;
        tail = curr;
        tail->next = head;
    }
    size--;
}

void SingleLinkedList::delete_idx(int idx){
    if (is_empty()){
        throw std::out_of_range("list is empty");
    }
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    if (idx == 0) {
        delete_front();
    } else if (idx == size - 1) {
        delete_back();
    } else {
        Node *curr = head;
        for (int i = 0; i < idx - 1; i++) {
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }
}

void SingleLinkedList::display(){
    if (is_empty()){
        std::cout << "List kosong" << std::endl;
    } else {
        Node *curr = head;
        for (int i = 0; i < size; i++) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}

int SingleLinkedList::get(int idx){
    if (is_empty()) {
        throw std::out_of_range("list is empty");
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

void SingleLinkedList::set(int val, int idx){
    if (is_empty()) {
        throw std::out_of_range("list is empty");
    }
    if (idx < 0 || idx >= size) throw std::out_of_range("index out of range");
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

void SingleLinkedList::clear(){
    while (!is_empty()) {
        delete_front();
    }
}