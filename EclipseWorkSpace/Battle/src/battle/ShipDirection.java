/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package battle;

/**
 *
 * @author konnn
 */
public enum ShipDirection {
    VERTICAL, HORIZONTAL;
    
    
   /* public ShipDirection(){
        Scanner
    }*/
    
    public boolean fromString(String dirString){
        switch (dirString) {
            case "h":
                return true;
            case "v":
                return true;
        }
        
        return false;
        
    }
    
}
