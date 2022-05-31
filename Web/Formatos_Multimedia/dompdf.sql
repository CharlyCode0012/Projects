-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 14-03-2022 a las 03:22:14
-- Versión del servidor: 10.4.22-MariaDB
-- Versión de PHP: 8.1.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `dompdf`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `dom`
--

CREATE TABLE `dom` (
  `id` int(11) NOT NULL,
  `nombre` varchar(200) DEFAULT NULL,
  `url1` varchar(200) DEFAULT NULL,
  `html` varchar(21300) CHARACTER SET utf8 DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `dom`
--

INSERT INTO `dom` (`id`, `nombre`, `url1`, `html`) VALUES
(1, 'WMF.pdf', '/FormImage/WMF.php', '    <div class=\"Cont-Info\">\r\n        <div class=\"Cont-Info__Text\">\r\n            <img id=\"Center\" src=\"http://localhost/Pagina Sistemas/Recursos/IMG/WMF_Logo.png\">\r\n\r\n            <br><br><br><br><br><br><br><br><br><br>\r\n            <h1 class=\"Titulo-Gothic\"> WMF </h1>\r\n            <h2 class=\"Subtitulo\">¿Qué es?</h2>\r\n\r\n            <p class=\"Text\">\r\n                Es un formato de gráficos vectoriales que permite\r\n                también la inclusión de mapas de bits.\r\n                <br><br>\r\n                Almacena una secuencia de llamadas a funciones\r\n                que son enviadas al nivel gráfico de Windows GDI\r\n                (Graphics Device Interface) para regenerar la imagen.\r\n                <br>\r\n                Es similar en propósito y diseño al formato\r\n                PostScript.\r\n            </p>\r\n\r\n            <h2 class=\"Subtitulo\">Última modificación</h2>\r\n\r\n            <p class=\"Text\">\r\n                La última versión salió en 2006 la cuál solucionó los problemas encontrados en 2005, lo cual\r\n                era una vulnerabilidad en el sistema que le permitia a otros usuarios poner código malicioso\r\n                a tra ves de una imagen.\r\n            </p>\r\n\r\n            <img id=\"ascii\" src=\"http://localhost/Pagina Sistemas/Recursos/IMG/WMF.png\">\r\n\r\n            <br><br>\r\n            <h2 class=\"Subtitulo\">¿Para qué se creó?</h2>\r\n\r\n            <p class=\"Text\">\r\n                Fue diseñado para ser ejecutado por la capa de gráficos de Windows GDI, a fin de restaurar la imagen,\r\n                aunque como los archivos WMF contienen la definición gráfica que constituye esta imagen, es posible\r\n                diseñar alternativas que convierten los WMF en archivos binarios\r\n            </p>\r\n\r\n            <br><br>\r\n            <h2 class=\"Subtitulo\">¿Qué se logró?</h2>\r\n\r\n            <p class=\"Text\">\r\n                Se consiguión un formato de archivo el cual es compatible con sisteas Windows además de rediseñar la imagen\r\n                de una mejor manera, transmitir dichos archivos a otros dispositivos.\r\n                <br><br>\r\n                Contienen una secuencia de registros de longitud\r\n                variable con gráficos, comandos de dibujo, propiedades\r\n                y definiciones de objetos. La extensión del archivo WMF\r\n                <br>\r\n                Tiene una plaeta de colores de: 16,777, 216 , es decir 24bits\r\n                <br>\r\n            </p>\r\n        </div>\r\n    </div>\r\n\r\n    ');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `dom`
--
ALTER TABLE `dom`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `dom`
--
ALTER TABLE `dom`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
