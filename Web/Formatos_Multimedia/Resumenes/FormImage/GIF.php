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
    <link rel="shortcut icon" href="../../Recursos/IMG/GIF_Logo1.png">
    <title>GIF</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <img id="Center" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/GIF_Logo.png">

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic">GIF</h1>
            <h2 class="Subtitulo">¿Qué es?</h2>

            <p class="Text">
                Un GIF es un formato de intercambio de imágenes.
                Consiste en el movimiento de uno o varios fotogramas alrededor de 3-5 segundos de duración y que se
                repite de manera infinita. Se anima mediante la combinación de varias imágenes o un solo vídeo.
                <br><br>
                Es un híbrido entre una imagen estática y un video.
                <br>
                Este formato de imagen fue creado en 1987 por Steve Wilhite en Compuserve, una compañía de comunicaciones
                norteamericana.
                <br><br>
                Los archivos GIF tienen un límite de 256 colores (8 bits). <br>
                Si se optimiza una imagen original de 24 bits como archivo GIF de 8 bits, es posible que se reste colores
                a la imagen.
            </p>
            <img src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/ejemGIF.png">
            <h2 class="Subtitulo">Versiones</h2>
            <p class="Text">
                Los archivos GIFs suelen usar un algoritmo de comprensión que se denomina codificación LZW
                <br><br>
                Este algoritmo se <b>caracteriza</b> porque:<br><br>
                -Favorece la <i>no degradación</i> y <i>pérdida de calidad</i> de la imagen.
                <br><br>
                Existen dos versiones de este formato de archivos: <i>GIF 87a</i> y <i>GIF 89a</i>, desarrolladas en 1987 y
                1989 respectivamente.
            </p>

            <h2 class="Subtitulo">¿Para qué se creó?</h2>
            <p class="Text">
                Se creo por la necesidad de subir imágenes en secuencia, y como el internet
                era muy lento en esa epoca, el subir un vídeo en una página web hacia que se cargara muy lento
                la página, además de que era muy pesado para el servidor almacenarlo.
            </p>
        </div>
    </div>

    <?php

    $db = new BaseDeDatos();

    $file = "GIF.pdf";
    $html = ob_get_clean();
    $url = "/FormImage/GIF.php";

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