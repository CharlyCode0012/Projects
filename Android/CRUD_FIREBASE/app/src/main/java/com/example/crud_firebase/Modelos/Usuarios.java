package com.example.crud_firebase.Modelos;

public class Usuarios {
    private String usuario, Pass, id;

    public Usuarios(String usuarios, String pass) {
        this.usuario = usuarios;
        Pass = pass;
    }

    public Usuarios() {

    }

    public void setId(String id) {
        this.id = id;
    }

    public void setUsuario(String usuarios) {
        this.usuario = usuarios;
    }

    public void setPass(String pass) {
        Pass = pass;
    }

    public String getId() {
        return id;
    }

    public String getUsuario() {
        return usuario;
    }

    public String getPass() {
        return Pass;
    }
}

