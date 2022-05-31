<?php 


require_once "../../Fun/Cn.php";
require_once "../../Fun/Productos.php";

$datos=array(
		$_POST['idProductos'],
	    $_POST['cantidadU'],
	    $_POST['descripcionU'],
	    $_POST['precioU'],
	    $_POST['marcaU'],
			);
    echo actualizaProductos($datos);
 ?>