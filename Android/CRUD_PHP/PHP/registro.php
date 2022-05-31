<?php
include "bd.php";
if(isset($_GET['usuario']) && isset($_GET['password']))
{
    $usr = $_GET['usuario'];
    $pass = $_GET['password'];
    
    $bd = new BaseDeDatos();
    $bd->registro($usr,$pass);

    $res=2;
    
    echo '{"usuario":'.$res.'}';
}