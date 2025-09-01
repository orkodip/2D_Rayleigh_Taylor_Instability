# 2D_Rayleigh_Taylor_Instability
This repository contain the codes (written in C++) for computation of Rayleigh-Taylor instability in 2D Cartesian coordinates using the THINC-scaling scheme-based CLSVOF method. The governing incompressible Navier-Stokes equation is solved in a mass-momentum consistent framework. Further, the finite volume method is used to discretize the governing equations in a co-located structured mesh. The numerical details of our in-house developed solver is available in the article: Mookherjee et al., 2024. A mass-momentum consistent THINC-scaling scheme for CLSVOF method on co-located grid. Numerical Heat Transfer, Part B: Fundamentals, pp.1-27.

# Reference
Mookherjee, O., Pramanik, S. and Sharma, A., 2024. A mass-momentum consistent THINC-scaling scheme for CLSVOF method on co-located grid. Numerical Heat Transfer, Part B: Fundamentals, pp.1-27.

# Software requirements
This solver needs:

- gcc

# How to install the required packages (on a Linux system)

To install gcc (compiler for C++ code)

```bash
sudo apt install build-essential
```

# How to compile and run the code

To compile the code

```bash
g++ ht.cpp -o output
```
To run this code

```bash
./output
```
