#include<iostream>
#include<fstream>
#include<string>

void main() {
	//1.Historial conversation
	//Abro archivo en modo de escritura
	std::ofstream file_w;
	file_w.open("historial.txt");
	
	std::string mensaje = "";
	if (file_w.is_open()) {
		while (mensaje != "exit") {
			getline(std::cin, mensaje);

			if (mensaje != "exit") {
				file_w << mensaje << std::endl;
			}
		}
		file_w.close();
	}
	else
	{
		std::cout << "Error: No se a podido abrir el archivo" << std::endl;
	}
	//2.Recuperar conversación
	
	std::ifstream file_r;

	file_r.open("historial.txt");
	
	//Veritificación de la existencia
	if (file_r){
		std::cout << "¿Quieres recuperar el historial? (y/n)" << std::endl;
		file_r.close();
	}
	else {
		std::cout << "Archivo no existe" << std::endl;
	}
}