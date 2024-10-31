#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "barang.h"
#include "user.h"
#include "views.h"

void mainMenu(Barang items[], int itemsLength) {
  bool isAuthenticated = true;

  while (1) {
    system("clear");
    int choose;
    printf("===== SELAMAT DATANG DI MINIMARKET =====\n");
    printf("[1] Kelola Barang\n");
    printf("[2] Beli Barang\n");
    printf("[3] Keluar\n");
    printf("========================================\n");
    printf("Masukan Pilihan : ");
    scanf("%d", &choose);

    if (choose == 1) {
      int pilihan = manageItemsMenu();
      if (pilihan == 1) {
        addItem(items, itemsLength);
      }
    }

  }
}

int manageItemsMenu() {
  system("clear");
  int choose;
  printf("===== KELOLA BARANG =====\n");
  printf("[1] Tambah Barang\n");
  printf("[2] Edit Barang\n");
  printf("[3] Hapus Barang\n");
  printf("[4] Kembali ke Menu Utama\n");
  printf("=========================\n");
  printf("Masukan Pilihan : ");
  scanf("%d", &choose);
  return choose;
}

