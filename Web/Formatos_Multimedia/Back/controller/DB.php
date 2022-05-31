<?php
include "DOM.php";

class BaseDeDatos
{
    private $con;
    public function __construct()
    {
        $this->con = new PDO('mysql:host=localhost;dbname=dompdf','root','');
    }
    
    public function consulta()
    {
        $sql = $this->con->prepare("SELECT * FROM dom WHERE id = 1");
        $sql->execute();
  
        $res = $sql->fetchAll();
        $arreglo = array();
        foreach($res as $dato)
        {
            array_push($arreglo, $dato['nombre']);
            array_push($arreglo, $dato['url1']);
            array_push($arreglo, $dato['html']);    
        }
        return $arreglo;
    }

    public function addDom($nomb, $url, $html){
        $sql = $this->con->prepare(
        "INSERT INTO dom (nombre, url1, html) 
         VALUES ('$nomb', '$url', '$html)
        ");
        $sql->execute();
    }

    public function updateDom($name, $url, $html){
        $sql = $this->con->prepare(
            "UPDATE dom 
             SET nombre='$name', url1='$url', html='$html'
             WHERE id=1
            ");
            $sql->execute();
    }

}
?>