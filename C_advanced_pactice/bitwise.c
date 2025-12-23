#include <stdio.h>
#include <math.h>

int main() {
    int x = 45;
    int n = 3;
    int a = 10, b = 20;
    int num = 64;
    
    printf("=== BIT MANIPULATION OPERATIONS ===\n\n");
    
    printf("x = %d (binary: ", x);
    for(int i = 7; i >= 0; i--) printf("%d", (x >> i) & 1);
    printf(")\n");
    printf("n = %d\n\n", n);
    
    printf("1.  Bat bit thu %d cua x:\n", n);
    printf("   Ket qua: %d\n", x | (1 << n));
    
    printf("\n2. Tat bit thu %d cua x:\n", n);
    printf("   Ket qua: %d\n", x & ~(1 << n));
    
    printf("\n3. Dao bit thu %d cua x:\n", n);
    printf("   Ket qua: %d\n", x ^ (1 << n));
    
    printf("\n4. Kiem tra bit thu %d co bat khong:\n", n);
    printf("   Ket qua: %s\n", (x & (1 << n)) ? "Co" : "Khong");
    
    printf("\n5. Hoan doi a=%d va b=%d khong dung bien tam:\n", a, b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("   Sau hoan doi: a=%d, b=%d\n", a, b);
    
    printf("\n6. Kiem tra %d co phai luy thua cua 2 khong:\n", num);
    printf("   Ket qua: %s\n", (num && !(num & (num - 1))) ? "Co" : "Khong");
    
    printf("\n7. Kiem tra %d la chan hay le:\n", num);
    printf("   Ket qua: %s\n", (num & 1) ? "Le" : "Chan");
    
    printf("\n8. Lay bu 2 (two's complement) cua %d:\n", num);
    printf("   Ket qua:  %d\n", ~num + 1);
    
    a = 10; b = 10;
    printf("\n9. Kiem tra a=%d va b=%d co bang nhau khong (khong dung ==):\n", a, b);
    printf("   Ket qua: %s\n", !(a ^ b) ? "Bang nhau" : "Khong bang");
    
    printf("\n10. Tim vi tri MSB cua %d:\n", x);
    printf("    Ket qua: %d\n", (int)log2(x));
    
    printf("\n11. Tim vi tri LSB cua %d:\n", x);
    printf("    Ket qua:  %d\n", (int)log2(x & -x));
    
    printf("\n12. Tat bit 1 o ngoai cung ben phai cua %d:\n", x);
    printf("    Ket qua: %d\n", x & (x - 1));
    
    printf("\n13. Co lap bit 1 o ngoai cung ben phai cua %d:\n", x);
    printf("    Ket qua: %d\n", x & -x);
    
    printf("\n14. Kiem tra %d co phai boi cua 8 khong:\n", num);
    printf("    Ket qua:  %s\n", !(num & 7) ? "Co" : "Khong");
    
    return 0;
}
