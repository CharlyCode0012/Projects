<?php 
	session_start();
	$iduser=$_SESSION['iduser'];
	require_once "../../Fun/Cn.php";
	require_once "../../Fun/Productos.php";
	    
	$Q1="SELECT PK_Id_Prod FROM Producto ORDER BY PK_Id_Prod DESC Limit 1";
	$result=mysqli_query($conn,$Q1);
	$Id_Prod=mysqli_fetch_row($result);
	$Id_Prod[0]= $Id_Prod[0]+1;
	mysqli_free_result($result);
	$Nombre=$_POST['marca'];

	$Q2="SELECT PK_Id_Marca FROM Marca WHERE Nom_Marc='$Nombre'";
	$R=mysqli_query($cnn,$Q2);
	$Id_Marc=mysqli_fetch_row($R);
	mysqli_free_result($R);
	$datos=array();
	$datos[0]=$Id_Prod[0];
	$datos[3]=$_POST['cantidad'];
	$datos[4]=$_POST['precio'];
	$datos[5]=$_POST['descripcion'];
	$datos[6]=$Id_Marc[0];
	echo insertaProductos1($datos);

 ?>