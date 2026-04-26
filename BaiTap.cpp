#include <iostream>
#include <string.h>
using namespace std;
// Khai báo cấu trúc dữ liệu
struct Ngay {
    int ngay, thang, nam;
};
struct SinhVien{
    char maSV[8];
    char HoTen[50];
    int GioiTinh;
    Ngay NgaySinh;
    char DiaChi[100];
    char Lop[12];
    char Khoa[7];
};
struct Node{
    SinhVien data;
    Node *link;
};
struct List{
    Node *dau;
    Node *cuoi;
};
void DanhSachRong(List &l){
    l.dau = l.cuoi = NULL;

}
Node* TaoNodeMoi(SinhVien x){
    Node *p = new Node;
    if (p = NULL) return NULL;
    p ->data = x;
    p ->link= NULL;
    return p;
}
void XoaBoNhoDem() {
    char c;
    while (cin.get(c) && c != '\n');
}
// so sánh chuỗi
int SoSanhChuoi(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] > s2[i]) return 1;
        if (s1[i] < s2[i]) return -1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') return 0;
    return (s1[i] == '\0') ? -1 : 1;
}
void NhapChuoi(char s[], int DoDaiMax) {
    char c;
    int i = 0;
    while (i < DoDaiMax - 1) {
        cin.get(c); 
        if (c == '\n') break; 
        s[i] = c;
        i++;
    }
    s[i] = '\0';
}
// Chen vao danh sach co thu tu
void ChenDanhSach(List &l, SinhVien x){
    Node *p = TaoNodeMoi(x);
    if(p == NULL) return;
       if (l.dau == NULL || SoSanhChuoi(p ->data.maSV, l.dau->data.maSV) == -1){
p ->link = l.dau;
l.dau = p;
if (l.cuoi == NULL) l.cuoi = p;
return;}
Node *truoc = l.dau;
while (truoc->link != NULL && SoSanhChuoi(p->data.maSV, truoc->link->data.maSV) == 1){
    truoc = truoc ->link;

}
p->link = truoc ->link;
truoc-> link = p;
if (p-> link == NULL) {
    l.cuoi = p;
}
       }
 void NhapMotSV(SinhVien &sv) {
    cout << "Nhap Ma SV: "; 
    cin >> sv.maSV;
    XoaBoNhoDem(); 

    cout << "Nhap Ho Ten: "; 
    NhapChuoi(sv.HoTen, 50);

    cout << "Nhap Gioi Tinh (0:Nam, 1:Nu): "; 
    cin >> sv.GioiTinh;

    cout << "Nhap Ngay, Thang, Nam sinh: ";
    cin >> sv.NgaySinh.ngay >> sv.NgaySinh.thang >> sv.NgaySinh.nam;
    XoaBoNhoDem();

    cout << "Nhap Dia chi: "; 
    NhapChuoi(sv.DiaChi, 100);

    cout << "Nhap Lop: "; 
    cin >> sv.Lop;

    cout << "Nhap Khoa: "; 
    cin >> sv.Khoa;
}

void XuatDanhSach(List l) {
    cout << "\n--- DANH SACH SINH VIEN (TANG DAN THEO MA SV) ---\n";
    Node *p = l.dau;
    while (p != NULL) {
        cout << p->data.maSV << " | " << p->data.HoTen << " | " 
             << p->data.NgaySinh.ngay << "/" << p->data.NgaySinh.thang << "/" << p->data.NgaySinh.nam 
             << " | Lop: " << p->data.Lop << endl;
        p = p->link;
    }
}

    
