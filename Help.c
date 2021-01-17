/*	Author			: Nauval Ozora Mahadri
	Deskripsi		: Bantuan pengarahan bagi pemain baru
============================================================*/
#include<stdio.h>
#include<windows.h>
	COORD 	coord={X:0,Y:0};
	void gotoxy(int x, int y){
		coord.X= x;
		coord.Y= y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	int main(){
		gotoxy(60,1);printf("HELP");
		gotoxy(10,2);printf("======================================================================================================");
		gotoxy(10,3);printf("1. Player pertama akan diminta mengisi kolom dan baris yang diinginkan seusai keinginan\n");
		gotoxy(10,4);printf("2. Giliran main akan dilempar ke player kedua setelah n(5,10, atau 15) detik\n");
		gotoxy(10,5);printf("3. Player kedua akan mendapat gilirannya untuk mengisi kolom dan baris yang belum terisi\n");
		gotoxy(10,6);printf("4. Langkah 1 - 3 akan diulangi terus sampai ada salah satu player yang berhasil\n");
		gotoxy(10,7);printf("   mengurutkan X/O sebanyak tiga kali secara berurutan atau bidang permainan sudah penuh\n");		
		gotoxy(10,8);printf("5. Jika permainan sudah selesai, maka game akan meminta inputan untuk melanjutkan permainan atau tidak.");
		return 0;
	}
