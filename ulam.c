/** Build it: gcc ulam.c -w -lm -o ulam */
#include <stdio.h>

int prime(int n) {
    if (n < 2) return 0;
    int f = 1;
    for (int i = 2; i <= n/2; i++) {
        if(n%i == 0) {
            f = 0;
            break;
        }
    }
    return f;
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
