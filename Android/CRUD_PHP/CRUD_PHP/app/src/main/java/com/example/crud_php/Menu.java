package com.example.crud_php;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

import com.example.crud_php.datos.PersonaDAO;

public class Menu extends AppCompatActivity {
    PersonaDAO  person = new PersonaDAO();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        Button cmdAgregar, cmdVer;

        cmdAgregar = (Button) findViewById(R.id.activityMenuAltas);
        cmdVer = (Button) findViewById(R.id.activityMenuVer);

        cmdVer.setOnClickListener(View-> cambio(true));
        cmdAgregar.setOnClickListener(View-> cambio(false));


    }
    private void cambio(boolean flag) {
        Intent intent;
        if(flag){
            intent = new Intent(this, ListadoDatos.class );
            person.setContext(Menu.this);
            person.readPersonaje();

        }

        else
            intent = new Intent(this, Altas.class );
        startActivity(intent);
    }
}