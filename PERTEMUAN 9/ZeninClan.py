def is_safe(board, row, col): 
    for i in range(row): 
        if board[i] == col or abs(i - row) == abs(board[i] - col):
            return False 
    return True


def ZeninClan(row, n, board):
    if row == n:
        return 1 
    
    total = 0 
    
    for col in range(n): 
        if is_safe(board, row, col): 
            board[row] = col 
            total += ZeninClan(row + 1, n, board) 
            board[row] = -1  
            
    return total 

n = int(input()) 
board = [-1] * n 
print(ZeninClan(0, n, board)) 