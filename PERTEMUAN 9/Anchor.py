def is_safe(board, row, col): # fungsi untuk memeriksa apakah aman untuk menempatkan ratu pada posisi (row, col)
    for i in range(row): # periksa setiap baris sebelumnya untuk memastikan tidak ada ratu yang menyerang posisi saat ini
        if board[i] == col or abs(i - row) == abs(board[i] - col): # periksa apakah ada ratu yang berada di kolom yang sama atau diagonal yang sama
            return False # kembalikan False jika ada ratu yang menyerang
    return True

# Fungsi nqueen untuk menghitung jumlah solusi dari masalah N-Queens
def nqueen(row, n, board):
    if row == n: # jika semua ratu telah ditempatkan dengan aman, maka kita telah menemukan solusi yang valid
        return 1 # kembalikan 1 untuk menghitung solusi ini
    
    # inisialiasi variabel total untuk menyimpan total kemungkinan tiap cabang
    total = 0 
    
    #loop untuk mencoba menempatkan ratu di setiap kolom pada baris saat ini
    for col in range(n): # coba tempatkan ratu pada kolom col di baris row
        if is_safe(board, row, col): # periksa apakah posisi ini aman untuk menempatkan ratu
            board[row] = col # tempatkan ratu pada posisi yang aman
            total += nqueen(row + 1, n, board) # rekursif untuk mencoba menempatkan ratu pada baris berikutnya
            board[row] = -1  # reset posisi ratu untuk backtracking
            
    return total 

n = int(input()) #
board = [-1] * n # inisialisasi papan dengan -1 untuk menunjukkan bahwa belum ada ratu yang ditempatkan
print(nqueen(0, n, board)) 