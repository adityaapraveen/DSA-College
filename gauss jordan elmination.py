import numpy as np

# Take input for the number of equations and variables
num_eqns = int(input("Enter the number of equations: "))
num_vars = int(input("Enter the number of variables: "))

# Take input for the coefficients matrix and the constants vector
A = np.zeros((num_eqns, num_vars), dtype=float)
B = np.zeros(num_eqns, dtype=float)
for i in range(num_eqns):
    eqn = input(f"Enter equation {i+1} coefficients separated by space: ")
    eqn_list = list(map(float, eqn.split()))
    A[i] = eqn_list[:-1]
    B[i] = eqn_list[-1]

# Combine the coefficient matrix and the constants vector
AB = np.column_stack((A, B))

# Get the dimensions of the matrix
num_rows, num_cols = AB.shape

# Perform Gauss Jordan elimination
for i in range(num_rows):
    # Divide the current row by the pivot element to make the pivot element 1
    pivot = AB[i][i]
    AB[i] = AB[i] / pivot

    # Eliminate the non-pivot elements in the current column
    for j in range(num_rows):
        if j != i:
            factor = AB[j][i]
            AB[j] = AB[j] - factor * AB[i]

# Extract the solution vector from the augmented matrix
X = AB[:, num_cols - 1]

print("Solution vector:")
print(X)
