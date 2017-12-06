/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package battle;
import java.util.*;
import java.io.*;
/**
 *
 * @author konnn
 */
public  class Ship {
     boolean positioned;
     int length;
     int points;
     String letter;
     Field field;
     String start;
     int locationInt;
     int col;
     int row;
     Location[] location;
     ShipDirection dir;     
    int hit,hitTemp;
    //private final String NULL;
    
    public Ship(){
        //length=0;
       // location= new Location[length];
        positioned=false;
        points=0;
        letter="";        
        hit=hitTemp=0;
        
    } 
    
   
    public String getLetter(){
        return letter;
    }
    
     public boolean hit(){
         if(this.hit<length){
             this.hit++;
              //hit=hitTemp;
             return true;
         }
         return false;
     }
     
     /*public int getLocation(){        
         return Integer.parseInt(Integer.toString(row)+Integer.toString(col));
    }*/
     //Η κάθε θέση εκφράζεται με ένα αριθμό σύμφωνα με τον αλγόριθμο δομής πίνακα.
     public int getLocation(){
         return row*col+col ;
     }
   
     
    public boolean isHit(){
        
            if(hit>hitTemp){
                hitTemp=hit;
                return true;
               // break;
            }            
        
       return false;
    }
    
    public boolean isSinking(){
        if(this.hit==this.length ){
            return true;
        }
         return false;
    }
    
  
    
    public void getSinkMessage(){
            if(isSinking()){
            System.out.println("Ship with type"+" "+letter+" "+"is sinking.");
            }
    }
    
    public void getHitMessage(){
        if(isHit()){
            System.out.println("The ship "+getLetter()+" is  hit.");
        }
    }
  /*  
    public void changeLetter(){
        if(isSinking()){
            this.letter="x"+letter;
        }
    }*/
    
    
    
    
}
