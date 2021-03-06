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
    int posibleLength=0;
    String file="";
    String scanner=null;    
    boolean loop=true;
    int dev=1;
     float dIC=0; //delta IoC
     float IC=0;
    
    
    
    
    System.out.println("Type the  path of the ciphered file (type x to loop out)  : ");
    input=terminalScanner.nextLine();
    if (input.equals("x")){
    	 terminalScanner.close();
    	 return;
    }
    
    while(loop){   	
  //  System.out.println(".");
    System.out.println("Type a motive length (type 0 to exit): ");
    motiveLength=terminalScanner.nextInt();
    up=down+motiveLength;
    
   
	try{
        fileScanner = new Scanner(new FileInputStream(input));
        
    }
    catch (FileNotFoundException e){
    	System.out.println("Error while openning..no file with that name.");
        System.exit(0);
    }
	while(fileScanner.hasNext()){
    	scanner=fileScanner.next();
    	file=file+scanner;	        
    }
	
	
	
	//System.out.print(file);
	file=file.replaceAll("\\W+", "");//remove all no-letters
	file=file.replaceAll("[0-9]","");//remove all no-letters
	file=file.toUpperCase();
	//System.out.print(file);
	char[] s=new char[file.length()];
	s=file.toCharArray();
	
/*---------cut the  plain text to motives according the size i gave before-------*/	
	System.out.println();
	while( up+motiveLength<file.length()&&i<file.length()/motiveLength){	
		
		l.add(file.substring(down,up) );    	
    	down=down+motiveLength;
    	up=up+motiveLength;
    	i++;	        	
    }
	//New declarations
	Set<String> aSet = new HashSet<String>(l);//used to store the motives in order to finde their freq.
	List<Integer> indexes = new ArrayList<Integer>();//stores the num of times that a motive found according to my desire(terminal input)
	List<Integer> factors = new ArrayList<Integer>();//for each motive i inserted in terminal the programm finds its factors and stores
	
	//*----------------------------Frequency of motives------------------------------------------------*/
	for (String temp : aSet) {
		System.out.println(temp + " frequency: " + Collections.frequency(l, temp)+".");
		//System.out.print(l.indexOf(temp));
		System.out.println();
	}
	
	//------------------------------
	
	//-------------------Look manually for a motive to find its factors
	
	while(loop){	
	System.out.println("Look up for  factors of  the most frequent motive (type x to loop out) :");
	//input=null;
	input=terminalScanner.nextLine();
    if(input.equals("x")) break;
    //each time we add i we add the motive's position to the plain text in order to find the factors 
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
	
	/*--------------- find the freq of each letter 
	//i=1;
	List<Integer> lettersFreq = new ArrayList<Integer>();
    Arrays.sort(s );      
    while(ch<='Z'){
    	h=0;dd=0;
    	while( h<file.length()){
        	if(s[h]==ch) dd++;
        	h++;
        }
    	lettersFreq.add( dd);
    	//i++;
    	 System.out.println(ch+" found "+dd+" times.");
    	ch++;	        	
    }
    System.out.println(lettersFreq);
----------------------------------------------------*/
	
	/*----or-----*/
	System.out.println("Print the plain's text letter freq. :");
	//input=terminalScanner.ne.nextLine();
	//if(input.equals("y")) 
	lettFreqToPrint(file);
	//else continue;
		
	
	 /*------------- Find Index of Coincidence-------------------*/ 
    while(loop){
    	int tst=0;
    	String tmp=null;
    	IC=dIC=0;
   
    System.out.println("Select posible length for IOC (type 0 to loop out) :");
    posibleLength=terminalScanner.nextInt();
    if(posibleLength==0) break;
    for( int j=0;j+1<=posibleLength;j++){
    	IC=0;
    	for(i=0;i<26;i++){
    		int t=(int)(j*file.length()/posibleLength);
    		//System.out.println(t);
    		int t1=(int)((j+1)*file.length()/posibleLength);
    		//System.out.println(t1);
    		tmp=  file.substring(t, t1);
    		IC+=(lettFreq(  tmp).get(i)* (lettFreq(tmp).get(i)-1));
    		tst=tst+lettFreq(  tmp).get(i);
    		// System.out.println("IC= "+IC
    	
    		
    }
    	
    	//System.out.println("tst= "+tst);
    	//System.out.println("Substring lengh= "+tmp.length());
    	IC/=tmp.length()*(tmp.length()-1);
    	//IC*=26;
    	dIC=dIC+IC;
    	//IC=IC*26/(file.substring(file.length()-file.length()*j/posibleLength, file.length()-file.length()*(j-1)/posibleLength).length()*(file.substring(file.length()-file.length()*j/posibleLength, file.length()-file.length()*(j-1)/posibleLength).length())-1);
    	// System.out.println("Posible length for IOC:"+j+" IoC: "+IC);
    	
    	   
    }
    dIC/=posibleLength;
    System.out.println("Delta (average) IoC: "+dIC);
    }
	
    }
    
    
}
	/*---------------------------methods----------------------*/
	
	//we need a method to returns an array of letters frequency for the given string "file" which is a subfile of the original file
	public static List<Integer> lettFreq(String file){
		char[] s=new char[file.length()];
		s=file.toCharArray();
		char ch='A';
		int h=0;
	    int dd=0; 
		List<Integer> lettersFreq = new ArrayList<Integer>();
	    Arrays.sort(s );  
	    while(ch<='Z'){
	    	int i=0;
	    	h=0;dd=0;
	    	while( h<file.length()){
	        	if(s[h]==ch) dd++;
	        	h++;
	        }
	    	lettersFreq.add(i, dd);
	    	i++;
	    	 
	    	ch++;	        	
	    }
	//    System.out.println(lettersFreq);
	    return lettersFreq;
	}
	
	public static void lettFreqToPrint(String file){
		char[] s=new char[file.length()];
		s=file.toCharArray();
		char ch='A';
		int h=0;
	    int dd=0; 
		//List<Integer> lettersFreq = new ArrayList<Integer>();
	    Arrays.sort(s );  
	    while(ch<='Z'){
	    	//int i=0;
	    	h=0;dd=0;
	    	while( h<file.length()){
	        	if(s[h]==ch) dd++;
	        	h++;
	        }
	    	//lettersFreq.add(i, dd);
	    //	i++;
	    	System.out.println(ch+" found "+dd+" times.");
	    	ch++;	        	
	    }
	//    System.out.println(lettersFreq);
	    //return lettersFreq;
	}
	
}
