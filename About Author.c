//keterangan mengenai para pembuat game
#include<stdio.h>
	int main(){
		//deklarasi
		int a;
		
		//logaritma
		printf("pilih salah satu author:1.Arsal Fadilah\n 		        2.Nauval Ozora Mahadri\n");
		printf("Pilih No Author:");
		scanf("%d", &a);
		
		//cek kesalahan pilihan
		if(a<1 || a>2){
			system("cls");
			printf("Nomer Author yang anda masukan salah !!!\n");
            printf("Coba lagi\n");
        system("pause");
        system("cls");
		}else{
		if(a<2){
				printf("Nama : Arsal Fadilah\n");
				printf("Tempat, Tanggal Lahir : Bandung, 26 April 2002\n");
				printf("Jenis Kelamin : Laki-laki\n");
				printf("Agama : Islam\n");
				printf("Alamat : Kp. Cidawolong 1 Rt 03/14 Des.Biru Kec.Majalaya Kab.Bandung\n");
				printf("Nomor Telepon : 081214151280\n");
				printf("E-mail : arsalfadilah2002@gmail.com\n");
				printf("Hobi : Basket\n");
				printf("Motto Hidup : Never give up ! Trust me its work");
			}else{
				printf("Nama : Nauval Ozora Mahadri\n");
				printf("Tempat, Tanggal Lahir : Bandung, 29 Juli 2002\n");
				printf("Jenis Kelamin : Laki-laki\n");
				printf("Agama : Islam\n");
				printf("Alamat : Jalan Cibangkong Tengah RT.09/RW.11 NO.300/120\n");
				printf("Alamat Asal : Kp. Cidawolong 1 Rt 03/14 Des.Biru Kec.Majalaya Kab.Bandung\n");
				printf("Nomor Telepon : 085624333058\n");
				printf("E-mail : ozoramahadri02@gmail.com\n");
				printf("Hobi : baca\n");
				printf("Motto Hidup : gak ada yang gak bisa\n");
			}
		}		
		return 0;
	}
