package com.example.crud_firebase.Datos;
import android.content.Context;
import android.content.SharedPreferences;
import android.util.Log;
import android.view.View;
import android.view.inputmethod.InputMethodSession;
import android.widget.Toast;


import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.example.crud_firebase.Globales.Generales;
import com.example.crud_firebase.MainActivity;
import com.example.crud_firebase.Modelos.Personajes;
import com.example.crud_firebase.Modelos.Usuarios;
import com.google.firebase.FirebaseApp;
import com.google.firebase.database.ChildEventListener;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.Query;
import com.google.firebase.database.ValueEventListener;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.Map;
import java.util.UUID;

public class PersonajeDAO {

    FirebaseDatabase mDatabase;
    DatabaseReference dbReference;
    private String id, name, edad, altura, genero, videojuego;
    private Context context;
    private boolean usFlag = false;



    public PersonajeDAO(){
        mDatabase = FirebaseDatabase.getInstance();
    }

    public PersonajeDAO(Context context) {

        mDatabase = FirebaseDatabase.getInstance();
        this.context = context;

    }


    public PersonajeDAO(String name, String edad, String altura, String genero, String videojuego) {
        this.name = name;
        this.edad = edad;
        this.altura = altura;
        this.genero = genero;
        this.videojuego = videojuego;
    }


    public void setName(String name) {
        this.name = name;
    }

    public void setEdad(String edad) {
        this.edad = edad;
    }

    public void setAltura(String altura) {
        this.altura = altura;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public void setVideojuego(String videojuego) {
        this.videojuego = videojuego;
    }

    public void setContext(Context context) {
        this.context = context;
    }

    public String getName() {
        return name;
    }

    public String getEdad() {
        return edad;
    }

    public String getAltura() {
        return altura;
    }

    public String getGenero() {
        return genero;
    }

    public String getVideojuego() {
        return videojuego;
    }


    public void deletePersonaje(Personajes personaje) {
        dbReference.child("Personajes").child(personaje.getId()).removeValue();
    }

    public void readPersonaje() {

        dbReference.child("Personajes").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                Generales.personajes.clear();

                for(DataSnapshot objectSnapshot : snapshot.getChildren()) {
                    Personajes person = objectSnapshot.getValue(Personajes.class);
                    Generales.personajes.add(person);
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

    }



    public void createPersonaje(Personajes person) {
        dbReference.child("Personajes").child(person.getId()).setValue(person);

    }

    public void setUser(Usuarios user1){
        dbReference.child("Usuarios").child(user1.getId()).setValue(user1);
    }

    public boolean checkUser(String user, String password) {

        dbReference.child("Usuarios").addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                Generales.usuarios.clear();

                for(DataSnapshot objectSnapshot : snapshot.getChildren()) {
                    Usuarios user1 = objectSnapshot.getValue(Usuarios.class);
                    Generales.usuarios.add(user1);
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });

        for(Usuarios item : Generales.usuarios){
            if (item.getUsuario().equals(user) && item.getPass().equals(password)) {
                usFlag = true;
                break;
            }
            else{
                usFlag = false;
            }
        }
        return usFlag;
    }



    public void initializeFireBase(){
        FirebaseApp.initializeApp(context);
        mDatabase =  FirebaseDatabase.getInstance();
        dbReference  = mDatabase.getReference();
    }

}
