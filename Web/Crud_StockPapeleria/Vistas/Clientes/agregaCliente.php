<?php 

session_start();
require_once "../../Fun/Cn.php";
require_once "../../Fun/Clientes.php";



	$datos=array(
			$_POST['nombre'],
			$_POST['apellidos'],
			$_POST['Puntos']
				);

echo agregaCliente($datos);
?>