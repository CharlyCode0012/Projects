package com.example.crud_firebase.Adaptadores;

import android.content.Context;
import android.content.Intent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.crud_firebase.Globales.Generales;
import com.example.crud_firebase.R;
import com.example.crud_firebase.TarjetaUsuario;
import com.mikhaellopez.circularimageview.CircularImageView;
import com.squareup.picasso.Picasso;

public class TarjetaAdapter extends RecyclerView.Adapter<TarjetaAdapter.TarjetaHolder> {

    Context contexto;

    public TarjetaAdapter(Context contexto)
    {
        this.contexto = contexto;
    }

    @NonNull
    @Override
    public TarjetaHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType)
    {
        View v = View.inflate(contexto, R.layout.tarjeta, null);
        return new TarjetaHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull TarjetaHolder holder, int position)
    {
        holder.tvNombre.setText(Generales.personajes.get(position).getNombre());
        holder.tvEdad.setText("" + Generales.personajes.get(position).getEdad());

        Picasso
                .get()
                .load("http://192.168.100.14/imagenes/dante.png")
                .into(holder.ivFoto);

        holder.tvNombre.setOnClickListener(view ->
        {
            Intent cambio = new Intent(contexto, TarjetaUsuario.class);
            cambio.putExtra("posicion",position);
            contexto.startActivity(cambio);
            Toast.makeText(contexto, Generales.personajes.get(position).getId()+"", Toast.LENGTH_SHORT).show();
        });

    }

    @Override
    public int getItemCount() {
        return Generales.personajes.size();
    }

    class TarjetaHolder extends RecyclerView.ViewHolder
    {
        TextView tvNombre;
        TextView tvEdad;
        CircularImageView ivFoto;

        public TarjetaHolder(@NonNull View itemView)
        {
            super(itemView);

            tvNombre = (TextView) itemView.findViewById(R.id.tarjetaNombre);
            tvEdad = (TextView) itemView.findViewById(R.id.tarjetaEdad);
            ivFoto = (CircularImageView) itemView.findViewById(R.id.tarjetaFoto);

        }
    }
}