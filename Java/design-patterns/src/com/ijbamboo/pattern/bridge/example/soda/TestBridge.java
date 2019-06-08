package com.ijbamboo.pattern.bridge.example.soda;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:51:13
 */
public class TestBridge {
	   public static void testCherryPlatform() {
	       SodaImpSingleton sodaImpSingleton = 
	         new SodaImpSingleton(new CherrySodaImp());
	       System.out.println(
	         "testing medium soda on the cherry platform");
	       MediumSoda mediumSoda = new MediumSoda();
	       mediumSoda.pourSoda();
	       System.out.println(
	         "testing super size soda on the cherry platform");
	       SuperSizeSoda superSizeSoda = new SuperSizeSoda();
	       superSizeSoda.pourSoda();       
	   }
	   
	   public static void testGrapePlatform() {
	       SodaImpSingleton sodaImpSingleton = 
	         new SodaImpSingleton(new GrapeSodaImp());
	       System.out.println(
	         "testing medium soda on the grape platform");
	       MediumSoda mediumSoda = new MediumSoda();
	       mediumSoda.pourSoda();
	       System.out.println(
	         "testing super size soda on the grape platform");
	       SuperSizeSoda superSizeSoda = new SuperSizeSoda();
	       superSizeSoda.pourSoda();       
	   }   
	   
	   public static void testOrangePlatform() {
	       SodaImpSingleton sodaImpSingleton = 
	         new SodaImpSingleton(new OrangeSodaImp());
	       System.out.println(
	         "testing medium soda on the orange platform");
	       MediumSoda mediumSoda = new MediumSoda();
	       mediumSoda.pourSoda();
	       System.out.println(
	         "testing super size soda on the orange platform");
	       SuperSizeSoda superSizeSoda = new SuperSizeSoda();
	       superSizeSoda.pourSoda();       
	   }
	    
	   public static void main(String[] args) {
	        testCherryPlatform();
	        testGrapePlatform();
	        testOrangePlatform();
	   }
	}