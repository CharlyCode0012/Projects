package Union;

import Nodo.Nodo;

public class Union {
    private Nodo origin;
    private Nodo destination;
  
    public Union(){}
    
    public Union(Nodo origin, Nodo destination) {
        this.origin = origin;
        this.destination = destination;
    }
 
    public Nodo getOrigin() {
        return origin;
    }
 
    public void setOrigin(Nodo origin) {
        this.origin = origin;
    }
 
    public Nodo getDestination() {
        return destination;
    }
 
    public void setDestination(Nodo destination) {
        this.destination = destination;
    }
 
 
    @Override
    public String toString() {
        return "Union [origen=" + origin.getName() + ", destino=" + destination.getName() + " ]";
    }
}

