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
    <link rel="shortcut icon" href="../../Recursos/IMG/PNG_Logo.png">
    <title>PNG</title>
</head>

<body>
    <script src="../../Recursos/Menu/Menu2.JS"></script>
    <?php
    ob_start();
    ?>
    <div class="Cont-Info">
        <div class="Cont-Info__Text">
            <img id="Center" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/PNG_Logo.png">

            <br><br><br><br><br><br><br><br><br><br>
            <h1 class="Titulo-Gothic"> PNG </h1>
            <h2 class="Subtitulo">¿Qué es?</h2>

            <p class="Text">
                El PNG development group en 1996-1997, liderado por Thomas Boutell; fue un grupo informal coordinado por
                e-mail.
                <br><br>
                Es un formato de archivo extensible para un almacenaje de imágenes rasterizadas sin pérdidas, portable y
                bien comprimido.
                <br>
                Puede usarse como reemplazo libre de patente para GIF, así como reemplaza muchos usos comunes de TIFF.

                <br><br>
                Está conformado por 2 partes:
                <br><br>
            <ol class="Text">
                <li>
                    <b>1.</b> Predicción: <br>

                    -Usa hasta 5 métodos de filtrado que predicen los pixeles que aparecerán en base a
                    los pixeles previos de cada línea, estos métodos de filtrado facilitan la compresión.
                </li><br>
                <li>
                    <b>2.</b> Compresión: <br>
                    – Usa el algoritmo Deflate, codificando imágenes aprovechando valores repetidos.
                    <br><br>
                    <ul class="Text">
                        La firma en 8 bytes: <i><b class="Negritas">89 50 4E 47 0D 0A 1A 0A</b></i>
                        <img id="ascii" src="http://<?php echo $_SERVER['HTTP_HOST'] ?>/Pagina Sistemas/Recursos/IMG/ejemPNG.png">
                        <li>
                            <b>89</b> – Detecta sistemas de transmisión que no soportan data a 8 bits.
                        </li>
                        <li>
                            <b>50 4E 47</b> – “PNG”, en ASCII.
                        </li>
                        <li>
                            <b> 0D 0A </b>– Nueva línea en estilo DOS, para conversiones DOS-Unix.
                        </li>
                        <li>
                            <b>1A</b> – Detiene al posible comando TYPE para ver el archivo en estilo DOS.
                        </li>
                        <li>
                            <b> 0A </b> – Nueva línea Unix para conversiones DOS-Unix.
                        </li>
                    </ul>
                </li>
            </ol>
            </p>



            <br><br>
            <h2 class="Subtitulo">¿Qué se logró?</h2>

            <p class="Text">
                Se logro un archivo compacto con una gran calidad de imagen, además de que es el ideal
                para usarlo en apps móviles o webs, ya que no es muy pesado, por lo que su descarga es rápida y amigable.
            </p>

        </div>
    </div>
    <?php

    $db = new BaseDeDatos();

    $file = "PNG.pdf";
    $html = ob_get_clean();
    $url = "/FormImage/PNG.php";

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