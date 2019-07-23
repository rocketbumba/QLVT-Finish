#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLIST 500
//List *hd;
//CreateList(hd);

struct infortree
{
	char MAVT[10];
	char TENVT[20];
	char DVT[20];
	int slt;//
};typedef infortree Infortree;
struct nodetree 
{	
	Infortree Iphone;
	struct nodetree *pRight;
	struct nodetree *pLeft; 
};typedef struct nodetree Nodetree;
typedef struct nodetree *Tree;
struct cthd
{
	char MAVT[10];
	double soluong;
	float dongia;
	float vat;
};typedef struct cthd Cthd;
struct date
{
	int ngay;
	int thang;
	int nam;
};typedef struct date Date;
//struct listcthd
//{
//	int n;
//	Cthd nodesCthd[20];
//};typedef listcthd Lcthd;
struct hoadon
{
	Date _Date;
	char SHD[20];
	char kind[5];
	Cthd *_Cthd=NULL;
	int soluongvattu;
};typedef hoadon HD;
struct dshoadon
{	
	HD _Hd;
	//\Lcthd _Lcthd;
	struct dshoadon *pNext;
};typedef dshoadon Ldshd;
struct nhanvien
{
	char MANV[15];
	char HO[50];
	char TEN[10];
	char SEX[5];
	Ldshd *_hd;
};typedef nhanvien Nhanvien;
Nhanvien *NV[300];
int soluongnv;



