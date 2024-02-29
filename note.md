# IT3170 - Thuật toán ứng dụng

## Chương 1: Các cấu trúc dữ liệu và thư viện
### 1. Các kiểu dữ liệu cơ bản
- Phải biết:
    + bool: true/false
    + char: biến nguyên 8 bit
    + string: biến xâu ký tự
    + int: biến nguyên 32 bit
    + long: biến nguyên 32 bit
    + float: biến thực 32 bit
    + double: biến thực 64 bit
- Các modifier:
    + signed
    + unsigned
    + short
    + long

### 2. Xử lý số nguyên lớn
- Làm thế nào để thực hiện tính toán trên các số nguyên lớn không thể lưu trữ bằng kiểu long long int ?
- Ý tưởng:
    + lưu trữ số nguyên dưới dạng string
    + thực hiện phép toán trên từng chữ số từ phải sang trái, có lưu phần nhớ như đã học ở tiểu học

- Ví dụ: file "VD1.c" + "VD2.c" trong folder Chap_1

### 3. Thư viện cấu trúc dữ liệu và thuật  toán
- Thư viện mẫu chuẩn STL trong C++ chia làm 4 thành phần:
    + Containers Library: chứa các cấu trúc dữ liệu mẫu
        + Sequence containers (cấu trúc tuần tự): Vector, Deque, List
        + Containers adaptors: Stack, Queue, Priority_queue
        + Associative containers (cấu trúc liên kết): Set, Multiset, Map, Multimap, Bitset
    + Algorithms Library: một số thuật toán để thao tác trên dữ liệu
    + Iterator Library: giống như con trỏ, dùng để truy cập đến các phần tử dữ liệu của container
    + Numeric library

- Một số cấu trúc dữ liệu thông dụng:
    + Mảng tĩnh             *int arr[10]*
    + Mảng động             *vector<int>*
    + Danh sách liên kết    *list<int>*
    + Ngăn xếp              *stack<int>*
    + Hàng đợi              *queue<int>*
    + Hàng đợi có ưu tiên   *priority_queue<int>*
    + Hàng đợi hai đầu      *deque<int>*
    + Tập hợp               *set<int>*
    + Ánh xạ                *map<int, int>*


# Dxy