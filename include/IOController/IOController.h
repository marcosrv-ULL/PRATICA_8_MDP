/**
  * Universidad de la laguna
  * Escuela superior de tecnología e ingeniería
  * Grado en informatica
  * Diseño y analisis de algoritmos
  *
  * @author Marcos Rodríguez Vega
  * @since 06/03/2022
  * desc @desc Esta clase se encarga básicamente de cualquier labor que requiera abrir fichero y copiar en los mismos
  *            Lo convierte todo a una string en el caso de leer, para que simule una especie de stream de caracteres
  *            y no tener los dipositivos de entrada y salida abierto mucho tiempo            
  * 
  */

#ifndef IOCONTROLLER_H
#define IOCONTROLLER_H

#include <string>
#include <fstream>
#include <iostream>
#include <streambuf>

class IOController {
    public:
        static std::string getStringOfFile(std::string filename);
        static void toFile(std::string, std::string);
};

#endif