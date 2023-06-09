#include <iostream>

// Membuat struktur node
struct Node {
    int data;       // Data pada node
    Node* prev;     // Pointer ke node sebelumnya
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
    
    // Mengatur pointer prev node baru ke nullptr karena akan menjadi head
    newNode->prev = nullptr;
    
    // Mengatur pointer prev head saat ini ke node baru
    if (*head != nullptr)
        (*head)->prev = newNode;
    
    // Mengatur head menjadi node baru
    *head = newNode;
}

// Fungsi untuk mencetak linked list maju
void cetakListMaju(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Fungsi untuk mencetak linked list mundur
void cetakListMundur(Node* node) {
    // Mencari tail atau simpul terakhir
    while (node->next != nullptr) {
        node = node->next;
    }
    
    // Mencetak elemen dari tail ke head
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->prev;
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
    
    // Mencetak linked list maju
    cetakListMaju(head);
    
    // Mencetak linked list mundur
    cetakListMundur(head);
    
    return 0;
}
