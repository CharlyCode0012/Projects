package com.example.crud_firebase;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


import com.example.crud_firebase.Datos.PersonajeDAO;
import com.example.crud_firebase.Modelos.Personajes;
import com.example.crud_firebase.Modelos.Usuarios;
import com.google.firebase.FirebaseApp;
import com.google.firebase.database.ChildEventListener;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.UUID;


public class MainActivity extends AppCompatActivity {

    EditText edUsuario, edContrasena;
    Button cmdRegistrar;
    PersonajeDAO connect;

    FirebaseDatabase mDatabase;
    DatabaseReference usersReference;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        connect = new PersonajeDAO(MainActivity.this);
        connect.initializeFireBase();
        if (comprobacionDeAccesoPrevio())
        {
            cambio();
        }
        else
        {
            Button cmdAcceder = (Button) findViewById(R.id.activitymainAcceder);
            cmdRegistrar = (Button) findViewById(R.id.activityMainRegistro);
            edUsuario = (EditText) findViewById(R.id.activitymainNombreUsuario);
            edContrasena = (EditText) findViewById(R.id.activitymainPassword);
            cmdAcceder.setOnClickListener(view -> cmdAccederOnClick());
            cmdRegistrar.setOnClickListener(view -> cmdRegistrarOnClick());
            cmdRegistrar.setEnabled(false);
            cmdRegistrar.setVisibility(View.GONE);
        }



    }

    @Override
    protected void onStart() {

        super.onStart();

    }

    private boolean comprobacionDeAccesoPrevio(){
        SharedPreferences preferences = getSharedPreferences("acceso", Context.MODE_PRIVATE);
        return preferences.getBoolean("valido", false);
    }

    private void cambio() {
        Intent cambio = new Intent(this, Menu.class);
        startActivity(cambio);
    }




    private void cmdAccederOnClick(){
        String nombre, contrasena;

        nombre = edUsuario.getText().toString();
        contrasena = edContrasena.getText().toString();
       if(connect.checkUser(nombre, contrasena)){
           SharedPreferences preferences = getSharedPreferences("acceso", Context.MODE_PRIVATE);
           SharedPreferences.Editor editar = preferences.edit();

           editar.putBoolean("valido", true);

           editar.commit();
           cambio();
       }
       else{
           Toast.makeText(this, "Usuario erroneo", Toast.LENGTH_SHORT).show();
           cmdRegistrar.setEnabled(true);
           cmdRegistrar.setVisibility(View.VISIBLE);
       }

       edUsuario.setText("");
       edContrasena.setText("");
    }

    private void cmdRegistrarOnClick() {
        Intent cambio = new Intent(this,Registro.class);
        startActivity(cambio);
    }
}