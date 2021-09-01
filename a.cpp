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
// Bài 702: Tính S(n) = 1 + 2 + 3 + … + n
// Bài 703: Hãy cài đặt hàm đệ quy tính T(n) = n! = 1 x 2 x 3 x … x n. Trong đó T(0) = 1
// Bài 704: Cho mảng 1 chiều các số nguyên. Viết hàm tính tổng các số chẵn trong mảng bằng phương pháp đệ quy
// Bài 705: Cho mảng 1 chiều các số nguyen. Viết hàm đếm số lượng giá trị dương trong mảng bằng phương pháp đệ quy
}

void nhap(int a[], int &n)
{
    do
    {
        cout << "Nhap n: "; cin >> n;
        if(n < 0 || n > max)
            cout <<"Nhap lai n.\n";
    } while (n < 0 || n > max);
    for(int i = 0; i < n; i++)
    {
        cout <<"a[" << i <<"] = ";
        cin >> a[i];
    }    
}

void xuat(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] <<"  ";
    }
    cout << "\n\n";
}

int tong(int n) //bai 702
{
    if(n == 0)
        return 0;
    return tong(n - 1) + n;
}

int giaithua(int n)
{
    if(n == 0)
        return 1;
    return giaithua(n - 1) * n;
}

int tongchan(int a[], int n)    //Bai 704
{
    if(n == 0)
        return 0;
    if(a[n - 1] % 2 == 0)
        return tongchan(a,n - 1) + a[n - 1];
    return tongchan(a,n - 1);
}

int demduong(int a[], int n)
{
    if(n == 0)
        return 0;
    if(a[n - 1] > 0)
        return 1 + demduong(a,n - 1);
    return demduong(a, n - 1);
}

int main()
{
    int a[max];
    int n,n1,n2;

    cout <<"Bai 702: \n";
    cout <<"Nhap so gia tri: "; cin >> n1;
    cout <<"Tong cac gia tri: " << tong(n1) << "\n\n";

    cout <<"Bai 703: \n";
    cout <<"Nhap so gia tri can tinh: "; cin >> n2;
    cout <<"Gia thua cua cac gia tri: " << giaithua(n2) << "\n\n";

    cout <<"Bai 704, 705: \n";
    nhap(a,n);
    xuat(a,n);

    cout <<"Tong chan: " << tongchan(a,n) << endl;
    cout <<"Tong so cac so duong: " << demduong(a,n) << endl;
    return 0;
}
