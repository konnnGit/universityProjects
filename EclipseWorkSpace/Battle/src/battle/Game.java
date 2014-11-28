/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package battle;
 import java.io.*;
import java.util.*;

/**
 *
 * @author konnn
 */
public class Game implements Serializable{
    //private int rows;
    //private int cols;
    String Player1_Name;
    String Player2_Name;
    //Field playerOponField;
    Field P1Field;
    Field P2Field;
    Player P1;
    Player P2;
    Command c;
  //  Ship[] shipList1;
   // Ship[] shipList2;
    
    
    public void init(){
        
    int i=0,j=0;
        Scanner input = new Scanner(System.in);
        Scanner input2 = new Scanner(System.in);
        System.out.print("Player1_Name:");
        Player1_Name=input.nextLine();
        System.out.println("For player1  type 1 to be human palyer or 2 to be computer");
        i=input.nextInt();
        if(i==1){               
        P1=new PlayerHuman(Player1_Name);
        }
        else{
           P1=new PlayerComputer(Player1_Name); 
        }
        System.out.print("Player2_Name:");
        Player2_Name=input2.nextLine();  
        System.out.println("For player2  type 1 to be human palyer or 2 to be computer");
        j=input2.nextInt();
        if(j==1){               
        P2=new PlayerHuman(Player2_Name);
        }
        else{
           P2=new PlayerComputer(Player2_Name); 
        }
        
         
         
         
        
         
        
        
    }
    
    public void placeShips(){
        System.out.println("Player "+P1.getName()+" ,select Field Dimensions:");
        P1Field= P1.initField();        
        P1.placeShips();
        System.out.println("Player "+P1.getName()+" Field");
        P1.printPalyerField();
        System.out.println("Player "+P2.getName()+" , select Field Dimensions:");
        P2Field=P2.initField();        
        P2.placeShips();
        System.out.println("Player "+P2.getName()+"Field");
        P2.printPalyerField();
        
        
    }
    
    public void play() throws FileNotFoundException, IOException, ClassNotFoundException{
        boolean isCmd=false;
        boolean toEnd=false;
         
     while( P1.hasWon() || P2.hasWon()){
         
    /*----player1 turn--------*/
        /// do{
            isCmd=false; 
        System.out.println("Player "+P1.getName()+" turn to select move :"); 
        P1.cmd=null;
        P1.selectMove(P2Field ); 
        if (P1.getCommand()==Command.exit){
            
            break;
        }
        else if (P1.getCommand()==Command.help){
            System.out.println("You have the options: give a location, exit,save game, load a game.");
            isCmd=true ;
            
        }
        
        else if(P1.getCommand()==Command.save){
            
            try{
                isCmd=true ;
                //open the file
                FileOutputStream saveP1File=new FileOutputStream("Player_1.txt");
                FileOutputStream saveP2File=new FileOutputStream("Player_2.txt");
                
                ObjectOutputStream saveObjectP1= new ObjectOutputStream(saveP1File);
                ObjectOutputStream saveObjectP2 = new ObjectOutputStream(saveP2File);
                
                saveObjectP1.writeObject(P1);
                saveObjectP2.writeObject(P2);
                   
                //saveObjectP1.close();
                //saveObjectP2.close();
                saveP1File.close();
                saveP2File.close();        
                
                //continue;
            }
            catch(IOException e){
                 System.out.println("Problem with the file output.");
            }
            
            
        }
        else if(P1.getCommand()==Command.load){
            try{
                isCmd=true ;
              FileInputStream savedP1File=new FileInputStream("Player_1.txt");  
              FileInputStream savedP2File=new FileInputStream("Player_2.txt");     
              
              ObjectInputStream savedObjectP1 = new ObjectInputStream(savedP1File);
              ObjectInputStream savedObjectP2 = new ObjectInputStream(savedP2File);              
              
              P1=(Player)savedObjectP1.readObject();
              P2=(Player)savedObjectP2.readObject();
              
             
              
              savedP1File.close();
                savedP2File.close(); 
                
            }
            catch(IOException | ClassNotFoundException e){                
                System.out.println("Problem with the file input.");
            }
            
        }
     //}while(isCmd);
        
        
        System.out.println("Player "+P1.getName()+" field results: " );    
        P1.printPalyerField();        
       
        
        System.out.println("Player "+P2.getName()+" field results: " );    
        P2.printPalyerField();
     
        
        /*-----player2 turn------*/
        
        //do{
            isCmd=false;
        
        System.out.println("Player "+P2.getName()+" turn to select move :"); 
        P2.selectMove(P1Field);
        if (P2.getCommand()==Command.exit){
            //System.out.println("tho help");
            toEnd=true;
            break;
        }
        else if (P2.getCommand()==Command.help){
            System.out.println("You have the options: give a location, exit,save game, load a game.");
            continue;
        }
        else if(P2.getCommand()==Command.save){
            try{
                
                //open the file
                FileOutputStream saveP1File=new FileOutputStream("Player_1.txt");
                FileOutputStream saveP2File=new FileOutputStream("Player_2.txt");
                
                ObjectOutputStream saveObjectP1 = new ObjectOutputStream(saveP1File);
                ObjectOutputStream saveObjectP2 = new ObjectOutputStream(saveP2File);               
                
                saveObjectP1.writeObject(P1);
                saveObjectP2.writeObject(P2);
                
               saveP1File.close();
                saveP2File.close();
                isCmd=true;
           }
           catch(IOException e){
                 System.out.println("Problem with the file output.");
            }
            
            
        }
        else if(P2.getCommand()==Command.load){
            try{
              FileInputStream savedP1File=new FileInputStream("Player_1.txt");  
              FileInputStream savedP2File=new FileInputStream("Player_2.txt");
              
              ObjectInputStream savedObjectP1 = new ObjectInputStream(savedP1File);
              ObjectInputStream savedObjectP2 = new ObjectInputStream(savedP2File);
              
                
              Player P1;
                P1 = (Player)savedObjectP1.readObject();
              this.P2=(Player)savedObjectP2.readObject();
               
               savedP1File.close();
                savedP2File.close();
                
            }
            catch(IOException | ClassNotFoundException e){                
                System.out.println("Problem with the file input.");
            }
            
        }
        System.out.println("Player "+P1.getName()+" field results: " );    
        P1.printPalyerField();
        System.out.println("Player "+P2.getName()+" field results: " );    
        P2.printPalyerField();
        System.out.println("Player "+P2.getName()+" turn to select move :"); 
        P2.selectMove(P1Field);   
        
        
       // } while(isCmd);
        
        }
        
            
       
    
}
        
    
    
    public void showResults(){
        System.out.println("End of game.");
        int resultP1=0,resultP2=0;
        for(int i=0;i<7;i++){
            if(P2Field.fieldShips[i].positioned && P2Field.fieldShips[i].isSinking()){
               
                 resultP1=resultP1+P2Field.fieldShips[i].points;
                
            }
        }
        for(int i=0;i<7;i++){
            if(P1Field.fieldShips[i].positioned && P1Field.fieldShips[i].isSinking()){
               
                 resultP2=resultP2+P1Field.fieldShips[i].points;
                
            }
        }
        System.out.println(P1.getName()+" score="+resultP1);
        System.out.println(P2.getName()+" score="+resultP2);
        
        if(resultP1>resultP2){
            System.out.println(P1.getName()+ " won");
        }
        else if(resultP1<resultP2){
           System.out.println(P2.getName()+ " won"); 
        }
        else{
            System.out.println( "Nobody won,equal score.");
        }
    }
}
  
