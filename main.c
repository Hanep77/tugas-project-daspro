#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int id;
  int stock;
  int price;
  char name[50];
} Barang;

typedef struct {
  int id;
  char username[50];
  char password[50];
} User;

int addItem(Barang items[], int itemsLength);
void showItem(Barang items[], int itemsLength);
void mainMenu(Barang items[], int itemsLength, bool isAuthenticated);
int manageItemsMenu();
int login();

int main() {
  Barang* items;
  items = (Barang*)malloc(50 * sizeof(Barang));
  int itemsLength = sizeof(items) / sizeof(items[0]);
  bool isAuthenticated = true;

  mainMenu(items, itemsLength, isAuthenticated);

  return 0;
}

// views
void mainMenu(Barang items[], int itemsLength, bool isAuthenticated) {
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
      if (isAuthenticated) {
        int pilihan = manageItemsMenu();
        if (pilihan == 1) {
          addItem(items, itemsLength);
        } else if (pilihan == 4) {
          continue;
        }
      } else {
        login();
      }
    } else {
      break;
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

int login() {
  system("clear");
  char username[50];
  char password[50];

  printf("===== LOGIN =====\n");
  printf("Username : ");
  fgets(username, sizeof(username), stdin);
  printf("Password : ");
  fgets(password, sizeof(password), stdin);
}

// fungsi-fungsi barang
void showItem(Barang items[], int itemsLength) {
  for (int i = 0; i < itemsLength; i++) {
    printf("id : %d", items[i].id);
    printf("nama : %s", items[i].name);
    printf("stok: %d", items[i].stock);
    printf("harga : %d", items[i].price);
  }
}

int addItem(Barang items[], int itemsLength) {
  Barang newItem;
  if (itemsLength == 0) {
    newItem.id = 1;
  } else {
    newItem.id = items[itemsLength - 1].id;
  }

  printf("masukan nama : ");
  fgets(newItem.name, sizeof(newItem.name), stdin);
  printf("masukan jumlah stok : ");
  scanf("%d", &newItem.stock);
  printf("masukan harga barang : ");
  scanf("%d", &newItem.price);

  return itemsLength + 1;
}
