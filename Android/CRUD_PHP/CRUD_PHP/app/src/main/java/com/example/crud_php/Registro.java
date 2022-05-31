package com.example.crud_php;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.crud_php.datos.PersonaDAO;

public class Registro extends AppCompatActivity {


    EditText edUserName, edContra1, edContra2;
    PersonaDAO person = new PersonaDAO();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_rgistro);

        Button cmdGuardar;
        cmdGuardar = (Button) findViewById(R.id.activityRegistroGuardar);

        edUserName = (EditText) findViewById(R.id.activityRegistroNombre);
        edContra1 = (EditText) findViewById(R.id.activityRegistroContraseña);
        edContra2= (EditText) findViewById(R.id.activityRegistroConfirmar);

        cmdGuardar.setOnClickListener(view -> guardarOnClick());

    }

    private void guardarOnClick() {
        String name, contrasenia, contra1;

        name = edUserName.getText().toString();
        contrasenia = edContra1.getText().toString();
        contra1 = edContra2.getText().toString();


        if(name.isEmpty() || contrasenia.isEmpty() || contra1.isEmpty())
            Toast.makeText(this, "Debe de llenar todos los campos", Toast.LENGTH_SHORT).show();
        else
        {
            if(contrasenia.equals(contra1)){
                person.setUrl("registro.php?usuario="+name+"&password="+contrasenia);
                person.setContext(Registro.this);
                person.connect();
            }
            else{
                Toast.makeText(this, "Las contraseñas deben ser iguales", Toast.LENGTH_SHORT).show();
            }
        }


    }
}