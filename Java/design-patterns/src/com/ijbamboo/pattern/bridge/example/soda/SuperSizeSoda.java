package com.ijbamboo.pattern.bridge.example.soda;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:48:33
 */
public class SuperSizeSoda extends Soda {  
	   public SuperSizeSoda() {
	       setSodaImp();
	   }
	   
	   public void pourSoda() {
	       SodaImp sodaImp = this.getSodaImp();
	       for (int i = 0; i < 5; i++) {
	           System.out.print("...glug...");
	           sodaImp.pourSodaImp();
	       }
	       System.out.println(" ");       
	   }
	}