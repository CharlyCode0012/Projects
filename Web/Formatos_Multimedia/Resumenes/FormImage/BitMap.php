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
    <link rel="shortcut icon" href="../../Recursos/IMG/BitMap_Logo.png">
    <title>BitMap</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <img id="Center" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/BitMap_Logo.png">

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic"> BMP </h1>
            <h2 class="Subtitulo">¿Qué es?</h2>

            <p class="Text">
                Tipo de archivo empleado por Windows por defecto para guardar imágenes independientes del dispositivo o
                archivos de mapa de bits, también conocidos como extensión de archivo de imagen Bitmap (.bmp).
                <br><br>
                Puede guardar imágenes de 24, 8 y menos bits, además de que se les puede dar una compresión sin perdida de
                calidad. Fue desarrollado por Microsoft en 1986
                <br><br>
            </p>

            <img id="ascii" src="../../Recursos/IMG/BitMap.png">

            <br><br>
            <h2 class="Subtitulo">¿Para qué se creó?</h2>

            <p class="Text">
                Fue creado como un formato de imágenes universal que pudiera ser reproducido en cualquier dispositivo,
                sin limitaciones de hardware, es por eso que tiene el concepto de formato independiente.
            </p>


            <h2 class="Subtitulo">¿Qué se logró?</h2>

            <p class="Text">
                Se consiguión un archivo universal, el cual es compatible en cualquier sistema,
                además de que tiene una combinacion de 16 millones de colores.
            </p>
        </div>
    </div>

    <?php

    $db = new BaseDeDatos();

    $file = "BitMap.pdf";
    $html = ob_get_clean();
    $url = "/FormImage/BitMap.php";

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