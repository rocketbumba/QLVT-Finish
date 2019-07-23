using namespace std;
//#define _WIN32_WINNT 0x0500
#include<iostream>
#include"struct.h"
#include<string>
#include"graphs.h"
#include"input.h"
#include"console.h"
#include<ctime>
struct vattu
{
	Infortree nodes[100];
	int n;
};
typedef struct vattu Vattu;
struct sohd
{
	char SHD[20];

};typedef struct sohd Sohd;
struct listshd
{
	Sohd a[100];
	int n;
};typedef struct listshd List;
struct Hddate
{
	Date _date;
	char HO[50];
	char TEN[50];
	char SHD[20];
	char Kind[10];
	double trigia;
};typedef struct Hddate HDD;
struct listhdd
{
	HDD _hdd[100];
	int n;
};typedef struct listhdd Lhdd;
int nam_nhuan(int year)
{
    if (year % 100 == 0)
     
    {
        if (year % 400 == 0){
            return 0;
        }
        else{
           return 1;
        }
    }
    else if (year % 4 == 0) {
        return 0;
    }
    else{
        return 1;
    }
}
struct dssnv
{
	Nhanvien a[100];
	int n;
};typedef dssnv Dsnv;
Ldshd *CheckSHD1(Ldshd *p,char x[20])//DONE
{
	for(Ldshd *k=p;k!=NULL;k=k->pNext)
	{
		if(strcmp(k->_Hd.SHD,x)==0) return k;
		
	}
	 return NULL;
}
void ShowEmployee(int vitri)//DONE
{	
	printf("\n");
	printf(".==============================.==========.==========.=======================.\n");
	printf("|Ho                            |Ten       |Gioi tinh |Ma Nhan vien           |\n");
	printf("*==============================*==========*==========*=======================*\n");
	printf("|%-30s|%-10s|%-10s|%-23s|\n",NV[vitri]->HO,NV[vitri]->TEN,NV[vitri]->SEX,NV[vitri]->MANV);
	printf("==============================================================================");	
}
void ShowHdDATE(Lhdd l,int x,int y,int from,int to);
//===================================THUAT TOAN VATTU=======================================
void Intialize_Tree(Tree &t);//khoi tao cay
void InsertTree(Tree &t,Infortree &a);// them cay vao vi tri
void FindNodeReplace(Tree &x,Tree &y);//tim node thay the
void DeleteNodeTree(Tree &t,Infortree a);//xoa node cay
void WriteTreeIntoFile(FILE *f,Infortree a);//luu node cay vo file
void SaveFile(Tree t,FILE *f);//luu cay vo file
Nodetree *SearchNodeTree(Tree t,char a[]);//tim cay theo ma vat tu
void ReadDataFromFile(FILE *f,Infortree &a);//doc node cay tu file
void ReadPreorder(Tree &t,FILE *f);//doc cay tu fule preorder
void Swap(Infortree &a,Infortree &b);//doi cho 2 node cay
void OrderNameVattu(Vattu &a);// sap xep ten vat tu
void ShowSortName1(Nodetree *t);//show ra man hinh console
int SearchNodeTree1(Tree t,char a[]);//tim cay
int SearchHDMAVT(char x[10]);// TIM MA VAT TU NAY XUAT HOA DON CHUA
int SearchNodeTree12(Tree t,char a[]);//TIM MA VAT TU TRA VE SO NGUYEN


//=========================== DO HOA VAT TU==================================================

void ShowChayVattu(Vattu a);//IN RA MAN HINH CONSOLE VATTU
void ShowChayVattuHieuChinh(Vattu &a,Tree &t,Infortree &p,bool &esc1);//DUNG CAC PHIM DIEU KHIEN
void ShowrectVattu1(Vattu a,int x,int y,int from,int to);//
void ShowrectVattu(Vattu a,int x,int y,int from,int to);//
void FormMaVattuHieu(int x, int y, Infortree &tmp, bool &esc);// FORM DIEN MA VAT TU HIEU CHINH
void MenuHieuChinh(Vattu a,Nodetree *&t,Tree k,bool escvt);//MENU HIEU CHINH VAT TU
void FormVattu(int x, int y, Infortree &tmp, bool &esc,Tree t);//form dien vat tu
//void ShowSHDRect(HD a,int x,int y,Tree t);
Tree t;
//============================THUAT TOAN NHAN VIEN=============================================
void DeleteEmployee(int vitri);// XOA NHAN VIEN
void Swap1(Nhanvien *&a,Nhanvien *&b);// DOI CHO NHAN VIEN KHI SORT TEN
void OrderNameNV(Dsnv &nv);//SORT TEN THEO BUBBLE SORT
int FindEmployeeByCode(char x[15]);//TIM VI TRI NHAN VIEN THEO MA NHAN VIEN
int CheckNameNV(char a[15],char b[15]);//KIEM TRA TEN NHAN VIEN TRUNG HAY KHONG DE SORT HO
int CheckMNV(char a[15]);//KIEM TRA TRUNG MA NHAN VIEN
void SaveListNV();//LUU DU LIEU NHAN VIEN VO FILE
void ReadNvFromFile(FILE *f,Nhanvien *&a);//DOC 1 NHAN VIEN TU FILE
void ReadAllNV();//DOC TOAN BO NHAN VIEN TU FILE
void ShowEmployee(int vitri);//SHOW 1 NHAN VIEN THEO VI TRI NHAN VIEN DO

//============================ DO HOA NHAN VIEN=============================================

void FormNHANVIEN(int x, int y, Nhanvien *&tmp,bool esc,int &soluongnv);// FORM NHAP THONG TIN NHAN VIEN
void Showrect(Dsnv nv,int x,int y,int from,int to);//BANG THONG TIN NHAN VIEN
void FormMaNVHieu(int x, int y, Nhanvien &tmp, bool &esc);//FORM DIE MA NHAN VIEN HIEU CHINH
void MenuHieuChinhNV(int vitri);//BANG NHAN VIEN HIEU CHINH
void ShowChayNhanvienHieuChinh(bool &esc1,Dsnv nv);//BANG NHAN VIEN CO THEM HIEU CHINH
void ShowChay();//BANG THONG TIN NHAN VIEN KO CO HIEU CHINH

//===========================THUAT TOAN HOA DON=============================================
Ldshd *CheckSHD1(Ldshd *p,char x[20]);//KIEM TRA XEM SO HOA DON CO TRUNG HAY KHONG
void ShowHdDATE(Lhdd l,int x,int y,int from,int to);//XUAT HOA DON THEO NGAY
void InsertNodeLast1(Ldshd *&a,Ldshd *p);//THEM HOA DON VAO DANH SACH LIEN KET DON
void ReadHd();//DOC HOA DON TU FILE
void Copy1(List &Shd);//COPY SO HOA DON QUA MANG TUYEN TINH
void SaveCTHDFULL(FILE *f,Cthd a);//LUU 1 CHI TIET HOA DON VAO FILE
void SaveFileListHd();//LUU TOAN BO HOA DON VAO FILE
void SaveFileHd12();//LUU TOAN BO CHI TIET HOA DON VAO FILE
void ReadCTH(FILE *f,HD &temp,char x[20]);//DOC CHI TIET HOA DON
void Copy1(List &Shd);//COPY SO HOA DON QUA MANG LIST
int Sum(Cthd *a,int n);//TINH TONG DOANH THU
int CheckSHD(Ldshd *p,char x[20]);//kiem tra trung so hao don
Ldshd *Create(HD &a);
//===============================DO HOA HOA DON============================================

void ShowSHD(List a,int x,int y,int from,int to);//SHOW RA CAC SO HOA DON HIEN CO VA TRA CUU
void FormSoHoadon(int x, int y, HD &tmp,bool &esc);//NHAP VAO SO HOA DON CAN TRA CUU
void FormHoadon(int x, int y, HD &tmp, bool &esc,int &vitri,Tree tp);//FORM DIEN THONG TIN HOA DON
void ShowChaySHD(List a,Tree t);//BANG CHAY SO HOA DON CO TRA CUU
void ShowSHDRect(HD a,int x,int y,Tree t,int vitri);//XUAT RA HOA DON THEO NGAY
void ShowrectCTHD(Cthd *lc,int x,int y,int from,int to,Tree t);//BANG THONG TIN CHI TIET HOA DON
void MenuXuatHoaDon(Lhdd &l);//MENU TRA CUU NGAY
void ShowHdDATE(Lhdd l,int x,int y,int from,int to);//BANG THONG TIN HOA DON THEO NGAY
void ShowChayHDD(Lhdd a);//BANG THONG TIN HOA DON MA CO CHAY DC
//==========================================================================================

//=======================CAC HAM VAT TU==============================================
int SearchNodeTree1(Tree t,char a[])//DONE
{
	if(t==NULL)
	{
		//printf("Ko co ma vat tu");
		return 0;
	}
	else
	{
		if(strcmp(t->Iphone.MAVT,a)<0)
		{
			SearchNodeTree(t->pRight,a);
		}
		else if(strcmp(t->Iphone.MAVT,a)>0)
		{
			SearchNodeTree(t->pLeft,a);
		}
		else if(strcmp(t->Iphone.MAVT,a)==0) 
		{
			return 1;
		}
	}
}
void Intialize_Tree(Tree &t)//DONE
{
	t=NULL;
}
void InsertTree(Tree &t,Infortree &a)//DONE
{
	if(t==NULL)
	{
		Nodetree*p=new Nodetree;
		p->Iphone=a;
		p->pLeft=NULL;
		p->pRight=NULL;
		t=p;
	}    
	else
	{
		if(strcmp(t->Iphone.MAVT,a.MAVT)<0)
		{
			InsertTree(t->pRight,a);
		}
		else if(strcmp(t->Iphone.MAVT,a.MAVT)>0)
		{
			InsertTree(t->pLeft,a);
		}
		else if(strcmp(t->Iphone.MAVT,a.MAVT)==0)
		{
			printf("\nMa vat tu da bi trung xin moi nhap lai");
			system("pause");
		}
	}
}
void Preorder(Tree t)//DONE
{
	if(t!=NULL)
	{
		printf("========================================\n");
		printf("Ma vat tu la ");
		printf("%s\n",t->Iphone.MAVT);
		printf("Ten vat tu la ");
		printf("%s\n",t->Iphone.TENVT);
		printf("Don vi tinh vat tu ");
		printf("%s\n",t->Iphone.DVT);
		printf("So luong ton vat tu ");		
		printf("%d\n",t->Iphone.slt);
		printf("============================================\n");
		Preorder(t->pLeft);
		Preorder(t->pRight);
	}
}
void FindNodeReplace(Tree &x,Tree &y)//DONE
{
	if(y->pLeft!=NULL)
	{
		FindNodeReplace(x,y->pLeft);
	}
	else
	{
		x->Iphone=y->Iphone;
		x=y;
		y=y->pRight;
	}
}
void DeleteNodeTree(Tree &t,Infortree a)//DONE
{
	if(t==NULL)
	{
		printf("Ko co ma vat tu vua tim");
		printf("\nVui long an enter de nhap lai");
		system("pause");
		
		return;
	}
	else
	{
		if(strcmp(t->Iphone.MAVT,a.MAVT)<0)
		{
			DeleteNodeTree(t->pRight,a);
		}
		else if(strcmp(t->Iphone.MAVT,a.MAVT)>0)
		{
			DeleteNodeTree(t->pLeft,a);
		}
		else
		{
			Nodetree *x=t;
			if(t->pLeft==NULL)
			{
				t=t->pRight;
			}
			else if(t->pRight==NULL)
			{
				t=t->pLeft;
			}
			else
			{
			
				
					FindNodeReplace(x,t->pRight);
				
				
			}
			delete x;
		}
	}
}
void WriteTreeIntoFile(FILE *f,Infortree a)//DONE
{
	fprintf(f,"%s\n",a.TENVT);
	fprintf(f,"%s\n",a.MAVT);
	fprintf(f,"%s\n",a.DVT);
	fprintf(f,"%d\n",a.slt);
}
void SaveFile(Tree t,FILE *f)//DONE
{
	if(t!=NULL)
	{
		WriteTreeIntoFile(f,t->Iphone);
		SaveFile(t->pLeft,f);
		SaveFile(t->pRight,f);
	}
}
Nodetree *SearchNodeTree(Tree t,char a[])//DONE
{
	if(t==NULL)
	{
		//printf("Ko co ma vat tu");
		return NULL;
	}
	else
	{
		if(strcmp(t->Iphone.MAVT,a)<0)
		{
			SearchNodeTree(t->pRight,a);
		}
		else if(strcmp(t->Iphone.MAVT,a)>0)
		{
			SearchNodeTree(t->pLeft,a);
		}
		else if(strcmp(t->Iphone.MAVT,a)==0) 
		{
			return t;
		}
	}
}
int SearchNodeTree12(Tree t,char a[])//DONE
{
	if(t==NULL)
	{
		//printf("Ko co ma vat tu");
		return 0;
	}
	else
	{
		if(strcmp(t->Iphone.MAVT,a)<0)
		{
			SearchNodeTree(t->pRight,a);
		}
		else if(strcmp(t->Iphone.MAVT,a)>0)
		{
			SearchNodeTree(t->pLeft,a);
		}
		else if(strcmp(t->Iphone.MAVT,a)==0) 
		{
			return 1;
		}
	}
}
void ReadDataFromFile(FILE *f,Infortree &a)//DONE
{
	fgets(a.TENVT,15,f);
	strtok(a.TENVT,"\n");
	fgets(a.MAVT,10,f);
	strtok(a.MAVT,"\n");
	fgets(a.DVT,15,f);
	strtok(a.DVT,"\n");
	fscanf(f,"%4d\n",&a.slt);
}
void ReadPreorder(Tree &t,FILE *f)//DONE
{
	while(!feof(f))
	{
		Infortree a;
		ReadDataFromFile(f,a);
		InsertTree(t,a);
	}
}

void Preorder1(Tree t,int &i,Vattu &a)//DONE
{
	if(t!=NULL)
	{
		strcpy(a.nodes[i].MAVT,t->Iphone.MAVT);
		strcpy(a.nodes[i].TENVT,t->Iphone.TENVT);
		strcpy(a.nodes[i].DVT,t->Iphone.DVT);
		a.nodes[i].slt=t->Iphone.slt;
		a.n++;
		i++;
		Preorder1(t->pLeft,i,a);
		Preorder1(t->pRight,i,a);
	}
}
void Swap(Infortree &a,Infortree &b)//DONE
{
	Infortree temp=a;
	a=b;
	b=temp;
}

void ShowChayVattuHieuChinh(Vattu &a,Tree &t,Infortree &p,bool &esc1)//DONE
{
	THONGTIN:
	Vattu e;
	int f=0;
	e.n=0;
	Preorder1(t,f,e);
	OrderNameVattu(e);
	Cursor(false);	
	bool reload = true, press = false, move = false, esc = false;
	int from = 0, to = 10, cur = 0, page = 1;
	while(true){
		if (reload){
			//clearRect(GetConsoleWidth()/8,2,90,22);
			Clear();
			page = 1; from = 0; to = 5;
			reload = false;
			drawNumber(GetConsoleWidth()/3+5,GetConsoleHeight()/2-3,page,WHITE);		
			ShowrectVattu1(e,GetConsoleWidth()/8,2,from,to);			
		}
		if (move){
			clearRect(GetConsoleWidth()/8,2,92,22);
			move = false;
			ShowrectVattu1(e,GetConsoleWidth()/8,2,from,to);
			drawNumber(GetConsoleWidth()/3+5,GetConsoleHeight()/2-3,page,WHITE);
		}
		KeyPress_3(cur,from,to,page,a.n,reload,press,move,esc1);
		if(esc1)
		{
			//printf("%shuhu",p.MAVT);	
			return;
		}	
		if(press)
		{
			press=false;
			if(cur==1)
			{
				AGAIN1:
				Cursor(true);	
				FormMaVattuHieu(60,26,p,esc); 
				if(esc)
				{
					esc=false;
					goto THONGTIN;
				}
				else
				{				
					Nodetree *k=SearchNodeTree(t,p.MAVT);
					if(k==NULL)
					{
						clearRect(60,26,30,4);
					 	goto AGAIN1;
					} 	
						else
						{
							bool escvt=false;
							MenuHieuChinh(a,k,t,escvt);
							if(escvt)
							{							
								escvt=false;
								goto THONGTIN;
							}
							goto THONGTIN;
						}
				}		
				//if(esc) return;
				//Cursor(false);	
			}							
			//break;
			else
			{
				bool escvt=false;
				Infortree p;
				Cursor(true);
				FormVattu(120,4,p,escvt,t);
				if(escvt)
				{
					escvt=false;
					goto THONGTIN;
				}
				else
				{					
					InsertTree(t,p);
					//Preorder1(t,f,e);
					goto THONGTIN;
				}		
			}
			break;
		}				
	}	
}
void ShowChayVattu(Vattu a)//DONE
{
	bool reload = true, press = false, move = false, esc = false, enter = false;
	int from, to, cur1, page, pre = -1, cur2 = 1;
	char c=62;
	gotoxy(GetConsoleWidth()/2-3,GetConsoleHeight()/2-3);
	printf("%c",c);
	while(true){
		if (reload){
			Clear();
			page = 1; from = 0; to = 5;
			reload = false;
			drawNumber(GetConsoleWidth()/2-3,GetConsoleHeight()/2-3,page,WHITE);
			ShowrectVattu(a,GetConsoleWidth()/4,2,from,to);
			
			
		}
		if (move){
			clearRect(GetConsoleWidth()/4,2,91,20);
			move = false;
			ShowrectVattu(a,GetConsoleWidth()/4,2,from,to);
			drawNumber(GetConsoleWidth()/2-3,GetConsoleHeight()/2-3,page,WHITE);
		}
		KeyPress_1(from,to,page,a.n,reload,move,esc);
		if(esc)
		{		
		 	esc=false;
			return;
		}	
	}	
}
void MenuHieuChinh(Vattu a,Nodetree *&t,Tree k,bool escvt){//DONE	
	NAA:
	system("cls"); // xoa man hình
	// ==================== VE CAI KHUNG - MAY CAI COT ====================== //
	draw_high_line(GetConsoleWidth()/2,0,GetConsoleHeight()-1);
	//draw_high_line(9,0,GetConsoleHeight()-1);
	draw_flat_line(GetConsoleWidth(),GetConsoleHeight()/3,GetConsoleWidth()/2);
	// ==================== VE MAY CAI CHU~ ============================= //
	drawText(GetConsoleWidth()/2 + 5,3,"1 . CHINH SUA TEN VAT TU",WHITE);
	drawText(GetConsoleWidth()/2 + 5,6,"2 . CHINH SUA DVT",WHITE);
	drawText(GetConsoleWidth()/2 + 5,9,"3. XOA VAT TU",WHITE);
	drawText(GetConsoleWidth()/2 + 5,12,"4. BACK",WHITE);
	drawText(GetConsoleWidth()/2 + 5,15,"AN PHIM [1] [2] [3] [4]  DE LUA CHON CHUC NANG",GREEN);
	// ==================== IN DS VAT TU ================================ //
	gotoxy(0,3);
	bool esc=false;
	ShowSortName1(t);
	char c;
	while(true){
		Cursor(false);
		c = getch();
		if(c==27) return;
		if (c == -32 || c == 0) c = getch(); // Khi an phim f1,f2,... hoac mui~ ten thì no se ko crack
		if (c == '1'){
			Cursor(true);
			char *vt, *n_vt; // vt : vat tu hien co trong ds, n_vt: vat tu moi 
			drawRect(GetConsoleWidth()/2 + 5,GetConsoleHeight()/3+5,GetConsoleWidth()/2-10,4);
			drawText(GetConsoleWidth()/2 + 7,GetConsoleHeight()/3+7,"TEN VAT TU ",WHITE);
			vt = InputStr(GetConsoleWidth()/2 + 19,GetConsoleHeight()/3+7,10,esc);			
			if (esc) {
				esc=false ;
				goto NAA;
			}
			strcpy(t->Iphone.TENVT,strupr(vt));
			DeleteSpace(t->Iphone.TENVT);
			goto NAA;
			break; // Chiu. kho ton them 2 dòng de~ 2 break, ko de~ break ngoai` if, neu ko se~ crack
		}
		if (c == '2'){
			char *dvt, *n_dvt; 
			drawRect(GetConsoleWidth()/2 + 5,GetConsoleHeight()/3+5,GetConsoleWidth()/2-10,4);
			drawText(GetConsoleWidth()/2 + 7,GetConsoleHeight()/3+7,"DVT       : ",WHITE);
			// Nhap ten vat tu muon hieu chinh
			Cursor(true);
			dvt = InputStr(GetConsoleWidth()/2 + 19,GetConsoleHeight()/3+7,10,esc);			
			if (esc) { 
				esc=false;
				goto NAA;
			}
			strcpy(t->Iphone.DVT,strupr(dvt));
			DeleteSpace(t->Iphone.DVT);
			goto NAA;
			break;
		}
		if (c == '3'){
			while(SearchHDMAVT(t->Iphone.MAVT)==1)
			{
				//Clear();
				drawRect(GetConsoleWidth()/2 + 5,GetConsoleHeight()/3+5,GetConsoleWidth()/2-10,4);
				drawText(GetConsoleWidth()/2 + 7,GetConsoleHeight()/3+7,"VAT TU NAY DA DUOC XUAT HOA DON.KO DUOC XOA ",YELLOW);
				getch();
				goto NAA;
			};
			Cursor(true);
			drawRect(GetConsoleWidth()/2 + 5,GetConsoleHeight()/3+5,GetConsoleWidth()/2-10,4);// phai co dong nay chung nang 3 moi chay :v
			drawText(GetConsoleWidth()/2 + 8,GetConsoleHeight()/3+7,"BAN CHAC CHAN XOA.Y(YES) N(NO)",YELLOW);		
			if(Yes())
			{
				
				drawText(GetConsoleWidth()/2 + 7,GetConsoleHeight()/3+7,"XOA THANH CONG.ANY KEY       : ",WHITE);
				DeleteNodeTree(k,t->Iphone);
				return;
			}
			else
			{
				return;
			}
			//break;
		}		
		break;
		if(c=='4')
		{
			return;
		}
	}
	//getch();
	
}
void ShowrectVattu(Vattu a,int x,int y,int from,int to)//DONE
{
	int start_x=x;
	int start_y=y;
	drawRect(start_x,start_y,90,2);
	draw_high_line(start_x+16,start_y,2);
	drawText(start_x+4,start_y+1,"MAVT",WHITE);
	draw_high_line(start_x+54,start_y,2);
	drawText(start_x+28,start_y+1,"TEN VATTU",WHITE);
	draw_high_line(start_x+74,start_y,2);
	//drawText(start_x+56,start_y+1,"DVT",WHITE);
	drawText(start_x+56,start_y+1,"SO LUONG TON",WHITE);
	drawText(start_x+80,start_y+1,"DVT",WHITE);
	drawText(GetConsoleWidth()/2-9,GetConsoleHeight()/2,"EXIT=DOUBLE ESC",GREEN);
	gotoxy(GetConsoleWidth()/2-8,GetConsoleHeight()/2-3);
	char c=60;
	printf("%c",c);
	gotoxy(GetConsoleWidth()/2+2,GetConsoleHeight()/2-3);
	char s=62;
	printf("%c",s);
	for(int i=from;i<to;i++){
			// DRAW ELEMENT FRAME // PUT ALL THIS IN LOOP TO DRAW
			drawRect(start_x,start_y+(i+1-from)*2,90,2);
			draw_high_line(start_x+16,start_y+(i+1-from)*2,2);
			draw_high_line(start_x+54,start_y+(i+1-from)*2,2);
			draw_high_line(start_x+74,start_y+(i+1-from)*2,2);
			draw_high_line(start_x+90,start_y+(i+1-from)*2,2);
			gotoxy(start_x,start_y+(i+1-from)*2);
			printf("%c",195);
			gotoxy(start_x+16,start_y+(i+1-from)*2);
			printf("%c",197);
			gotoxy(start_x+54,start_y+(i+1-from)*2);
			printf("%c",197);
			gotoxy(start_x+90,start_y+(i+1-from)*2);
			printf("%c",197);
			gotoxy(start_x+74,start_y+(i+1-from)*2);
			printf("%c",180);
//			// DRAW ELEMENT DATA // PUT ALL THIS IN LOOP TO DRAW
			drawText(start_x+2,start_y+1+(i+1-from)*2,a.nodes[i].MAVT,WHITE);
			drawText(start_x+20,start_y+1+(i+1-from)*2,a.nodes[i].TENVT,WHITE);
			drawText(start_x+80,start_y+1+(i+1-from)*2,a.nodes[i].DVT,WHITE);
			drawNumber(start_x+60,start_y+1+(i+1-from)*2,a.nodes[i].slt,WHITE);
		}
		printf("\n");
		printf("\n");
}
void ShowrectVattu1(Vattu a,int x,int y,int from,int to)//DONE
{
	int start_x=x;
	int start_y=y;
	drawRect(start_x,start_y,90,2);
	draw_high_line(start_x+16,start_y,2);
	drawText(start_x+4,start_y+1,"MAVT",WHITE);
	draw_high_line(start_x+54,start_y,2);
	drawText(start_x+28,start_y+1,"TEN VATTU",WHITE);
	draw_high_line(start_x+74,start_y,2);
	//drawText(start_x+56,start_y+1,"DVT",WHITE);
	drawText(start_x+56,start_y+1,"SO LUONG TON",WHITE);
	drawText(start_x+80,start_y+1,"DVT",WHITE);
	drawText(GetConsoleWidth()/5-5,GetConsoleHeight()/2+14,"EXIT=ESC",RED);
	drawText(GetConsoleWidth()/2+5,GetConsoleHeight()/2+14,"F2=HIEU CHINH VAT TU",GREEN);
	drawText(GetConsoleWidth()/2+48,GetConsoleHeight()/2+14,"ENTER=ACCPET",YELLOW);
	drawText(GetConsoleWidth()/2-20,GetConsoleHeight()/2+14,"F1=THEM VAT TU",GREEN);
	gotoxy(GetConsoleWidth()/3,GetConsoleHeight()/2-3);
	char c=60;
	printf("%c",c);
	gotoxy(GetConsoleWidth()/3+10,GetConsoleHeight()/2-3);
	char s=62;
	printf("%c",s);
	
	for(int i=from;i<to;i++){
			// DRAW ELEMENT FRAME // PUT ALL THIS IN LOOP TO DRAW
			drawRect(start_x,start_y+(i+1-from)*2,90,2);
			draw_high_line(start_x+16,start_y+(i+1-from)*2,2);
			draw_high_line(start_x+54,start_y+(i+1-from)*2,2);
			draw_high_line(start_x+74,start_y+(i+1-from)*2,2);
			draw_high_line(start_x+90,start_y+(i+1-from)*2,2);
			gotoxy(start_x,start_y+(i+1-from)*2);
			printf("%c",195);
			gotoxy(start_x+16,start_y+(i+1-from)*2);
			printf("%c",197);
			gotoxy(start_x+54,start_y+(i+1-from)*2);
			printf("%c",197);
			gotoxy(start_x+90,start_y+(i+1-from)*2);
			printf("%c",197);
			gotoxy(start_x+74,start_y+(i+1-from)*2);
			printf("%c",180);
			drawText(start_x+2,start_y+1+(i+1-from)*2,a.nodes[i].MAVT,WHITE);
			drawText(start_x+20,start_y+1+(i+1-from)*2,a.nodes[i].TENVT,WHITE);
			drawText(start_x+80,start_y+1+(i+1-from)*2,a.nodes[i].DVT,WHITE);
			drawNumber(start_x+60,start_y+1+(i+1-from)*2,a.nodes[i].slt,WHITE);
		}
		printf("\n");
		printf("\n");
}
void FormVattu(int x, int y, Infortree &tmp, bool &esc,Tree t){//DONE
	char *ch;
	//clearRect()
	drawRect(x,y,40,16);
	draw_flat_line(x,y+4,40);
	draw_flat_line(x,y+8,40);
	draw_flat_line(x,y+12,40);
	drawText(x+2,y+2, "TEN VAT TU  : ",WHITE); 
	drawText(x+2,y+6, "MA VAT TU   : ",WHITE);
	drawText(x+2,y+10,"DON VI TINH : ",WHITE);
	drawText(x+2,y+14,"SO LUONG TON: ",WHITE);
	strcpy(tmp.TENVT,strupr(InputStr(x+2+14,y+2,20,esc)));
	DeleteSpace(tmp.TENVT);
	if (esc) return;
	strcpy(tmp.MAVT,strupr(InputStr(x+2+14,y+6,10,esc)));
	DeleteSpace(tmp.MAVT);
	//if(tmp.MAVT==NULL) return;
	Nodetree *k=SearchNodeTree(t,tmp.MAVT);
	while(k!=NULL)
	{	
		drawText(x-10,y+20,"XIN LOI MA VAT TU KHONG DUOC TRUNG.ENTER NHAP LAI ",RED);
		getch();
		clearRect(x+1,y+6,40,2);
		clearRect(x-10,y+20,60,2);
		drawRect(x,y,40,16);
		drawText(x+2,y+6, "MA VAT TU   : ",WHITE);
		strcpy(tmp.MAVT,strupr(InputStr(x+2+14,y+6,10,esc)));
		Nodetree *k=SearchNodeTree(t,tmp.MAVT);
		if(k==NULL) break;
	}
	if (esc) return;
	strcpy(tmp.DVT,strupr(InputStr(x+2+14,y+10,20,esc)));
	ch=InputStrint(x+2+14,y+14,100,esc);
	if (esc) return;
	tmp.slt=atoi(ch);
	drawText(GetConsoleWidth()/2,y+20,"ENTER DE CHAC CHAN ",DARKCYAN);
	//gotoxy(10,30);
	getch();
}
void FormMaVattu(int x, int y, Infortree &tmp, bool &esc)//ODNE
{
	char *ch;
	drawRect(90,0,30,4);
	drawText(90+2,2, "MA VAT TU CAN XOA   : ",WHITE);
	drawText(90+2,7, "INSERT=ENTER    ",WHITE);
	drawText(90+2,8, "EXIT=ESC    ",WHITE);
	strcpy(tmp.MAVT,strupr(InputStr(90+2+22,2,10,esc)));
	if (esc) return;
}
void FormMaVattuHieu(int x, int y, Infortree &tmp, bool &esc)//DONE
{
	//if()
	//ShowSortName(e);
	char *ch;
	drawRect(x,y,50,4);
	drawText(x+2,y+2, "MA VAT TU HIEU CHINH : ",WHITE);
	drawText(x+10,y+5, "ENTER DE XAC NHAN ",WHITE);
	strcpy(tmp.MAVT,strupr(InputStr(x+2+23,y+2,10,esc)));
	if (esc)
	{
//		strcpy(tmp.MAVT,""); // reset neu nhu an esc, char tmp.MAVT van~ la` 1 chuoi~ empty
		//esc=false;
		return;
	}	
}
void OrderNameVattu(Vattu &a)//DONE
{
	for(int i=0;i<a.n;i++)
	{
		for(int j=a.n-1;j>=i;j--)
		{
			if(strcmp(a.nodes[j].TENVT,a.nodes[j-1].TENVT)<0)
			{
				Swap(a.nodes[j],a.nodes[j-1]);
			}
		}
	}
}
void ShowSortName1(Nodetree *t)//DONE	
{
	printf(".==========.====================.====================.=======================.\n");
	printf("|Ma Vat tu |Ten vat tu          |Don vi tinh         |So luong ton           |\n");
	printf("*==========*====================*====================*=======================*\n");
//	for(int i=0;i<a.n;i++)
//	{
		printf("|%-10s|%-20s|%-20s|%-23d|\n",t->Iphone.MAVT,t->Iphone.TENVT,t->Iphone.DVT,t->Iphone.slt);
//	}
	printf("*==========*====================*====================*=======================*");
}

void FormSoHoadon(int x, int y, HD &tmp,bool &esc){//DONE
	char *ch;
	//ShowSHD(a,2,2,0,a.n);
	drawRect(x,y,45,5);
	//draw_flat_line(x,y+4,40);
	drawText(x+2,y+2, "So Hoa don can tra cuu : ",WHITE);
	drawText(x+14,y+10, "Enter=Insert||Esc=Exit ",DARKBLUE);
	strcpy(tmp.SHD,strupr(InputStr(x+28,y+2,20,esc)));
	if (esc) return;
	drawText(x+13,y+8, "Enter chuyen man hinh xac nhan ",DARKPINK);
	getch();
}	
void SaveFileHd12()//DONE
{
	FILE *fp=fopen("CTHD.txt","w");
	for(int i=0;i<soluongnv;i++)
	{
		for(Ldshd *k=NV[i]->_hd;k!=NULL;k=k->pNext)
		{			
			if(k->_Hd._Cthd!=NULL)
			{				
				fprintf(fp,"%d\n",k->_Hd.soluongvattu);
				fprintf(fp,"%s\n",k->_Hd.SHD);
				for(int j=0;j<k->_Hd.soluongvattu;j++)
				{	
					SaveCTHDFULL(fp,k->_Hd._Cthd[j]);
				}
			}
		}
	}
	fclose(fp);
}

//=======================CAC HAM NHAN VIEN===============================================
void FormNHANVIEN(int x, int y, Nhanvien *&tmp,bool esc,int &soluongnv){//DONE
	NV:
	//Clear();
	char *ch;
	drawRect(x,y,40,16);
	draw_flat_line(x,y+4,40);
	draw_flat_line(x,y+8,40);
	draw_flat_line(x,y+12,40);
	drawText(x+13,y-1, "THONG TIN NHAN VIEN  ",WHITE);
	//drawText(GetConsoleWidth()/2+14,y+20, "ENTER=INSERT    ",DARKBLUE);
	//drawText(GetConsoleWidth()/2+19,y+21, "ESC=EXIT      ",DARKBLUE);   
	drawText(x+2,y+2, "HO          : ",WHITE); 
	drawText(x+2,y+6, "TEN         : ",WHITE);
	drawText(x+2,y+10,"GIOI TINH   : ",WHITE);
	drawText(x+2,y+14,"MA NHAN VIEN: ",WHITE);
	strcpy(tmp->HO,strupr(InputStr(x+2+14,y+2,30,esc)));
	DeleteSpace(tmp->HO);
	if (esc) {fflush(stdin);return;}
	strcpy(tmp->TEN,strupr(InputStr(x+2+14,y+6,18,esc)));
	DeleteSpace(tmp->TEN);
	if (esc) {fflush(stdin);return;}
	strcpy(tmp->SEX,strupr(InputStr(x+2+14,y+10,3,esc)));
	DeleteSpace(tmp->SEX);
	if (esc) {fflush(stdin);return;}
	MNV:
	strcpy(tmp->MANV,strupr(InputStr(x+2+14,y+14,10,esc)));
	DeleteSpace(tmp->MANV);
	while(CheckMNV(tmp->MANV)==0) {
	drawText(x+2,y+18,"MA NHAN VIEN DA BI TRUNG.ENTER NHAP LAI ",RED);
	getch();
	clearRect(x,y+13,41,7);
	//clearRect(x+2,y+17,)
	draw_flat_line(x,y+12,40);
	drawRect(x,y,40,16);
	drawText(x+2,y+14,"MA NHAN VIEN: ",WHITE);
	strcpy(tmp->MANV,strupr(InputStr(x+2+14,y+14,10,esc)));
	DeleteSpace(tmp->MANV);
	//goto MNV;
	}
	if(esc) return;
	soluongnv++;
}
void CopyNV(Dsnv &nv)
{
	nv.n=soluongnv;
	for(int i=0;i<nv.n;i++)
	{
		strcpy(nv.a[i].HO,NV[i]->HO);
		strcpy(nv.a[i].TEN,NV[i]->TEN);
		strcpy(nv.a[i].SEX,NV[i]->SEX);
		strcpy(nv.a[i].MANV,NV[i]->MANV);
	}
}
void ReadNvFromFile(FILE *f,Nhanvien *&a)//DONE
{
//		fscanf(f,"%s\n",&a->HO);
//		fscanf(f,"%s\n",&a->TEN);
//		fscanf(f,"%s\n",&a->SEX);
//		fscanf(f,"%s\n",&a->MANV);
		fgets(a->HO,50,f);
		strtok(a->HO,"\n");
		fgets(a->TEN,10,f);
		strtok(a->TEN,"\n");
		fgets(a->SEX,5,f);
		strtok(a->SEX,"\n");
//		fgets(a->MANV,15,f);
//		strtok(a->MANV,"\n");
		fscanf(f,"%s\n",&a->MANV);
}
void ReadAllNV()//DONE
{
	FILE *f=fopen("Nhanvien.txt","r");	
	int i=0;
	while(1)
	{
		NV[soluongnv]=new Nhanvien;
		ReadNvFromFile(f,NV[soluongnv]);
		soluongnv++;
		if(feof(f))
		{
			break;
		}
	}
	fclose(f);
	
}
void Swap1(Nhanvien &a,Nhanvien &b)//DONE
{
	Nhanvien temp;
	temp=a;
	a=b;
	b=temp;
}
void OrderNameNV(Dsnv &nv)//DONE
{
	for(int i=1;i<nv.n;i++)
	{

		for(int j=nv.n-1;j>=i;j--)
		{			
			if(strcmp(nv.a[j].TEN,nv.a[j-1].TEN)<0)
			{
				//cout<<i<<endl;
				//cout<<j<<endl;
				Swap1(nv.a[j],nv.a[j-1]);
			}
			else if(strcmp(nv.a[j].TEN,nv.a[j-1].TEN)==0)
			{
				if(strcmp(nv.a[j].HO,nv.a[j-1].HO)<0)
				{
					Swap1(nv.a[j],nv.a[j-1]);
				}
			}
		}
	}
}
void Showrect(Dsnv nv,int x,int y,int from,int to)//DONE
{
	
	int start_x=x;
	int start_y=y;
	drawRect(start_x,start_y,70,2);
	draw_high_line(start_x+16,start_y,2);
	drawText(start_x+4,start_y+1,"MANV",WHITE);
	draw_high_line(start_x+54,start_y,2);
	drawText(start_x+28,start_y+1,"TEN NHAN VIEN",WHITE);
	drawText(start_x+56,start_y+1,"GIOI TINH",WHITE);
	gotoxy(GetConsoleWidth()/3-4,GetConsoleHeight()/3+3);
	char c=60;
	printf("%c",c);
	gotoxy(GetConsoleWidth()/3+4,GetConsoleHeight()/3+3);
	char s=62;
	printf("%c",s);
	drawText(GetConsoleWidth()/5-5,GetConsoleHeight()/2+14,"EXIT=ESC",RED);
	drawText(GetConsoleWidth()/2+10,GetConsoleHeight()/2+14,"F2=THEM NHAN VIEN",GREEN);
	drawText(GetConsoleWidth()/2+48,GetConsoleHeight()/2+14,"ENTER=ACCEPT",YELLOW);
	drawText(GetConsoleWidth()/2-20,GetConsoleHeight()/2+14,"F1=HIEU CHINH NHAN VIEN",GREEN);
	for(int i=from;i<to;i++){
			// DRAW ELEMENT FRAME // PUT ALL THIS IN LOOP TO DRAW
			drawRect(start_x,start_y+(i+1-from)*2,70,2);
			draw_high_line(start_x+16,start_y+(i+1-from)*2,2);
			draw_high_line(start_x+54,start_y+(i+1-from)*2,2);
			gotoxy(start_x,start_y+(i+1-from)*2);
			printf("%c",195);
			gotoxy(start_x+16,start_y+(i+1-from)*2);
			printf("%c",197);
			gotoxy(start_x+54,start_y+(i+1-from)*2);
			printf("%c",197);
			gotoxy(start_x+70,start_y+(i+1-from)*2);
			printf("%c",180);
			drawText(start_x+2,start_y+1+(i+1-from)*2,nv.a[i].MANV,WHITE);
			drawText(start_x+20,start_y+1+(i+1-from)*2,nv.a[i].HO,WHITE);
			drawText(start_x+40,start_y+1+(i+1-from)*2,nv.a[i].TEN,WHITE);
			drawText(start_x+66,start_y+1+(i+1-from)*2,nv.a[i].SEX,WHITE);
		}
		printf("\n");
		printf("\n");
}
void Showrect1(Dsnv nv,int x,int y,int from,int to)//DONE
{
	
	int start_x=x;
	int start_y=y;
	drawRect(start_x,start_y,70,2);
	draw_high_line(start_x+16,start_y,2);
	drawText(start_x+4,start_y+1,"MANV",WHITE);
	draw_high_line(start_x+54,start_y,2);
	drawText(start_x+28,start_y+1,"TEN NHAN VIEN",WHITE);
	drawText(start_x+56,start_y+1,"GIOI TINH",WHITE);
	gotoxy(GetConsoleWidth()/2-7,GetConsoleHeight()/2-3);
	char c=60;
	printf("%c",c);
	gotoxy(GetConsoleWidth()/2+1,GetConsoleHeight()/2-3);
	char s=62;
	printf("%c",s);
	drawText(GetConsoleWidth()/5-5,GetConsoleHeight()/2+14,"EXIT=ESC",RED);
	drawText(GetConsoleWidth()/2-10,GetConsoleHeight()/2+14,"F1=TRA CUU NHAN VIEN THEO CODE",GREEN);
	drawText(GetConsoleWidth()/2+48,GetConsoleHeight()/2+14,"ENTER=ACCEPT",YELLOW);
	//drawText(GetConsoleWidth()/2-20,GetConsoleHeight()/2+14,"F1=HIEU CHINH NHAN VIEN",GREEN);
	for(int i=from;i<to;i++){
			// DRAW ELEMENT FRAME // PUT ALL THIS IN LOOP TO DRAW
			drawRect(start_x,start_y+(i+1-from)*2,70,2);
			draw_high_line(start_x+16,start_y+(i+1-from)*2,2);
			draw_high_line(start_x+54,start_y+(i+1-from)*2,2);
			gotoxy(start_x,start_y+(i+1-from)*2);
			printf("%c",195);
			gotoxy(start_x+16,start_y+(i+1-from)*2);
			printf("%c",197);
			gotoxy(start_x+54,start_y+(i+1-from)*2);
			printf("%c",197);
			gotoxy(start_x+70,start_y+(i+1-from)*2);
			printf("%c",180);
			drawText(start_x+2,start_y+1+(i+1-from)*2,nv.a[i].MANV,WHITE);
			drawText(start_x+20,start_y+1+(i+1-from)*2,nv.a[i].HO,WHITE);
			drawText(start_x+40,start_y+1+(i+1-from)*2,nv.a[i].TEN,WHITE);
			drawText(start_x+66,start_y+1+(i+1-from)*2,nv.a[i].SEX,WHITE);
		}
		printf("\n");
		printf("\n");
}
void FormMaNVHieu(int x, int y, Nhanvien &tmp, bool &esc)//DONE
{
	char *ch;
	drawRect(x,y,50,4);
	drawText(x+2,y+2, "MA NV HIEU CHINH : ",WHITE);
	drawText(x+10,y+5, "ENTER DE XAC NHAN ",WHITE);
	strcpy(tmp.MANV,strupr(InputStr(x+2+23,y+2,10,esc)));
	if (esc)
	{
		//esc=false;
		return;
	}	
}
int FindEmployeeByCode(char x[15])//DONE
{
	for(int i=0;i<soluongnv;i++)
	{
		if(strcmp(NV[i]->MANV,x)==0)
		{
			return i;
		}		
	}
	return 1999;
}
int FindEmployeeByName(char x[15])//DONE
{
	for(int i=0;i<soluongnv;i++)
	{
		if(strcmp(NV[i]->TEN,x)==0)
		{
			return i;
		}		
	}
	return 1999;
}
void SaveListNV()//DONE
{
	FILE *f=fopen("Nhanvien.txt","w");
	for(int i=0;i<soluongnv;i++)
	{
		fprintf(f,"%s\n",NV[i]->HO);
		fprintf(f,"%s\n",NV[i]->TEN);
		fprintf(f,"%s\n",NV[i]->SEX);
		fprintf(f,"%s\n",NV[i]->MANV);
	}
	fclose(f);
}
void MenuHieuChinhNV(int vitri){//DONE	
	NAA:
	Cursor(false);	
	system("cls"); // xoa man hình
	// ==================== VE CAI KHUNG - MAY CAI COT ====================== //
	draw_high_line(GetConsoleWidth()/2,0,GetConsoleHeight()-1);
	draw_flat_line(GetConsoleWidth(),GetConsoleHeight()/3,GetConsoleWidth()/2);	
	// ==================== VE MAY CAI CHU~ ============================= //
	drawText(GetConsoleWidth()/2 + 5,3,"1 . CHINH SUA HO NHAN VIEN",WHITE);
	drawText(GetConsoleWidth()/2 + 5,6,"2 . CHINH SUA TEN",WHITE);
	drawText(GetConsoleWidth()/2 + 5,9,"3. XOA NHAN VIEN",WHITE);
	drawText(GetConsoleWidth()/2 + 5,12,"4. BACK",WHITE);
	drawText(GetConsoleWidth()/2 + 5,15,"AN PHIM [1] [2] [3] [4]  DE LUA CHON CHUC NANG",GREEN);
	// ==================== IN DS VAT TU ================================ //
	gotoxy(0,3);
	ShowEmployee(vitri);
	bool esc=false;
	char c;
	while(true){
		c = getch();
		if(c==27) return;
		if (c == -32 || c == 0) c = getch(); // Khi an phim f1,f2,... hoac mui~ ten thì no se ko crack
		if (c == '1'){
			Cursor(true);
			char *vt, *n_vt; // vt : vat tu hien co trong ds, n_vt: vat tu moi 
			drawRect(GetConsoleWidth()/2 + 5,GetConsoleHeight()/3+5,GetConsoleWidth()/2-10,4);
			drawText(GetConsoleWidth()/2 + 7,GetConsoleHeight()/3+7,"HO NHAN VIEN ",WHITE);
			vt = strupr(InputStr(GetConsoleWidth()/2 + 20,GetConsoleHeight()/3+7,30,esc));			
			if (esc) {
				esc=false;
				 
				goto NAA;
			}
			strcpy(NV[vitri]->HO,vt);
			DeleteSpace(NV[vitri]->HO);
			goto NAA;
			break;
		}
		if (c == '2'){
			Cursor(true);
			char *dvt, *n_dvt; 
			drawRect(GetConsoleWidth()/2 + 5,GetConsoleHeight()/3+5,GetConsoleWidth()/2-10,4);
			drawText(GetConsoleWidth()/2 + 7,GetConsoleHeight()/3+7,"TEN NHAN VIEN : ",WHITE);
			// Nhap ten vat tu muon hieu chinh
			dvt = strupr(InputStr(GetConsoleWidth()/2 + 22,GetConsoleHeight()/3+7,10,esc));			
			if (esc) { 
				esc=false;
				goto NAA;
			}
			strcpy(NV[vitri]->TEN,dvt);
			DeleteSpace(NV[vitri]->TEN);
			goto NAA;
			break;
		}
		if (c == '3'){
			Cursor(true);
			if(NV[vitri]->_hd!=NULL)
			{
				drawRect(GetConsoleWidth()/2 + 5,GetConsoleHeight()/3+5,GetConsoleWidth()/2-10,4);
				drawText(GetConsoleWidth()/2 + 7,GetConsoleHeight()/3+7,"NHAN VIEN NAY DA XUAT HOA DON.VUI LONG KHONG XOA ",RED);
				getch();
				goto NAA;
			}
			else
			{
				drawRect(GetConsoleWidth()/2 + 5,GetConsoleHeight()/3+5,GetConsoleWidth()/2-10,4);
				drawText(GetConsoleWidth()/2 + 7,GetConsoleHeight()/3+7,"BAN CHAC CHAN XOA CHU Y(YES) N(NO) ",WHITE);
				if(Yes())
				{
					DeleteEmployee(vitri);
					return;
				}
				else
				{
					goto NAA;
				}
			}
		}
		break;
		if(c=='4')
		{
			return;
		}
	}
	//getch();
}
void ShowChayNhanvienHieuChinh(bool &esc1,Dsnv nv)//DONE
{
	AHIHI:
	Cursor(false);
	CopyNV(nv);
	OrderNameNV(nv);
	//OrderNameNV();	
	bool reload = true, press = false, move = false, esc = false;
	int from = 0, to = 10, cur = 0, page = 1;
	while(true){
		if (reload){
			Clear();
			page = 1; from = 0; to = 5;
			reload = false;
			drawNumber(GetConsoleWidth()/3,GetConsoleHeight()/3+3,page,WHITE);		
			Showrect(nv,GetConsoleWidth()/8,2,from,to);
			
		}
		if (move){
			//Clear();
			clearRect(GetConsoleWidth()/8,2,80,40);
			move = false;
			Showrect(nv,GetConsoleWidth()/8,2,from,to);
			drawNumber(GetConsoleWidth()/3,GetConsoleHeight()/3+3,page,WHITE);
		}
		KeyPress_3(cur,from,to,page,soluongnv,reload,press,move,esc1);
		if(esc1)
		{	
			return;
		}	
		if(press)
		{
			press=false;
			if(cur==1)
			{
				Cursor(true);
				Nhanvien b;
				NV[soluongnv]=new Nhanvien;
				FormNHANVIEN(100,5,NV[soluongnv],esc,soluongnv);
				if (esc)
				{
					esc = false;
					break;
				}
				goto AHIHI;
			}
			else if(cur==2)
			{
				Cursor(true);
				bool esc=false;
				MM:
				Nhanvien p;
				FormMaNVHieu(60,26,p,esc); 
				if(esc)
				{
					esc=false;
					goto AHIHI;
				} 
				else
				{				
					int vitri=FindEmployeeByCode(p.MANV);
					if(vitri!=1999)
					{
						MenuHieuChinhNV(vitri);
						goto AHIHI;
					}	
					else
					{
						clearRect(60,26,50,4);
						goto MM;
					}	
				}
			}
			break;
		}				
	}
	
}
void ShowChay(Dsnv nv)//DONE
{
	QUAMON:
	bool reload = true, press = false, move = false, esc = false;
	int from = 0, to = 10, cur = 0, page = 1;
	CopyNV(nv);
	OrderNameNV(nv);
	while(true){
		if (reload){
			Clear();
			page = 1; from = 0; to = 5;
			reload = false;
			drawNumber(GetConsoleWidth()/2-3,GetConsoleHeight()/2-3,page,WHITE);
			Showrect1(nv,GetConsoleWidth()/4,2,from,to);
		}
		if (move){
			clearRect(GetConsoleWidth()/4,2,80,40);
			move = false;
			Showrect1(nv,GetConsoleWidth()/4,2,from,to);
			drawNumber(GetConsoleWidth()/2-3,GetConsoleHeight()/2-3,page,WHITE);
		}
		KeyPress_3(cur,from,to,page,soluongnv,reload,press,move,esc);
		if(esc)
		{
		 	esc=false;
			return;
		}
		if(press)
		{
			press=false;
			if(cur==1)
			{
				return;
				//goto AHIHI;
			}
			else if(cur==2)
			{
				Cursor(true);
				bool esc=false;
				MM:
				Nhanvien p;
				FormMaNVHieu(60,26,p,esc); 
				if(esc)
				{
					esc=false;
					//goto AHIHI;
				} 
				else
				{				
					int vitri=FindEmployeeByCode(p.MANV);
					if(vitri!=1999)
					{
						gotoxy(30,20);
						ShowEmployee(vitri);
						getch();
						goto QUAMON;
					}	
					else
					{
						clearRect(60,26,50,4);
						goto MM;
					}	
				}
			}
			break;
		}					
	}	
}
int CheckNameNV(char a[15],char b[15])//DONE
{
	if(strcmp(a,b)==0) return 0;
	else return 1999;
}
void DeleteEmployee(int vitri)//DONE
{
	for(int i=vitri+1;i<soluongnv;i++)
	{
		NV[i-1]=NV[i];
	}
	soluongnv--;
}
int CheckMNV(char a[15])//kiem tra ma nhan vien//DONE
{
	for(int i=0;i<soluongnv;i++)
	{
		if(strcmp(NV[i]->MANV,a)==0)
		{
			return 0;
		}		
	}
	return 1;
}
//=======================CAC HAM HOA DON=====================================================
int CheckVATTU(Cthd *a,char x[20],int n)
{
	for(int i=0;i<n;i++)
	{
		if(strcmp(a[i].MAVT,x)==0) return 0;
	}
	return 1;
}
void FormHoadon(int x, int y, HD &tmp, bool &esc,int &vitri,Tree tp){//DONE
	MANU:
	Clear();
	Cursor(true);
	char *ch;
	vitri=1999;
	drawText(x-1,y-1, "THONG TIN HOA DON   : ",DARKBLUE); 
	drawRect(x,y,40,16);
	draw_flat_line(x,y+4,40);
	draw_flat_line(x,y+8,40);
	draw_flat_line(x,y+12,40);
	drawText(x+2,y+2, "MA NHAN VIEN   : ",WHITE); 
	drawText(x+2,y+6, "LOAI HOA DON   : ",WHITE);
	drawText(x+2,y+10,"SO HOA DON     : ",WHITE);
	ch = strupr(InputPassword(x+2+17,y+2,15,esc));
	if(esc ) return;
	for(int i=0;i<soluongnv;i++)
	{
		if(CheckNameNV(ch,NV[i]->MANV)==0)
		{
			drawText(x+2,y+14,"Da tim duoc !!     ",YELLOW);
			vitri=i;
			break;
		}		
	}
	if(vitri==1999)
	{
		drawText(x+2,y+14,"Chua tim duoc      ",RED);
		getch();
	 	goto MANU;
	}	
	strcpy(tmp.kind,strupr(InputStrIO(x+2+17,y+6,1,esc)));
	if (esc) return;
	SHD1:
	strcpy(tmp.SHD,strupr(InputStr(x+2+17,y+10,20,esc)));
	for(int i=0;i<soluongnv;i++)
	{
		if(CheckSHD(NV[i]->_hd,tmp.SHD)==0)
		{
			drawText(x+2,y+14,"SO HOA DON TRUNG     : ",WHITE);
			getch();
			clearRect(x,y+9,41,16);
			drawRect(x,y,40,16);
			draw_flat_line(x,y+4,40);
			draw_flat_line(x,y+8,40);
			draw_flat_line(x,y+12,40);
			drawText(x+2,y+10,"SO HOA DON     : ",WHITE);
			goto SHD1;
		}		 
	}
	if (esc) return;
	time_t now=time('\0');
	tm *t=localtime(&now);
	tmp._Date.ngay=t->tm_mday;
	tmp._Date.thang=1+t->tm_mon;
	tmp._Date.nam=1900+t->tm_year;
	if(strcmp(tmp.kind,"n")==0||strcmp(tmp.kind,"N")==0)
	{
		//Clear();
		NHAPN:
		drawRect(x,y+20,40,5);
		drawText(x+2,y+22,"SO LAN DUA VAT TU VAO HOA DON : ",WHITE);	
		char *ch=InputStrint(x+2+31,y+22,100,esc);
		
		tmp.soluongvattu=atoi(ch);
		if(tmp.soluongvattu>20)
		{
			drawText(x,y+25,"XIN LOI.VUOT QUA GIOI HAN CHO PHEP.ENTER NHAP LAI",RED);
			getch();
			clearRect(x+2,y+22,45,5);
			goto NHAPN;
		}
		tmp._Cthd=new Cthd[atoi(ch)]; 
		for(int i=0;i<atoi(ch);i++)
		{
			AGAIN:
			clearRect(x+60,y,40,20);		
			Cthd k;
			drawRect(x+60,y,40,20);
			draw_flat_line(x+60,y+4,40);
			draw_flat_line(x+60,y+8,40);
			draw_flat_line(x+60,y+12,40);
			draw_flat_line(x+60,y+16,40);
			drawText(x+65,y+2, "MA VAT TU:  ",WHITE);			
			drawText(x+65,y+6, "SO LUONG :  ",WHITE);
			drawText(x+65,y+10,"DON GIA  :  ",WHITE);			
			drawText(x+65,y+14,"VAT=10%            ",WHITE);
			strcpy(k.MAVT,strupr(InputStr(x+60+17,y+2,15,esc)));
			if (esc) return;
			if(SearchNodeTree1(tp,k.MAVT)==0)
			{
				drawText(x+2+60,y+17,"MA VAT TU KHONG CO TRONG KHO.XIN NHAP LAI",RED);
				getch();
				goto AGAIN;
			}
			if(CheckVATTU(tmp._Cthd,k.MAVT,tmp.soluongvattu)==0)
			{
				drawText(x+2+60,y+17,"1 VAT TU CHI DC DUA VAO 1 LAN",WHITE);
				getch();
				clearRect(x+60,y+17,41,5);
				goto AGAIN;
			} 
			Nodetree *p=SearchNodeTree(tp,k.MAVT);
			drawText(x+2+60,y+17,"DAY LA VAT TU",WHITE);
			drawText(x+20+60,y+17,p->Iphone.TENVT,YELLOW);
			drawText(x+2+60,y+18,"HAY CHAC CHAN TIEP TUC.Y(YES) N(NO)",YELLOW);
			if(Yes())
			{
				clearRect(x+60,y+17,41,5);
				//drawRect(x+60,y+16,40,5);				
				k.soluong=atoi(InputStrint(x+60+17,y+6,15,esc));
				if (esc) return;				
				p->Iphone.slt=p->Iphone.slt+k.soluong;
				k.dongia=atoi(InputStrint(x+60+17,y+10,15,esc));
				if (esc) return;
				k.vat=0.1;
				if (esc) return;
				tmp._Cthd[i].soluong=k.soluong;			
				tmp._Cthd[i].dongia=k.dongia;
				strcpy(tmp._Cthd[i].MAVT,k.MAVT);
				tmp._Cthd[i].vat=k.vat;
				getch();			
			}
			else
			{
				
				clearRect(x+60,y,40,20);
				goto AGAIN;
			}	
		}	
	}
	else
	{
		NHAPX:
		drawRect(x,y+20,40,5);
		drawText(x+2,y+22,"SO LAN DUA VAT TU VAO HOA DON : ",WHITE);
		char *ch=InputStrint(x+2+31,y+22,100,esc);
		tmp.soluongvattu=atoi(ch);
		if(tmp.soluongvattu>20)
		{
			drawText(x,y+25,"XIN LOI.VUOT QUA GIOI HAN CHO PHEP.ENTER NHAP LAI",RED);
			getch();
			clearRect(x+2,y+22,45,5);
			goto NHAPX;
		} 
		tmp._Cthd=new Cthd[atoi(ch)];
		for(int i=0;i<atoi(ch);i++)
		{
			MANU1:
			clearRect(x+60,y,40,20);			
			Cthd k;
			drawRect(x+60,y,40,20);
			draw_flat_line(x+60,y+4,40);
			draw_flat_line(x+60,y+8,40);
			draw_flat_line(x+60,y+12,40);
			draw_flat_line(x+60,y+16,40);
			drawText(x+65,y+2, "MA VAT TU:  ",WHITE);			
			drawText(x+65,y+6, "SO LUONG :  ",WHITE);
			drawText(x+65,y+10,"DON GIA  :  ",WHITE);			
			drawText(x+65,y+14,"VAT=10%            ",WHITE);
			strcpy(k.MAVT,strupr(InputStr(x+2+75,y+2,15,esc)));
			if (esc) return;			
			if(SearchNodeTree1(tp,k.MAVT)==0)
			{ 
				drawText(x+2+60,y+2,"MA VAT TU KHONG CO TRONG KHO.XIN NHAP LAI",RED);
				getch();
				goto MANU1;
			}
			if(CheckVATTU(tmp._Cthd,k.MAVT,tmp.soluongvattu)==0)
			{
				drawText(x+2+60,y+17,"1 VAT TU CHI DC DUA VAO 1 LAN",WHITE);
				getch();
				clearRect(x+60,y+17,41,5);
			 	goto MANU1;
			}	
			Nodetree *p=SearchNodeTree(tp,k.MAVT);
			drawText(x+2+60,y+17,"DAY LA VAT TU",WHITE);
			drawText(x+20+60,y+17,p->Iphone.TENVT,YELLOW);
			drawText(x+2+60,y+18,"HAY CHAC CHAN TIEP TUC.Y(YES) N(NO)",YELLOW);
			if(Yes())
			{
				MANU2:
				clearRect(x+60,y+17,41,5);
				k.soluong=atoi(InputStr(x+60+17,y+6,15,esc));			
				if(p->Iphone.slt<k.soluong)
				{
					clearRect(x+2,y+16,40,5);
					drawText(x+2+60,y+17,"VAT TU NAY CHI CON",WHITE);
					drawNumber(x+21+60,y+17,p->Iphone.slt,YELLOW);
					drawText(x+2+60,y+18,"BAN MUON DUNG HET KO.Y(YES) N(NO)",YELLOW);
					if(Yes())
					{
						k.soluong=p->Iphone.slt;
						p->Iphone.slt=p->Iphone.slt-k.soluong;
					}
					else
					{
						clearRect(x,y+4,40,5);
						drawRect(x,y,40,16);
						draw_flat_line(x,y+4,40);
						draw_flat_line(x,y+8,40);
						draw_flat_line(x,y+12,40);
						draw_flat_line(x,y+16,40);		
						drawText(x+2,y+6, "SO LUONG        :  ",WHITE);					
						goto MANU2;
					} 
				}
				k.dongia=atoi(InputStr(x+2+75,y+10,15,esc));
				k.vat=0.1;
				tmp._Cthd[i].soluong=k.soluong;		
				tmp._Cthd[i].dongia=k.dongia;
				strcpy(tmp._Cthd[i].MAVT,k.MAVT);
				tmp._Cthd[i].vat=k.vat;
			}
			else
			{
				goto MANU1;
			}						
		}
	}			
}
void ShowChaySHD(List a,Tree t)
{
	
	bool reload = true, press = false, move = false, esc = false, enter = false;
	int from, to, cur1, page, pre = -1, cur2 = 1;

	while(true){
		if (reload){
			page = 1; from = 0; to = 5;
			reload = false;
			//gotoxy()
			drawNumber(GetConsoleWidth()/2+4,GetConsoleHeight()/2-4,page,WHITE);
			ShowSHD(a,GetConsoleWidth()/2,2,from,to);
		}
		if (move){
			Clear();
			move = false;
			drawNumber(GetConsoleWidth()/2+4,GetConsoleHeight()/2-4,page,WHITE);
			ShowSHD(a,GetConsoleWidth()/2,2,from,to);
		}
		KeyPress_3(cur1,from,to,page,a.n,reload,press,move,esc);
		if(esc)
		{
		 	esc=false;
			return;
		}
		if(press)
		{
			press=false;
			if(cur1==1)
			{
					Cursor(true);
					NHAPHOADON:
					int vitri;
					HD c;
					FormSoHoadon(GetConsoleWidth()/3+20,20,c,esc);
					if (esc)
					{
						esc = false;
						break;
					}
					Ldshd *p;
					for(int i=0;i<soluongnv;i++)
					{						
						p=CheckSHD1(NV[i]->_hd,c.SHD);
						if(p!=NULL)
						{
							vitri=i;
							break;
						}										
					}
					if(p==NULL)
					{
						drawText(GetConsoleWidth()/3+20,27,"SO HOA DON KHONG CO",YELLOW);
						getch();
						clearRect(GetConsoleWidth()/3+20,20,50,10);
						goto NHAPHOADON;
					}
					ShowSHDRect(p->_Hd,3,4,t,vitri);
			}
			break;
		}			
	}	
}
void ReadCTH(FILE *f,HD &temp,char x[20])//DONE
{
	
	while(!feof(f))
	{	
		HD l;
		fscanf(f,"%d\n",&l.soluongvattu);
		l._Cthd=new Cthd[l.soluongvattu]; 			
		char c[20];
		fgets(c,20,f);
		strtok(c,"\n");
		for(int i=0;i<l.soluongvattu;i++)
		{		
			fgets(l._Cthd[i].MAVT,20,(FILE*)f);
			strtok(l._Cthd[i].MAVT,"\n");
			int a,b,c;
			fscanf(f,"%d",&a);
			fscanf(f,"%d",&b);
			fscanf(f,"%d ",&c);
			l._Cthd[i].soluong=a;
			l._Cthd[i].dongia=b;
			l._Cthd[i].vat=c;			
		}
		if(strcmp(c,x)==0)
		{
			temp.soluongvattu=l.soluongvattu;
			temp._Cthd=new Cthd[l.soluongvattu];
			for(int i=0;i<temp.soluongvattu;i++)
			{
				temp._Cthd[i].soluong=l._Cthd[i].soluong;
				temp._Cthd[i].dongia=l._Cthd[i].dongia;
				temp._Cthd[i].vat=l._Cthd[i].vat;
				strcpy(temp._Cthd[i].MAVT,l._Cthd[i].MAVT);
			}
			break;
		}	
	}			
}
void ReadHd()//DONE
{
	FILE *f=fopen("Hoadon.txt","r");	
	while(!feof(f))
	{
		HD b;	
		char x[15];
		fgets(x,15,f);
		strtok(x,"\n");
		fgets(b.kind,20,f);
		strtok(b.kind,"\n");
		fgets(b.SHD,10,f);
		strtok(b.SHD,"\n");
		fscanf(f,"%d",&b._Date.thang);
		fscanf(f,"%d",&b._Date.ngay);
		fscanf(f,"%d ",&b._Date.nam);
		for(int i=0;i<soluongnv;i++)
		{
			if(CheckNameNV(x,NV[i]->MANV)==0)
			{
				FILE *fp=fopen("CTHD.txt","r");
				ReadCTH(fp,b,b.SHD);
				fclose(fp);
				Ldshd *p=Create(b);
				InsertNodeLast1(NV[i]->_hd,p);
			}
		}	
	}
	fclose(f);	
}
void ShowSHDRect(HD a,int x,int y,Tree t,int vitri)//DONE
{
	Clear();
	int start_x=x;
	int start_y=y;
	drawRect(start_x,start_y,140,15);
	draw_high_line(start_x+10,start_y,10);
	draw_high_line(start_x+30,start_y,10);
	draw_high_line(start_x+59,start_y,10);
	draw_flat_line(start_x,start_y+5,140);
	draw_flat_line(start_x,start_y+10,140);
	gotoxy(start_x+30,start_y+5);
	drawText(start_x+3,start_y+3,"LOAI",WHITE);
	drawText(start_x+18,start_y+3,"SHD",WHITE);
	drawText(start_x+40,start_y+3,"NGAY LAP HOA DON",WHITE);
	drawText(start_x+65,start_y+3,"NHAN VIEN LAP HOA DON",WHITE);
	drawRect(start_x+140,start_y+5,10,5);
	drawText(start_x+141,start_y+7,"ESC=EXIT",GREEN);
	drawText(start_x+5,start_y+8,a.kind,WHITE);
	drawText(start_x+20,start_y+8,a.SHD,WHITE);
	drawNumber(start_x+35,start_y+8,a._Date.ngay,WHITE);
	drawNumber(start_x+40,start_y+8,a._Date.thang,WHITE);
	drawNumber(start_x+45,start_y+8,a._Date.nam,WHITE);
	drawText(start_x+60,start_y+8,NV[vitri]->HO,WHITE);
	drawText(start_x+110,start_y+8,NV[vitri]->TEN,WHITE);
	bool reload = true, press = false, move = false, esc = false, enter = false;
	int from, to, cur1, page, pre = -1, cur2 = 1;
	while(true){
		if (reload){
			page = 1; from = 0; to = a.soluongvattu;
			reload = false;
			ShowrectCTHD(a._Cthd,GetConsoleWidth()/4,2,from,to,t);
		}
		if (move){
			clearRect(GetConsoleWidth()/4-38,19,141,15);
			move = false;
			ShowrectCTHD(a._Cthd,GetConsoleWidth()/4,2,from,to,t);
		}
		KeyPress_1(from,to,page,a.soluongvattu,reload,move,esc);
		if(esc)
		{
		 	esc=false;
			return;
		}	
	}	
}
void ShowrectCTHD(Cthd *lc,int x,int y,int from,int to,Tree t)//DONE
{
	//Clear();
	
	int start_x=x;
	int start_y=y;
	drawRect(start_x-38,y+17,140,30);
	drawText(start_x-30,start_y+15,"MAVT",WHITE);
	draw_high_line(x-20,y+12,35);
	drawText(start_x-15,start_y+15,"TEN VAT TU",WHITE);
	draw_high_line(x,y+12,35);
	drawText(start_x+5,start_y+15,"SO LUONG",WHITE);
	draw_high_line(x+15,y+12,35);
	drawText(start_x+18,start_y+15,"DON GIA 1 CAI",WHITE);
	draw_high_line(x+33,y+12,35);
	drawText(start_x+38,start_y+15,"VAT",WHITE);
	draw_high_line(x+45,y+12,35);
	drawText(start_x+50,start_y+15,"DOANH THU CHUA VAT",WHITE);
	draw_high_line(x+70,y+12,35);
	drawText(start_x+72,start_y+15,"TONG DOANH THU",WHITE);	
	for(int i=from;i<to;i++){
//			// DRAW ELEMENT DATA // PUT ALL THIS IN LOOP TO DRAW
			int doanhthu=lc[i].soluong*lc[i].dongia;
			int tongdoanhthu=doanhthu-doanhthu*0.1;
			Nodetree *k=SearchNodeTree(t,lc[i].MAVT);
			drawText(start_x-30,start_y+4+(i+7-from)*2,lc[i].MAVT,WHITE);
			drawNumber(start_x+8,start_y+4+(i+7-from)*2,lc[i].soluong,WHITE);
			drawNumber(start_x+20,start_y+4+(i+7-from)*2,lc[i].dongia,WHITE);
			drawText(start_x+38,start_y+4+(i+7-from)*2,"10%",WHITE);			
			drawNumber(start_x+48,start_y+4+(i+7-from)*2,doanhthu,WHITE);
			drawText(start_x-15,start_y+4+(i+7-from)*2,k->Iphone.TENVT,WHITE);
			drawNumber(start_x+72,start_y+4+(i+7-from)*2,tongdoanhthu,WHITE);
		}
}
void Copy1(List &Shd)//DONE
{
	Shd.n=0;
	//int h=0;
	for(int i=0;i<soluongnv;i++)
	{
		for(Ldshd *g=NV[i]->_hd;g!=NULL;g=g->pNext)
		{
			strcpy(Shd.a[Shd.n].SHD,g->_Hd.SHD);
			Shd.n++;
		}
	}
}
int Sum(Cthd *a,int n)//DONE
{
	int sum=0;
	for(int i=0;i<n;i++ )
	{		
		sum=sum+(a[i].dongia*a[i].soluong);		
	}
	return sum;
}
void MenuXuatHoaDon(Lhdd &l, bool &esc)//DONE
{
	YOLO:
	system("cls"); // xoa man hình
	// ==================== VE CAI KHUNG - MAY CAI COT ====================== //
	draw_flat_line(0,5,GetConsoleWidth()-1);
	// ==================== VE MAY CAI CHU~ ============================= //
	drawText(GetConsoleWidth()/3,3,"1 . Tu ngay",WHITE);
	drawText(GetConsoleWidth()/2,3,"Den ngay",WHITE);
	drawText(GetConsoleWidth()/2+20,3,"Thang",WHITE);
	drawText(GetConsoleWidth()/2+30,3,"NAM",WHITE);
	char *ch,*cl,*cd,*n;
	ch=InputStrint(GetConsoleWidth()/3+14,3,2,esc);
	if (esc){
		esc = true;
		return ;
	}
	cl=InputStrint(GetConsoleWidth()/2+14,3,2,esc);
	if (esc){
		esc = true;
		return ;
	}
	cd=InputStrint(GetConsoleWidth()/2+27,3,2,esc);
	if (esc){
		esc = true;
		return ;
	}
	n=InputStrint(GetConsoleWidth()/2+35,3,4,esc);
	if (esc){
		esc = true;
		return ;
	}
	system("pause");
	int j,k,m;
	int y;
	j=atoi(ch);
	k=atoi(cl);
	m=atoi(cd);
	y=atoi(n);
	if(m>12||m<1) 	
	{
		gotoxy(GetConsoleWidth()/2,14);
		printf("THANG NGAY NHAP VAO KHONG CHINH XAC");
		getch();
		goto YOLO;
	}	
	if(j>k)
	{
		gotoxy(GetConsoleWidth()/2,14);
		printf("THANG NGAY NHAP VAO KHONG CHINH XAC");
		getch();
		goto YOLO;
	}
	if(nam_nhuan(y)==0&& m==2 &&k>29)
	{
		gotoxy(GetConsoleWidth()/2,14);
		printf("THANG NGAY NHAP VAO KHONG CHINH XAC");
		getch();
		goto YOLO;
	}
	else if(nam_nhuan(y)==0&&m==2 &&k>28){
		gotoxy(GetConsoleWidth()/2,14);
		printf("NAM KO NHUAN KHONG CO NGAY 29");
		getch();
		goto YOLO;
	}
	if(j>31||k>31)
	{
		gotoxy(GetConsoleWidth()/2,14);
		printf("THANG NGAY NHAP VAO KHONG CHINH XAC");
		getch();
		goto YOLO;
	} 
	
	//if(j>k) goto YOLO;
	l.n=0;
	for(int i=j;i<=k;i++)
	{
		for(int q=0;q<soluongnv;q++)
		{

						
			if(NV[q]->_hd!=NULL)
			{			
				for(Ldshd *g=NV[q]->_hd;g!=NULL;g=g->pNext)
				{
					if(g->_Hd._Date.ngay==i&&g->_Hd._Date.thang==m)
					{
						int tong=0;
						tong=Sum(g->_Hd._Cthd,g->_Hd.soluongvattu);					
						l._hdd[l.n].trigia=tong-tong*0.1;
//						//cout<<tong;
//						//system("pause");
						strcpy(l._hdd[l.n].HO,NV[q]->HO);
						strcpy(l._hdd[l.n].TEN,NV[q]->TEN);
						strcpy(l._hdd[l.n].SHD,g->_Hd.SHD);
						strcpy(l._hdd[l.n].Kind,g->_Hd.kind);
						l._hdd[l.n]._date.ngay=g->_Hd._Date.ngay;
						l._hdd[l.n]._date.thang=g->_Hd._Date.thang;
						l._hdd[l.n]._date.nam=g->_Hd._Date.nam;
						l.n++;
					}
				}
			}
		}
	}
	ShowChayHDD(l);
	drawText(GetConsoleWidth()/2+20,14,"ENTER TO CONTINUE",WHITE);	
}
void ShowHdDATE(Lhdd l,int x,int y,int from,int to)//DONE
{
	int start_x=x;
	int start_y=y;
	drawRect(x,y,130,6);
	draw_high_line(x+35,y,6);
	draw_high_line(x+55,y,6);
	draw_high_line(x+65,y,6);
	draw_high_line(x+85,y,6);
	//draw_flat_line(x,y+5,130);
	//draw_flat_line(x,y+7,130);
	//draw_flat_line(x,y+9,130);
	//draw_flat_line(x,y+11,130);
	//draw_flat_line(x,y+13,130);
	//draw_flat_line(x,y+15,130);
	drawText(x+5,y+2,"HO TEN NHAN VIEN LAP",WHITE);
	drawText(x+35+2,y+2,"SO HOA DON",WHITE);
	drawText(x+55+2,y+2,"LOAI",WHITE);
	drawText(x+65+2,y+2,"NGAY LAP HOA DON",WHITE);
	drawText(x+85+10,y+2,"TRI GIA HOA DON",WHITE);
	for(int i=from;i<to;i++)
	{
//		drawText(x+3,y+(i+3-from)*2,l._hdd[i].HO,RED);
//		drawText(x+25,y+(i+3-from)*2,l._hdd[i].TEN,RED);
//		drawText(x+38,y+(i+3-from)*2,l._hdd[i].SHD,RED);
//		drawText(x+60,y+(i+3-from)*2,l._hdd[i].Kind,RED);
//		drawNumber(x+66,y+(i+3-from)*2,l._hdd[i]._date.ngay,WHITE);
//		drawNumber(x+69,y+(i+3-from)*2,l._hdd[i]._date.thang,WHITE);
//		drawNumber(x+72,y+(i+3-from)*2,l._hdd[i]._date.nam,WHITE);
//		drawNumber(x+86,y+(i+3-from)*2,l._hdd[i].trigia,WHITE);
			drawRect(start_x,start_y+(i+3-from)*2,130,2);
			draw_high_line(start_x+35,start_y+(i+3-from)*2,2);
			draw_high_line(start_x+55,start_y+(i+3-from)*2,2);
			draw_high_line(start_x+65,start_y+(i+3-from)*2,2);
			draw_high_line(start_x+85,start_y+(i+3-from)*2,2);
			gotoxy(start_x,start_y+(i+3-from)*2);
			printf("%c",195);
			gotoxy(start_x+35,start_y+(i+3-from)*2);
			printf("%c",197);
			gotoxy(start_x+55,start_y+(i+3-from)*2);
			printf("%c",197);
			gotoxy(start_x+65,start_y+(i+3-from)*2);
			printf("%c",197);
			gotoxy(start_x+85,start_y+(i+3-from)*2);
			printf("%c",197);
			gotoxy(start_x+130,start_y+(i+3-from)*2);
			printf("%c",197);
			drawText(start_x+4,start_y+1+(i+3-from)*2,l._hdd[i].HO,WHITE);
			drawText(start_x+20,start_y+1+(i+3-from)*2,l._hdd[i].TEN,WHITE);
			drawText(start_x+40,start_y+1+(i+3-from)*2,l._hdd[i].SHD,WHITE);
			drawText(start_x+60,start_y+1+(i+3-from)*2,l._hdd[i].Kind,WHITE);
			drawNumber(start_x+70,start_y+1+(i+3-from)*2,l._hdd[i]._date.ngay,WHITE);
			drawNumber(start_x+73,start_y+1+(i+3-from)*2,l._hdd[i]._date.thang,WHITE);
			drawNumber(start_x+75,start_y+1+(i+3-from)*2,l._hdd[i]._date.nam,WHITE);
			drawText(start_x+72,start_y+1+(i+3-from)*2,"/",WHITE);
			drawText(start_x+74,start_y+1+(i+3-from)*2,"/",WHITE);
			drawNumber(start_x+86,start_y+1+(i+3-from)*2,l._hdd[i].trigia,WHITE);
			drawText(start_x+110,start_y+1+(i+3-from)*2,"VND",WHITE);
	}
}
void ShowChayHDD(Lhdd a)//DONE
{
	bool reload = true, press = false, move = false, esc = false, enter = false;
	int from, to, cur1, page, pre = -1, cur2 = 1;
	char c=62;
	//gotoxy(GetConsoleWidth()/2-3,GetConsoleHeight()/2-3);
	//printf("%c",c);
	while(true){
		if (reload){
			//Clear();
			page = 1; from = 0; to = a.n;
			reload = false;
			//drawNumber(GetConsoleWidth()/2-3,GetConsoleHeight()/2+5,page,WHITE);
			ShowHdDATE(a,GetConsoleWidth()/8,10,from,to);						
		}
		if (move){
			//Clear();
			clearRect(GetConsoleWidth()/8,10,60,15);
			move = false;
			ShowHdDATE(a,GetConsoleWidth()/8,10,from,to);
			//drawNumber(GetConsoleWidth()/2-3,GetConsoleHeight()/2+5,page,WHITE);
		}
		KeyPress_1(from,to,page,a.n,reload,move,esc);
		if(esc)
		{		
		 	esc=false;
			return;
		}	
	}	
}
int CheckSHD(Ldshd *p,char x[20])
{
	for(Ldshd *k=p;k!=NULL;k=k->pNext)
	{
		if(strcmp(k->_Hd.SHD,x)==0) return 0;		
	}
	return 1;
}
int SearchHDMAVT(char x[10])//DONE
{
	for(int i=0;i<soluongnv;i++)
	{
		if(NV[i]->_hd!=NULL)
		{
			for(Ldshd *k=NV[i]->_hd;k!=NULL;k=k->pNext)
			{
				if(k->_Hd._Cthd!=NULL)
				{
					for(int j=0;j<k->_Hd.soluongvattu;j++)
					{
						if(strcmp(k->_Hd._Cthd[j].MAVT,x)==0) return 1;
					}
				}	
			}
		}
	}
	return 0;
}
Ldshd *Create(HD &a)//DONE
{
	Ldshd *p=new Ldshd;
	if(p==NULL)
	{
		printf("\nNo more Ram");
	}
	p->_Hd=a;
	p->pNext=NULL;
	return p;
}
void InsertNodeLast1(Ldshd *&a,Ldshd *p)//DONE
{
	if(a==NULL)
	{
		a=p;
	}
	else
	{
		p->pNext = a; 
		a = p;
	}
}
void ShowSHD(List a,int x,int y,int from,int to)//DONE
{
	int start_x=x;
	int start_y=y;
	drawRect(start_x,start_y,10,2);
	//drawFillRect(4,5,10,5,RED);
	drawButton(4,6,GREEN,25,0,"CAC HOA DON HIEN CO"," ");
	drawText(start_x+3,start_y+1,"SHD",WHITE);
	//Message(f)
	drawButton(4,20,PINK,25,0,"F1 OR ESC","BACK ");
	drawButton(4,25,YELLOW,25,0,"F2","TRA CUU SO HOA DON ");
		gotoxy(GetConsoleWidth()/2,GetConsoleHeight()/2-4);
	char c1=60;
	printf("%c",c1);
	char c2=62;
	gotoxy(GetConsoleWidth()/2+8,GetConsoleHeight()/2-4);
	printf("%c",c2);
   	int k = y;
   for(int i=from;i<to;i++)
   { 		
   		drawRect(start_x,start_y+(i+1-from)*2,10,2);
   		gotoxy(start_x,start_y+(i+1-from)*2);
   		printf("%c",195);
   		gotoxy(start_x+10,start_y+(i+1-from)*2);
		printf("%c",180);
		drawText(start_x+2,start_y+(i+1-from)*2+1,a.a[i].SHD,WHITE);
   }
}
void SaveCTHDFULL(FILE *f,Cthd a)//DONE
{
	fprintf(f,"%s\n",a.MAVT);
	fprintf(f,"%0.f\n",a.soluong);
	fprintf(f,"%0.f\n",a.dongia);
	fprintf(f,"%0.f\n",a.vat);
}
void SaveFileListHd()
{
	FILE *fp=fopen("Hoadon.txt","w");
	for(int i=0;i<soluongnv;i++)
	{	
		for(Ldshd *k=NV[i]->_hd;k!=NULL;k=k->pNext)
		{
			fprintf(fp,"%s\n",NV[i]->MANV);
			fprintf(fp,"%s\n",k->_Hd.kind);
			fprintf(fp,"%s\n",k->_Hd.SHD);
			fprintf(fp,"%d\n",k->_Hd._Date.thang);
			fprintf(fp,"%d\n",k->_Hd._Date.ngay);
			fprintf(fp,"%d\n",k->_Hd._Date.nam);
		}
	}
	fclose(fp);
}


void Menu2(Tree &t)
{
	Cursor(false);
	SetConsoleTitle("CHUONG TRINH QUAN LI VAT TU");
	bool esc = false;
	bool esc1 = false;
	resizeConsole();
	typedef char str[31];	
	string thaotac1[7]={"THONG TIN VAT TU","HIEU CHINH VAT TU","THONG TIN NHAN VIEN","HIEU CHINH NHAN VIEN","THEM HOA DON","XUAT HOA DON","XUAT HOA DON THEO NGAY"};
	// Title();
	int pre = -1, cur = 1, x = GetConsoleWidth()/2.2;
	char c;
	bool press = true, enter = false;
	drawTitle_1(GetConsoleWidth()/2.5,1);
	for(int i=1;i<=7;i++){
		drawText(x,(i*2)+10,thaotac1[i-1],WHITE);
	}	
	while(true){
		if (cur > 7) cur = 1;
		if (cur < 1) cur = 7;	
		if (press){
			press = false;
			if (pre != -1){
				drawText(x,(pre*2)+10,thaotac1[pre-1],WHITE);
			}
			drawText(x,(cur*2)+10,thaotac1[cur-1],GREEN);
		} 
		Keypress(pre,cur,enter,press,esc1);
		if(esc1)
		{
			Cursor(true);
			Clear();
			drawRect(GetConsoleWidth()/2-15,GetConsoleHeight()/2-5,50,10);
			drawText(GetConsoleWidth()/2+5-15,GetConsoleHeight()/2+3-5,"LUU LAI PHIEN LAM VIEC.AN Y(YES) OR N(NO)",YELLOW);
			if(Yes())
			{
				FILE *fp=fopen("Vattu.txt","w");
				SaveFile(t,fp);
				fclose(fp);										
				SaveListNV();
				SaveFileListHd();
				SaveFileHd12();
				return;
			}
			else
			{
				return;
			}			
		}
		if (enter){
			Cursor(false);
			rewind(stdin);
			Vattu e;
			int f=0;
			e.n=0;
			Preorder1(t,f,e);
			OrderNameVattu(e);
			enter = false;
			int flag=-1;
			switch(cur){
				//Clear();				
				case 1: // Thong tin vat tu
				{	
					Clear();
					OrderNameVattu(e);
					printf("\n");
					ShowChayVattu(e);
				}
				break;
				
				case 2: // hieu chinh vat tu
				{
					AGAIN1:
					Clear();
					drawRect(GetConsoleWidth()/3,GetConsoleHeight()/4,40,5);
					drawText(GetConsoleWidth()/3+3,GetConsoleHeight()/4+2,"TEN DANG NHAP",WHITE);
					drawText(GetConsoleWidth()/3+3,GetConsoleHeight()/4+3,"PASSWORD",WHITE);
					char *name;
					name=InputStr(GetConsoleWidth()/3+20,GetConsoleHeight()/4+2,10,esc1);
					if(esc1)
					{
							esc1=false;
							break;
					}
					char *pass;
					pass=InputPassword(GetConsoleWidth()/3+20,GetConsoleHeight()/4+3,10,esc1);
					if(esc1)
					{
							esc1=false;
							break;
					}
					if(strcmp(name,"admin")==0&&strcmp(pass,"admin")==0)
					{
						Infortree h;
						ShowChayVattuHieuChinh(e,t,h,esc);
						if (esc)
						{
							esc = false;
							break;
						}
					}
					else
					{
						drawText(GetConsoleWidth()/3+3,GetConsoleHeight()/4+5," SAI PASSWORD HOAC TEN DANG NHAP",YELLOW);
						getch();
						goto AGAIN1;
					}	
				}
				break;

			
				case 3: // thong tin nhan vien
				{
					AGAIN2:
					Clear();
					drawRect(GetConsoleWidth()/3,GetConsoleHeight()/4,40,5);
					drawText(GetConsoleWidth()/3+3,GetConsoleHeight()/4+2,"TEN DANG NHAP",WHITE);
					drawText(GetConsoleWidth()/3+3,GetConsoleHeight()/4+3,"PASSWORD",WHITE);
					char *name;
					name=InputStr(GetConsoleWidth()/3+20,GetConsoleHeight()/4+2,10,esc1);
					if(esc1)
					{
							esc1=false;
							break;
					}
					char *pass;
					pass=InputPassword(GetConsoleWidth()/3+20,GetConsoleHeight()/4+3,10,esc1);
					if(esc1)
					{
							esc1=false;
							break;
					}
					if(strcmp(name,"admin")==0&&strcmp(pass,"admin")==0)
					{
					//Clear();
						Dsnv nv;
					//OrderNameNV();
						ShowChay(nv);
					}
					else
					{
						drawText(GetConsoleWidth()/3+3,GetConsoleHeight()/4+5," SAI PASSWORD HOAC TEN DANG NHAP",YELLOW);
						getch();
						goto AGAIN2;
					}				
				}
				break;
				case 4: // HIEU CHING NHAN VIEN
				{
					HIEUCHINH:
					Clear();
					Cursor(true);	
					drawRect(GetConsoleWidth()/3,GetConsoleHeight()/4,40,5);
					drawText(GetConsoleWidth()/3+3,GetConsoleHeight()/4+2,"TEN DANG NHAP",WHITE);
					drawText(GetConsoleWidth()/3+3,GetConsoleHeight()/4+3,"PASSWORD",WHITE);
					char *name;
					name=InputStr(GetConsoleWidth()/3+20,GetConsoleHeight()/4+2,10,esc1);
					if(esc1)
					{
							esc1=false;
							break;
					}
					char *pass;
					pass=InputPassword(GetConsoleWidth()/3+20,GetConsoleHeight()/4+3,10,esc1);
					if(esc1)
					{
							esc1=false;
							break;
					}
					if(strcmp(name,"admin")==0&&strcmp(pass,"admin")==0)
					{
						Dsnv nv;									
						ShowChayNhanvienHieuChinh(esc1,nv);
						if(esc1)
						{
							esc1=false;
						}
					}
					else
					{
						drawText(GetConsoleWidth()/3+3,GetConsoleHeight()/4+5," SAI PASSWORD HOAC TEN DANG NHAP",YELLOW);
						getch();
						goto HIEUCHINH;
					}
					Cursor(false);		
				}
				//break;
				break;
				case 5: // them hoa don
				{
					int vitri;
					HD c;
					FormHoadon(GetConsoleWidth()/3,10,c,esc,vitri,t);
					if(esc)
					{
						esc=false;
						break;
					}
					Clear();
					drawRect(GetConsoleWidth()/3,GetConsoleHeight()/3,60,10);
					drawText(GetConsoleWidth()/3+5,GetConsoleHeight()/3+3,"XIN HAY CHAC CHAN VI DA THEM VAO KHONG XOA DC",YELLOW);
					drawText(GetConsoleWidth()/3+5,GetConsoleHeight()/3+5,"AN Y(YES) HOAC N(NO)",YELLOW);
					if(Yes())	
					{								
						Ldshd *p=Create(c);				
						InsertNodeLast1(NV[vitri]->_hd,p);
						break;
					}
					else
					{
						break;
					}				
				}	
				break;
				case 6: // xuat hoa don		
				{
					LALA:
					Clear();					
					List a;
					Copy1(a);
					ShowChaySHD(a,t);
					getch();	
				}
				break;
				case 7:
				{	
					Lhdd lhd;				
					MenuXuatHoaDon(lhd,esc1);
					if (esc1){
						esc1 = false;
						break;
					}
					
					//getch();
				}
				break;
				case 10:
				{	
					cout<<"aaa";			
				}
				break;	
			}
			Cursor(false);	
			Clear();
			for(int i=1;i<=7;i++){
				drawText(x,(i*2)+10,thaotac1[i-1],WHITE);
			}
			press = true;
			drawTitle_1(GetConsoleWidth()/2.5,1);
		}
	}
}
int main()
{
	bool esc=false;
	Tree t;
	Intialize_Tree(t);	
	FILE *fp=fopen("Vattu.txt","r");
	ReadPreorder(t,fp);
	fclose(fp);
	ReadAllNV();
	//Dsnv k;
	ReadHd();
	Menu2(t);
	//CopyNV(k);	
	return 0;
}

