/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package battle;

/**
 *
 * @author konnn
 */
public class MoveIsCommandException extends InvalidLocationException{
    Command theCommand;
    
    public MoveIsCommandException(Command cmd){        
        super();
        this.theCommand=cmd;
        this.message="You entered the command:";
    }
    
    public Command getCommand(){
        return theCommand;
    }
    
    public void getMoveIsCommandExceptionMessage(){
        System.out.println(message+" "+getCommand()) ;
    }
}
