<?php 

	require_once "../../FUN/Cn.php";
	require_once "../../Fun/Productos.php";
	$idart=$_POST['idart'];

	echo json_encode(obtenDatosProductos($idart));

 ?>