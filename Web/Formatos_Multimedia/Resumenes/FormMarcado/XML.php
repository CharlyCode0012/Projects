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
    <link rel="shortcut icon" href="../../Recursos/IMG/XML_Logo.png">
    <title>XML</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <h1 class="Titulo-Gothic">XML</h1>
            <h2 class="Subtitulo">¿Qué es?</h2>
            <p class="Text">
                XML son las siglas para Extensible Markup Language (o Lenguaje de Etiquetado Extensible, en español);
                es un lenguaje de marcado que define un conjunto de reglas para la codificación de documentos.
                El lenguaje de marcado es un conjunto de códigos que se pueden aplicar en el análisis de datos o la lectura de
                textos creados por computadoras o personas.
                El lenguaje XML proporciona una plataforma para definir elementos para crear un formato y generar un lenguaje
                personalizado.
                <br><br>
            </p>
            <img src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/XML.png">
            <h2 class="Subtitulo">Última modificación</h2>
            <p class="Text">
                La versión actual es XML 1.0 (quinta edición), del 26 de noviembre de 2008. Existe también otra especificación,
                XML 1.1 (segunda edición) del año 2006, pero su principal diferencia es el tratamiento de caracteres
                Unicode 2.0 en los nombres, que ya ha sido incorporado en la última edición de XML 1.0.
            </p>

            <h2 class="Subtitulo">¿Para qué se creó?</h2>
            <p class="Text">
                Se buscó definir un subconjunto del SGML que <b>permita:</b>
                <br><br>
            <ul class="Text">
                <li>
                    -Mezclar elementos de diferentes lenguajes, es decir, que los lenguajes sean extensibles. -Mezclar elementos de diferentes lenguajes, es decir, que los lenguajes sean extensibles.
                </li>
                <li>
                    -La creación de analizadores simples, sin ninguna lógica especial para cada lenguaje.
                </li>
                <li>
                    -Empezar de cero y hacer hincapié en que no se acepte nunca un documento con errores de sintaxis.
                </li>
            </ul>

            <br><br>
            <p class="Text">
                Para hacer esto XML deja de lado muchas características de SGML que estaban pensadas para facilitar la
                escritura manual de documentos.
                XML en cambio está orientado a hacer las cosas más sencillas para los programas automáticos
                que necesiten interpretar el documento.
            </p>

            </p>

            <h2 class="Subtitulo">¿Qué se logró?</h2>
            <p class="Text">
                <b>XML aplicado a los sitios web</b>
                <br>
                Permite separar el contenido de la presentación y que los mismos datos se puedan mostrar de varias
                formas distintas sin demasiado esfuerzo.
                <br><br>
                <b>XML para la comunicación entre aplicaciones</b>
                <br>
                Representación de los datos muy simple y fácil de transmitir por la red.
                <br><br>
                <b>Aplicaciones heredadas</b>
                <br>
                Acceso a datos de aplicaciones que ya no están en uso o incompatibles por diferencias entre versiones.
            </p>
        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "XML.pdf";
    $html = ob_get_clean();
    $url = "/FormMarcado/XML.php";

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