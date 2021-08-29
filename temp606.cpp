#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <time.h>
#define max 100
#define pi 3.14
#define minyear 1800
#define maxyear 10000
using namespace std;

// Bài 593: Khai báo kiểu dữ liệu để biểu diễn ngày
// Bài 594: Nhập ngày
// Bài 595: Xuất ngày theo định dạng (ng/th/nm)
// Bài 596: Kiểm tra năm nhuận
// Bài 597: Tính số thứ tự ngày trong năm
// Bài 598: Tính số thứ tự ngày kể từ ngày 1/1/1
// Bài 599: Tìm ngày khi biết năm và số thứ tự của ngày trong năm
// Bài 600: Tìm ngày khi biết số thứ tự ngày kể từ ngày 1/1/1
// Bài 601: Tìm ngày kế tiếp
// Bài 602: Tìm ngày hôm qua
// Bài 603: Tìm ngày kế đó k ngày
// Bài 604: Tìm ngày trước đó k ngày
// Bài 605: Khoảng cách giữa 2 ngày
// Bài 606: So sánh 2 ngày
// Tính thứ của ngày bất kỳ trong năm(Dùng CT Zeller)

struct ngaythang{
    int ngay;
    int thang;
    int nam;
};
typedef struct ngaythang nt;

bool kiemtranhuan(ngaythang a)
{
    return (a.nam % 4 == 0 && a.nam % 100 != 0) || (a.nam % 400 == 0);
}

bool kiemtranhuan2(int i)
{
    if(i % 4 == 0 && i % 100 != 0 || i % 100 == 0)
        return true;
    return false;
}
int songaytrongthang(nt a)
{
    int songay;
    switch(a.thang)
    {
        case 1:case 3:case 5:case 7: case 8: case 10: case 12:
            songay = 31;
            break;
        case 4:case 6: case 9:case 11: 
            songay = 30;
            break;
        case 2:
            int check = kiemtranhuan(a);
            if(check == 1)
                songay = 29;
            else
                songay = 28;
    }
    return songay;
}
// Bài 594: Nhập ngày
void nhap(nt &a)
{
    do
    {
        cout <<"Nhap nam: "; cin >> a.nam;
        if(a.nam < minyear || a.nam > maxyear)
            cout <<"Nhap lai nam.\n";
    } while (a.nam < minyear || a.nam > maxyear);
    do
    {
        cout <<"Nhap thang: "; cin >> a.thang;
        if(a.thang < 1 || a.thang > 12)
            cout <<"Nhap lai thang.\n";
    } while (a.thang < 1 || a.thang > 12);
    
    int songay = songaytrongthang(a);
    do
    {
        cout <<"Nhap ngay: "; cin >> a.ngay;
        if(a.ngay < 1 || a.ngay > songay)
            cout <<"Nhap lai so ngay.\n";
    } while (a.ngay < 1 || a.ngay > songay);
        
}

// Bài 595: Xuất ngày theo định dạng (ng/th/nm)
void xuat(nt a, int n)
{
    if(n == 0)
        cout <<"Ngay da nhap: " << a.ngay << "/" << a.thang << "/" << a.nam << "\n\n";
    else cout << a.ngay << "/" << a.thang << "/" << a.nam << "\n\n";    //Tu nhap yeu cau phia truoc
}
// Bài 596: Kiểm tra năm nhuận  //bai tren
// Bài 597: Tính số thứ tự ngày trong năm
float sothuthu(nt a)
{
    int S = a.ngay;
    int check = kiemtranhuan(a);
    for(int i = 1; i < a.thang; i++)
    {
        switch(i)
        {
            case 4:case 6:case 9: case 11: 
                S+= 30;
                break;
            case 2:
                S += check == 1 ? 29 : 28;
                break;
            default: S+= 31;

        }
    }
    return S;
}

// Bài 598: Tính số thứ tự ngày kể từ ngày 1/1/1
float songaytinhtungaychotruoc(nt a)
{
    int check = kiemtranhuan(a);
    float S = sothuthu(a);
    for(int i = 1; i < a.nam; i++)
    {
        if(check == 1)
            S += 366;
        else S+= 365;
    }
    return S;
}

// Bài 599: Tìm ngày khi biết năm và số thứ tự của ngày trong năm
ngaythang timngay(int n, int nam)
{
    nt d;
    int STT = n,thang;
    int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (kiemtranhuan2(nam))
        a[1] = 29;
    for(int i = 0; i < 12;i++)
    {
        if(a[i] < STT)
        {
            STT -= a[i];
        }
        else
        {
            thang = i + 1;
            break;
        }
    }    
    d.ngay = STT;
    d.nam = nam;
    d.thang = thang;
    return d;    
}

// Bài 600: Tìm ngày khi biết số thứ tự ngày kể từ ngày 1/1/1
// Tuong tu bai tren
// Bài 601: Tìm ngày kế tiếp
ngaythang ngayketiep(nt a)
{
    if(a.ngay < songaytrongthang(a))
    {
        a.ngay++;
    }
    else if(a.thang < 12)
    {
        a.ngay = 1;
        a.thang++;
    }
    else
    {
        a.ngay = 1;
        a.thang = 1;
        a.nam++;
    }
    return a;
}

// Bài 602: Tìm ngày hôm qua
ngaythang homqua(nt a)
{
    if(a.ngay > 1)
    {
        a.ngay--;
    }
    else if(a.thang > 1) //ngay bang 1
    {
        a.thang--;
        a.ngay = songaytrongthang(a);        
    }
    else
    {
        a.ngay = 31;
        a.thang = 12;    //thang = 1
        a.nam--;
    }
    return a;
}

// Bài 603: Tìm ngày kế đó k ngày(tuong duong tim ngay ke tiep k lan)
ngaythang ngayketiepk(nt a, int k)
{
    nt b;
    while(k > 0)
    {
        b = ngayketiep(a);
        k--;
    }
    return b;
}
// Bài 604: Tìm ngày trước đó k ngày
// Bài 605: Khoảng cách giữa 2 ngày
// Bài 606: So sánh 2 ngày
// Tính thứ của ngày bất kỳ trong năm(Dùng CT Zeller)

int main()
{
    nt a;
    nt b;
}
