/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package shop_simulator;

/**
 *
 * @author konnn
 */
public class Cashier {
     ClientQueue queue;   
     boolean open;
     Client currentClient;
     long serviceTime;
     boolean isOpen;
     long idleTime ;
   
   public Cashier(){
       //ClientQueue queues;
      // LinkedList<ClientQueue> queues=new LinkedList<ClientQueue >();
        queue=new ClientQueue();   
        open = false;
        currentClient=null ;
        serviceTime =0;
        idleTime = 0 ;
        isOpen=false;
        //currentTime=0;
       
      
       
   }
   
   
   boolean isCashierOpen(){
       if (isOpen) return true;
       else return false;
   }
   
   
   
   
   void serviceQueue(long currentTime){ 
       if(queue.isQueueEmpty()) {
           //System.out.println("Emty queue.");
           return;
       }
       currentClient=queue.removeFirstClient();
           if(currentTime>=currentClient.serviceTime()){
               queue.deletFirstClient();
              // System.out.println("Client left.");
           }
          //else{
           //    System.out.println("Client serviced.time:"+currentTime);
               //queue..items.push(currentClient);
         //  }
               
   
   // System.out.println("Emty queue.\n");
    //return;
  }

   int clientInQueue(){
       return queue.sizeOfQueue();
   }
   
    void enqueueClient(Client currentClient){
       // ListIterator iter = this.queue.listIterator();
        Client cli;
        cli=currentClient;
   
        queue.items.add(cli);
        
              
        
    }
   
 

       
   
   
    
}
