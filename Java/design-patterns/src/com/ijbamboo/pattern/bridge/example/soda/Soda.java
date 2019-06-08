package com.ijbamboo.pattern.bridge.example.soda;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午8:47:29
 */
public abstract class Soda {  
	   SodaImp sodaImp; 
	   
	   public void setSodaImp() {
	       this.sodaImp = SodaImpSingleton.getTheSodaImp();
	   }
	   public SodaImp getSodaImp() {
	       return this.sodaImp;
	   }
	   
	   public abstract void pourSoda();
	}