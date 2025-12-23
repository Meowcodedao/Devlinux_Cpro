#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bai1_khaiBaoConTro() {
    int x = 100;
    int *p = &x;
    printf("Dia chi:  %p, Gia tri: %d\n\n", (void*)p, *p);
}

void bai2_hoanDoi(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bai3_tongMang(int *arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += *(arr + i);
    return sum;
}

void bai4_nhapMang(int *arr, int n) {
    for(int i = 0; i < n; i++)
        scanf("%d", arr + i);
}

void bai4_inMang(int *arr, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n\n");
}

void bai5_kichThuoc() {
    void *p;
    int x;
    float f;
    double d;
    char c;
    p = &x;
    printf("int: %lu bytes\n", sizeof(*((int*)p)));
    p = &f;
    printf("float: %lu bytes\n", sizeof(*((float*)p)));
    p = &d;
    printf("double: %lu bytes\n", sizeof(*((double*)p)));
    p = &c;
    printf("char: %lu bytes\n\n", sizeof(*((char*)p)));
}

void bai6_conTroMang() {
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;
    for(int i = 0; i < 5; i++)
        printf("%d ", *(p + i));
    printf("\n\n");
}

int bai7_demKyTu(char *str) {
    int count = 0;
    while(*(str + count) != '\0')
        count++;
    return count;
}

void bai8_thayDoiGiaTri(int *x) {
    *x = 999;
}

void bai9_soSanhDiaChi() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p1 = &arr[1];
    int *p2 = &arr[3];
    printf("p1 < p2: %s\n\n", (p1 < p2) ? "Dung" : "Sai");
}

void bai10_saoChuoi(char *dest, char *src) {
    while(*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void bai11_malloc() {
    int *arr = (int*)malloc(10 * sizeof(int));
    printf("Nhap 10 so: ");
    for(int i = 0; i < 10; i++)
        scanf("%d", arr + i);
    for(int i = 0; i < 10; i++)
        printf("%d ", *(arr + i));
    printf("\n\n");
    free(arr);
}

int* bai12_timMax(int *arr, int n) {
    int *max = arr;
    for(int i = 1; i < n; i++)
        if(*(arr + i) > *max)
            max = arr + i;
    return max;
}

void bai13_daoNguocChuoi(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    while(start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void bai14_nhapMaTran(int **mat, int n, int m) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", *(mat + i) + j);
}

void bai15_congMaTran(int **a, int **b, int **c, int n, int m) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            *(*(c + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
}

int cong(int a, int b) { return a + b; }
int tru(int a, int b) { return a - b; }
int nhan(int a, int b) { return a * b; }
int chia(int a, int b) { return b != 0 ? a / b : 0; }

void bai16_conTroHam() {
    int (*phepTinh[4])(int, int) = {cong, tru, nhan, chia};
    printf("10 + 5 = %d\n", phepTinh[0](10, 5));
    printf("10 - 5 = %d\n", phepTinh[1](10, 5));
    printf("10 * 5 = %d\n", phepTinh[2](10, 5));
    printf("10 / 5 = %d\n\n", phepTinh[3](10, 5));
}

void bai17_mayTinh() {
    int (*ops[4])(int, int) = {cong, tru, nhan, chia};
    char *ten[] = {"+", "-", "*", "/"};
    int a, b, chon;
    printf("Nhap a b: ");
    scanf("%d %d", &a, &b);
    printf("0:+, 1:-, 2:*, 3:/  ");
    scanf("%d", &chon);
    if(chon >= 0 && chon <= 3)
        printf("%d %s %d = %d\n\n", a, ten[chon], b, ops[chon](a, b));
}

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void bai18_linkedList() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = NULL;
    Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    free(head->next);
    free(head);
}

void bai19_maTranDong() {
    int n, m;
    printf("Nhap n m: ");
    scanf("%d %d", &n, &m);
    int **mat = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++)
        mat[i] = (int*)malloc(m * sizeof(int));
    printf("Nhap ma tran:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

void bai20_voidSwap() {
    int x = 10, y = 20;
    printf("Truoc: x=%d, y=%d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("Sau: x=%d, y=%d\n\n", x, y);
}

int main() {
    printf("bai1\n");
    bai1_khaiBaoConTro();
    
    printf("bai2\n");
    int num1 = 5, num2 = 10;
    printf("Truoc: a=%d, b=%d\n", num1, num2);
    bai2_hoanDoi(&num1, &num2);
    printf("Sau: a=%d, b=%d\n\n", num1, num2);
    
    printf("bai3\n");
    int arr1[5] = {1, 2, 3, 4, 5};
    printf("Tong: %d\n\n", bai3_tongMang(arr1, 5));
    
    printf("bai4\n");
    int arr2[5];
    printf("Nhap 5 so: ");
    bai4_nhapMang(arr2, 5);
    bai4_inMang(arr2, 5);
    
    printf("bai5\n");
    bai5_kichThuoc();
    
    printf("bai6\n");
    bai6_conTroMang();
    
    printf("bai7\n");
    char str1[] = "Hello";
    printf("So ky tu: %d\n\n", bai7_demKyTu(str1));
    
    printf("bai8\n");
    int x = 100;
    printf("Truoc: %d\n", x);
    bai8_thayDoiGiaTri(&x);
    printf("Sau: %d\n\n", x);
    
    printf("bai9\n");
    bai9_soSanhDiaChi();
    
    printf("bai10\n");
    char dest[20];
    bai10_saoChuoi(dest, str1);
    printf("Sao chep: %s\n\n", dest);
    
    printf("bai11\n");
    bai11_malloc();
    
    printf("bai12\n");
    int *maxPtr = bai12_timMax(arr1, 5);
    printf("Max: %d\n\n", *maxPtr);
    
    printf("bai13\n");
    char str2[] = "Hello";
    bai13_daoNguocChuoi(str2);
    printf("Dao nguoc: %s\n\n", str2);
    
    printf("bai14\n");
    int **mat = (int**)malloc(2 * sizeof(int*));
    for(int i = 0; i < 2; i++)
        mat[i] = (int*)malloc(2 * sizeof(int));
    printf("Nhap ma tran 2x2:\n");
    bai14_nhapMaTran(mat, 2, 2);
    for(int i = 0; i < 2; i++)
        free(mat[i]);
    free(mat);
    printf("\n");
    
    printf("bai15\n");
    int **matA = (int**)malloc(2 * sizeof(int*));
    int **matB = (int**)malloc(2 * sizeof(int*));
    int **matC = (int**)malloc(2 * sizeof(int*));
    for(int i = 0; i < 2; i++) {
        matA[i] = (int*)malloc(2 * sizeof(int));
        matB[i] = (int*)malloc(2 * sizeof(int));
        matC[i] = (int*)malloc(2 * sizeof(int));
    }
    printf("Nhap ma tran A 2x2:\n");
    bai14_nhapMaTran(matA, 2, 2);
    printf("Nhap ma tran B 2x2:\n");
    bai14_nhapMaTran(matB, 2, 2);
    bai15_congMaTran(matA, matB, matC, 2, 2);
    printf("Tong:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++)
            printf("%d ", matC[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < 2; i++) {
        free(matA[i]);
        free(matB[i]);
        free(matC[i]);
    }
    free(matA);
    free(matB);
    free(matC);
    
    printf("bai16\n");
    bai16_conTroHam();
    
    printf("bai17\n");
    bai17_mayTinh();
    
    printf("bai18\n");
    bai18_linkedList();
    
    printf("BAI19\n");
    bai19_maTranDong();
    
    printf("bai20\n");
    bai20_voidSwap();
    
    return 0;
}
