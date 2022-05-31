package MapBuilder;

import Nodo.Nodo;
import Union.Union;
import Graph.Graph;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;

public class MapBuilder {
    private static  Graph instance = new Graph();
    private static ArrayList<String> names = new ArrayList<String>();
    private static ArrayList<HashMap<String,ArrayList<Integer>>> matrix = new ArrayList<HashMap<String,ArrayList<Integer>>>();
    private static ArrayList<Integer> arr = new ArrayList<Integer>();
    private static int tamanio;

    public static Scanner in = new Scanner(System.in);
    public static boolean Error = false;
    
    public MapBuilder() {
    }
    


    public static Graph getGraph() {
        return instance;
    }

    public static void setGraph(int size)
    {
        String name;
        tamanio = size;
        for(int i = 0; i < size; i++)
        {
            System.out.println("\n\t Agrega el nodo "+ (i+1) + ": ");
            Nodo node = new Nodo();
            name = in.nextLine();
            node.setName(name);
            instance.addNode(node, i);
        }

    }

    public static void setAdjacents()
    {
        int size = 0;
        int num = 0;
        String name;
        for(Nodo i : instance.getNodes())
        {
            System.out.print("\n Ingrese la cantidad de hijos que tiene el nodo " + i.getName() + ": ");
            size = in.nextInt();
            in.nextLine();
            for(int cont = 0; cont < size; cont++)
            {
                Nodo destino = new Nodo();
                
                Union edge = new Union();
                edge.setOrigin(i);

                System.out.print("\n Ingrese el nombre del hijo "+ (cont+1) + ": ");
                name = in.next();

                destino = searchNode(name);
                if(destino.getName().equals(i.getName()))
                {
                    System.out.println("\n\n\t\t\t **ERROR**\n\n\t Un nodo no puede ser su propio hijo");
                    Error = true;
                }

                if(Error)
                {
                    break;
                }
                edge.setDestination(destino);
                i.addEdge(edge);
            }

            if(Error)
            {
                break;
            }
                

            if(num > 0)
            {
                if(!compareUnion(i))
                {
                    System.out.println("\n\n\t\t **ERROR**\n Nodo bidireccional\n");
                    Error = true;
                    return;
                }
                
            }
            num ++;
            
        }

        if(!Error)
        {
            getNames();
            makeMatrix();
        }
    }

    private static Nodo searchNode(String name){
        Nodo node = new Nodo();
        node = instance.IndexOf(name);

        if(node.getIndice() == -1)
        {
            System.out.println("\n\n\t\t **ERROR**\n No existe tal nodo\n");
            Error = true;
        }  
        return node;
    }

    private static boolean compareUnion(Nodo node)
    {
        for(Union i : node.getAdjacents())
        {
            Nodo origen = i.getOrigin();
            Nodo destino = i.getDestination();

            for(Union j : destino.getAdjacents())
            {
                if(origen.equals(j.getDestination()))
                {
                    return false;
                }
                    
            }
        }
        return true;
    }

    private static void getNames(){
        
        for(Nodo i : instance.getNodes())
        {
            names.add(i.getName());
        }
        
    }

    static void search(String value)
    {
        ArrayList<String> _hijos = new ArrayList<String>();

        for(Nodo i : instance.getNodes())
        {
            if(i.getName().equals(value)){
                for(Union j: i.getAdjacents()){
                    _hijos.add(j.getDestination().getName());
                }
                
            }
        }

        //
        for(String i : _hijos)
        {
            //se obtiene el indice del arreglo de nombres, el cual coincide con el orden ingresado
            int indice = names.indexOf(i);
            if(indice !=-1)
            {
                //se encontro y se le pone 1 en esa posicion
                arr.set(indice, 1);
            }
        }
    }

    private static void makeMatrix()
    {
        
        for(int i = 0; i < tamanio; i++)
        {
           HashMap<String,ArrayList<Integer>> map = new HashMap<String,ArrayList<Integer>>();
           arr = new ArrayList<Integer>();
           for(int cont2 = 0; cont2 < tamanio; cont2++){
                arr.add(0);
            }
           search(names.get(i));

           map.put(names.get(i), arr);
           matrix.add(map);        
        }

        for(var j : matrix)
        {
            for (String i : j.keySet()) {
                System.out.println("key: " + i + " value: " + j.get(i));
            }
        }
        
    }

    public void setCamino(String origen, String destino)
    /*{
        HashMap<String,ArrayList<Integer>> row =  new HashMap<String,ArrayList<Integer>>();
        ArrayList<String> uniones = new ArrayList<String>();
        String err;
        int indO = instance.indexOf(origen);
        int indD = instance.indexOf(destino);

        if(indO != -1 && indD != -1)
        {

        }
        else
        {
            err = indO == -1? origen + " ": ""; 
            err += indD == -1? destino + " ": "";
            Error = true;
            System.out.println("Error, no existe tal nodo " + err);
        }
    }*/
    {
        String err;
        Stack<Union> opciones = new Stack<Union>();
        ArrayList<Union> caminos = new ArrayList<Union>();
        ArrayList<Union> ruta = new ArrayList<Union>();
        ArrayList<Union> rutaTemp = new ArrayList<Union>();
        Nodo ntemp = new Nodo();
        String name;
        boolean ciclo = true, flag = false;
        int posicion = 0;
        int cont2 = 0;

        int indO = instance.indexOf(origen);
        int indD = instance.indexOf(destino);

        if(indO != -1 && indD != -1)
        {
            ntemp = instance.IndexOf(indO);
            caminos = ntemp.getAdjacents();
            for(Union i: caminos){
                opciones.add(i);
            }
            caminos = new ArrayList<Union>();

            while(!opciones.isEmpty()){
                Union utemp = new Union();

                //Ultima conexion encontrada
                utemp = opciones.pop();
                posicion = opciones.size();
                //Nodo destino
                ntemp = utemp.getDestination();
                //se obtienen las rutas de ese destino
                caminos = ntemp.getAdjacents();

                if(!caminos.isEmpty() || ntemp.getName().equals(destino))
                {
                    name = ntemp.getName();
                    if(validarCiclo(ruta, utemp))
                    {
                        //si no coincide se agrega
                        ruta.add(utemp);
                        for(Union i: caminos)
                        {
                            ciclo = validarCiclo(ruta, i);
                            if(!ciclo)
                            {
                                cont2 = 1;
                                while(opciones.size() > posicion + 1)
                                {
                                    opciones.pop();
                                    cont2++;
                                }

                                for(int cont = 0; cont < ruta.size()-cont2; cont++)
                                {
                                    rutaTemp.add(ruta.get(cont));
                                }

                                ruta = new ArrayList<Union>();

                                for(Union j: rutaTemp)
                                {
                                    ruta.add(j);
                                }

                                rutaTemp = new ArrayList<Union>();
                                break;
                            }
                            opciones.add(i);       
                        }
                        ciclo = caminos.isEmpty()? true: ciclo;

                        caminos = new ArrayList<Union>();
                        if(ciclo)
                        {
                            if(ntemp.getName().equals(destino))
                            {
                                System.out.print(origen);
                                for(Union i : ruta)
                                {
                                    System.out.print(" -> " + i.getDestination().getName());
                                }
                                System.out.println();
                                Union s = new Union();
                                s = opciones.isEmpty()? new Union(): opciones.peek();
                                rutaTemp = new ArrayList<Union>();
                                for(Union i: ruta)
                                {
                                    if(s.getOrigin().getName().equals(i.getDestination().getName()))
                                    {
                                        flag = true;
                                        break;
                                    }
                                    rutaTemp.add(i);
                                }
                                ruta = new ArrayList<Union>();
                                if(flag)
                                {
                                    for(Union i : rutaTemp)
                                    {
                                        ruta.add(i);
                                    }
                                }
                                rutaTemp = new ArrayList<Union>();
                                
                            }
                        }
                        
                    }  
                }
                

            }
        }else
        {
            err = indO == -1? origen + " ": ""; 
            err += indD == -1? destino + " ": "";
            Error = true;
            System.out.println("Error, no existe tal nodo " + err);
        }
    }

    private boolean validarCiclo(ArrayList<Union> rutas, Union camino)
    {
        Nodo destino = new Nodo();
        destino = camino.getDestination();


        for(Union i: rutas)
        {
            if(i.getOrigin().getName().equals(destino.getName()))
            {
                //coincide con un nodo ya recorrido
                return false;
            }
        }
        return true;
    }
}
