package com.example.crud_php;

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

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;



public class MainActivity extends AppCompatActivity {

    EditText edUsuario, edContrasena;
    Button cmdRegistrar;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);



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
        }


    }

    @Override
    protected void onStart() {
        super.onStart();
        cmdRegistrar.setEnabled(false);
        cmdRegistrar.setVisibility(View.GONE);
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

        String url = "http://192.168.100.14/app/ingreso.php?";

        url = url + "usuario=" + nombre;
        url = url + "&password=" + contrasena;

        // http://localhost/app/ingreso.php?usuario=juan&password=1234

        RequestQueue solicitud = Volley.newRequestQueue(this);


        JsonObjectRequest request;

        request = new JsonObjectRequest
                (
                        Request.Method.GET,
                        url,
                        null,
                        new Response.Listener<JSONObject>() // Se logro
                        {
                            @Override
                            public void onResponse(JSONObject response)
                            {
                                int id;
                                try
                                {
                                    id = response.getInt("usuario");
                                    if (id != -1)
                                    {
                                        SharedPreferences preferences = getSharedPreferences("acceso", Context.MODE_PRIVATE);
                                        SharedPreferences.Editor editar = preferences.edit();

                                        editar.putBoolean("valido", true);

                                        editar.commit();

                                        cambio();
                                    }
                                    else
                                    {
                                        edUsuario.setText("");
                                        edContrasena.setText("");

                                        Toast.makeText(MainActivity.this,
                                                "Usuario no valido",
                                                Toast.LENGTH_LONG).show();
                                        cmdRegistrar.setEnabled(true);
                                        cmdRegistrar.setVisibility(View.VISIBLE);

                                    }
                                }
                                catch (JSONException e)
                                {
                                    Log.d("generales", e.getMessage());
                                }
                            }
                        },
                        (VolleyError error) -> { Toast.makeText(this,
                                "Error de conexion",
                                Toast.LENGTH_LONG).show();}

                );

        solicitud.add(request);
    }

    private void cmdRegistrarOnClick() {
        Intent cambio = new Intent(this,Registro.class);
        startActivity(cambio);
    }
}