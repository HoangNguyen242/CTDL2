#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
	int data; // du lieu cua node
	struct Node *pLeft;
	struct Node *pRight;
};
typedef struct Node NODE;
typedef NODE* TREE;

// khoi tao cay
void KhoiTaoCay(TREE &t)
{
	t = NULL;
};
void ThemPhanTu(TREE &t, int x)
{
	if(t == NULL)
	{
		NODE *p = new NODE; //khoi tao 1 node de them vao cay
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		// Neu phan tu them vao nho hon node goc => them vao ben trai
		if(t->data > x)
		{
			ThemPhanTu(t->pLeft,x);
		}
		else if(t->data < x) // Neu phan tu them vao nho hon node goc => them vao ben phai
		{
			ThemPhanTu(t->pRight,x);
		}
	}
};
//Ham xuat cay nhi phan NODE LEFT RIGT
void Duyet_NLR(TREE t)
{
	//Neu cay con phan tu thi tiep tuc duyet
	if(t!=NULL)
	{
		cout<<t->data<<" ";//xuat du lieu trong node
		Duyet_NLR(t->pLeft);//duyet qua trai
		Duyet_NLR(t->pRight);//duyet qua phai
	}
}
void Menu(TREE &t)
{
	while(true)
	{
		cout<<"\t\tMENU\n";
		cout<<"1. Nhap"<<endl;
		cout<<"2. Xuat"<<endl;
		cout<<"0. Thoat"<<endl;
		int luachon;
		cout<<"Ban chon: ";
		cin >> luachon;
		switch(luachon)
		{
			case 1:
				{
					int x;
					cout<<"Nhap so nguyen: ";
					cin>>x;
					ThemPhanTu(t,x);
					break;
				}
			case 2:
				{
					cout<<"Duyet cay theo NLR: "<<endl;
					Duyet_NLR(t);
					break;
				}
			case 0:
				exit(0);
		}
	}
}
int main()
{
	TREE t;
	KhoiTaoCay(t);
	Menu(t);
	return 0;
}