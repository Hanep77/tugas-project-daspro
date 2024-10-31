#include <stdio.h>
#include <stdlib.h>

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
