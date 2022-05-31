package com.example.crud_php.datos;

import android.content.Context;
import android.content.SharedPreferences;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonArrayRequest;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.Volley;
import com.example.crud_php.Globlales.Generales;
import com.example.crud_php.MainActivity;
import com.example.crud_php.modelos.Persona;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.Map;

public class PersonaDAO {

    private String url = "http://192.168.100.14/app/";
    private String url1 = "http://192.168.100.14/app/";
    private String name, edad, altura, genero, videojuego;
    private Context context;

    public PersonaDAO() {
    }

    public PersonaDAO(String url, String name, String edad, String altura, String genero, String videojuego) {
        this.url += url;
        this.name = name;
        this.edad = edad;
        this.altura = altura;
        this.genero = genero;
        this.videojuego = videojuego;
    }

    public PersonaDAO(String name, String edad, String altura, String genero, String videojuego) {
        this.name = name;
        this.edad = edad;
        this.altura = altura;
        this.genero = genero;
        this.videojuego = videojuego;
    }

    public void setUrl(String url) {
        this.url = this.url + url;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setEdad(String edad) {
        this.edad = edad;
    }

    public void setAltura(String altura) {
        this.altura = altura;
    }

    public void setGenero(String genero) {
        this.genero = genero;
    }

    public void setVideojuego(String videojuego) {
        this.videojuego = videojuego;
    }

    public void setContext(Context context) {
        this.context = context;
    }

    public String getUrl() {
        return url;
    }

    public String getName() {
        return name;
    }

    public String getEdad() {
        return edad;
    }

    public String getAltura() {
        return altura;
    }

    public String getGenero() {
        return genero;
    }

    public String getVideojuego() {
        return videojuego;
    }


    public void deletePersonaje(String id) {
        //resetUrl();
        this.url = this.url + "delete.php?";
        this.url = this.url + "id=" + id;
        connect();
    }

    public void readPersonaje() {
        resetUrl();
        this.url = this.url + "read.php?";

        RequestQueue solicitud = Volley.newRequestQueue(context);
        Toast.makeText(context, url, Toast.LENGTH_LONG).show();

        JsonArrayRequest request;
        Generales.personas.clear();
        request = new JsonArrayRequest
                (
                        Request.Method.GET,
                        url, null,
                        new Response.Listener<JSONArray>() // Se logro
                        {


                            @Override
                            public void onResponse(JSONArray response)
                            {

                                    for(int i=0;i<response.length();i++){
                                        // Get current json object

                                        try {
                                            JSONObject character = new JSONObject(response.get(i).toString());

                                            // Get the current student (json object) data
                                            int id = Integer.parseInt(character.getString("id"));
                                            String name = character.getString("nombre");
                                            String genero =character.getString("genero");
                                            int age = Integer.parseInt(character.getString("edad"));
                                            int altura = Integer.parseInt(character.getString("altura"));
                                            String videojuego = character.getString("videojuego");
                                            Generales.personas.add(new Persona(name, genero, altura, age, videojuego, id));

                                        }  catch (JSONException e)
                                        {
                                            Log.d("generales", e.getMessage());
                                            Toast.makeText(context,
                                                    "Error de array",
                                                    Toast.LENGTH_LONG).show();
                                        }
                                    }
                            }
                        },
                        (VolleyError error) -> { Toast.makeText(context,
                                "Error de conexion",
                                Toast.LENGTH_LONG).show();}

                );

        solicitud.add(request);

//arrayrequest
    }



    public void cuPersonaje(String name, String genero, String edad, String altura, String videojuego, String id) {
        this.url = this.url + "select.php?";
        this.url = this.url + "nombre=" + name;
        this.url = this.url + "&genero=" + genero;
        this.url = this.url + "&edad=" + edad;
        this.url = this.url + "&altura=" + altura;
        this.url = this.url + "&video=" + videojuego;
        this.url = this.url + "&flag=" +id;//-1 create
        connect();
    }

    public void connect (){

        RequestQueue solicitud = Volley.newRequestQueue(context);

        JsonObjectRequest request;
        Toast.makeText(context, url, Toast.LENGTH_LONG).show();

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
                                        Toast.makeText(context,
                                                "LOGRADO!",
                                                Toast.LENGTH_LONG).show();
                                    }
                                    else
                                    {

                                        Toast.makeText(context,
                                                "Usuario no valido",
                                                Toast.LENGTH_LONG).show();

                                    }
                                }
                                catch (JSONException e)
                                {
                                    Log.d("generales", e.getMessage());
                                }
                            }
                        },
                        (VolleyError error) -> { }

                );

        solicitud.add(request);
        resetUrl();
    }

    private void resetUrl(){
        url = url1;
    }

}
