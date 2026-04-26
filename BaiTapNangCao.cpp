#include <iostream>
using namespace std;

// Cấu trúc một người trong vòng tròn
struct Node {
    int so;
    Node* next;
};

// Hàm tạo Node mới
Node* TaoNodeMoi(int gt) {
    Node* p = new Node;
    p->so = gt;
    p->next = NULL;
    return p;
}
int TimNguoiChienThang(int n, int m) {
    if (n == 1) return 1;

    // Tạo vòng tròn N người
    Node* dau = TaoNodeMoi(1);
    Node* ht = dau;
    for (int i = 2; i <= n; i++) {
        ht->next = TaoNodeMoi(i);
        ht = ht->next;
    }
    ht->next = dau; 

    Node* p = dau;       
    Node* truoc = ht;    

    while (p->next != p) { 
        for (int dem = 0; dem < m; dem++) {
            truoc = p;
            p = p->next;
        }

        truoc->next = p->next;
        Node* temp = p;
        p = truoc->next; 
        delete temp;
    }

    int NguoiChienThang = p->so;
    delete p; 
    return NguoiChienThang;
}

int main() {
    // Giả sử chọn N bất kỳ là 7
    int n = 7; 
    cout << " KIEM TRA BAI TOAN JOSEPHUS VOI N = " << n << " ---\n";

    // Kiểm tra với M = 1
    cout << "Voi M = 1: Nguoi chien thang la " << TimNguoiChienThang(n, 1) << endl;

    // Kiểm tra với M = 2
    cout << "Voi M = 2: Nguoi chien thang la " << TimNguoiChienThang(n, 2) << endl;

    // Kiểm tra với M = 3
    cout << "Voi M = 3: Nguoi chien thang la " << TimNguoiChienThang(n, 3) << endl;
//Thử với n rất lớn
    int nRatLon = 100005;
    cout << "\nKiem tra voi N lon, M = 1: ";
    cout << TimNguoiChienThang(nRatLon, 1) << endl;

    return 0;
}