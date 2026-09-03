# C++ Linear Systems Solver (Gaussian Elimination)

A lightweight C++ tool that solves systems of $N$ linear equations in $N$ variables ($Ax = b$) using Gaussian Elimination with Forward Elimination and Back Substitution.

---

## Features

* **Dynamic Matrix Input:** Accepts $N \times (N + 1)$ augmented matrices for systems of any standard linear size.
* **Forward Elimination:** Converts the augmented matrix into Upper Triangular Form using row operations.
* **Back Substitution:** Computes exact variable values ($x_1, x_2, \dots, x_n$) starting from the bottom row upward.
* **Pivot Zero Detection:** Includes basic runtime checking to catch zero pivot elements before division.
* **Formatted Output:** Displays results rounded to 4 decimal places via standard stream manipulators (`std::setprecision`).

---

## Technical Details

    Input Augmented Matrix [A | b]
    │
    ▼
    Forward Elimination  ───> Converts A to Upper Triangular Form
    │
    ▼
    Back Substitution  ───> Solves for x[N] down to x[1]
    │
    ▼
    Output Vector x

* **Algorithm:** Gaussian Elimination
* **Time Complexity:** $\mathcal{O}(N^3)$ for forward elimination; $\mathcal{O}(N^2)$ for back substitution.
* **Space Complexity:** $\mathcal{O}(N^2)$ dynamic memory allocation using nested `std::vector`.

---

## Compilation & Execution

### Prerequisites
* Any standard C++ compiler supporting **C++11** or later (e.g., `g++`, `clang++`, or MSVC).

### Compile
```bash
g++ -std=c++11 -O2 main.cpp -o Linear_Guassian_Elimination
./linear_Guassian_Elimination
```

### Sample
Enter the size of the matrix (N): 3

Enter the augmented matrix row by row (including constants):
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3

### Sample Output
Solution for the system:
x[1] = 2.0000
x[2] = 3.0000
x[3] = -1.0000
