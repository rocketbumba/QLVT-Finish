#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// H�m thay d?i k�ch c? c?a khung cmd v?i tham s? truy?n v�o l� chi?u cao, chi?u r?ng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// H�m t� m�u.
void Clear(){
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordScreen = { 0, 0 }; 
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi; 
	DWORD dwConSize;
	if( !GetConsoleScreenBufferInfo( hStdout, &csbi )){
		return;
	}
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
   if( !FillConsoleOutputCharacter( hStdout,        // Handle to console screen buffer 
                                    (TCHAR) ' ',     // Character to write to the buffer
                                    dwConSize,       // Number of cells to write 
                                    coordScreen,     // Coordinates of first cell 
                                    &cCharsWritten ))// Receive number of characters written
   {
      return;
   }
   if( !GetConsoleScreenBufferInfo( hStdout, &csbi )){
      return;
   }
   if( !FillConsoleOutputAttribute( hStdout,         // Handle to console screen buffer 
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize,        // Number of cells to set attribute 
                                    coordScreen,      // Coordinates of first cell 
                                    &cCharsWritten )) // Receive number of characters written
   {
      return;
   }
   SetConsoleCursorPosition( hStdout, coordScreen );
}
void SetConsolePos(int x,int y){
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos( consoleWindow, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER );
}
void ShowCur(bool CursorVisibility){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}
void GotoXY (int column, int line){
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void TextColor (int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
