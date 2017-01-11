
#include <thread>
#include "client.h"
#include <chrono>


int main(int argc, char* argv[]){
    if(argc!=3){
        std::cout << "Para ejecutar el archivo en la linea de comandos escribir ./client direcIP port" << std::endl;
        std::cout << "donde direcIP es una direccion IP que representa la direcion del servidor al que se debe conectar el cliente" << std::endl;
        std::cout << "Ejemplo: ./client 192.168.1.1 49999" << std::endl;
        return 0;
    }

    Client cliente(atoi(argv[2]),argv[1]);
    while(true){
        cv::Mat decoded_image;
        cliente.retrieve(decoded_image);
        if(decoded_image.cols!=0){ // Si existe imagen, mostrar por pantalla
            cv::imshow("imagen descomprimida",decoded_image);
        }
        cv::waitKey (3);
    }
}

