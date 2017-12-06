/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package clubtester;
import java.util.*;
import java.lang.String;
        /**
 *
 * @author konnn
 */
public class ClubTester {
    
    static String menuChoice() {

        Scanner input = new Scanner(System.in); // Scan input

		String choice;

        do {
            System.out.println("Press\n\t 'n' to give a new member of the club,"+
				"\n\t 'x' to exit the program.");

			choice = input.nextLine();
		}
		while ((choice.equals("n") || choice.equals("x")) == false);

        return choice;
    }


    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Club c= new Club();
        String choice;
        int k=0;
       // int num=0;
        do {
			choice = menuChoice();
			if (choice.equals("n")) {
                            c.join();//τρεχω τη μεθοδο join που δημιουργει και εισαγει μελος στη λιστα
                            //num++;
                        }
             }
		while (!choice.equals("x"));
        
      
        
        System.out.println("numberOfMembers: " +c.numberOfMembers() );
        for(int j=0; j<c.numberOfMembers(); j++){
            
          // for(int k=0; k<3; k++){
        System.out.print("Member " +c.clubList[j][k] );
         System.out.print(" ");
       // System.out.println( +c.clubList[j][k]  );
        System.out.print("joined in month " +c.clubList[j][k+1]  );
          System.out.print(" ");
        System.out.println(" of  " +c.clubList[j][k+2]  );
        k=0;
        //}
        }
        
        }
    
    }
       
    
    
    

