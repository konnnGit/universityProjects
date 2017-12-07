/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mailsimulator;
import java.lang.*;
import java.util.ListIterator;
/**
 *
 * @author konnn
 */
public class MailClient {
   private MailServer server;
   private String user ;
   
    
    public MailClient(MailServer server, String user){
       // this.
        this.server=server;
        this.user=user;           
    }

    
    MailItem getNextMailItem(){
        //ListIterator iter = server.items.listIterator();
        //while(iter.hasNext()){
       // while(server.getNextMailItem(user))        
            return server.getNextMailItem(user);
        //}
        //return null;
                    
    }
    void printNextMailItem(){
       // ListIterator iter = server.items.listIterator();
     //   MailItem m=new MailItem(null,null,null);
        //while(iter.hasNext()&&!(iter.next().equals(m)) )
        //for(int i=0;i<server.howManyMailItems(user);i++)
      //do{
        //while(this.getNextMailItem())
        getNextMailItem().print();
   // }while(iter.hasPrevious());   
    }
    void sendMailItem(String to, String message){       
        MailItem i = new MailItem (MailClient.this.user,to,message);
        server.post( i ) ; 
                
    }

    



    
}
