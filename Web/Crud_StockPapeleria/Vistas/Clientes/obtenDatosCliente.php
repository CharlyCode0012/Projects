<?php 

require_once "../../Fun/Cn.php";
require_once "../../Fun/Clientes.php";


	echo json_encode(obtenDatosCliente($_POST['idcliente']));

 ?>