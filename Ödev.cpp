/* 
Geliştirici:Melik Mirza ÇELİK
Öğrenci No:B241200060
Ödev No:1
Ödev Konusu: Lojistik Planlama
*/

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <fstream>

using namespace std;

int lojistik[10][10];
int gecilen[10][10] = { false };

int musteriX1 = 4, musteriY1 = 0;
int musteriX2 = 5, musteriY2 = 3;
int musteriX3 = 4, musteriY3 = 8;
int musteriX4 = 6, musteriY4 = 7;
int musteriX5 = 8, musteriY5 = 5;

int* musteri1 = &lojistik[musteriX1][musteriY1];
int* musteri2 = &lojistik[musteriX2][musteriY2];
int* musteri3 = &lojistik[musteriX3][musteriY3];
int* musteri4 = &lojistik[musteriX4][musteriY4];
int* musteri5 = &lojistik[musteriX5][musteriY5];


int toplamYol = 0;

void kaydetToplamYol();
void lojistikSystem(int a, int b);
void kurye();

int main()
{
    setlocale(LC_ALL, "Turkish");

    cout << "Talep Adresleri:" << endl;
    cout << "Konum 1 : " << "(" << musteriX1 + 1 << "," << musteriY1 + 1 << ")" << " - " << "Adres : " << musteri1 << endl;
    cout << "Konum 2 : " << "(" << musteriX2 + 1 << "," << musteriY2 + 1 << ")" << " - " << "Adres : " << musteri2 << endl;
    cout << "Konum 3 : " << "(" << musteriX3 + 1 << "," << musteriY3 + 1 << ")" << " - " << "Adres : " << musteri3 << endl;
    cout << "Konum 4 : " << "(" << musteriX4 + 1 << "," << musteriY4 + 1 << ")" << " - " << "Adres : " << musteri4 << endl;
    cout << "Konum 5 : " << "(" << musteriX5 + 1 << "," << musteriY5 + 1 << ")" << " - " << "Adres : " << musteri5 << endl;
    cout << endl;

    cout << "Başlangıç Matris Durum:" << endl;
    lojistikSystem(0, 0);
    Sleep(2000);

    lojistikSystem(1, 0);
    Sleep(750);
    lojistikSystem(2, 0);
    Sleep(750);
    lojistikSystem(3, 0);
    Sleep(750);
    lojistikSystem(4, 0);
    Sleep(750);
    lojistikSystem(4, 1);
    Sleep(750);
    lojistikSystem(4, 2);
    Sleep(750);
    lojistikSystem(4, 3);
    Sleep(750);
    lojistikSystem(5, 3);
    Sleep(750);
    lojistikSystem(6, 3);
    Sleep(750);
    lojistikSystem(7, 3);
    Sleep(750);
    lojistikSystem(8, 3);
    Sleep(750);
    lojistikSystem(8, 4);
    Sleep(750);
    lojistikSystem(8, 5);
    Sleep(750);
    lojistikSystem(8, 6);
    Sleep(750);
    lojistikSystem(8, 7);
    Sleep(750);
    lojistikSystem(7, 7);
    Sleep(750);
    lojistikSystem(6, 7);
    Sleep(750);
    lojistikSystem(5, 7);
    Sleep(750);
    lojistikSystem(4, 7);
    Sleep(750);
    lojistikSystem(4, 8);
    Sleep(750);
    lojistikSystem(3, 8);
    Sleep(750);
    lojistikSystem(2, 8);
    Sleep(750);
    lojistikSystem(1, 8);
    Sleep(750);
    lojistikSystem(0, 8);
    Sleep(750);
    lojistikSystem(0, 7);
    Sleep(750);
    lojistikSystem(0, 6);
    Sleep(750);
    lojistikSystem(0, 5);
    Sleep(750);
    lojistikSystem(0, 4);
    Sleep(750);
    lojistikSystem(0, 3);
    Sleep(750);
    lojistikSystem(0, 2);
    Sleep(750);
    lojistikSystem(0, 1);
    Sleep(750);
    lojistikSystem(0, 0);
   

    cout << "\nGidiş-Geliş Toplam Yol: " << toplamYol << "\n" << endl;

    kaydetToplamYol();

    return 0;
}

void kurye() {
    cout << "\033[31m" << setw(4) << "K" << "\033[0m";
}

void lojistikSystem(int a, int b) {
    if (b != 0 || a != 0) {
        cout << "\n";
        cout << "Hareket Sonrası Matris " << endl;
    }
    else {
        cout << "\n" << "K (0,0) noktasında" << endl;
    }

    int i;
    int j;
    int elemanEkleyici = 1;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            lojistik[i][j] = elemanEkleyici++;
        }
    }

    gecilen[a][b] = true;
    toplamYol += lojistik[a][b];

    for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
            if (l == a && k == b) {
                kurye();
            }
            else if (gecilen[l][k] && !(l == musteriX1 && k == musteriY1) && !(l == musteriX2 && k == musteriY2) && !(l == musteriX3 && k == musteriY3) && !(l == musteriX4 && k == musteriY4) && !(l == musteriX5 && k == musteriY5)) {
                cout << "\033[32m" << setw(4) << lojistik[l][k] << "\033[0m";
            }
            else if (l == musteriX1 && k == musteriY1) {
                cout << "\033[34m" << setw(4) << lojistik[musteriX1][musteriY1] << "\033[0m";
            }
            else if (l == musteriX2 && k == musteriY2) {
                cout << "\033[34m" << setw(4) << lojistik[musteriX2][musteriY2] << "\033[0m";
            }
            else if (l == musteriX3 && k == musteriY3) {
                cout << "\033[34m" << setw(4) << lojistik[musteriX3][musteriY3] << "\033[0m";
            }
            else if (l == musteriX4 && k == musteriY4) {
                cout << "\033[34m" << setw(4) << lojistik[musteriX4][musteriY4] << "\033[0m";
            }
            else if (l == musteriX5 && k == musteriY5) {
                cout << "\033[34m" << setw(4) << lojistik[musteriX5][musteriY5] << "\033[0m";
            }
            else {
                cout << setw(4) << lojistik[l][k];
            }
        }
        cout << endl;
    }
    cout << "Güncel Toplam Yol: " << toplamYol << endl;
}

void kaydetToplamYol()
{
    ofstream dosya("Cost.txt", ios::trunc);

    if (dosya.is_open())
    {
        dosya << "Talep Adresleri:" << endl;
        dosya << "Konum 1 : " << "(" << musteriX1 + 1 << "," << musteriY1 + 1 << ")" << " - " << "Adres : " << musteri1 << endl;
        dosya << "Konum 2 : " << "(" << musteriX2 + 1 << "," << musteriY2 + 1 << ")" << " - " << "Adres : " << musteri2 << endl;
        dosya << "Konum 3 : " << "(" << musteriX3 + 1 << "," << musteriY3 + 1 << ")" << " - " << "Adres : " << musteri3 << endl;
        dosya << "Konum 4 : " << "(" << musteriX4 + 1 << "," << musteriY4 + 1 << ")" << " - " << "Adres : " << musteri4 << endl;
        dosya << "Konum 5 : " << "(" << musteriX5 + 1 << "," << musteriY5 + 1 << ")" << " - " << "Adres : " << musteri5 << endl;
        dosya << endl;
        dosya << "Gidiş-Dönüş Toplam Yol: " << toplamYol << endl;

        dosya.close();
    }
    else
    {
        cout << "Dosya açılamadı!" << endl;
    }
}