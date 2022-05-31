<?php
    $Temp2=$_POST['Temp1'];
    echo "$Temp2";
    include("database_connect.php");
    
    if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}
    
    mysqli_query($con, "UPDATE DHT11 SET LM35='{$Temp2}' WHERE id=99999");
    
    $result = mysqli_query($con, "SELECT * FROM DHT11 WHERE id=99999");
    while($row = mysqli_fetch_array($result)) {
    if($row['id'] == 99999){
		$n6 = $row['Temp'];
		
		//Next line will echo the data back to the Arduino
		echo "$n6";
}
}
?>