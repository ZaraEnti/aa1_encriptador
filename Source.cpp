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
				file_w << mensaje; 
			}
			getline(std::cin, mensaje);
			if (mensaje == "exit") {
				//eliminar el salto de linea
			}
		}file_w << std::endl;
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
		char c;
		std::cout << "¿Quieres recuperar el historial? (y/n)" << std::endl;
		std::cin >> c;
		
		if (c=='n'||c=='N') {
			mensaje = "";//reset del mensaje
			//Se sobreescribe
			file_w.open("historial.txt");
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
		}
		else if (c=='y'||c=='Y') {
			mensaje = "";//reset del mensaje
			//Se añade
			file_w.open("historial.txt", std::ios::app);
			if (file_w.is_open()) {
				while (mensaje != "exit") {
					getline(std::cin, mensaje);

					if (mensaje != "exit") {
						file_w << mensaje << std::endl;
					}
				}
				file_w.close();
			}
		}
	}
	else {
		std::cout << "Archivo no existe" << std::endl;
	}
}