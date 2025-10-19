
//gcc -std=c11 -Wall -Wextra -O2 bit_operations.c -o bit_operations
//./bit_operations


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// 1 Bật (set) một bit cụ thể
uint32_t set_bit(uint32_t n, uint8_t pos) {
    return n | (1U << pos);
}

// 2️ Tắt (clear) một bit cụ thể
uint32_t clear_bit(uint32_t n, uint8_t pos) {
    return n & ~(1U << pos);
}

// 3️ Đảo (toggle) một bit cụ thể
uint32_t toggle_bit(uint32_t n, uint8_t pos) {
    return n ^ (1U << pos);
}

// 4️ Kiểm tra một bit cụ thể đã được bật hay chưa
bool is_bit_set(uint32_t n, uint8_t pos) {
    return ((n >> pos) & 1U) != 0;
}

// 5️ Hoán đổi hai số mà không cần biến thứ ba (tránh khi cùng địa chỉ)
void swap_numbers(uint32_t *a, uint32_t *b) {
    if (a == b) return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

// 6️ Kiểm tra một số có phải là lũy thừa của 2 hay không
bool is_power_of_two(uint32_t n) {
    return n != 0 && ((n & (n - 1)) == 0);
}

// 7️ Đếm số bit 1 trong biểu diễn nhị phân (Brian Kernighan)
uint8_t count_set_bits(uint32_t n) {
    uint8_t cnt = 0;
    while (n) {
        n &= (n - 1);
        ++cnt;
    }
    return cnt;
}

// 8️ Kiểm tra số chẵn hay lẻ
bool is_even(uint32_t n) {
    return (n & 1U) == 0;
}

// 9️ Tìm bù 2 (two’s complement)
int32_t twos_complement(int32_t n) {
    return (~n) + 1;
}

// 10 Kiểm tra hai số có bằng nhau mà không dùng toán tử so sánh
bool is_equal(uint32_t a, uint32_t b) {
    return (a ^ b) == 0;
}

// 11 Tìm vị trí MSB (0-based), trả về -1 nếu n == 0
int find_MSB_position(uint32_t n) {
    if (n == 0) return -1;
    int pos = 0;
    while (n >>= 1) ++pos;
    return pos;
}

// 12  Tìm vị trí LSB (0-based), trả về -1 nếu n == 0
int find_LSB_position(uint32_t n) {
    if (n == 0) return -1;
    int pos = 0;
    while ((n & 1U) == 0) {
        n >>= 1;
        ++pos;
    }
    return pos;
}

// 13 Tắt bit 1 ở ngoài cùng bên phải
uint32_t turn_off_rightmost_set_bit(uint32_t n) {
    return n & (n - 1);
}

// --- Hàm main demo ---
int main(void) {
    uint32_t n = 0b10100100; // 0xA4 = 164
    printf("Giá trị ban đầu: 0x%X\n", n);

    printf("1. Set bit 1 -> 0x%X\n", set_bit(n, 1));
    printf("2. Clear bit 2 -> 0x%X\n", clear_bit(n, 2));
    printf("3. Toggle bit 5 -> 0x%X\n", toggle_bit(n, 5));
    printf("4. Bit 5 %s\n", is_bit_set(n, 5) ? "đã bật" : "chưa bật");

    uint32_t a = 10, b = 5;
    swap_numbers(&a, &b);
    printf("5. Sau khi swap: a=%u, b=%u\n", a, b);

    printf("6. 16 %s lũy thừa của 2\n", is_power_of_two(16) ? "là" : "không phải");
    printf("7. Số bit 1 trong 0x%X là %u\n", n, count_set_bits(n));
    printf("8. 13 là %s\n", is_even(13) ? "chẵn" : "lẻ");
    printf("9. Bù 2 của 5 là %d\n", twos_complement(5));
    printf("10. 7 và 7 %s nhau\n", is_equal(7, 7) ? "bằng" : "không bằng");

    printf("11. Vị trí MSB của 0x%X là %d\n", n, find_MSB_position(n));
    printf("12. Vị trí LSB của 0x%X là %d\n", n, find_LSB_position(n));
    printf("13. Tắt bit 1 ngoài cùng bên phải: 0x%X\n", turn_off_rightmost_set_bit(n));

    return 0;
}
