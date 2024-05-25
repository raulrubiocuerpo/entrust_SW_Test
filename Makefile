all: solucion_cpp solucion_go

solucion_cpp: solucion.cc
	g++ -o solucion_cpp solucion.cc

solucion_go: solucion.go
	go build -o solucion_go solucion.go

clean:
	rm -f solucion_cpp solucion_go paginated_document_cc.txt paginated_document_go.txt