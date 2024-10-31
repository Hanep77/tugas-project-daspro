typedef struct {
  int id;
  int stock;
  int price;
  char name[50];
} Barang;

int addItem(Barang items[], int itemsLength);
void showItem(Barang items[], int itemsLength);
