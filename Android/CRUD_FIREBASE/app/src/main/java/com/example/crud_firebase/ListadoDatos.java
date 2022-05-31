package com.example.crud_firebase;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;

import com.example.crud_firebase.Globales.Generales;
import com.example.crud_firebase.Adaptadores.TarjetaAdapter;
import com.example.crud_firebase.Datos.PersonajeDAO;
import com.example.crud_firebase.Modelos.Personajes;

public class ListadoDatos extends AppCompatActivity {

    RecyclerView rvLista;
    TarjetaAdapter adaptador;
    PersonajeDAO person;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listado_datos);
        person = new PersonajeDAO(ListadoDatos.this);


        rvLista = (RecyclerView) findViewById(R.id.activitylistadodedatosLista);

        LinearLayoutManager vistaHorizontal;

        vistaHorizontal = new LinearLayoutManager
                (this,
                        LinearLayoutManager.VERTICAL,
                        false);

        rvLista.setLayoutManager(vistaHorizontal);

        adaptador = new TarjetaAdapter(this);
        rvLista.setAdapter(adaptador);
    }

    @Override
    protected void onRestart()
    {
        super.onRestart();
    }

    @Override
    protected void onStart()
    {
        super.onStart();
        //Log.d("general", "onStart");
        adaptador.notifyDataSetChanged();
    }
}