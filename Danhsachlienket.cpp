#include <iostream>
#include <iomanip>
#include <math.h>
#include <Windows.h>
#include <string.h>
#include <string>
#define max 100
#define pi 3.14
using namespace std;

struct node
{
    int data;
    struct node *pNext;
};
typedef struct node NODE;

struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list li;

void khoitao(li &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE *khoitaonode(int x)
{
    NODE *p = new NODE;
    if(p == 0)
    {
        cout <<"Khong du bo nho de cap phat cho gia tri.\n";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

void themvaodau(li &l, NODE *p)
{
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void themvaocuoi(li &l, NODE *p)
{
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void xuat(li l)
{
    for(NODE *k = l.pHead; k != NULL; k = k->pNext)
    {
        cout << k->data << "  ";
    }
}

void thempsauq(li &l, NODE *p)
{
    int x1;
    cout <<"Nhap gia tri node q: "; cin >> x1;
    NODE *q = khoitaonode(x1);

    if(q->data == l.pHead->data && l.pHead->pNext == NULL)
    {
        themvaocuoi(l,p);
    }
    else
    {
        for(NODE *k = l.pHead; k != NULL; k = k->pNext)
        {
            if(q->data == k->data)
            {
                NODE *h = khoitaonode(p->data);
                NODE *g = k->pNext;
                h->pNext = g;
                k->pNext = h;
            }
        }
    }
}

int main()
{
    li l;
    khoitao(l);
    int n;
    cout <<"Nhap so gia tri: "; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cout <<"Nhap x: ";
        cin >> x;
        NODE *e = khoitaonode(x);
        themvaocuoi(l,e);
    }
    xuat(l);
    int x2;
    cout <<"\nNhap gia tri nut p can them vao sau: "; cin >> x2;
    NODE *p = khoitaonode(x2);
    thempsauq(l,p);
    xuat(l);
}
