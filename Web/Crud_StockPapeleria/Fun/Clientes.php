<?php 

	
		function agregaCliente($datos){
			require("Cn.php");
			$idusuario=$_SESSION['iduser'];

			$sql="INSERT into cliente (PK_Id_Cli, Nom_C, Ape1_C, Puntos)
				  values ('$idusuario', '$datos[0]', '$datos[1]', '$datos[2]')";
			return mysqli_query($conn,$sql);	
		}

		function obtenDatosCliente($idcliente){
			require("Cn.php");
			$sql="SELECT * FROM Cliente";
			$result=mysqli_query($conn,$sql);
			$ver=mysqli_fetch_row($result);

			$datos=array(
					'id_cliente' => $ver[0], 
					'nombre' => $ver[1],
					'apellido' => $ver[2],
					'Puntos' => $ver[3],
						);
			return $datos;
		}

		function actualizaCliente($datos){
			require("Cn.php");
			$sql="UPDATE Cliente set Nom_C='$datos[1]', Ape1_C='$datos[2]', Puntos='$datos[3]' where PK_Id_Cli='$datos[0]'";
			return mysqli_query($conn,$sql);
		}

		function eliminaCliente($idcliente){
			require("Cn.php");

			$sql="DELETE from Cliente where PK_Id_Cli='$idcliente'";

			return mysqli_query($conexion,$sql);
		}
	

 ?>