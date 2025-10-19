# Bit Operations — Demo

File này chứa chương trình C minh họa các phép toán bit (set/clear/toggle/check, swap bằng XOR, đếm bit 1, kiểm tra lũy thừa của 2, MSB/LSB, v.v.).

## Yêu cầu
- GCC (hoặc trình biên dịch C tương đương)
- Hệ điều hành: Linux

## Cách biên dịch
Mở terminal trong thư mục project:
```bash
cd "/home/danivan/Documents/Devlinux/Cpro/Module1 Review/"
gcc -std=c11 -Wall -Wextra -O2 bit_operations.c -o bit_operations
```

## Cách chạy
Sau khi biên dịch:
```bash
./bit_operations
```

## Kết quả mong đợi (ví dụ)
Chạy chương trình sẽ in ra các ví dụ demo, ví dụ:
```
Giá trị ban đầu: 0xA4
1. Set bit 1 -> 0xA6
2. Clear bit 2 -> 0xA0
3. Toggle bit 5 -> 0x24
4. Bit 5 đã bật
5. Sau khi swap: a=5, b=10
6. 16 là lũy thừa của 2
7. Số bit 1 trong 0xA4 là 3
8. 13 là lẻ
9. Bù 2 của 5 là -5
10. 7 và 7 bằng nhau
11. Vị trí MSB của 0xA4 là 7
12. Vị trí LSB của 0xA4 là 2
13. Tắt bit 1 ngoài cùng bên phải: 0xA0
```
(Thực tế format có thể khác chút tùy hệ thống.)
