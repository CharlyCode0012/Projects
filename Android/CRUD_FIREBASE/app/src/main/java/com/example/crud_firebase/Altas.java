package com.example.crud_firebase;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.crud_firebase.Datos.PersonajeDAO;
import com.example.crud_firebase.Globales.Generales;
import com.example.crud_firebase.Datos.PersonajeDAO;
import com.example.crud_firebase.Modelos.Personajes;

import java.util.UUID;

public class Altas extends AppCompatActivity {

    EditText etNombre, etGenero, etAltura, etVideoJuego, etEdad;
    Button cmdGuardar;
    Personajes personaje;
    PersonajeDAO person = new PersonajeDAO(Altas.this);

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_altas);

        person.initializeFireBase();
        etNombre = (EditText) findViewById(R.id.activityAltasNombre);
        etGenero = (EditText) findViewById(R.id.activityAltasGenero);
        etEdad = (EditText) findViewById(R.id.activityAltasEdad);
        etAltura = (EditText) findViewById(R.id.activityAltasAltura);
        etVideoJuego = (EditText) findViewById( R.id.activityAltasVideoJ);

        cmdGuardar = (Button) findViewById(R.id.activityAltasGuardar);
        cmdGuardar.setOnClickListener((View view) -> { guardar(); });


    }

    public void guardar() {
        String nombre,genero, edad, altura, vj;
        nombre =etNombre.getText().toString();
        genero = etGenero.getText().toString();
        edad = etEdad.getText().toString();
        altura = etAltura.getText().toString();
        vj = etVideoJuego.getText().toString();

        if(nombre.isEmpty() || genero.isEmpty() || vj.isEmpty() || edad.isEmpty() || altura.isEmpty()) {
            Toast.makeText(this, "Llene todos los campos", Toast.LENGTH_SHORT).show();
            return;
        }
        setPersonaje(nombre, genero, edad, altura, vj);
        person.createPersonaje(personaje);

        etNombre.setText("");
        etGenero.setText("");
        etAltura.setText("");
        etVideoJuego .setText("");
        etEdad .setText("");
        Intent intent = new Intent(Altas.this, Menu.class);
        startActivity(intent);
    }


    public void setPersonaje(String name, String genero, String edad, String altura, String videoJuego){
        personaje = new Personajes();
        personaje.setId(UUID.randomUUID().toString());
        personaje.setEdad(edad);
        personaje.setAltura(altura);
        personaje.setVideojuego(videoJuego);
        personaje.setNombre(name);
        personaje.setGenero(genero);
    }
}