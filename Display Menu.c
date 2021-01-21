//Modul Display Menu
//Akan menampilkan menu awal bagi player yang baru memasuki game
//I.S = layar kosong
//F.s = akan terlihat tampilan menu

int main(){
	
	//Deklarasi
	int choice;
	
	//Algoritma
	do{
		printf("MENU");
		printf("-------------------------------");
		printf(" 1. Start Game");
		printf(" 2. High Score");
		printf(" 3. Help");
		printf(" 4. About Author");
		printf(" 5. Exit Game");
		printf("Pilih menu : ");scanf("%d", &choice);

		if(choice == 1){ playGame(); }
		else if(choice == 2){ highScore(); }
		else if(choice == 3){ help(); }
		else if(choice == 4){ aboutAuthor(); }
	while(choice!=5)

	return 0;
}
