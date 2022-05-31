<?php 

		function registroUsuario($datos){
			require("Cn.php");

			$sql="INSERT into Empleado (nombre,
								apellido,
								email,
								password,
								fechaCaptura)
						values ('$datos[0]',
								'$datos[1]',
								'$datos[2]',
								'$datos[3]',
								'$fecha')";
			return mysqli_query($conn,$sql);
		}
		function loginUser($datos){
			require("Cn.php");
			$password=sha1($datos[1]);

			$_SESSION['usuario']=$datos[0];
			$_SESSION['iduser']=self::traeID($datos);

			$sql="SELECT * 
					from Empleados
				where Nom_UE='$datos[0]'
				and Contra_E='$password'";
			$result=mysqli_query($conn,$sql);

			if(mysqli_num_rows($result) > 0){
				return 1;
			}else{
				return 0;
			}
		}
		function traeID($datos){
			require("Cn.php");

			$password=sha1($datos[1]);

			$sql="SELECT id_usuario 
					from usuarios 
					where email='$datos[0]'
					and password='$password'"; 
			$result=mysqli_query($conn,$sql);

			return mysqli_fetch_row($result)[0];
		}

		function obtenDatosUsuario($idusuario){
			require("Cn.php");

			$sql="SELECT id_usuario,
							nombre,
							apellido,
							email
					from usuarios 
					where id_usuario='$idusuario'";
			$result=mysqli_query($conn,$sql);

			$ver=mysqli_fetch_row($result);

			$datos=array(
						'id_usuario' => $ver[0],
							'nombre' => $ver[1],
							'apellido' => $ver[2],
							'email' => $ver[3]
						);

			return $datos;
		}

		function actualizaUsuario($datos){
			require("Cn.php");

			$sql="UPDATE usuarios set nombre='$datos[1]',
									apellido='$datos[2]',
									email='$datos[3]'
						where id_usuario='$datos[0]'";
			return mysqli_query($conn,$sql);	
		}

		function eliminaUsuario($idusuario){
			require("Cn.php");
			$sql="DELETE from usuarios 
					where id_usuario='$idusuario'";
			return mysqli_query($conn,$sql);
		}
	

 ?>