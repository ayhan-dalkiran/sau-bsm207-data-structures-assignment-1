all: build run

build:
	g++ -I ./include/ -o ./lib/gene_node.o -c ./src/gene_node.cpp
	g++ -I ./include/ -o ./lib/chromosome.o -c ./src/chromosome.cpp
	g++ -I ./include/ -o ./lib/list_node.o -c ./src/list_node.cpp
	g++ -I ./include/ -o ./lib/chromosome_list.o -c ./src/chromosome_list.cpp
	g++ -I ./include/ -o ./bin/main ./lib/gene_node.o ./lib/chromosome.o ./lib/list_node.o ./lib/chromosome_list.o ./src/main.cpp

run:
	./bin/main