<?php
include "Persona.php";

class BaseDeDatos
{
    private $con;
    public function __construct()
    {
        $this->con = new PDO('mysql:host=localhost;dbname=aplicacionmoviles','root','');
    }
    
    public function consulta($query)
    {
        $sql = $this->con->prepare($query);
        $sql->execute();
	
        $res = $sql->fetchAll();
        $arreglo = array();
        foreach($res as $dato)
        {
            $obj = new Persona();
            $obj->id = $dato['id'];
            $obj->nombre = $dato['nombre'];
            $obj->genero = $dato['genero'];
            $obj->edad = $dato['edad'];
            $obj->altura = $dato['altura'];
            $obj->videojuego = $dato['videojuego'];
            array_push($arreglo, $obj);
        }
        return $arreglo;
    }

    public function validar_usuario ($usr,$pass)
    {
                
        $sql = $this->con->prepare("SELECT * FROM usuarios WHERE BINARY usuario = '$usr' and BINARY pass= '$pass'");
        
        $sql->execute();
        $res = $sql->fetchAll();
        
        if(count($res) > 0)
        {
            foreach($res as $dato)
                return $dato['id'];
            
        }
        return -1;
    }

    public function registro($usr,$pass){
        $sql = $this->con->prepare(
            "INSERT INTO usuarios (usuario, pass)
             VALUES ('$usr', '$pass')
            ");
            $sql->execute();
    }

    public function addPersonaje($nomb, $gene, $edad, $alt, $videojuego){
        $sql = $this->con->prepare(
        "INSERT INTO personajes (nombre, genero, edad, altura, videojuego) 
         VALUES ('$nomb', '$gene', '$edad', '$alt', '$videojuego')
        ");
        $sql->execute();
    }

    public function updatePersonaje($nomb, $gene, $edad, $alt, $videojuego, $id){
        $sql = $this->con->prepare(
            "UPDATE personajes 
             SET nombre='$nomb', genero='$gene', edad='$edad', altura='$alt', videojuego='$videojuego' 
             WHERE id='$id'
            ");
            $sql->execute();
        
    }

    public function removePersonaje($id){

        $sql = $this->con->prepare(
            "DELETE FROM personajes WHERE id='$id'"
        );
        $sql->execute();
        
    }
}

