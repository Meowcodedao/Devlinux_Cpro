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


