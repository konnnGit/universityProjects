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
public class Shop {
     Date Times;
     long startTime;
      long MAX_TIME=500;
      /**
       * 
       */
      static int NUM_CASHIERS=5;   
      //int numOfCashiers=5;
     ArrayList<Cashier> cashier;
     Cashier c1;
     Cashier c2;
     Cashier c3;
     Cashier c4;
     Cashier c5;
   
   
    
    public Shop(){ 
        Times= new Date();
        startTime=Times.getTime()/1000;
       // numOfCashiers=5;
        c1=new Cashier();
        c2=new Cashier();
        c3=new Cashier();
        c4=new Cashier();
        c5=new Cashier();
        
        cashier=new ArrayList<Cashier>(NUM_CASHIERS);///array with the num of cashiers          
        
        cashier.add(c1);
        cashier.add(c2);
        cashier.add(c3);
        cashier.add(c4);
        cashier.add(c5);
      
    }
  /*  void initCashiers(Cashier c){
        this.c1.startDate.=now;
        this.c2.startDate=now;       
        
    }*/
    void rumSim(){    
         
        Date Timer= new Date();
        //ο crTimeNewCl_temp μετρά τη κάθε χρονική στιγμή, ενώ ο crTimeNewCl την αρχή
        long crTimeNewCl,crTimeNewCl_temp;
        crTimeNewCl=Timer.getTime()/10000;  
        crTimeNewCl_temp=crTimeNewCl;
        
        
       
        
        
        while(crTimeNewCl_temp-crTimeNewCl<MAX_TIME){
            adjustCashier();
            if(pCreateClient()==true){
                 Client newClient=new Client(crTimeNewCl_temp); 
                 //ο νέος πελάτης πηγαίνει στο λιγότερο συνωστισμένο ταμείο
                 selectMinCashier(cashier).enqueueClient(newClient);                
                
                 //System.out.println("The new client added to a cashier.time: "+crTimeNewCl_temp);
                
                 
                 c1.serviceQueue(crTimeNewCl_temp);
                 c2.serviceQueue(crTimeNewCl_temp);
                 c3.serviceQueue(crTimeNewCl_temp);
                 c4.serviceQueue(crTimeNewCl_temp);
                 c5.serviceQueue(crTimeNewCl_temp);
            }
            //Αν δεν δημιουργηθεί πελάτης
            else{
                 c1.serviceQueue(crTimeNewCl_temp);
                 c2.serviceQueue(crTimeNewCl_temp);
                 c3.serviceQueue(crTimeNewCl_temp);
                 c4.serviceQueue(crTimeNewCl_temp);
                 c5.serviceQueue(crTimeNewCl_temp);
                
            }
            System.out.println("Size of c1:"+c1.queue.sizeOfQueue());
            System.out.println("Size of c2:"+c2.queue.sizeOfQueue());
           System.out.println("Size of c3:"+c3.queue.sizeOfQueue());
           System.out.println("Size of c4:"+c4.queue.sizeOfQueue());
           System.out.println("Size of c5:"+c5.queue.sizeOfQueue());
           System.out.println("");
            crTimeNewCl_temp++;
        }
        
        
       /*Υπάρχει ενδεχόμενο να τελειώσει η μέρα και να έχουμε πελάτες στα ταμεία*/            
            
        
        
         System.out.println("\nEnd of the day. \n");
    }
    
    long getStartTime(){
        return startTime;
    
    }
    //πιθανότητα δημιουργίας πελάτη
    boolean pCreateClient(){
        Random generator = new Random();
        int r=generator.nextInt(9);
        if(r<6) return true;
        else return false;
        
    }

    void adjustCashier(){
       // ListIterator iter = cashier.listIterator();
        if (numOfCustomers()<10) {
            c1.isOpen=true;
        //Ίσως είναι περιτός  έλεγχος απ' τη στιγμή που οι πελάτες λειτουργούν "έξυπνα".
            if (c2.queue.isQueueEmpty()){
            c2.isOpen=false;                          
            }
        
            if (c3.queue.isQueueEmpty()){
            c3.isOpen=true;            
            }
        
             if (c4.queue.isQueueEmpty()){
             c4.isOpen=false;              
            }
        
             if (c5.queue.isQueueEmpty()){
            c5.isOpen=false;             
             }
            
        }     
        
        else if (numOfCustomers()>=10 && numOfCustomers()<30){
        c1.isOpen=true;
        
        c2.isOpen=true; 
        
        if (c3.queue.isQueueEmpty()){
            c3.isOpen=true;             
        }
        
        if (c4.queue.isQueueEmpty()){
             c4.isOpen=false;              
        }
        
        if (c5.queue.isQueueEmpty()){
            c5.isOpen=false;             
        }
            
        }
        
        
    else if(numOfCustomers()>=30 && numOfCustomers()<50) {
        c1.isOpen=true;
        
        c2.isOpen=true;
        
        c3.isOpen=true;
        if (c4.queue.isQueueEmpty()){
             c4.isOpen=false;              
        }
        if (c5.queue.isQueueEmpty()){
            c5.isOpen=false;            
        }
    }
     
    else if(numOfCustomers()>=50 && numOfCustomers()<70){
        c1.isOpen=true;
        c2.isOpen=true;
        c3.isOpen=true;
        c4.isOpen=true;
        if (c5.queue.isQueueEmpty()){
            c5.isOpen=false;            
        }
    }
    else {
        c1.isOpen=true;
        c2.isOpen=true;
        c3.isOpen=true;
        c4.isOpen=true;
        c5.isOpen=true;
    }
        
    }

     Cashier selectMinCashier(ArrayList<Cashier> shopCashierList){
       // shopCashierList=new ArrayList<Cashier>(NUM_CASHIERS);
        ListIterator iter = shopCashierList.listIterator();
        Cashier temp = new Cashier();       
        Cashier minCashier=new Cashier();
        if(iter.hasNext())            
            minCashier=(Cashier) iter.next();  
        
        while(iter.hasNext()){
            temp=(Cashier) iter.next();
            if(temp.isCashierOpen()){
                 if(temp.clientInQueue() <= minCashier.clientInQueue())
                        minCashier=temp;                
            } 
            else return minCashier;
        }
             
        return minCashier;
        
    }

int numOfCustomers(){
return c1.queue.sizeOfQueue()+c2.queue.sizeOfQueue()+c3.queue.sizeOfQueue()+c4.queue.sizeOfQueue()+c5.queue.sizeOfQueue();
}
    
    
}
 