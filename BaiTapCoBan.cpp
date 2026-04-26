#include <iostream>
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
    if (p == NULL) return NULL;
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
void SaoChepChuoi(char dich[], char nguon[]) {
    int i = 0;
    while (nguon[i] != '\0') {
        dich[i] = nguon[i];
        i++;
    }
    dich[i] = '\0'; // Kết thúc chuỗi bằng ký tự rỗng
}
void GanSV(SinhVien &sv, char ma[], char ten[], int gt, int d, int m, int y, char lp[]) {
    SaoChepChuoi(sv.maSV, ma);
    SaoChepChuoi(sv.HoTen, ten);
    sv.GioiTinh = gt;
    sv.NgaySinh.ngay = d;
    sv.NgaySinh.thang = m;
    sv.NgaySinh.nam = y;
    SaoChepChuoi(sv.Lop, lp);
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

// 3.In sinh viên cùng ngày sinh
bool TrungNgaySinh(Ngay n1, Ngay n2) {
    return (n1.ngay == n2.ngay && n1.thang == n2.thang && n1.nam == n2.nam);
}
void SinhVienCungNgaySinh(List l) {
    bool TimThay = false;
    cout << "\nCAC SINH VIEN CO CUNG NGAY SINH\n";

    for (Node *p = l.dau; p != NULL; p = p->link) {
        bool trung = false;
        for (Node *q = l.dau; q != NULL; q = q->link) {
            if (p != q && TrungNgaySinh(p->data.NgaySinh, q->data.NgaySinh)) {
                trung = true;
                break;
            }
        }
        

        if (trung) {
            cout << p->data.maSV << " | " << p->data.HoTen << " | " 
                 << p->data.NgaySinh.ngay << "/" << p->data.NgaySinh.thang << "/" << p->data.NgaySinh.nam << endl;
            TimThay = true;
        }
    }
    

    if (!TimThay) {
        cout << "Khong tim thay sinh vien cung ngay sinh" << endl;
    }
}
//4. Loại bỏ sinh viên có cùng ngày sinh
bool KiemTraCoTrung(List l, Node* k) {
    for (Node *p = l.dau; p != NULL; p = p->link) {
        if (p != k && TrungNgaySinh(p->data.NgaySinh, k->data.NgaySinh))
            return true;
    }
    return false;
}

void XoaSVTrungNgaySinh(List &l) {
    Node *ht = l.dau;
    Node *truoc = NULL;

    while (ht != NULL) {
        if (KiemTraCoTrung(l, ht)) {
            Node *temp = ht;
            if (truoc == NULL) { 
                l.dau = ht->link;
                ht = l.dau;
            } else {
                truoc->link = ht->link;
                ht = truoc->link;
            }
            
            if (ht == NULL) l.cuoi = truoc;
            
            delete temp; // Giải phóng bộ nhớ
        } else {
            truoc = ht;
            ht = ht->link;
        }
    }
    cout << "\nDa loai bo cac sinh vien co cung ngay sinh." << endl;
}
int main() {
    List l; DanhSachRong(l);
    SinhVien s1, s2, s3;
    
    // Bây giờ việc tạo dữ liệu chỉ mất 1 dòng mỗi người
    GanSV(s1, "20241111", "Nguyen Van Vinh", 0, 19, 7, 2006, "ET1");
    ChenDanhSach(l, s1);

    GanSV(s2, "20241112", "Tran Thi Binh", 1, 19, 7, 2006, "ET1");
    ChenDanhSach(l, s2);

    GanSV(s3, "20241113", "Le Van Chau", 0, 20, 5, 2005, "ET1");
    ChenDanhSach(l, s3);

    XuatDanhSach(l);
    SinhVienCungNgaySinh(l);
    XoaSVTrungNgaySinh(l);
    XuatDanhSach(l);
    return 0;
}
