package com.ijbamboo.pattern.proxy.example.tea;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:08:55
 */
public class PotOfTeaProxy implements PotOfTeaInterface {  
	   PotOfTea potOfTea;
	    
	   public PotOfTeaProxy() {}
	   
	   public void pourTea() {
	       potOfTea = new PotOfTea();
	       potOfTea.pourTea();
	   }
	}