<?php
include("database_connect.php");
$Temp= $_POST['temp'];
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
//echo json_encode($vel.', '. $state.', '.$dir);
mysqli_query($con, "UPDATE DHT11 SET Temp='{$Temp}' WHERE id=99999");

header("location: index.php");
