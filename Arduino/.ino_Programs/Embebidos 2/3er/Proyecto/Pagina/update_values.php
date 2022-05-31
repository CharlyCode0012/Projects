<?php
include("database_connect.php");
$Temp= $_POST['temp'];

//echo json_encode($vel.', '. $state.', '.$dir);
mysqli_query($conn, "UPDATE DHT11 SET Temp=$Temp WHERE id=99999");

header("location: index.php");
