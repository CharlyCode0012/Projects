<?php 



require_once "../../Fun/Conexion.php";
require_once "../../Fun/Productos.php";
$idart=$_POST['idProd'];
	echo eliminaProductos($idart);

 ?>