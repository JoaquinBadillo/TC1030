#ifndef pelicula_h
#define pelicula_h

#include "video.hpp"

class Pelicula: public Video
{
    public:
        Pelicula();
        Pelicula(int id_, std::string nombre_, float duracion_, std::string genero_, float calificacion_);
};

Pelicula::Pelicula(): Video() {}
Pelicula::Pelicula(int id_, std::string nombre_, float duracion_, std::string genero_, float calificacion_): Video(id_, nombre_, duracion_, genero_, calificacion_) {}
#endif