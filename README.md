Bài Tập Nâng Cao: 
Nếu M = 1, xác định độ phức tạp thuật toán tương ứng với giải thuật đã đề xuất, tính thời gian chạy chương trình với giá trị N > 100000.
1. Với M = 1. 
- Độ phức tạp thời gian (T(n)): Để tìm ra người chiến thắng, thực hiện N - 1 lượt loại bỏ.
+ Mỗi lượt loại bỏ với M = 1 tốn đúng 1 bước nhảy. Khi đó, tổng số bước nhảy là N - 1 xấp xỉ O(N).
- Độ phức tạp không gian: Tạo N node để đại diện cho N người
-> Độ phức tạp: O(N).
2. Tính toán thời gian
- Với N > 100000, có xấp xỉ 200000 phép toán( dịch, xóa node). Máy tính có thể tính 100000000 phép toán trên giây. Do đó, thời gian chạy ước lượng xấp xỉ 0,002s. Thuật toán chạy nhanh.
  
