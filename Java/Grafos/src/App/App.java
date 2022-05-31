package App;

import java.util.Scanner;
import MapBuilder.MapBuilder;

public class App {
    public static Scanner input = new Scanner(System.in);
    public static void main(String[] args) throws Exception {

        System.out.print("\n\t\t ¿Cuantos nodos tiene tu grafo?\n Num: ");
        int cant = input.nextInt();
        
        MapBuilder grafo = new MapBuilder();

        grafo.setGraph(cant);
        grafo.setAdjacents();
        
        if(!grafo.Error)
        {
            System.out.print("\n Ingrese el inicio del recorrido: ");
            input.nextLine();
            String origen = input.next();
            System.out.print("\n\n Ingrese el fin del recorrido: ");
            String destino = input.next();

            grafo.setCamino(origen, destino);
        }
        
    }
}
