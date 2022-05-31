<?php
include "bd.php";

if (isset($_GET['id'])) {
    $id = $_GET['id'];

    $bd = new BaseDeDatos();
    $bd->removePersonaje($id);
    $ur=2;
    echo'{"usuario:"'.$ur.'}';
}
