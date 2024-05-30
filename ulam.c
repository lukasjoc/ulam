/** Build it: gcc ulam.c -w -lm -o ulam */
#include <stdio.h>

int prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

#define row_size 7
#define sp_size row_size * row_size
int sp[sp_size] = {0};
int pos = sp_size /2;
int val = 1;
int dist = 1;

void next_iteration() {
    // right
    if (pos+1 >= sp_size) {
        return NULL;
    }
    if (sp[pos+1] != 0) {
        dist++;
    }
    for (int i = 0; i < dist; i++) {
        val++;
        pos++;
        sp[pos] = val;
    }
    // up
    if (sp[pos-row_size] != 0) {
        dist++;
    }
    if (pos+1>=sp_size) {
        return NULL;
    }
    if (sp[pos-row_size] != 0) {
        val++;
        pos++;
        sp[pos] = val;
    }
    for (int i = 0; i < dist; i++) {
        val++;
        pos -= row_size;
        sp[pos] = val;
    }
    // left
    if (sp[pos-1] != 0) {
        dist++;
    }
    if (pos-1 >= sp_size) {
        return NULL;
    }
    for (int i = 0; i < dist; i++) {
        val++;
        pos--;
        sp[pos] = val;
    }
    // down
    if (sp[pos + row_size] != 0) {
        dist++;
    }
    if (pos+row_size >= sp_size) {
        return NULL;
    }
    if (sp[pos+row_size] != 0) {
        val++;
        pos--;
        sp[pos] = val;
    }
    for (int i = 0; i < dist; i++) {
        val++;
        pos += row_size;
        sp[pos] = val;
    }
}

void create_spiral() {
    sp[sp_size /2] = val;
    while (1) {
        if (val >= sp_size) break;
        next_iteration();
    }
}

void print_spiral_box() {
    for (int i = 0; i < sp_size; i++) {
        if ((i % row_size) == 0) printf("\n");
        printf("%-2s", prime(sp[i]) ? "." : " ");
    }
    printf("\n");
}

int main(void) {
    create_spiral();
    print_spiral_box();
    return 0;
}
