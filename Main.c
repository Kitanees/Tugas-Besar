#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<mmsystem.h>
//Authors : Arsal Fadilah && Nauval Ozora

/*kumpulan modul*/
void LoadDisplay();
void DisplayMenu();
int InputMenu();
void StartGame();
int ChooseEnemy();
int ChooseLevel();
void InpuNama();
void PlayerVsPlayer();
int suit();
void Easy();
void DisplayBoard();
void persiapanMatrix();
void PlayTheGame();
int StartTime();
int EndTime();
void p_1_InputX(int* x, int* y, double *waktuInput);
void p_2_InputO(int* x, int* y, double *waktuInput);
bool CekSel(int x, int y);
bool CekBar();
bool CekBarCom();
void inputInBarCom(int *x, int *y);
bool CekCol();
bool CekColCom();
void inputInColCom(int *x, int *y);
bool CekDiagon();
bool CekDiagonRLCom();
bool CekDiagonLRCom();
void inputInDiagonCom(int *x, int *y);
void inputRandCom(int *x, int *y);
bool CekPenuh();
void GameOver();
void Medium();
void Hard();
void PlayerVsComputer();
void p_com_InputO(int *x, int *y, double *waktuInput);
void PlayGame_1();
void PlayGame_2();
void PlayGame_3();
void PlayGame_4();
void yourGame();
void HighScores();
void Help();
void AboutAuthor();
void loadGame();
void savedGame();
void exitGame();
void tampilan_awal();

/*modul interface*/
void SetColor(int ForgC);
void gotoxy();
//variabel interface
int tampilX, tampilY;

//variabel global
int ukuran, bonus;
double waktu;
struct dataPlayer {
    int posisi;
    int enemy;
    int level;
    int menangSuit;
    int score_1;
    int score_2;
    char nama[20];
    char nama_2[20];
    char matrix_2D[12][12];
    bool mulai;
} data;

//modul utama
int main() {

    //set background
    system("color 0B");

    //play backsound
    /*PlaySound(TEXT("themesong.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    if((data.posisi!=1 ||data.score_2 != 2) && !data.mulai){
        LoadDisplay();
    }*/

    //inisialisasi var
    ukuran = 0;
    data.posisi = 0;
    data.score_1 = 0;
    data.score_2 = 0;
    data.mulai = true;
    
    tampilan_awal();
    system("cls");

menu:
    DisplayMenu();
    switch (InputMenu()) {
    case 1: StartGame(); break;
    case 2: loadGame(); break;
    case 3: HighScores(); break;
    case 4: Help(); break;
    case 5: AboutAuthor(); break;
    case 6: exitGame(); break;
    default:
        gotoxy(50, 13);printf("WRONG INPUT NUMBER.\n");
        gotoxy(33, 14);printf("Pilih Nomer Aja Salah, Apalagi Pilih Pasangan Hidup -.-\n\n");
        gotoxy(45, 15);system("pause");
        system("cls");
        goto menu;
    }

    return 0;
}

void LoadDisplay() {
    int i=0;
    tampilX = 50;
    tampilY = 13;

    system("cls");
        gotoxy(tampilX+5, tampilY); printf("%d %%\n", i);
        gotoxy(tampilX+2, tampilY+1); printf("Loading -");
    for(i=1; i<=100; i++){
        gotoxy(tampilX+5, tampilY); printf("%d %%\n", i);
        if((1+i)%5==0){
            gotoxy(tampilX+2, tampilY+1); printf("Loading -");
        }else if ((1+i)%4==0){
            gotoxy(tampilX+3, tampilY+1); printf("Loading \\");
        } else if ((1+i)%3==0){
            gotoxy(tampilX+2, tampilY+1); printf("Loading |");
        }  else if ((1+i)%2==0){
            gotoxy(tampilX+2, tampilY+1); printf("Loading /");
        }
        gotoxy(tampilX+12, tampilY+1);system("cls");
    }


}

void DisplayMenu() {
    tampilX=30;
    tampilY=10;

    system("cls");

    gotoxy(tampilX, tampilY);printf("|||||||||||||||||||||||| MENU |||||||||||||||||||||||\n");
    gotoxy(tampilX, tampilY+1);printf("=====================================================\n");
    gotoxy(tampilX+2, tampilY+2);printf("1. Play Game\n");
    gotoxy(tampilX+2, tampilY+3);printf("2. Load Game\n");
    gotoxy(tampilX+2, tampilY+4);printf("3. High Score\n");
    gotoxy(tampilX+2, tampilY+5);printf("4. Help\n");
    gotoxy(tampilX+2, tampilY+6);printf("5. About Author\n");
    gotoxy(tampilX+2, tampilY+7);printf("6. Exit\n\n");
    gotoxy(tampilX, tampilY+9);printf("Silahkan Pilih Menu Anda : ");

}

int InputMenu() {
    int x, tambah=0;

    while(scanf("%d", &x)!= 1 && getchar() != '\n'){
        gotoxy(tampilX, tampilY+10+tambah);printf("! ONLY INTEGER ! ==> ");
        tambah++;
    }

    system("cls");

    return x;
}

void StartGame() {

    data.enemy = ChooseEnemy();
    data.level = ChooseLevel();
    data.posisi = 0;

    switch (data.enemy) {
        case 1: PlayerVsPlayer(); break;
        case 2: PlayerVsComputer(); break;
    }

}

int ChooseEnemy() {
    int x, tambah=0;
    tampilX = 45;
    tampilY = 11;

    gotoxy(tampilX+10, tampilY);printf("Pilih Lawan Bermain\n");
    gotoxy(tampilX, tampilY+1);printf("=============================\n");
    gotoxy(tampilX+2, tampilY+2);printf("1. Player  Vs Player \n");
    gotoxy(tampilX+2, tampilY+3);printf("2. Player Vs Komputer\n\n");
    gotoxy(tampilX, tampilY+5);printf("Pilihan Kamu : ");
    while(scanf("%d", &x)!= 1 && getchar() != '\n'){
        gotoxy(tampilX, tampilY+6+tambah);printf("! ONLY INTEGER ! ==> ");
        tambah++;
    }
    system("cls");

    if(x==1 || x==2){
        return x;
    }else {
        gotoxy(tampilX, tampilY+6);printf("Ops, anda salah input\n");
        gotoxy(tampilX, tampilY+7);system("pause");
        system("cls");
        return ChooseEnemy();
    }

}

int ChooseLevel() {
    int x, tambah=0;
    tampilX = 45;
    tampilY = 10;

    gotoxy(tampilX+3, tampilY);printf("Pilih Level Kemampuanmu!\n");
    gotoxy(tampilX, tampilY+1);printf("=============================\n");
    gotoxy(tampilX+2, tampilY+2);printf("1. Amateur\n");
    gotoxy(tampilX+2, tampilY+3);printf("2. Professional\n");
    gotoxy(tampilX+2, tampilY+4);printf("3. Legend\n");
    gotoxy(tampilX+2, tampilY+5);printf("4. Your Own Game\n\n");
    gotoxy(tampilX, tampilY+7);printf("Pilihan Kamu : ");
    while(scanf("%d", &x)!= 1 && getchar() != '\n'){
        gotoxy(tampilX, tampilY+8+tambah);printf("! ONLY INTEGER ! ==> ");
        tambah++;
    }
    system("cls");

    if(x>=1 && x<=4){
       return x;
    } else {
        gotoxy(tampilX, tampilY+8);printf("Ops Anda Salah Menginputkan Pilihan!\n");
        gotoxy(tampilX, tampilY+9);system("pause");
        system("cls");
        return ChooseLevel();
    }

}

void InpuNama() {
    tampilX = 43;
    tampilY = 13;

    if(data.enemy==1){
        gotoxy(tampilX+2, tampilY);printf("Nama Player 1 (X) : ");
        fgets(data.nama, sizeof(data.nama), stdin);
        data.nama[strlen(data.nama) - 1] = '\0';
        scanf("%[^\n]s", data.nama);
        gotoxy(tampilX+2, tampilY+1);printf("Nama Player 2 (O) : ");
        fgets(data.nama_2, sizeof(data.nama_2), stdin);
        data.nama_2[strlen(data.nama_2) - 1] = '\0';
        scanf("%[^\n]s", data.nama_2);
    } else {
        gotoxy(tampilX, tampilY);printf("Nama Kamu : ");
        fgets(data.nama, sizeof(data.nama), stdin);
        data.nama[strlen(data.nama) - 1] = '\0';
        scanf("%[^\n]s", data.nama);
        strcpy(data.nama_2, "Arva_Com");
        gotoxy(tampilX, tampilY+1);printf("Nama Komputer : %s\n", data.nama_2);
        gotoxy(tampilX, tampilY+2);system("pause");

    }

}

void PlayerVsPlayer() {

    InpuNama();
    data.menangSuit = suit();
    switch (data.level) {
        case 1: Easy(); break;
        case 2: Medium(); break;
        case 3: Hard(); break;
        case 4: yourGame(); break;
    }

}

int suit() {

		//Deklarasi
		int kom, P, menang;
		tampilX = 40;
		tampilY = 13;
		//Deskripsi: merandom nomor suwit computer
		//Input: -
		//Output: integer hasil random suwit
        system("cls");
		gotoxy(tampilX+2, tampilY);printf("Sebelum Bermain, Mari Kita SUIT ....\n");
		gotoxy(tampilX, tampilY+1);printf("Tunggu Sebentar, Jangan Kemana - Mana !!! ");
        Sleep(5000);
		system("cls");
		do{
			system("cls");
			srand(time(0));//1.Batu 2.Gunting 3.Kertas
			switch(data.enemy){
				case 1 :
					P =rand()%3+1;
					kom=rand()%3+1;
						if(kom==1){
							gotoxy(tampilX, tampilY);printf("PLAYER 2 %s MENDAPATKAN : BATU\n", data.nama_2);
							if(P==1){
								gotoxy(tampilX, tampilY+1);printf("PLAYER 1 %s MENDAPATKAN : BATU\n", data.nama);
								gotoxy(tampilX, tampilY+3);printf("HASIL SERI !!! ULANGI LAGI !!!");
								Sleep(1000);
							}
							else if(P==2){
								gotoxy(tampilX, tampilY+1);printf("PLAYER 1 %s MENDAPATKAN : GUNTING\n", data.nama);
								gotoxy(tampilX, tampilY+3);printf("PLAYER 2 %s BERMAIN TERLEBIH DAHULU", data.nama_2);
								menang=2;
							}
							else if(P==3){
								gotoxy(tampilX, tampilY+1);printf("PLAYER 1 %s MENDAPATKAN : KERTAS\n", data.nama);
								gotoxy(tampilX, tampilY+3);printf("PLAYER 2 %s BERMAIN TERLEBIH DAHULU", data.nama);
								menang=1;
							}
						}
						else if(kom==2){
							gotoxy(tampilX, tampilY);printf("PLAYER 2 %s MENDAPATKAN : GUNTING\n", data.nama_2);
							if(P==1){
								gotoxy(tampilX, tampilY+1);printf("PLAYER 1 %s MENDAPATKAN : BATU\n", data.nama);
								gotoxy(tampilX, tampilY+3);printf("PLAYER 2 %s BERMAIN TERLEBIH DAHULU", data.nama);
								menang=1;
							}
							else if(P==2){
								gotoxy(tampilX, tampilY+1);printf("PLAYER 1 %s MENDAPATKAN : GUNTING\n", data.nama);
								gotoxy(tampilX, tampilY+3);printf("HASIL SERI !!! ULANGI LAGI !!!");
								Sleep(1000);
							}
							else if(P==3){
								gotoxy(tampilX, tampilY+1);printf("PLAYER 1 %s MENDAPATKAN : KERTAS\n", data.nama);
								gotoxy(tampilX, tampilY+3);printf("PLAYER 2 %s BERMAIN TERLEBIH DAHULU", data.nama_2);
								menang=2;
							}
						}
						else if(kom==3){
							gotoxy(tampilX, tampilY);printf("PLAYER 2 %s MENDAPATKAN : KERTAS\n", data.nama_2);
							if(P==1){
								gotoxy(tampilX, tampilY+1);printf("PLAYER 1 %s MENDAPATKAN : BATU\n", data.nama);
								gotoxy(tampilX, tampilY+3);printf("PLAYER 2 %s BERMAIN TERLEBIH DAHULU", data.nama_2);
								menang=2;
							}
							else if(P==2){
								gotoxy(tampilX, tampilY+1);printf("PLAYER 1 %s MENDAPATKAN : GUNTING\n", data.nama);
								gotoxy(tampilX, tampilY+3);printf("PLAYER 1 %s BERMAIN TERLEBIH DAHULU", data.nama);
								menang=1;
							}
							else if(P==3){
								gotoxy(tampilX, tampilY+1);printf("PLAYER 1 %s MENDAPATKAN : KERTAS\n", data.nama);
								gotoxy(tampilX, tampilY+3);printf("HASIL SERI! !! ULANGI LAGI !!!");
								Sleep(1000);
							}
						}
				break;
				case 2 :
					P =rand()%3+1;
					kom=rand()%3+1;
						if(kom==1){
							gotoxy(tampilX, tampilY);printf("KOMPUTER MENDAPATKAN : BATU\n");
							if(P==1){
								gotoxy(tampilX, tampilY+1);printf("PLAYER MENDAPATKAN : BATU\n");
								gotoxy(tampilX, tampilY+3);printf("HASIL SERI !!! ULANGI LAGI !!!");
								Sleep(1000);
							}
							else if(P==2){
								gotoxy(tampilX, tampilY+1);printf("PLAYER MENDAPATKAN : GUNTING\n");
								gotoxy(tampilX, tampilY+3);printf("KOMPUTER BERMAIN TERLEBIH DAHULU");
								menang=2;
							}
							else if(P==3){
								gotoxy(tampilX, tampilY+1);printf("PLAYER MENDAPATKAN : KERTAS\n");
								gotoxy(tampilX, tampilY+3);printf("PLAYER BERMAIN TERLEBIH DAHULU");
								menang=1;
							}
						}
						else if(kom==2){
							gotoxy(tampilX, tampilY);printf("KOMPUTER MENDAPATKAN : GUNTING\n");
							if(P==1){
								gotoxy(tampilX, tampilY+1);printf("PLAYER MENDAPATKAN : BATU\n");
								gotoxy(tampilX, tampilY+3);printf("PLAYER BERMAIN TERLEBIH DAHULU");
								menang=1;
							}
							else if(P==2){
								gotoxy(tampilX, tampilY+1);printf("PLAYER MENDAPATKAN : GUNTING\n");
								gotoxy(tampilX, tampilY+3);printf("HASIL SERI !!! ULANGI LAGI !!!");
								Sleep(1000);
							}
							else if(P==3){
								gotoxy(tampilX, tampilY+1);printf("PLAYER MENDAPATKAN : KERTAS\n");
								gotoxy(tampilX, tampilY+3);printf("KOMPUTER BERMAIN TERLEBIH DAHULU");
								menang=2;
							}
						}
						else if(kom==3){
							gotoxy(tampilX, tampilY);printf("KOMPUTER MENDAPATKAN : KERTAS\n");
							if(P==1){
								gotoxy(tampilX, tampilY+1);printf("PLAYER MENDAPATKAN : BATU\n");
								gotoxy(tampilX, tampilY+3);printf("KOMPUTER BERMAIN TERLEBIH DAHULU");
								menang=2;
							}
							else if(P==2){
								gotoxy(tampilX, tampilY+1);printf("PLAYER MENDAPATKAN : GUNTING\n");
								gotoxy(tampilX, tampilY+3);printf("PLAYER BERMAIN TERLEBIH DAHULU");
								menang=1;
							}
							else if(P==3){
								gotoxy(tampilX, tampilY+1);printf("PLAYER MENDAPATKAN : KERTAS\n");
								gotoxy(tampilX, tampilY+2);printf("HASIL SERI !!! ULANGI LAGI !!!");
								Sleep(1000);
							}
						}
						break;
						}
					}while(P==kom);

					printf("\n");
                    gotoxy(tampilX, tampilY+5);system("pause");
					system("cls");
					return menang;
}

void Easy() {

    char c;
    data.mulai = true;
    bool lagu = true;

    bonus = 300;
    ukuran = 4;
    waktu = 10;

    /*if(lagu){
        PlaySound(TEXT("musicingame.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        lagu = false;
    }*/

    LoadDisplay();

    gotoxy(40, tampilY);printf("Hai, Kamu Sudah Tau Cara Mainnya (y/t) ? ");
    fflush(stdin);
    scanf("%c", &c);
    if(c=='t'){
        Help();
    } else {
        gotoxy(50, tampilY+1);printf("Selamat Bermain BRO !!!");
        Sleep(2000);
        system("cls");
    }

    if(data.posisi!=1 && data.posisi!=2){
        persiapanMatrix();
    }

    DisplayBoard();

    while (data.mulai) {
        PlayTheGame();
    }

    system("cls");
    DisplayBoard();
    if(data.score_1 == 0 && data.score_2==0){
        gotoxy(50, tampilY); printf("SERI");
        gotoxy(50, tampilY+1); printf("Ulang (y/t) ? ");
        scanf("%c", &c);
        scanf("%c", &c);
        if(c=='y'){
            persiapanMatrix();
            Easy();
        }else{
            main();
        }
    }else{
        gotoxy(50, tampilY+1); printf("GAME OVER\n");
        HighScores();
    }
}

void persiapanMatrix() {
    char angkaCol, angkaBar;
    int i, j;

    angkaCol = '1';
    for (i = 0; i < ukuran ; i++) {
        angkaBar = '0';
        for (j = 0; j < ukuran; j++) {
            if (i == 0) {
                data.matrix_2D[i][j] = angkaBar;
                angkaBar = angkaBar + 1;
            }
            else if (j == 0) {
                data.matrix_2D[i][j] = angkaCol;
                angkaCol = angkaCol + 1;
            }
            else {
                data.matrix_2D[i][j] = '\0';
            }
        }
    }
}

void DisplayBoard(){
    int i, j, tampilTengah;
    tampilX = 50 ;
    tampilY = 10 ;
    tampilTengah = ((tampilX+17+((ukuran-4)*4))+(tampilX-9))/2 + 5;

    system("color 0B");
    gotoxy(tampilX-9, tampilY-5);printf("%s", data.nama);
    gotoxy(tampilTengah, tampilY-5);printf("vs");
    gotoxy(tampilX+17+((ukuran-4)*4), tampilY-5);printf("%s", data.nama_2);
    gotoxy(tampilX-9, tampilY-3);printf("score X : %d", data.score_1);
    gotoxy(tampilX+17+((ukuran-4)*4), tampilY-3);printf("score O : %d", data.score_2);

    for (i = 0; i < ukuran; i++) {
            tampilX = 50;
        for (j = 0; j < ukuran; j++) {
            if(data.matrix_2D[i][j]=='\0'){
                SetColor(9);
                gotoxy(tampilX, tampilY);printf("|_ _");
                //tampilY++;
                tampilX+=4;
            } else if (data.matrix_2D[i][j]>=48 && data.matrix_2D[i][j] <= 57){
                SetColor(10);
                gotoxy(tampilX, tampilY);printf("  %c ", data.matrix_2D[i][j]);
                //tampilY++;
                tampilX+=4;
            } else if (data.matrix_2D[i][j] != '/' && data.matrix_2D[i][j] != '\\'){
                SetColor(14);
                gotoxy(tampilX, tampilY);printf("|_%c_", data.matrix_2D[i][j]);
                //tampilY++;
                tampilX+=4;
            } else if (data.matrix_2D[i][j]=='/'){
                SetColor(4);
                gotoxy(tampilX, tampilY);printf("|_%c_", data.matrix_2D[i][j]);
                //tampilY++;
                tampilX+=4;
            } else {
                SetColor(5);
                gotoxy(tampilX, tampilY);printf("|_%c_", data.matrix_2D[i][j]);
                //tampilY++;
                tampilX+=4;
            }
        }
        if (data.matrix_2D[i][j-1]>=48 && data.matrix_2D[i][j-1] <= 57){
            gotoxy(tampilX, tampilY);printf("\n\n");
            tampilY+=2;
            //tampilX++;
        } else {
            gotoxy(tampilX, tampilY);printf("| \n\n");
            tampilY+=2;
            //tampilX++;
        }
    }

    SetColor(14);

}

void PlayTheGame() {
    if (data.enemy == 1 && data.menangSuit == 1) {
    	PlayGame_1();
    }
    else if (data.enemy == 1 && data.menangSuit == 2) {
    	PlayGame_2();
    }
    else if (data.enemy == 2 && data.menangSuit == 1) {
    	PlayGame_3();
    }
    else if(data.enemy == 2 && data.menangSuit == 2) {
    	PlayGame_4();
	}
}

int StartTime() {
    clock_t startInput;
    startInput = clock();

    return startInput;
}

int EndTime() {
    clock_t endInput;
    endInput = clock();

    return endInput;
}

void p_1_InputX(int* x, int* y, double *waktuInput) {
    int baris=0, kolom=0, tambah=0;
    int t;
    tampilX = 50;
    tampilY = tampilY;

    //StartTime
    t = StartTime();
    gotoxy(tampilX, tampilY);printf("(X) input baris kolom : ");
    while(scanf("%d %d", &baris, &kolom)!= 2 && getchar() != '\n'){
        gotoxy(tampilX, tampilY+1+tambah); printf("! ONLY INTEGER ! ==> ");
        tambah++;
    }
    t = EndTime() - t;

    *x = baris;
    *y = kolom;
    *waktuInput = ((double)t)/CLOCKS_PER_SEC;

}

void p_2_InputO(int* x, int* y, double *waktuInput) {
    int baris=0, kolom=0, tambah=0;
    int t;
    tampilX = 50;
    tampilY = tampilY;

    //StartTime
    t = StartTime();
    gotoxy(tampilX, tampilY);printf("(O) input baris kolom : ");
    while(scanf("%d %d", &baris, &kolom)!= 2 && getchar() != '\n'){
        gotoxy(tampilX, tampilY+1+tambah);printf("! ONLY INTEGER ! ==> ");
        tambah++;
    }
    t = EndTime() - t;

    *x = baris;
    *y = kolom;
    *waktuInput = ((double)t)/CLOCKS_PER_SEC;
}

bool CekSel(int x, int y) {

    if (data.matrix_2D[x][y] == '\0') {
        //printf("\nkosong\n");
        return true;
    }
    else {
        return false;
    }

}

bool CekBar() {
    int count=0;
    int i, j, k;

    //cek bar X
    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran-2; j++){
            count = 0;
            for(k=j; k<j+3; k++){
                 if(data.matrix_2D[i][k]=='X'){
                    count++;
                }
                if(count==3){
                    for(k=k; k>=j; k--){
                        data.matrix_2D[i][k]='\\';
                    }
                    return true;
                }
            }

        }
    }

    //cek bar O
    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran-2; j++){
            count = 0;
            for(k=j; k<j+3; k++){
                if(data.matrix_2D[i][k]=='O'){
                    count++;
                }
                if(count==3){
                    for(k=k; k>=j; k--){
                        data.matrix_2D[i][k]='/';
                    }
                    return true;
                }
            }

        }
    }

    return false;

}

bool CekBarCom(){

    int i, j, k, count=0;

    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran-2; j++){
            count = 0;
            for(k=j; k<j+3; k++){
                 if(data.matrix_2D[i][k]=='X'){
                    count++;
                } else if (data.matrix_2D[i][k]=='O' || data.matrix_2D[i][k]=='/'){
                    count--;
                }
            }
                if(count==2){
                    return true;
                }
        }
    }

    return false;

}

void inputInBarCom(int *x, int *y){
    int count=0;
    int i, j, k;

    //cek bar X
    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran-2; j++){
            count = 0;
            for(k=j; k<j+3; k++){
                 if(data.matrix_2D[i][k]=='X'){
                    count++;
                 }
                 else if(data.matrix_2D[i][k]=='O' || data.matrix_2D[i][k]=='/'){
                    count--;
                 }
            }
                if(count==2){
                    k=k-1;
                    //printf("\ncek count problem\n");
                    for(k=k; k>=j; k--){
                        if(data.matrix_2D[i][k]=='\0'){
                            *x = i;
                            *y = k;
                            //printf("\nisi dengan %d %d\n", i , k);
                           // Sleep(2000);
                            goto finish;
                        }
                    }
                }
        }
    }

    finish:
        count=0;

}

bool CekCol() {
    int count=0;
    int i, j, k;

    //cek Col X
    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran-2; j++){
            count = 0;
            for(k=j; k<j+3; k++){
               if(data.matrix_2D[k][i]=='X'){
                    count++;
                }
                if(count==3){
                    for(k=k; k>=j; k--){
                        data.matrix_2D[k][i]='\\';
                    }
                    return true;
                }
            }

        }
    }

    //cek Col O
    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran-2; j++){
            count = 0;
            for(k=j; k<j+3; k++){
               if(data.matrix_2D[k][i]=='O'){
                    count++;
                }
                if(count==3){
                    for(k=k; k>=j; k--){
                        data.matrix_2D[k][i]='/';
                    }
                    return true;
                }
            }
        }
    }

    return false;

}

bool CekColCom() {

    int i, j, k, count=0;

    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran-2; j++){
            count = 0;
            for(k=j; k<j+3; k++){
               if(data.matrix_2D[k][i]=='X'){
                    count++;
                } else if (data.matrix_2D[k][j]=='O' || data.matrix_2D[k][j]=='/'){
                    count--;
                }
            }
                if(count==2){
                    return true;
                }
        }
    }

    return false;

}

void inputInColCom(int *x, int *y){
    int i, j, k, count=0;

    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran-2; j++){
            count = 0;
            for(k=j; k<j+3; k++){
               if(data.matrix_2D[k][i]=='X'){
                    count++;
                } else if(data.matrix_2D[k][i]=='O' || data.matrix_2D[k][i]=='/'){
                    count--;
                }
            }
                if(count==2){
                    k = k-1;
                    for(k=k; k>=j; k--){
                        if(data.matrix_2D[k][i]=='\0'){
                            *x = k;
                            *y = i;
                           // printf("\nIsi %d %d\n", k , i);
                            //Sleep(2000);
                            goto finish;
                        }
                    }
                }
        }
    }

    finish:
        count=0;
}

bool CekDiagon() {
    int count=0, tambahBar = 0, tambahKol = 0;
    int i, j, k, l;

    //cek diagon bar left to right X
    for(l=1; l<ukuran-2; l++){
    tambahBar = 0;
        for(k=1; k<ukuran-2; k++){
            count=0;
            for(i=l; i<l+3; i++){
                for(j=k; j<k+3; j++){
                    if(i+tambahBar==j+tambahKol){
                        if(data.matrix_2D[i][j]=='X'){
                            count++;
                        }
                    }
                    if(count==3){
                        for(i=i; i>=l; i--){
                            for(j=k+2; j>=k; j--){
                                if(i+tambahBar==j+tambahKol){
                                    data.matrix_2D[i][j]='\\';
                                }
                            }
                        }
                        return true;
                    }
                }

            }

            tambahBar++;
        }
        tambahKol++;
    }

    //cek diagon rifht to left X
    tambahKol = 0;
    for(l=1; l<ukuran-2; l++){
        tambahBar=0;
         for(k=1; k<ukuran-2; k++){
            count = 0;
            for(i=l; i<l+3; i++){
                for(j=k+2; j>=k; j--){
                    if(i+j==k+3+tambahKol){
                        if(data.matrix_2D[j][i]=='X'){
                            count++;
                        }
                    }
                    if(count==3){
                        for(i=i; i>=l; i--){
                            for(j=k; j<=k+2; j++){
                                if(i+j==k+3+tambahKol){
                                    data.matrix_2D[j][i]='\\';
                                }
                            }
                        }
                        return true;
                    }
                }
            }

            tambahBar++;
        }
        tambahKol++;
    }


    //cek diagon left to right O
    tambahKol =0;
    for(l=1; l<ukuran-2; l++){
    tambahBar = 0;
        for(k=1; k<ukuran-2; k++){
            count=0;
            for(i=l; i<l+3; i++){
                for(j=k; j<k+3; j++){
                    if(i+tambahBar==j+tambahKol){
                        if(data.matrix_2D[i][j]=='O'){
                            count++;
                        }
                    }
                    if(count==3){
                        for(i=i; i>=l; i--){
                            for(j=k+2; j>=k; j--){
                                if(i+tambahBar==j+tambahKol){
                                    data.matrix_2D[i][j]='/';
                                }
                            }
                        }
                        return true;
                    }
                }

            }

            tambahBar++;
        }
        tambahKol++;
    }

    //cek diagon rifht to left O
    tambahKol = 0;
    for(l=1; l<ukuran-2; l++){
        tambahBar=0;
         for(k=1; k<ukuran-2; k++){
            count = 0;
            for(i=l; i<l+3; i++){
                for(j=k+2; j>=k; j--){
                    if(i+j==k+3+tambahKol){
                        if(data.matrix_2D[j][i]=='O'){
                            count++;
                        }
                    }
                    if(count==3){
                        for(i=i; i>=l; i--){
                            for(j=k; j<=k+2; j++){
                                if(i+j==k+3+tambahKol){
                                    data.matrix_2D[j][i]='/';
                                }
                            }
                        }
                        return true;
                    }
                }
            }

            tambahBar++;
        }
        tambahKol++;
    }

    //jika tidak sama
    return false;

}

bool CekDiagonLRCom(){
    int count=0, tambahBar = 0, tambahKol = 0;
    int i, j, k, l;

    //cek diagon bar left to right X
    for(l=1; l<ukuran-2; l++){
    tambahBar = 0;
        for(k=1; k<ukuran-2; k++){
            count=0;
            for(i=l; i<l+3; i++){
                for(j=k; j<k+3; j++){
                    if(i+tambahBar==j+tambahKol){
                        if(data.matrix_2D[i][j]=='X'){
                            count++;
                        } else if(data.matrix_2D[i][j]=='O' || data.matrix_2D[i][j]=='/'){
                            count--;
                        }
                    }
                }
            }
                if(count==2){
                    return true;
                }
            tambahBar++;
        }
        tambahKol++;
    }

    return false;
}

bool CekDiagonRLCom(){
    int count=0, tambahBar = 0, tambahKol = 0;
    int i, j, k, l;

    //cek right to left diagon
    for(l=1; l<ukuran-2; l++){
        tambahBar=0;
         for(k=1; k<ukuran-2; k++){
            count = 0;
            for(i=l; i<l+3; i++){
                for(j=k+2; j>=k; j--){
                    if(i+j==k+3+tambahKol){
                        if(data.matrix_2D[j][i]=='X'){
                            count++;
                        } else if (data.matrix_2D[j][i]=='O' || data.matrix_2D[j][i]=='/'){
                            count--;
                        }
                    }

                }
            }
                if(count==2){
                    return true;
                }
            tambahBar++;
        }
        tambahKol++;
    }

    return false;

}

void inputInDiagonCom(int *x, int *y) {
    int count=0, tambahBar = 0, tambahKol = 0;
    int i=0, j=0, k=0, l=0;

    if(CekDiagonLRCom()){
        //input diagon bar left to right X
        for(l=1; l<ukuran-2; l++){
        tambahBar = 0;
            for(k=1; k<ukuran-2; k++){
                count=0;
                for(i=l; i<l+3; i++){
                    for(j=k; j<k+3; j++){
                        if(i+tambahBar==j+tambahKol){
                            if(data.matrix_2D[i][j]=='X'){
                                count++;
                            } else if(data.matrix_2D[i][j]=='O' || data.matrix_2D[i][j]=='/'){
                                count--;
                            }
                        }
                    }
                }
                    if(count==2){
                        for(i=l; i<l+3; i++){
                            for(j=k; j<k+3; j++){
                                if(i+tambahBar==j+tambahKol){
                                    if(data.matrix_2D[i][j]=='\0'){
                                        *x = i;
                                        *y = j;
                                        //printf("\nisi RL : %d %d\n", i , j);
                                        //Sleep(2000);
                                        goto finish;
                                    }
                                }
                            }
                        }
                    }
                tambahBar++;
            }
            tambahKol++;
        }
    }
    else if (CekDiagonRLCom()){
        for(l=1; l<ukuran-2; l++){
            tambahBar=0;
             for(k=1; k<ukuran-2; k++){
                count = 0;
                for(i=l; i<l+3; i++){
                    for(j=k+2; j>=k; j--){
                        if(i+j==k+3+tambahKol){
                            if(data.matrix_2D[j][i]=='X'){
                                count++;
                            } else if (data.matrix_2D[j][i]=='O' || data.matrix_2D[j][i]=='/'){
                                count--;
                            }
                        }

                    }
                }
                    if(count==2){
                        for(i=l; i<l+3; i++){
                            for(j=k+2; j>=k; j--){
                                if(i+j==k+3+tambahKol){
                                    if(data.matrix_2D[j][i]=='\0'){
                                        *x = j;
                                        *y = i;
                                        //printf("\nisi RL : %d %d\n", j , i);
                                        //Sleep(2000);
                                        goto finish;
                                    }
                                }

                            }
                        }
                    }
                tambahBar++;
            }
            tambahKol++;
        }
    }

    finish:
        count = 0;

}

void inputRandCom(int *x, int *y){
    int bar=0, col=0;
    const int len=ukuran-1;

    //srand(time(0));
    bar = rand()%len+1;
    col = rand()%len+1;

    if(CekSel(bar, col)){
        *x = bar;
        *y = col;
    } else {
        inputRandCom(&bar, &col);
        *x = bar;
        *y = col;
    }

}

bool CekPenuh(){
    int i , j, count=0;
    int penuh = ukuran - 1;
    penuh = penuh * penuh;

    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran; j++){
            if(data.matrix_2D[i][j]!='\0'){
                count++;
            }
        }
    }

    if(count==penuh){
        return true;
    } else {
        return false;
    }
}

void GameOver() {

        //game over jika bukan easy
        if(ukuran!=4){
            if(CekPenuh()){
                gotoxy(tampilX, tampilY+1); printf("GAME OVER");
            }
            else if(!data.mulai){
                data.mulai=true;
            }
        } else if (CekPenuh()){
            gotoxy(tampilX, tampilY+1); printf("SERI");
        }

}

void Medium() {
    char c;

    bonus = 120;
    ukuran = 6;
    waktu = 7;

    bool lagu = true;

    /*if(lagu){
        PlaySound(TEXT("musicingame.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        lagu = false;
    }*/

    LoadDisplay();
    gotoxy(40, tampilY);printf("Hai, Kamu Sudah Tau Cara Mainnya (y/t) ? ");
    fflush(stdin);
    scanf("%c", &c);
    if(c=='t'){
        Help();
    } else {
        gotoxy(50, tampilY+1);printf("Selamat Bermain BRO !!!");
        Sleep(2000);
        system("cls");
    }

    if(data.posisi!=1 && data.posisi!=2){
        persiapanMatrix();
    }

    DisplayBoard();

    while (data.mulai) {
        PlayTheGame();
    }

    system("cls");
    DisplayBoard();
    if(data.score_1 == 0 && data.score_2==0){
        gotoxy(50, tampilY); printf("SERI");
        gotoxy(50, tampilY+1); printf("Ulang (y/t) ? ");
        scanf("%c", &c);
        scanf("%c", &c);
        if(c=='y'){
            persiapanMatrix();
            Easy();
        }else{
            main();
        }
    }else{
        gotoxy(50, tampilY+1); printf("GAME OVER\n");
        HighScores();
    }
}

void Hard() {

    char c;

    bonus = 150;
    ukuran = 8;
    waktu = 5;

    bool lagu = true;

    /*if(lagu){
        PlaySound(TEXT("musicingame.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        lagu = false;
    }*/

    LoadDisplay();
    gotoxy(40, tampilY);printf("Hai, Kamu Sudah Tau Cara Mainnya (y/t) ? ");
    fflush(stdin);
    scanf("%c", &c);
    if(c=='t'){
        Help();
    } else {
        gotoxy(50, tampilY+1);printf("Selamat Bermain BRO !!!");
        Sleep(2000);
        system("cls");
    }

    if(data.posisi!=1 && data.posisi!=2){
        persiapanMatrix();
    }

    DisplayBoard();

    while (data.mulai) {
        PlayTheGame();
    }

    system("cls");
    DisplayBoard();
    if(data.score_1 == 0 && data.score_2==0){
        gotoxy(50, tampilY); printf("SERI");
        gotoxy(50, tampilY+1); printf("Ulang (y/t) ? ");
        scanf("%c", &c);
        scanf("%c", &c);
        if(c=='y'){
            persiapanMatrix();
            Easy();
        }else{
            main();
        }
    }else{
        gotoxy(50, tampilY+1); printf("GAME OVER\n");
        HighScores();
    }
}

void PlayerVsComputer() {


    InpuNama();
    data.menangSuit = suit();
    switch (data.level) {
    case 1: Easy(); break;
    case 2: Medium(); break;
    case 3: Hard(); break;
    case 4: yourGame(); break;
    }

}

void p_com_InputO(int *x, int *y, double *waktuInput) {
    int bar=0, col=0;
    int t;
    tampilX = 50;
    tampilY = tampilY;

    t = StartTime();
        /*cek bar, col and diagon for input bar and col computer*/
        if(CekBarCom()){
            //printf("\n cek bar problem\n");
            //Sleep(1000);
            inputInBarCom(&bar, &col);
            if (data.matrix_2D[bar][col]=='\0'){
                //printf("\nbar\n");
                goto here;
            }
        } if (CekColCom()){
            //printf("\n cek col problem\n");
            //Sleep(1000);
            inputInColCom(&bar, &col);
            if (data.matrix_2D[bar][col]=='\0'){
                    //printf("\ncol\n");
                goto here;
            }
        } if (CekDiagonLRCom() || CekDiagonRLCom()) {
           // printf("\n cek diagon problem\n");
           // Sleep(1000);
            inputInDiagonCom(&bar, &col);
            if (data.matrix_2D[bar][col]=='\0'){
                //printf("\ndiagon\n");
                goto here;
            }
        }

    here:
        if(bar==0 && col ==0){
            inputRandCom(&bar, &col);
        }

       gotoxy(tampilX, tampilY); printf("(O) input baris kolom : %d %d", bar, col);

    t = EndTime() - t;
    Sleep(2000);

    *x = bar;
    *y = col;
    *waktuInput = ((double)t)/CLOCKS_PER_SEC;

}

void PlayGame_1(){
	int bar = 0, col = 0;
    double waktuInput = 0;
    bool penuh = true;
    tampilX = 50;
        //Inputan jika player 1 main dulu mode p vs p
        if(data.posisi==1 || data.posisi==0){
            data.posisi = 1;
            p_1_InputX(&bar, &col, &waktuInput);
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                data.matrix_2D[bar][col] = 'X';
                DisplayBoard();
                if(CekBar()){
                    data.mulai = false;
                } else if(CekCol()){
                    data.mulai = false;
                } else if(CekDiagon()){
                    data.mulai = false;
                } else if(CekPenuh()){
                    penuh = false;
                    data.mulai = false;
                }
                //Hitung Highscores
                if(!data.mulai && penuh){
                    data.score_1++;
                    data.score_1 = data.score_1+(waktu-waktuInput)*bonus;
                }
            } else if(waktuInput>waktu){
                gotoxy(tampilX, tampilY+1);printf("Giliran di-GANTI Karena :");
                gotoxy(tampilX, tampilY+2);printf("Waktu Berpikir Anda %.2f s",waktuInput);
                gotoxy(tampilX, tampilY+3);printf("Harusnya %.0f s\n", waktu);
                Sleep(2000);
                system("cls");
                DisplayBoard();
            } else if (bar == 0 && col ==0){
                savedGame();
            } else {
                gotoxy(tampilX, tampilY+1);printf("kotak penuh, giliran diganti !\n");
                Sleep(1500);
                system("cls");
                DisplayBoard();
            }
            GameOver();
        }

        if(data.mulai){
            data.posisi = 2;
            p_2_InputO(&bar, &col, &waktuInput);
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                data.matrix_2D[bar][col] = 'O';
                DisplayBoard();
                if(CekBar()){
                    data.mulai = false;
                } else if(CekCol()){
                    data.mulai = false;
                } else if(CekDiagon()){
                    data.mulai = false;
                } else if(CekPenuh()){
                    penuh = false;
                    data.mulai = false;
                }

                if(!data.mulai && penuh){
                    data.score_2++;
                    data.score_2 = data.score_2+(waktu-waktuInput)*bonus;
                }

            } else if(waktuInput>waktu){
                gotoxy(tampilX, tampilY+1);printf("Giliran di-GANTI Karena :");
                gotoxy(tampilX, tampilY+2);printf("Waktu Berpikir Anda %.2f s",waktuInput);
                gotoxy(tampilX, tampilY+3);printf("Harusnya %.0f s\n", waktu);
                Sleep(2000);
                system("cls");
                DisplayBoard();
            } else if(bar == 0 && col ==0){
                savedGame();
            } else {
                gotoxy(tampilX, tampilY+1);printf("kotak penuh, giliran diganti !\n");
                Sleep(1500);
                system("cls");
                DisplayBoard();
            }
            GameOver();
        }
        data.posisi=data.posisi-1;
}


void PlayGame_2(){
	int bar = 0, col = 0;
    double waktuInput = 0;
    bool penuh = true;
    tampilX = 50;
        if(data.posisi==1 || data.posisi==0){
           data.posisi = 1;
            p_2_InputO(&bar, &col, &waktuInput);
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                data.matrix_2D[bar][col] = 'O';
                DisplayBoard();
                if(CekBar()){
                    data.mulai = false;
                } else if(CekCol()){
                    data.mulai = false;
                } else if(CekDiagon()){
                    data.mulai = false;
                } else if(CekPenuh()){
                    penuh = false;
                    data.mulai = false;
                }
                if(!data.mulai && penuh){
                    data.score_2++;
                    data.score_2 = data.score_2+(waktu-waktuInput)*bonus;
                }

            } else if(waktuInput>waktu){
                gotoxy(tampilX, tampilY+1);printf("Giliran di-GANTI Karena :");
                gotoxy(tampilX, tampilY+2);printf("Waktu Berpikir Anda %.2f s",waktuInput);
                gotoxy(tampilX, tampilY+3);printf("Harusnya %.0f s\n", waktu);
                Sleep(2000);
                system("cls");
                DisplayBoard();
            } else if(bar == 0 && col ==0){
                savedGame();
            } else {
                gotoxy(tampilX, tampilY+1);printf("kotak penuh, giliran diganti !\n");
                Sleep(1500);
                system("cls");
                DisplayBoard();
            }
            GameOver();
        }

        if(data.mulai){
            data.posisi = 2;
            p_1_InputX(&bar, &col, &waktuInput);
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                data.matrix_2D[bar][col] = 'X';
                DisplayBoard();
                if(CekBar()){
                    data.mulai = false;
                } else if(CekCol()){
                    data.mulai = false;
                } else if(CekDiagon()){
                    data.mulai = false;
                } else if(CekPenuh()){
                    penuh = false;
                    data.mulai = false;
                }

                if(!data.mulai && penuh){
                    data.score_1++;
                    data.score_1 = data.score_1+(waktu-waktuInput)*bonus;
                }

            } else if(waktuInput>waktu){
                gotoxy(tampilX, tampilY+1);printf("Giliran di-GANTI Karena :");
                gotoxy(tampilX, tampilY+2);printf("Waktu Berpikir Anda %.2f s",waktuInput);
                gotoxy(tampilX, tampilY+3);printf("Harusnya %.0f s\n", waktu);
                Sleep(2000);
                system("cls");
                DisplayBoard();
            } else if(bar == 0 && col ==0){
                savedGame();
            } else {
                gotoxy(tampilX, tampilY+1);printf("kotak penuh, giliran diganti !\n");
                Sleep(1500);
                system("cls");
                DisplayBoard();
            }
            GameOver();
        }
        data.posisi=data.posisi-1;
}

void PlayGame_3(){
	int bar = 0, col = 0;
    double waktuInput = 0;
    bool penuh = true;
    tampilX = 50;
        if(data.posisi==1 || data.posisi==0){
            data.posisi = 1;
            p_1_InputX(&bar, &col, &waktuInput);
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                data.matrix_2D[bar][col] = 'X';
                DisplayBoard();
                if(CekBar()){
                    data.mulai = false;
                } else if(CekCol()){
                    data.mulai = false;
                } else if(CekDiagon()){
                    data.mulai = false;
                } else if(CekPenuh()){
                    penuh = false;
                    data.mulai = false;
                }

                if(!data.mulai && penuh){
                    data.score_1++;
                    data.score_1 = data.score_1+(waktu-waktuInput)*bonus;
                }

            } else if(waktuInput>waktu){
                gotoxy(tampilX, tampilY+1);printf("Giliran di-GANTI Karena :");
                gotoxy(tampilX, tampilY+2);printf("Waktu Berpikir Anda %.2f s",waktuInput);
                gotoxy(tampilX, tampilY+3);printf("Harusnya %.0f s\n", waktu);
                Sleep(2000);
                system("cls");
                DisplayBoard();
            } else if(bar == 0 && col ==0){
                    savedGame();
            } else {
                gotoxy(tampilX, tampilY+1);printf("kotak penuh, giliran diganti !\n");
                Sleep(1500);
                system("cls");
                DisplayBoard();
            }
            GameOver();
        }

        if(data.mulai){
            data.posisi=2;
            p_com_InputO(&bar, &col, &waktuInput);
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                data.matrix_2D[bar][col] = 'O';
                DisplayBoard();
                if(CekBar()){
                    data.mulai = false;
                } else if(CekCol()){
                    data.mulai = false;
                } else if(CekDiagon()){
                    data.mulai = false;
                } else if(CekPenuh()){
                    penuh = false;
                    data.mulai = false;
                }

                if(!data.mulai && penuh){
                    data.score_2++;
                    data.score_2 = data.score_2+(waktu-waktuInput)*bonus;
                }

            } else if(waktuInput>waktu){
                gotoxy(tampilX, tampilY+1);printf("Giliran di-GANTI Karena :");
                gotoxy(tampilX, tampilY+2);printf("Waktu Berpikir Anda %.2f s",waktuInput);
                gotoxy(tampilX, tampilY+3);printf("Harusnya %.0f s\n", waktu);
                Sleep(2000);
                system("cls");
                DisplayBoard();
            } else if(bar == 0 && col ==0){
                    savedGame();
            } else {
                gotoxy(tampilX, tampilY+1);printf("kotak penuh, giliran diganti !\n");
                Sleep(1500);
                system("cls");
                DisplayBoard();
            }
            GameOver();
        }
        data.posisi=data.posisi-1;
}

void PlayGame_4(){
	int bar = 0, col = 0;
    double waktuInput = 0;
    bool penuh = true;
    tampilX = 50;
        if(data.posisi==1 || data.posisi==0){
            p_com_InputO(&bar, &col, &waktuInput);
            data.posisi = 1;
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                data.matrix_2D[bar][col] = 'O';
                DisplayBoard();
                if(CekBar()){
                    data.mulai = false;
                } else if(CekCol()){
                    data.mulai = false;
                } else if(CekDiagon()){
                    data.mulai = false;
                } else if(CekPenuh()){
                    penuh = false;
                    data.mulai = false;
                }

                if(!data.mulai && penuh){
                    data.score_2++;
                    data.score_2 = data.score_2+(waktu-waktuInput)*bonus;
                }

            } else if(waktuInput>waktu){
                gotoxy(tampilX, tampilY+1);printf("Giliran di-GANTI Karena :");
                gotoxy(tampilX, tampilY+2);printf("Waktu Berpikir Anda %.2f s",waktuInput);
                gotoxy(tampilX, tampilY+3);printf("Harusnya %.0f s\n", waktu);
                Sleep(2000);
                system("cls");
                DisplayBoard();
            }
            //else if(bar == 0 && col ==0){
              //      savedGame();
            //}
            else {
                gotoxy(tampilX, tampilY+1);printf("kotak penuh, giliran diganti !\n");
                Sleep(1500);
                system("cls");
                DisplayBoard();
            }

            GameOver();
        }

        if(data.mulai){
            p_1_InputX(&bar, &col, &waktuInput);
            data.posisi = 2;
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                data.matrix_2D[bar][col] = 'X';
                DisplayBoard();
                if(CekBar()){
                    data.mulai = false;
                } else if(CekCol()){
                    data.mulai = false;
                } else if(CekDiagon()){
                    data.mulai = false;
                } else if(CekPenuh()){
                    penuh = false;
                    data.mulai = false;
                }

                if(!data.mulai && penuh){
                    data.score_1++;
                    data.score_1 = data.score_1+(waktu-waktuInput)*bonus;
                }

            } else if(waktuInput>waktu){
                gotoxy(tampilX, tampilY+1);printf("Giliran di-GANTI Karena :");
                gotoxy(tampilX, tampilY+2);printf("Waktu Berpikir Anda %.2f s",waktuInput);
                gotoxy(tampilX, tampilY+3);printf("Harusnya %.0f s\n", waktu);
                Sleep(2000);
                system("cls");
                DisplayBoard();
            } else if(bar == 0 && col ==0){
                savedGame();
            } else {
                gotoxy(tampilX, tampilY+1);printf("kotak penuh, giliran diganti !\n");
                Sleep(1500);
                system("cls");
                DisplayBoard();
            }
            GameOver();
        }
        data.posisi=data.posisi-1;
}

void yourGame(){
    int tambah=0;
    char c;
    tampilX = 40;
    tampilY = 13;

    menu:
    system("cls");
    gotoxy(tampilX, tampilY);printf("Berapa Ukuran Papan Anda (3 s/d 9) ? ");
    while(scanf("%d", &ukuran)!= 1 && getchar() != '\n'){
        gotoxy(tampilX, tampilY+1+tambah);printf("! ONLY INTEGER ! ==> ");
        tambah++;
    } tambah = 0;

    ukuran=ukuran+1;

    if(ukuran<=3 || ukuran>=11){
        gotoxy(tampilX, tampilY+1);printf("Maaf Papan Anda Tidak Bisa Diciptakan Karena Ukurannya Tidak Ada :(\n");
        gotoxy(tampilX, tampilY+2);printf("Ulangi lagi yah :)\n");
        Sleep(3000);
        goto menu;
    }

    system("cls");
    gotoxy(tampilX, tampilY);printf("Berapa Lama Batas Waktu Inputan ? ");
    while(scanf("%lf", &waktu)!= 1 && getchar() != '\n'){
        gotoxy(tampilX, tampilY+1+tambah);printf("! ONLY INTEGER ! ==> ");
        tambah++;
    }tambah=0;

    if(waktu<=0){
        gotoxy(tampilX, tampilY+1);printf("Maaf Waktu Inputan Tidak Bisa Diciptakan Karena Waktunya Tidak Tersedia :(\n");
        gotoxy(tampilX, tampilY+2);printf("Ulangi lagi yah :)\n");
        Sleep(3000);
        goto menu;
    }

    system("cls");
    gotoxy(tampilX, tampilY);printf("Berapa Skor Bonus Yang Anda Mau ? ");
    while(scanf("%d", &bonus)!= 1 && getchar() != '\n'){
        gotoxy(tampilX, tampilY+1+tambah);printf("! ONLY INTEGER ! ==> ");
        tambah++;
    }

    bool lagu = true;

    /*if(lagu){
        PlaySound(TEXT("musicingame.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        lagu = false;
    }*/

    LoadDisplay();

    gotoxy(40, tampilY);printf("Hai, Kamu Sudah Tau Cara Mainnya (y/t) ? ");
    fflush(stdin);
    scanf("%c", &c);
    if(c=='t'){
        Help();
    } else {
        gotoxy(50, tampilY+1);printf("Selamat Bermain BRO !!!");
        Sleep(2000);
        system("cls");
    }

    fflush(stdin);

    if(data.posisi!=1 && data.posisi!=2){
        persiapanMatrix();
    }

    DisplayBoard();

    while (data.mulai) {
        PlayTheGame();
    }

    system("cls");
    DisplayBoard();
    if(data.score_1 == 0 && data.score_2==0){
        gotoxy(50, tampilY); printf("SERI");
        gotoxy(50, tampilY+1); printf("Ulang (y/t) ? ");
        scanf("%c", &c);
        scanf("%c", &c);
        if(c=='y'){
            persiapanMatrix();
            yourGame();
        }else{
            main();
        }
    }else{
        gotoxy(50, tampilY+1); printf("GAME OVER\n");
        HighScores();
    }

}

void HighScores() {

    char c;
    int n=0, i=0, j=0;

    struct formatHS{
        char namaPemenang[20];
        int skor;
    }sortScore[500], tulis;

    /*open file for writing appending*/
    if(ukuran!=0 && (data.score_1!=0 || data.score_2!=0)){
        FILE *outfile;
        //menulis highscores
        outfile = fopen("HighScores.dat", "ab");

        //check menang kalah
        if(data.score_1>data.score_2){
            strcpy(tulis.namaPemenang, data.nama);
            tulis.skor = data.score_1;
        } else {
            strcpy(tulis.namaPemenang, data.nama_2);
            tulis.skor = data.score_2;
        }

        gotoxy(45, tampilY+1);printf("%s, Selamat Bang Jagoo !!!", tulis.namaPemenang);

        //writing file
        //fwrite(&tulis, sizeof(struct formatHS), 1, outfile);

        //check if file not succed write
        if(fwrite(&tulis, sizeof(struct formatHS), 1, outfile) != 0){
            gotoxy(45, tampilY+2); printf("Score Pemenang Berhasil Disimpan !!!");
            gotoxy(45, tampilY+3);system("pause");
        } else {
            gotoxy(45, tampilY+2);printf("Sorry Ada Masalah :(\n");
            gotoxy(45, tampilY+3);system("pause");
        }

        fclose(outfile);

        /*open file for sorting descending*/
        FILE *sortFile;
        sortFile = fopen("HighScores.dat", "rb");

        //input array of struct from file
        while(fread(&sortScore[i], sizeof(struct formatHS), 1, sortFile)){
            //printf("%d\n", i);
            system("cls");
            i++;
            n++;
        }

        //gotoxy(tampilX, tampilY);system("pause");

        fclose(sortFile);

        //sort struct data
        for (i = 0; i < n; i++){
            for (j = i; j < n; j++) {
                if (sortScore[i].skor < sortScore[j].skor) {
                    tulis = sortScore[j];
                    sortScore[j] = sortScore[i];
                    sortScore[i] = tulis;
                }
            }
        }

        //back input from struct data to file
        sortFile = fopen("HighScores.dat", "wb");
        for(i=0; i<n; i++){
            fwrite(&sortScore[i], sizeof(struct formatHS), 1, sortFile);
        }

        fclose(sortFile);
    }

    /*open file for read and display*/
    tampilX=40;
    tampilY=14;
    gotoxy(tampilX, tampilY);printf("Anda mau melihat High Score ? (y/t) : ");
    //input \n yg terbawa sebelumnya
    scanf("%c", &c);
    //input pilihannya
    scanf("%c", &c);
    system("cls");

    if(c == 'y'){
        FILE *infile;
        infile = fopen("HighScores.dat", "rb");
        tampilY = 7;

        if(infile == NULL){
           gotoxy(tampilX, tampilY+1); printf("Ah, sorry, file tidak ditemukan\n");
            exit(0);
        }
        gotoxy(tampilX-4, tampilY+1);printf("No");
        gotoxy(tampilX, tampilY+1);printf("Nama");
        gotoxy(tampilX+20, tampilY+1);printf("Skor");
        i = 0;
        while(fread(&tulis, sizeof(struct formatHS), 1, infile) && i!=10){
            gotoxy(tampilX-4, tampilY+2);printf("%d", i+1);
            gotoxy(tampilX, tampilY+2);printf("%s", tulis.namaPemenang);
            gotoxy(tampilX+20, tampilY+2);printf("%d\n", tulis.skor);
            i++;
            tampilY++;
        }
        //getch();
        fclose(infile);
    }

    data.mulai = false;
    gotoxy(tampilX, tampilY+3);printf("Back To Menu");
    gotoxy(tampilX, tampilY+5);system("pause");
    system("cls");
    main();

}

void Help() {
int x, y, tambah=0;
        system("cls");
		gotoxy(55,2);printf("HELP\n");
		gotoxy(10,3);printf("======================================================================================================\n");
		gotoxy(10,5);printf("1. Player pertama (PLAYER 1 (X) atau PLAYER 2 (O)) akan diminta mengisi baris dan kolom yang diinginkan\n");
		gotoxy(10,6);printf("2. Giliran main akan dilempar ke player kedua setelah n(5(easy),10(medium), atau 15(hard) detik\n");
		gotoxy(10,7);printf("3. Player kedua akan mendapat gilirannya untuk mengisi kolom dan baris yang belum terisi\n");
		gotoxy(10,8);printf("4. Jika setelah n detik atau kotak sudah terisi, maka kesempatan giliran diubah\n");
		gotoxy(10,9);printf("5. Langkah 1 - 4 akan diulangi terus sampai ada salah satu player yang berhasil\n");
		gotoxy(10,10);printf("   mengurutkan X/O sebanyak tiga kali secara berurutan atau bidang permainan sudah penuh\n");
		gotoxy(10,11);printf("6. Score akan dihitung ketika terdapat (X/O) berderet 3 kali dengan rumus :\n");
		gotoxy(10,12);printf("\t\t  Score = Banyak Deret (X/O) + (n - waktu Input Player Terakhir) * Bonus\n");
		gotoxy(10,13);printf("7. Jika permainan sudah selesai, maka game akan meminta inputan untuk melanjutkan permainan atau tidak.\n");
		gotoxy(10,15);printf("Mari dicoba Cara Inputnya !!!");
		gotoxy(10,16);printf("Contoh : Player 1 (X) Input Baris Kolom : 2 3");
		gotoxy(10,17);printf("Ikuti Contoh !, Player (X) Input Baris Kolom : ");
        while(scanf("%d %d", &x, &y)!= 2 && getchar() != '\n'){
            gotoxy(tampilX, 18+tambah); printf("! ONLY INTEGER ! ==> ");
            tambah++;
        }
		if(x!=2 && y!=3){
            gotoxy(10,18);printf("Harap Ikuti Contoh");
            Sleep(2000);
            system("cls");
            Help();
		}else{
            gotoxy(10,18);printf("Selamat Anda Sudah Bisa Menginputkannya :)");
            Sleep(2000);
            system("cls");
            if(ukuran==0){
                data.mulai = false;
                gotoxy(10,18);printf("Back To Menu\n");
                gotoxy(10,19);system("pause");
                system("cls");
                main();
            }
		}

}

void AboutAuthor() {
int a;

		//Algoritma
		menu:
		gotoxy(30,3);printf("pilih salah satu author:   1. Arsal Fadilah\n \t\t\t\t\t\t\t 2. Nauval Ozora Mahadri\n");
		gotoxy(37,6);printf("Pilih No Author :  ");
		scanf("%d", &a);

        printf("\n\n");

		//cek kesalahan pilihan
		if(a<1 || a>2){
			system("cls");
			gotoxy(35,3);printf("Nomer Author yang anda masukan salah !!!\n");
       		gotoxy(35,6);system("pause");
            system("cls");
            goto menu;
		}else{
		if(a<2){
				printf("Nama \t\t\t: Arsal Fadilah\n");
				printf("Tempat, Tanggal Lahir \t: Bandung, 26 April 2002\n");
				printf("Jenis Kelamin \t\t: Laki-laki\n");
				printf("Agama \t\t\t: Islam\n");
				printf("Alamat \t\t\t: Kp. Cidawolong 1 Rt 03/14 Des.Biru Kec.Majalaya Kab.Bandung\n");
				printf("Nomor Telepon \t\t: 081214151280\n");
				printf("E-mail \t\t\t: arsalfadilah2002@gmail.com\n");
				printf("Hobi \t\t\t: Basket\n");
				printf("Motto Hidup \t\t: Never give up ! Trust me its work\n");
			}else{
				printf("Nama \t\t\t: Nauval Ozora Mahadri\n");
				printf("Tempat, Tanggal Lahir \t: Bandung, 29 Juli 2002\n");
				printf("Jenis Kelamin \t\t: Laki-laki\n");
				printf("Agama \t\t\t: Islam\n");
				printf("Alamat \t\t\t: Jalan Cibangkong Tengah RT.09/RW.11 NO.300/120\n");
				printf("Nomor Telepon \t\t: 085624333058\n");
				printf("E-mail \t\t\t: ozoramahadri02@gmail.com\n");
				printf("Hobi \t\t\t: baca\n");
				printf("Motto Hidup \t\t: gak ada yang gak bisa\n");
			}
		}

    data.mulai = true;
    gotoxy(0,24);printf("\nBack To Menu\n");
    gotoxy(0,25);system("pause");
    system("cls");
    main();

}

void loadGame(){

    FILE *loadFile;

    loadFile = fopen("saveFile.dat", "rb");

    while(fread(&data, sizeof(struct dataPlayer), 1, loadFile)){
        printf("loading . . .");
        system("cls");
    }

    //printf("%d", data.mulai);
    //system("pause");

    fclose(loadFile);

    switch (data.level) {
        case 1: Easy(); break;
        case 2: Medium(); break;
        case 3: Hard(); break;
    }

}

void savedGame(){

    char c;

    gotoxy(tampilX-20, tampilY+2);printf("Jika Anda Menyimpan Game Kali Ini, Data Yang Dulu Tersimpan Akan Tegantikan.");
    gotoxy(tampilX, tampilY+3);printf("Yakin Mau Menyimpannya (y/t) ? ");
    //input tambahan untuk \n
    scanf("%c", &c);
    scanf("%c", &c);

    if(c == 'y'){
        FILE *savedFile;

        savedFile = fopen("saveFile.dat", "wb");

        if(fwrite(&data, sizeof(struct dataPlayer), 1, savedFile) != 0){
            gotoxy(tampilX, tampilY+4);printf("Game berhasil disimpan !!!");
            gotoxy(tampilX, tampilY+5);printf("Mau lanjut ? (y/t) : ");
            //input tambahan \n
            scanf("%c", &c);
            scanf("%c", &c);
            fclose(savedFile);
            if(c == 'y'){
                PlayTheGame();
            } else {
                main();
            }
        } else {
            printf("Ops, ada yang salah :(");
            fclose(savedFile);
        }


    } else {
        printf("Oke lanjut gan ...");
        PlayTheGame();
    }

}

void exitGame() {
	char c;
	
	gotoxy(tampilX, tampilY);printf("Anda mau keluar dari game ? (y/t) : ");
    scanf("%c", &c);
    scanf("%c", &c);
    system("cls");
	if(c == 't'){
		gotoxy(0,24);printf("\nBack To Menu\n");
    	gotoxy(0,25);system("pause");
   	 	main();
	}else{
   	 	exit(0);
	}
    
}

void SetColor(int ForgC){

    //code copy  from stackoverflow
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }

}

void gotoxy(int x, int y){
	//Deskripsi: Prosedur untuk menentukan posisi koordinat yang dikehendaki pada layar
	//I.S.: Koordinat pada layar belum ditentukan
	//F.S.: Koordinat peda layar sudah ditentukan
    HANDLE screen = GetStdHandle( STD_OUTPUT_HANDLE );

	COORD set;
	set.X = x;
	set.Y = y;
	SetConsoleCursorPosition(screen, set);
}

void tampilan_awal(){
	tampilX=48;
    tampilY=12;
    
	gotoxy(tampilX+5, tampilY);printf("AVRA.COM");
	gotoxy(tampilX, tampilY+3);printf("ULTIMATE TIC TAC TOE");
	Sleep(5000);
}
