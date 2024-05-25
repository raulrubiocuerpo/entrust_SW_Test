# entrust_SW_Test

## Description
Solution to the given task in 'TOPS SW Technical exercise.docx' in C++ and Golang languages.

## Necessary resources
- Operating System: Linux or WSL (Windows Subsystem for Linux).
- Golang compiler: On Linux or WSL, `sudo apt install golang-go`.
- C++ compiler: On Linux or WSL, `sudo apt install g++`.
- Make: On Linux or WSL, `sudo apt install make`.

## How to execute the programs
1. Clone the repository in your local machine using `git clone https://github.com/raulrubiocuerpo/entrust_SW_Test.git`
2. Navigate to the directory of the project
3. Build / Run the program:
    ## Using the Makefile:
    1. all:
        in the terminal use `make all` to build both solucion.cc and solucion.go executables run the executables using `./solucion_cpp` and `./solucion_go`, respectively
        
    2. solucion_cpp: use `make solucion_cpp` to build the solucion.cc executable, run the executables using `./solucion_cpp`
        
    3. solucion_go: use `make solucion_go` to build the solucion.go executable, run the executables using `./solucion_go`
        
    4. clean: use `make clean` to remove the executables and the txt files generated.

    ## Only for the solucion.go file: 
    1. Run the program using `go run solucion.go` or build the executable with `go build -o solucion_go solucion.go` then run it with `./solucion_go`

    ## Only for the solucion.cc file: 
    1. Build the executable using `g++ -o solucion_cpp solucion.cc` then run it with `./solucion_cpp`