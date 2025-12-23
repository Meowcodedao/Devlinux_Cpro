#include <stdio.h>

void bai1_tinhTong(int arr[], int *n) {
    printf("Nhap 5 so:  ");
    *n = 5;
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Tong: %d\n\n", sum);
}

void bai2_timMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max) max = arr[i];
    printf("Max: %d\n\n", max);
}

void bai3_demChanLe(int arr[], int n) {
    int chan = 0, le = 0;
    for(int i = 0; i < n; i++)
        arr[i] % 2 == 0 ?  chan++ : le++;
    printf("Chan: %d, Le: %d\n\n", chan, le);
}

void bai4_daoNguoc(int arr[], int n) {
    for(int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
    printf("Dao nguoc:  ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");
}

void bai5_maxVaViTri(int arr[], int n) {
    int max = arr[0], pos = 0;
    for(int i = 1; i < n; i++)
        if(arr[i] > max) { max = arr[i]; pos = i; }
    printf("Max: %d, Vi tri: %d\n\n", max, pos);
}

void bai6_timX(int arr[], int n) {
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    for(int i = 0; i < n; i++)
        if(arr[i] == x) { printf("Co\n\n"); return; }
    printf("Khong\n\n");
}

void bai7_trungBinh(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    printf("TB: %. 2f\n\n", (float)sum/n);
}

void bai8_gopMang(int c[], int *nc) {
    int a[50], b[50], na, nb;
    printf("Nhap n(A): ");
    scanf("%d", &na);
    for(int i = 0; i < na; i++) scanf("%d", &a[i]);
    printf("Nhap n(B): ");
    scanf("%d", &nb);
    for(int i = 0; i < nb; i++) scanf("%d", &b[i]);
    for(int i = 0; i < na; i++) c[i] = a[i];
    for(int i = 0; i < nb; i++) c[na+i] = b[i];
    *nc = na + nb;
    printf("C: ");
    for(int i = 0; i < *nc; i++) printf("%d ", c[i]);
    printf("\n\n");
}

void bai9_sapXep(int arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    printf("Sap xep:  ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");
}

void bai10_xoa(int arr[], int *n) {
    int k;
    printf("Vi tri xoa:  ");
    scanf("%d", &k);
    for(int i = k; i < *n-1; i++) arr[i] = arr[i+1];
    (*n)--;
    for(int i = 0; i < *n; i++) printf("%d ", arr[i]);
    printf("\n\n");
}

void bai11_chen(int arr[], int *n) {
    int val, pos;
    printf("Gia tri:  ");
    scanf("%d", &val);
    printf("Vi tri: ");
    scanf("%d", &pos);
    for(int i = *n; i > pos; i--) arr[i] = arr[i-1];
    arr[pos] = val;
    (*n)++;
    for(int i = 0; i < *n; i++) printf("%d ", arr[i]);
    printf("\n\n");
}

void bai12_xuatHienNhieuNhat(int arr[], int n) {
    int maxCount = 0, mostFreq = arr[0];
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++)
            if(arr[j] == arr[i]) count++;
        if(count > maxCount) { maxCount = count; mostFreq = arr[i]; }
    }
    printf("Nhieu nhat: %d (%d lan)\n\n", mostFreq, maxCount);
}

void bai13_loaiTrung(int arr[], int n, int unique[], int *nu) {
    *nu = 0;
    for(int i = 0; i < n; i++) {
        int isDup = 0;
        for(int j = 0; j < *nu; j++)
            if(arr[i] == unique[j]) { isDup = 1; break; }
        if(!isDup) unique[(*nu)++] = arr[i];
    }
    for(int i = 0; i < *nu; i++) printf("%d ", unique[i]);
    printf("\n\n");
}

void bai14_daoNhom3(int arr[], int n) {
    for(int i = 0; i < n; i += 3) {
        int end = (i+2 < n) ? i+2 : n-1;
        int start = i;
        while(start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++; end--;
        }
    }
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");
}

void bai15_tongViTriChan(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i += 2) sum += arr[i];
    printf("Tong vi tri chan: %d\n\n", sum);
}

void bai16_cheoChinh(int mat[3][3]) {
    printf("Nhap ma tran 3x3:\n");
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &mat[i][j]);
    int sum = 0;
    for(int i = 0; i < 3; i++) sum += mat[i][i];
    printf("Cheo chinh: %d\n\n", sum);
}

void bai17_cheoPhu(int mat[3][3]) {
    int sum = 0;
    for(int i = 0; i < 3; i++) sum += mat[i][2-i];
    printf("Cheo phu:  %d\n\n", sum);
}

void bai18_doiXung(int mat[3][3]) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(mat[i][j] != mat[j][i]) { printf("Khong doi xung\n\n"); return; }
    printf("Doi xung\n\n");
}

void bai19_congMaTran(int mat1[3][3], int mat2[3][3], int res[3][3]) {
    printf("Nhap ma tran 2:\n");
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            scanf("%d", &mat2[i][j]);
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    printf("Tong:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) printf("%d ", res[i][j]);
        printf("\n");
    }
    printf("\n");
}

void bai20_nhanMaTran(int mat1[3][3], int mat2[3][3], int res[3][3]) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            res[i][j] = 0;
            for(int k = 0; k < 3; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    printf("Tich:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) printf("%d ", res[i][j]);
        printf("\n");
    }
}

int main() {
    int arr[100], n, c[100], nc, unique[100], nu;
    int mat[3][3], mat2[3][3], res[3][3];
    
    bai1_tinhTong(arr, &n);
    bai2_timMax(arr, n);
    bai3_demChanLe(arr, n);
    bai4_daoNguoc(arr, n);
    bai5_maxVaViTri(arr, n);
    bai6_timX(arr, n);
    bai7_trungBinh(arr, n);
    bai8_gopMang(c, &nc);
    bai9_sapXep(c, nc);
    bai10_xoa(c, &nc);
    bai11_chen(c, &nc);
    bai12_xuatHienNhieuNhat(c, nc);
    bai13_loaiTrung(c, nc, unique, &nu);
    bai14_daoNhom3(unique, nu);
    bai15_tongViTriChan(unique, nu);
    bai16_cheoChinh(mat);
    bai17_cheoPhu(mat);
    bai18_doiXung(mat);
    bai19_congMaTran(mat, mat2, res);
    bai20_nhanMaTran(mat, mat2, res);
    
    return 0;
}
