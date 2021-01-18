#include<stdio.h>
#include<windows.h>
	int main(){
	//Deskripsi: Modul untuk menampilkan landing page
	//I.S.: Landing massage belum tetampilkan
	//F.S.: landing massage tertamplkan
	
	//deklarasi
	int a=0;
	//Algoritma
	do{
		a=a+1;
			printf("%d %%", a);
			printf("Loading . . . ");
		system("cls");
	}
	while(a<=100);
	printf("Start the Game . . . ");

	return 0;
	}
