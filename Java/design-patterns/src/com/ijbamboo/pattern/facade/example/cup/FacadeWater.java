package com.ijbamboo.pattern.facade.example.cup;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:02:03
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
