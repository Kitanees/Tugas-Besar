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
void yourGame();
void HighScores();
void Help();
void AboutAuthor();
void loadGame();
void savedGame();
void exitGame();

/*modul interface*/
void SetColor(int ForgC);


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
    char matrix_2D[10][10];
    bool mulai;
} data;

int main() {

    //set background
    system("color 0B");

    //play backsound
    PlaySound(TEXT("themesong.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    if((data.posisi!=1 ||data.score_2 != 2) && !data.mulai){
        LoadDisplay();
    }

    //inisialisasi var
    ukuran = 0;
    data.posisi = 0;
    data.score_1 = 0;
    data.score_2 = 0;
    data.mulai = true;

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
        printf("WRONG INPUT NUMBER.\n");
        printf("Pilih nomer aja salah, apalagi pilih pasangan hidup -.-\n\n");
        system("pause");
        system("cls");
        goto menu;
    }

    return 0;
}

void LoadDisplay() {
    int i;

    system("cls");

    for(i=0; i<=100; i++){
        printf("%d %%\nloading . . .", i);
        system("cls");
    }


}

void DisplayMenu() {

    system("cls");

    printf("\t\t\tMenu\n");
    printf("=====================================================\n");
    printf("1. Play Game\n");
    printf("2. Load Game\n");
    printf("3. High Score\n");
    printf("4. Help\n");
    printf("5. About Author\n");
    printf("6. Exit\n\n");
    printf("please input number of menu, your choose : ");

}

int InputMenu() {
    int x;

    while(scanf("%d", &x)!= 1 && getchar() != '\n'){
        printf("! ONLY INTEGER ! ==> ");
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
    int x;

    printf("Pilih Lawan : \n");
    printf("1. Player Vs Player\n");
    printf("2. Player Vs Computer\n\n");
    printf("Pilihan kamu : ");
    while(scanf("%d", &x)!= 1 && getchar() != '\n'){
        printf("! ONLY INTEGER ! ==> ");
    }
    system("cls");

    if(x==1 || x==2){
        return x;
    }else {
        printf("Ops, anda salah input\n");
        system("pause");
        system("cls");
        return ChooseEnemy();
    }

}

int ChooseLevel() {
    int x;

    printf("Pilih Level : \n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("4. Your Own Game\n\n");
    printf("Pilihan kamu : ");
    while(scanf("%d", &x)!= 1 && getchar() != '\n'){
        printf("! ONLY INTEGER ! ==> ");
    }
    system("cls");

    if(x>=1 && x<=4){
       return x;
    } else {
        printf("Ops anda salah menginputkan !\n");
        system("pause");
        system("cls");
        return ChooseLevel();
    }

}

void InpuNama() {

    if(data.enemy==1){
        printf("nama player 1 (X) : ");
        fgets(data.nama, sizeof(data.nama), stdin);
        data.nama[strlen(data.nama) - 1] = '\0';
        scanf("%[^\n]s", data.nama);
        printf("nama player 2 (O) : ");
        fgets(data.nama_2, sizeof(data.nama_2), stdin);
        data.nama_2[strlen(data.nama_2) - 1] = '\0';
        scanf("%[^\n]s", data.nama_2);
    } else {
        printf("nama kamu : ");
        fgets(data.nama, sizeof(data.nama), stdin);
        data.nama[strlen(data.nama) - 1] = '\0';
        scanf("%[^\n]s", data.nama);
        strcpy(data.nama_2, "Arva_Com");
        printf("nama komputer : %s\n", data.nama_2);
        system("pause");

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
		int kom, P,s,i,menang;
		//Deskripsi: merandom nomor suwit computer
		//Input: -
		//Output: integer hasil random suwit
        system("cls");
		printf("Sebelum Bermain, Tentukan siapa yang akan Bermain Terlebih Dahulu....\n");
		printf("Tunggu Sebentar. Jangan Kemana - mana!!! ");
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
							printf("PLAYER %s MENDAPATKAN BATU\n", data.nama_2);
							if(P==1){
								printf("PLAYER %s MENDAPATKAN BATU\n", data.nama);
								printf("HASIL SERI!!! ULANGI LAGI!");
							}
							else if(P==2){
								printf("PLAYER %s MENDAPATKAN GUNTING\n", data.nama);
								printf("PLAYER %s BERMAIN TERLEBIH DAHULU", data.nama_2);
								menang=2;
							}
							else if(P==3){
								printf("PLAYER %s MENDAPATKAN KERTAS\n", data.nama);
								printf("PLAYER %s BERMAIN TERLEBIH DAHULU", data.nama);
								menang=1;
							}
						}
						else if(kom==2){
							printf("PLAYER %s MENDAPATKAN GUNTING\n", data.nama_2);
							if(P==1){
								printf("PLAYER %s MENDAPATKAN BATU\n", data.nama);
								printf("PLAYER %s BERMAIN TERLEBIH DAHULU", data.nama);
								menang=1;
							}
							else if(P==2){
								printf("PLAYER %s MENDAPATKAN GUNTING\n", data.nama);
								printf("HASIL SERI!!! ULANGI LAGI!");
							}
							else if(P==3){
								printf("PLAYER %s MENDAPATKAN KERTAS\n", data.nama);
								printf("PLAYER %s BERMAIN TERLEBIH DAHULU", data.nama_2);
								menang=2;
							}
						}
						else if(kom==3){
							printf("PLAYER %s MENDAPATKAN KERTAS\n", data.nama_2);
							if(P==1){
								printf("PLAYER %s MENDAPATKAN BATU\n", data.nama);
								printf("PLAYER %s BERMAIN TERLEBIH DAHULU", data.nama_2);
								menang=2;
							}
							else if(P==2){
								printf("PLAYER %s MENDAPATKAN GUNTING\n", data.nama);
								printf("PLAYER %s BERMAIN TERLEBIH DAHULU", data.nama);
								menang=1;
							}
							else if(P==3){
								printf("PLAYER %s MENDAPATKAN KERTAS\n", data.nama);
								printf("HASIL SERI!!! ULANGI LAGI!");
							}
						}
				break;
				case 2 :
					P =rand()%3+1;
					kom=rand()%3+1;
						if(kom==1){
							printf("KOMPUTER MENDAPATKAN BATU\n");
							if(P==1){
								printf("PLAYER MENDAPATKAN BATU\n");
								printf("HASIL SERI!!! ULANGI LAGI!");
							}
							else if(P==2){
								printf("Player mendapatkan Gunting\n");
								printf("KOMPUTER BERMAIN TERLEBIH DAHULU");
								menang=2;
							}
							else if(P==3){
								printf("PLAYER MENDAPATKAN KERTAS\n");
								printf("PLAYER BERMAIN TERLEBIH DAHULU");
								menang=1;
							}
						}
						else if(kom==2){
							printf("KOMPUTER MENDAPATKAN GUNTING\n");
							if(P==1){
								printf("PLAYER MENDAPATKAN BATU\n");
								printf("PLAYER BERMAIN TERLEBIH DAHULU");
								menang=1;
							}
							else if(P==2){
								printf("PLAYER MENDAPATKAN GUNTING\n");
								printf("HASIL SERI!!! ULANGI LAGI!");
							}
							else if(P==3){
								printf("PLAYER MENDAPATKAN KERTAS\n");
								printf("KOMPUTER BERMAIN TERLEBIH DAHULU");
								menang=2;
							}
						}
						else if(kom==3){
							printf("KOMPUTER MENDAPATKAN KERTAS\n");
							if(P==1){
								printf("PLAYER MENDAPATKAN BATU\n");
								printf("KOMPUTER BERMAIN TERLEBIH DAHULU");
								menang=2;
							}
							else if(P==2){
								printf("PLAYER MENDAPATKAN GUNTING\n");
								printf("PLAYER BERMAIN TERLEBIH DAHULU");
								menang=1;
							}
							else if(P==3){
								printf("PLAYER MENDAPATKAN KERTAS\n");
								printf("HASIL SERI!!! ULANGI LAGI!");
							}
						}
						break;
						}
					}while(P==kom);

					printf("\n");
                    system("pause");
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

    if(lagu){
        PlaySound(TEXT("musicingame.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        lagu = false;
    }

    LoadDisplay();

    if(data.posisi!=1 && data.posisi!=2){
        persiapanMatrix();
    }

    DisplayBoard();

    while (data.mulai) {
        PlayTheGame();
    }

    system("cls");
    DisplayBoard();
    if(CekPenuh()){
        printf("\nSERI\n");
        printf("Ulang (y/t) ? ");
        scanf("%c", &c);
        scanf("%c", &c);
        if(c=='y'){
            Easy();
        }else{
            main();
        }
    }else{
        printf("\nGAME OVER\n");
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
    int i, j;

    system("color 0B");
    printf("\n%s\t\t vs \t\t%s\n", data.nama, data.nama_2);
    printf("score X : %d \t\t\tscore O : %d\n\n", data.score_1, data.score_2);

    for (i = 0; i < ukuran; i++) {
        for (j = 0; j < ukuran; j++) {
            if(data.matrix_2D[i][j]=='\0'){
                SetColor(9);
                printf("|_ _");
            } else if (data.matrix_2D[i][j]>=48 && data.matrix_2D[i][j] <= 57){
                SetColor(10);
                printf("  %c ", data.matrix_2D[i][j]);
            } else if (data.matrix_2D[i][j] != '/' && data.matrix_2D[i][j] != '\\'){
                SetColor(14);
                printf("|_%c_", data.matrix_2D[i][j]);
            } else if (data.matrix_2D[i][j]=='/'){
                SetColor(4);
                printf("|_%c_", data.matrix_2D[i][j]);
            } else {
                SetColor(5);
                printf("|_%c_", data.matrix_2D[i][j]);
            }
        }
        if (data.matrix_2D[i][j-1]>=48 && data.matrix_2D[i][j-1] <= 57){
            printf("\n\n");
        } else {
            printf("| \n\n");
        }
    }

    SetColor(14);

}

void PlayTheGame() {
    int bar = 0, col = 0;
    double waktuInput = 0;
    bool penuh = true;


    if (data.enemy == 1 && data.menangSuit == 1) {
        //Inputan ;
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
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            } else if (bar == 0 && col ==0){
                savedGame();
            } else {
                printf("kotak penuh, giliran diganti !\n");
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
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            } else if(bar == 0 && col ==0){
                savedGame();
            } else {
                printf("kotak penuh, giliran diganti !\n");
            }
            GameOver();
        }
        data.posisi=data.posisi-1;
    }
    else if (data.enemy == 1 && data.menangSuit == 2) {
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
                    printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            } else if(bar == 0 && col ==0){
                savedGame();
            } else {
                printf("kotak penuh, giliran diganti !\n");
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
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            } else if(bar == 0 && col ==0){
                savedGame();
            } else {
                printf("kotak penuh, giliran diganti !\n");
            }
            GameOver();
        }
        data.posisi=data.posisi-1;
    }
    else if (data.enemy == 2 && data.menangSuit == 1) {
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
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            } else if(bar == 0 && col ==0){
                    savedGame();
            } else {
                printf("kotak penuh, giliran diganti !\n");
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
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            } else if(bar == 0 && col ==0){
                    savedGame();
            } else {
                printf("kotak penuh, giliran diganti !\n");
            }
            GameOver();
        }
        data.posisi=data.posisi-1;
    }
    else if(data.enemy == 2 && data.menangSuit == 2) {
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
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            }
            //else if(bar == 0 && col ==0){
              //      savedGame();
            //}
            else {
                printf("kotak penuh, giliran diganti !\n");
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
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            } else if(bar == 0 && col ==0){
                savedGame();
            } else {
                printf("kotak penuh, giliran diganti !\n");
            }
            GameOver();
        }
        data.posisi=data.posisi-1;
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
    int baris=0, kolom=0;
    double time_taken=0;
    int t;

    //StartTime
    t = StartTime();
    printf("(X) input baris kolom : ");
    while(scanf("%d %d", &baris, &kolom)!= 2 && getchar() != '\n'){
        printf("! ONLY INTEGER ! ==> ");
    }
    t = EndTime() - t;

    *x = baris;
    *y = kolom;
    *waktuInput = ((double)t)/CLOCKS_PER_SEC;

}

void p_2_InputO(int* x, int* y, double *waktuInput) {
    int baris=0, kolom=0;
    double time_taken=0;
    int t;

    //StartTime
    t = StartTime();
    printf("(O) input baris kolom : ");
    while(scanf("%d %d", &baris, &kolom)!= 2 && getchar() != '\n'){
        printf("! ONLY INTEGER ! ==> ");
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
                    for(k; k>=j; k--){
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
                    for(k; k>=j; k--){
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
                    for(k; k>=j; k--){
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
                    for(k; k>=j; k--){
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
                    for(k; k>=j; k--){
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
                    for(k; k>=j; k--){
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
                        for(i; i>=l; i--){
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
                        for(i; i>=l; i--){
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
                        for(i; i>=l; i--){
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
                        for(i; i>=l; i--){
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
    int i=0, j=0, k=0, l=0, bar=0, col=0;

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
                printf("\nGAME OVER\n");
            }
            else if(!data.mulai){
                data.mulai=true;
            }
        } else if (CekPenuh()){
            printf("\nSERI\n");
        }

}

void Medium() {

    bonus = 120;
    ukuran = 6;
    waktu = 7;

    bool lagu = true;

    if(lagu){
        PlaySound(TEXT("musicingame.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        lagu = false;
    }

    LoadDisplay();

    if(data.posisi!=1 && data.posisi!=2){
        persiapanMatrix();
    }

    DisplayBoard();

    while (data.mulai) {
        PlayTheGame();
    }

    system("cls");
    DisplayBoard();
    printf("\nGAME OVER\n");

    HighScores();

}

void Hard() {

    bonus = 150;
    ukuran = 8;
    waktu = 5;

    bool lagu = true;

    if(lagu){
        PlaySound(TEXT("musicingame"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        lagu = false;
    }

    LoadDisplay();

    if(data.posisi!=1 && data.posisi!=2){
        persiapanMatrix();
    }

    DisplayBoard();

    while (data.mulai) {
        PlayTheGame();
    }

    system("cls");
    DisplayBoard();
    printf("\nGAME OVER\n");
    HighScores();
}

void PlayerVsComputer() {
    int menangSuit;

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
    int i, j, k, l;
    int t;

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

        printf("(O) input baris kolom : %d %d", bar, col);

    t = EndTime() - t;
    Sleep(2000);

    *x = bar;
    *y = col;
    *waktuInput = ((double)t)/CLOCKS_PER_SEC;

}

void yourGame(){

    printf("Berapa ukuran papan mu ? ");
    while(scanf("%d", &ukuran)!= 1 && getchar() != '\n'){
        printf("! ONLY INTEGER ! ==> ");
    }

    if(ukuran<=3){
        printf("Maaf papan mu tidak bisa diciptakan karena ukurannya terlalu kecil\n");
        printf("Ulangi lagi yah :)\n");
        Sleep(3000);
        yourGame();
    }

    printf("Berapa lama batas waktu inputan ? ");
    while(scanf("%lf", &waktu)!= 1 && getchar() != '\n'){
        printf("! ONLY INTEGER ! ==> ");
    }

    if(waktu<=0){
        printf("Maaf waktu mu tidak bisa diciptakan karena waktunya terlalu kecil\n");
        printf("Ulangi lagi yah :)\n");
        Sleep(3000);
        yourGame();
    }

    printf("Berapa skor bonus yang mau kamu dapatkan ?");
    while(scanf("%d", &bonus)!= 1 && getchar() != '\n'){
        printf("! ONLY INTEGER ! ==> ");
    }

    bool lagu = true;

    if(lagu){
        PlaySound(TEXT("musicingame.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        lagu = false;
    }

    LoadDisplay();

    if(data.posisi!=1 && data.posisi!=2){
        persiapanMatrix();
    }

    DisplayBoard();

    while (data.mulai) {
        PlayTheGame();
    }

    system("cls");
    DisplayBoard();
    printf("\nGAME OVER\n");

    HighScores();

}

void HighScores() {

    char c;
    int n=0, i=0, j=0;

    struct formatHS{
        char namaPemenang[20];
        int skor;
    }sortScore[500], tulis;

    /*open file for writing appending*/
    if(ukuran!=0){
        FILE *outfile;

        outfile = fopen("HighScores.dat", "ab");

        //check menang kalah
        if(data.score_1>data.score_2){
            strcpy(tulis.namaPemenang, data.nama);
            tulis.skor = data.score_1;
        } else {
            strcpy(tulis.namaPemenang, data.nama_2);
            tulis.skor = data.score_2;
        }

        printf("\n%s, Selamat Bang Jagoo !!!\n", tulis.namaPemenang);

        //writing file
        fwrite(&tulis, sizeof(struct formatHS), 1, outfile);

        //check if file not succed write
        if(fwrite != 0){
            printf("High Score Berhasil disimpan\n");
            system("pause");
        } else {
            printf("sorry ada masalah :(\n");
        }

        fclose(outfile);

        /*open file for sorting descending*/
        FILE *sortFile;
        sortFile = fopen("HighScores.dat", "rb");

        //input array of struct from file
        while(fread(&sortScore[i], sizeof(struct formatHS), 1, sortFile)){
            printf("%d\n", i);
            system("cls");
            i++;
            n++;
        }

        system("pause");

        fclose(sortFile);

        //sort struxt data
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
    printf("Anda mau melihat High Score ? (y/t) : ");
    //input \n yg terbawa sebelumnya
    scanf("%c", &c);
    //input pilihannya
    scanf("%c", &c);

    if(c == 'y'){
        FILE *infile;
        infile = fopen("HighScores.dat", "rb");

        if(infile == NULL){
            printf("Ah, sorry, file tidak ditemukan\n");
            exit(0);
        }
        printf("Nama\t\t\tSkor\n");
        i = 0;
        while(fread(&tulis, sizeof(struct formatHS), 1, infile) && i!=10){
            printf("%s\t\t\t%d\n", tulis.namaPemenang, tulis.skor);
            i++;
        }

        fclose(infile);
    }

    data.mulai = false;
    printf("\nBack To Menu\n");
    system("pause");
    system("cls");
    main();

}

void Help() {
printf("\t\t\t\t\t\tHELP\n");
		printf("======================================================================================================\n");
		printf("1. Player pertama akan diminta mengisi kolom dan baris yang diinginkan seusai keinginan\n");
		printf("2. Giliran main akan dilempar ke player kedua setelah n(5,10, atau 15) detik\n");
		printf("3. Player kedua akan mendapat gilirannya untuk mengisi kolom dan baris yang belum terisi\n");
		printf("4. Langkah 1 - 3 akan diulangi terus sampai ada salah satu player yang berhasil\n");
		printf("   mengurutkan X/O sebanyak tiga kali secara berurutan atau bidang permainan sudah penuh\n");
		printf("5. Jika permainan sudah selesai, maka game akan meminta inputan untuk melanjutkan permainan atau tidak.\n");

    data.mulai = false;
    printf("\nBack To Menu\n");
    system("pause");
    system("cls");
    main();

}

void AboutAuthor() {
int a;

		//logaritma
		printf("pilih salah satu author: 1. Arsal Fadilah\n\t\t\t 2. Nauval Ozora Mahadri\n");
		printf("Pilih no author : ");
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
				//printf("Alamat Asal \t: Kp. Cidawolong 1 Rt 03/14 Des.Biru Kec.Majalaya Kab.Bandung\n");
				printf("Nomor Telepon \t\t: 085624333058\n");
				printf("E-mail \t\t\t: ozoramahadri02@gmail.com\n");
				printf("Hobi \t\t\t: baca\n");
				printf("Motto Hidup \t\t: gak ada yang gak bisa\n");
			}
		}

    data.mulai = false;
    printf("\nBack To Menu\n");
    system("pause");
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

    printf("Jika anda menyimpan game kali ini, data yang dulu tersimpan akan tegantikan.\n");
    printf("Yakin mau menyimpannya (y/t) ? ");
    //input tambahan untuk \n
    scanf("%c", &c);
    scanf("%c", &c);

    if(c == 'y'){
        FILE *savedFile;

        savedFile = fopen("saveFile.dat", "wb");

        fwrite(&data, sizeof(struct dataPlayer), 1, savedFile);

        fclose(savedFile);

        if(fwrite != 0){
            printf("Game berhasil disimpan !!!");
            printf("Mau lanjut ? (y/t) : ");
            //input tambahan \n
            scanf("%c", &c);
            scanf("%c", &c);
            if(c == 'y'){
                PlayTheGame();
            } else {
                main();
            }
        } else {
            printf("Ops, ada yang salah :(");
        }


    } else {
        printf("Oke lanjut gan ...");
        PlayTheGame();
    }

}

void exitGame() {
    exit(0);
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

