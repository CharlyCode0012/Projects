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
    <link rel="shortcut icon" href="../../Recursos/IMG/Pdf.svg">
    <title>PDF</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <div class="Cont-Info">
        <?php
        ob_start();
        ?>
        <div class="Cont-Info__Text">
            <img id="PDF" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/pdfLogo.png">

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic"> PDF </h1>
            <h2 class="Subtitulo">¿Qué es?</h2>

            <p class="Text">
                El formato PDF (Portable Document Format, Formato de documento portátil) es un formato de archivo universal que conserva las fuentes,
                las imágenes y la maquetación de los documentos originales creados en una amplia gama de aplicaciones y plataformas.
                <br><br>
                Es decir este formato es independiente de plataformas, de software o hardware.
                <br><br>
            </p>

            <h2 class="Subtitulo">Última modificación</h2>

            <p class="Text">
                La versión original 1.7 del formato PDF se lanzó en noviembre de 2006 y se asoció con Acrobat y Adobe Reader 8.0.
                <br>
                La versión 1.7 se publicó como ISO 32000-1 en julio de 2008.
                <br><br>
                Entre otras novedades, esta versión de PDF introduce un mecanismo de extensibilidad basado en un Diccionario de
                Extensiones.
                <br> <br>
                Adobe utilizó este mecanismo para introducir nuevas funciones, pero también está disponible para que otros
                proveedores o desarrolladores lo utilicen para establecer extensiones publicadas.
            </p>

            <img id="ascii" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/Pdf.png">

            <br><br>
            <h2 class="Subtitulo">¿Para qué se creó?</h2>

            <p class="Text">
                Para presentar e intercambiar documentos de forma fiable, independiente del software, el hardware, o el sistema operativo
            </p>

            <br><br><br>
            <h2 class="Subtitulo">¿Qué se logró?</h2>

            <p class="Text">
                Se consiguión un archivo universal, el cual es compatible en cualquier sistema,
                además de que es una forma de hacer menos pesados los archivos de texto, como los .docx,
                los rtf, pptx, entre otros.
                Además de que gracias a ello se puede generar pdf del contenido de una página web, ya que es fiel a su contenido.
            </p>
        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "_PDF.pdf";
    $html = ob_get_clean();
    $url = "/FormText/PDF.php";

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