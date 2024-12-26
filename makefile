all:derle bagla calistir

derle:
	g++ -c -I "./include" ./src/BST.cpp -o ./lib/BST.o
	g++ -c -I "./include" ./src/BSTDugum.cpp -o ./lib/BSTDugum.o
	g++ -c -I "./include" ./src/BagliListe.cpp -o ./lib/BagliListe.o
	g++ -c -I "./include" ./src/BagliListeDugum.cpp -o ./lib/BagliListeDugum.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/main.o ./lib/BST.o ./lib/BSTDugum.o ./lib/BagliListe.o ./lib/BagliListeDugum.o -o ./bin/program
calistir:
	./bin/program