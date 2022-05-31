

<?php 

		function insertaProductos1($datos){
			require("Cn.php");

			$sql="INSERT into Producto (Pk_Id_Prod,
										No_Exis,
										Precio,
										Descripcion,
										FK_Id_Marca,
							values ('$datos[0]',
									'$datos[1]',
									'$datos[2]',
									'$datos[3]',
									'$datos[4]')";
			return mysqli_query($conn,$sql);
		}

		function obtenDatosProductos($idProductos){
			require("Cn.php");
			$sql="SELECT Producto(*), Marca.Nom_Marc
				from Producto INNER JOIN Marca
				where PK_Id_Prod='$idProductos'";
			$result=mysqli_query($conn,$sql);

			$ver=mysqli_fetch_row($result);

			$datos=array(
					"PK_Id_Prod" => $ver[0],
					"No_Exis" => $ver[1],
					"Precio" => $ver[2],
					"Descripcion" => $ver[3],
					"Marca" => $ver[4]);
			mysqli_free_result($result);
			return $datos;
		}

		function actualizaProductos($datos){
			require("Cn.php");
			$sql="UPDATE Producto set FK_Id_Marca='$datos[4]', No_Exis ='$datos[1]',
				  Precio='$datos[2]', Descripcion='$datos[3]'WHERE PK_Id_Prod='$datos[0]'";
			return mysqli_query($conn,$sql);
		}

		function eliminaProductos($idProductos){
			require("Cn.php");
			$sql="DELETE from Producto
					where PK_Id_Prod='$idProductos'";
			$result=mysqli_query($conn,$sql);
		}	

 ?>