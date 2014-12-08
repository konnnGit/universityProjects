/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mailsimulator;
import java.util.* ;
/**
 *
 * @author konnn
 */
public class MailServer {
    ArrayList<MailItem> items ;
//     ListIterator iter = items.listIterator();
    public MailServer (){        
     ArrayList <MailItem> items = new ArrayList<MailItem>(); 
    // ListIterator iter = items.listIterator();
     this.items=items;
    } 
    
    void post(MailItem item){
        ListIterator iter = items.listIterator();
    
        // MailItem item=new MailItem(null,null,null);
        //  if (item==null)
         iter.add(item);
        //  else break;
    }
  //  }
    int howManyMailItems(String who){
        ListIterator iter = this.items.listIterator();
        MailItem m=new MailItem(null,null,null);
        int count=0;
       // for (int i=0;i< items.size();i++){
            while(iter.hasNext()){
                 m = (MailItem) iter.next();
            if (m.getTo().equals(who)) {
                count++;
            }
            }
         System.out.println(count);
        return count; 
       
    }
    MailItem getNextMailItem(String who){
        
        MailItem m=new MailItem(null,null,null);        
       ListIterator iter = items.listIterator();
    /// while(iter.hasNext()){        
            m = (MailItem) iter.next();         
                if (who.equals(m.getTo()))
                    return m;
                //else return null;

    //   }
                return null;

  
}

} 