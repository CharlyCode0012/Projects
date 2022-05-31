package com.example.crud_firebase;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import com.example.crud_firebase.Datos.PersonajeDAO;


public class Menu extends AppCompatActivity {
    PersonajeDAO  person;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        Button cmdAgregar, cmdVer;

        cmdAgregar = (Button) findViewById(R.id.activityMenuAltas);
        cmdVer = (Button) findViewById(R.id.activityMenuVer);

        cmdVer.setOnClickListener(View-> cambio(true));
        cmdAgregar.setOnClickListener(View-> cambio(false));
        person = new PersonajeDAO(Menu.this);
        person.initializeFireBase();

    }
    private void cambio(boolean flag) {
        Intent intent = null;
        if(flag){
            intent = new Intent(this, ListadoDatos.class );
            person.readPersonaje();
        }

        else
            intent = new Intent(this, Altas.class );
        startActivity(intent);
    }
}