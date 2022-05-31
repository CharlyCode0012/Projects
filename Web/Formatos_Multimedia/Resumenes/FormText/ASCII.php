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
    <link rel="shortcut icon" href="../../Recursos/IMG/ASCII_logo.svg">
    <title>ASCII</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <pre><img id ="Center" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/ASCII_logo.png"></pre>

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic"> ASCII </h1>
            <h2 class="Subtitulo">¿Qué es?</h2>

            <p class="Text">
                Sus siglas significan American Standard Code for Information Interchange, su traducción al español es:
                Código Americano Estándar para el Intercambio de Información.
                <br><br>
                Es un estándar para la representación de caracteres en cualquier dispositivo electrónico.
                Le asigna un código binario a cada letra, lo cual hace posible que la maquina traduzca dicho código y
                lo imprima en pantalla.
                <br><br>
            </p>

            <h2 class="Subtitulo">Última modificación</h2>

            <p class="Text">
                Al inicio era un sistema de 7 bits, pero después se empleo un 8vo bit para llegar a lo que es hoy en día
                (1981 IBM, página de código 437)
                <br><br>
                ASCII ha evolucionado y gracias a ello existen cosas como Unicode, el cual permite traducir de cualquier alfabeto
                a otro distinto, al igual que UTF-8 nos permite poder mostrar cualquier carácter especial en el ordenador.
            </p>

            <img id="ascii" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/ascii.png">

            <br><br>
            <h2 class="Subtitulo">¿Para qué se creó?</h2>

            <p class="Text">
                Se creó para darle una alternativa a los ordenadores para que puedan entendernos, ya que fue necesario
                generar una traducción desde el sistema binario hacia el alfabeto latino.
                <br>
                Además para poder hacer que cualquier persona que pueda leer entienda lo que el ordenador muestra,
                ya que al usar caracteres especiales el ordenador solía mandar caracteres sin sentido porque no entendía
                lo que le ingresaban, por lo que tampoco la persona entendía el resultado del ordenador.
            </p>

            <br><br><br>
            <h2 class="Subtitulo">¿Qué se logró?</h2>

            <p class="Text">
                El resultado fue un conjunto de caracteres de 256 caracteres, es decir un sistema de 8 bits, donde cada
                carácter tiene un código binario.
                <br><br>
                Dichos caracteres sirven para poder hacer que el usuario entienda lo que hay así como
                el ordenador entienda lo que se le ingresa.
                <br>
                Además de que sustento las bases para los demas estandares o formatos como lo es UNICODE (utf-8).
            </p>
        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "ASCII.pdf";
    $html = ob_get_clean();
    $url = "/FormText/ASCII.php";

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