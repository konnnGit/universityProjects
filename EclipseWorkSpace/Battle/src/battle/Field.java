/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package battle;
import java.util.*;
import java.lang.*;

/**
 *
 * @author konnn
 */
public class Field {
    int shipsCreated;
    public Location[] location;
    int numOfPositions; 
    public int rows;
    public int cols;     
    public String[][] Board;
    int countPos;
    Player player;
    Ship [ ] fieldShips;
    
    
    
    public Field(int rows,int cols ){
        shipsCreated=0;
        fieldShips=new Ship [7];
         
        fieldShips[0]=new AicraftCarrier();
        fieldShips[1]=new AicraftCarrier();
        fieldShips[2]=new Destroyer();
        fieldShips[3]=new Destroyer();
        fieldShips[4]=new Destroyer();
        fieldShips[5]=new Submarine();
        fieldShips[6]=new Submarine();
    
        int i = 0,j = 0;
        countPos=0;
        this.rows=rows;
        this.cols=cols;
        numOfPositions=rows*cols;
        location=new Location[numOfPositions];
        Board=new String[rows][cols];
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                Board[r][c]=".";
                    location[i]=new Location(r,c);
                    i++;                 
                
            }
            
        }
        System.out.println("num of locations ="+i);
    }
   
    
    void printBoard() {
        
       
        System.out.print("   ");
        for(int rr=0;rr<Field.this.Board.length;rr++){
            if(rr>=9){
                System.out.print((rr+1)+" ");
            }
            else{
            System.out.print((rr+1)+"  ");
            }
        }
         System.out.println();
         System.out.print("   ");
        for(int rr=0;rr<Field.this.Board.length;rr++){
            System.out.print("---"+"");
        }
        System.out.println();
        
        for(int rr=0;rr<Field.this.Board.length;rr++){
            System.out.print(getLocation(rr)+""+"|"+"");
            for(int cc=0;cc<Field.this.Board[rr].length;cc++){
                //if (Field.this.Board[rr][cc]==DOT) {
                    System.out.print(" "+Field.this.Board[rr][cc]+" ");
                }
                
            System.out.println();
            }
            
        }
    public String getLocation(int r){
        String a = null;
        switch (r){
        case 0: a= "A"; break;
        case 1: a= "B"; break;
        case 2: a="C"; break;
        case 3: a= "D"; break;
        case 4: a=  "E"; break;
        case 5: a= "F" ; break;
        case 6: a= "G"; break; 
        case 7: a="H"; break;
        case 8 : a= "I"; break;
        case 9: a= "J"; break;
        case 10: a= "K"; break;
        case 11: a= "L"; break;
        case 12: a="M"; break;
        case 13: a="N"; break;
        case 14 : a= "O"; break;
        //default: return Integer.valueOf(locString);
        }
        return a;
        
    }
        
    
    public String getLocation(int r, int c){
        String a,b;
        switch (r){
        case 0: a= "A"; break;
        case 1: a= "B"; break;
        case 2: a="C"; break;
        case 3: a= "D"; break;
        case 4: a=  "E"; break;
        case 5: a= "F" ; break;
        case 6: a= "G"; break; 
        case 7: a="H"; break;
        case 8 : a= "I"; break;
        case 9: a= "J"; break;
        case 10: a= "K"; break;
        case 11: a= "L"; break;
        case 12: a="M"; break;
        case 13: a="N"; break;
        case 14 : a= "O"; break;
        //default: return Integer.valueOf(locString);
        }
        switch (c){
        case 0: b= "A"; break;
        case 1: b= "B"; break;
        case 2: b="C"; break;
        case 3: b= "D"; break;
        case 4: b=  "E"; break;
        case 5: b= "F" ; break;
        case 6: b= "G"; break; 
        case 7: b="H"; break;
        case 8 : b= "I"; break;
        case 9: b= "J"; break;
        case 10: b= "K"; break;
        case 11: b= "L"; break;
        case 12: b="M"; break;
        case 13: b="N"; break;
        case 14 : b= "O"; break;
        //default: return Integer.valueOf(locString);
        }
        return "r"+"c";
        
    }
    
    public int getShipsCreated(){
        return shipsCreated;
    }
    
   public int getLocation(String locString){
      //  int a1,b,c = 0;
        int a = 0;
        //a=Integer.valueOf(locString.substring(0, 0));
        //a=locString.substring(0, 0);
        switch (locString){
        case "A": a= 0; break;
        case "B": a= 1; break;
        case "C": a= 2; break;
        case "D": a= 3; break;
        case "E": a= 4; break;
        case "F": a=5; break;
        case "G": a= 6; break; 
        case "H": a= 7; break;
        case "I": a= 8; break;
        case "J": a= 9; break;
        case "K": a= 10; break;
        case "L": a= 11; break;
        case "M": a=12; break;
        case "N": a=13; break;
        case "O" : a= 14; break;
        //default: return -1;
        }     
        return a;
      /*  
        b=Integer.valueOf(locString.substring(1, 1));
        if(Integer.valueOf(locString.substring(2, 2))<=5){
            c=Integer.valueOf(locString.substring(2, 2));
            return a1*b*c;
        }
        Board[a1][b]="o";
        return a1*b;*/
    }
    
  /*  boolean getLocation(String locString){
        if(locString.equals(".")) return true;
    */    
    
   public void placeShipRandomly(/*Ship s*/){
       Random randx=new Random();
       Random randy=new Random();
       Random randd=new Random();
       //init each ship
       for(int initEachSip=0;initEachSip<7;initEachSip++){
          // finalShip;
       
       boolean checkMarcked=false;
       int maxTries=5;
       int x,y,tries,isCorrect,i;       
       tries=0;
       int r;      
      
       int dir=randd.nextInt(2);
       if (dir==1) {
            fieldShips[initEachSip].dir=ShipDirection.HORIZONTAL;
       }
       else { 
           fieldShips[initEachSip].dir=ShipDirection.VERTICAL;
       }
       while(tries<maxTries){
           x=y=isCorrect=i=0;
           x=randx.nextInt(this.rows);           
           y=randy.nextInt(this.cols);          
          
           
       //    fieldShips[initEachSip].row=x;
       //    fieldShips[initEachSip].col=y;
        //  
       if(fieldShips[initEachSip].dir.equals(ShipDirection.HORIZONTAL)){
      
   /*-------------------------it is HORIZONTAL-----------------*/        
             while( y+i>=0 && y+i<cols && i<fieldShips[initEachSip].length){                 
                if(this.Board[x][y+i].equals(".")) {
                   isCorrect++;
               }
               i++;              
         
            }
             if(isCorrect==fieldShips[initEachSip].length){
                 fieldShips[initEachSip].positioned=true;
                 shipsCreated++;
                 for(int m=0;m<fieldShips[initEachSip].length;m++){
                     fieldShips[initEachSip].location[m]=new Location(x,y+m);  
                    // System.out.println("Locs of ships at the initialing ="+fieldShips[initEachSip].location[m].getLCLocation());
                     this.Board[x][y+m]=fieldShips[initEachSip].getLetter();
                     
                 }
                 break;
             }
             
       }
          /*-------------------------it is  VERTICAL-----------------*/
       else{
          // i=1;
           while(  x+i>=0 && x+i<rows && i<fieldShips[initEachSip].length){
               if(this.Board[x+i][y].equals(".")) {
                   isCorrect++;
               }
               i++;            
         
            }
           if(isCorrect==fieldShips[initEachSip].length){
               fieldShips[initEachSip].positioned=true;
               shipsCreated++;
                 for(int m=0;m<fieldShips[initEachSip].length;m++){
                     fieldShips[initEachSip].location[m]=new Location(x+m,y);
                     // System.out.println("Locs of ships at the initialing ="+fieldShips[initEachSip].location[m].getLCLocation());
                     this.Board[x+m][y]=fieldShips[initEachSip].getLetter();
                    
                 }
             }
           break;
           
       }
       tries++;
       }
       
       }
       
}
   
   
   
                   
    }

    
    
    
      
    
    
    

