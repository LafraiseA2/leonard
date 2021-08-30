#include <iostream>
#include <iomanip>
#include <math.h>
#include <Windows.h>
#include <string.h>
#include <string>
#define max 100
#define pi 3.14
using namespace std;

void debai(int a)
{
// Bài 609: Hãy khai báo kiểu dữ liệu để biểu diễn thông tin của 1 vé xem phim (VE). 
// Biết rằng 1 vé xem phim gồm những thành phần sau:
// Tên phim: Chuỗi tối đa 20 ký tự
// Giá tiền: kiểu số nguyên 4 byte
// Xuất chiếu: kiểu thời gian (THOIGIAN)
// Ngày xem: kiểu dữ liệu ngày (NGAY)
// Sau đó viết hàm nhập, xuất cho kiểu dữ liệu này
}

struct thoigian{
    int gio;
    int phut;
};
typedef struct thoigian tg;

struct ngay{
    int ngay;
    int thang;
    int nam;
};

struct vexemphim{
    string ten;
    int gia;
    thoigian time;
    ngay ngayxem;
};
typedef struct vexemphim ve;

bool kiemtranamnhuan(ngay a)
{
    return (a.nam % 4 == 0 && a.nam % 100 != 0) || (a.nam % 400 == 0);
}

int songay(ngay a)
{
    int sn;
    int check = kiemtranamnhuan(a);
    switch(a.thang)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            sn = 31;
            break;
        case 4: case 6: case 9: case 11:
            sn = 30;
            break;
        case 2:
            if(check == 1)
                sn = 29;
            else sn = 28;
            break;
    }
    return sn;
}

void nhapgio(thoigian &a)
{
    cout <<"Nhap gio: ";
    cin >> a.gio;
    cout <<"Nhap phut: ";
    cin >> a.phut;
}

void nhapthoigian(ngay &a)
{
    int sn = songay(a);
    do
    {
        cout <<"Nhap nam: "; cin >> a.nam;
        if(a.nam < 0 || a.nam > 10000)
            cout <<"Nhap lai nam.\n";
    } while (a.nam < 0 || a.nam > 10000);

    do
    {
        cout <<"Nhap thang: "; cin >> a.thang;
        if(a.thang < 1 || a.thang > 12)
            cout <<"Nhap lai thang.\n";
    } while (a.thang < 1 || a.thang > 12);
    
    do
    {
        cout << "Nhap ngay: "; cin >> a.ngay;
        if(a.ngay < 1 || a.ngay > sn)
            cout <<"Nhap lai ngay.\n";
    } while (a.ngay < 1 || a.ngay > sn);
    
}

void nhap(ve &a)
{
    cout <<"Nhap ten phim: ";
    getline(cin, a.ten);
    cout <<"Nhap gia ve: "; 
    cin >> a.gia;
    cout <<"Nhap gio xem phim: \n";
    nhapgio(a.time);
    cout <<"Nhap ngay chieu: \n";
    nhapthoigian(a.ngayxem);
}

void xuat(ve a)
{
    cout <<"Ten phim: " << a.ten << endl;
    cout <<"Gia ve: " << a.gia << endl;
    cout <<"Gio xem phim: " << a.time.gio <<" gio " << a.time.phut << " phut.\n";
    cout <<"Ngay chieu: " << a.ngayxem.ngay <<"/n" << a.ngayxem.thang <<"/" << a.ngayxem.nam << endl;
}

int main()
{
    ve a;
    cout <<"Nhap thong tin phim: \n";
    nhap(a);
    system("cls");
    xuat(a);
}
