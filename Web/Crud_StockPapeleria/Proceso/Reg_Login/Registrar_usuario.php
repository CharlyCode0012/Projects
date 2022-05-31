<?php

use FontLib\Table\Type\head;

require_once("../../Fun/Cn.php");
    $pass=sha1($_POST['Pass']);
    $datos=array($_POST['nombre'], $_POST['Ape1'], $_POST['Ape2'], $Adm=$_POST['Adm'], $_POST['Fecha'], 
    $_POST['CURP'], $_POST['RFC'], $pass, $_POST['Dir'], $_POST['UserN'], $_POST['Mun']);
    
        $Q="SELECT PK_Id_Emp FROM Empleado ORDER BY PK_Id_Emp DESC Limit 1";
        $result=mysqli_query($conn,$Q);
        $Id_Emp=mysqli_fetch_row($result);
        $Id_Emp[0]= $Id_Emp[0]+1;
        mysqli_free_result($result);
        $sql="INSERT into Empleado (PK_Id_Emp, Nom_E, Ap1_E, Ap2_E, Adm, FN_E, CURP_E, RFC_E, Contra_E, Direc_E, Nom_UE, FK_Id_Mun)
                Values ('$Id_Emp[0]','$datos[0]','$datos[1]', '$datos[2]', '$datos[3]', '$datos[4]',
                 '$datos[5]','$datos[6]','$datos[7]','$datos[8]','$datos[9]','$datos[10]')";
        $R=mysqli_query($conn,$sql);
   
header("location:../../Index.php");
        
?>