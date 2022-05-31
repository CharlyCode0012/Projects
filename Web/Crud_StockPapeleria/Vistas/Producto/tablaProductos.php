
<?php 
	require_once "../../Fun/Cn.php";
	$sql="SELECT Producto.*, Marca.Nom_Marc FROM Producto
		  INNER JOIN Marca
		  on Producto.FK_Id_Marca=Marca.PK_Id_Marca";
	$result=mysqli_query($conn,$sql);

 ?>

<table class="table table-hover table-condensed table-bordered" style="text-align: center; background-color: rgba(255, 255, 255, 0.877);">
	 	<caption><h2 style="text-align: center; color: black; font-weight:bold; font-family:'Copperplate Gothic Light', Arial;">
		 Productos</h2></caption>
	<tr>
		<td>Cantidad</td>
		<td>Descripcion</td>
		<td>Marca</td>
		<td>Precio</td>
		<td>Editar</td>
		<td>Eliminar</td>
	</tr>

	<?php while($ver=mysqli_fetch_row($result)): ?>

	<tr>
		<td><?php echo $ver[1]; ?></td>
		<td><?php echo $ver[3]; ?></td>
		<td><?php echo $ver[4]; ?></td>
		<td><?php echo $ver[2]; ?></td>
		<td>
			<span  data-toggle="modal" data-target="#abremodalUpdateProductos" class="btn btn-warning btn-xs" onclick="agregaDatosProductos('<?php echo $ver[0] ?>')">
				<span class="glyphicon glyphicon-pencil"></span>
			</span>
		</td>
		<td>
			<span class="btn btn-danger btn-xs" onclick="eliminaProductos('<?php echo $ver[0] ?>')">
				<span class="glyphicon glyphicon-remove"></span>
			</span>
		</td>
	</tr>
<?php endwhile; ?>
</table>