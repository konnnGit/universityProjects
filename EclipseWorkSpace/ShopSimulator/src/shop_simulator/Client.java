/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package shop_simulator;
import java.util.*;
/*
 *
 * @author konnn
 */
public final class Client {   
    public final int MAX_ITEMS=50;  
    static int NUM_CASHIERS=5;
    public long priority;
    public int numItems;
   // public float payCash;
    
    
    public Client(long creationTime ){
        priority=creationTime;
        //if (pNumItems()==0) 
        numItems=pNumItems(); 
        // if (numItems==0) numItems=1;
       // payCash=  (float) 0.4;
    }

   
    public long serviceTime() {
        if(pCash())
        return  priority+numItems*5+pRandomDelay()+120;
        else return priority+numItems*5+pRandomDelay()+90;
        
    }
    
    public long getClientCT(){
        return this.priority;
    }
    
    int pNumItems(){        
        Random generator = new Random();
        int it=generator.nextInt(MAX_ITEMS);
        return it;
    }
    
    boolean pCash(){
        Random generator = new Random();
        int r=generator.nextInt(9);
        if(r<4) return true;
        else return false;
        
    }
    
    int pRandomDelay(){
        Random generator = new Random();
        int r=generator.nextInt(9);
        if(r<2) return (20);
        else if(r>2&& r<7) return (60);
        else return (120);
        
    }
    
    
   
    
}
