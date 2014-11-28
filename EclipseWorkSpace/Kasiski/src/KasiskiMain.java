import java.io.*;
import java.util.*;

public class KasiskiMain {
	public static void main(String[] args) {
		
	
	LinkedList<String> l=new LinkedList<String>();
	
	int motiveLength=3;
	String input =null;
	Scanner fileScanner =null;
    Scanner terminalScanner = new Scanner(System.in);
    int i,up,down;
    i=up=down=0;
    
    String file="";
    String scanner=null;    
    boolean loop=true;
    int dev=1;
    int h=0;
    int dd=0;   
    float IC=0;
    char ch='A';
    
    
    
    System.out.println("Name of the ciphered file(type exit to loop out)  : ");
    input=terminalScanner.nextLine();
    if (input.equals("exit")){
    	 terminalScanner.close();
    	 return;
    }
    
    while(loop){   	
    System.out.println("Type 0 to exit.");
    System.out.println("Desired motive length: ");
    motiveLength=terminalScanner.nextInt();
    up=down+motiveLength;
    
   
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
	while( up+motiveLength<file.length()&&i<file.length()/motiveLength){	
		
		l.add(file.substring(down,up) );    	
    	down=down+motiveLength;
    	up=up+motiveLength;
    	i++;	        	
    }
	//New declarations
	Set<String> uniqueSet = new HashSet<String>(l);
	List<Integer> indexes = new ArrayList<Integer>();
	List<Integer> factors = new ArrayList<Integer>();
	
	//*----------------------------Frequency of motives---*/
	for (String temp : uniqueSet) {
		System.out.println(temp + " frequency: " + Collections.frequency(l, temp)+",");
		System.out.print(l.indexOf(temp));
		System.out.println();
	}
	
	//------------------------------
	
	//-------------------Look manually for a motive to find its factors
	
	while(loop){	
	System.out.println("Look up for motive(type exit to loop out) :");
	//input=null;
	input=terminalScanner.nextLine();
    if(input.equals("exit")) break;
    
    for(i=0;i<l.size();i++){
    	 if(l.get(i).equals(input)){
    		 indexes.add(i);
    		 
    	 }
    	 
    }
    
    
    
    for(i=0;i<indexes.size()-1;i++){
    	//System.out.print(indexes.get(i+1)-indexes.get(i)+"-");
    	for(dev=1;dev<(indexes.get(i+1)-indexes.get(i));dev++){
    		if((indexes.get(i+1)-indexes.get(i))%dev==0)
    			factors.add(dev);
    	}
    		
    }
    Collections.sort(factors);
    System.out.println("Motive "+input+"  factors are:" +factors);
 //   System.out.print("Sorted list of "+input+ factors);
    factors.clear();
	}
	
	//-----------------------------------------
	 //terminalScanner.close();
	
	//--------------- find the freq of each letter 
    Arrays.sort(s);      
    while(ch<='Z'){
    	h=0;dd=0;
    	while( h<file.length()){
        	if(s[h]==ch) dd++;
        	h++;
        }
    	 System.out.println(ch+" found "+dd+" times.");
    	ch++;	        	
    }
    
//----------------------------------------------------
    
    
    //------------- Find Ic
    int posibleLength=0;
    System.out.println("Assume posible length :");
    posibleLength=terminalScanner.nextInt();
    for(i=0;)
    
    
	
    }
}
}