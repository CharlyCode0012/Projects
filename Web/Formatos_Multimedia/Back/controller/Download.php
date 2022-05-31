<?php
ob_start();
?>

<!DOCTYPE html>
<html lang="en">

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
    <style>
        ;

        @font-face {
            font-family: 'Tangerine';
            font-style: normal;
            font-weight: 400;
            font-display: swap;
            src: url(https://fonts.gstatic.com/s/tangerine/v15/IurY6Y5j_oScZZow4VOxCZZM.woff2) format('woff2');
            unicode-range: U+0000-00FF, U+0131, U+0152-0153, U+02BB-02BC, U+02C6, U+02DA, U+02DC, U+2000-206F, U+2074, U+20AC, U+2122, U+2191, U+2193, U+2212, U+2215, U+FEFF, U+FFFD;
        }

        /* latin-ext */
        @font-face {
            font-family: 'Montserrat Alternates';
            font-style: italic;
            font-weight: 200;
            font-display: swap;
            src: url(https://fonts.gstatic.com/s/montserratalternates/v16/mFTkWacfw6zH4dthXcyms1lPpC8I_b0juU057p8dAYxK8mRBkw.woff2) format('woff2');
            unicode-range: U+0100-024F, U+0259, U+1E00-1EFF, U+2020, U+20A0-20AB, U+20AD-20CF, U+2113, U+2C60-2C7F, U+A720-A7FF;
        }

        /* latin */
        @font-face {
            font-family: 'Montserrat Alternates';
            font-style: italic;
            font-weight: 200;
            font-display: swap;
            src: url(https://fonts.gstatic.com/s/montserratalternates/v16/mFTkWacfw6zH4dthXcyms1lPpC8I_b0juU057p8dAYxE8mQ.woff2) format('woff2');
            unicode-range: U+0000-00FF, U+0131, U+0152-0153, U+02BB-02BC, U+02C6, U+02DA, U+02DC, U+2000-206F, U+2074, U+20AC, U+2122, U+2191, U+2193, U+2212, U+2215, U+FEFF, U+FFFD;
        }

        .Titulo-Gothic {
            margin-left: -85px;
            padding: 0 0px;
            color: #737ef2;
            font-family: 'Tangerine', cursive;
            font-size: 58px;
            text-shadow: 4px 4px 4px #aaa;
            margin-bottom: 10px;

        }

        .Text {
            font-size: 20px;
            font-family: Cambria, Cochin, Georgia, Times, 'Times New Roman', serif;
        }

        /*
    Seccion de resumen
*/

        .Cont-Info {
            width: 100%;
            height: 100;
            padding: 50px 20px;


        }

        .Cont-Info__Text {
            margin: auto;
            margin-bottom: 100px;
            width: auto;
            overflow: auto;
        }

        .Cont-Info__Text img {
            float: right;
            width: 350px;
            height: 350px;
            margin-right: 18px;
            margin-left: 18px;
        }

        #ascii {
            margin-top: 30px;
            float: left;
            width: 350px;
            height: 350px;
            margin-right: 18px;
            margin-left: -10px;
        }

        .Cont-Info__Text h1 {
            padding: 0 45%;
        }

        .Cont-Info__Text h1 img {
            padding: 200px;
        }



        .Subtitulo {
            margin: 60px 0;
            font-size: 38px;
            font-family: 'Montserrat Alternates', sans-serif;
            text-shadow: 4px 4px 4px rgb(49, 49, 49) !important;
        }

        .Cont-Info__Form {
            display: flex;
            justify-content: center;
            align-items: center;
            width: content;
            margin-bottom: 30px;
        }

        .Cont-Info__Form-Button {
            font-size: 20px;
            background-color: #a873de;
            margin: 30px 0;
            width: 150px;
            height: 50px;
            border-radius: 10px;
        }

        .Cont-Info__Form-Button:hover {
            cursor: pointer;
            background-color: #9349dd;
            transition: 0.5s all ease;
        }

        #Center {
            height: 200px;
            width: 300px;
            display: inline-block;
            margin-bottom: 0px;
            margin-right: 38%;
            margin-top: 60px;
        }

        #PDF {
            height: 200px;
            width: 350px;
            display: inline-block;
            margin-bottom: 0px;
            margin-right: 38%;
            margin-top: 60px;
        }

        #Img-Program {

            height: 200px;
            width: 200px;
            float: left;
        }

        .Negritas {

            font-style: italic;
        }
    </style>
    <title>Document</title>
</head>

<body>
    <?php
    include "DB.php";



    $bd = new BaseDeDatos();
    $arr = array();

    $arr = $bd->consulta();

    $file = $arr[0];
    $url = $arr[1];
    $html = $arr[2];
    echo ($html);
    $html1 = ob_get_clean();
    require_once '../../Back/libreria/dompdf/autoload.inc.php';

    use Dompdf\Dompdf;

    $dompdf = new Dompdf();

    $options = $dompdf->getOptions();
    $options->set(array('isRemoteEnabled' => true));
    $dompdf->setOptions($options);

    $dompdf->loadHtml($html1);
    $dompdf->setPaper('letter');

    $dompdf->render();
    $dompdf->stream("$file", array("Attachment" => false));
    header("Location: ../../Resumenes" . $url);

    ?>
</body>

</html>

<?php
die();
?>