<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registro</title>
    <link rel="stylesheet" href="Librerias/bootstrap/css/bootstrap.css">
    <script src="Librerias/jquery-3.6.0.min.js"></script>

</head>
<body style="background-color:#3f3f3f">
    <br><br><br>
    <div class="container">
        <div class="row">
            <div class="col-sm-4"></div>
            <div class="col-sm-4">
                <div class="panel panel-danger">
                    <div class="panel panel-heading">Registrar Administradoe</div>
                    <div class="panel panel-body">
                        <form id="frmRegistro" action="Proceso/Reg_Login/Registrar_usuario.php" method="POST">
                            <label>Nombre</label>
                            <input type="text" class="form-control input-sm"name="nombre" id="nombre" required>
                            <label>Apellido 1</label>
                            <input type="text" class="form-control input-sm"name="Ape1" id="Ape1" required>
                            <label>Apellido 2</label>
                            <input type="text" class="form-control input-sm"name="Ape2" id="Ape2" required>
                            <label>Adm</label>
                            <input type="text" class="form-control input-sm"name="Adm" id="Adm" required>
                            <label>FechaN</label>
                            <input type="date" class="form-control input-sm"name="Fecha" id="Fecha" 
                            value="2003-01-17"min="1970-01-01" max="2099-12-31" required>
                            <label>Curp</label>
                            <input type="text" class="form-control input-sm"name="CURP" id="CURP" required>
                            <label>RFC</label>
                            <input type="text" class="form-control input-sm"name="RFC" id="RFC" required>
                            <label>User Name</label>
                            <input type="text" class="form-control input-sm"name="UserN" id="UserN" required>
                            <label>Contrase??a</label>
                            <input type="password" class="form-control input-sm"name="Pass" id="Pass" required>
                            <label>Direccion</label>
                            <input type="text" class="form-control input-sm"name="Dir" id="Dir" required>
                            <label>Municipio</label>
                            <input type="text" class="form-control input-sm"name="Mun" id="Mun" required>
                            <p></p>
                                <button class="btn btn-primary" id="registro">Registrar</button>
                                <a href="Index.php" class="btn btn-default">Regresar</a>
                        </form>
                    </div>
                </div>
            </div>
            <div class="col-sm-4"></div>
        </div>

    </div>
</body>
</html>
