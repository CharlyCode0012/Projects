<?php
require("Fun/Cn.php");
   $pass=sha1($_POST['password']);
   $arr= array($_POST['usuario'], $pass);
   session_start();
   $_SESSION['usuario']=$arr[0];
   $Q2="SELECT*FROM Empleado WHERE Nom_UE= '$arr[0]' AND Contra_E='$arr[1]'";
   $Result=mysqli_query($conn,$Q2);
   $filas=mysqli_num_rows($Result);
   if($filas){
       header("location:Vistas/Menu.php");
   }
   else{
       ?>
       <?php
       include("Index.php");
       ?>
        <script>alert('Datos erroneos'); windows.location='Index.php' </script>
       <?php
   }
   mysqli_free_result($Result);
   mysqli_close($conn);
?>