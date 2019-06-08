package com.ijbamboo.pattern.Mediator.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:31:00
 */
public class TestDvdMediator {

	public static void main(String[] args) {
	       DvdMediator dvdMediator = new DvdMediator();
	       DvdLowercaseTitle dvdLower = 
	         new DvdLowercaseTitle("Mulholland Dr.", dvdMediator);
	       DvdUpcaseTitle dvdUp = 
	         new DvdUpcaseTitle(dvdLower, dvdMediator);
	       
	       System.out.println("Lowercase LC title :" + 
	                           dvdLower.getLowercaseTitle());
	       System.out.println("Lowercase super title :" + 
	                           dvdLower.getTitle());   
	       System.out.println("Upcase UC title :" + 
	                           dvdUp.getUpcaseTitle());
	       System.out.println("Upcase super title :" + 
	                           dvdUp.getTitle());   
	       
	       dvdLower.setSuperTitleLowercase();
	       
	       System.out.println(" ");
	       System.out.println("After Super set to LC");
	       System.out.println("Lowercase LC title :" + 
	                           dvdLower.getLowercaseTitle());
	       System.out.println("Lowercase super title :" + 
	                           dvdLower.getTitle());
	       System.out.println("Upcase UC title :" + 
	                           dvdUp.getUpcaseTitle());
	       System.out.println("Upcase super title :" + 
	                           dvdUp.getTitle());
	   }
	} 
