package com.ijbamboo.pattern.facade.example.cup;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:02:03
 */
public class FacadeWater {

	boolean waterIsBoiling; 
    
	   public FacadeWater() {
	       setWaterIsBoiling(false);
	       System.out.println("behold the wonderous water");       
	   }
	   
	   public void boilFacadeWater() {
	       setWaterIsBoiling(true);
	       System.out.println("water is boiling");
	   }
	   
	   public void setWaterIsBoiling(boolean isWaterBoiling) {
	       waterIsBoiling = isWaterBoiling;
	   }
	   public boolean getWaterIsBoiling() {
	       return waterIsBoiling;
	   }
	}
