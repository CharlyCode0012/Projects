<?php
include "bd.php";

$query = "SELECT * FROM personajes";
$array1 = array();
$bd = new BaseDeDatos();
$array1 = $bd->consulta($query);

/*foreach ($array1 as $value) {
    echo '{
             "id: "' . $value->id . '
             "nombre:"' . $value->nombre . ',
             "genero:"' . $value->genero . ',
             "edad:"' . $value->edad . ',
             "altura:"' . $value->altura . ',
             "videojuego:"' . $value->videojuego . '
            },
            ';
    //echo json_encode($value);
}*/
echo json_encode($array1);

