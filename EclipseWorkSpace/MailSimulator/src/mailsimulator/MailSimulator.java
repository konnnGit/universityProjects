  /*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package mailsimulator;
import java.util.* ;
import java.lang.*;
/**
 *
 * @author konnn
 */
public class MailSimulator {

    /**
     * @param args the command line arguments
     */
    
    static String menuChoice() {

        Scanner input = new Scanner(System.in); // Scan input

		String choice;

        do {
            System.out.println("Press\n\t 'n' to send a new mail."+
				"\n\t 'x' to exit the program.");

			choice = input.nextLine();
		}
		while ((choice.equals("n") || choice.equals("x")) == false);

        return choice;
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input1 = new Scanner(System.in);
        Scanner input2 = new Scanner(System.in);
        Scanner input3 = new Scanner(System.in);
        String choice = null;
        
        MailServer myserver = new MailServer();
        String Mary = "Mary    ";
        MailClient Client1 = new MailClient(myserver, Mary);
        String Costas = "Costas";
        MailClient  Client2 = new MailClient (myserver,Costas);
        do{      
            choice = menuChoice();
			if (choice.equals("n")) {            
        
        System.out.println("Send to whom?:");
        String Cl;
        Cl= input1.nextLine();
        
        System.out.println("Message:");
        String Mess;
        Mess=input2.nextLine();        
        Client1.sendMailItem(Cl, Mess); 
        System.out.println("You have a new email:");
        Client2.printNextMailItem();
                        }
                      
       }while (!choice.equals("x"));

       
        
       // Client2.printNextMailItem();
    }
}
