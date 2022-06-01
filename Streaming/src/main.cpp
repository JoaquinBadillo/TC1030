#include <iostream>
#include <stdlib.h>
#include "streaming.hpp"

int main(void)
{
    Streaming plataforma;

    std::string input1;
    char option = ' ';

    std::string input2;
    char seleccion = '0';

    std::string continuar;

    std::string calificacion; 
    float rating;
    std::string genero;
    std::string serie;
    std::string titulo;

    do
    {
        try
        {
            // The clear command will only work in UNIX and MacOS, I added it to make the menu cleaner.
            std::system("@cls||clear");

            plataforma();
            std::getline(std::cin, input1);

            std::system("@cls||clear");

            if (input1.size() != 1)
            {
                throw 6;
            }

            option = input1[0];

            try
            {
                switch (option)
                {
                    case '0':
                        break;
                    
                    case '1':
                        std::cout << "Carga de archivos\n\n"; 
                        try
                        {
                            plataforma.readData("data/series.csv", "data/peliculas.csv");
                        }
                        catch(int a)
                        {
                            std::cerr << "Error "  << a << ": ";
                            if (a == 2)
                            {
                                std:: cerr << "No se pudo abrir el archivo de series. \n\n";
                            }
                            else if (a == 3)
                            {
                                std:: cerr << "No se pudo abrir el archivo de películas. \n\n";
                            }
                        }
                        break;
                    
                    case '2':
                        std::cout << "Búsqueda de vídeos\n\n";
                        {
                            try
                            {
                                std::cout << "Para buscar por calificación presione \"c\" o \"C\"\n";
                                std::cout << "Para buscar por género presione \"g\" o \"G\"\n";
                                std::cout << "Opción: ";
                                std::getline(std::cin, input2);

                                if (input2.size() != 1)
                                {
                                    throw 6;
                                }
                                        
                                seleccion = tolower(input2[0]);
                                switch (seleccion)
                                {
                                    case 'c':
                                        try
                                        {
                                            std::cout << "Ingrese la calificación para buscar títulos: ";
                                            std::getline(std::cin, calificacion);
                                            rating = std::stof(calificacion);
                                            plataforma.searchVideos(rating);
                                        }
                                        catch (const std::invalid_argument& ia)
                                        {
                                            std::cerr << "Error 7: Argumento inválido, " << ia.what() << " no puede convertir su entrada a flotante." << "\n\n";
                                        }                                     
                                        break;

                                    case 'g':
                                        std::cout << "Ingrese el género para buscar títulos: ";
                                        std::getline(std::cin, genero);
                                        plataforma.searchVideos(genero);
                                        break;

                                    default:
                                        throw 1;
                                }
                            } 
                            catch(int a)
                            {
                                std::cerr << "Error " << a;
                                if (a == 1)
                                {
                                    std::cerr << ": Opción inválida.\n\n";
                                }
                                else if (a == 4)
                                {
                                    std::cerr << ": Género no reconocido.\n\n";
                                }
                                else if (a == 5)
                                {
                                    std::cerr << ": La calificación introducida es inválida.\n\n";
                                }
                                else if (a == 6)
                                {
                                    std::cerr << ": Solo se aceptan caracteres (no vacíos).\n\n";
                                }
                            }
                        }
                        break;

                    case '3':
                        std::cout << "Búsqueda de episodios por calificación y serie\n\n";
                        try
                        {
                            try
                            {
                                std::cout << "Escribe el nombre de la serie: ";
                                std::getline(std::cin, serie);

                                std::cout << "Escribe la calificación: ";
                                std::getline(std::cin, calificacion);

                                rating = std::stof(calificacion);

                                plataforma.searchEpisode(serie, rating);
                            }
                            catch (const std::invalid_argument& ia)
                            {
                                std::cerr << "Error 7: Argumento inválido, " << ia.what() << " no puede convertir su entrada a flotante." << "\n\n";
                            }
                        }
                        catch(int a)
                        {
                            std::cerr << "Error " << a << ": La calificación introducida es inválida.\n\n";
                        }
                        break;

                    case '4':
                        std::cout << "Búsqueda de películas por calificación\n\n";
                        try
                        {
                            try
                            {
                                std::cout << "Escribe la calificación: ";
                                std::getline(std::cin, calificacion);
                                rating = std::stof(calificacion);

                                plataforma.searchMovies(rating); 
                            }
                            catch (const std::invalid_argument& ia)
                            {
                                std::cerr << "Error 7: Argumento inválido, " << ia.what() << " no puede convertir su entrada a flotante." << "\n\n";
                            }
                        }
                        catch(int a)
                        {
                            std::cerr << "Error " << a << ": La calificación introducida es inválida.\n\n";
                        }
                        break;

                    case '5':
                        std::cout << "Calificación personal de vídeos\n\n";
                        try
                        {
                            std::cout << "Escribe el título que deseas calificar: ";
                            std::getline(std::cin, titulo);

                            plataforma.rate(titulo); 
                            std::cout << "Video calificado exitosamente.\n\n";
                        }
                        catch(int a)
                        {
                            std::cerr << "Error " << a;
                            if (a == 5)
                            {
                                std::cerr << ": La calificación introducida es inválida.\n\n";
                            }
                            else if (a == 7)
                            {
                                std::cerr << ": Argumento inválido, stof no puede convertir su entrada a flotante." << "\n\n";
                            }
                            else if (a == 404)
                            {
                                std::cerr << ": título no encontrado.\n\n";
                            }
                        }
                        break;

                    default:
                        throw 1;
                }
            }
            catch(int a)
            {
                std::cerr << "Error " << a << ": Opción inválida.\n\n";
            }      
        }
        catch (int a)
        {
            if (a == 6)
            {
                std::cerr << "Error 6: Solo se aceptan caracteres (no vacíos).\n\n";
            }
        }

        std::cout << "Presione enter para continuar: ";
        std::getline(std::cin, continuar);

    } while (option != '0');
    std::cout << "Logout\n\n";
    std::cout << "Ha salido exitosamente\n";

    return 0;
}