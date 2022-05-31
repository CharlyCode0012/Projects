<?php 

session_start();
require_once "../../Fun/Cn.php";
require_once "../../Fun/Clientes.php";

	$datos=array(
			$_POST['idclienteU'],
			$_POST['nombreU'],
			$_POST['apellidosU'],
			$_POST['PuntosU']
				);

	echo actualizaCliente($datos);

	
	
 ?>