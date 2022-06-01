#ifndef streaming_h
#define streaming_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "episodio.hpp"
#include "pelicula.hpp"

class Interface
{
    public:
        virtual void readData(std::string, std::string)=0;
        virtual void searchVideos(float)=0;
        virtual void searchVideos(std::string)=0;
        virtual void searchEpisode(std::string, float)=0;
        virtual void searchMovies(float)=0;
        virtual void rate(std::string)=0;
        virtual void showMenu()=0;
};

class Streaming: public Interface
{
    private:
        std::vector<Episodio> episodios;
        std::vector<Pelicula> peliculas;

    public:
        void readData(std::string seriesFile, std::string moviesFile);
        void searchVideos(float calificacion);
        void searchVideos(std::string genero);
        void searchEpisode(std::string serie, float calificacion);
        void searchMovies(float calificacion);
        void rate(std::string titulo);

        // Menu
        void showMenu();
        void operator()();
};

void Streaming::readData(std::string seriesFile, std::string moviesFile)
{
    // Clear vectors to avoid loading videos multiple times
    episodios.clear();
    peliculas.clear();

    // Counter used to avoid adding the first line of the CSV.
    int contador = 0;

	std::vector<std::string> row;
	std::string line, word;

    // Load episodes
	std::fstream file1(seriesFile, std::ios::in);
	if(file1.is_open())
	{
		while(getline(file1, line))
		{
            if (contador > 0)
            {
                row.clear();
 
			    std::stringstream str(line);
 
                while(getline(str, word, ','))
                {
                    row.push_back(word);
                }

                episodios.push_back(Episodio(stoi(row[0]), row[1], stoi(row[2]), row[3], stoi(row[4]), stof(row[5]), row[6], stof(row[7])));
            }
            contador++;
		}
	}
	else
    {
        throw 2;
    }

    // Load movies
    contador = 0; // Counter needs to start at 0 again to skip the header.
    std::fstream file2(moviesFile, std::ios::in);
	if(file2.is_open())
	{
		while(getline(file2, line))
		{
            if (contador > 0)
            {
                row.clear();
    
                std::stringstream str(line);
    
                while(getline(str, word, ','))
                {
                    row.push_back(word);
                }
                peliculas.push_back(Pelicula(stoi(row[0]), row[1], stof(row[2]), row[3], stof(row[4])));
            } 
            contador++;
		}
	}
	else
    {        
        throw 3;
    }

    std::cout << "Archivos de datos cargados exitosamente\n\n";
}

void Streaming::searchVideos(float calificacion)
{
    if ((calificacion>=1.0) && (calificacion<=5.0))
    {
        std::cout << "\nResultados: \n";
        int contador = 0;

        std::vector<Episodio>::iterator it1;

        for (it1 = episodios.begin(); it1 != episodios.end(); it1++)
        {
            if (it1 -> getCalificacion() == calificacion)
            {
                std::cout << it1 -> getNombre() << std::endl;
                contador++;
            } 
        }

        std::vector<Pelicula>::iterator it2;

        for (it2 = peliculas.begin(); it2 != peliculas.end(); it2++)
        {
            if (it2 -> getCalificacion() == calificacion)
            {
                std::cout << it2 -> getNombre() << std::endl;
                contador++;
            }
        }

        if (contador == 0)
        {
            std::cout << "No se encontraron resultados para su búsqueda. \n";
        }

        std::cout << "\n";
    }

    else
    {
        throw 5;
    }
}

void Streaming::searchVideos(std::string genero)
{
    int n = genero.length();
    genero[0] = toupper(genero[0]);
    
    if (genero == "Drama" || genero == "Accion" || genero == "Misterio")
    {
        std::cout << "\nResultados: \n";
        std::vector<Episodio>::iterator it1;

        for (it1 = episodios.begin(); it1 != episodios.end(); it1++)
        {
            if (it1 -> getGenero() == genero)
            {
                std::cout << it1 -> getNombre() << std::endl;
            } 
        }

        std::vector<Pelicula>::iterator it2;

        for (it2 = peliculas.begin(); it2 != peliculas.end(); it2++)
        {
            if (it2 -> getGenero() == genero)
            {
                std::cout << it2 -> getNombre() << std::endl;
            }
        }
    }
    else
    {
        throw 4;
    }

    std::cout << std::endl;
}

void Streaming::searchEpisode(std::string serie, float calificacion)
{
    int contador = 0;

    if  ((calificacion >= 1) && (calificacion <=5))
    {
        serie[0] = toupper(serie[0]);
        int n = serie.length();

        std::cout << "\nResultados: \n";

        for (int i = 1; i < n; i++)
        {
            if (serie[i-1] == ' ')
            {
                serie[i] = toupper(serie[i]);
            }
        }

        std::vector<Episodio>::iterator it1;

        for (it1 = episodios.begin(); it1 != episodios.end(); it1++)
        {
            if ((it1 -> getSerie() == serie) && (it1 -> getCalificacion() == calificacion))
            {
                std::cout << it1 -> getNombre() << std::endl;
                contador++;
            } 
        }
    }
    else
    {
        throw 5;
    }
    
    if (contador == 0)
    {
        std::cout << "No se encontraron resultados para su búsqueda.\n";
    }

    std::cout << "\n";
}

void Streaming::searchMovies(float calificacion)
{
    int contador = 0;
    if ((calificacion >= 1) && (calificacion <=5))
    {
        std::cout << "\nResultados: \n";
        std::vector<Pelicula>::iterator it1;

        for (it1 = peliculas.begin(); it1 != peliculas.end(); it1++)
        {
            if (it1 -> getCalificacion() == calificacion)
            {
                std::cout << it1 -> getNombre() << std::endl;
                contador++;
            } 
        }     
    }
    else
    {
        throw 5;
    }

    if (contador == 0)
    {
        std::cout << "No se encontraron resultados para su búsqueda.\n";
    }

    std::cout << "\n";

}

void Streaming::rate(std::string titulo)
{
    std::string calificacion;
    float rating;

    int contador = 0;
    std::vector<Episodio>::iterator it1;

    for (it1 = episodios.begin(); it1 != episodios.end(); it1++)
    {
        if (it1 -> getNombre() == titulo)
        {
            try
            {
                std::cout << "Escriba la calificación que desea otorgar (entre 1 y 5): ";
                std::getline(std::cin, calificacion);

                rating = std::stof(calificacion);
            }
            catch (const std::invalid_argument& ia)
            {
                std::cerr << "Error 7: Argumento inválido, " << ia.what() << " no puede convertir su entrada a flotante." << "\n\n";
            }
            
            if ((rating >= 1) && (rating <= 5))
            {
                it1 -> calificar(rating);
                contador++;
            }
            else
            {
                throw 5;
            }
        } 
    }

    std::vector<Pelicula>::iterator it2;

    for (it2 = peliculas.begin(); it2 != peliculas.end(); it2++)
    {
        if (it2 -> getNombre() == titulo)
        {
            try
            {
                std::cout << "Escriba la calificación que desea otorgar (entre 1 y 5): ";
                std::getline(std::cin, calificacion);

                rating = std::stof(calificacion);
            }
            catch (const std::invalid_argument& ia)
            {
                throw 7;
            }

            if ((rating >= 1) && (rating <= 5))
            {
                it2 -> calificar(rating);
                contador++;
            }
            else
            {
                throw 5;
            }
        } 
    }

    if (contador == 0)
    {
        throw 404;
    }
}

void Streaming::showMenu()
{
    std::cout << "MENU\n";
    std::cout << "Escoja una opción usando los números correspondientes\n";
    std::cout << "1. Cargar archivo de datos \n";
    std::cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género\n";
    std::cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada\n";
    std::cout << "4. Mostrar las películas con cierta calificacion\n";
    std::cout << "5. Calificar un video\n";
    std::cout << "0. Salir\n\n";

    std::cout << "Opción: ";
}

void Streaming::operator()()
{
    this -> showMenu();
}
#endif