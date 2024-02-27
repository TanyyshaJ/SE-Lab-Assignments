class MatrixOperations:
    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.matrix1 = self.get_matrix(rows, columns)
        self.matrix2 = self.get_matrix(rows, columns)

    def get_matrix(self, r, c):
        matrix = []
        for i in range(r):
            row = []
            for j in range(c):
                elem = int(input(f"Enter element at position ({i+1}, {j+1}): "))
                row.append(elem)
            matrix.append(row)
        return matrix

    def matrix_display(self, matrix):
        print("\n")
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                print("{:<5}".format(matrix[i][j]), end=" ")
            print()

    def add_matrices(self):
        sum_matrix = [[self.matrix1[i][j] + self.matrix2[i][j] for j in range(self.columns)] for i in range(self.rows)]
        print("Sum of Matrix 1 and Matrix 2: ")
        self.matrix_display(sum_matrix)

    def subtract_matrices(self):
        sub_matrix = [[self.matrix1[i][j] - self.matrix2[i][j] for j in range(self.columns)] for i in range(self.rows)]
        print("Subtraction of Matrix 1 and Matrix 2: ")
        self.matrix_display(sub_matrix)

    def multiply_matrices(self):
        prod_matrix = [[0] * self.columns for _ in range(self.rows)]
        for i in range(len(self.matrix1)):
            for j in range(len(self.matrix2[0])):
                for k in range(len(self.matrix2)):
                    prod_matrix[i][j] += self.matrix1[i][k] * self.matrix2[k][j]

        print("Product of Matrix 1 and Matrix 2: ")
        self.matrix_display(prod_matrix)

    def transpose_matrix(self):
        trans_matrix = [[self.matrix1[i][j] for i in range(self.rows)] for j in range(self.columns)]
        print("Transpose of Matrix 1: ")
        self.matrix_display(trans_matrix)


# Example Usage:
rows, columns = list(map(int, input("Enter the number of rows and columns respectively, separated by a space: ").split()))
matrix_operations = MatrixOperations(rows, columns)

matrix_operations.add_matrices()
matrix_operations.subtract_matrices()
matrix_operations.multiply_matrices()
matrix_operations.transpose_matrix()
