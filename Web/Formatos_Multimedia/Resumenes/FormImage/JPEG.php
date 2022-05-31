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
    <link rel="shortcut icon" href="../../Recursos/IMG/JPEG_Logo.svg">
    <title>JEPG</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <img id="Center" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/JPEG_Logo.png">

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic"> JPEG </h1>
            <h2 class="Subtitulo">¿Qué es?</h2>

            <p class="Text">
                Este formato fue creado por Joint Photographic Experts Group
                (el nombre de un comité de expertos que creó un estándar de compresión y codificación de archivos e imágenes fijas).
                <br><br>
                Jpeg es una imagen rasterizada silenciosa de 24 bits, con ocho bits en cada canal del modelo de color rgb.
                <br>
                Esto no deja espacio para los canales alfa.

                <br><br>
                El estándar JPEG permite varios métodos matemáticos diferentes, algunos de los que no afectan a la
                calidad de imagen y se llaman lossless, como codificación de Huffman, y otros que degradan la imagen y
                se llaman con pérdida, como la transformación de espacio de color y disminución de resolución.
            </p>

            <img id="ascii" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/ejemJPEG.jpg">

            <br><br>
            <h2 class="Subtitulo">¿Para qué se creó?</h2>


            <p class="Text">
                Es utilizado por las cámaras fotográficas digitales y otros dispositivos de captura de imagen, junto con JPG/JFIF,
                incluso es otro formato para el almacenamiento y la transmisión de imágenes fotográficas en Web, por ende, se requería
                de este formato para la facilidad de transimisión de imagenes entre computadora y camara.
            </p>

            <br><br><br><br>
            <h2 class="Subtitulo">¿Qué se logró?</h2>

            <p class="Text">
                Las imagenes eran muy pesadas para subirlas en páginas web, por lo que con este estandar las imágenes
                requieren entre un 50 y un 75 por ciento menos de espacio de almacenamiento.
            </p>
        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "JPEG.pdf";
    $html = ob_get_clean();
    $url = "/FormImage/JPEG.php";

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