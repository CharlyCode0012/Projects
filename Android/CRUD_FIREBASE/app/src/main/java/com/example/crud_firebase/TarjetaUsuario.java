package com.example.crud_firebase;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.example.crud_firebase.Globales.Generales;
import com.example.crud_firebase.Datos.PersonajeDAO;
import com.example.crud_firebase.Modelos.Personajes;

public class TarjetaUsuario extends AppCompatActivity {
    EditText etNombre, etGenero, etAltura, etVideoJuego, etEdad;

    Button cmdModificar , cmdEliminar;
    PersonajeDAO person = new PersonajeDAO();
    int pos;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tarjeta_usuario);

        //Generales.personas.add(new Persona("a1","a2",130,19,"halo"));
        person.setContext(TarjetaUsuario.this);
        person.initializeFireBase();
        etNombre = (EditText) findViewById(R.id.activityTarjetaDeUsuarioNombre);
        etGenero = (EditText) findViewById(R.id.activityTarjetaDeUsuarioGenero);
        etEdad = (EditText) findViewById(R.id.activityTarjetaDeUsuarioEdad);
        etAltura = (EditText) findViewById(R.id.activityTarjetaDeUsuarioAltura);
        etVideoJuego = (EditText) findViewById( R.id.activityTarjetaDeUsuarioVideoJ);

        cmdModificar = (Button) findViewById(R.id.activitytarjetadeusuarioModificar);
        cmdEliminar = (Button) findViewById(R.id.activitytarjetadeusuarioEliminar);

        pos = getIntent().getIntExtra("posicion", -1);
        if (pos == -1)
        {
            /* Mostrar error */
        }
        else
        {
            Personajes lol = Generales.personajes.get(pos);
            etNombre.setText(lol.getNombre());
            etGenero.setText(lol.getGenero());
            etEdad.setText(""+lol.getEdad());
            etAltura.setText(""+lol.getAltura());
            etVideoJuego.setText(lol.getVideojuego());

            statusEditText(false);
        }

        cmdModificar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                cmdModificarOnclick();
            }
        });
        cmdEliminar.setOnClickListener(view -> {cmdEliminarOnclick();});

    }

    public void cmdModificarOnclick()
    {
        if (cmdModificar.getText().toString().equals("Modificar"))
        {
            statusEditText(true);
            cmdModificar.setText("Guardar");
        }
        else
        {
            Personajes personaje;
            personaje = Generales.personajes.get(pos);
            personaje.setId(Generales.personajes.get(pos).getId());
            personaje.setNombre(etNombre.getText().toString());
            personaje.setGenero(etGenero.getText().toString());
            personaje.setAltura(etAltura.getText().toString());
            personaje.setEdad(etEdad.getText().toString());
            personaje.setVideojuego(etVideoJuego.getText().toString());
            //person.createPersonaje(personaje);
            person.createPersonaje(personaje);
            cmdModificar.setText("Modificar");
            statusEditText(false);
        }
    }

    private void statusEditText(boolean status)
    {

        etNombre.setEnabled(status);
        etGenero.setEnabled(status);
        etAltura.setEnabled(status);
        etVideoJuego.setEnabled(status);
        etEdad.setEnabled(status);


    }

    private void cmdEliminarOnclick()
    {
        AlertDialog.Builder confirmarEliminacion = new AlertDialog.Builder(this);

        confirmarEliminacion
                .setMessage(R.string.confirmar)
                .setPositiveButton
                        (
                                R.string.afirmativo,
                                new DialogInterface.OnClickListener()
                                {
                                    @Override
                                    public void onClick(DialogInterface dialogInterface, int i)
                                    {

                                        person.deletePersonaje(Generales.personajes.get(pos));
                                        Intent intent = new Intent(TarjetaUsuario.this, Menu.class);
                                        startActivity(intent);
                                    }
                                }
                        )
                .setNegativeButton
                        (
                                R.string.cancelar,
                                (DialogInterface dialogInterface, int i) -> { }
                        );

        confirmarEliminacion.create();
        confirmarEliminacion.show();


    }
}