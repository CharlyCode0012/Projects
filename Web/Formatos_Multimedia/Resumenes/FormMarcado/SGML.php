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
    <link rel="shortcut icon" href="../../Recursos/IMG/logoSGML.png">
    <title>SGML</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <h1 class="Titulo-Gothic">SGML</h1>
            <h2 class="Subtitulo">¿Qué es?</h2>
            <p class="Text">
                GML es un descendiente del lenguaje de marcado generalizado de IBM, el cual se desarrolló en la década
                de los 60's, se finalizó en la década de los 70's cerca de los 80's por el mismo equipo de IBM liderado por
                Charles Goldfarb con la idea de que sería muy útil tener tags en los documentos para separar las partes de
                los componentes en el documento como si fueran párrafos.
                <br><br>
            </p>
            <img src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/logoSGML.png">
            <h2 class="Subtitulo">Última modificación</h2>
            <p class="Text">
                SGML fue trabajado en 1998 al formato XML, un perfil exitoso de SGML.
                El uso completo de SGML se encuentra raramente o nulo en nuevos proyectos.
            </p>

            <h2 class="Subtitulo">¿Para qué se creó?</h2>
            <p class="Text">
                SGML fue diseñado originalmente para permitir el intercambio de grandes documentos en el gobierno, leyes, e
                industrias.
                <br>
                Muchos de esos documentos deben permanecer intactos durante un largo tiempo en el campo de la informática.
                <br><br>
                SGML también fue aplicado ampliamente por militares, y la industria aeroespacial, para referencias técnicas, y por
                la industria editorial.
            </p>

            <h2 class="Subtitulo">¿Qué se logró?</h2>
            <p class="Text">
                La aparición del perfil XML ha hecho SGML adecuado para la aplicación generalizada de pequeña escala, y el uso de propósito general.
                establece lo que algunos idiomas pueden o no pueden hacer, qué elementos deben incluirse, como las etiquetas, y la estructura básica del idioma.
                <br>
                A medida que un padre transmite los rasgos genéticos a su hijo, el SGML pasa las reglas de estructura y formato a los lenguajes de marcado.
                Es decir, se pusieron las bases para lenguajes como XML.
            </p>
        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "SGML.pdf";
    $html = ob_get_clean();
    $url = "/FormMarcado/SGML.php";

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