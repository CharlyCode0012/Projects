<?php

$unit = $_GET['id1'];
$pass = $_GET['pw1'];

include("database_connect.php"); 	//We include the database_connect.php which has the data for the connection to the database


// Check  the connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

//Now we update the values in database
//mysqli_query($con,"UPDATE USERS SET TEXT_HEX = $text WHERE id=$unit AND PASSWORD=$pass");	;	


//Get all the values form the table on the database
$result = mysqli_query($con,"SELECT * FROM USERS WHERE id=$unit AND PASSWORD=$pass ");	//table select is ESPtable2, must be the same on yor database

while($row = mysqli_fetch_array($result)) {
if($row['id'] == $unit){
		$n6 = $row['TEXT_HEX'];
		
		//Next line will echo the data back to the Arduino
		echo "{"RGB:".$n6."}";
}
?>








