import java.io.*;
import java.util.*;

public class KasiskiMain {
	public static void main(String[] args) {
		
	motivesList	list=new motivesList();
	LinkedList<String> l=new LinkedList<String>();
	
	String input =null;
	Scanner fileScanner =null;
    Scanner terminalScanner = new Scanner(System.in);
    int j,i,up,down;
    j=i=up=down=0;
    up=down+3;
    String file="";
    String scanner=null;
    String s123;

    System.out.println("Name of the ciphered file : ");
    input=terminalScanner.nextLine();
    terminalScanner.close();
	try{
        fileScanner = new Scanner(new FileInputStream(input));
        
    }
    catch (FileNotFoundException e){
    	System.out.println("error while openning..no file with that name.");
        System.exit(0);
    }
	while(fileScanner.hasNext()){
    	scanner=fileScanner.next();
    	file=file+scanner;	        
    }
	//System.out.print(file);
	file=file.replaceAll("\\W+", "");//remove all no-letters
	file=file.toUpperCase();
	//System.out.print(file);
	char[] s=new char[file.length()];
	s=file.toCharArray();
	
	
	System.out.println();
	while( up+3<file.length()&&i<file.length()/3){	
		//s123=file.substring(down,up);
		//System.out.print(s123+'-');
		l.add(file.substring(down,up) );    	
    	down=down+3;
    	up=up+3;
    	i++;	        	
    }
	
	Set<String> uniqueSet = new HashSet<String>(l);
	//List<Integer> indexes = new ArrayList<Integer>();
	
	/*--Frequency of motives---*/
	for (String temp : uniqueSet) {
		System.out.println(temp + " frequency: " + Collections.frequency(l, temp)+",");
		System.out.print(l.indexOf(temp));
		System.out.println();
	}
	/*--!Frequency of motives---*/
	System.out.println("Look for motive :");
	
	input=terminalScanner.nextLine();
    terminalScanner.close();
    for(i=0)
    
    if()
    

	

}
}