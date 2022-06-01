#ifndef episodio_h
#define episodio_h

#include <vector>
#include <string>

#include "video.hpp"

class Episodio: public Video
{
    private:
        std::string serie;
        int numeroEpisodio;
        int temporada;

    public:
        // Setters
        void setSerie(std::string serie_);
        void setNumeroEpisodio(int numero);
        void setTemporada(int temporada_);

        // Getters
        std::string getSerie();
        int getNumeroEpisodio();
        int getTemporada();

        // Constructors
        Episodio();
        Episodio(int id_, std::string serie_, int numero, std::string nombre_, int temporada_, float duracion_, std::string genero_, float calificacion_);
};


void Episodio::setSerie(std::string serie_)
{
    serie_[0] = toupper(serie_[0]);

    int n = serie_.length();

    for (int i = 1; i < n; i++)
    {
        if (serie_[i-1] == ' ')
        {
            serie_[i]=toupper(serie_[i]);
        }
    }

    serie = serie_;
}

void Episodio::setNumeroEpisodio(int numero)
{
    if (numero > 0)
    {
        numeroEpisodio = numero;
    }
}

void Episodio::setTemporada(int temporada_)
{
    if (temporada_ > 0)
    {
        temporada = temporada_;
    }
}

std::string Episodio::getSerie()
{
    return serie;
}

int Episodio::getNumeroEpisodio()
{
    return numeroEpisodio;
}

int Episodio::getTemporada()
{
    return temporada;
}

Episodio::Episodio(): Video()
{
    serie = "NA";
    numeroEpisodio = 0;
    temporada = 0;
}

Episodio::Episodio(int id_, std::string serie_, int numero, std::string nombre_, int temporada_, float duracion_, std::string genero_, float calificacion_): Video(id_, nombre_, duracion_, genero_, calificacion_)
{
    setSerie(serie_);
    setNumeroEpisodio(numero);
    setTemporada(temporada_);
}

#endif