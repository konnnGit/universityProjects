/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package clubtester;

/**
 *
 * @author konnn
 */
public class Membership {
    private String name;
    private String month;
    private String year;
    
    public Membership( String n, String m,  String y){
        name=n;
        month=m;
        year=y;        
    }
    
    public String getName(){
        return name;
    }
    public String getMonth(){
        return month;
    }
    public String getYear(){
        return year;
    }
    public String toString(){
         String all=name+month+year;
         return all;
    }
    
    
    
}
