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
    <link rel="shortcut icon" href="../../Recursos/IMG/PostS.png">
    <title>Post S</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <pre><img id ="Center" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/PsLogo.png"></pre>

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic">PostScript</h1>
            <h2 class="Subtitulo">¿Qué es?</h2>

            <p class="Text">
                Es un lenguaje de programación que se usa para decirle a una máquina destinada a imprimir cómo
                y qué debe imprimir.
                <br><br>
                Los documentos PostScript se destinan a imprimirse en aparatos PostScript, es decir,
                en aparatos que tienen un dispositivo interno capaz de descifrar el código que reciben y convertirlo en
                simples puntos de impresión.
            </p>

            <h2 class="Subtitulo">Última modificación</h2>

            <p class="Text">
                Su última versión es <b>PostScript 3</b>.
                <br><br>
                A partir de esta versión, Adobe abandonó la terminología de niveles, pasando a usar la de versiones. Esta versión fue liberada a finales de 1997.
                Esta nueva versión, introdujo varias mejoras y las pirncipales son:
                <br><br><br>
            <ul class="Text">
                <li>
                    • Uso de 12 bits para describir las lineaturas de semitono
                </li><br>

                <li>
                    • Control extremadamente mejorado de las separaciones de color.
                </li><br>
                <li>
                    • Soporte del formato PDF desarrollado para el programa Acrobat.
                </li>
                <li><br>
                    • Gestión del color mucho más avanzada
                </li><br>
                <li>
                    • Nuevas características de impresión relacionadas con las posibilidades que ofrece Internet que aún no han sido muy desarrolladas.
                </li><br>
                <li>
                    • Introducción de nuevos filtros de compresión de imágenes como son el FlateDecode y FlateEncode y para definición de datos.
                </li><br>
            </ul>
            </p>
            <h2 class="Subtitulo">¿Para qué se creó?</h2>

            <p class="Text">
                Antes era necesario tener las tipografías definidas de forma fija dentro de la impresora. <br>
                Ahora, PostScript brindaba la capacidad de definir texto como cualquier otro objeto gráfico
                (describiéndolo matemáticamente a partir de líneas rectas y curvas, y luego escalarlo a cualquier tamaño deseado)
                y de resolverlo a cualquier resolución.
                <br><br>
                Tratar el texto como cualquier otro objeto gráfico era un concepto sumamente avanzado,
                pero para Adobe lo logro con este formato PostScript.
            </p>

            <h2 class="Subtitulo">¿Qué se logró?</h2>

            <p class="Text">
                PostScript indicará a la impresora la posición, tamaño, ángulo de giro, sólo la forma o la tonalidad de color o gris que debe tener cada elemento de la página.
                Por lo que se consiguión un sistema de impresión fijo sin necesidad de almacenar tipografías fijas en la impresora.
            </p>
        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "PostScript.pdf";
    $html = ob_get_clean();
    $url = "/FormText/PostScript.php";

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