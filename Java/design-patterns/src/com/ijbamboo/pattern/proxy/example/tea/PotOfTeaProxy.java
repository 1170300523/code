package com.ijbamboo.pattern.proxy.example.tea;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:08:55
 */
public class PotOfTeaProxy implements PotOfTeaInterface {  
	   PotOfTea potOfTea;
	    
	   public PotOfTeaProxy() {}
	   
	   public void pourTea() {
	       potOfTea = new PotOfTea();
	       potOfTea.pourTea();
	   }
	}