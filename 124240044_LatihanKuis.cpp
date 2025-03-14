#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int input, pilihan, pilihan2;
struct pnddk
{
    string nama;
    string alamat;
    string jenis_kelamin;
    int nik;
};

pnddk dtwrga [100];
int jmlhdta = 0;
char y;

void simpanKeFile() {
    FILE *file = fopen("penduduk.dat", "wb");
    fwrite(dtwrga, sizeof(pnddk), jmlhdta, file);
    fclose(file);
}

void bacaDariFile() {
    FILE *file = fopen("penduduk.dat", "rb");
    if (!file) return;
    jmlhdta = fread(dtwrga, sizeof(pnddk), 100, file);
    fclose(file);
}

void menu () {
    cout << "MENU PILIHAN" << endl;
    cout << "1. Input Data" << endl;
    cout << "2. Tampilkan Data" << endl;
    cout << "3. Searching" << endl;
    cout << "4. Edit Data" << endl;
    cout << "5. Hapus Data" << endl;
    cout << "6. Exit" << endl;
    cout << setfill('=') << setw(20) << " " << endl;
}

void inputData() {
    cout << "INPUT DATA " << endl;
        cout << setfill ('-') << setw (100) << " " << endl;

        cout << "Ingin input berapa data?";
        cin >> input;
        while (!(cin >> input) || input <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid! Masukkan angka positif: ";
        }

            for (int i = 0; i < input; i++) {
            cout << "Data ke-" << i+1 << endl;
            cout << "NIK: ";
            cin >> dtwrga[i].nik;
            cin.ignore();
            cout << "Nama: ";
            cin.ignore();
            getline(cin, dtwrga[i].nama); 
            cout << "Alamat: ";
            getline(cin, dtwrga[i].alamat);
            cout << "Jenis Kelamin: ";
            cin >> dtwrga[i].jenis_kelamin;

            cout << "Data berhasil ditambahkan.\n";
            cout << endl;
            } 

            jmlhdta += input;
    
    cout << "Apakah Anda Ingin Melanjutkan Program (y/n) "; cin >> y;
        if (y == 'n')
        {
                cout << "Terimakasih telah menggunakan program ini";
                        exit(0); 
        }
}

void quickSort(int low, int high) {
    if (low < high) {
        int pivot = dtwrga[high].nik;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (dtwrga[j].nik < pivot) {
                i++;
                swap(dtwrga[i], dtwrga[j]);
            }
        }
        swap(dtwrga[i + 1], dtwrga[high]);
        int pi = i + 1;
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void tampilkan () {
    quickSort(0, jmlhdta - 1);
    cout << "DATA PENDUDUK " << endl;
        cout << setfill ('-') << setw (100) << " " << endl;
        cout << setfill (' ') << "| " << left << "No " << " | "  
             << setw (15) << "NIK" << " | " 
             << setw (30) << "Nama" << " | " 
             << setw (20) << "Alamat" <<  " | " 
             << setw (19) << "Jenis Kelamin" << endl;
        cout << setfill ('-') << setw (100) << " " << endl;

        for (int i = 0; i < jmlhdta; i++) {
                    cout << "| " << setfill(' ') << setw(3) << left << (i + 1) << " | "
                         << setw(15) << left << dtwrga[i].nik << " | "
                         << setw(30) << dtwrga[i].nama << " | " 
                         << setw(20) << dtwrga[i].alamat << " | " 
                         << setw(19) << left << dtwrga[i].jenis_kelamin << endl;
                }

    if (jmlhdta == 0) {
        cout << "Tidak ada data yang tersimpan.\n";
        return;
    }

    cout << "Apakah Anda Ingin Melanjutkan Program (y/n) "; cin >> y;
    if (y == 'n')
    {
        cout << "terimakasih telah menggunakan program ini";
            exit(0); 
    }
}

void searching () {
    int cari;
    bool found;
    char ulangi;
    cout << "SEARCHING DATA " << endl;
    cout << "Masukkan NIK yang ingin dicari = ";
    cin >> cari;

    found = false;
            for (int i = 0; i < jmlhdta; i++) {
                if (dtwrga[i].nik == cari) {
                    cout << "Data ditemukan!\n";
                    cout << "Nama             : " << dtwrga[i].nama << endl;
                    cout << "NIK              : " << dtwrga[i].nik << endl;
                    cout << "Alamat           : " << dtwrga[i].alamat << endl;
                    cout << "Jenis Kelamin    : " << dtwrga[i].jenis_kelamin << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Data tidak ditemukan.\n";
            }

            cout << "Apakah Anda Ingin Melanjutkan Program (y/n) "; cin >> y;
            if (y == 'n')
            {
                cout << "terimakasih telah menggunakan program ini";
                    exit(0); 
            }
    
}

void editData() {
    int nik_edit;
    cout << "Masukkan NIK yang ingin diedit: ";
    cin >> nik_edit;
    for (int i = 0; i < jmlhdta; i++) {
        if (dtwrga[i].nik == nik_edit) {
            cout << "Masukkan alamat baru: ";
            cin.ignore();
            getline(cin, dtwrga[i].alamat);
            simpanKeFile();
            cout << "Data berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Data tidak ditemukan!\n";

    cout << "Apakah Anda Ingin Melanjutkan Program (y/n) "; cin >> y;
            if (y == 'n')
            {
                cout << "terimakasih telah menggunakan program ini";
                    exit(0); 
            }
}

void hapusData() {
    int nik_hapus;
    cout << "Masukkan NIK yang ingin dihapus: ";
    cin >> nik_hapus;
    for (int i = 0; i < jmlhdta; i++) {
        if (dtwrga[i].nik == nik_hapus) {
            for (int j = i; j < jmlhdta - 1; j++) {
                dtwrga[j] = dtwrga[j + 1];
            }
            jmlhdta--;
            simpanKeFile();
            cout << "Data berhasil dihapus!\n";
            return;
        }
    }
    cout << "Data tidak ditemukan!\n";

    cout << "Apakah Anda Ingin Melanjutkan Program (y/n) "; cin >> y;
            if (y == 'n')
            {
                cout << "terimakasih telah menggunakan program ini";
                    exit(0); 
            }
}

void keluardt () {
    cout << "Terima kasih telah menggunakan program ini.";
    exit (0);
}

int main () { 

    do
    {
     menu();
     cout << " Masukkan pilihan : "; cin >> pilihan;
     switch (pilihan)
     {
     case 1 : inputData();
             break;
     case 2 : tampilkan();
             break;
     case 3 : searching();
             break;
     case 4 : editData();
             break;
     case 5 : hapusData();
             break;
     case 6 : keluardt();
             break;
     default: cout << "pilihan tidak valid" << endl;
             break;
     }

    } while (pilihan != 6);
    return 0;
    
}

