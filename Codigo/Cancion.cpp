#include "Cancion.hpp"

Cancion::Cancion(string idInterno,string nombreCancion,string nombreArtista,string nombreAlbum,int anio,int duracionSegundos,string ubicacionArchivo){
    this->idInterno=idInterno;
    this->nombreCancion=nombreCancion;
    this->nombreArtista=nombreArtista;
    this->nombreAlbum=nombreAlbum;
    this->anio=anio;
    this->duracionSegundos=duracionSegundos;
    this->ubicacionArchivo=ubicacionArchivo;
}
string Cancion::getId(){
    return this->idInterno;
}
string Cancion::getNombreCancion(){
    return this->nombreCancion;
}
string Cancion::getArtista(){
    return this->nombreArtista;
}
string Cancion::getAlbum(){
    return this->nombreAlbum;
}
int Cancion::getAnio(){
    return this->anio;
}
string Cancion::getDuracion(){
    int minutos = this->duracionSegundos/60;
    int segundos = this->duracionSegundos%60;
    return  to_string(minutos)+":"+to_string(segundos);
}
string Cancion::getUbicacion(){
    return this->ubicacionArchivo;
}
void Cancion::setUbicacion(string ubicacionArchivo){
    this->ubicacionArchivo=ubicacionArchivo;
}
Cancion::~Cancion(){

}