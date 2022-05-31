package com.example.crud_php.modelos;

public class Persona
{
    private String nombre;
    private String genero;
    private int altura;
    private int edad, id;
    public int index;
    private String videojuego;
    private static int contador = 0;
//

    public Persona(){

    }
    public Persona(String nombre, String genero, int altura, int edad, String videojuego,int id) {
        this.nombre = nombre;
        this.genero = genero;
        this.altura = altura;
        this.edad = edad;
        this.videojuego = videojuego;
        this.id = id;
    }

    public Persona(String nombre, String genero, int altura, int edad, String videojuego) {
        this.nombre = nombre;
        this.genero = genero;
        this.altura = altura;
        this.edad = edad;
        this.videojuego = videojuego;
    }

    public String getNombre() {
        return nombre;
    }

    public String getGenero() {
        return genero;
    }

    public int getAltura() {
        return altura;
    }

    public int getEdad() {
        return edad;
    }

    public String getVideojuego() {
        return videojuego;
    }

    public int getId() {
        return id;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public void setAltura(int altura) {
        this.altura = altura;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setVideojuego(String videojuego) {
        this.videojuego = videojuego;
    }
}
