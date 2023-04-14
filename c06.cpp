#include <iostream>
#include <algorithm>
#include <ranges>

struct Node {
    int data;
    Node* next;
};

bool add(Node*& head, int data) {
    Node* node = head;
    while (node != nullptr) {
        if (node->data == data) {
            return false;
        }
        node = node->next;
    }
    Node* new_node = new Node{ data, head };
    head = new_node;
    return true;
}

size_t size(const Node* head) {
    size_t count = 0;
    const Node* node = head;
    while (node != nullptr) {
        count++;
        node = node->next;
    }
    return count;
}

void clear(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        std::cout << "DEL: " << temp->data << " ";
        delete temp;
    }
}

void printList(const Node* head) {
    const Node* node = head;
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}



int main() {
    std::vector<int> v1 = {43, 2, 15};
    std::vector<int> v2 = {567, 12, 5645};

    std::cout << "Zadanie 1: " << std::endl;
    auto comparator = [](int x, int y) -> bool {
        return x % 10 < y % 10;
    };
    std::ranges::sort(v1, comparator);
    for (int val : v1) {
        std::cout << val << " ";
    }
    std::cout << '\n';

    std::cout << "Zadanie 2: " << std::endl;
    auto projekcja = [](int x) -> int {
        return x % 10;
    };
    std::ranges::sort(v1, {}, projekcja);
    for (int val : v2) {
        std::cout << val << " ";
    }
    std::cout << '\n';


    std::cout << "Zadanie 3: " << std::endl;
    int tab[] = {
            1, 4, 1, 3, 5
    };

    Node* head = 0;

    for (size_t i = 0, e = std::size(tab); i != e; i++) {
        bool b = add(head, tab[i]);
        std::cout << tab[i] << (b ? " " : " NOT ")
             << "added" << std::endl;
    }
    std::cout << "Size of the list: " << size(head) << std::endl;
    printList(head);
    clear(head);


    return 0;
}