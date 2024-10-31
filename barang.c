#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "barang.h"

void showItem(Barang items[], int itemsLength) {
  for (int i = 0; i < itemsLength; i++) {
    printf("id : %d", items[i].id);
    printf("nama : %s", items[i].name);
    printf("stok: %d", items[i].stock);
    printf("harga : %d", items[i].price);
  }
}

int addItem(Barang items[], int itemsLength) {
  system("clear");
  Barang newItem;
  if (itemsLength == 0) {
    newItem.id = 1;
  } else {
    newItem.id = items[itemsLength - 1].id;
  }

  printf("===== TAMBAH BARANG =====\n");

  printf("masukan nama : ");
  getchar();
  fgets(newItem.name, sizeof(newItem.name), stdin);

  printf("masukan jumlah stok : ");
  scanf("%d", &newItem.stock);

  printf("masukan harga barang : ");
  scanf("%d", &newItem.price);

  return itemsLength + 1;
}
