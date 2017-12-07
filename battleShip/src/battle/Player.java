/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package battle;
import java.util.*;
import java.io.*;
/**
 *String
 * @author konnn
 */
public class Player implements Serializable{
    int manualShipsPositioned;
    public Location location ;
    private String name;
    public int score;
    private Field field;    
    int numOfMoves;
    boolean marked;
    boolean isHuman; 
    Command cmd;
    
    
    public Player(String name){       
        this.name=name;
        score=0;
        marked=false;
        numOfMoves=0;        
        cmd=null;
    }
    
    public String getName(){
        return name;
    }
    
    public Field initField(){
        int c=0,r=0;
        Scanner input = new Scanner(System.in);
        //if(isHuman){
        do{
            
        System.out.print("Rows( <=15):");
        r=input.nextInt();
        System.out.println("You selected "+r);
        System.out.print("Columns (<=15):");                
        c = input.nextInt();
        System.out.println("You selected "+c);     
        
        }while(r>15 || c>15);
        
        field=new Field(r,c);       
        return field;
    }
    
    public void placeShips(){
        int u=0;
        String buffer=null;
        if(!isHuman){
          // for(int j=0;j<7;j++){
            field.placeShipRandomly( );
        //} 
        }
        else{
            
        String inputA,inputB,inputC,inputTotal = null;
        int intInputA = 0,intInputB = 0,intInputC=0,dirInput=0;
        //Field=new
        Scanner sc=new Scanner(System.in);
        System.out.println("Randomise Ship Placing?(y/n)");
        String what=sc.nextLine();
       //PREPEI NA TO DIORTHOSO
        if( what.equals("y")){ 
        //for(int j=0;j<7;j++){
            field.placeShipRandomly( );
       // }
        
        /*field.placeShipRandomly( A1);
        field.placeShipRandomly( A2);
        field.placeShipRandomly( D1);
        field.placeShipRandomly( D2);
        field.placeShipRandomly( D3);
        field.placeShipRandomly( S1);
        field.placeShipRandomly( S2);*/
        
        //otherField.placeShipRandomly( );
    }
        /*-----------manual creation-------------------------------*/
        else {
            System.out.println("You give ships with this order:2*AircraftCarriers then 3*Destroyers and finally 2*Submarines. "); 
            int g=0;
            int sum=0;
            //sum=sum+g;
            //try{
            
            while(g<7){ 
                try{
              sum++;
              inputTotal=null;
                  
            System.out.println("For the "+(g+1)+" Ship give give coordinates: ");
            
            inputTotal=sc.nextLine();
            
            if(inputTotal.length()==2){                
            inputA=inputTotal.substring(0,1 );
            intInputA=field.getLocation(inputA);            
            field.fieldShips[g].row=intInputA;            
            inputB=inputTotal.substring(1, 2);
            intInputB=Integer.parseInt(inputB);
            field.fieldShips[g].col=intInputB;
           // do{
             System.out.println("For the "+(g+1)+" Ship give direction (you have to type 1 for 'HORIZONTAL' and 2 for  'VERTICAL': ");
             dirInput=sc.nextInt();
             buffer=sc.nextLine();
             if(dirInput==1){
                 field.fieldShips[g].dir=ShipDirection.HORIZONTAL;
                 for( u=0;u<field.fieldShips[g].length;u++){
                     field.Board[intInputA][intInputB-1+u]=field.fieldShips[g].letter;
                 }
                 
             }
             else if(dirInput==2){
                 field.fieldShips[g].dir=ShipDirection.VERTICAL;
                 for( u=0;u<field.fieldShips[g].length;u++){
                     field.Board[intInputA+u][intInputB-1]=field.fieldShips[g].letter;
                 }
                 
             }
             //}while(dirInput!=1 || dirInput!=2);
        }
        else if(inputTotal.length()==3){
            inputA=inputTotal.substring(0,1 );
            intInputA=field.getLocation(inputA);
            field.fieldShips[g].row=intInputA;
            inputB=inputTotal.substring(1, 2);
            intInputB=Integer.parseInt(inputB);
            inputC=  inputTotal.substring(2, 3);
            intInputB=Integer.parseInt(inputB+inputC);
            
           
            
            
             field.fieldShips[g].col=intInputB;
            // do{
             System.out.println("For the "+(g+1)+" Ship give direction (you have to type 'HORIZONTAL' or 'VERTICAL': ");
             dirInput=sc.nextInt();
             buffer=sc.nextLine();
             if(dirInput==1){
                 field.fieldShips[g].dir=ShipDirection.HORIZONTAL;
                 for( u=0;u< field.fieldShips[g].length;u++){
                     field.Board[intInputA][intInputB+u-1]= field.fieldShips[g].letter;
                 }
                  
             }
             else if(dirInput==2) {
                  field.fieldShips[g].dir=ShipDirection.VERTICAL;
                 for( u=0;u< field.fieldShips[g].length;u++){
                     field.Board[intInputA+u][intInputB-1]= field.fieldShips[g].letter;
                 }
                  
             }
             //}while(dirInput!=1 || dirInput!=2);
        }
        /*else{
            continue;
        }*/
            g++;
                }
                
              catch(Exception e){
                  System.out.println("Wrong location,out of borders,try again.");
              }
            
            
            
      
                     
                   
            
            
        }

}     
   
    }}


    
    public void printPalyerField(){
        field.printBoard();
    }
    
    public boolean hasWon(){
        int po=0,si=0;
        for(int l=0;l<7;l++){
        //if(A1.isSinking() && A2.isSinking()&&D1.isSinking()&& D2.isSinking()&&D3.isSinking()&&S1.isSinking()&&S2.isSinking()){
            if(field.fieldShips[l].positioned) {
                po++;
                if( field.fieldShips[l].isSinking()) {
                si++;
            }
            }
            
            
            }
        if(po==si) {
            return false;
        }
        else {
            return true;
        }
    }
    
    
   
    
    public void selectMove(Field otherField) {
        int check=0;
        boolean toContinue=true;
        boolean toBreak=false;
        boolean isCmd=false;
 /*-------------------- isHuman------------------*/      
        
        
        
        if(isHuman){
        
            
        
        String inputA,inputB,inputC,inputTotal;
        int intInputA = 0,intInputB = 0,intInputC;
        Scanner input=new Scanner(System.in);        
        //BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        
        
       
       do{/*-------loop if ismarked---*/
         try{
        System.out.println("Insert your move: ");
        inputTotal=input.nextLine(); 
        
        
        if (inputTotal.equals("help")){
            this.cmd=Command.help;
            throw new MoveIsCommandException(cmd);
        }
        else if(inputTotal.equals("save")){
                this.cmd=Command.save;
                
                throw new MoveIsCommandException(cmd); 
                
            }
        else if(inputTotal.equalsIgnoreCase("load")){
                this.cmd=Command.load;
                throw new MoveIsCommandException(cmd);                
            }
        else if (inputTotal.equalsIgnoreCase("exit")){
                this.cmd=Command.exit;
                throw new MoveIsCommandException(cmd);                
            }
       
        if(inputTotal.length()==2){
            inputA=inputTotal.substring(0,1 );     
            intInputA=otherField.getLocation(inputA);
            inputB=inputTotal.substring(1, 2);
            intInputB=Integer.parseInt(inputB)-1;
            
            if(intInputA>14 || intInputB>14 || intInputA<0 || intInputB<0){ 
                throw new InvalidLocationException();
            }
            
        }
        else if(inputTotal.length()==3){
            inputA=inputTotal.substring(0,1 );
            intInputA=otherField.getLocation(inputA);
            inputB=inputTotal.substring(1, 2);
            //intInputB=Integer.parseInt(inputB);
            inputC=  inputTotal.substring(2, 3);
            intInputB=Integer.parseInt(inputB+inputC)-1;
            inputTotal=inputA+inputB+inputC;
            if(intInputA>14 || intInputB>14 || intInputA<0 || intInputB<0){
                throw new InvalidLocationException();
            }
            
           
        }          
        
        
        for( check=0;check<otherField.location.length;check++){
                 if(!otherField.location[ check].isMarked()){
                    toContinue =false; 
                    break;
                 }
             }  
        
        
        }
         catch (MoveIsCommandException MICE){
           MICE.getMoveIsCommandExceptionMessage();
           isCmd=true;
           break;
          //System.out.println(message);
           
       }
         
       catch(InvalidLocationException e) {
            //System.out.println();
            e.getInvalidLocationExceptionMessage();
       }
           
        } while(toContinue);
       
      /// if(!isCmd){
        otherField.location[  intInputA*intInputB+intInputB ].mark();
        otherField.Board[intInputA][intInputB]="o";
        for(int t=0;t<7;t++){                
               // if(otherField.fieldShips[t].positioned==true ){System.out.println("SHIP HEADER LOCATION :"+otherField.fieldShips[t].location[0].getLCLocation());}                   
                //System.out.println("\nparseInt location from rand"+Integer.parseInt(Integer.toString(r)+Integer.toString(c)));           
                    for(int o=0;o<otherField.fieldShips[t].length;o++){
                        
                     if(otherField.fieldShips[t].positioned==true && otherField.fieldShips[t].location[o].getLCLocation()==intInputA*intInputB+intInputB){
                       // System.out.println("SHIP LOCATIONS :"+otherField.fieldShips[t].location[o].getLCLocation());
                        otherField.fieldShips[t].hit(); 
                        
                        otherField.fieldShips[t].getHitMessage();
                        otherField.fieldShips[t].getSinkMessage();
                        otherField.Board[intInputA][intInputB]="x";   toBreak=true; break;
                    }      
                }      
              if(toBreak){
                   break;
              }                
             
        }
        
        //}     
        }  
          
  /*---------- is Computer-----------------------------------------------*/ 
        else{
            
            int r=0,c=0;
            Random randr;
            randr = new Random();
            Random randc=new Random();
           
            do{/*-------loop if ismarked---*/
             r=randr.nextInt(field.rows);            
             c=randc.nextInt(field.cols);            
             for( check=0;check<otherField.location.length;check++){
                 if(!otherField.location[ check].isMarked()){
                    toContinue =false; 
                    break;
                 }
             }            
             }while(toContinue);
           
            otherField.location[r*c+c].mark();      
            otherField.Board[r][c]="o"; 
            
            /*------seek if any ship equals the random coos------*/ 
            for(int t=0;t<7;t++){                
               // if(otherField.fieldShips[t].positioned==true ){System.out.println("SHIP HEADER LOCATION :"+otherField.fieldShips[t].location[0].getLCLocation());}                   
                //System.out.println("\nparseInt location from rand"+Integer.parseInt(Integer.toString(r)+Integer.toString(c)));           
                    for(int o=0;o<otherField.fieldShips[t].length;o++){
                        
                     if(otherField.fieldShips[t].positioned==true && otherField.fieldShips[t].location[o].getLCLocation()==r*c+c){
                       // System.out.println("SHIP LOCATIONS :"+otherField.fieldShips[t].location[o].getLCLocation());
                        otherField.fieldShips[t].hit();                                         
                        otherField.fieldShips[t].getHitMessage();
                        otherField.fieldShips[t].getSinkMessage();   
                        //otherField.fieldShips[t].changeLetter();
                        otherField.Board[r][c]="x";   
                        toBreak=true;
                        break;
                    }
                     /*----threaten----*/
                   /*  else if(otherField.fieldShips[t].positioned==true &&( otherField.fieldShips[t].location[o].row-4==r ||  otherField.fieldShips[t].location[o].row+4==r || otherField.fieldShips[t].location[o].col-4==c|| otherField.fieldShips[t].location[o].col+4==c)){
                         System.out.println("Ship is threaten");
                         //otherField.fieldShips[t].threaten();//Ακόμα δε κάνει κάτι.
                         toBreak=true; break;
                     }*/      
                }      
              if(toBreak){
                   break;
              }        
              
              
             
        }
                   
        }   
        
    
   
    
    
    
    }
    
    public Command getCommand(){
        return cmd;
    }
    
}
       