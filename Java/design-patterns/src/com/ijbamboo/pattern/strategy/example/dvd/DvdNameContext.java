package com.ijbamboo.pattern.strategy.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:40:51
 */
public class DvdNameContext {

	private DvdNameStrategy dvdNameStrategy; 
	   
	   public DvdNameContext(char strategyTypeIn) {
	       switch (strategyTypeIn) {
	           case 'C' : 
	             this.dvdNameStrategy = new DvdNameAllCapStrategy(); 
	             break;
	           case 'E' : 
	             this.dvdNameStrategy = new DvdNameTheAtEndStrategy(); 
	             break;
	           case 'S' : 
	             this.dvdNameStrategy = 
	               new DvdNameReplaceSpacesStrategy();
	             break;
	           default  : 
	             this.dvdNameStrategy = new DvdNameTheAtEndStrategy();
	       }     
	   }  
	   
	   public String[] formatDvdNames(String[] namesIn) {
	       return this.formatDvdNames(namesIn, ' ');
	   }    
	   
	   public String[] formatDvdNames(String[] namesIn, char replacementIn) {
	       String[] namesOut = new String[namesIn.length];
	       for (int i = 0; i < namesIn.length; i++) {
	           namesOut[i] = 
	             dvdNameStrategy.formatDvdName(namesIn[i], replacementIn);
	           System.out.println(
	             "Dvd name before formatting: " + namesIn[i]);
	           System.out.println(
	             "Dvd name after formatting:  " + namesOut[i]);
	           System.out.println("==========================");
	       }
	       return namesOut;
	   }
	}
