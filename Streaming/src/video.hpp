#ifndef video_h
#define video_h

#include <string>

class Video
{
    protected:
        int id;
        std::string nombre;
        float duracion;
        std::string genero;
        float calificacion;
        float tuCalificacion;

    public:

        // Setters
        void setId(int id_);
        void setNombre(std::string nombre_);
        void setDuracion(float duracion_);
        void setGenero(std::string genero_);
        void setCalificacion(float calificacion_);
        void calificar(float calificacion_);

        // Getters
        int getId();
        std::string getNombre();
        float getDuracion();
        std::string getGenero();
        float getCalificacion();
        float getTuCalificacion();

        // Constructors
        Video();
        Video(int id_, std::string nombre_, float duracion_, std::string genero_, float calificacion_);
};


void Video::setId(int id_)
{
    if (id_ > 0)
    {
        id = id_;
    }
}

void Video::setNombre(std::string nombre_)
{
    if (islower(nombre_[0]))
    {
        nombre_[0] = toupper(nombre_[0]);
    }

    nombre = nombre_;
}

void Video::setDuracion(float duracion_)
{
    if (duracion_ > 0)
    {
        duracion = duracion_;
    }
}

void Video::setGenero(std::string genero_)
{
    int n = genero_.length();
    genero_[0] = toupper(genero_[0]);
    
    if (genero_ == "Drama" || genero_ == "Accion" || genero_ == "Misterio")
    {
        genero = genero_;
    }
}

void Video::setCalificacion(float calificacion_)
{
    if ((calificacion_ >= 1) && (calificacion_ <= 5))
    {
        calificacion = calificacion_;
    }
}

void Video::calificar(float calificacion_)
{
    if ((calificacion_ >= 1) && (calificacion_ <= 5))
    {
        tuCalificacion = calificacion_;
    }
}

int Video::getId()
{
    return id;
}

std::string Video::getNombre()
{
    return nombre;   
}

float Video::getDuracion()
{
    return duracion;
}

std::string Video::getGenero()
{
    return genero;
}

float Video::getCalificacion()
{
    return calificacion;
}

float Video::getTuCalificacion()
{
    return tuCalificacion;
}

Video::Video()
{
    id = 0;
    nombre = "\0";
    duracion = 0;
    genero = "NA";
    calificacion = 0;
    tuCalificacion = 0;
}

Video::Video(int id_, std::string nombre_, float duracion_, std::string genero_, float calificacion_)
{
    setId(id_);
    setNombre(nombre_);
    setGenero(genero_);
    setCalificacion(calificacion_);
    tuCalificacion = 0;
}
#endif