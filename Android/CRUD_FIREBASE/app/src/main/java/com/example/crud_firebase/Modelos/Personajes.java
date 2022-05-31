package com.example.crud_firebase.Modelos;

public class Personajes
{
    private String nombre, genero, id, altura, edad, videojuego;

//

    public Personajes(){

    }
    public Personajes(String nombre, String genero, String altura, String edad, String videojuego,String id) {
        this.nombre = nombre;
        this.genero = genero;
        this.altura = altura;
        this.edad = edad;
        this.videojuego = videojuego;
        this.id = id;
    }

    public Personajes(String nombre, String genero, String altura, String edad, String videojuego) {
        this.nombre = nombre;
        this.genero = genero;
        this.altura = altura;
        this.edad = edad;


    }

    public String getNombre() {
        return nombre;
    }

    public String getGenero() {
        return genero;
    }

    public String getAltura() {
        return altura;
    }

    public String getEdad() {
        return edad;
    }

    public String getVideojuego() {
        return videojuego;
    }

    public String getId() {
        return id;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public void setAltura(String altura) {
        this.altura = altura;
    }

    public void setEdad(String edad) {
        this.edad = edad;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setVideojuego(String videojuego) {
        this.videojuego = videojuego;
    }
}

