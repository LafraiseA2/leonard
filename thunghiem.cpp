#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>
#include <ctime>
#define max 100
// Bài 378: Tìm 1 chữ số xuất hiện nhiều nhất
using namespace std;

void nhap(int a[][max], int &dong, int &cot)
{
    do
    {
        cout <<"Nhap so dong: "; cin >> dong;
        if(dong < 0 || dong > max)
            cout <<"Nhap lai dong.\n";
    } while (dong < 0 || dong > max);
    do
    {
        cout <<"Nhap so cot: "; cin >> cot;
        if(cot < 0 || cot > max)
            cout <<"Nhap lai cot.\n";
    } while (cot < 0 || cot > max);
    for(int i = 0; i < dong; i++)
    {
        for(int j = 0; j < cot; j++)
        {
            cout <<"a[" << i <<"][" << j <<"]: ";
            cin >> a[i][j];
        }
    }    
}

void xuat(int a[][max], int dong, int cot)
{
    for(int i = 0; i < dong; i++)
    {
        for(int j = 0; j < cot; j++)
        {
            cout << a[i][j] <<"     ";
        }
        cout <<"\n";
    }
}

void tachso(int a, int b[])
{
    int chuso;
    a = abs(a);
    do
    {
        chuso = a % 10;
        b[chuso]++;
        a /= 10;
    } while (a > 0);
    
}

int nhieunhat(int a[][max], int dong, int cot)
{
    int b[10] = {0};
    for(int i = 0; i < dong; i++)
    {
        for(int j = 0; j < cot; j++)
        {
            tachso(a[i][j], b);
        }
    }
    int chusonhieunhat = 0;
    for(int i = 0; i < 10; i++)
    {
        if(b[chusonhieunhat] < b[i])
            chusonhieunhat = i;
    }

    return chusonhieunhat;
}
int main()
{
    int a[max][max];
    int dong, cot;
    nhap(a,dong,cot);
    xuat(a,dong,cot);
    cout <<"Chu so xuat hien nhieu nhat la: " << nhieunhat(a, dong,cot);
    return 0;
}