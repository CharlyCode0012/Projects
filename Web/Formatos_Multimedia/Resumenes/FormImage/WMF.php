<!DOCTYPE html>
<html lang="en">
<?php
include "../../Back/controller/DB.php";
?>

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../../Recursos/CSS/Normalize.css">
    <link rel="stylesheet" href="../../Recursos/CSS/DOM/Resumen.css">
    <link rel="stylesheet" href="../../Recursos/CSS/DOM/Menu.css">
    <link rel="stylesheet" href="../../Font-Awesome/fontawesome-free-6.0.0-web/css/all.min.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Rajdhani&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Tangerine">
    <link href="https://fonts.googleapis.com/css2?family=Montserrat+Alternates:ital,wght@1,200&family=Rajdhani&display=swap" rel="stylesheet">
    <link rel="shortcut icon" href="../../Recursos/IMG/WMF.png">
    <title>WMF</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <img id="Center" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/WMF_Logo.png">

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic"> WMF </h1>
            <h2 class="Subtitulo">¿Qué es?</h2>

            <p class="Text">
                Es un formato de gráficos vectoriales que permite
                también la inclusión de mapas de bits.
                <br><br>
                Almacena una secuencia de llamadas a funciones
                que son enviadas al nivel gráfico de Windows GDI
                (Graphics Device Interface) para regenerar la imagen.
                <br>
                Es similar en propósito y diseño al formato
                PostScript.
            </p>

            <h2 class="Subtitulo">Última modificación</h2>

            <p class="Text">
                La última versión salió en 2006 la cuál solucionó los problemas encontrados en 2005, lo cual
                era una vulnerabilidad en el sistema que le permitia a otros usuarios poner código malicioso
                a tra ves de una imagen.
            </p>

            <img id="ascii" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/WMF.png">

            <br><br>
            <h2 class="Subtitulo">¿Para qué se creó?</h2>

            <p class="Text">
                Fue diseñado para ser ejecutado por la capa de gráficos de Windows GDI, a fin de restaurar la imagen,
                aunque como los archivos WMF contienen la definición gráfica que constituye esta imagen, es posible
                diseñar alternativas que convierten los WMF en archivos binarios
            </p>

            <br><br>
            <h2 class="Subtitulo">¿Qué se logró?</h2>

            <p class="Text">
                Se consiguión un formato de archivo el cual es compatible con sisteas Windows además de rediseñar la imagen
                de una mejor manera, transmitir dichos archivos a otros dispositivos.
                <br><br>
                Contienen una secuencia de registros de longitud
                variable con gráficos, comandos de dibujo, propiedades
                y definiciones de objetos. La extensión del archivo WMF
                <br>
                Tiene una plaeta de colores de: 16,777, 216 , es decir 24bits
                <br>
            </p>
        </div>
    </div>

    <?php

    $db = new BaseDeDatos();

    $file = "WMF.pdf";
    $html = ob_get_clean();
    $url = "/FormImage/WMF.php";

    $db->updateDom($file, $url, $html);
    echo $html;

    echo <<< ETO
        <div class = "Cont-Info__Form">
        <a href="../../Back/controller/Download.php" target="_blank"><button class="Cont-Info__Form-Button">Descargar</button></a>
        </div>
        ETO;

    ?>
</body>

</html>