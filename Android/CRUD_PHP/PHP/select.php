<?php
include "bd.php";

if(isset($_GET['nombre']) && isset($_GET['genero']) && isset($_GET['edad']) && isset($_GET['altura']) && isset($_GET['video']) && isset($_GET['flag']))
{
    $nomb = $_GET['nombre'];
    $gene = $_GET['genero'];
    $edad = $_GET['edad'];
    $alt = $_GET['altura'];
    $videojuego = $_GET['video'];
    //$img = $_GET['img'];
    
    $flag = $_GET['flag'];
    $res = 2;
    $bd = new BaseDeDatos();

    if($flag === "true"){
        $bd->addPersonaje($nomb, $gene, $edad, $alt, $videojuego);
    }
    else{
        $bd->updatePersonaje($nomb, $gene, $edad, $alt, $videojuego, $flag);
    } 

    echo '{"usuario":'.$res.'}';
}
