<!DOCTYPE html>
<?php
	include("database_connect.php");
?>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<script src="https://kit.fontawesome.com/00d9b08a45.js" crossorigin="anonymous"></script><!-- FontAwesome 4-->
    <link rel="stylesheet" href="CSS/Style.css">
	<link rel="stylesheet" href="CSS/Conten.css">
	<link rel="stylesheet" href="CSS/Range.css">
	<title></title>
</head>
<body>
	<div class="menu">
		<nav class="menu1">
			<button class="darkModeSwitch" id="switch">
				<span><i class="fa fa-sun-o"></i></span>   
				<span><i class="fa fa-moon-o"></i></span>
		</nav>
	</div>
	
		<form id = "formulario"  method = "POST" action= "update_values.php">
			
			<fieldset class="range1">
				<legend>Temperatura</legend>
					<div class="inputDiv">
						<div class="etiquetaG"></div>
						<input type="num" name= "temp" id="temp">
					</div>
			</fieldset>
			
			<fieldset class="range1">
				<legend>On/Off</legend>
					<div class="inputDiv">
						<div class="etiquetaB"></div>
						<select name="State" id="State">
							<option value="Off">Off</option>
							<option value="On">On</option>
						</select>
					</div>
				  <script src="JS/Range.JS"></script>
			</fieldset>

			<fieldset class = "show1">
				<legend>Datos</legend>
				<div class="inputDiv">
				<label type="text" name= "getTemp" id = "getTemp">
					<?php 
					$unit = 99999;
					$result = mysqli_query($con,"SELECT * FROM USERS WHERE id=$unit");
					$row = mysqli_fetch_array($result);
					echo "Temp: ".$row['temp'];
					?>
				</label>
					<input type="submit" value="Enviar">
				</div>
			</fieldset>
			<script src="JS/Value.JS"></script>
		</form>
	<script src="JS/main.js"></script>
</body>
</html>