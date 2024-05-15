#include<iostream>
#include<ofstrem>
#include<string>

void main() {
	ofstrem file;
	file.open("historial.txt");
	string mensaje = "";
	while (mensaje != "exit") {
		getline(cin, mensaje);
		file << mensaje;
		file.close();
	}

}