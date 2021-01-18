/*	Author			: Nauval Ozora Mahadri
	Deskripsi		: Bantuan pengarahan bagi pemain baru
============================================================*/
#include<stdio.h>
#include<windows.h>
	int main(){
		printf("HELP");
		printf("======================================================================================================\n");
		printf("1. Player pertama akan diminta mengisi kolom dan baris yang diinginkan seusai keinginan\n");
		printf("2. Giliran main akan dilempar ke player kedua setelah n(5,10, atau 15) detik\n");
		printf("3. Player kedua akan mendapat gilirannya untuk mengisi kolom dan baris yang belum terisi\n");
		printf("4. Langkah 1 - 3 akan diulangi terus sampai ada salah satu player yang berhasil\n");
		printf("   mengurutkan X/O sebanyak tiga kali secara berurutan atau bidang permainan sudah penuh\n");		
		printf("5. Jika permainan sudah selesai, maka game akan meminta inputan untuk melanjutkan permainan atau tidak.");
		return 0;
	}
