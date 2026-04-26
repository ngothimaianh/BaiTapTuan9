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
    
