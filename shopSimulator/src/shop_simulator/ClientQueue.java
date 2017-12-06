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
public class ClientQueue {
    LinkedList<Client> items;
   
    
    public ClientQueue(){
       items =new LinkedList<Client>();
      
    }
    
    void addClient(Client item){
        items.add(item);
    }
    
    Client removeFirstClient(){
        return items.getFirst();
    }
    
    void deletFirstClient(){
        items.removeFirst();
        
    }
    
     int sizeOfQueue(){
         return this.items.size();         
     }
     
     boolean isQueueEmpty(){
         return this.items.isEmpty();
     }
     
     

    
    
}
