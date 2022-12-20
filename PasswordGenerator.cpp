#include <iostream>
#include <conio.h>
#include <dos.h> 
#include <windows.h>
#include <time.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void setcursor (bool visible, DWORD size) {
	if (size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

void drawBorder(int x=0, int y=0){
	char v = 186;
    char h = 205;
    char tr = 187;
    char br = 188;
    char tl = 201;
    char bl = 200;
    int width = 24;
    int height = 4;
    
    gotoxy (x + 4, y); cout << "Password Generator";
    
    for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++){
	    	gotoxy (j + x,i + y);
	    	if (i == 1 && j == 1) cout<< tl;
			else if(i == height && j == 1) cout << bl;
	    	else if(i == 1 && j == width) cout << tr;
			else if(i == height && j == width) cout << br;
			else if(i == 1 || i == height) cout << h;
			else if(j == 1 || j == width) cout << v;
		}
	}
}

int main() {
    srand((unsigned) time(NULL));
	setcursor(0,0);  
	
	system("cls");
 	  
 	int complexity;
 	int length;
 	
	char op;
	do {
		system("cls");
		
		cout << "\n\n";
		cout << "|-------------------------------------|" << endl;
		cout << "|        PASSWORD GENERATOR           |" << endl;
		cout << "|-------------------------------------|" << "\n\n";
		
		cout << "Seleziona una delle due opzioni: " << "\n\n";
		
		
		do {
			cout << "[1] Semplice   |   [2] Difficile" << endl;
			cout << endl << "Opzioni [1 / 2]: ";
			cin >> complexity;
			
			if (complexity < 1 || complexity > 2)
				cout << "[Errore] Valore non valido." << endl;
		} while (complexity < 1 || complexity > 2 );
		
		if ( complexity == 1) length = 8;
		else if (complexity == 2) length = 14;
		else length = 20;
	
		char pass[21] = "";
		
		int i;
		for (i = 0; i < length; i++) {
			if (complexity == 1) {
				if(rand()%2 == 0)
					pass[i] = 97 + rand()%26;
				else
					pass[i] = 48 + rand()%10;
			}
			else if ( complexity == 2 ){
				if ( rand()%3 == 0 )
					pass[i] = 97 + rand()%26;
				else if ( rand()%3 == 1 )
					pass[i] = 65 + rand()%26;
				else
					pass[i] = 48 + rand()%10;
			}
			else if ( complexity == 2 ){
				if ( rand()%4 == 0 )
					pass[i] = 97 + rand()%26;
				else if( rand()%4 == 1 )
					pass[i] = 65 + rand()%26;
				else if( rand()%4 == 2 )
					pass[i] = 33 + rand()%15;
				else
					pass[i] = 48 + rand()%10;
			}
		}
		pass[i] = '\0';
		
		cout<<"\n\n\t\t    [La Password si sta generando..] \n\t\t\t";
		for (int i = 0; i < 10; i++){
			cout << (char)176;
			Sleep(200);
		}
		
		system("cls");
		drawBorder(8,5);
		
		gotoxy(11,8); cout << pass;
		
		gotoxy(10,15); cout << "Desideri generale una nuova Password? [y / n]: ";
		op = getch();
	} while(op == 'y' || op == 'Y');
	
    return 0;
}