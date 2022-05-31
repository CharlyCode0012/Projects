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
    <link rel="shortcut icon" href="../../Recursos/IMG/html5_logo.png">
    <title>HTML</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <h1 class="Titulo-Gothic">HTML</h1>
            <h2 class="Subtitulo">¿Qué es?</h2>
            <img src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/html5_logo.png">
            <p class="Text">
                HTML o Lenguaje de Marcas de Hipertexto es un lenguaje que nos ayuda a tener una estructura y significado al contenido de una página web.
                <br><br>
                HTML es solo un lenguaje que por medio de marcadores (tags) y atributos definen como el contenido se verá presentado en un navegador.
            </p>
            <h2 class="Subtitulo">Última modificación</h2>
            <p class="Text">
                La última especificación oficial de HTML se publicó el 24 de diciembre de 1999 y se denomina HTML 4.01.

                Se trata de una revisión y actualización de la versión HTML 4.0, por lo que no incluye novedades significativas
            </p>

            <h2 class="Subtitulo">¿Para qué se creó?</h2>
            <p class="Text">
                La idea era crear un ambiente en que los científicos tuvieran la posibilidad de divulgar sus investigaciones
                para que sus colegas los consultaran con relativa facilidad.
            </p>

            <h2 class="Subtitulo">¿Qué se logró?</h2>
            <p class="Text">
                Gracias a la creación de HTML y sus etiquetas podemos estructurar y crear páginas web llenas de atributos
                accesibles a mucha información, además de darle un formato adecuado a las paginas web.
            </p>


        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "HTML.pdf";
    $html = ob_get_clean();
    $url = "/FormMarcado/HTML.php";

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