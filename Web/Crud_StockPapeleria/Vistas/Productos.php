<?php 
session_start();
if(isset($_SESSION['usuario'])){

	?>


	<!DOCTYPE html>
	<html>
	<head>
		<title>Productos</title>
		<?php require_once "menu.php"; ?>
		<?php require_once "../Fun/Cn.php"; 
		$sql="SELECT * FROM Producto";
		$result=mysqli_query($conn,$sql);
		?>
	</head>
	<body>
		<div class="container">
			<br><br><br><br><br><br><br><br>
			<div class="row">
				<div class="col-sm-4" style=" background-color:rgba(255, 255, 255, 0.877)";>
				<h1>Productos</h1>
					<form id="frmProductos" enctype="multipart/form-data">
						<label>Cantidad</label>
						<input type="text" class="form-control input-sm" id="cantidad" name="cantidad">
						<label>Precio</label>
						<input type="text" class="form-control input-sm" id="precio" name="precio">
						<label>Descripcion</label>
						<input type="text" class="form-control input-sm" id="descripcion" name="descripcion">
						<label>Marca</label>
						<input type="text" class="form-control input-sm" id="marca" name="marca">
						<p></p>
						<span id="btnAgregaProductos" class="btn btn-primary">Agregar</span>
					</form>
				</div>
				<div class="col-sm-8">
					<div id="tablaProductosLoad"></div>
				</div>
			</div>
		</div>

		<!-- Button trigger modal -->
		
		<!-- Modal -->
		<div class="modal fade" id="abremodalUpdateProductos" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
			<div class="modal-dialog modal-sm" role="document">
				<div class="modal-content">
					<div class="modal-header">
						<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
						<h4 class="modal-title" id="myModalLabel">Actualiza Productos</h4>
					</div>
					<div class="modal-body">
						<form id="frmProductosU" enctype="multipart/form-data">
							<input type="text" id="idProductos" hidden="" name="idProductos">
							</select>
							<label>Cantidad</label>
							<input type="text" class="form-control input-sm" id="cantidadU" name="cantidadU">
							<label>Descripcion</label>
							<input type="text" class="form-control input-sm" id="descripcionU" name="descripcionU">
							<label>Precio</label>
							<input type="text" class="form-control input-sm" id="precioU" name="precioU">
							<label>Marca</label>
							<input type="text" class="form-control input-sm" id="marcaU" name="marcaU">
							
						</form>
					</div>
					<div class="modal-footer">
						<button id="btnActualizaProductos" type="button" class="btn btn-warning" data-dismiss="modal">Actualizar</button>

					</div>
				</div>
			</div>
		</div>

	</body>
	</html>

	<script type="text/javascript">
		function agregaDatosProductos(idProductos){
			$.ajax({
				type:"POST",
				data:"idart=" + idProductos,
				url:"Producto/obtenDatosProductos.php",
				success:function(r){
					
					dato=jQuery.parseJSON(r);
					$('#idProductos').val(dato['id_producto']);
					$('#cantidadU').val(dato['cantidad']);
					$('#precioU').val(dato['precio']);
					$('#descripcionU').val(dato['descripcion']);
					$('#marcaU').val(dato['marca']);

				}
			});
		}

		function eliminaProductos(idProductos){
			alertify.confirm('¿Desea eliminar este Productos?', function(){ 
				$.ajax({
					type:"POST",
					data:"idProductos=" + idProductos,
					url:"Producto/eliminarProductos.php",
					success:function(r){
						if(r==1){
							$('#tablaProductosLoad').load("Producto/tablaProductos.php");
							alertify.success("Eliminado con exito!!");
						}else{
							alertify.error("No se pudo eliminar :(");
						}
					}
				});
			}, function(){ 
				alertify.error('Cancelo !')
			});
		}
	</script>

	<script type="text/javascript">
		$(document).ready(function(){
			$('#btnActualizaProductos').click(function(){

				datos=$('#frmProductosU').serialize();
				$.ajax({
					type:"POST",
					data:datos,
					url:"Producto/actualizaProductos.php",
					success:function(r){
						if(r==1){
							$('#tablaProductosLoad').load("Producto/tablaProductos.php");
							alertify.success("Actualizado con exito :D");
						}else{
							alertify.error("Error al actualizar :(");
						}
					}
				});
			});
		});
	</script>

	<script type="text/javascript">
		$(document).ready(function(){
			$('#tablaProductosLoad').load("Producto/tablaProductos.php");

			$('#btnAgregaProductos').click(function(){

				vacios=validarFormVacio('frmProductos');

				if(vacios > 0){
					alertify.alert("Debes llenar todos los campos!!");
					return false;
				}

				var formData = new FormData(document.getElementById("frmProductos"));

				$.ajax({
					url: "Producto/insertaProductos.php",
					type: "post",
					dataType: "html",
					data: formData,
					cache: false,
					contentType: false,
					processData: false,

					success:function(r){
						
						if(r == 1){
							$('#frmProductos')[0].reset();
							$('#tablaProductosLoad').load("Producto/tablaProductos.php");
							alertify.success("Agregado con exito :D");
						}else{
							alertify.error("Fallo al subir el archivo :(");
						}
					}
				});
				
			});
		});
	</script>

	<?php 
}else{
	header("location:../index.php");
}
?>