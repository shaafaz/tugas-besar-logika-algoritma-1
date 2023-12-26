#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct akun
{
    char username[20];
    char password[20];
};
 struct jadwal_kereta {
    char kelas[20];
    char kereta[20];
    char stasiun_berangkat[20];
    char tujuan[20];
    char tanggal_berangkat[20];
    char jam_berangkat[10];
    char jam_datang[10];
    int harga;
    };
struct tiket {
    char username[20];
    char kereta[20];
    char kelas[20];
    char stasiun_berangkat[20];
    char tujuan[20];
    char tanggal_berangkat[20];
    char jam_berangkat[10];
    char jam_datang[10];
    int nomor_kursi;
};


struct kursi {
    int nomor_kursi;
    int terpesan;
};

void simpanAkunKeFile(struct akun daftar_akun[], int total_akun) {
    FILE *file = fopen("akun.txt", "w");
    if (file == NULL) {
        printf("");
        return;
    }

    for (int i = 0; i < total_akun; i++) {
        fprintf(file, "username \t \t password\n %s \t \t \t %s\n", daftar_akun[i].username, daftar_akun[i].password);
    }

    fclose(file);
}

void muatAkunDariFile(struct akun daftar_akun[], int *total_akun) {
    FILE *file = fopen("akun.txt", "r");
    if (file == NULL) {
        printf("");
        return;
    }

    while (fscanf(file, "%s %s", daftar_akun[*total_akun].username, daftar_akun[*total_akun].password) != EOF) {
        (*total_akun)++;
    }

    fclose(file);
}
void simpanTiketKeFile(struct tiket daftar_tiket[], int total_tiket) {
    FILE *file = fopen("tiket.txt", "w");
    if (file == NULL) {
        printf("");
        return;
    }

    for (int i = 0; i < total_tiket; i++) {
        fprintf(file, "username: %s\n", daftar_tiket[i].username);
        fprintf(file, "kereta: %s\n", daftar_tiket[i].kereta);
        fprintf(file, "kelas: %s\n", daftar_tiket[i].kelas);
        fprintf(file, "stasiun_berangkat: %s\n", daftar_tiket[i].stasiun_berangkat);
        fprintf(file, "tujuan: %s\n", daftar_tiket[i].tujuan);
        fprintf(file, "tanggal_berangkat: %s\n", daftar_tiket[i].tanggal_berangkat);
        fprintf(file, "jam_berangkat: %s\n", daftar_tiket[i].jam_berangkat);
        fprintf(file, "jam_datang: %s\n", daftar_tiket[i].jam_datang);
        fprintf(file, "nomor_kursi: %d\n", daftar_tiket[i].nomor_kursi);
        fprintf(file, "=============================\n");
    }

    fclose(file);
}

int main()
{
    int pilihan1;
    struct akun daftar_akun[50];
    int total_akun = 0;
    muatAkunDariFile(daftar_akun, &total_akun);
    int sukses_login = 0;
    char loginUser[50];
    struct jadwal_kereta jadwal[20];
    int scheduleCount = 0;

    strcpy(jadwal[0].kereta, "Tawang Jaya");
    strcpy(jadwal[0].kelas, "Ekesekutif");
    strcpy(jadwal[0].stasiun_berangkat, "Poncol");
    strcpy(jadwal[0].tujuan, "tegal");
    strcpy(jadwal[0].tanggal_berangkat, "20-12-2023");
    strcpy(jadwal[0].jam_berangkat, "08:00");
    strcpy(jadwal[0].jam_datang, "10:30");
    jadwal[0].harga = 25000;
    scheduleCount++;

    int jumlah_kursi_yang_tersedia = 50;
    int total_kursi = 50;
    struct kursi daftar_kursi[50];
    // Inisialisasi daftar kursi
    for (int i = 0; i < total_kursi; i++) {
        daftar_kursi[i].nomor_kursi = i + 1;
        daftar_kursi[i].terpesan = 0; // Semua kursi awalnya belum dipesan
    }
    struct tiket daftar_tiket[50];
    int total_tiket = 0;


    while(1)
    {
        printf("\n");
        printf("\t\t\t\t   SELAMAT DATANG DI PEMESENAN TIKET KAI \n\n");
        printf("\t\t\t\t|=========================================|\n");
        printf("\t\t\t\t| \t\t 1. Daftar                |\n");
        printf("\t\t\t\t|=========================================|\n");
        printf("\t\t\t\t| \t\t 2. Login                 |\n");
        printf("\t\t\t\t|=========================================|\n");
        printf("\t\t\t\t| \t\t 3. Exit                  |\n");
        printf("\t\t\t\t|=========================================|");
        printf("\n\t\t\t\tPilihan Anda: ");
        scanf("%d", &pilihan1);

        if (pilihan1 == 1 ){
            if (total_akun < 50 ){
                printf("\t\t\t\tMasukan username : ");
                scanf("%s", daftar_akun[total_akun].username);
                printf("\t\t\t\tMasukan password : ");
                scanf("%s", daftar_akun[total_akun].password);
                total_akun++;
                printf("\t\t\t\tPendaftaran Berhasil, silahkan login ");
                simpanAkunKeFile(daftar_akun, total_akun);
                sleep(1);
                system("cls");
            } else {
                printf("\t\t\t\tBatas akun telah tercapai");
            }
        } else if (pilihan1 == 2){
            char username[20];
            char password[20];

            printf ("\t\t\t\tMasukan username : ");
            scanf ("%s", username);
            printf ("\t\t\t\tMasukan password : ");
            scanf ("%s", password);

            for (int i = 0; i < total_akun; i++){
                if (strcmp(username, daftar_akun[i].username) == 0 && strcmp(password, daftar_akun[i].password) == 0 ){
                    printf("\t\t\t\tSelamat, login berhasil ");
                    sukses_login = 1;
                    strcpy(loginUser, username);
                    system("cls");
                }
            }
            if (!sukses_login) {
                    printf("\t\t\t\tUsername atau Password yang anda masukan salah, silahkan masukan yang benar ");
            }
            system("cls");
        } else if (pilihan1 == 3){
            printf("Terima Kasih");
            break;
        } else {
            printf("\t\t\t\tPILIH SENG BENER BJIR");
        }

        if(sukses_login)
        {
            while(1)
            {
                printf("\n\t\t\t\t\t   Selamat Datang!\n");
                printf("\t\t\t\t|=========================================|");
                printf("\n\t\t\t\t\t\t1. Pesan Tiket\n");
                printf("\t\t\t\t|=========================================|");
                printf("\n\t\t\t\t\t\t2. Tiket Saya\n");
                printf("\t\t\t\t|=========================================|");
                printf("\n\t\t\t\t\t\t3. Logout\n");
                printf("\t\t\t\t|=========================================|");
                printf("\n\t\t\t\tPilihan Anda: ");
                scanf("%d", &pilihan1);
                system("cls");

                if (pilihan1 == 1){
                    int jenis_kereta;
                    printf("\n\t\t\t\tPilih jenis kereta:\n");
                    printf("\t\t\t\t================================\n");
                    printf("\t\t\t\t 1. Kereta Antar Kota\n");
                    printf("\t\t\t\t================================\n");
                    printf("\n\t\t\t\t Pilihan Anda: ");
                    scanf("%d", &jenis_kereta);
                    system("cls");

                    char stasiun_keberangkatan[20];
                    char stasiun_tujuan[20];
                    char tanggal[20];
                    int jadwal_tersedia = 0;

                    if (jenis_kereta == 1){
                        printf("\n\t\t\t\tAnda memilih 'Kereta Antar Kota'.\n");
                        printf("\n\t\t\t\tMasukkan stasiun keberangkatan : ");
                        scanf("%s", stasiun_keberangkatan);
                        printf("\n\t\t\t\tMasukkan stasiun Tujuan : ");
                        scanf("%s", stasiun_tujuan);
                        printf("\n\t\t\t\tMasukkan tanggal keberangkatan : ");
                        scanf("%s", tanggal);
                        system("cls");

                        printf("\n\t\t\t\tJadwal untuk rute %s - %s : \n", stasiun_keberangkatan, stasiun_tujuan);
                        for (int i = 0; i < scheduleCount; i++) {
                            if (strcmp(jadwal[i].stasiun_berangkat, stasiun_keberangkatan) == 0 &&
                                strcmp(jadwal[i].tujuan, stasiun_tujuan) == 0 && strcmp(jadwal[i].tanggal_berangkat, tanggal) == 0 ){
                                printf("\t\t\t\tJadwal %d:\n", i + 1);
                                printf("\t\t\t\tKereta          : %s\n", jadwal[i].kereta);
                                printf("\t\t\t\tKelas           : %s\n", jadwal[i].kelas);
                                printf("\t\t\t\tStasiun Keberangkatan: %s\n", jadwal[i].stasiun_berangkat);
                                printf("\t\t\t\tTujuan          : %s\n", jadwal[i].tujuan);
                                printf("\t\t\t\tTanggal         : %s\n", jadwal[i].tanggal_berangkat);
                                printf("\t\t\t\tJam Berangkat   : %s\n", jadwal[i].jam_berangkat);
                                printf("\t\t\t\tJam Sampai      : %s\n", jadwal[i].jam_datang);
                                printf("\t\t\t\tHarga           : Rp %d\n", jadwal[i].harga);
                                printf("\n\t\t\t\t=========================\n");
                                jadwal_tersedia = 1;
                            }
                        }
                        if (!jadwal_tersedia){
                            printf("\n\t\t\t\tMaaf jadwal tidak tersedia");
                            system("pause");
                        }else {
                            int jadwal_pilih;
                            printf("\n\t\t\t\tPilih jadwal : ");
                            scanf("\n\t\t\t\t%d", &jadwal_pilih);

                            int pilih_kursi;
                            printf("\n\t\t\t\tJumlah kursi yang tersedia: %d\n", jumlah_kursi_yang_tersedia);
                            printf("\n\t\t\t\tKursi yang tersedia:\n");
                            printf("\t\t\t\t======================\n");
                            for (int i = 0; i < total_kursi; i++) {
                                if (daftar_kursi[i].terpesan == 0) {
                                    printf("\t\t\t\tNomor Kursi: %d\n", daftar_kursi[i].nomor_kursi);
                                }
                            }
                            printf("\t\t\t\t======================\n");
                            printf("\n\t\t\t\tPilih kursi Anda (nomor kursi): ");
                            scanf("%d", &pilih_kursi);

                            if (pilih_kursi >= 1 && pilih_kursi <= total_kursi) {
                                while (daftar_kursi[pilih_kursi - 1].terpesan != 0) {
                                    printf("\t\t\t\tKursi nomor %d sudah terpesan. Silakan pilih kursi lain: ", pilih_kursi);
                                    scanf("%d", &pilih_kursi);
                                }
                            daftar_kursi[pilih_kursi - 1].terpesan = 1;
                            printf("\t\t\t\tKursi nomor %d berhasil dipesan untuk jadwal %d. \n", pilih_kursi, jadwal_pilih);
                            sleep(2);
                            system("cls");
                            }
                            printf("\n\t\t\t\tRincian Pemesanan:\n");
                            printf("\t\t\t\t=======================================\n");
                            printf("\n\t\t\t\tJadwal yang dipilih:\n");
                            printf("\n\t\t\t\tKereta                : %s\n", jadwal[jadwal_pilih - 1].kereta);
                            printf("\n\t\t\t\tKelas                 : %s\n", jadwal[jadwal_pilih - 1].kelas);
                            printf("\n\t\t\t\tStasiun Keberangkatan : %s\n", jadwal[jadwal_pilih - 1].stasiun_berangkat);
                            printf("\n\t\t\t\tStasiun Tujuan        : %s\n", jadwal[jadwal_pilih - 1].tujuan);
                            printf("\n\t\t\t\tTanggal               : %s\n", jadwal[jadwal_pilih - 1].tanggal_berangkat);
                            printf("\n\t\t\t\tJam Berangkat         : %s\n", jadwal[jadwal_pilih - 1].jam_berangkat);
                            printf("\n\t\t\t\tJam Sampai            : %s\n", jadwal[jadwal_pilih - 1].jam_datang);
                            printf("\n\t\t\t\tHarga: Rp %d\n", jadwal[jadwal_pilih - 1].harga);
                            printf("\n\t\t\t\tKursi yang dipilih    : %d\n", pilih_kursi);
                            printf("\t\t\t\t=======================================\n");

                            int pembayaran;
                            printf("\n\t\t\t\tSilakan lakukan pembayaran sebesar Rp %d untuk menyelesaikan pemesanan.\n", jadwal[jadwal_pilih - 1].harga);
                            printf("\t\t\t\tMasukkan jumlah uang yang Anda bayarkan: Rp ");
                            scanf("%d", &pembayaran);
                            if (pembayaran >= jadwal[jadwal_pilih - 1].harga) {
                            int kembalian = pembayaran - jadwal[jadwal_pilih - 1].harga;
                            printf("\t\t\t\tPembayaran berhasil! Silahkan cek tiket anda di menu Tiket Saya.\n");
                            if (kembalian > 0) {
                                printf("\t\t\t\tKembalian Anda: Rp %d\n", kembalian);
                            }
                            sleep(2);
                            system("cls");
                            // Buat tiket
                            strcpy(daftar_tiket[total_tiket].username, loginUser);
                            strcpy(daftar_tiket[total_tiket].kereta, jadwal[jadwal_pilih - 1].kereta);
                            strcpy(daftar_tiket[total_tiket].kelas, jadwal[jadwal_pilih - 1].kelas);
                            strcpy(daftar_tiket[total_tiket].stasiun_berangkat, jadwal[jadwal_pilih - 1].stasiun_berangkat);
                            strcpy(daftar_tiket[total_tiket].tujuan, jadwal[jadwal_pilih - 1].tujuan);
                            strcpy(daftar_tiket[total_tiket].tanggal_berangkat, jadwal[jadwal_pilih - 1].tanggal_berangkat);
                            strcpy(daftar_tiket[total_tiket].jam_berangkat, jadwal[jadwal_pilih - 1].jam_berangkat);
                            strcpy(daftar_tiket[total_tiket].jam_datang, jadwal[jadwal_pilih - 1].jam_datang);
                            daftar_tiket[total_tiket].nomor_kursi = pilih_kursi;
                            total_tiket++;
                            simpanTiketKeFile(daftar_tiket, total_tiket);

                            } else {
                                printf("\t\t\t\tMaaf, jumlah uang yang Anda masukkan kurang. Silakan masukkan jumlah yang cukup.\n");
                                printf("\t\t\t\tMasukkan jumlah uang yang Anda bayarkan: Rp ");
                                scanf("%d", &pembayaran);
                            }
                        }
                    }
                } else if (pilihan1 == 2) {
                    printf("\n\t\t\t\tTiket Saya:\n");
                    int tiket_ditemukan = 0;
                    for (int i = 0; i < total_tiket; i++) {
                        if (strcmp(daftar_tiket[i].username, loginUser) == 0){
                        // Tampilkan informasi tiket
                        printf("\t\t\t\t=======================================\n");
                        printf("\t\t\t\tTiket %d:\n", i + 1);
                        printf("\t\t\t\tKereta                : %s\n", daftar_tiket[i].kereta);
                        printf("\t\t\t\tKelas                 : %s\n", daftar_tiket[i].kelas);
                        printf("\t\t\t\tStasiun Keberangkatan : %s\n", daftar_tiket[i].stasiun_berangkat);
                        printf("\t\t\t\tStasiun Tujuan        : %s\n", daftar_tiket[i].tujuan);
                        printf("\t\t\t\tTanggal               : %s\n", daftar_tiket[i].tanggal_berangkat);
                        printf("\t\t\t\tJam Berangkat         : %s\n", daftar_tiket[i].jam_berangkat);
                        printf("\t\t\t\tJam Sampai            : %s\n", daftar_tiket[i].jam_datang);
                        printf("\t\t\t\tNomor Kursi           : %d\n", daftar_tiket[i].nomor_kursi);
                        printf("\t\t\t\t=======================================\n");
                        tiket_ditemukan = 1;
                        }
                    }
                    if (!tiket_ditemukan) {
                        printf("\t\t\t\tAnda belum memesan tiket.\n");
                    }
                    system(" pause ");
                    system("cls");
                } else if (pilihan1 == 3) {
                    printf("Anda telah logout.\n");
                    sukses_login = 0;
                    break;
                } else {
                    printf("\t\t\t\tPILIH SENG BENER BJIR");
                }
            }
        }
    }
    return 0;
}
