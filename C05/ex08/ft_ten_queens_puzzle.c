#include <unistd.h>

void	print_solution(int *board, int col) {
	char c = board[col] + '0';
	write(1, &c, 1);
	if (col == 9) {
		write(1, "$\n", 2);
	} else {
		print_solution(board, col + 1);
	}
}

int	place_queen(int *board, int col, int *cols, int *diag1, int *diag2) {
	if (col == 10) {
		print_solution(board, 0);
		return 1;
	}
	int count = 0;
	count += try_rows(board, col, cols, diag1, diag2, 0);
	return count;
}

int	try_rows(int *board, int col, int *cols, int *diag1, int *diag2, int row) {
	if (row == 10) return 0;
	int count = 0;
	if (cols[row] || diag1[row - col + 9] || diag2[row + col]) {
		count += try_rows(board, col, cols, diag1, diag2, row + 1);
	} else {
		board[col] = row;
		cols[row] = 1;
		diag1[row - col + 9] = 1;
		diag2[row + col] = 1;
		count += place_queen(board, col + 1, cols, diag1, diag2);
		cols[row] = 0;
		diag1[row - col + 9] = 0;
		diag2[row + col] = 0;
		count += try_rows(board, col, cols, diag1, diag2, row + 1);
	}
	return count;
}

int	ft_ten_queens_puzzle(void) {
	int board[10] = {0};
	int cols[10] = {0};
	int diag1[19] = {0};
	int diag2[19] = {0};
	return place_queen(board, 0, cols, diag1, diag2);
}

int	main(void) {
	char c;
	int solutions = ft_ten_queens_puzzle();
	c = solutions / 10 + '0';
	write(1, &c, 1);
	c = solutions % 10 + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
	return 0;
}
