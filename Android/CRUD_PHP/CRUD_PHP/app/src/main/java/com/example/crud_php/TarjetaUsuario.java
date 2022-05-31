package com.example.crud_php;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.text.InputType;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.crud_php.Globlales.Generales;
import com.example.crud_php.datos.PersonaDAO;
import com.example.crud_php.modelos.Persona;

public class TarjetaUsuario extends AppCompatActivity {
    EditText etNombre, etGenero, etAltura, etVideoJuego, etEdad;

    Button cmdModificar , cmdEliminar;
    PersonaDAO person = new PersonaDAO();
    int pos;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tarjeta_usuario);

        //Generales.personas.add(new Persona("a1","a2",130,19,"halo"));
        person.setContext(TarjetaUsuario.this);
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
            Persona lol = Generales.personas.get(pos);
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
            Persona persona;
            persona = Generales.personas.get(pos);

            persona.setNombre(etNombre.getText().toString());
            persona.setGenero(etGenero.getText().toString());
            persona.setAltura(Integer.parseInt(etAltura.getText().toString()));
            persona.setEdad(Integer.parseInt(etEdad.getText().toString()));
            persona.setVideojuego(etVideoJuego.getText().toString());
            person.cuPersonaje(persona.getNombre(), persona.getGenero(), persona.getEdad()+"", persona.getAltura()+"", persona.getVideojuego(), persona.getId()+"");

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

                                        person.deletePersonaje(Generales.personas.get(pos).getId()+"");
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