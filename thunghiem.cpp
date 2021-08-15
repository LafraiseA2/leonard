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

int main()
{
    int a[][max];
    int n;
    nhap(a,n);
}
