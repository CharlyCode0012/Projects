package Nodo;
import Union.Union;

import java.util.ArrayList;

 

public class Nodo {
    private String name;
    private ArrayList<Union> adjacents = new ArrayList<Union>();
    private int indice;
    public Nodo(){
        
    }
 
    public Nodo (String name, int indice) {
        this.name = name;
        this.indice = indice;
    }
 
    public void addEdge(Union edge) {
        adjacents.add(edge);
    }
 
    public ArrayList<Union> getAdjacents() {
        return adjacents;
    }
 
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    public int getIndice() {
        return indice;
    }

    public void setIndice(int indice) {
        this.indice = indice;
    }

    @Override
    public String toString() {
        return "Nodo [nombre=" + name + ", adjacents=" + adjacents + "]";
    }

    
    
}