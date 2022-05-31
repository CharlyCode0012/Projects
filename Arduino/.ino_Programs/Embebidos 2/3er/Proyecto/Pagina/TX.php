<?php
    include("database_connect.php");
    
    $result = mysqli_query($conn, "SELECT Temp From DHT11 WHERE id=99999");
    echo ($result); 
?>