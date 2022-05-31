package com.example.crud_php;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.crud_php.Globlales.Generales;
import com.example.crud_php.datos.PersonaDAO;
import com.example.crud_php.modelos.Persona;

public class Altas extends AppCompatActivity {

    EditText etNombre, etGenero, etAltura, etVideoJuego, etEdad;
    Button cmdGuardar;
    PersonaDAO person = new PersonaDAO();

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_altas);

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
        person.setUrl("select.php?nombre="+nombre+"&genero="+genero+"&edad="+edad+"&altura="+altura+"&video="+vj+"&flag="+true);
        person.setContext(Altas.this);
        //person.cuPersonaje(nombre, genero, edad, altura, vj, "-"+1);
        person.connect();
        etNombre.setText("");
        etGenero.setText("");
        etAltura.setText("");
        etVideoJuego .setText("");
        etEdad .setText("");
        Intent intent = new Intent(Altas.this, Menu.class);
        startActivity(intent);
    }
}