package Graph;
import Nodo.Nodo;



import java.util.ArrayList;

public class Graph {

    private ArrayList<Nodo> nodes = new ArrayList<Nodo>();
 
    public void addNode(Nodo node, int indice) {
        node.setIndice(indice);
        nodes.add(node);
    }
 
    public  ArrayList<Nodo> getNodes() {
        return nodes;
    }
 
    @Override
    public String toString() {
        return "Graph [nodes=" + nodes + "]";
    }

    public int indexOf(String name){
        int cont = 0;
        for(Nodo i : nodes)
        {
            if(i.getName().equals(name))
            {
                return cont;
            }
            cont++;
        }
        return -1;
    }

    public Nodo IndexOf(String name)
    {
        for(Nodo i : nodes)
        {
            if(i.getName().equals(name))
            {
                return i;
            }
        }
        
        Nodo nod = new Nodo();
        nod.setIndice(-1);
        return nod;
    }

    public Nodo IndexOf(int index)
    {

        if(!nodes.isEmpty())
        {
            if(index < nodes.size())
            {
                return nodes.get(index);
            }        
        }

        Nodo nod = new Nodo();
        nod.setIndice(-1);
        return nod;
    }
}
