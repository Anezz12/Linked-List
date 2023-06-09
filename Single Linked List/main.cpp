#include <iostream>

// Membuat struktur node
struct Node {
    int data;       // Data pada node
    Node* next;     // Pointer ke node berikutnya
};

// Fungsi untuk menambahkan node baru di awal linked list
void tambahNode(Node** head, int newData) {
    // Mengalokasikan memori untuk node baru
    Node* newNode = new Node();
    
    // Menyimpan data pada node baru
    newNode->data = newData;
    
    // Mengatur pointer next node baru ke head saat ini
    newNode->next = *head;
    
    // Mengatur head menjadi node baru
    *head = newNode;
}

// Fungsi untuk mencetak linked list
void cetakList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    // Inisialisasi head sebagai null
    Node* head = nullptr;
    
    // Menambahkan node-node baru
    tambahNode(&head, 3);
    tambahNode(&head, 7);
    tambahNode(&head, 9);
    
    // Mencetak linked list
    cetakList(head);
    
    return 0;
}
