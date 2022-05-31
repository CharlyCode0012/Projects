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
    <link rel="shortcut icon" href="../../Recursos/IMG/RTFL.png">
    <title>RTF</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <pre><img id ="Center" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/TituloRTF2.png"></pre>

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic"> RTF </h1>
            <h2 class="Subtitulo">¿Qué es?</h2>

            <p class="Text">
                La extensión RTF feu desarrollado en 1987, cuyas siglas provienen de Rich Text Format el cuál es un estándar
                de archivo que define un tipo
                de codificación para texto formateado y gráficos, así como la transferencia de datos entre procesadores
                de texto.
            </p>

            <h2 class="Subtitulo">Modificaciones</h2>

            <p class="Text">
                En la última versión se añadieron las etiquetas inteligentes SmartTags y el uso de XML, XLS y OMML.
                <br>
                El usuario puede incorporar datos de fuente, caracteres Unicode de 16 bits e imágenes a nivel binario en
                el archivo.
                <br><br>
                Al visualizar el texto sin formato, el lenguaje de marcas es legible, pero no representa una
                distracción significativa como para dificultar la compresión y el seguimiento del material.
            </p>

            <img id="ascii" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/RTF.png">

            <br><br>
            <h2 class="Subtitulo">¿Para qué se creó?</h2>

            <p class="Text">
                Fue diseñado por el equipo de Microsoft Word para lograr el intercambio de documentos de texto
                en múltiples plataformas, definiendo así un formato en el que se debía en-codificar
                texto formateado y gráficos.
            </p>

            <br><br><br> <br><br> <br>
            <h2 class="Subtitulo">¿Qué se logró?</h2>
            <p class="Text">
                Permite al usuario escribir texto con la posibilidad de guardarlo y utilizarlo en distintos sistemas operativos.
                <br><br>
                A diferencia de otros tipos de archivo de texto, el formato RTF solo admite texto,
                pero no es compatible con imágenes, vídeo ni audio.
            </p>

        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "RTF.pdf";
    $html = ob_get_clean();
    $url = "/FormText/RTF.php";

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