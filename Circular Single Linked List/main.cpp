#include <iostream>

// Membuat struktur node
struct Node {
    int data;       // Data pada node
    Node* next;     // Pointer ke node berikutnya
};

// Fungsi untuk menambahkan node baru ke dalam linked list
void tambahNode(Node** head, int newData) {
    // Mengalokasikan memori untuk node baru
    Node* newNode = new Node();
    
    // Menyimpan data pada node baru
    newNode->data = newData;
    
    if (*head == nullptr) {
        // Jika linked list masih kosong, maka node baru akan menjadi head dan menunjuk ke dirinya sendiri
        newNode->next = newNode;
        *head = newNode;
    } else {
        // Jika linked list tidak kosong, maka node baru akan menjadi tail dan menunjuk ke head
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        *head = newNode;    // Mengatur node baru sebagai head baru
    }
}

// Fungsi untuk mencetak linked list
void cetakList(Node* head) {
    if (head != nullptr) {
        Node* current = head->next;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head->next); // Melakukan iterasi sampai kembali ke node awal
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
