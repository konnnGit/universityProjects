/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package battle;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author konnn (Konstantinos Spalas, cst08094, AM:2025200800094)
 */
public class Battle {
    private static String a;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
            //String e = null;
            
            //do{
            Game G=new Game();
            G.init();
            G.placeShips();
        try {
            G.play();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Battle.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException | ClassNotFoundException ex) {
            Logger.getLogger(Battle.class.getName()).log(Level.SEVERE, null, ex);
        }
            G.showResults();
           // System.out.println("Press any key to start a new game or e to exit");
           // }while(!e.equals("e"));

            System.exit(0);
        
      
        
    }
}
