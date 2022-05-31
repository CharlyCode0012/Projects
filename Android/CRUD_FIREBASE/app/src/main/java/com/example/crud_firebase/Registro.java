package com.example.crud_firebase;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.crud_firebase.Datos.PersonajeDAO;
import com.example.crud_firebase.Modelos.Personajes;
import com.example.crud_firebase.Modelos.Usuarios;
import com.google.firebase.FirebaseApp;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

import java.util.UUID;

public class Registro extends AppCompatActivity {


    EditText edUserName, edContra1, edContra2;
    PersonajeDAO person = new PersonajeDAO();
    Usuarios user1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_registro);

        Button cmdGuardar;
        cmdGuardar = (Button) findViewById(R.id.activityRegistroGuardar);

        edUserName = (EditText) findViewById(R.id.activityRegistroNombre);
        edContra1 = (EditText) findViewById(R.id.activityRegistroContraseña);
        edContra2 = (EditText) findViewById(R.id.activityRegistroConfirmar);

        cmdGuardar.setOnClickListener(view -> guardarOnClick());

        person.setContext(Registro.this);
        person.initializeFireBase();

    }

    private void guardarOnClick() {
        String name, contrasenia, contra1;

        name = edUserName.getText().toString();
        contrasenia = edContra1.getText().toString();
        contra1 = edContra2.getText().toString();

        if (name.isEmpty() || contrasenia.isEmpty() || contra1.isEmpty())
            Toast.makeText(this, "Debe de llenar todos los campos", Toast.LENGTH_SHORT).show();
        else {
            if (contrasenia.equals(contra1)) {
                user1 = new Usuarios();
                setUser1(name, contrasenia);
                person.setUser(user1);
            } else {
                Toast.makeText(this, "Las contraseñas deben ser iguales", Toast.LENGTH_SHORT).show();
            }
        }
        edUserName.setText("");
        edContra1.setText("");
        edContra2.setText("");
        onBackPressed();
    }

    public void setUser1(String name, String pass){
        user1.setId(UUID.randomUUID().toString());
        user1.setPass(pass);
        user1.setUsuario(name);
    }


}
