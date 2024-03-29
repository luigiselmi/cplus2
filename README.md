C/C++ for Numerical Methods and Scientific Applications
=======================================================
This repository contains programs in C/C++. The C/C++ source code can be compiled from
the command line or from an IDE such as [Eclipse CDT](https://www.eclipse.org/cdt/). [Gnuplot](http://www.gnuplot.info/) is the tool used to plot the output of the programs.

## Compile and execute from the command Line
The GNU g++ (or gcc) compiler for C and C++ is installed by default on any Linux OS and it
can be used from the command line. For the MS Windows OS the [Cygwin Project](https://www.cygwin.com/) provides a Linux environment with the GNU C/C++ compilers.
### Compile and link a C/C++ program
To compile a C source file you can use the GNU gcc compiler (or the cc compiler for C programs)

$ gcc HelloWorld.c

The output of the compilation by default is an executable file a.exe. In order to name the
executable file like the source code you can use the command

$ gcc HelloWorld.c -o HelloWorld

C++ source code can be compiled using the GNU g++ compiler.

### Run a program
To execute a program, HelloWorld.exe for instance, use the command

$ ./HelloWorld.exe

or simply

$ ./HelloWorld

## Eclipse CDT (C/C++ Development Tooling)
The main problem about developing using a text editor is that it is difficult to use a debugger. The GNU GDB debugger can be used with the command line (see ref.4) but you may
be used to an IDE such as Eclipse, the Java IDE, that can be used to develop C/C++ application as well. One needs to install Java in order to execute the IDE, then the compiler and the debugger. In Eclipse CDT an executable is created in a project that includes all the required C or C++ files, one of which contains the main() function. If a main() function is defined in more than a file in the same project the IDE will raise an error of "multiple definitions of main". For this reason in Eclipse CDT each file containing a main() function should be in a separate project.

## Scientific applications
In this section are reported some simulations performed using the code in this repository. The details of each application are presented in a separate page with a link to the source code.
### Floating point arithmetic
[Floating-point arithmetic](c/sp/floating-point-arithmetic.md)  

### Random walk
[Random walk on a square lattice](c/sp/random_walk.md)  

### Connected components
[Connected components](c/sp/connected_components.md)  

### Cellular automaton
[Cellular automaton](c/sp/cellular_automaton.md)

## References and Credits
Most of the software is taken from the following books:
1. [Kernighan, Ritchie - The C Programming Language, 2nd Ed](http://s3-us-west-2.amazonaws.com/belllabs-microsite-dritchie/cbook/index.html)  
2. [Barone, Marinari, Organtini, Ricci-Tersenghi - Scientific Programming](https://chimera.roma1.infn.it/SPENG/)    
3. [Gnuplotting, scientific plots using gnuplot](http://www.gnuplotting.org/)  
4. [Hartmann et al. - A practical guide to computer simulations](https://arxiv.org/abs/cond-mat/0111531)  
5. [Goldberg - What every computer scientist should know about floating-point arithmetic](https://dl.acm.org/doi/10.1145/103162.103163)  
