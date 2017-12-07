/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package battle;

/**
 *
 * @author konnn
 */
public class Location {
    int row;
    int col;       
    boolean marked;
    boolean isShip;
     
    
     
    public Location(int x, int y){
        this.row=x;
        this.col=y;
        marked=false;
        isShip=false;            
    }
    public int getLCLocation(){        
        return row*col+col;        
    }
    
    public void mark(){        
        this.marked=true;
    }
    
        
    
    public boolean isMarked(){
        return marked;
    }
    
    
    
    
    
    
    
}
