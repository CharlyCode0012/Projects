
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Papeleria Raquel</title>
    <link rel="stylesheet" href="Librerias/bootstrap/css/bootstrap.css">
    <script src="Librerias/jquery-3.6.0.min.js"></script>
</head>
<body style="background-color:#3f3f3f">
    <br><br><br><br>
   <div class="container">
       <div class="row">
           <div class="col-sm-5"></div>
           <div class="col-sm-5">
               <div class=" panel panel-primary">
                   <div class="panel panel-heading"> Papeleria Raquel</div>
                   <div class= "panel panel-body">
                        <p>
                            <div align="center">
                                <img src="Img/Logo_Raquel.PNG" width="320" height="250">
                            </div>
                        </p>
                        <form id="frmLogin" action="Validar.php" method="Post">
                            <label>Usuario</label>
                            <input type="text" class="form-control input-sm" name="usuario" id="usuario">
                            <label>Contraseña</label>
                            <input type="password" class="form-control input-sm" name="password" id="password">
                            <p></p>
                            <button class="btn btn-primary btn-m">Entrar</button>
                            <a href="Registro.php" class="btn btn-danger btn-m">Registrar</a>
                        </form>
                   </div> 
               </div>
           </div>
           <div class="col-sm-5"></div>
           </div>
       </div>
   </div> 
</body>
</html>


