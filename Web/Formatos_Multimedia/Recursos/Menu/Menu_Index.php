<!DOCTYPE html>
<html lang="en">
<head>
    
    <link rel="stylesheet" href="../CSS/Normalize.css">
    <link rel="stylesheet" href="../CSS/DOM/Menu.css">
    <link rel="stylesheet" href="../../Font-Awesome/css/all.css">
    
    <title>Menu Index</title>
</head>
<body>
    <nav class="Menu">
        <input type="checkbox" id="check">
        <label class="Menu__CheckBtn" for="check">
            <i class="fa-solid fa-bars"></i>
        </label>
        <a class="Menu__Logo" href=""><img class="Menu__Logo-Img" src="" alt=""></a>
        <ul class="Menu__Opciones">
            <li><a href="Index.php"><i class="fa-solid fa-house"></i>Home</a></li>
            <li><a href="FormText.php">Formato de Texto</a></li>
            <li><a href="FormImage.php">Formato de imagen</a></li>
        </ul>
    </nav>
    <section></section>
    <script
        src="https://code.jquery.com/jquery-3.6.0.min.js"
        integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4="
        crossorigin="anonymous">
    </script>
    <script>
        $(document).ready(function(){
            $('li').on('click', function(){
                $(this).siblings().removeClass('active');
                $(this).addClass('active');
            })
        })
    </script>
</body>
</html>