  /*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package battle;

import java.io.*;

/**
 *
 * @author konnn
 */
public class InvalidLocationException extends IOException{
    String message;
    public InvalidLocationException(){        
        super();
        this.message="You entered wrong location,out of bounds.";
    }
    
    
   public  void getInvalidLocationExceptionMessage(){
       System.out.println(message) ;
   }
    
    
}
