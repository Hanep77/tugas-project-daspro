#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "barang.h"
#include "user.h"
#include "views.h"

void seedItems(Barang* items);
void seedUsers(User* users);

int main() {
  // variable declaration
  Barang* items = (Barang*)malloc(50 * sizeof(Barang));
  User* users = (User*)malloc(50 * sizeof(User));

  // seed
  seedItems(items);
  seedUsers(users);

  // length of variables
  int itemsLength = sizeof(items) / sizeof(items[0]); // Sesuaikan panjang array sesuai jumlah data yang diisi oleh seedItems
  int usersLength = sizeof(users) / sizeof(users[0]); // Sesuaikan panjang array sesuai jumlah data yang diisi oleh seedUsers

  mainMenu(items, itemsLength);

  // Free memory
  free(items);
  free(users);

  return 0;
}

void seedItems(Barang* newItems) {
  newItems[0].id = 1;
  strcpy(newItems[0].name, "rinso");
  newItems[0].stock = 10;
  newItems[0].price = 5000;

  newItems[1].id = 2;
  strcpy(newItems[1].name, "sabun");
  newItems[1].stock = 10;
  newItems[1].price = 3000;

  newItems[2].id = 3;
  strcpy(newItems[2].name, "soklin");
  newItems[2].stock = 20;
  newItems[2].price = 15000;
}

void seedUsers(User* users) {
  users[0].id = 1;
  strcpy(users[0].username, "soklin");
  strcpy(users[0].password, "rahasia");
}
