/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package shop_simulator;
import java.util.*;

/**
 *
 * @author konnn
 */

 /*
 * Το έργο πονάει στα εξής:
 * Μπορεί να τελειώσει η μέρα και να υπάρχουν πελάτες.
 * Δεν υλοποιεί εξπρές ταμείο
 * Δεν εξυπηρετεί άτομα με ειδικές ανάγκες
 * Δεν υπολογίζει idletime
 */

public class Shop_SImulator {
    

    /**
     * @param args the command line arguments
     */ 
    public static void main(String[] args) {
        // TODO code application logic here
        
        
        
        Shop newShop=new Shop();
       
        System.out.println("A new shop created at "  +newShop.getStartTime());
       
        newShop.rumSim();
       
        
       
    }
}
