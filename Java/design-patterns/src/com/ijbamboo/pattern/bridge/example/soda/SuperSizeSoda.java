package com.ijbamboo.pattern.bridge.example.soda;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����8:48:33
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