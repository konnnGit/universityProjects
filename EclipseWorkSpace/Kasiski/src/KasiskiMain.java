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
	List<Integer> indexes = new ArrayList<Integer>();
	
	/*--Frequency of motives---*/
	for (String temp : uniqueSet) {
		System.out.println(temp + " frequency: " + Collections.frequency(l, temp)+",");
		System.out.print(l.indexOf(temp));
		System.out.println();
	}
	/*--!Frequency of motives---*/
	
/*	while (l.iterator().hasNext()){
		String tmp1=l.iterator().next();
		while(l.iterator().hasNext()){
			String tmp2=l.iterator().next();
			int in=l.indexOf(l.iterator().next());
			if (tmp1.equals(tmp2)) indexes.add(in);
		}
		System.out.println("indexes"+tmp1 +":"+indexes);
		indexes.clear();
	}*/
	/*for (String temp1 : l) {
		for (String temp2 : l) {
			if (temp1.equals(temp2)){
				indexes.add(l.indexOf(temp1));
				indexes.add(l.indexOf(temp2));
			}
		}
		System.out.println("indexes"+temp1 +":"+indexes);
		indexes.clear();
	}*/
	
	for(i=0;i<l.size()-1;i++){
		indexes.add(l.indexOf(l.get(i)));
		for(j=1;j<l.size();j++){
			if(l.get(i).equals(l.get(j))) indexes.add(l.indexOf(l.get(j)));
		}
		System.out.println("indexes"+l.get(i) +":"+indexes);
		indexes.clear();
	}
	
	/*
	for(i=0;i<l.size();i++){
		if(l.iterator().equals(l.get(i))){
			indexes.add(l.indexOf(l.get(i)));
			//k=l.get(i).indexOf(l.get(i));
			System.out.println(l.indexOf(l.get(i)));
		}
		System.out.println("indexes"+l.get(i) +":"+indexes);
		indexes.clear();
	}*/
	
	
	//System.out.println(indexes);
	/*System.out.println("Name of the most motive : ");
	input=terminalScanner.nextLine();
    terminalScanner.close();
	for (String temp=input : uniqueSet) {
		
		
	}*/
	
	

}
}