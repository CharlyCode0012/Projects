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
    <title>Programas</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <img id="Center" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/iconos-formatos-imagen.png">

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic">Programas</h1>
            <h2 class="Subtitulo">PhotoShop</h2>
            <img id="Img-Program" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/Photoshop_Logo2.png">
            <p class="Text">
                Se utiliza para modificar imágenes digitalizadas, como fotografías. <br>
                También se usa para crear y editar fotos y gráficos
                <br><br>
                <b>CARACTERÍSTICAS:</b>
            <ul class="Text">
                <li>- Soporta muchos tipos de archivos de imágenes, como JPG, PNG, GIF, y muchos más.</li>
                <li>- Conjunto de múltiples capas, donde puedes modificar, transformar y distorsionar las imágenes.</li>
                <li>- Permite el tratamiento extensivo de fotos como controlar y retocar el color.</li>
            </ul>
            </p>


            <h2 class="Subtitulo">Illustrator</h2>
            <img id="Img-Program" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/Illustrator.png">
            <p class="Text">
                Se trata del programa de diseño ideal para crear piezas de arte digital incluido en Adobe Systems,
                y viene a ser uno de los pioneros en el diseño vectorial.
                <br><br>
                <b>CARACTERÍSTICAS:</b>
            <ul class="Text">
                <li>- Controles para un diseño vectorial.</li>
                <li>- Libertad de utilizar una infinidad de tipografías de diferentes estilos. <br>
                    Además de poder agregarle efectos, cambiar el tamaño, el interlineado, la rotación, etc
                </li>
                <li>- Ofrece diferentes funciones para personalizar el trazo, los guiones, los vectores,
                    las líneas, los pinceles, etc.
                </li>
            </ul>
            </p>

            <h2 class="Subtitulo">GIMP</h2>
            <img id="Img-Program" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/gimp.png">
            <p class="Text">
                GIMP es posiblemente la mejor alternativa gratis, la más potente y profesional a Photoshop. <br>
                Es un programa referente para retocar fotos por sus características muy avanzadas.
                <br><br>
                <b>CARACTERÍSTICAS:</b>
            <ul class="Text">
                <li>- Tiene muchas herramientas para manipular los colores y el aspecto de las imágenes como el enfoque,
                    eliminación de manchas, sombras, modificación de escala, etc.
                </li>
                <li>- También es capaz de importar ficheros en pdf, así como imágenes vectoriales (svg).
                </li>
                <li>- Permite la automatización de muchos procesos mediante macros.
                </li>
            </ul>
            </p>



            <h2 class="Subtitulo">Pixlr</h2>
            <img id="Img-Program" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/Pixlr_Logo1.png">
            <p class="Text">
                Es un editor online que funciona muy bien y tiene muchas variedades de fuentes, stickers, efectos, colores, etc.
                y es gratuita.
                <br>
                Su interfaz es parecida a Photoshop lo que hace que el manejo resulte familiar, facilitando encontrar la
                herramienta que buscas sin dificultades. Es una buena opción si lo que buscas es una edición rápida y versátil.
                <br><br>
                <b>CARACTERÍSTICAS:</b>
            <ul class="Text">
                <li>- Pixlr Editor, para editar fotos ofreciendo casi las mismas características que Photoshop.
                </li>
                <li>- Pixlr Express, la herramientas de diseño online para crear collages y comics
                </li>
                <li>-Tiene la particularidad de tener 3 editores online (Pixlr Editor, Pixlr Express y Pixlr App),
                    para escoger el que mejor se adapte a tus necesidades.
                </li>
            </ul>
            </p>

            <h2 class="Subtitulo">ImgFlip</h2>
            <img id="Img-Program" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/imgflip_Logo.png">
            <p class="Text">
                Imgflip es una de las herramientas más completas. <br>
                Con ella puedes incluir una imagen o una dirección
                URL de un vídeo alojado en Youtube y convertir una sección del mismo en un archivo gif.
                <br><br>
                <b>CARACTERÍSTICAS:</b>
            <ul class="Text">
                <li>- Permite cargar varias imágenes diferentes y convertirlas en un archivo gif de diapositivas.
                </li>
                <li>- Tiene opciones para personalizar el tipo de letra y tamaño de la misma.
                </li>
                <li>-Puedes subir tu propio archivo de vídeo y personalizar una parte del mismo en gif.
                </li>
            </ul>
            </p>
        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "Programas.pdf";
    $html = ob_get_clean();
    $url = "/FormImage/Programas.php";

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