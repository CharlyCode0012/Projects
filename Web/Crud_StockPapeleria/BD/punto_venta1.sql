-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 30, 2022 at 10:47 PM
-- Server version: 10.4.21-MariaDB
-- PHP Version: 8.0.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `punto_venta1`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `SumFacturas` (IN `Proveedor` TINYINT)  BEGIN
    SELECT SUM(Imp_N) 
    FROM Factura
    WHERE FK_Id_Prov = Proveedor;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `cliente`
--

CREATE TABLE `cliente` (
  `PK_Id_Cli` smallint(6) NOT NULL,
  `Nom_C` varchar(180) NOT NULL,
  `Ap1_C` varchar(100) DEFAULT NULL,
  `Puntos` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `cliente`
--

INSERT INTO `cliente` (`PK_Id_Cli`, `Nom_C`, `Ap1_C`, `Puntos`) VALUES
(1, 'Emiliano', 'Gonzalez', 20),
(2, 'Issac', 'Robles', 0);

-- --------------------------------------------------------

--
-- Table structure for table `empleado`
--

CREATE TABLE `empleado` (
  `PK_Id_Emp` tinyint(4) NOT NULL,
  `Nom_E` varchar(180) NOT NULL,
  `Ap1_E` varchar(100) NOT NULL,
  `Ap2_E` varchar(100) NOT NULL,
  `Adm` bit(1) NOT NULL,
  `FN_E` date NOT NULL,
  `CURP_E` char(18) NOT NULL,
  `RFC_E` varchar(13) NOT NULL,
  `Contra_E` varchar(150) NOT NULL,
  `Direc_E` varchar(250) NOT NULL,
  `Nom_UE` varchar(180) NOT NULL,
  `FK_Id_Mun` tinyint(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `empleado`
--

INSERT INTO `empleado` (`PK_Id_Emp`, `Nom_E`, `Ap1_E`, `Ap2_E`, `Adm`, `FN_E`, `CURP_E`, `RFC_E`, `Contra_E`, `Direc_E`, `Nom_UE`, `FK_Id_Mun`) VALUES
(1, 'CARLOS DANIEL', 'Lozano', 'Vazquez', b'1', '2003-01-17', 'LOVC030117HJCZZRA3', 'LOVC030117A65', '0906Gean.0906', 'Calle Laurel 10, Col. Higuera', 'DarkKnight', 120),
(2, 'Emilio', 'Camarena', 'Nava', b'0', '2003-05-17', 'CANE030517HJCMVMB2', 'CANE030517B27', 'CaNava012', 'Calle Vergeles 12, Col Tabachines', 'CaNavaEmi', 120),
(3, 'Charly', 'sada', 'sdad', b'1', '2003-01-17', 'LOVC030117HJCZZRA3', 'LOVC030117A8', '63829939523e1bbab7158436f52d927b3659fca8', 'LAUREL', 'Danny', 120);

-- --------------------------------------------------------

--
-- Table structure for table `factura`
--

CREATE TABLE `factura` (
  `PK_No_Factura` smallint(6) NOT NULL,
  `F_Factura` date DEFAULT NULL,
  `Imp_N` float NOT NULL,
  `FK_Id_Emp` tinyint(4) DEFAULT NULL,
  `FK_Id_Prov` tinyint(4) DEFAULT NULL,
  `FK_No_FactD` smallint(6) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `facturad`
--

CREATE TABLE `facturad` (
  `PK_No_FactD` smallint(6) NOT NULL,
  `Cantidad` smallint(6) NOT NULL,
  `Precio_Un` float NOT NULL,
  `Precio_L` float NOT NULL,
  `Imp_B` float NOT NULL,
  `FK_Id_Prod` smallint(6) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `marca`
--

CREATE TABLE `marca` (
  `PK_Id_Marca` int(11) NOT NULL,
  `Nom_Marc` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `marca`
--

INSERT INTO `marca` (`PK_Id_Marca`, `Nom_Marc`) VALUES
(1, 'Paper Mate'),
(2, 'Bic'),
(3, 'Vinci'),
(4, 'Pelikan'),
(5, 'Escolar'),
(6, 'Baco'),
(7, 'Scribe'),
(8, 'Estrella'),
(9, 'Barrilito'),
(10, 'Crayola'),
(11, 'Top'),
(12, 'MAE'),
(13, 'CASIO'),
(14, 'Azor'),
(15, 'Signal'),
(16, 'Berol'),
(17, 'Fiero'),
(18, 'Tuk'),
(19, 'Prismacolor'),
(20, 'Leoncito'),
(21, 'Mapita'),
(22, 'Magistral '),
(23, 'Libre');

-- --------------------------------------------------------

--
-- Table structure for table `municipio`
--

CREATE TABLE `municipio` (
  `PK_Id_Mun` tinyint(4) NOT NULL,
  `Nom_Mun` varchar(250) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `municipio`
--

INSERT INTO `municipio` (`PK_Id_Mun`, `Nom_Mun`) VALUES
(1, 'Acatic'),
(2, 'Acatlan de Juarez'),
(3, 'Ahualulco de Mercado'),
(4, 'Amacueca'),
(5, 'Amatitan'),
(6, 'Ameca'),
(7, 'Arandas'),
(8, 'Atemajac de Brizuela'),
(9, 'Atengo'),
(10, 'Atenguillo '),
(11, 'Atotonilco el Alto'),
(12, 'Atoyac'),
(13, 'Autlan de Navarro'),
(14, 'Ayotlan'),
(15, 'Ayutla'),
(16, 'Bolanos'),
(17, 'Cabo Corrientes'),
(18, 'Canadas de Obregon '),
(19, 'Casimiro Castillo'),
(20, 'Chapala'),
(21, 'Chimaltitan '),
(22, 'Chiquilistlan'),
(23, 'Cihuatlan'),
(24, 'Cocula'),
(25, 'Colotlan'),
(26, 'Concepcion de Buenos Aires'),
(27, 'Cuautitlan de Garcia Barragan'),
(28, 'Cuautla '),
(29, 'Cuquio'),
(30, 'Degollado'),
(31, 'Ejutla '),
(32, 'El Arenal'),
(33, 'El Grullo'),
(34, 'El Limon'),
(35, 'El Salto'),
(36, 'Encarnacion de Diaz'),
(37, 'Etzatlan'),
(38, 'Gomez Farias'),
(39, 'Guachinango '),
(40, 'Guadalajara'),
(41, 'Hostotipaquillo'),
(42, 'Huejucar'),
(43, 'Huejuquilla el Alto'),
(44, 'Ixtlahuacan de los Membrillos'),
(45, 'Ixtlahuacan del Rio'),
(46, 'Jalostotitlan'),
(47, 'Jamay'),
(48, 'Jesus Maria'),
(49, 'Jilotlan de los Dolores'),
(50, 'Jocotepec'),
(51, 'Juanacatlan'),
(52, 'Juchitlan'),
(53, 'La Barca'),
(54, 'La Huerta'),
(55, 'La Manzanilla de la Paz '),
(56, 'Lagos de Moreno'),
(57, 'Magdalena'),
(58, 'Mascota'),
(59, 'Mazamitla'),
(60, 'Mexticacan'),
(61, 'Mezquitic '),
(62, 'Mixtlan '),
(63, 'Ocotlan'),
(64, 'Ojuelos de Jalisco'),
(65, 'Pihuamo'),
(66, 'Poncitlan'),
(67, 'Puerto Vallarta'),
(68, 'Quitupan'),
(69, 'San Cristobal de la Barranca '),
(70, 'San Diego de Alejandria'),
(71, 'San Gabriel'),
(72, 'San Ignacio Cerro Gordo'),
(73, 'San Juan de los Lagos'),
(74, 'San Juanito de Escobedo'),
(75, 'San Julian'),
(76, 'San Marcos '),
(77, 'San Martin de Bolanos '),
(78, 'San Martin Hidalgo'),
(79, 'San Miguel el Alto'),
(80, 'San Pedro Tlaquepaque'),
(81, 'San Sebastian del Oeste'),
(82, 'Santa Maria de los angeles '),
(83, 'Santa Maria del Oro '),
(84, 'Sayula'),
(85, 'Tala'),
(86, 'Talpa de Allende'),
(87, 'Tamazula de Gordiano'),
(88, 'Tapalpa'),
(89, 'Tecalitlan'),
(90, 'Techaluta de Montenegro '),
(91, 'Tecolotlan'),
(92, 'Tenamaxtlan'),
(93, 'Teocaltiche'),
(94, 'Teocuitatlan de Corona'),
(95, 'Tepatitlan de Morelos'),
(96, 'Tequila'),
(97, 'Teuchitlan'),
(98, 'Tizapan el Alto'),
(99, 'Tlajomulco de Zuniga'),
(100, 'Toliman'),
(101, 'Tomatlan'),
(102, 'Tonala'),
(103, 'Tonaya'),
(104, 'Tonila'),
(105, 'Totatiche'),
(106, 'Tototlan'),
(107, 'Tuxcacuesco '),
(108, 'Tuxcueca'),
(109, 'Tuxpan'),
(110, 'Union de San Antonio'),
(111, 'Union de Tula'),
(112, 'Valle de Guadalupe'),
(113, 'Valle de Juarez'),
(114, 'Villa Corona'),
(115, 'Villa Guerrero'),
(116, 'Villa Hidalgo'),
(117, 'Villa Purificacion'),
(118, 'Yahualica de Gonzalez Gallo'),
(119, 'Zacoalco de Torres'),
(120, 'Zapopan'),
(121, 'Zapotiltic'),
(122, 'Zapotitlan de Vadillo');

-- --------------------------------------------------------

--
-- Table structure for table `producto`
--

CREATE TABLE `producto` (
  `PK_Id_Prod` smallint(6) NOT NULL,
  `No_Exis` smallint(6) DEFAULT NULL,
  `Precio` float NOT NULL,
  `Descripcion` varchar(250) NOT NULL,
  `FK_Id_Marca` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `producto`
--

INSERT INTO `producto` (`PK_Id_Prod`, `No_Exis`, `Precio`, `Descripcion`, `FK_Id_Marca`) VALUES
(1, 29, 4.5, 'lapiz No. 2', 12),
(2, 34, 5, 'Lapiz No.2 Mirado Hexagonal', 1),
(3, 43, 5, 'Lapiz No.2 Triangular', 4),
(4, 48, 5, 'Pluma de cristal Color Negra', 2),
(5, 34, 5, 'Pluma de cristal Color Azul', 2),
(6, 30, 5, 'Pluma de Cristal Color Verde', 2),
(7, 28, 5, 'Pluma de cristal color Roja', 2),
(8, 18, 5, 'Pluma Kilometrica Azul', 1),
(9, 8, 5, 'Pluma Kilometrica Negra', 1),
(10, 43, 5, 'Pluma Kilometrica Verde', 1),
(11, 58, 5, 'Pluma Kilometrica Roja', 1),
(12, 44, 5, 'Pluma Kilometrica Punta Fina Roja', 1),
(13, 44, 5, 'Pluma Kilometrica Punta Fina Azul', 1),
(14, 18, 5, 'Pluma Kilometrica Punta Fina Negra', 1),
(15, 26, 5, 'Pluma Kilometrica verde pastel', 1),
(16, 44, 5, 'Pluma Kilometrica azul pastel', 1),
(17, 14, 5, 'Pluma Kilometrica rosa pastel', 1),
(18, 21, 5, 'Pluma Kilometrica Morada ', 1),
(19, 28, 5, 'Pluma Kilometrica naranja ', 1),
(20, 47, 5, 'Bicolor tamaÃ±o de lapiz No.2', 4),
(21, 36, 11, 'Bicolor Grande', 4),
(22, 4, 1.5, 'Zacapuntas plastico', 12),
(23, 21, 7, 'Zacapuntas metal', 12),
(24, 4, 10, 'Zacapuntas metal 2ble entrada', 12),
(25, 35, 18, 'Corrector de estilo pluma ', 2),
(26, 31, 13, 'Corrector de estilo brocha', 2),
(27, 31, 3, 'Borrador Blanco', 4),
(28, 10, 3, 'Borrador Migajon pequeÃ±o', 12),
(29, 59, 6, 'Borrador Migajon Grande', 12),
(30, 44, 12, 'Pintura de agua Roja', 3),
(31, 15, 12, 'Pintura de agua Morada', 3),
(32, 31, 12, 'Pintura de agua  Verde', 3),
(33, 37, 12, 'Pintura  de agua Gris', 3),
(34, 25, 12, 'Pintura  de agua CafÃ©', 3),
(35, 20, 12, 'Pintura de agua Celeste', 3),
(36, 18, 12, 'Pintura  de agua Amarilla', 3),
(37, 40, 12, 'Pintura  de agua Naranja', 3),
(38, 46, 12, 'Pintura  de agua Durazno', 3),
(39, 48, 12, 'Pintura  de agua Negra', 3),
(40, 50, 12, 'Pintura de agua Blanca', 3),
(41, 57, 12, 'Pintura  de agua Azul Marino', 3),
(42, 15, 12, 'Pintura  de agua Verde Limon', 3),
(43, 39, 30, 'Colores de 12 pz. ', 20),
(44, 55, 70, 'Colores de 12 pz. Fantasy', 1),
(45, 28, 157, 'Colores de 24 pz.', 19),
(46, 32, 94, 'Colores de 24 pz.', 10),
(47, 27, 20, 'Colores de 12 pz.', 21),
(48, 11, 15, 'Marcatextos Naranja', 14),
(49, 14, 15, 'Marcatextos Azul', 14),
(50, 46, 15, 'Marcatextos Verde', 14),
(51, 31, 15, 'Marcatextos Amarillo', 14),
(52, 33, 15, 'Marcatextos Rosa', 14),
(53, 11, 15, 'Marcatextos Rojo', 14),
(54, 38, 12, 'Marcador de Agua Azul', 4),
(55, 5, 12, 'Marcador de Agua Verde', 4),
(56, 57, 12, 'Marcador de Agua Rosa', 4),
(57, 55, 12, 'Marcador de Agua Morado', 4),
(58, 29, 12, 'Marcador de Agua Gris', 4),
(59, 11, 12, 'Marcador de Agua Rojo', 4),
(60, 58, 12, 'Marcador de Agua Negro', 4),
(61, 18, 12, 'Marcador de Agua CafÃ©', 4),
(62, 47, 12, 'Marcador de Agua Amarillo', 4),
(63, 53, 12, 'Marcador de Agua Naranja', 4),
(64, 38, 26, 'Marcador de aceite 2ble punta Azul', 15),
(65, 13, 26, 'Marcador de aceite 2ble punta Negro', 15),
(67, 47, 18, 'Marcador de Aceite Azul', 16),
(68, 37, 17, 'Marcador para pintarron Negro', 22),
(69, 32, 17, 'Marcador para pintarron Azul', 22),
(70, 60, 17, 'Marcador para pintarron Verde', 22),
(71, 60, 17, 'Marcador para pintarron Rojo', 22),
(72, 54, 15, 'Marcador de cera rojo', 4),
(73, 18, 15, 'Marcador de cera Azul', 4),
(74, 51, 15, 'Marcador de cera Verde', 4),
(75, 30, 10, 'Plastilina Verde', 5),
(76, 34, 10, 'Plastilina roja', 5),
(77, 32, 10, 'Plastilina Azul', 5),
(78, 56, 10, 'Plastilina CafÃ©', 5),
(79, 25, 10, 'Plastilina Gris', 5),
(80, 26, 10, 'Plastilina Rosa', 5),
(81, 18, 10, 'Plastilina Blanca', 5),
(82, 41, 10, 'Plastilina Negra', 5),
(83, 39, 10, 'Plastilina Verde Limon', 5),
(84, 54, 10, 'Plastilina celeste', 5),
(85, 30, 10, 'Plastilina Naranja', 5),
(86, 20, 10, 'Plastilina amarilla', 5),
(87, 46, 10, 'Plastilina Morada', 5),
(88, 87, 5, 'Cartulina Azul pastel', 23),
(89, 100, 5, 'Cartulina Rosa pastel', 23),
(90, 21, 5, 'Cartulina Verde Pastel', 23),
(91, 95, 4, 'Cartulina blanca', 23),
(92, 16, 7, 'Cartulina Azul Marino', 23),
(93, 62, 7, 'Cartulina Roja', 23),
(94, 36, 7, 'Cartulina Morada', 23),
(95, 58, 7, 'Cartulina Negra', 23),
(96, 65, 7, 'Cartulina Naranja', 23),
(97, 83, 7, 'Cartulina Verde Bandera', 23),
(98, 94, 32, 'juego de geometria', 6),
(99, 68, 160, 'Calculadora cientifica', 13),
(100, 4, 40, 'Abaco', 6),
(101, 11, 20, 'Cuaderno profesional Raya', 7),
(102, 88, 20, 'Cuaderno profesional 2ble Raya', 7),
(103, 64, 20, 'Cuaderno profesional Cuadro Chico', 7),
(104, 52, 20, 'Cuaderno profesional Cuadro Grande', 7),
(105, 58, 20, 'Cuaderno profesional dibujo', 7),
(106, 57, 20, 'Cuaderno profesional Mixto', 7),
(107, 93, 15, 'Cuaderno forma francesa espiral Raya', 7),
(108, 84, 15, 'Cuaderno forma francesa espiral 2ble raya', 7),
(109, 23, 15, 'Cuaderno forma francesa espiral Cuadro Grande', 7),
(110, 79, 15, 'Cuaderno forma francesa espiral Cuadro chico', 7),
(111, 7, 15, 'Cuaderno forma francesa espiral Dibujo', 7),
(112, 62, 15, 'Cuaderno forma Italiana espiral Raya', 8),
(113, 58, 15, 'Cuaderno forma Italiana espiral 2ble raya', 8),
(114, 28, 15, 'Cuaderno forma Italiana espiral Cuadro Grande', 8),
(115, 44, 15, 'Cuaderno forma Italiana espiral Cuadro chico', 8),
(116, 92, 15, 'Cuaderno forma Italiana espiral Dibujo', 8),
(117, 8, 180, 'Recopilador', 7),
(118, 68, 32, '100 Hojas para recopilador Raya', 7),
(119, 35, 32, '100 Hojas para recopilador 2ble Raya', 7),
(120, 42, 32, '100 Hojas para recopilador Cuadro chico', 7),
(121, 95, 32, '100 Hojas para recopilador Cuadro grande', 7),
(122, 47, 9, 'Tijeras', 9),
(123, 52, 10, 'Regla madera', 9),
(124, 54, 15, 'Regla metalica', 9),
(125, 30, 6, 'Regla plastico', 9),
(126, 82, 17, 'Regla flexible', 12),
(127, 34, 6, 'Transportador', 9),
(128, 73, 45, 'calculadora basica', 9),
(129, 59, 60, 'Pistola de silicon', 9),
(130, 10, 2, 'Barra de silicon', 23),
(131, 60, 5, 'Cinta diurex', 18),
(132, 90, 20, 'Cinta masking tape', 18),
(133, 96, 30, 'Cinta canela', 18),
(134, 41, 28, 'Cinta diurex grande', 18),
(135, 35, 9, 'Resistol de barra 7gr', 11),
(136, 62, 16, 'Resitol de barra 16gr', 11),
(137, 61, 19, 'Resitol de barra 20gr', 11),
(138, 99, 24, 'Resistol de barra 27 gr', 11),
(139, 2, 20, 'Rafia verde', 17),
(140, 12, 20, 'Rafia CafÃ©', 17),
(141, 35, 20, 'Rafia blanca', 17),
(142, 17, 20, 'Rafia amarilla', 17),
(143, 30, 32, 'Crayolas 12 pz', 10),
(144, 20, 23, 'Crayolas pequenias 12 pz', 10),
(145, 37, 10, 'Crayolas pequenias 8 pz', 23),
(146, 55, 60, 'Bote con crayolas 24 pzas', 4);

-- --------------------------------------------------------

--
-- Table structure for table `proveedor`
--

CREATE TABLE `proveedor` (
  `PK_Id_Prov` tinyint(4) NOT NULL,
  `Nom_P` varchar(180) NOT NULL,
  `Direc_P` varchar(250) NOT NULL,
  `Tel_P` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `proveedor`
--

INSERT INTO `proveedor` (`PK_Id_Prov`, `Nom_P`, `Direc_P`, `Tel_P`) VALUES
(1, 'Sajor', 'Calle Rio Juarez No. 1447, Col. El Rosario. C.P. 44898, Guadalajara, Jalisco México.', '33 3942 7070');

-- --------------------------------------------------------

--
-- Table structure for table `ticket`
--

CREATE TABLE `ticket` (
  `PK_No_Ticket` smallint(6) NOT NULL,
  `Precio_Lin` float NOT NULL,
  `Total_B` float NOT NULL,
  `Total_N` float NOT NULL,
  `F_Ven` date DEFAULT NULL,
  `FK_Id_Prod` smallint(6) DEFAULT NULL,
  `FK_Id_Emp` tinyint(4) DEFAULT NULL,
  `FK_Id_Cli` smallint(6) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Triggers `ticket`
--
DELIMITER $$
CREATE TRIGGER `t_puntos` AFTER INSERT ON `ticket` FOR EACH ROW BEGIN
UPDATE cliente SET puntos = puntos+10 
WHERE pk_id_cli = new.fk_id_cli;
END
$$
DELIMITER ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cliente`
--
ALTER TABLE `cliente`
  ADD PRIMARY KEY (`PK_Id_Cli`);

--
-- Indexes for table `empleado`
--
ALTER TABLE `empleado`
  ADD PRIMARY KEY (`PK_Id_Emp`),
  ADD KEY `FK_Id_Mun` (`FK_Id_Mun`);

--
-- Indexes for table `factura`
--
ALTER TABLE `factura`
  ADD PRIMARY KEY (`PK_No_Factura`),
  ADD KEY `FK_Id_Emp` (`FK_Id_Emp`),
  ADD KEY `FK_Id_Prov` (`FK_Id_Prov`),
  ADD KEY `FK_No_FactD` (`FK_No_FactD`);

--
-- Indexes for table `facturad`
--
ALTER TABLE `facturad`
  ADD PRIMARY KEY (`PK_No_FactD`),
  ADD KEY `FK_Id_Prod` (`FK_Id_Prod`);

--
-- Indexes for table `marca`
--
ALTER TABLE `marca`
  ADD PRIMARY KEY (`PK_Id_Marca`);

--
-- Indexes for table `municipio`
--
ALTER TABLE `municipio`
  ADD PRIMARY KEY (`PK_Id_Mun`);

--
-- Indexes for table `producto`
--
ALTER TABLE `producto`
  ADD PRIMARY KEY (`PK_Id_Prod`),
  ADD KEY `FK_Id_Marca` (`FK_Id_Marca`);

--
-- Indexes for table `proveedor`
--
ALTER TABLE `proveedor`
  ADD PRIMARY KEY (`PK_Id_Prov`);

--
-- Indexes for table `ticket`
--
ALTER TABLE `ticket`
  ADD PRIMARY KEY (`PK_No_Ticket`),
  ADD KEY `FK_Id_Emp` (`FK_Id_Emp`),
  ADD KEY `FK_Id_Prod` (`FK_Id_Prod`),
  ADD KEY `FK_Id_Cli` (`FK_Id_Cli`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `cliente`
--
ALTER TABLE `cliente`
  MODIFY `PK_Id_Cli` smallint(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `empleado`
--
ALTER TABLE `empleado`
  MODIFY `PK_Id_Emp` tinyint(4) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `factura`
--
ALTER TABLE `factura`
  MODIFY `PK_No_Factura` smallint(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `facturad`
--
ALTER TABLE `facturad`
  MODIFY `PK_No_FactD` smallint(6) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `marca`
--
ALTER TABLE `marca`
  MODIFY `PK_Id_Marca` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT for table `municipio`
--
ALTER TABLE `municipio`
  MODIFY `PK_Id_Mun` tinyint(4) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=123;

--
-- AUTO_INCREMENT for table `producto`
--
ALTER TABLE `producto`
  MODIFY `PK_Id_Prod` smallint(6) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=147;

--
-- AUTO_INCREMENT for table `proveedor`
--
ALTER TABLE `proveedor`
  MODIFY `PK_Id_Prov` tinyint(4) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `ticket`
--
ALTER TABLE `ticket`
  MODIFY `PK_No_Ticket` smallint(6) NOT NULL AUTO_INCREMENT;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `empleado`
--
ALTER TABLE `empleado`
  ADD CONSTRAINT `empleado_ibfk_1` FOREIGN KEY (`FK_Id_Mun`) REFERENCES `municipio` (`PK_Id_Mun`);

--
-- Constraints for table `factura`
--
ALTER TABLE `factura`
  ADD CONSTRAINT `factura_ibfk_1` FOREIGN KEY (`FK_Id_Emp`) REFERENCES `empleado` (`PK_Id_Emp`),
  ADD CONSTRAINT `factura_ibfk_2` FOREIGN KEY (`FK_Id_Prov`) REFERENCES `proveedor` (`PK_Id_Prov`),
  ADD CONSTRAINT `factura_ibfk_3` FOREIGN KEY (`FK_No_FactD`) REFERENCES `facturad` (`PK_No_FactD`);

--
-- Constraints for table `facturad`
--
ALTER TABLE `facturad`
  ADD CONSTRAINT `facturad_ibfk_1` FOREIGN KEY (`FK_Id_Prod`) REFERENCES `producto` (`PK_Id_Prod`);

--
-- Constraints for table `producto`
--
ALTER TABLE `producto`
  ADD CONSTRAINT `producto_ibfk_1` FOREIGN KEY (`FK_Id_Marca`) REFERENCES `marca` (`PK_Id_Marca`);

--
-- Constraints for table `ticket`
--
ALTER TABLE `ticket`
  ADD CONSTRAINT `ticket_ibfk_1` FOREIGN KEY (`FK_Id_Emp`) REFERENCES `empleado` (`PK_Id_Emp`),
  ADD CONSTRAINT `ticket_ibfk_2` FOREIGN KEY (`FK_Id_Prod`) REFERENCES `producto` (`PK_Id_Prod`),
  ADD CONSTRAINT `ticket_ibfk_3` FOREIGN KEY (`FK_Id_Cli`) REFERENCES `cliente` (`PK_Id_Cli`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
