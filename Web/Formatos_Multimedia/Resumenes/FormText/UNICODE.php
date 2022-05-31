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
    <link rel="shortcut icon" href="../../Recursos/IMG/Unicode_Logo.svg">
    <title>UNICODE</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <pre><img id ="Center" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/UNICODE_Logo.png"></pre>

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic"> UNICODE </h1>
            <h2 class="Subtitulo">¿Qué es?</h2>

            <p class="Text">
                Unicode es el estándar de codificación de caracteres universal utilizado para la representación de texto para
                procesamiento del equipo.
                <br><br>
                Unicode proporciona una manera consistente de codificación de texto multilingüe y facilita el intercambio
                de archivos de texto internacionales.
            </p>

            <h2 class="Subtitulo">Modificaciones</h2>

            <p class="Text">
                Hay muchos cambios, aquí hay unos de los <b>ejemplos mas notables:</b>
                <br><br>
            <ul class="Text">
                <li>
                    • Se agregaron 4,306 caracteres Hangul, más el conjunto original de 2,350 y además se elimina
                    el alfabeto tibetano em 1993
                </li>
                <li>
                    • Se agrego el símbolo del euro en 1998
                </li>
                <li>
                    • Se agrego 143 símbolos matemáticos alfabéticos y de varios alfabetos raros, con 13
                    emoticonoes
                </li>
                <li>
                    • En 2017 se agrega el símbolo del bitcoin
                </li>
            </ul>
            </p>

            <img id="ascii" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/BitCoin.png">

            <br><br>
            <h2 class="Subtitulo">¿Para qué se creó?</h2>

            <p class="Text">
                Unicode se creó para solucionar el problema ocasionado por la profusión de juegos de códigos.
                <br><br>
                Desde el principio de la programación de sistemas se han desarrollado cientos de codificaciones, cada
                una de ellas para pequeños grupos de idiomas y con fines específicos.
                <br><br>
                Es decir que al trabajr con personas de otros paises habia problemas de codificacion
                por los diferentes caracteres que se creaban.
            </p>

            <br><br><br>
            <h2 class="Subtitulo">¿Qué se logró?</h2>

            <p class="Text">
                <b>Sistemas operativos</b>
                <br><br>
                Unicode es el estándar interno para la asignación de texto en la mayoría de los sistemas operativos modernos.
                <br>
                Algunos sistemas operativos, como macOS de Apple, permiten el uso de caracteres Unicode en los nombres de
                archivos.
                <br><br>
                <b>Páginas web</b>
                <br><br>
                La variante Unicode UTF-8 se ha convertido en el estándar para codificar documentos HTML.
                <br>
                Ya en 2016, más del 80 % de las páginas web más visitadas del mundo utilizaban UTF-8 para almacenar
                y mostrar sus documentos HTML.
            </p>

        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "UNICODE.pdf";
    $html = ob_get_clean();
    $url = "/FormText/UICODE.php";

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