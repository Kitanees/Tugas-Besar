#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
//Authors : Arsal Fadilah && Nauval Ozora

/*kumpulan modul*/
void LoadGame();
void DisplayMenu();
int InputMenu();
void StartGame();
int ChooseEnemy();
int ChooseLevel();
void InpuNama();
void PlayerVsPlayer();
int suit();
void Easy(int menangSuit);
void DisplayBoard();
void persiapanMatrix();
void PlayTheGame(int menangSuit, int bonus);
int StartTime();
int EndTime();
void p_1_InputX(int* x, int* y, double *waktuInput);
void p_2_InputO(int* x, int* y, double *waktuInput);
bool CekSel(int x, int y);
bool CekBar();
bool CekCol();
bool CekDiagon();
bool CekPenuh();
void GameOver();
void Medium(int menangSuit);
void Hard(int menangSuit);
void PlayerVsComputer();
char p_com_InputO();
void HighScores();
void Help();
void AboutAuthor();
void exitGame();

//variabel global
int enemy, level, ukuran;
double waktu;
struct dataPlayer {
    int score_1;
    int score_2;
    char nama[20];
    char nama_2[20];
} data;
char matrix_2D[10][10];
bool mulai = true;

int main() {

    LoadGame();
menu:
    DisplayMenu();
    switch (InputMenu()) {
    case 1: StartGame(); break;
    case 2: HighScores(); break;
    case 3: Help(); break;
    case 4: AboutAuthor(); break;
    case 5: exitGame(); break;
    default:
        printf("WRONG INPUT NUMBER.\n");
        printf("Pilih nomer aja salah, apalagi pilih pasangan hidup -.-\n\n");
        system("pause");
        system("cls");
        goto menu;
    }

    return 0;
}

void LoadGame() {
    int i;

    for(i=0; i<=100; i++){
        printf("%d %%\nloading . . .", i);
        system("cls");
    }


}

void DisplayMenu() {

    printf("\t\t\tMenu\n");
    printf("=====================================================\n");
    printf("1. Play Game\n");
    printf("2. High Score\n");
    printf("3. Help\n");
    printf("4. About Author\n");
    printf("5. Exit\n\n");
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

    enemy = ChooseEnemy();
    level = ChooseLevel();

    switch (enemy) {
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
    printf("3. Hard\n\n");
    printf("Pilihan kamu : ");
    while(scanf("%d", &x)!= 1 && getchar() != '\n'){
        printf("! ONLY INTEGER ! ==> ");
    }
    system("cls");

    if(x>=1 && x<=3){
       return x;
    } else {
        printf("Ops anda salah menginputkan !\n");
        system("pause");
        system("cls");
        return ChooseLevel();
    }

}

void InpuNama() {

    if(enemy==1){
        printf("nama player 1 : ");
        fgets(data.nama, sizeof(data.nama), stdin);
        data.nama[strlen(data.nama) - 1] = '\0';
        scanf("%[^\n]s", data.nama);
        printf("nama player 2 : ");
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
    int menangSuit;

    InpuNama();
    menangSuit = suit();
    switch (level) {
        case 1: Easy(menangSuit); break;
        case 2: Medium(menangSuit); break;
        case 3: Hard(menangSuit); break;
    }

}

int suit() {
    		system("cls");
		//Deklarasi
		int kom, P,s,i,menang;
		//Deskripsi: merandom nomor suwit computer
		//Input: -
		//Output: integer hasil random suwit

		printf("Sebelum Bermain, Tentukan siapa yang akan Bermain Terlebih Dahulu....\n");
		printf("Tunggu Sebentar. Jangan Kemana - mana!!!");
		for(i=0;i<999999999;i++){
		}
		system("cls");
		do{
			system("cls");
			srand(time(0));//1.Batu 2.Gunting 3.Kertas
			switch(enemy){
				case 1 :
					P =rand()%3+1;
					kom=rand()%3+1;
						if(kom==1){
							printf("PLAYER 2 MENDAPATKAN BATU\n");
							if(P==1){
								printf("PLAYER 1 MENDAPATKAN BATU\n");
								printf("HASIL SERI!!! ULANGI LAGI!");
							}
							else if(P==2){
								printf("PLAYER 1 MENDAPATKAN GUNTING\n");
								printf("PLAYER 2 BERMAIN TERLEBIH DAHULU");
								menang=2;
							}
							else if(P==3){
								printf("PLAYER 1 MENDAPATKAN KERTAS\n");
								printf("PLAYER 1 BERMAIN TERLEBIH DAHULU");
								menang=1;
							}
						}
						else if(kom==2){
							printf("PLAYER 2 MENDAPATKAN GUNTING\n");
							if(P==1){
								printf("PLAYER 1 MENDAPATKAN BATU\n");
								printf("PLAYER BERMAIN TERLEBIH DAHULU");
								menang=1;
							}
							else if(P==2){
								printf("PLAYER 1 MENDAPATKAN GUNTING\n");
								printf("HASIL SERI!!! ULANGI LAGI!");
							}
							else if(P==3){
								printf("PLAYER 1 MENDAPATKAN KERTAS\n");
								printf("PLAYER 2 BERMAIN TERLEBIH DAHULU");
								menang=2;
							}
						}
						else if(kom==3){
							printf("PLAYER 2 MENDAPATKAN KERTAS\n");
							if(P==1){
								printf("PLAYER 1 MENDAPATKAN BATU\n");
								printf("PLAYER 2 BERMAIN TERLEBIH DAHULU");
								menang=2;
							}
							else if(P==2){
								printf("PLAYER 1 MENDAPATKAN GUNTING\n");
								printf("PLAYER 1 BERMAIN TERLEBIH DAHULU");
								menang=1;
							}
							else if(P==3){
								printf("PLAYER 1 MENDAPATKAN KERTAS\n");
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

void Easy(int menangSuit) {

    int bonus = 300;
    ukuran = 4;
    waktu = 10;

    persiapanMatrix();
    DisplayBoard();

    while (mulai) {
        PlayTheGame(menangSuit, bonus);
    }

    system("cls");
    DisplayBoard();
    printf("\nGAME OVER\n");
    HighScores();

}

void persiapanMatrix() {
    char angkaCol, angkaBar;
    int i, j;

    angkaCol = '1';
    for (i = 0; i < ukuran ; i++) {
        angkaBar = '0';
        for (j = 0; j < ukuran; j++) {
            if (i == 0) {
                matrix_2D[i][j] = angkaBar;
                angkaBar = angkaBar + 1;
            }
            else if (j == 0) {
                matrix_2D[i][j] = angkaCol;
                angkaCol = angkaCol + 1;
            }
            else {
                matrix_2D[i][j] = '\0';
            }
        }
    }
}

void DisplayBoard(){
    int i, j;

    printf("\n%s\t\t vs \t\t%s\n", data.nama, data.nama_2);
    printf("score X : %d \t\t\tscore O : %d\n\n", data.score_1, data.score_2);

    for (i = 0; i < ukuran; i++) {
        for (j = 0; j < ukuran; j++) {
            if(matrix_2D[i][j]=='\0'){
                printf("  ");
            }else{
                printf("%c ", matrix_2D[i][j]);
            }
        }
        printf("\n");
    }

}

void PlayTheGame(int menangSuit, int bonus) {
    int bar = 0, col = 0;
    double waktuInput = 0;

    if (enemy == 1 && menangSuit == 1) {
        //Inputan ;
        p_1_InputX(&bar, &col, &waktuInput);
        if (CekSel(bar, col) && waktuInput<=waktu) {
            system("cls");
            matrix_2D[bar][col] = 'X';
            DisplayBoard();
            if(CekBar()){
                mulai = false;
            } else if(CekCol()){
                mulai = false;
            } else if(CekDiagon()){
                mulai = false;
            } else if(CekPenuh()){
                mulai = false;
            }
            //Hitung Highscores
            if(!mulai){
                data.score_1++;
                data.score_1 = data.score_1+(waktu-waktuInput)*bonus;
            }

        } else if(waktuInput>waktu){
            printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
        } else {
            printf("kotak penuh, giliran diganti !\n");
        }

        GameOver();

        if(mulai){
            //system("cls");
            p_2_InputO(&bar, &col, &waktuInput);
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                matrix_2D[bar][col] = 'O';
                DisplayBoard();
                if(CekBar()){
                    mulai = false;
                } else if(CekCol()){
                    mulai = false;
                } else if(CekDiagon()){
                    mulai = false;
                } else if(CekPenuh()){
                    mulai = false;
                }

                if(!mulai){
                    data.score_2++;
                    data.score_2 = data.score_2+(waktu-waktuInput)*bonus;
                }

            } else if(waktuInput>waktu){
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            } else {
                printf("kotak penuh, giliran diganti !\n");
            }
            GameOver();
        }

    }
    else if (enemy == 1 && menangSuit == 2) {
        p_2_InputO(&bar, &col, &waktuInput);
        if (CekSel(bar, col) && waktuInput<=waktu) {
            system("cls");
            matrix_2D[bar][col] = 'O';
            DisplayBoard();
            if(CekBar()){
                mulai = false;
            } else if(CekCol()){
                mulai = false;
            } else if(CekDiagon()){
                mulai = false;
            } else if(CekPenuh()){
                mulai = false;
            }

            if(!mulai){
                data.score_2++;
                data.score_2 = data.score_2+(waktu-waktuInput)*bonus;
            }

        } else if(waktuInput>waktu){
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
        } else {
            printf("kotak penuh, giliran diganti !\n");
        }

        GameOver();

        if(mulai){
            p_1_InputX(&bar, &col, &waktuInput);
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                matrix_2D[bar][col] = 'X';
                DisplayBoard();
                if(CekBar()){
                    mulai = false;
                } else if(CekCol()){
                    mulai = false;
                } else if(CekDiagon()){
                    mulai = false;
                } else if(CekPenuh()){
                    mulai = false;
                }

                if(!mulai){
                    data.score_1++;
                    data.score_1 = data.score_1+(waktu-waktuInput)*bonus;
                }

            } else if(waktuInput>waktu){
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            } else {
                printf("kotak penuh, giliran diganti !\n");
            }
            GameOver();
        }

    }
    else if (enemy == 2 && menangSuit == 1) {
        p_1_InputX(&bar, &col, &waktuInput);
        if (CekSel(bar, col) && waktuInput<=waktu) {
            system("cls");
            matrix_2D[bar][col] = 'X';
            DisplayBoard();
            if(CekBar()){
                mulai = false;
            } else if(CekCol()){
                mulai = false;
            } else if(CekDiagon()){
                mulai = false;
            } else if(CekPenuh()){
                mulai = false;
            }

            if(!mulai){
                data.score_1++;
                data.score_1 = data.score_1+(waktu-waktuInput)*bonus;
            }

        } else if(waktuInput>waktu){
            printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
        } else {
            printf("kotak penuh, giliran diganti !\n");
        }
        GameOver();

        if(mulai){
            p_com_InputO();
            GameOver();
        }
    }
    else {
        p_com_InputO();
        GameOver();

        if(mulai){
            p_1_InputX(&bar, &col, &waktuInput);
            if (CekSel(bar, col) && waktuInput<=waktu) {
                system("cls");
                matrix_2D[bar][col] = 'X';
                DisplayBoard();
                if(CekBar()){
                    mulai = false;
                } else if(CekCol()){
                    mulai = false;
                } else if(CekDiagon()){
                    mulai = false;
                } else if(CekPenuh()){
                    mulai = false;
                }

                if(!mulai){
                    data.score_1++;
                    data.score_1 = data.score_1+(waktu-waktuInput)*bonus;
                }

            } else if(waktuInput>waktu){
                printf("giliran diganti karena :\n waktu berpikir anda %.2f s\n harusnya %.0f s\n", waktuInput, waktu);
            } else {
                printf("kotak penuh, giliran diganti !\n");
            }
            GameOver();
        }
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

    if (matrix_2D[x][y] == '\0') {
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
                 if(matrix_2D[i][k]=='X'){
                    count++;
                }
                if(count==3){
                    for(k; k>=j; k--){
                        matrix_2D[i][k]='\\';
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
                if(matrix_2D[i][k]=='O'){
                    count++;
                }
                if(count==3){
                    for(k; k>=j; k--){
                        matrix_2D[i][k]='/';
                    }
                    return true;
                }
            }

        }
    }

    return false;

}

bool CekCol() {
    int count=0;
    int i, j, k;

    //cek Col X
    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran-2; j++){
            count = 0;
            for(k=j; k<j+3; k++){
               if(matrix_2D[k][i]=='X'){
                    count++;
                }
                if(count==3){
                    for(k; k>=j; k--){
                        matrix_2D[k][i]='\\';
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
               if(matrix_2D[k][i]=='O'){
                    count++;
                }
                if(count==3){
                    for(k; k>=j; k--){
                        matrix_2D[k][i]='/';
                    }
                    return true;
                }
            }
        }
    }

    return false;

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
                        if(matrix_2D[i][j]=='X'){
                            count++;
                        }
                    }
                    if(count==3){
                        for(i; i>=l; i--){
                            for(j=k+2; j>=k; j--){
                                if(i+tambahBar==j+tambahKol){
                                    matrix_2D[i][j]='\\';
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
                        if(matrix_2D[j][i]=='X'){
                            count++;
                        }
                    }
                    if(count==3){
                        for(i; i>=l; i--){
                            for(j=k; j<=k+2; j++){
                                if(i+j==k+3+tambahKol){
                                    matrix_2D[j][i]='\\';
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
                        if(matrix_2D[i][j]=='O'){
                            count++;
                        }
                    }
                    if(count==3){
                        for(i; i>=l; i--){
                            for(j=k+2; j>=k; j--){
                                if(i+tambahBar==j+tambahKol){
                                    matrix_2D[i][j]='/';
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
                for(j=k+3-1; j>=k; j--){
                    if(i+j==k+3+tambahKol){
                        if(matrix_2D[j][i]=='O'){
                            count++;
                        }
                    }
                    if(count==3){
                        for(i; i>=l; i--){
                            for(j=k+2; j>=k; j--){
                                if(i+tambahBar==j+tambahKol){
                                    matrix_2D[i][j]='/';
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

bool CekPenuh(){
    int i , j, count=0;
    int penuh = ukuran - 1;
    penuh = penuh * penuh;

    for(i=1; i<ukuran; i++){
        for(j=1; j<ukuran; j++){
            if(matrix_2D[i][j]!='\0'){
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
            else if(!mulai){
                mulai=true;
            }
        }

}

void Medium(int menangSuit) {

    int bonus = 120;
    ukuran = 6;
    waktu = 7;

    persiapanMatrix();
    DisplayBoard();

    while (mulai) {
        PlayTheGame(menangSuit, bonus);
    }

    system("cls");
    DisplayBoard();
    printf("\nGAME OVER\n");

    HighScores();

}

void Hard(int menangSuit) {

    int bonus = 150;
    ukuran = 8;
    waktu = 5;

    persiapanMatrix();
    DisplayBoard();

    while (mulai) {
        PlayTheGame(menangSuit, bonus);
    }

    system("cls");
    DisplayBoard();
    printf("\nGAME OVER\n");
    HighScores();
}

void PlayerVsComputer() {
    int menangSuit;

    InpuNama();
    menangSuit = suit();
    switch (level) {
    case 1: Easy(menangSuit); break;
    case 2: Medium(menangSuit); break;
    case 3: Hard(menangSuit); break;
    }

}

char p_com_InputO() {}

void HighScores() {

    char c;
    int n=0, i=0, j=0;

    struct formatHS{
        char namaPemenang[20];
        int skor;
    }sortScore[100], tulis;

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
            printf("loading . . .\n");
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
}

void exitGame() {}
