package com.ijbamboo.pattern.strategy.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:41:19
 */
public class TestDvdStrategy {

	 public static void main(String[] args) {
	       DvdNameContext allCapContext = 
	           new DvdNameContext('C');
	       DvdNameContext theEndContext = 
	           new DvdNameContext('E');
	       DvdNameContext spacesContext = 
	           new DvdNameContext('S');
	       
	       String dvdNames[] = new String[3];
	       dvdNames[0] = "Jay and Silent Bob Strike Back";
	       dvdNames[1] = "The Fast and the Furious";
	       dvdNames[2] = "The Others";
	       
	       char replaceChar = '*';       
	       
	       System.out.println("Testing formatting with all caps");
	       String[] dvdCapNames = 
	           allCapContext.formatDvdNames(dvdNames);
	       
	       System.out.println(" ");         
	       System.out.println(
	           "Testing formatting with beginning the at end");
	       String[] dvdEndNames = 
	           theEndContext.formatDvdNames(dvdNames);     
	       
	       System.out.println(" ");       
	       System.out.println("Testing formatting with all spaces replaced with " + 
	           replaceChar);
	       String[] dvdSpcNames = 
	           spacesContext.formatDvdNames(dvdNames, replaceChar);
	   }
	}  
