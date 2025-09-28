# Smart Plant Watering System

## ⚙️ Cấu trúc dự án
- **source/**
  - `actuators.c` – Điều khiển các thiết bị chấp hành (bơm, van...)
  - `button.c` – Xử lý nút nhấn
  - `sensors.c` – Đọc dữ liệu từ cảm biến (độ ẩm đất, nhiệt độ...)
  - `watering.c` – Logic tưới nước
  - `main.c` – Điểm vào chính của chương trình
- **include/** – Chứa file header (.h)
- **makefile** – Script build chương trình
- **README.md** – Tài liệu dự án


Yêu cầu: gcc

Build chương trình:
make

Chạy chương trình:
./spws

Xóa file build:
make clean


* **actuators.c** → Quản lý thiết bị chấp hành (bơm, van).
* **button.c** → Quản lý input từ nút nhấn.
* **sensors.c** → Đọc dữ liệu từ cảm biến (giả lập hoặc thật).
* **watering.c** → Thuật toán quyết định tưới cây dựa vào dữ liệu cảm biến.
* **main.c** → Hàm `main()`, khởi động chương trình, gọi các module.
