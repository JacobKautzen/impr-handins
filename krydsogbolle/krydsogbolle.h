
typedef enum cell {empty, kryds, bolle} cell;

void kryds_og_bolle(void);

void scan_move(int *x, int *y);

void update_arena(cell arena[][3], int x, int y, int player);

void print_arena(cell arena[][3]);

int winner(cell arena[][3]);
