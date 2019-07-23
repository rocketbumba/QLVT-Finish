char *InputStr(int x, int y, int maxlen, bool &esc){ 
	string tmp; // = ""
	char c, *a = new char[maxlen];
	gotoxy(x,y);
	while(true){
		c = getch(); // c = a 
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){ // 32 = SPACE
			if (tmp.size() < maxlen){
				tmp.push_back(c); // tmp = "a"
				printf("%c",c); 
			}
		}
		if (c == 32 && tmp.size() > 0 && tmp.size() < maxlen){
			tmp.push_back(c); // tmp = "a"
			printf("%c",c);
		}
		if (c == 8 && tmp.size() != 0){ // BACKSPACE
			tmp.erase(tmp.size()-1,1); // xóa kí tu cuoi trong string tmp
			printf("\b \b"); // In ra khoang trong bi. xóa
		}
		if (c == 13 && tmp.size() != 0){ // ENTER
			strcpy(a,tmp.c_str());
			return a; // convert string thành const char
		}
		if (c == 27){ // ESC
			esc = true;
			return a=new char[maxlen];
		}
	}
}
char *InputStrint(int x, int y, int maxlen, bool &esc){ 
	string tmp; // = ""
	char c, *a = new char[maxlen];
	gotoxy(x,y);
	while(true){
		c = getch(); // c = a 
		if ( c >= '0' && c <= '9' ){ // 32 = SPACE
			if (tmp.size() < maxlen){
				tmp.push_back(c); // tmp = "a"
				printf("%c",c); 
			}
		}
		if (c == 8 && tmp.size() != 0){ // BACKSPACE
			tmp.erase(tmp.size()-1,1); // xóa kí tu cuoi trong string tmp
			printf("\b \b"); // In ra khoang trong bi. xóa
		}
		if (c == 13 && tmp.size() != 0){ // ENTER
			strcpy(a,tmp.c_str());
			return a; // convert string thành const char
		}
		if (c == 27){ // ESC
			esc = true;
			//strcpy()
			return a;
		}
	}
}
char *InputStrIO(int x, int y, int maxlen, bool &esc){ 
	string tmp; // = ""
	char c, *a = new char[maxlen];
	gotoxy(x,y);
	while(true){
		c = getch(); // c = a 
		if ( c == 'N' || c == 'X'||c == 'n' || c == 'x' ){ // 32 = SPACE
			if (tmp.size() < maxlen){
				tmp.push_back(c); // tmp = "a"
				printf("%c",c); 
			}
		}
		if (c == 8 && tmp.size() != 0){ // BACKSPACE
			tmp.erase(tmp.size()-1,1); // xóa kí tu cuoi trong string tmp
			printf("\b \b"); // In ra khoang trong bi. xóa
		}
		if (c == 13 && tmp.size() != 0){ // ENTER
			strcpy(a,tmp.c_str());
			return a; // convert string thành const char
		}
		if (c == 27){ // ESC
			esc = true;
			return a;
		}
	}
}
void KeyPress_1( int &from, int &to, int &page, int maxlen, bool &reload, bool &move, bool &esc){
	char c; 
	c = getch();
	if (c == -32){
		c = getch();
		if (c == 75){ // left arrow - Lui
			if (from != 0){ 
				move = true;
				to = from;
				page--;
			}
			if (from - 10 < 0){ 
				from = 0;
			}
			else from -= 5;
		}
		if (c == 77){ // right arrow - Tien
			if (to != maxlen){ // Neu to van~ con` co` the~ tien toi thi` tiep tuc 
				move = true;
				from = to;
				page++;
			} 
			// vd: from = 0, to = 10, in ra array tu 0->9, thi minh chi can gan from = to se` in ra bat dau o ptu~ 10
			if (to + 5 > maxlen){ // Neu to+10 > do dai ds thi` set to = max length cua~ ds
				to = maxlen;
			}
			else to += 5; // neu ko thi` to += 10
		}
	}
	if (c == 27) esc = true;
}
void KeyPress_3( int &cur, int &from, int &to, int &page, int maxlen, bool &reload, bool &press, bool &move, bool &esc){
	char c; // Lay ds mon hoc lam` vi du.
	c = getch();
	if (c == 0){
		c = getch();
		if (c == 59){ // F1: Them Mon Hoc
			cur = 2; press = true;
		}
		if(c==60)
		{
			cur=1;press=true;
		}
	}
	if (c == -32){
		c = getch();
		if (c == 75){ // left arrow - Lui
			if (from != 0){ // Neu from = 0 thi` ko can` phai~ chuyen~ trang
				move = true;
				to = from;
				page--;
			}
			if (from - 10 < 0){ // Neu dang o~ trang dau tien thi` ko can` phai~ thay doi~ thong so
				from = 0;
			}
			else from -= 5;
		}
		if (c == 77){ // right arrow - Tien
			if (to != maxlen){ // Neu to van~ con` co` the~ tien toi thi` tiep tuc 
				move = true;
				from = to;
				page++;
			} 
			// vd: from = 0, to = 10, in ra array tu 0->9, thi minh chi can gan from = to se` in ra bat dau o ptu~ 10
			if (to + 5 > maxlen){ // Neu to+10 > do dai ds thi` set to = max length cua~ ds
				to = maxlen;
			}
			else to += 5; // neu ko thi` to += 10
		}
	}
	if (c == 27) esc = true;
}
void Keypress(int &pre, int &cur, bool &enter, bool &press,bool &esc){
	char c = getch();
	if (c == -32){
		c = getch();
		if (c == 72){ // UP
			pre = cur--; press = true;
		}
		if (c == 80){ // DOWN
			pre = cur++; press = true;
		}
	}
	if (c == 27){ // ESC
		esc=true;
	}
	if (c == 13){ // ENTER
		enter = true;
	}
}
void DeleteChar(char x[],int vitri)
{
	int n=strlen(x);
	for(int i=vitri+1;i<n;i++)
	{
		x[i-1]=x[i];
	}
	x[n-1]='\0';
}
void DeleteSpace(char x[])
{
	while(1)
	{
		if(x[0]==' ') DeleteChar(x,0);
		else break;
	}
}
char *InputStrYN(int x, int y, int maxlen, bool &esc){ 
	string tmp; // = ""
	char c, *a = new char[maxlen];
	gotoxy(x,y);
	while(true){
		c = getch(); // c = a 
		if (c == 'y' && c == 'n' || c == 'Y'){ // 32 = SPACE
			if (tmp.size() < maxlen){
				tmp.push_back(c); // tmp = "a"
				printf("%c",c); 
			}
		}
		if (c == 8 && tmp.size() != 0){ // BACKSPACE
			tmp.erase(tmp.size()-1,1); // xóa kí tu cuoi trong string tmp
			printf("\b \b"); // In ra khoang trong bi. xóa
		}
		if (c == 13 && tmp.size() != 0){ // ENTER
			strcpy(a,tmp.c_str());
			return a; // convert string thành const char
		}
		if (c == 27){ // ESC
			esc = true;
			return a=new char[maxlen];
		}
	}
}
bool Yes(){
	char c;
	while(true){
		c = getch();
		if (c == 'y' || c == 'Y') return true;
		else if ( c == 'n' || c == 'N') return false;
	}
}
char *InputPassword(int x, int y, int maxlen, bool &esc){ 
	string tmp; // = ""
	char c, *a = new char[maxlen];
	gotoxy(x,y);
	while(true){
		c = getch(); // c = a 
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == 32){ // 32 = SPACE
			if (tmp.size() < maxlen){
				tmp.push_back(c); // tmp = "a"
				printf("*"); 
			}
		}
		if (c == 8 && tmp.size() != 0){ // BACKSPACE
			tmp.erase(tmp.size()-1,1); // xóa kí tu cuoi trong string tmp
			printf("\b \b"); // In ra khoang trong bi. xóa
		}
		if (c == 13 && tmp.size() != 0){ // ENTER
			strcpy(a,tmp.c_str());
			return a; // convert string thành const char
		}
		if (c == 27){ // ESC
			esc = true;
			return a=new char[maxlen];
		}
	}
}
