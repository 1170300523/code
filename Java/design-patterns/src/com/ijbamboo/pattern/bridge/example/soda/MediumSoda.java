package com.ijbamboo.pattern.bridge.example.soda;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:47:56
 */
public class MediumSoda extends Soda {  
	   public MediumSoda() {
	       setSodaImp();
	   }
	   
	   public void pourSoda() {
	       SodaImp sodaImp = this.getSodaImp();
	       for (int i = 0; i < 2; i++) {
	           System.out.print("...glug...");
	           sodaImp.pourSodaImp();
	       }
	       System.out.println(" ");
	   }
	}