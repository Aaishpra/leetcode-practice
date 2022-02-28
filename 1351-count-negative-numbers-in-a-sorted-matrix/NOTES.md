n = len(grid)-1
row, col = 0, len(grid[0])-1
count = 0
while col >=0 and row <= n:
number = grid[row][col]
if number < 0:
count += (n - row + 1)
col -= 1
else:
row += 1
return count