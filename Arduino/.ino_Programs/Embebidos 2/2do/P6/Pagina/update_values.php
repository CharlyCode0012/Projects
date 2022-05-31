<?php
//This file will get the values when you click any of the ON/OFF buttons or change buttons on the index.php file
//We get that value and send it to the datapase table and by that update the values
//$value = $_POST['value'];		//Get the value
$rgb = $_POST['rgb1'];
$unit = 99999;		

//connect to the database
include("database_connect.php"); //We include the database_connect.php which has the data for the connection to the database

// Check the connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

//Now update the value sent from the post (ON/OFF, change or send button)
mysqli_query($con,"UPDATE USERS SET TEXT_HEX= '{$rgb}'
WHERE id=$unit");

//go back to the interface
header("location: index.html");
?>