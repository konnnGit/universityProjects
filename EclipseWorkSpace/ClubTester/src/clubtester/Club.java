/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package clubtester;
import java.util.*;
import java.lang.*;
/**
 *
 * @author konnn
 */
public class Club {
    public String[][] clubList;
    public  int i=0;
         
   
    public Club(){
      
         clubList= new String[100][100];//Αρχικοποίηση ΣΤΑΤΙΚΟΥ πίνακα-λίστα
        
    }
        
    public void  join(){
       // clubList= new String[10][10];
         String newname;
         String newmonth;
         String newyear;
         Scanner input = new Scanner(System.in);
         System.out.println("Please enter name of new member: ");
         newname  = input.nextLine() ;
         System.out.println("Please enter month of new member: ");
         newmonth = input.nextLine() ;
         System.out.println("Please enter year of new member: ");
         newyear  = input.nextLine() ;
          
         Membership mem = new Membership(  newname ,   newmonth,  newyear); //Δημιουργία νέου μελους με τα παραπάνω στοιχεια που εισαγει ο χρηστης
         
         clubList[i][0]=mem.getName();//Εισαγωγη στοιχειων νεου μελους στη λιστα
         clubList[i][1]=mem.getMonth();
         clubList[i][2]=mem.getYear();
         
     
       
        i++;//Αριθμει τα μελη
       
           
           
          

}
    public int numberOfMembers(){
         
                
                
                return i;
    }
    }

