#include<stdio.h>
#include<windows.h>
	COORD 	coord={X:0,Y:0};
	void gotoxy(int x, int y){
		coord.X= x;
		coord.Y= y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	int main(){
	//Deskripsi: Modul untuk menampilkan landing page
	//I.S.: Landing massage belum tetampilkan
	//F.S.: landing massage tertamplkan
	
	//deklarasi
	int a=0;
	//Algoritma
	do{
		a=a+1;
			gotoxy(50,18);	printf("%d %%", a);
			gotoxy(45,20);	printf("Loading . . . ");
		system("cls");
	}
	while(a<=100);
	gotoxy(43,16);printf("Start the Game . . . ");

	return 0;
	}
