import java.io.*;
import java.util.*;

public class KasiskiMain {
	public static void main(String[] args) {
	motivesList	list=new motivesList();
	LinkedList<Motive> l=new LinkedList<Motive>();
	Motive n=null;
//	Iterator<Motive> iterList =list.iterator();
	//motivesList<Motive> iterList2 =new motivesList<Motive>();
	String input =null;
	Scanner fileScanner =null;
    Scanner terminalScanner = new Scanner(System.in);
    int j,i,up,down;
    j=i=up=down=0;
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
	System.out.print(file);
	char[] s=new char[file.length()];
	s=file.toCharArray();
	String[] strTrimmed=new String[file.length()];
	/*
	while(i<file.length()/3 && up+3<file.length()){	        
    	strTrimmed[i]=file.substring(down,up);
    	System.out.print(strTrimmed[i]+",");
    	down=down+3;
    	up=up+3;
    	i++;	        	
    }
	
	for(j=0;j<i;j++){
		list.addToStart(strTrimmed[j], j);
		System.out.print(list.getNewEntry()+",");
	}*/
	i++;
	System.out.println();
	while( up+3<file.length()){	 
		
		n.newMotive(file.substring(down,up),i);
		l.add(i,n );
    	System.out.print(l.get(i).getMotiveName()+",");
    	down=down+3;
    	up=up+3;
    	i++;	        	
    }
	

	
	while(list.iterator().hasNext()){
		System.out.print(list.iterator().next().getMotiveName()+",");
	}
/*	
	while(iterList.hasNext()){
		
		if(iterList.equals(iterList.next())){
			System.out.print(iterList.next().getMotiveName()+":");
			System.out.print(iterList.next().getPosition());
		}
		System.out.println();
	}
	*/
    
	

}
}