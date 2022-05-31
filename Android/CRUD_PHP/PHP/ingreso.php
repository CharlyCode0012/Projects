<?php
include "bd.php";

if(isset($_GET['usuario']) && isset($_GET['password']))
{
    $usr = $_GET['usuario'];
    $pass = $_GET['password'];
    
    $bd = new BaseDeDatos();
    $res = $bd->validar_usuario($usr,$pass);
    
    echo '{"usuario":'.$res.'}';
}
