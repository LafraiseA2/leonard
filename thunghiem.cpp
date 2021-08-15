#include <iostream>
#include <iomanip>
#include <cmath>
#define max 100
using namespace std;
/* Bài 250: Hảy cho biết các phần tử trong mảng có lập thành cấp số cộng hay không? Nếu có chỉ ra công sai d*/

void nhap(int a[], int &n)      // Khai bao nhap mang
{
    do
    {
        cout <<"Nhap n: "; cin >> n;
        if(n < 0 || n > max)
            cout << "Nhap lai n.\n ";
    } while (n < 0 || n > max);
    
    for(int i = 1; i <= n; i++)     //Nhap cac bien trong mang
    {
        cout <<"a[" << i << "]: ";
        cin >> a[i];
    }
}

int capsocong(int a[], int n)
{
    int d = a[2] - a[1];
    for(int i = 2; i < n; i++)
    {
        if(a[i + 1] - a[i] != d)
            return 0;
    }
    return 1;
}
int main()
{
    int a[max];
    int n;
    nhap(a,n);
    // Xuat ket qua
    cout << capsocong(a,n);
}